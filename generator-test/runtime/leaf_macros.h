#ifndef __leaf_MACROS_H__
#define __leaf_MACROS_H__
#include <stddef.h>
#include <malloc.h>
#define leaf_GENERIC_HEADER_LIST2(TYPENAME, LISTNAME)\
typedef struct LISTNAME##_list {\
    size_t capacity;\
    size_t size;\
    TYPENAME* data;\
} LISTNAME##_list;\
int LISTNAME##_list_create(LISTNAME##_list* output, size_t initial_capacity);\
void LISTNAME##_list_destroy(LISTNAME##_list* input);\
int LISTNAME##_list_reserve_additional(LISTNAME##_list* list, size_t additional_size);\
int LISTNAME##_list_push_back(LISTNAME##_list* list, TYPENAME data);\
int LISTNAME##_list_pop_back(LISTNAME##_list* list, TYPENAME* output);

#define leaf_GENERIC_IMPLEMENTATION_LIST2(TYPENAME, LISTNAME)\
int LISTNAME##_list_create(LISTNAME##_list* output, size_t initial_capacity) {\
    output->capacity = initial_capacity;\
    output->size = 0;\
    output->data = (TYPENAME*)malloc(sizeof(TYPENAME) * (initial_capacity + 1));\
    if (!output->data) { return 1; }\
    memset(output->data, 0, sizeof(TYPENAME) * (initial_capacity + 1));\
    return 0;\
}\
void LISTNAME##_list_destroy(LISTNAME##_list* input) {\
    if (input->capacity > 0) {\
        free(input->data);\
        input->capacity = 0;\
        input->size = 0;\
        input->data = NULL;\
    }\
}\
int LISTNAME##_list_reserve_additional(LISTNAME##_list* list, size_t additional_size) {\
    if (list->size + additional_size >= list->capacity) {\
        TYPENAME* tmp = realloc(list->data, sizeof(TYPENAME) * (list->capacity + list->capacity + additional_size)); \
        if (!tmp) { return 1; }\
        list->data = tmp;\
        memset(list->data + list->capacity, 0, (sizeof(TYPENAME) * (list->capacity + list->capacity + additional_size)) - list->capacity);\
        list->capacity = list->capacity + list->capacity + additional_size;\
    }\
    list->size += additional_size;\
    return 0;\
}\
int LISTNAME##_list_push_back(LISTNAME##_list* list, TYPENAME data) {\
    if (list->size + 1 >= list->capacity) {\
        TYPENAME* tmp = realloc(list->data, sizeof(TYPENAME) * (list->capacity + list->capacity + 1)); \
        if (!tmp) { return 1; }\
        list->data = tmp;\
        list->capacity = list->capacity + list->capacity + 1;\
    }\
    list->data[list->size++] = data;\
    return 0;\
}\
int LISTNAME##_list_pop_back(LISTNAME##_list* list, TYPENAME* output) {\
    if (list->size == 0) { return 1; }\
    if (output) {\
        (*output) = list->data[--list->size];\
    } else {\
        list->size--;\
    }\
    return 0;\
}
#define leaf_GENERIC_HEADER_LIST(TYPENAME) leaf_GENERIC_HEADER_LIST2(TYPENAME, TYPENAME)
#define leaf_GENERIC_IMPLEMENTATION_LIST(TYPENAME) leaf_GENERIC_IMPLEMENTATION_LIST2(TYPENAME, TYPENAME)
#endif