#ifndef __leaf_LIBRARY_H__
#define __leaf_LIBRARY_H__

#include "leaf_macros.h"
#include "leaf_string.h"
#include "leaf_type.h"

#include <stdio.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif
    typedef struct leaf_library_attribute
    {
        leaf_string key;
        leaf_string value;
    } leaf_library_attribute;
    leaf_GENERIC_HEADER_LIST(leaf_library_attribute);

    struct leaf_library;
    leaf_GENERIC_HEADER_LIST2(struct leaf_library*, leaf_library_ptr);
    leaf_GENERIC_HEADER_LIST2(struct leaf_library, leaf_library);
    typedef struct leaf_library
    {
        leaf_string name;
        leaf_type_list types;
        leaf_library_attribute_list attributes;
        leaf_library_ptr_list dependencies;
    } leaf_library;
    typedef leaf_library* leaf_library_ptr;

    // Deallocates a library and all its types.
    // Ensure to either stop the runtime fully or to unload in order.
    // @param input The leaf_library instance to unload.
    void leaf_library_destroy(leaf_library_ptr input);

    // Updates the libraries this library is depending on.
    // Should be called whenever an edit inside the library occured.
    // @param loaded_libraries The list of loaded libraries.
    // @param input The leaf_library instance.
    void leaf_library_update_dependencies(const leaf_library_list loaded_libraries, leaf_library_ptr input);

    // Attempts to locate the given type.
    // @param library The library to search.
    // @param name The typename to find.
    // @param output A valid address of an leaf_type or NULL.
    // @return Will return 0 if a type with that name was found. Returns non-null value in any other case.
    int leaf_library_find_type(const leaf_library_ptr library, leaf_string name, leaf_type_ptr* output);

    // Serializes the leaf_library to disk.
    // This should only be called after leaf_library_update_dependencies was called or if no edits occured.
    // @param file An initialized FILE stream with WRITE mode.
    // @param input The leaf_library instance.
    // @return If serialization was successfull, returns 0. In any other case this method returns a non-null value.
    int leaf_library_serialize(FILE* file, const leaf_library_list loaded_libraries, leaf_library input);

    // Serializes the leaf_library to disk.
    // @param file An initialized FILE stream with READ mode.
    // @param output A pointer to the output leaf_library variable.
    // @return If deserialization was successfull, returns 0. In any other case this method returns a non-null value.
    int leaf_library_deserialize(FILE* file, const leaf_library_list loaded_libraries, leaf_library* output);

    // Serializes the leaf_string to disk.
    // @param file An initialized FILE stream with WRITE mode.
    // @param input The leaf_string instance.
    // @return If serialization was successfull, returns 0. In any other case this method returns a non-null value.
    int leaf_string_serialize(FILE* file, leaf_string input);

    // Serializes the leaf_string to disk.
    // @param file An initialized FILE stream with READ mode.
    // @param output A pointer to the output leaf_string variable.
    // @return If deserialization was successfull, returns 0. In any other case this method returns a non-null value.
    int leaf_string_deserialize(FILE* file, leaf_string* output);

#ifdef __cplusplus
}
#endif

#endif