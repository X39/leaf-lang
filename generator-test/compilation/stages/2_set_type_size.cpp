#include "2_set_type_size.hpp"

bool leaf::compilation::stages::set_type_size::visit_enter(std::shared_ptr<leaf::parsing::instance::namespace_> node)
{
    if (!stage_base::visit_enter(node)) { return false; }
    auto type_name = name_from_nav_stack();
    auto type = m_cu->lib().get_type(type_name);

    // Ensure we only process types which are not yet processed
    if (type->instance_size != leaf_INVALID_SIZE) { return true; }

    // Precaculate data sizes
    size_t instance_size = 0;
    size_t static_size = 0;
    for (size_t i = 0; i < type->fields.size; i++)
    {
        auto field = type->fields.data + i;
        if (field->flags & YSF_INSTANCE)
        {
            // ToDo: Report error because instance-fields in namespace-types are not allowed.
        }

        if (field->size == leaf_INVALID_SIZE)
        {
            if (field->data_type_reference.flags & YSF_POINTER)
            { // Pointer-type
                field->size = leaf_POINTER_SIZE;
            }
            else
            { // Data-type
                leaf_type_ptr refered_type;
                if (!get_type_from_reference_index(field->data_type_reference.index, refered_type)) { return false; }
                if (refered_type->instance_size == leaf_INVALID_SIZE)
                { // Rerun because type size cannot yet be determined
                    m_cu->rerun_stage();
                    return true;
                }
                field->size = refered_type->instance_size;
            }
        }

        if (field->flags & YSF_INSTANCE)
        { // Instance-Data
            instance_size += field->size;
        }
        else
        { // Static-Data
            static_size += field->size;
        }
    }

    // Apply data sizes and offsets for fields
    if (!uint8_list_create(&type->static_data, static_size)) { throw std::bad_alloc(); }
    type->instance_size = instance_size;
    instance_size = 0;
    static_size = 0;
    for (size_t i = 0; i < type->fields.size; i++)
    {
        auto field = type->fields.data + i;
        if (field->flags & YSF_INSTANCE)
        { // Instance-Data
            field->offset = instance_size;
            instance_size += field->size;
        }
        else
        { // Static-Data
            field->offset = static_size;
            static_size += field->size;
        }
    }
    return true;
}
bool leaf::compilation::stages::set_type_size::visit_enter(std::shared_ptr<leaf::parsing::instance::class_> node)
{
    if (!stage_base::visit_enter(node)) { return false; }
    auto type_name = name_from_nav_stack();
    auto type = m_cu->lib().get_type(type_name);

    // Ensure we only process types which are not yet processed
    if (type->instance_size != leaf_INVALID_SIZE) { return true; }

    // Precaculate data sizes
    size_t instance_size = 0;
    size_t static_size = 0;
    for (size_t i = 0; i < type->fields.size; i++)
    {
        auto field = type->fields.data + i;
        if (field->size == leaf_INVALID_SIZE)
        {
            if (field->data_type_reference.flags & YSF_POINTER)
            { // Pointer-type
                field->size = leaf_POINTER_SIZE;
            }
            else
            { // Data-type
                leaf_type_ptr refered_type;
                if (!get_type_from_reference_index(field->data_type_reference.index, refered_type)) { return false; }
                if (refered_type->instance_size == leaf_INVALID_SIZE)
                { // Rerun because type size cannot yet be determined
                    m_cu->rerun_stage();
                    return true;
                }
                field->size = refered_type->instance_size;
            }
        }

        if (field->flags & YSF_INSTANCE)
        { // Instance-Data
            instance_size += field->size;
        }
        else
        { // Static-Data
            static_size += field->size;
        }
    }

    // Apply data sizes and offsets for fields
    if (!uint8_list_create(&type->static_data, static_size)) { throw std::bad_alloc(); }
    type->instance_size = instance_size;
    instance_size = 0;
    static_size = 0;
    for (size_t i = 0; i < type->fields.size; i++)
    {
        auto field = type->fields.data + i;
        if (field->flags & YSF_INSTANCE)
        { // Instance-Data
            field->offset = instance_size;
            instance_size += field->size;
        }
        else
        { // Static-Data
            field->offset = static_size;
            static_size += field->size;
        }
    }
    return true;
}