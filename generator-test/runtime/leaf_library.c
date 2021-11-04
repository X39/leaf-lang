#include "leaf_library.h"
#include <stddef.h>
#include <string.h>


leaf_GENERIC_IMPLEMENTATION_LIST(leaf_library_attribute);
leaf_GENERIC_IMPLEMENTATION_LIST2(struct leaf_library*, leaf_library_ptr);
leaf_GENERIC_IMPLEMENTATION_LIST2(struct leaf_library, leaf_library);



#define leaf_LIBRARY_READ(TYPE)\
static TYPE leaf_library_read_##TYPE(FILE* file) {\
    TYPE out;\
    fread(&out, sizeof(TYPE), 1, file);\
    return out;\
}
#define leaf_LIBRARY_WRITE(TYPE)\
static void leaf_library_write_##TYPE(FILE* file, TYPE input) {\
    fwrite(&input, sizeof(TYPE), 1, file);\
}
leaf_LIBRARY_READ(uint8_t);
leaf_LIBRARY_READ(uint16_t);
leaf_LIBRARY_READ(uint32_t);
leaf_LIBRARY_READ(uint64_t);
leaf_LIBRARY_READ(int8_t);
leaf_LIBRARY_READ(int16_t);
leaf_LIBRARY_READ(int32_t);
leaf_LIBRARY_READ(int64_t);
leaf_LIBRARY_WRITE(uint8_t);
leaf_LIBRARY_WRITE(uint16_t);
leaf_LIBRARY_WRITE(uint32_t);
leaf_LIBRARY_WRITE(uint64_t);
leaf_LIBRARY_WRITE(int8_t);
leaf_LIBRARY_WRITE(int16_t);
leaf_LIBRARY_WRITE(int32_t);
leaf_LIBRARY_WRITE(int64_t);



struct leaf_library_meta_info
{
    uint32_t version;
    uint64_t attributes;
    uint64_t dependant_libraries;
    uint64_t types;
};
#define leaf_LIBRARY_FILE_VERSION 1

void leaf_library_destroy(leaf_library_ptr input)
{
    // Unload attributes
    for (size_t i = 0; i < input->attributes.size; i++)
    {
        leaf_string_destroy(input->attributes.data[i].key);
        leaf_string_destroy(input->attributes.data[i].value);
    }
    leaf_library_attribute_list_destroy(&input->attributes);

    // Unload dependencies
    leaf_library_ptr_list_destroy(&input->dependencies);

    // Unload types
    for (size_t i = 0; i < input->types.size; i++)
    {
        leaf_type_ptr type = input->types.data + i;
        leaf_string_destroy(type->name);

        for (size_t j = 0; j < type->methods.size; j++)
        {
            leaf_method_info_ptr method_info = type->methods.data + j;
            leaf_string_destroy(method_info->name);

            for (size_t k = 0; k < method_info->parameters.size; k++)
            {
                leaf_parameter_info_ptr parameter_info = method_info->parameters.data + j;

                leaf_string_destroy(parameter_info->name);
            }
            leaf_parameter_info_list_destroy(&type->methods);
        }
        leaf_method_info_list_destroy(&type->methods);

        for (size_t j = 0; j < type->properties.size; j++)
        {
            leaf_property_info_ptr property_info = type->properties.data + j;
            leaf_string_destroy(property_info->name);
        }
        leaf_property_info_list_destroy(&type->properties);

        for (size_t j = 0; j < type->fields.size; j++)
        {
            leaf_field_info_ptr field_info = type->fields.data + j;
            leaf_string_destroy(field_info->name);
        }
        leaf_field_info_list_destroy(&type->fields);

        uint8_list_destroy(&type->static_data);
        uint8_list_destroy(&type->bytecode);
    }
    leaf_type_list_destroy(&input->types);
}

void leaf_library_update_dependencies(const leaf_library_list loaded_libraries, leaf_library_ptr input)
{
    input->dependencies.size = 0;
    // For every type ...
    for (size_t type_index = 0; type_index < input->types.size; type_index++)
    {
        leaf_type_ptr type = input->types.data + type_index;
        // ... walk through every refered type ...
        for (size_t refered_index = 0; refered_index < type->referred_types.size; refered_index++)
        {
            leaf_type_ptr refered_type = type->referred_types.data[refered_index];
            if (refered_type >= input->types.data
                && refered_type < input->types.data + input->types.size)
            {
                continue;
            }
            for (size_t loaded_libraries_index = 0; loaded_libraries_index < loaded_libraries.size; loaded_libraries_index++)
            {
                leaf_library_ptr loaded_library = loaded_libraries.data + loaded_libraries_index;
                if (refered_type >= loaded_library->types.data
                    && refered_type < loaded_library->types.data + loaded_library->types.size)
                {
                    leaf_library_ptr_list_push_back(&input->dependencies, loaded_library);
                    break;
                }
            }
        }
    }
}

int leaf_library_find_type(const leaf_library_ptr library, leaf_string name, leaf_type_ptr* output)
{
    for (size_t index = 0; index < library->types.size; index++)
    {
        if (library->types.data[index].name.length == name.length
            && strcmp(library->types.data[index].name.data, name.data) == 0)
        {
            if (output != NULL)
            {
                *output = library->types.data + index;
            }
            return 0;
        }
    }
    return -1;
}
int leaf_library_serialize(FILE* file, leaf_library_list loaded_libraries, leaf_library input)
{
    // 1. Write out meta_info
    struct leaf_library_meta_info meta_info;
    meta_info.version = leaf_LIBRARY_FILE_VERSION;
    meta_info.attributes = input.attributes.size;
    meta_info.dependant_libraries = input.dependencies.size;
    meta_info.types = input.types.size;
    leaf_library_write_uint64_t(file, meta_info.version);
    leaf_library_write_uint64_t(file, meta_info.attributes);
    leaf_library_write_uint64_t(file, meta_info.dependant_libraries);
    leaf_library_write_uint64_t(file, meta_info.types);

    // 2. Write out attributes
    for (size_t index = 0; index < input.attributes.size; index++)
    {
        if (!leaf_string_serialize(file, input.attributes.data[index].key)) { return 1; }
        if (!leaf_string_serialize(file, input.attributes.data[index].value)) { return 1; }
    }

    // 3. Write out libraries the input is depending on
    for (size_t index = 0; index < input.dependencies.size; index++)
    {
        if (!leaf_string_serialize(file, input.dependencies.data[index]->name)) { return 1; }
    }
    // 4. Write out only the names of the types inside of the input library
    for (size_t index = 0; index < input.types.size; index++)
    {
        leaf_type_ptr type = input.types.data + index;

        // 4.1. Write Type-Name
        if (!leaf_string_serialize(file, type->name)) { return 1; }
    }
    // 5. Write out everyting else from the types inside of the input library
    for (size_t index = 0; index < input.types.size; index++)
    {
        leaf_type_ptr type = input.types.data + index;
        // 5.1. Write flags
        leaf_library_write_uint64_t(file, type->flags);
        // 5.2. Write size of static_data
        leaf_library_write_uint64_t(file, type->static_data.size);
        // 5.3. Write refered types list
        leaf_library_write_uint64_t(file, type->referred_types.size);
        for (size_t refered_type_index = 0; refered_type_index < type->referred_types.size; refered_type_index++)
        {
            if (!leaf_string_serialize(file, type->referred_types.data[refered_type_index]->name)) { return 1; }
        }
        // 5.4. Write fields
        leaf_library_write_uint64_t(file, type->fields.size);
        for (size_t field_index = 0; field_index < type->fields.size; field_index++)
        {
            leaf_field_info_ptr field_info = type->fields.data + field_index;
            // 5.4.1. Write field_info name
            if (!leaf_string_serialize(file, field_info->name)) { return 1; }
            // 5.4.2. Write flags
            leaf_library_write_uint64_t(file, field_info->flags);
            // 5.4.3. Write data-type index
            leaf_library_write_uint64_t(file, field_info->data_type_reference.index);
            leaf_library_write_uint64_t(file, field_info->data_type_reference.flags);
            // 5.4.4. Write data-offset
            leaf_library_write_uint64_t(file, field_info->offset);
            // 5.4.5. Write data-size
            leaf_library_write_uint64_t(file, field_info->size);
        }

        // 5.5. Write properties
        leaf_library_write_uint64_t(file, type->properties.size);
        for (size_t property_index = 0; property_index < type->properties.size; property_index++)
        {
            leaf_property_info_ptr property_info = type->properties.data + property_index;
            // 5.5.1. Write field_info name
            if (!leaf_string_serialize(file, property_info->name)) { return 1; }

            // 5.5.2. Write flags
            leaf_library_write_uint64_t(file, property_info->flags);

            // 5.5.3. Write data-type index
            leaf_library_write_uint64_t(file, property_info->data_type_reference.index);
            leaf_library_write_uint64_t(file, property_info->data_type_reference.flags);

            // 5.5.4. Write getter bytecode length
            leaf_library_write_uint64_t(file, property_info->get_bytecode_length);

            // 5.5.5. Write getter bytecode offset
            leaf_library_write_uint64_t(file, property_info->get_bytecode_offset);

            // 5.5.6. Write setter bytecode length
            leaf_library_write_uint64_t(file, property_info->set_bytecode_length);

            // 5.5.7. Write setter bytecode offset
            leaf_library_write_uint64_t(file, property_info->set_bytecode_offset);
        }
        // 5.6. Write methods
        leaf_library_write_uint64_t(file, type->methods.size);
        for (size_t method_index = 0; method_index < type->methods.size; method_index++)
        {
            leaf_method_info_ptr method_info = type->methods.data + method_index;

            // 5.6.1. Write method_info name
            if (!leaf_string_serialize(file, method_info->name)) { return 1; }

            // 5.6.2. Write flags
            leaf_library_write_uint64_t(file, method_info->flags);

            // 5.6.3. Write method_info_type
            leaf_library_write_uint64_t(file, method_info->type);

            // 5.6.4. Write return_type_reference
            leaf_library_write_uint64_t(file, method_info->return_type_reference.index == SIZE_MAX ? UINT64_MAX : method_info->return_type_reference.index);
            leaf_library_write_uint64_t(file, method_info->return_type_reference.flags);

            // 5.6.5. Write bytecode_length
            leaf_library_write_uint64_t(file, method_info->bytecode_length);

            // 5.6.6. Write bytecode_offset
            leaf_library_write_uint64_t(file, method_info->bytecode_offset);

            // 5.6.7. Write out all parameters of this method_info
            leaf_library_write_uint64_t(file, method_info->parameters.size);
            for (size_t parameter_index = 0; parameter_index < method_info->parameters.size; parameter_index++)
            {
                leaf_parameter_info_ptr parameter_info = method_info->parameters.data + parameter_index;

                // 5.6.7.1. Write field_info name
                if (!leaf_string_serialize(file, parameter_info->name)) { return 1; }

                // 5.6.7.2. Write type_reference
                leaf_library_write_uint64_t(file, parameter_info->type_reference.index);
                leaf_library_write_uint64_t(file, parameter_info->type_reference.flags);
            }
        }

        // 5.7. Write bytecode.size
        leaf_library_write_uint64_t(file, type->bytecode.size);

        // 5.8. Write bytecode.data
        fwrite(type->bytecode.data, sizeof(uint8_t), type->bytecode.size, file);

        // 5.9. Write refered method list
        leaf_library_write_uint64_t(file, type->referred_methods.size);
        for (size_t refered_method_index = 0; refered_method_index < type->referred_methods.size; refered_method_index++)
        {
            // 5.9.1. Write type_reference_index
            leaf_library_write_uint64_t(file, type->referred_methods.data[refered_method_index].type_reference_index);

            // 5.9.2. Write referred_method_index
            leaf_library_write_uint64_t(file, type->referred_methods.data[refered_method_index].referred_method_index);

            // 5.9.3. Write bytecode_index
            leaf_library_write_uint64_t(file, type->referred_methods.data[refered_method_index].bytecode_index);
        }
    }

    return 0;
}

int leaf_library_deserialize_v1(FILE* file, leaf_library_list loaded_libraries, leaf_library* output)
{
    // 1. Read in meta_info
    struct leaf_library_meta_info meta_info;
    meta_info.version = leaf_library_read_uint32_t(file);
    meta_info.attributes = leaf_library_read_uint32_t(file);
    meta_info.dependant_libraries = leaf_library_read_uint32_t(file);
    meta_info.types = leaf_library_read_uint32_t(file);

    // 2. Read in attributes
    if (!leaf_library_attribute_list_create(&output->attributes, meta_info.attributes)) { return 1; }
    for (size_t index = 0; index < meta_info.attributes; index++)
    {
        if (!leaf_string_deserialize(file, &output->attributes.data[index].key)) { return 1; }
        if (!leaf_string_deserialize(file, &output->attributes.data[index].value)) { return 1; }
    }

    // 3. Read in and try to find libraries this depends on
    int dependencies_load_error_flag = 0;
    if (!leaf_library_ptr_list_create(&output->dependencies, meta_info.dependant_libraries)) { return 1; }
    for (size_t index = 0; index < meta_info.dependant_libraries; index++)
    {
        leaf_string str;
        if (!leaf_string_deserialize(file, &str)) { return 1; }
        output->dependencies.data[index] = NULL;
        for (size_t loaded_library_index = 0; loaded_library_index < loaded_libraries.size; loaded_library_index++)
        {
            if (loaded_libraries.data[loaded_library_index].name.length == str.length
                && strcmp(loaded_libraries.data[loaded_library_index].name.data, str.data) == 0)
            {
                output->dependencies.data[index] = loaded_libraries.data + loaded_library_index;
                break;
            }
        }
        if (!output->dependencies.data[index]) { dependencies_load_error_flag = 1; }
    }
    if (dependencies_load_error_flag) { return 1; }

    // 4. Read in the names of the types of inside of the library
    if (!leaf_type_list_create(&output->types, meta_info.types)) { return 1; }
    for (size_t type_index = 0; type_index < meta_info.types; type_index++)
    {
        leaf_type_ptr type = output->types.data + type_index;
        type->library = output;

        // 4.1 Read in type-name
        if (!leaf_string_deserialize(file, &type->name)) { return 1; }
    }

    // 5. Read in everything else from the types of the library
    for (size_t type_index = 0; type_index < meta_info.types; type_index++)
    {
        leaf_type_ptr type = output->types.data + type_index;
        size_t capacity = 0;

        // 5.1 Read in flags
        type->flags = leaf_library_read_uint64_t(file);

        // 5.2 Read in static_data and prepare the list
        capacity = leaf_library_read_uint64_t(file);
        if (!uint8_list_create(&type->static_data, capacity)) { return 1; }

        // 5.3 Read in refered types list and try to find the refered types
        int refered_types_load_error_flag = false;
        capacity = leaf_library_read_uint64_t(file);
        if (!leaf_type_ptr_list_create(&type->referred_types, capacity)) { return 1; }
        for (size_t refered_type_index = 0; refered_type_index < capacity; refered_type_index++)
        {
            leaf_string str;
            if (!leaf_string_deserialize(file, &str)) { return 1; }
            if (!(type->referred_types.data[refered_type_index] = leaf_library_find_type(
                output, str, &type->referred_types.data[refered_type_index])))
            {
                for (size_t loaded_library_index = 0; loaded_library_index < loaded_libraries.size; loaded_library_index++)
                {
                    if ((type->referred_types.data[refered_type_index] = leaf_library_find_type(
                        &loaded_libraries.data[loaded_library_index], str, &type->referred_types.data[refered_type_index])))
                    {
                        break;
                    }
                }
                if (!type->referred_types.data[refered_type_index]) { dependencies_load_error_flag = 1; }
            }
        }
        if (dependencies_load_error_flag) { return 1; }

        // 5.4 Read in and prepare fields list
        capacity = leaf_library_read_uint64_t(file);
        if (!leaf_field_info_list_create(&type->fields, capacity)) { return 1; }
        for (size_t field_index = 0; field_index < capacity; field_index++)
        {
            leaf_field_info_ptr field_info = type->fields.data + field_index;

            // 5.4.1 Read in field_info name
            if (!leaf_string_deserialize(file, &field_info->name)) { return 1; }

            // 5.4.2 Read in field_info flags
            field_info->flags = leaf_library_read_uint64_t(file);

            // 5.4.3 Read in field_info data_type_reference
            field_info->data_type_reference.index = leaf_library_read_uint64_t(file);
            field_info->data_type_reference.flags = leaf_library_read_uint64_t(file);

            // 5.4.4 Read in field_info data-offset
            field_info->offset = leaf_library_read_uint64_t(file);

            // 5.4.5 Read in field_info data-size
            field_info->size = leaf_library_read_uint64_t(file);
        }

        // 5.5 Read in and prepare property_info_list
        capacity = leaf_library_read_uint64_t(file);
        if (!leaf_property_info_list_create(&type->properties, capacity)) { return 1; }
        for (size_t property_index = 0; property_index < capacity; property_index++)
        {
            leaf_property_info_ptr property_info = type->properties.data + property_index;

            // 5.5.1 Read in field_info name
            if (!leaf_string_deserialize(file, &property_info->name)) { return 1; }

            // 5.5.2 Read in property_info flags
            property_info->flags = leaf_library_read_uint64_t(file);

            // 5.5.3 Read in property_info data_type_reference
            property_info->data_type_reference.index = leaf_library_read_uint64_t(file);
            property_info->data_type_reference.flags = leaf_library_read_uint64_t(file);

            // 5.5.4 Read in property_info getter bytecode length
            property_info->get_bytecode_length = leaf_library_read_uint64_t(file);

            // 5.5.5 Read in property_info getter bytecode offset
            property_info->get_bytecode_offset = leaf_library_read_uint64_t(file);

            // 5.5.6 Read in property_info setter bytecode length
            property_info->set_bytecode_length = leaf_library_read_uint64_t(file);

            // 5.5.7 Read in property_info setter bytecode offset
            property_info->set_bytecode_offset = leaf_library_read_uint64_t(file);
        }

        // 5.6 Read in and prepare method_info_list
        capacity = leaf_library_read_uint64_t(file);
        if (!leaf_method_info_list_create(&type->methods, capacity)) { return 1; }
        for (size_t method_index = 0; method_index < capacity; method_index++)
        {
            leaf_method_info_ptr method_info = type->methods.data + method_index;

            // 5.6.1 Read in method_info name
            if (!leaf_string_deserialize(file, &method_info->name)) { return 1; }

            // 5.6.2 Read in method_info flags
            method_info->flags = leaf_library_read_uint64_t(file);

            // 5.6.3 Read in method_info type
            method_info->type = leaf_library_read_uint64_t(file);

            // 5.6.4 Read in method_info return_type_reference
            method_info->return_type_reference.index = leaf_library_read_uint64_t(file);
            method_info->return_type_reference.flags = leaf_library_read_uint64_t(file);

            // 5.6.5 Read in method_info getter bytecode length
            method_info->bytecode_length = leaf_library_read_uint64_t(file);

            // 5.6.6 Read in method_info getter bytecode offset
            method_info->bytecode_offset = leaf_library_read_uint64_t(file);

            // 5.6.7 Read in method_info parameters and prepare the list
            capacity = leaf_library_read_uint64_t(file);
            if (!leaf_parameter_info_list_create(&method_info->parameters, capacity)) { return 1; }
            for (size_t parameter_index = 0; parameter_index < method_info->parameters.size; parameter_index++)
            {
                leaf_parameter_info_ptr parameter_info = method_info->parameters.data + parameter_index;

                // 5.6.7.1. Read field_info name
                if (!leaf_string_deserialize(file, &parameter_info->name)) { return 1; }

                // 5.6.7.2. Read type_reference
                parameter_info->type_reference.index = leaf_library_read_uint64_t(file);
                parameter_info->type_reference.flags = leaf_library_read_uint64_t(file);
            }
        }

        // 5.7. Read bytecode.size
        capacity = leaf_library_read_uint64_t(file);
        if (!uint8_list_create(&type->bytecode, capacity)) { return 1; }

        // 5.8. Read bytecode.data
        fread(type->bytecode.data, sizeof(uint8_t), capacity, file);

        // 5.9 Read in refered types list and try to find the refered types
        int refered_types_load_error_flag = false;
        capacity = leaf_library_read_uint64_t(file);
        if (!leaf_method_call_reference_list_create(&type->referred_methods, capacity)) { return 1; }
        for (size_t refered_method_index = 0; refered_method_index < capacity; refered_method_index++)
        {
            leaf_method_call_reference* method_call_reference = type->referred_methods.data + refered_method_index;
            // 5.9.1. Read in type_reference_index
            method_call_reference->type_reference_index = leaf_library_read_uint64_t(file);

            // 5.9.2. Read in referred_method_index
            method_call_reference->referred_method_index = leaf_library_read_uint64_t(file);

            // 5.9.3. Read in bytecode_index
            method_call_reference->bytecode_index = leaf_library_read_uint64_t(file);

            // Get refered type
            if (method_call_reference->referred_method_index >= type->referred_types.size) { dependencies_load_error_flag = 1; continue; }
            leaf_type_ptr refered_type = type->referred_types.data[method_call_reference->referred_method_index];

            // Get refered method
            if (method_call_reference->referred_method_index >= refered_type->methods.size) { dependencies_load_error_flag = 1; continue; }
            leaf_method_info_ptr refered_method = refered_type->methods.data + method_call_reference->referred_method_index;

            // Update the address
            if (method_call_reference->bytecode_index >= type->bytecode.size) { dependencies_load_error_flag = 1; continue; }
            *((uint64_t*)(type->bytecode.data + method_call_reference->bytecode_index)) = ((uint64_t*)(refered_type->bytecode.data + refered_method->bytecode_offset));
        }
        if (dependencies_load_error_flag) { return 1; }
    }
    return 0;
}
int leaf_library_deserialize(FILE* file, leaf_library_list loaded_libraries, leaf_library* output)
{
    uint32_t version = leaf_library_read_uint32_t(file);
    fseek(file, 0, SEEK_SET);
    switch (version)
    {
        case 0: return leaf_library_deserialize_v1(file, loaded_libraries, output);
        default: return -1;
    }
}

int leaf_string_serialize(FILE* file, leaf_string input)
{
    leaf_library_write_uint64_t(file, input.length);
    fwrite(input.data, sizeof(char), input.length, file);
    return 0;
}

int leaf_string_deserialize(FILE* file, leaf_string* output)
{
    output->length = leaf_library_read_uint64_t(file);
    if (leaf_string_create3(output->length, output)) { return 1; }
    fread(output->data, sizeof(char), output->length, file);
    return 0;
}
