#include "1_register_contents.hpp"

bool leaf::compilation::stages::register_contents::visit_enter(std::shared_ptr<leaf::parsing::instance::property> node)
{
    if (!stage_base::visit_enter(node)) { return false; }
    auto property_name = name_from_nav_stack();
    auto current_type_name = name_from_nav_stack(-1);
    leaf_type* current_type = m_cu->lib().get_type(current_type_name);

    leaf_property_info property_info;
    property_info.flags = leaf_flags::YSF_EMPTY;
    if (!node->is_static) { property_info.flags |= leaf_flags::YSF_INSTANCE; }
    if (node->is_sealed) { property_info.flags |= leaf_flags::YSF_SEALED; }
    if (node->is_virtual) { property_info.flags |= leaf_flags::YSF_VIRTUAL; }

    if (!leaf_string_create2(property_name.c_str(), property_name.length(), &property_info.name)) { return false; }
    if (!leaf_property_info_list_push_back(&current_type->properties, property_info)) { return false; }
    if (!fill_type_reference(property_info.data_type_reference, node->target_type)) { return false; }
    return true;
}

bool leaf::compilation::stages::register_contents::visit_enter(std::shared_ptr<leaf::parsing::instance::method> node)
{
    if (!stage_base::visit_enter(node)) { return false; }
    auto method_name = name_from_nav_stack();
    auto current_type_name = name_from_nav_stack(-1);
    leaf_type* current_type = m_cu->lib().get_type(current_type_name);

    leaf_method_info method_info;
    method_info.flags = leaf_flags::YSF_EMPTY;
    if (!node->is_static) { method_info.flags |= leaf_flags::YSF_INSTANCE; }
    if (node->is_sealed) { method_info.flags |= leaf_flags::YSF_SEALED; }
    if (node->is_virtual) { method_info.flags |= leaf_flags::YSF_VIRTUAL; }

    if (!leaf_string_create2(method_name.c_str(), method_name.length(), &method_info.name)) { return false; }
    if (!leaf_method_info_list_push_back(&current_type->methods, method_info)) { return false; }
    if (!fill_type_reference(method_info.return_type_reference, node->return_type)) { return false; }
    return true;
}

bool leaf::compilation::stages::register_contents::visit_enter(std::shared_ptr<leaf::parsing::instance::field> node)
{
    if (!stage_base::visit_enter(node)) { return false; }
    auto field_name = name_from_nav_stack();
    auto current_type_name = name_from_nav_stack(-1);
    leaf_type* current_type = m_cu->lib().get_type(current_type_name);

    leaf_field_info field_info;
    field_info.offset = leaf_INVALID_OFFSET;
    field_info.size = leaf_INVALID_SIZE;
    field_info.flags = leaf_flags::YSF_EMPTY;
    if (!node->is_static) { field_info.flags |= leaf_flags::YSF_INSTANCE; }
    if (node->is_sealed) { field_info.flags |= leaf_flags::YSF_SEALED; }
    if (node->is_virtual) { field_info.flags |= leaf_flags::YSF_VIRTUAL; }

    if (!leaf_string_create2(field_name.c_str(), field_name.length(), &field_info.name)) { return false; }
    if (!leaf_field_info_list_push_back(&current_type->fields, field_info)) { return false; }
    if (!fill_type_reference(field_info.data_type_reference, node->target_type)) { return false; }
    return true;
}

bool leaf::compilation::stages::register_contents::visit_enter(std::shared_ptr<leaf::parsing::instance::conversion> node)
{
    auto current_type_name = name_from_nav_stack();
    leaf_type* current_type = m_cu->lib().get_type(current_type_name);

    leaf_method_info method_info;
    method_info.flags = leaf_flags::YSF_EMPTY;
    method_info.type = leaf_method_info_type::YSMIT_CONVERSION;

    if (!leaf_string_create2(NULL, 0, &method_info.name)) { return false; }
    if (!leaf_method_info_list_push_back(&current_type->methods, method_info)) { return false; }
    if (!fill_type_reference(method_info.return_type_reference, node->target_type)) { return false; }
    return true;
}

bool leaf::compilation::stages::register_contents::visit_enter(std::shared_ptr<leaf::parsing::instance::operator_binary_overload> node)
{
    auto current_type_name = name_from_nav_stack();
    leaf_type* current_type = m_cu->lib().get_type(current_type_name);

    leaf_method_info method_info;
    method_info.flags = leaf_flags::YSF_EMPTY;
    switch (node->operator_.type)
    {
        case leaf::parsing::instance::tok::PLUS: method_info.type = leaf_method_info_type::YSMIT_OPBINARY_ADD; break;
        case leaf::parsing::instance::tok::MINUS: method_info.type = leaf_method_info_type::YSMIT_OPBINARY_SUBTRACT; break;
        case leaf::parsing::instance::tok::STAR: method_info.type = leaf_method_info_type::YSMIT_OPBINARY_MULTIPLY; break;
        case leaf::parsing::instance::tok::SLASH: method_info.type = leaf_method_info_type::YSMIT_OPBINARY_DIVIDE; break;
        case leaf::parsing::instance::tok::_LESS_THEN_LESS_THEN_LESS_THEN: method_info.type = leaf_method_info_type::YSMIT_OPBINARY_TRIPPLE_SHIFT_LEFT; break;
        case leaf::parsing::instance::tok::_LESS_THEN_LESS_THEN: method_info.type = leaf_method_info_type::YSMIT_OPBINARY_DOUBLE_SHIFT_LEFT; break;
        case leaf::parsing::instance::tok::_LESS_THEN_EQUAL: method_info.type = leaf_method_info_type::YSMIT_OPBINARY_LESS_THEN_OR_EQUAL; break;
        case leaf::parsing::instance::tok::_LESS_THEN: method_info.type = leaf_method_info_type::YSMIT_OPBINARY_LESS_THEN; break;
        case leaf::parsing::instance::tok::_GREATER_THEN_GREATER_THEN_GREATER_THEN: method_info.type = leaf_method_info_type::YSMIT_OPBINARY_TRIPPLE_SHIFT_RIGHT; break;
        case leaf::parsing::instance::tok::_GREATER_THEN_GREATER_THEN: method_info.type = leaf_method_info_type::YSMIT_OPBINARY_DOUBLE_SHIFT_RIGHT; break;
        case leaf::parsing::instance::tok::_GREATER_THEN_EQUAL: method_info.type = leaf_method_info_type::YSMIT_OPBINARY_GREATER_THEN_OR_EQUAL; break;
        case leaf::parsing::instance::tok::_GREATER_THEN: method_info.type = leaf_method_info_type::YSMIT_OPBINARY_GREATER_THEN; break;
        case leaf::parsing::instance::tok::_VERTICAL_BAR_VERTICAL_BAR: method_info.type = leaf_method_info_type::YSMIT_OPBINARY_LOGICAL_OR; break;
        case leaf::parsing::instance::tok::_VERTICAL_BAR: method_info.type = leaf_method_info_type::YSMIT_OPBINARY_BITWISE_OR; break;
        case leaf::parsing::instance::tok::_AMPERSAND_AMPERSAND: method_info.type = leaf_method_info_type::YSMIT_OPBINARY_LOGICAL_AND; break;
        case leaf::parsing::instance::tok::_AMPERSAND: method_info.type = leaf_method_info_type::YSMIT_OPBINARY_BITWISE_AND; break;
        default:
        // ToDo: Report error
        return false;
    }

    if (!leaf_string_create2(NULL, 0, &method_info.name)) { return false; }
    if (!leaf_method_info_list_push_back(&current_type->methods, method_info)) { return false; }
    if (!fill_type_reference(method_info.return_type_reference, node->target_type)) { return false; }
    return true;
}

bool leaf::compilation::stages::register_contents::visit_enter(std::shared_ptr<leaf::parsing::instance::operator_unary_overload> node)
{
    auto current_type_name = name_from_nav_stack();
    leaf_type* current_type = m_cu->lib().get_type(current_type_name);

    leaf_method_info method_info;
    method_info.flags = leaf_flags::YSF_EMPTY;
    switch (node->operator_.type)
    {
        case leaf::parsing::instance::tok::PLUS: method_info.type = leaf_method_info_type::YSMIT_OPUNARY_PLUS; break;
        case leaf::parsing::instance::tok::MINUS: method_info.type = leaf_method_info_type::YSMIT_OPUNARY_MINUS; break;
        case leaf::parsing::instance::tok::_EXCLAMATION: method_info.type = leaf_method_info_type::YSMIT_OPUNARY_LOGICAL_NOT; break;
        case leaf::parsing::instance::tok::_TILDE: method_info.type = leaf_method_info_type::YSMIT_OPUNARY_BITWISE_NOT; break;
            // ToDo: Report error
            return false;
    }

    if (!leaf_string_create2(NULL, 0, &method_info.name)) { return false; }
    if (!leaf_method_info_list_push_back(&current_type->methods, method_info)) { return false; }
    if (!fill_type_reference(method_info.return_type_reference, node->target_type)) { return false; }
    return true;
}

bool leaf::compilation::stages::register_contents::visit_enter(std::shared_ptr<leaf::parsing::instance::constructor> node)
{
    auto current_type_name = name_from_nav_stack();
    leaf_type* current_type = m_cu->lib().get_type(current_type_name);

    leaf_method_info method_info;
    method_info.flags = leaf_flags::YSF_EMPTY;
    method_info.type = leaf_method_info_type::YSMIT_CONSTRUCTOR;

    if (!leaf_string_create2(NULL, 0, &method_info.name)) { return false; }
    if (!leaf_method_info_list_push_back(&current_type->methods, method_info)) { return false; }
    if (!fill_type_reference_void(method_info.return_type_reference)) { return false; }
    if (!get_type_reference_index(current_type, method_info.return_type_reference.index)) { return false; }
    return true;
}

bool leaf::compilation::stages::register_contents::visit_enter(std::shared_ptr<leaf::parsing::instance::copystructor> node)
{
    auto current_type_name = name_from_nav_stack();
    leaf_type* current_type = m_cu->lib().get_type(current_type_name);

    leaf_method_info method_info;
    method_info.flags = leaf_flags::YSF_EMPTY;
    method_info.type = leaf_method_info_type::YSMIT_COPY;

    if (!leaf_string_create2(NULL, 0, &method_info.name)) { return false; }
    if (!leaf_method_info_list_push_back(&current_type->methods, method_info)) { return false; }
    if (!fill_type_reference_void(method_info.return_type_reference)) { return false; }
    auto current_type_name = name_from_nav_stack(-1);
    if (!get_type_reference_index(m_cu->lib().get_type(current_type_name), method_info.return_type_reference.index)) { return false; }
    return true;
}

bool leaf::compilation::stages::register_contents::visit_enter(std::shared_ptr<leaf::parsing::instance::destructor> node)
{
    auto current_type_name = name_from_nav_stack();
    leaf_type* current_type = m_cu->lib().get_type(current_type_name);

    leaf_method_info method_info;
    method_info.flags = leaf_flags::YSF_EMPTY;
    method_info.type = leaf_method_info_type::YSMIT_DESTRUCTOR;

    if (!leaf_string_create2(NULL, 0, &method_info.name)) { return false; }
    if (!leaf_method_info_list_push_back(&current_type->methods, method_info)) { return false; }
    if (!fill_type_reference_void(method_info.return_type_reference)) { return false; }
    return true;
}

bool leaf::compilation::stages::register_contents::visit_enter(std::shared_ptr<leaf::parsing::instance::method_arglist_item> node)
{
    if (!m_parameter_info_list) { return false; }
    // node->type->base
    leaf_parameter_info inf;
    if (!fill_type_reference(inf.type_reference, node->type)) { return false; }
    if (!leaf_string_create2(m_cu->get(node->name).data(), node->name.length, &inf.name)) { return false; }
    if (!leaf_parameter_info_list_push_back(m_parameter_info_list, inf)) { return false; }
    return true;
}
