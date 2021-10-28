#ifndef __leaf_TYPE_H__
#define __leaf_TYPE_H__
#include "leaf_string.h"
#include "leaf_macros.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
#include <string_view>
#include <algorithm>
extern "C" {
#endif
    enum leaf_flags
    {
        YSF_EMPTY = 0x0000,
        // If set, declares the type as namespace.
        // Incompatible with YSF_CLASS and YSF_CONTRACT
        YSF_NAMESPACE = 0x0001,
        // If set, declares the type as class.
        // Incompatible with YSF_NAMESPACE and YSF_CONTRACT
        YSF_CLASS = 0x0002,
        // If set, declares the type as a contract.
        // Incompatible with YSF_CLASS and YSF_NAMESPACE
        YSF_CONTRACT = 0x0004,
        // If set, tells that this is an instantiable class or part of an instantiable class.
        YSF_INSTANCE = 0x0008,
        // If set, tells that this is not instantiable or callable and serves only as declaration.
        YSF_ABSTRACT = 0x0010,
        // If set, the given type/method/... may not be inherited any further.
        YSF_SEALED = 0x0020,
        // If set, marks the given method/property/... as virtual and thus inheritable.
        YSF_VIRTUAL = 0x0040,
        // If set, declares this variable as having a template argument
        YSF_TEMPLATE = 0x0080,
        // If set, declares that the given variable is an array.
        YSF_ARRAY = 0x0100,
        // Implies that a pointer dereference is required to access this.
        YSF_POINTER = 0x0200,
        // If set, tells the compiler to inline the contents of a given method/...
        YSF_INLINE = 0x0400,
        // If set, indicates that a given property has a getter
        YSF_GET = 0x0800,
        // If set, indicates that a given property has a setter
        YSF_SET = 0x1000,
        YSF_RESERVED2 = 0x2000,
        YSF_RESERVED1 = 0x4000,
        YSF_RESERVED0 = 0x8000,
    };
#ifdef __cplusplus
}
static inline leaf_flags operator|(leaf_flags a, leaf_flags b)
{
    return static_cast<leaf_flags>(static_cast<int>(a) | static_cast<int>(b));
}
static inline leaf_flags operator|=(leaf_flags& a, leaf_flags b)
{
    return a = a | b;
}
static inline leaf_flags operator&(leaf_flags a, leaf_flags b)
{
    return static_cast<leaf_flags>(static_cast<int>(a) & static_cast<int>(b));
}
static inline leaf_flags operator&=(leaf_flags& a, leaf_flags b)
{
    return a = a & b;
}
extern "C" {
#endif
    enum leaf_method_info_type
    {
        YSMIT_NORMAL,
        YSMIT_INDEXER,
        YSMIT_PROPERTY,
        YSMIT_CONSTRUCTOR,
        YSMIT_DESTRUCTOR,
        YSMIT_COPYSTRUCTOR,
        YSMIT_CONVERSION,

        YSMIT_OPBINARY_ADD,
        __YSMIT_OPBINARY_START__ = YSMIT_OPBINARY_ADD,
        YSMIT_OPBINARY_SUBTRACT,
        YSMIT_OPBINARY_MULTIPLY,
        YSMIT_OPBINARY_DIVIDE,
        YSMIT_OPBINARY_TRIPPLE_SHIFT_LEFT,
        YSMIT_OPBINARY_DOUBLE_SHIFT_LEFT,
        YSMIT_OPBINARY_LESS_THEN_OR_EQUAL,
        YSMIT_OPBINARY_LESS_THEN,
        YSMIT_OPBINARY_TRIPPLE_SHIFT_RIGHT,
        YSMIT_OPBINARY_DOUBLE_SHIFT_RIGHT,
        YSMIT_OPBINARY_GREATER_THEN_OR_EQUAL,
        YSMIT_OPBINARY_GREATER_THEN,
        YSMIT_OPBINARY_LOGICAL_OR,
        YSMIT_OPBINARY_BITWISE_OR,
        YSMIT_OPBINARY_BITWISE_XOR,
        YSMIT_OPBINARY_LOGICAL_AND,
        YSMIT_OPBINARY_BITWISE_AND,
        YSMIT_OPBINARY_EQUAL,
        YSMIT_OPBINARY_SAME,
        YSMIT_OPBINARY_NOT_EQUAL,
        YSMIT_OPBINARY_APPROXIMATION_EQUAL,
        __YSMIT_OPBINARY_END__ = YSMIT_OPBINARY_BITWISE_AND,
        YSMIT_OPUNARY_PLUS,
        __YSMIT_OPUNARY_START__ = YSMIT_OPUNARY_PLUS,
        YSMIT_OPUNARY_MINUS,
        YSMIT_OPUNARY_LOGICAL_NOT,
        YSMIT_OPUNARY_BITWISE_NOT,
        __YSMIT_OPUNARY_END__ = YSMIT_OPUNARY_BITWISE_NOT,
    };
#ifndef __leaf_RUNTIME_H__
    struct leaf_runtime;
#endif
    typedef void (*leaf_method_callback)(struct leaf_runtime* runtime);
    struct leaf_parameter_info;
    struct leaf_method_info;
    struct leaf_type;
    struct leaf_library;

#define leaf_INVALID_SIZE SIZE_MAX
#define leaf_INVALID_OFFSET SIZE_MAX
#define leaf_POINTER_SIZE sizeof(void*)

#define leaf_TYPE_REFERENCE_VOID_INDEX SIZE_MAX
    typedef struct leaf_type_reference
    {
        // The flags owned by this type reference.
        // See leaf_flags for more infos.
        enum leaf_flags flags;
        
        // The index of the type referred to.
        // Index refers to the first leaf_type most local to the current position,
        // as in: leaf_parameter_info would refer to the type that owns the leaf_method_info.
        // Note that SIZE_MAX is reserved for void.
        size_t index;
    } leaf_type_reference;
#ifdef __cplusplus
    inline bool operator == (const leaf_type_reference& l, const leaf_type_reference& r)
    {
        return l.flags == r.flags && l.index == r.index;
    }
    inline bool operator != (const leaf_type_reference& l, const leaf_type_reference& r)
    {
        return !(l == r);
    }
#endif

    typedef struct leaf_parameter_info
    {
        // The name of this parameter
        leaf_string name;

        // The type this represents.
        leaf_type_reference type_reference;
    } leaf_parameter_info;
    typedef leaf_parameter_info* leaf_parameter_info_ptr;
    leaf_GENERIC_HEADER_LIST(leaf_parameter_info);

    typedef struct leaf_method_info
    {
        // The name of this method_info.
        leaf_string name;
        // The type of this method_info.
        enum leaf_method_info_type type;
        // The flags owned by this method_info. See leaf_flags for more infos.
        enum leaf_flags flags;

        // The offset to the actual code inside the owned_by->bytecode field in bytes.
        size_t bytecode_offset;
        // The length of the actual code inside the owned_by->bytecode field in bytes.
        size_t bytecode_length;
        // If not NULL, the JIT compiled version of this method.
        leaf_method_callback callback;

        // The type this represents.
        leaf_type_reference return_type_reference;
        // The parameters of this method_info.
        leaf_parameter_info_list parameters;
    } leaf_method_info;
    typedef leaf_method_info* leaf_method_info_ptr;
    leaf_GENERIC_HEADER_LIST(leaf_method_info);

    typedef struct leaf_field_info
    {
        // The name of this field_info.
        leaf_string name;
        // The flags owned by this field_info. See leaf_flags for more infos.
        enum leaf_flags flags;

        // The size of this field in bytes.
        size_t size;
        // The offset to this field in bytes.
        size_t offset;

        // The type this represents.
        leaf_type_reference data_type_reference;
    } leaf_field_info;
    typedef leaf_field_info* leaf_field_info_ptr;
    leaf_GENERIC_HEADER_LIST(leaf_field_info);
    leaf_GENERIC_HEADER_LIST2(uint8_t, uint8);
    leaf_GENERIC_HEADER_LIST2(struct leaf_type, leaf_type);
    leaf_GENERIC_HEADER_LIST2(struct leaf_type*, leaf_type_ptr);
    typedef struct leaf_method_call_reference
    {
        // The type-reference index of the type containing the referred method.
        size_t type_reference_index;

        // Index of the referred index inside of its parent method.
        size_t referred_method_index;

        // Index to the bytecode where the method is referred inside the calling type.
        size_t bytecode_index;
    } leaf_method_call_reference;
    leaf_GENERIC_HEADER_LIST(leaf_method_call_reference);
    typedef struct leaf_type
    {
        // Full typename. Namespace and type are separated by a single ':'.
        leaf_string name;
        // The flags owned by this type. See leaf_flags for more infos.
        enum leaf_flags flags;
        // All methods contained in this.
        // Includes methods for:
        // - (copy)constructors
        // - destructors
        // - indexers
        // - methods
        // - operators
        // - property getters
        // - property setters
        // - conversions
        leaf_method_info_list methods;
        // All fields relating to this type.
        leaf_field_info_list fields;

        // The types referred inside of any methods/properties/fields/... of this type.
        leaf_type_ptr_list referred_types;

        // The methods referred to inside the bytecode of this type.
        leaf_method_call_reference_list referred_methods;

        // Data for static fields.
        uint8_list static_data;

        // Instance-size
        size_t instance_size;

        // Method and property bytecode data.
        uint8_list bytecode;

        // The library this type lives in
        struct leaf_library* library;
    } leaf_type;
    typedef leaf_type* leaf_type_ptr;
#ifdef __cplusplus
    inline bool operator == (const leaf_type_ptr& l, const std::string_view& r)
    {
        std::string_view lv(l->name.data, l->name.size);
        return lv == r;
    }
    inline bool operator != (const leaf_type_ptr& l, const std::string_view& r)
    {
        return !(l == r);
    }
#endif

#ifdef __cplusplus
}
#endif

#endif