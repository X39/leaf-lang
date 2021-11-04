#include "leaf_library_wrapper.hpp"
#include <stdexcept>
#include <charconv>

bool leaf::compilation::library_wrapper::register_type(leaf_type type)
{
    // Gate off invalid input
    if (type.name.length == 0) { return false; }
    if (type.name.data == NULL) { return false; }
    if (!m_pointer) { return false; }

    // Check if type is already registred
    std::string key(type.name.data, type.name.data + type.name.length);
    if (has_type(key)) { return false; }
    std::unique_lock lock(m_mutex);

    // Set library dependant values
    type.library = m_pointer;

    // Add type to the library
    if (!leaf_type_list_push_back(&m_pointer->types, type)) { throw std::bad_alloc(); }
    m_types_map[key] = m_pointer->types.data + (m_pointer->types.size - 1);
    return true;
}

static bool find_recursive(const leaf_library_ptr to_find, const leaf_library_ptr data)
{
    for (size_t i = 0; i < data->dependencies.size; ++i)
    {
        if (data->dependencies.data[i] == to_find) { return false; }
        if (!find_recursive(to_find, data->dependencies.data[i])) { return false; }
    }
    return true;
}

leaf_type_reference leaf::compilation::library_wrapper::refer_type(leaf_type_ptr target_type, const leaf_type_ptr refered_type)
{
    // Gate off invalid input
    if (!target_type) { throw std::runtime_error("target_type pointer is empty"); }
    if (target_type->library != m_pointer) { throw std::runtime_error("target_type must be living in this library"); }
    if (!refered_type) { throw std::runtime_error("refered_type pointer is empty"); }
    if (!refered_type->library) { throw std::runtime_error("refered_type library pointer is empty"); }
    
    // Variables
    leaf_type_reference type_reference;
    type_reference.flags = YSF_EMPTY;
    type_reference.index = SIZE_MAX;

    bool library_exists = false;

    if (refered_type->library == m_pointer)
    {
        library_exists = true;
        // Check if type is already refered
        for (size_t refered_types_index = 0; refered_types_index < target_type->refered_types.size; ++refered_types_index)
        {
            if (target_type->refered_types.data[refered_types_index] == refered_type)
            {
                // Check for type
                type_reference.index = refered_types_index;
                return type_reference;
            }
        }
    }
    else
    {
        // Try to find type in library
        for (size_t dependency_index = 0; dependency_index < m_pointer->dependencies.size; ++dependency_index)
        {
            // Check if library is already existing
            if (m_pointer->dependencies.data[dependency_index] == refered_type->library)
            {
                // Check if type is already refered
                for (size_t refered_types_index = 0; refered_types_index < target_type->refered_types.size; ++refered_types_index)
                {
                    if (target_type->refered_types.data[refered_types_index] == refered_type)
                    {
                        // Check for type
                        type_reference.index = refered_types_index;
                        return type_reference;
                    }
                }
                library_exists = true;
                break;
            }
        }
    }
    std::unique_lock lock(m_mutex);
    if (!library_exists)
    {
        for (size_t dependency_index = 0; dependency_index < m_pointer->dependencies.size; ++dependency_index)
        {
            if (find_recursive(m_pointer, m_pointer->dependencies.data[dependency_index])) { throw std::runtime_error("Cannot introduce circular dependencies"); }
        }
        if (leaf_library_ptr_list_push_back(&m_pointer->dependencies, refered_type->library)) { throw std::bad_alloc(); }
    }
    type_reference.index = target_type->refered_types.size;
    if (leaf_type_ptr_list_push_back(&target_type->refered_types, refered_type)) { throw std::bad_alloc(); }
    return type_reference;
}

leaf_type_ptr leaf::compilation::library_wrapper::get_type(std::string_view name) const
{
    leaf_type_ptr type_ptr;
    if (!try_get_type(name, type_ptr))
    {
        std::string msg = "Failed to locate type '";
        msg += name;
        msg += "'.";
        throw std::runtime_error(msg);
    }
    return type_ptr;
}

bool leaf::compilation::library_wrapper::try_get_type(std::string_view name, leaf_type_ptr& out_type) const
{
    std::shared_lock lock(m_mutex);
    std::string key(name.begin(), name.end());
    auto res = m_types_map.find(key);
    if (res == m_types_map.end()) { return false; }

    out_type = res->second;
    return true;
}

bool leaf::compilation::library_wrapper::has_type(std::string_view name) const
{
    std::shared_lock lock(m_mutex);
    std::string key(name.begin(), name.end());
    auto res = m_types_map.find(key);
    return res != m_types_map.end();
}

bool leaf::compilation::library_collection::try_get_type(std::string_view name, leaf_type_ptr& out_type) const
{
    for (auto& library : m_libraries)
    {
        if (library->try_get_type(name, out_type))
        {
            return true;
        }
    }
    return false;
}
