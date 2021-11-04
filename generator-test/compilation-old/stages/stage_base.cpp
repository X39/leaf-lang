#include "stage_base.hpp"

void leaf::compilation::stages::stage_base::get_ident_recursive(std::vector<std::string_view>& local_stack, std::shared_ptr<leaf::parsing::instance::ident_navigation> data)
{
    // Check left
    if (std::holds_alternative<leaf::parsing::instance::token>(data->left))
    {
        local_stack.push_back(m_cu->get(std::get<leaf::parsing::instance::token>(data->left)));
    }
    else if (std::holds_alternative<std::shared_ptr<leaf::parsing::instance::ident_navigation>>(data->left))
    {
        get_ident_recursive(local_stack, std::get<std::shared_ptr<leaf::parsing::instance::ident_navigation>>(data->left));
    }
    else
    {
        throw std::runtime_error("Not all variant paths are handled.");
    }

    // Check right
    if (data->right.type == leaf::parsing::instance::tok::IDENT)
    {
        local_stack.push_back(m_cu->get(data->right));
    }
}

bool leaf::compilation::stages::stage_base::visit_enter(std::shared_ptr<leaf::parsing::instance::namespace_> node)
{
    auto name = get_ident(node->name);
    m_nav_stack.push_back(name);
    leaf_type_ptr type_ptr;
    if (m_cu->lib().try_get_type(name, type_ptr))
    {
        helper.push_type(type_ptr);
    }
    return true;
}
bool leaf::compilation::stages::stage_base::visit_leave(std::shared_ptr<leaf::parsing::instance::namespace_> node)
{
    auto name = get_ident(node->name);
    m_nav_stack.push_back(name);
    if (m_cu->lib().has_type(name))
    {
        helper.pop_type();
    }
    return true;
}

bool leaf::compilation::stages::stage_base::visit_enter(std::shared_ptr<leaf::parsing::instance::class_> node)
{
    std::string name(m_cu->get(node->name).begin(), m_cu->get(node->name).end());
    m_nav_stack.push_back(name);

    name = name_from_nav_stack();
    leaf_type_ptr type_ptr;
    if (m_cu->lib().try_get_type(name, type_ptr))
    {
        helper.push_type(type_ptr);
    }
    return true;
}
bool leaf::compilation::stages::stage_base::visit_leave(std::shared_ptr<leaf::parsing::instance::class_> node)
{
    if (helper.has_type())
    {
        helper.pop_type();
    }
    return true;
}

bool leaf::compilation::stages::stage_base::visit_enter(std::shared_ptr<leaf::parsing::instance::property> node)
{
    std::string name(m_cu->get(node->name).begin(), m_cu->get(node->name).end());
    m_nav_stack.push_back(name);
    return true;
}
bool leaf::compilation::stages::stage_base::visit_leave(std::shared_ptr<leaf::parsing::instance::property> node)
{
    m_nav_stack.pop_back();
    return true;
}

bool leaf::compilation::stages::stage_base::visit_enter(std::shared_ptr<leaf::parsing::instance::method> node)
{
    std::string name(m_cu->get(node->name).begin(), m_cu->get(node->name).end());
    m_nav_stack.push_back(name);
    return true;
}
bool leaf::compilation::stages::stage_base::visit_leave(std::shared_ptr<leaf::parsing::instance::method> node)
{
    m_nav_stack.pop_back();
    return true;
}

bool leaf::compilation::stages::stage_base::visit_enter(std::shared_ptr<leaf::parsing::instance::field> node)
{
    std::string name(m_cu->get(node->name).begin(), m_cu->get(node->name).end());
    m_nav_stack.push_back(name);
    return true;
}
bool leaf::compilation::stages::stage_base::visit_leave(std::shared_ptr<leaf::parsing::instance::field> node)
{
    m_nav_stack.pop_back();
    return true;
}

bool leaf::compilation::stages::stage_base::visit_enter(std::shared_ptr<leaf::parsing::instance::pragma_disable> node)
{
    std::string key(m_cu->get(node->code).begin(), m_cu->get(node->code).end());
    m_cu->disable(key);
    return true;
}
bool leaf::compilation::stages::stage_base::visit_enter(std::shared_ptr<leaf::parsing::instance::pragma_enable> node)
{
    std::string key(m_cu->get(node->code).begin(), m_cu->get(node->code).end());
    m_cu->enable(key);
    return true;
}

bool leaf::compilation::stages::stage_base::try_resolve_type_name(
    std::string type_ident,
    leaf_type_reference& out_type_reference,
    leaf_type_ptr& out_type_ptr)
{
    auto first_end_index = type_ident.find('.');
    auto possible_alias = first_end_index == std::string::npos ? std::string_view() : std::string_view(type_ident.begin(), type_ident.begin() + first_end_index);
    auto possible_alias_remaining = first_end_index == std::string::npos ? type_ident : std::string_view(type_ident.begin() + first_end_index + 1, type_ident.end());
    size_t hits = 0;
    std::string expanded_name;
    helper.iterate([&](std::string_view full_name, std::string_view alias) -> void {
        // Craft lookup string
        expanded_name.resize(0);
        if (alias == possible_alias)
        {
            std::string expanded_name;
            expanded_name.reserve(full_name.size() + 1 + possible_alias_remaining.size());
            expanded_name.append(full_name);
            expanded_name.append(".");
            expanded_name.append(possible_alias_remaining.begin(), possible_alias_remaining.end());
        }
        else
        {
            expanded_name.reserve(full_name.size() + 1 + type_ident.size());
            expanded_name.append(full_name);
            expanded_name.append(".");
            expanded_name.append(type_ident);
        }

        if (m_cu->lib_collection().try_get_type(expanded_name, out_type_ptr))
        {
            hits++;
        }
    });
    if (hits == 1)
    {
        out_type_reference = m_cu->lib().refer_type(helper.current_type(), out_type_ptr);
        return true;
    }
    else
    {
        return false;
    }
}

bool leaf::compilation::stages::stage_base::try_resolve_type_name(
    std::shared_ptr<leaf::parsing::instance::type_navigation> type_navigation,
    leaf_type_reference& out_type_reference,
    leaf_type_ptr& out_type_ptr)
{
    std::vector<std::string> type_name_parts;
    auto tmp = type_navigation->left;

    // If right elements holds something, add it to type_name_parts
    if (type_navigation->right.type != leaf::parsing::instance::tok::__UNSET__)
    {
        type_name_parts.push_back(std::string(m_cu->get(type_navigation->right).begin(), m_cu->get(type_navigation->right).end()));
    }

    // Add to type_name_parts while left is not token or current (tmp) not contains a template definition
    while (!std::holds_alternative<leaf::parsing::instance::token>(tmp))
    {
        auto tmp2 = std::get<std::shared_ptr<leaf::parsing::instance::type_navigation>>(tmp);
        if (!tmp2->template_)
        {
            // ToDo: Report NotImplemented error
            return false;
        }
        if (type_navigation->right.type != leaf::parsing::instance::tok::__UNSET__)
        {
            type_name_parts.push_back(std::string(m_cu->get(type_navigation->right).begin(), m_cu->get(type_navigation->right).end()));
        }
    }
    if (std::holds_alternative<leaf::parsing::instance::token>(tmp)
        && std::get<leaf::parsing::instance::token>(tmp).type != leaf::parsing::instance::tok::__UNSET__)
    {
        type_name_parts.push_back(std::string(
            m_cu->get(std::get<leaf::parsing::instance::token>(tmp)).begin(),
            m_cu->get(std::get<leaf::parsing::instance::token>(tmp)).end()));
    }

    if (!type_navigation->template_)
    {
        // ToDo: Report NotImplemented error
        return false;
    }

    std::reverse(type_name_parts.begin(), type_name_parts.end());
    std::string type_name;
    size_t len = 0;
    for (auto it : type_name_parts)
    {
        len += it.length();
    }
    type_name.reserve(len + type_name_parts.size() - 1);
    for (auto it : type_name_parts)
    {
        if (!type_name.empty()) { type_name.append(1, '.'); }
        type_name.append(it);
    }

    return try_resolve_type_name(type_name, out_type_reference, out_type_ptr);
}
bool leaf::compilation::stages::stage_base::fill_type_reference(leaf_type_reference& ref, const std::shared_ptr<leaf::parsing::instance::type_match>& node)
{
    leaf_type_ptr type_ptr;
    if (!try_resolve_type_name(node->base, ref, type_ptr)) { return false; }

    ref.flags = leaf_flags::YSF_EMPTY;
    if (node->is_array) { ref.flags |= leaf_flags::YSF_ARRAY; }
    if (node->is_heap) { ref.flags |= leaf_flags::YSF_POINTER; }
    return true;
}
bool leaf::compilation::stages::stage_base::fill_type_reference_void(leaf_type_reference& ref)
{
    ref.flags = leaf_flags::YSF_EMPTY;
    ref.index = SIZE_MAX;
    return true;
}
bool leaf::compilation::stages::stage_base::get_type_reference_index(leaf_type_ptr type, size_t& out_index)
{
    auto current_type_name = name_from_nav_stack();
    auto current_type = m_cu->lib().get_type(current_type_name);
    // ToDo: Lookup other libraries if not existing.
    if (!current_type) { return false; }
    std::string_view type_name(type->name.data, type->name.data + type->name.length);

    // ToDo: Replace with library lookup
    for (size_t i = 0; i < current_type->referred_types.size; i++)
    {
        std::string_view it_name(
            current_type->referred_types.data[i]->name.data,
                current_type->referred_types.data[i]->name.data + current_type->referred_types.data[i]->name.length);
        if (it_name == type_name)
        {
            return i;
        }
    }
    auto cur_end = current_type->referred_types.size;
    if (!leaf_type_ptr_list_push_back(&current_type->referred_types, type)) { throw std::bad_alloc(); }
    return cur_end;
}

bool leaf::compilation::stages::stage_base::get_type_from_reference_index(size_t index, leaf_type_ptr& out_type)
{
    auto current_type = helper.current_type();
    if (current_type->referred_types.size <= index) { return false; }
    out_type = current_type->referred_types.data[index];
    return true;
}
