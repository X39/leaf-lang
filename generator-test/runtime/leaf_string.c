#include "leaf_string.h"
#include <malloc.h>
#include <string.h>

int leaf_string_copy(const leaf_string input, leaf_string_ptr output)
{
    output->data = malloc(sizeof(char) * (input.length + 1));
    if (output->data == NULL)
    {
        return -1;
    }
    strncpy(output->data, input.data, output->length);
    output->data[output->length] = '\0';
    output->length = input.length;
    return 0;
}

int leaf_string_create(const char* input, leaf_string_ptr output)
{
    output->length = strlen(input);
    output->data = malloc(sizeof(char) * (output->length + 1));
    if (output->data == NULL)
    {
        return -1;
    }
    strncpy(output->data, input, output->length);
    output->data[output->length] = '\0';
    return 0;
}

int leaf_string_create2(const char* input, size_t length, leaf_string_ptr output)
{
    output->length = length;
    if (length > 0)
    {
        output->data = malloc(sizeof(char) * (output->length + 1));
        if (output->data == NULL)
        {
            return -1;
        }
        strncpy(output->data, input, output->length);
        output->data[output->length] = '\0';
    }
    else
    {
        output->data = NULL;
    }
    return 0;
}

int leaf_string_create3(size_t capacity, leaf_string_ptr output)
{
    output->length = capacity;
    if (capacity > 0)
    {
        output->data = malloc(sizeof(char) * (output->length + 1));
        if (output->data == NULL)
        {
            return -1;
        }
    }
    else
    {
        output->data = NULL;
    }
    return 0;
}

void leaf_string_destroy(const leaf_string input)
{
    if (input.data)
    {
        free(input.data);
    }
}

int leaf_string_concat(leaf_string_ptr output, const leaf_string left, const leaf_string right)
{
    output->length = left.length + right.length;
    output->data = malloc(sizeof(char) * (output->length + 1));
    if (output->data == NULL)
    {
        return -1;
    }
    strncpy(output->data, left.data, left.length);
    strncpy(output->data + left.length, right.data, right.length);
    output->data[output->length] = '\0';
    return 0;
}

int leaf_string_concat_array(leaf_string_ptr output, size_t count, const leaf_string_ptr strings)
{
    if (count == 0)
    {
        output->data = NULL;
        output->length = 0;
        return 0;
    }
    size_t total_length = 0;
    for (size_t i = 0; i < count; i++)
    {
        total_length += strings[i].length;
    }
    output->length = total_length;
    output->data = malloc(sizeof(char) * (output->length + 1));
    if (output->data == NULL)
    {
        return -1;
    }
    total_length = 0;
    for (size_t i = 0; i < count; i++)
    {
        strncpy(output->data + total_length, strings[i].data, strings[i].length);
        total_length += strings[i].length;
    }
    output->data[output->length] = '\0';
    return 0;
}

int leaf_string_join_array(leaf_string_ptr output, const leaf_string separator, size_t count, const leaf_string_ptr strings)
{
    return leaf_string_join_array2(output, separator.data, separator.length, count, strings);
}

int leaf_string_join_array2(leaf_string_ptr output, const char* separator, size_t separator_length, size_t count, const leaf_string_ptr strings)
{
    if (count == 0)
    {
        output->data = NULL;
        output->length = 0;
        return 0;
    }
    size_t total_length = separator_length * (count - 1);
    for (size_t i = 0; i < count; i++)
    {
        total_length += strings[i].length;
    }
    output->length = total_length;
    output->data = malloc(sizeof(char) * (output->length + 1));
    if (output->data == NULL)
    {
        return -1;
    }
    total_length = 0;
    for (size_t i = 0; i < count; i++)
    {
        if (i > 0)
        {
            strncpy(output->data + total_length, separator, separator_length);
            total_length += separator_length;
        }
        strncpy(output->data + total_length, strings[i].data, strings[i].length);
        total_length += strings[i].length;
    }
    output->data[output->length] = '\0';
    return 0;
}
