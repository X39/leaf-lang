#include "0_register_types.hpp"

bool leaf::compilation::stages::register_types::visit_enter(std::shared_ptr<leaf::parsing::instance::namespace_> node)
{
    if (!stage_base::visit_enter(node)) { return false; }
    if (!(node->methods.empty() && node->conversions.empty() && node->fields.empty() && node->properties.empty()))
    {
        auto name = name_from_nav_stack();
        leaf_type type;
        type.instance_size = leaf_INVALID_SIZE;
        type.flags = leaf_flags::YSF_NAMESPACE;
        if (!leaf_string_create2(name.c_str(), name.length(), &type.name)) { return false; }
        if (m_cu->lib().has_type(name))
        {
            // ToDo: Report error "A type with the name {name} already exists."
            return false;
        }
        else
        {
            m_cu->lib().register_type(type);
        }
    }
    return true;
}

bool leaf::compilation::stages::register_types::visit_enter(std::shared_ptr<leaf::parsing::instance::class_> node)
{
    if (!stage_base::visit_enter(node)) { return false; }

    auto name = name_from_nav_stack();
    leaf_type type;
    type.instance_size = leaf_INVALID_SIZE;
    type.flags = leaf_flags::YSF_CLASS;
    if (!leaf_string_create2(name.c_str(), name.length(), &type.name)) { return false; }
    if (m_cu->lib().has_type(name))
    {
        // ToDo: Report error "A type with the name {name} already exists."
        return false;
    }
    else
    {
        m_cu->lib().register_type(type);
    }
    return true;
}