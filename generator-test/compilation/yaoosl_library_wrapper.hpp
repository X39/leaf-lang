#pragma once
#include "../runtime/leaf_library.h"
#include <map>
#include <string>
#include <string_view>
#include <shared_mutex>
#include <vector>
#include <memory>

namespace leaf::compilation
{
    class library_wrapper
    {
        mutable std::shared_mutex m_mutex;
        leaf_library_ptr m_pointer;
        std::map<std::string, leaf_type_ptr> m_types_map;
    public:
        library_wrapper(leaf_library_ptr ptr)
        {
            exchange(ptr);
        }
        ~library_wrapper()
        {
            if (m_pointer)
            {
                delete m_pointer;
            }
        }

        leaf_library_ptr exchange(leaf_library_ptr newPtr)
        {
            std::unique_lock lock(m_mutex);
            m_types_map.clear();

            auto tmp = m_pointer;
            m_pointer = newPtr;

            for (size_t i = 0; i < m_pointer->types.size; i++)
            {
                std::string key(m_pointer->types.data[i].name.data, m_pointer->types.data[i].name.length);
                m_types_map[key] = m_pointer->types.data + i;
            }
            return tmp;
        }

        // Allows to register a new type.
        // @param type The type to register.
        // @return Only returns true if the type was registered successfully.
        //         - Returns false if the leaf_type.name is empty.
        //         - Returns false if the leaf_type.name.data is NULL.
        //         - Returns false if the leaf_type.name already exists.
        bool register_type(leaf_type type);

        // Allows to refer an existing type.
        // If the refered_type is not inside of the current library,
        // that types library will be added to the dependency list of the current library.
        // If the refered_type was already refered, no additional reference will be added
        // and instead the existing reference is returned.
        // 
        // Will throw a std::runtime_error if:
        //         - target_type is NULL
        //         - target_type is not part of this library
        //         - refered_type is NULL
        //         - refered_type library pointer is NULL
        //         - Circular Dependency would be introduced
        // 
        // @param target_type The type to add the refered_type to
        // @param refered_type The type that is supposed to be refered
        // @return A valid type reference for target_type
        leaf_type_reference refer_type(leaf_type_ptr target_type, const leaf_type_ptr refered_type);

        // Wrapper around library_wrapper::try_get_type
        // that throws an exception if a type was not found.
        // 
        // Will throw a std::runtime_error if:
        //         - Type refered by name is not existing
        // @param name The name of the type to find.
        // @return The type found.
        leaf_type_ptr get_type(std::string_view name) const;

        // Attempts to find a type.
        // @param name The name of the type to find.
        // @param out_type The out reference that will be altered if a type was found.
        // @return True if the type was found, false if not.
        bool try_get_type(std::string_view name, leaf_type_ptr& out_type) const;

        // Checks wether a given type with the provided name exists or not.
        // @param name The name of the potentially existing type to check its existance of.
        // @return true if the type is found, false if it it was not found.
        bool has_type(std::string_view name) const;


        using iterator = leaf_type_ptr;
        iterator begin() { return m_pointer ? m_pointer->types.data : nullptr; }
        iterator end() { return m_pointer ? m_pointer->types.data + m_pointer->types.size : nullptr; }
        using const_iterator = const leaf_type_ptr;
        const_iterator begin() const { return m_pointer ? m_pointer->types.data : nullptr; }
        const_iterator end() const { return m_pointer ? m_pointer->types.data + m_pointer->types.size : nullptr; }
    };
    class library_collection
    {
        std::vector<std::shared_ptr<library_wrapper>> m_libraries;
    public:

        void push_back(std::shared_ptr<library_wrapper> library)
        {
            m_libraries.push_back(library);
        }

        // Attempts to find a type in all libraries registered.
        // @param name The name of the type to find.
        // @param out_type The out reference that will be altered if a type was found.
        // @return True if the type was found, false if not.
        bool try_get_type(std::string_view name, leaf_type_ptr& out_type) const;


        using iterator = std::vector<std::shared_ptr<library_wrapper>>::iterator;
        iterator begin() { return m_libraries.begin(); }
        iterator end() { return m_libraries.end(); }
        using const_iterator = std::vector<std::shared_ptr<library_wrapper>>::const_iterator;
        const_iterator begin() const { return m_libraries.begin(); }
        const_iterator end() const { return m_libraries.end(); }
    };
}