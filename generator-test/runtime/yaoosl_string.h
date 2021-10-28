#ifndef __leaf_STRING_H__
#define __leaf_STRING_H__

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct leaf_string
    {
        size_t length;
        char* data;
    } leaf_string;
    typedef leaf_string* leaf_string_ptr;

    // Copies the contents of a leaf_string into another.
    // @param input     The original leaf_string.
    // @param output    A location the copied instance should be put in. No check will be performed wether the string actually exists or not!
    // @return          Returns 0 on success and a non-null value on failure.;
    int leaf_string_copy(const leaf_string input, leaf_string_ptr output);

    // Creates a new string from the provided input.
    // @param input     The character stream string. strlen will be used to count the length of the string.
    // @param output    A location the created instance should be put in. No check will be performed wether the string actually exists or not!
    // @return          Returns 0 on success and a non-null value on failure.
    int leaf_string_create(const char* input, leaf_string_ptr output);

    // Creates a new string from the provided input.
    // @param input     The character stream string.
    // @param length    The length of the input string.
    // @param output    A location the created instance should be put in. No check will be performed wether the string actually exists or not!
    // @return          Returns 0 on success and a non-null value on failure.
    int leaf_string_create2(const char* input, size_t length, leaf_string_ptr output);

    // Creates a new string with the given capacity.
    // @param capacity  The capacity of the input string.
    // @param output    A location the created instance should be put in. No check will be performed wether the string actually exists or not!
    // @return          Returns 0 on success and a non-null value on failure.
    int leaf_string_create3(size_t capacity, leaf_string_ptr output);

    // Destroys and thus invalidates a leaf_string string.
    // @param input     An existing leaf_string. Will be invalid after this method call.
    void leaf_string_destroy(const leaf_string input);

    // Destroys and thus invalidates a leaf_string string.
    // @param output    A location the concated string should be put in. No check will be performed wether the string actually exists or not!
    // @param left      The left leaf_string.
    // @param right     The right leaf_string
    // @return          Returns 0 on success and a non-null value on failure.
    int leaf_string_concat(leaf_string_ptr output, const leaf_string left, const leaf_string right);

    // Destroys and thus invalidates a leaf_string string.
    // @param output    A location the concated string should be put in. No check will be performed wether the string actually exists or not!
    // @param count     The count of strings in the input.
    // @param strings   The input leaf_string instances in an array.
    // @return          Returns 0 on success and a non-null value on failure.
    int leaf_string_concat_array(leaf_string_ptr output, size_t count, const leaf_string_ptr strings);

    // Destroys and thus invalidates a leaf_string string.
    // @param output    A location the joined string should be put in. No check will be performed wether the string actually exists or not!
    // @param separator The separator to put inbetween the strings.
    // @param count     The count of strings in the input.
    // @param strings   The input leaf_string instances in an array.
    // @return          Returns 0 on success and a non-null value on failure.
    int leaf_string_join_array(leaf_string_ptr output, const leaf_string separator, size_t count, const leaf_string_ptr strings);

    // Destroys and thus invalidates a leaf_string string.
    // @param output            A location the joined string should be put in. No check will be performed wether the string actually exists or not!
    // @param separator         The separator to put inbetween the strings.
    // @param separator_length  The length of the separator.
    // @param count             The count of strings in the input.
    // @param strings           The input leaf_string instances in an array.
    // @return                  Returns 0 on success and a non-null value on failure.
    int leaf_string_join_array2(leaf_string_ptr output, const char* separator, size_t separator_length, size_t count, const leaf_string_ptr strings);

#ifdef __cplusplus
}
#endif

#endif