#ifndef __leaf_EMIT_H__
#define __leaf_EMIT_H__

#include "leaf_type.h"
#include "leaf_opcodes.h"

#ifdef __cplusplus
extern "C" {
#endif

    int leaf_emit_static_call(leaf_type_ptr type, leaf_method_info_ptr ptr);

    // Emits the opcode YSOPC_NOP into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_nop(uint8_list* blob);
    // Emits the opcode YSOPC_HALT into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_halt(uint8_list* blob);
    // Emits the opcode YSOPC_i8_STACK_RESERVE into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @param bytes The amount of bytes to reserve
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_i8_stack_reserve(uint8_list* blob, uint8_t bytes);
    // Emits the opcode YSOPC_i16_STACK_RESERVE into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @param bytes The amount of bytes to reserve
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_i16_stack_reserve(uint8_list* blob, uint16_t bytes);
    // Emits the opcode YSOPC_i32_STACK_RESERVE into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @param bytes The amount of bytes to reserve
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_i32_stack_reserve(uint8_list* blob, uint64_t bytes);
    // Emits the opcode YSOPC_i64_STACK_RESERVE into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @param bytes The amount of bytes to reserve
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_i64_stack_reserve(uint8_list* blob, uint64_t bytes);
    // Emits one of the opcodes matching the following pattern into the blob: YSOPC_i*_STACK_RESERVE
    // The method will automatically choose the smallest possible one.
    // @param blob The uint8 data that represents the bytecode
    // @param bytes The amount of bytes to reserve
    // @return 0 on success, 1 if allocation for additional space failed.
    static int leaf_emit_i_stack_reserve(uint8_list* blob, uint64_t bytes)
    {
        if (bytes <= UINT8_MAX) { return leaf_emit_i8_stack_reserve(blob, bytes); }
        else if (bytes <= UINT16_MAX) { return leaf_emit_i16_stack_reserve(blob, bytes); }
        else if (bytes <= UINT32_MAX) { return leaf_emit_i32_stack_reserve(blob, bytes); }
        else { return leaf_emit_i64_stack_reserve(blob, bytes); }
    }
    // Emits the opcode YSOPC_i8_m1_STACK_RESERVE_d into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_i8_m1_stack_reserve_d(uint8_list* blob, uint8_t bytes, uint8_t ysopc_m1_modifier);
    // Emits the opcode YSOPC_i16_m1_STACK_RESERVE_d into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_i16_m1_stack_reserve_d(uint8_list* blob, uint16_t bytes, uint8_t ysopc_m1_modifier);
    // Emits the opcode YSOPC_i32_m1_STACK_RESERVE_d into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_i32_m1_stack_reserve_d(uint8_list* blob, uint32_t bytes, uint8_t ysopc_m1_modifier);
    // Emits the opcode YSOPC_i64_m1_STACK_RESERVE_d into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_i64_m1_stack_reserve_d(uint8_list* blob, uint64_t bytes, uint8_t ysopc_m1_modifier);
    // Emits one of the opcodes matching the following pattern into the blob: YSOPC_i*_m1_STACK_RESERVE_d
    // The method will automatically choose the smallest possible one.
    // @param blob The uint8 data that represents the bytecode
    // @param multiplier The amount of multiplier to reserve
    // @param ysopc_m1_modifier YSOPC_M1* modifier that describes the value on the value-stack
    // @return 0 on success, 1 if allocation for additional space failed.
    static int leaf_emit_i_m1_stack_reserve_d(uint8_list* blob, uint64_t multiplier, uint8_t ysopc_m1_modifier)
    {
        if (multiplier <= UINT8_MAX) { return leaf_emit_i8_m1_stack_reserve_d(blob, multiplier, ysopc_m1_modifier); }
        else if (multiplier <= UINT16_MAX) { return leaf_emit_i16_m1_stack_reserve_d(blob, multiplier, ysopc_m1_modifier); }
        else if (multiplier <= UINT32_MAX) { return leaf_emit_i32_m1_stack_reserve_d(blob, multiplier, ysopc_m1_modifier); }
        else { return leaf_emit_i64_m1_stack_reserve_d(blob, multiplier, ysopc_m1_modifier); }
    }


    // Emits the opcode YSOPC_i8_HEAP_ALLOC into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_i8_heap_alloc(uint8_list* blob, uint8_t bytes);
    // Emits the opcode YSOPC_i16_HEAP_ALLOC into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_i16_heap_alloc(uint8_list* blob, uint16_t bytes);
    // Emits the opcode YSOPC_i32_HEAP_ALLOC into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_i32_heap_alloc(uint8_list* blob, uint32_t bytes);
    // Emits the opcode YSOPC_i64_HEAP_ALLOC into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_i64_heap_alloc(uint8_list* blob, uint64_t bytes);
    // Emits one of the opcodes matching the following pattern into the blob: YSOPC_i*_HEAP_ALLOC
    // The method will automatically choose the smallest possible one.
    // @param blob The uint8 data that represents the bytecode
    // @param bytes The amount of bytes to reserve
    // @return 0 on success, 1 if allocation for additional space failed.
    static int leaf_emit_i_heap_alloc(uint8_list* blob, uint64_t bytes)
    {
        if (bytes <= UINT8_MAX) { return leaf_emit_i8_heap_alloc(blob, bytes); }
        else if (bytes <= UINT16_MAX) { return leaf_emit_i16_heap_alloc(blob, bytes); }
        else if (bytes <= UINT32_MAX) { return leaf_emit_i32_heap_alloc(blob, bytes); }
        else { return leaf_emit_i64_heap_alloc(blob, bytes); }
    }
    // Emits the opcode YSOPC_i8_m1_HEAP_ALLOC_d into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_i8_m1_heap_alloc_d(uint8_list* blob, uint8_t multiplier, uint8_t ysopc_m1_modifier);
    // Emits the opcode YSOPC_i16_m1_HEAP_ALLOC_d into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_i16_m1_heap_alloc_d(uint8_list* blob, uint16_t multiplier, uint8_t ysopc_m1_modifier);
    // Emits the opcode YSOPC_i32_m1_HEAP_ALLOC_d into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_i32_m1_heap_alloc_d(uint8_list* blob, uint32_t multiplier, uint8_t ysopc_m1_modifier);
    // Emits the opcode YSOPC_i64_m1_HEAP_ALLOC_d into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_i64_m1_heap_alloc_d(uint8_list* blob, uint64_t multiplier, uint8_t ysopc_m1_modifier);
    // Emits one of the opcodes matching the following pattern into the blob: YSOPC_i*_m1_HEAP_ALLOC_d
    // The method will automatically choose the smallest possible one.
    // @param blob The uint8 data that represents the bytecode
    // @param multiplier The amount of multiplier to reserve
    // @param ysopc_m1_modifier YSOPC_M1* modifier that describes the value on the value-stack
    // @return 0 on success, 1 if allocation for additional space failed.
    static int leaf_emit_i_m1_heap_alloc_d(uint8_list* blob, uint64_t multiplier, uint8_t ysopc_m1_modifier)
    {
        if (multiplier <= UINT8_MAX) { return leaf_emit_i8_m1_heap_alloc_d(blob, multiplier, ysopc_m1_modifier); }
        else if (multiplier <= UINT16_MAX) { return leaf_emit_i16_m1_heap_alloc_d(blob, multiplier, ysopc_m1_modifier); }
        else if (multiplier <= UINT32_MAX) { return leaf_emit_i32_m1_heap_alloc_d(blob, multiplier, ysopc_m1_modifier); }
        else { return leaf_emit_i64_m1_heap_alloc_d(blob, multiplier, ysopc_m1_modifier); }
    }
    
    // Emits the opcode YSOPC_o8_v8_MOVE_d into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @param offset The offset of targeted the value on the value stack
    // @param bytes The size of the value on the value stack at SL
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o8_v8_move_d(uint8_list* blob, uint8_t offset, uint8_t bytes);
    // Emits the opcode YSOPC_o8_v16_MOVE_d into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @param offset The offset of targeted the value on the value stack
    // @param bytes The size of the value on the value stack at SL
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o8_v16_move_d(uint8_list* blob, uint8_t offset, uint16_t bytes);
    // Emits the opcode YSOPC_o16_v8_MOVE_d into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @param offset The offset of targeted the value on the value stack
    // @param bytes The size of the value on the value stack at SL
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o16_v8_move_d(uint8_list* blob, uint16_t offset, uint8_t bytes);
    // Emits the opcode YSOPC_o16_v16_MOVE_d into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @param offset The offset of targeted the value on the value stack
    // @param bytes The size of the value on the value stack at SL
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o16_v16_move_d(uint8_list* blob, uint16_t offset, uint16_t bytes);
    // Emits the opcode YSOPC_o32_v32_MOVE_d into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @param offset The offset of targeted the value on the value stack
    // @param bytes The size of the value on the value stack at SL
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o32_v32_move_d(uint8_list* blob, uint32_t offset, uint32_t bytes);
    // Emits the opcode YSOPC_o64_v64_MOVE_d into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @param offset The offset of targeted the value on the value stack
    // @param bytes The size of the value on the value stack at SL
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o64_v64_move_d(uint8_list* blob, uint64_t offset, uint64_t bytes);

    // Emits one of the opcodes matching the following pattern into the blob: YSOPC_o*_v*_MOVE_d
    // The method will automatically choose the smallest possible one.
    // @param blob The uint8 data that represents the bytecode
    // @param offset The offset of targeted the value on the value stack
    // @param bytes The size of the value on the value stack at SL
    // @return 0 on success, 1 if allocation for additional space failed.
    static int leaf_emit_o_v_move_d(uint8_list* blob, uint64_t offset, uint64_t bytes)
    {
        if (offset <= UINT8_MAX && bytes <= UINT8_MAX) { return leaf_emit_o8_v8_move_d(blob, offset, bytes); }
        else if (offset <= UINT8_MAX && bytes <= UINT16_MAX) { return leaf_emit_o8_v16_move_d(blob, offset, bytes); }
        else if (offset <= UINT16_MAX && bytes <= UINT8_MAX) { return leaf_emit_o16_v8_move_d(blob, offset, bytes); }
        else if (offset <= UINT16_MAX && bytes <= UINT16_MAX) { return leaf_emit_o16_v16_move_d(blob, offset, bytes); }
        else if (offset <= UINT32_MAX && bytes <= UINT32_MAX) { return leaf_emit_o32_v32_move_d(blob, offset, bytes); }
        else { return leaf_emit_o64_v64_move_d(blob, offset, bytes); }
    }

    // Emits the opcode YSOPC_o8_o8_i8_GET_DEREF into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @param pointer_offset The offset of the to dereference pointer
    // @param value_offset The offset to the value inside the dereferenced pointer
    // @param value_length The length of the value inside the dereferenced pointer
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o8_o8_i8_get_deref(uint8_list* blob, uint8_t pointer_offset, uint8_t value_offset, uint8_t value_length);
    // Emits the opcode YSOPC_o8_o8_i16_GET_DEREF into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @param pointer_offset The offset of the to dereference pointer
    // @param value_offset The offset to the value inside the dereferenced pointer
    // @param value_length The length of the value inside the dereferenced pointer
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o8_o8_i16_get_deref(uint8_list* blob, uint8_t pointer_offset, uint8_t value_offset, uint16_t value_length);
    // Emits the opcode YSOPC_o8_o16_i8_GET_DEREF into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @param pointer_offset The offset of the to dereference pointer
    // @param value_offset The offset to the value inside the dereferenced pointer
    // @param value_length The length of the value inside the dereferenced pointer
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o8_o16_i8_get_deref(uint8_list* blob, uint8_t pointer_offset, uint16_t value_offset, uint8_t value_length);
    // Emits the opcode YSOPC_o8_o16_i16_GET_DEREF into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @param pointer_offset The offset of the to dereference pointer
    // @param value_offset The offset to the value inside the dereferenced pointer
    // @param value_length The length of the value inside the dereferenced pointer
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o8_o16_i16_get_deref(uint8_list* blob, uint8_t pointer_offset, uint16_t value_offset, uint16_t value_length);
    // Emits the opcode YSOPC_o16_o8_i8_GET_DEREF into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @param pointer_offset The offset of the to dereference pointer
    // @param value_offset The offset to the value inside the dereferenced pointer
    // @param value_length The length of the value inside the dereferenced pointer
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o16_o8_i8_get_deref(uint8_list* blob, uint16_t pointer_offset, uint8_t value_offset, uint8_t value_length);
    // Emits the opcode YSOPC_o16_o8_i16_GET_DEREF into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @param pointer_offset The offset of the to dereference pointer
    // @param value_offset The offset to the value inside the dereferenced pointer
    // @param value_length The length of the value inside the dereferenced pointer
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o16_o8_i16_get_deref(uint8_list* blob, uint16_t pointer_offset, uint8_t value_offset, uint16_t value_length);
    // Emits the opcode YSOPC_o16_o16_i8_GET_DEREF into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @param pointer_offset The offset of the to dereference pointer
    // @param value_offset The offset to the value inside the dereferenced pointer
    // @param value_length The length of the value inside the dereferenced pointer
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o16_o16_i8_get_deref(uint8_list* blob, uint16_t pointer_offset, uint16_t value_offset, uint8_t value_length);
    // Emits the opcode YSOPC_o16_o16_i16_GET_DEREF into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @param pointer_offset The offset of the to dereference pointer
    // @param value_offset The offset to the value inside the dereferenced pointer
    // @param value_length The length of the value inside the dereferenced pointer
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o16_o16_i16_get_deref(uint8_list* blob, uint16_t pointer_offset, uint16_t value_offset, uint16_t value_length);
    // Emits the opcode YSOPC_o32_o32_i32_GET_DEREF into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @param pointer_offset The offset of the to dereference pointer
    // @param value_offset The offset to the value inside the dereferenced pointer
    // @param value_length The length of the value inside the dereferenced pointer
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o32_o32_i32_get_deref(uint8_list* blob, uint32_t pointer_offset, uint32_t value_offset, uint32_t value_length);
    // Emits the opcode YSOPC_o64_o64_i64_GET_DEREF into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @param pointer_offset The offset of the to dereference pointer
    // @param value_offset The offset to the value inside the dereferenced pointer
    // @param value_length The length of the value inside the dereferenced pointer
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o64_o64_i64_get_deref(uint8_list* blob, uint64_t pointer_offset, uint64_t value_offset, uint64_t value_length);
    // Emits one of the opcodes matching the following pattern into the blob: YSOPC_o*_o*_i*_GET_DEREF
    // The method will automatically choose the smallest possible one.
    // @param blob The uint8 data that represents the bytecode
    // @param pointer_offset The offset of the to dereference pointer
    // @param value_offset The offset to the value inside the dereferenced pointer
    // @param value_length The length of the value inside the dereferenced pointer
    // @return 0 on success, 1 if allocation for additional space failed.
    static int leaf_emit_o_o_i_get_deref(uint8_list* blob, uint64_t pointer_offset, uint64_t value_offset, uint64_t value_length)
    {
             if (pointer_offset <= UINT8_MAX  && value_offset <= UINT8_MAX  && value_length <= UINT8_MAX)  { return leaf_emit_o8_o8_i8_get_deref(blob, pointer_offset, value_offset, value_length); }
        else if (pointer_offset <= UINT8_MAX  && value_offset <= UINT8_MAX  && value_length <= UINT16_MAX) { return leaf_emit_o8_o8_i16_get_deref(blob, pointer_offset, value_offset, value_length); }
        else if (pointer_offset <= UINT8_MAX  && value_offset <= UINT16_MAX && value_length <= UINT8_MAX)  { return leaf_emit_o8_o16_i8_get_deref(blob, pointer_offset, value_offset, value_length); }
        else if (pointer_offset <= UINT8_MAX  && value_offset <= UINT16_MAX && value_length <= UINT16_MAX) { return leaf_emit_o8_o16_i16_get_deref(blob, pointer_offset, value_offset, value_length); }
        else if (pointer_offset <= UINT16_MAX && value_offset <= UINT8_MAX  && value_length <= UINT8_MAX)  { return leaf_emit_o16_o8_i8_get_deref(blob, pointer_offset, value_offset, value_length); }
        else if (pointer_offset <= UINT16_MAX && value_offset <= UINT8_MAX  && value_length <= UINT16_MAX) { return leaf_emit_o16_o8_i16_get_deref(blob, pointer_offset, value_offset, value_length); }
        else if (pointer_offset <= UINT16_MAX && value_offset <= UINT16_MAX && value_length <= UINT8_MAX)  { return leaf_emit_o16_o16_i8_get_deref(blob, pointer_offset, value_offset, value_length); }
        else if (pointer_offset <= UINT16_MAX && value_offset <= UINT16_MAX && value_length <= UINT16_MAX) { return leaf_emit_o16_o16_i16_get_deref(blob, pointer_offset, value_offset, value_length); }
        else if (pointer_offset <= UINT32_MAX && value_offset <= UINT32_MAX && value_length <= UINT32_MAX) { return leaf_emit_o32_o32_i32_get_deref(blob, pointer_offset, value_offset, value_length); }
        else { return leaf_emit_o64_o64_i64_get_deref(blob, pointer_offset, value_offset, value_length); }
    }

    // Emits the opcode YSOPC_o8_o8_GET_REF into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @param pointer_offset The offset of the to dereference pointer
    // @param value_offset The offset to the value inside the dereferenced pointer
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o8_o8_get_ref(uint8_list* blob, uint8_t pointer_offset, uint8_t value_offset);
    // Emits the opcode YSOPC_o8_o16_GET_REF into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @param pointer_offset The offset of the to dereference pointer
    // @param value_offset The offset to the value inside the dereferenced pointer
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o8_o16_get_ref(uint8_list* blob, uint8_t pointer_offset, uint16_t value_offset);
    // Emits the opcode YSOPC_o16_o8_GET_REF into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @param pointer_offset The offset of the to dereference pointer
    // @param value_offset The offset to the value inside the dereferenced pointer
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o16_o8_get_ref(uint8_list* blob, uint16_t pointer_offset, uint8_t value_offset);
    // Emits the opcode YSOPC_o16_o16_GET_REF into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @param pointer_offset The offset of the to dereference pointer
    // @param value_offset The offset to the value inside the dereferenced pointer
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o16_o16_get_ref(uint8_list* blob, uint16_t pointer_offset, uint16_t value_offset);
    // Emits the opcode YSOPC_o32_o32_GET_REF into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @param pointer_offset The offset of the to dereference pointer
    // @param value_offset The offset to the value inside the dereferenced pointer
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o32_o32_get_ref(uint8_list* blob, uint32_t pointer_offset, uint32_t value_offset);
    // Emits the opcode YSOPC_o64_o64_GET_REF into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @param pointer_offset The offset of the to dereference pointer
    // @param value_offset The offset to the value inside the dereferenced pointer
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o64_o64_get_ref(uint8_list* blob, uint64_t pointer_offset, uint64_t value_offset);
    // Emits one of the opcodes matching the following pattern into the blob: YSOPC_o*_o*_GET_REF
    // The method will automatically choose the smallest possible one.
    // @param blob The uint8 data that represents the bytecode
    // @param pointer_offset The offset of the to dereference pointer
    // @param value_offset The offset to the value inside the dereferenced pointer
    // @return 0 on success, 1 if allocation for additional space failed.
    static int leaf_emit_o_o_get_ref(uint8_list* blob, uint64_t pointer_offset, uint64_t value_offset)
    {
        if (pointer_offset <= UINT8_MAX && value_offset <= UINT8_MAX) { return leaf_emit_o8_o8_get_ref(blob, pointer_offset, value_offset); }
        else if (pointer_offset <= UINT8_MAX && value_offset <= UINT16_MAX) { return leaf_emit_o8_o16_get_ref(blob, pointer_offset, value_offset); }
        else if (pointer_offset <= UINT16_MAX && value_offset <= UINT8_MAX) { return leaf_emit_o16_o8_get_ref(blob, pointer_offset, value_offset); }
        else if (pointer_offset <= UINT16_MAX && value_offset <= UINT16_MAX) { return leaf_emit_o16_o16_get_ref(blob, pointer_offset, value_offset); }
        else if (pointer_offset <= UINT32_MAX && value_offset <= UINT32_MAX) { return leaf_emit_o32_o32_get_ref(blob, pointer_offset, value_offset); }
        else { return leaf_emit_o64_o64_get_ref(blob, pointer_offset, value_offset); }
    }

    // Emits the opcode YSOPC_o8_VALUE_REF into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o8_value_ref(uint8_list* blob, uint8_t value_offset);
    // Emits the opcode YSOPC_o16_VALUE_REF into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @param value_offset The offset to the value in the value stack
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o16_value_ref(uint8_list* blob, uint16_t value_offset);
    // Emits the opcode YSOPC_o32_VALUE_REF into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @param value_offset The offset to the value in the value stack
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o32_value_ref(uint8_list* blob, uint32_t value_offset);
    // Emits the opcode YSOPC_o64_VALUE_REF into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @param value_offset The offset to the value in the value stack
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o64_value_ref(uint8_list* blob, uint64_t value_offset);
    // Emits one of the opcodes matching the following pattern into the blob: YSOPC_o*_o*_GET_REF
    // The method will automatically choose the smallest possible one.
    // @param blob The uint8 data that represents the bytecode
    // @param value_offset The offset to the value in the value stack
    // @return 0 on success, 1 if allocation for additional space failed.
    static int leaf_emit_o_value_ref(uint8_list* blob, uint64_t value_offset)
    {
             if (value_offset <= UINT8_MAX) { return leaf_emit_o8_value_ref(blob, value_offset); }
        else if (value_offset <= UINT16_MAX) { return leaf_emit_o16_value_ref(blob, value_offset); }
        else if (value_offset <= UINT32_MAX) { return leaf_emit_o32_value_ref(blob, value_offset); }
        else { return leaf_emit_o64_value_ref(blob, value_offset); }
    }


    // Emits the opcode YSOPC_PUSH_TRUE into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_push_true(uint8_list* blob);
    // Emits the opcode YSOPC_PUSH_FALSE into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_push_false(uint8_list* blob);

    // Emits the opcode YSOPC_m1_CAST_UI8_v into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_m1_cast_ui8_v(uint8_list* blob, uint8_t ysopc_m1_modifier);
    // Emits the opcode YSOPC_m1_CAST_UI16_v into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_m1_cast_ui16_v(uint8_list* blob, uint8_t ysopc_m1_modifier);
    // Emits the opcode YSOPC_m1_CAST_UI32_v into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_m1_cast_ui32_v(uint8_list* blob, uint8_t ysopc_m1_modifier);
    // Emits the opcode YSOPC_m1_CAST_UI64_v into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_m1_cast_ui64_v(uint8_list* blob, uint8_t ysopc_m1_modifier);
    // Emits the opcode YSOPC_m1_CAST_I8_v into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_m1_cast_i8_v(uint8_list* blob, uint8_t ysopc_m1_modifier);
    // Emits the opcode YSOPC_m1_CAST_I16_v into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_m1_cast_i16_v(uint8_list* blob, uint8_t ysopc_m1_modifier);
    // Emits the opcode YSOPC_m1_CAST_I32_v into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_m1_cast_i32_v(uint8_list* blob, uint8_t ysopc_m1_modifier);
    // Emits the opcode YSOPC_m1_CAST_I64_v into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_m1_cast_i64_v(uint8_list* blob, uint8_t ysopc_m1_modifier);





    // Emits the opcode YSOPC_i64_CALL into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_i64_call(uint8_list* blob);
    // Emits the opcode YSOPC_RETURN into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_return(uint8_list* blob);
    // Emits the opcode YSOPC_COPY_c into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_copy_c(uint8_list* blob);
    // Emits the opcode YSOPC_COPY_POP_c into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_copy_pop_c(uint8_list* blob);
    // Emits the opcode YSOPC_o32_COPY into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o32_copy(uint8_list* blob);
    // Emits the opcode YSOPC_o16_COPY into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o16_copy(uint8_list* blob);
    // Emits the opcode YSOPC_o32_COPY into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o32_copy(uint8_list* blob);
    // Emits the opcode YSOPC_o64_COPY into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o64_copy(uint8_list* blob);
    // Emits the opcode YSOPC_COPY_PRIMITIVE_v8 into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_copy_primitive_v8(uint8_list* blob);
    // Emits the opcode YSOPC_COPY_PRIMITIVE_v16 into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_copy_primitive_v16(uint8_list* blob);
    // Emits the opcode YSOPC_COPY_PRIMITIVE_v32 into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_copy_primitive_v32(uint8_list* blob);
    // Emits the opcode YSOPC_COPY_PRIMITIVE_v64 into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_copy_primitive_v64(uint8_list* blob);
    // Emits the opcode YSOPC_o8_o8_CLONE_d into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o8_o8_clone_d(uint8_list* blob);
    // Emits the opcode YSOPC_o16_o8_CLONE_d into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o16_o8_clone_d(uint8_list* blob);
    // Emits the opcode YSOPC_o8_o16_CLONE_d into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o8_o16_clone_d(uint8_list* blob);
    // Emits the opcode YSOPC_o16_o16_CLONE_d into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o16_o16_clone_d(uint8_list* blob);
    // Emits the opcode YSOPC_o32_o32_CLONE_d into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o32_o32_clone_d(uint8_list* blob);
    // Emits the opcode YSOPC_o64_o64_CLONE_d into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_o64_o64_clone_d(uint8_list* blob);

    // Emits the opcode YSOPC_i8_i8_i8_THIS_GET_DEREF into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_i8_i8_i8_this_get_deref(uint8_list* blob);
    // Emits the opcode YSOPC_i8_i8_i16_THIS_GET_DEREF into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_i8_i8_i16_this_get_deref(uint8_list* blob);
    // Emits the opcode YSOPC_i8_i16_i8_THIS_GET_DEREF into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_i8_i16_i8_this_get_deref(uint8_list* blob);
    // Emits the opcode YSOPC_i8_i16_i16_THIS_GET_DEREF into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_i8_i16_i16_this_get_deref(uint8_list* blob);
    // Emits the opcode YSOPC_i16_i8_i8_THIS_GET_DEREF into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_i16_i8_i8_this_get_deref(uint8_list* blob);
    // Emits the opcode YSOPC_i16_i8_i16_THIS_GET_DEREF into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_i16_i8_i16_this_get_deref(uint8_list* blob);
    // Emits the opcode YSOPC_i16_i16_i8_THIS_GET_DEREF into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_i16_i16_i8_this_get_deref(uint8_list* blob);
    // Emits the opcode YSOPC_i16_i16_i16_THIS_GET_DEREF into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_i16_i16_i16_this_get_deref(uint8_list* blob);
    // Emits the opcode YSOPC_i32_i32_i32_THIS_GET_DEREF into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_i32_i32_i32_this_get_deref(uint8_list* blob);
    // Emits the opcode YSOPC_i64_i64_i64_THIS_GET_DEREF into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_i64_i64_i64_this_get_deref(uint8_list* blob);
    // Emits the opcode YSOPC_POP into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_pop(uint8_list* blob);
    // Emits the opcode YSOPC_m1_i8_PUSH into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_m1_i8_push(uint8_list* blob);
    // Emits the opcode YSOPC_m1_i16_PUSH into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_m1_i16_push(uint8_list* blob);
    // Emits the opcode YSOPC_m1_i32_PUSH into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_m1_i32_push(uint8_list* blob);
    // Emits the opcode YSOPC_m1_i64_PUSH into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_m1_i64_push(uint8_list* blob);
    // Emits the opcode YSOPC_PUSH_UI8_0 into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_push_ui8_0(uint8_list* blob);
    // Emits the opcode YSOPC_PUSH_UI8_1P into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_push_ui8_1p(uint8_list* blob);
    // Emits the opcode YSOPC_PUSH_I8_0 into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_push_i8_0(uint8_list* blob);
    // Emits the opcode YSOPC_PUSH_I8_1P into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_push_i8_1p(uint8_list* blob);
    // Emits the opcode YSOPC_PUSH_I8_1N into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_push_i8_1n(uint8_list* blob);
    // Emits the opcode YSOPC_PUSH_UI16_0 into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_push_ui16_0(uint8_list* blob);
    // Emits the opcode YSOPC_PUSH_UI16_1P into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_push_ui16_1p(uint8_list* blob);
    // Emits the opcode YSOPC_PUSH_I16_0 into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_push_i16_0(uint8_list* blob);
    // Emits the opcode YSOPC_PUSH_I16_1P into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_push_i16_1p(uint8_list* blob);
    // Emits the opcode YSOPC_PUSH_I16_1N into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_push_i16_1n(uint8_list* blob);
    // Emits the opcode YSOPC_PUSH_UI32_0 into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_push_ui32_0(uint8_list* blob);
    // Emits the opcode YSOPC_PUSH_UI32_1P into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_push_ui32_1p(uint8_list* blob);
    // Emits the opcode YSOPC_PUSH_I32_0 into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_push_i32_0(uint8_list* blob);
    // Emits the opcode YSOPC_PUSH_I32_1P into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_push_i32_1p(uint8_list* blob);
    // Emits the opcode YSOPC_PUSH_I32_1N into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_push_i32_1n(uint8_list* blob);
    // Emits the opcode YSOPC_PUSH_UI64_0 into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_push_ui64_0(uint8_list* blob);
    // Emits the opcode YSOPC_PUSH_UI64_1P into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_push_ui64_1p(uint8_list* blob);
    // Emits the opcode YSOPC_PUSH_I64_0 into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_push_i64_0(uint8_list* blob);
    // Emits the opcode YSOPC_PUSH_I64_1P into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_push_i64_1p(uint8_list* blob);
    // Emits the opcode YSOPC_PUSH_I64_1N into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_push_i64_1n(uint8_list* blob);
    // Emits the opcode YSOPC_PUSH_F32_0 into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_push_f32_0(uint8_list* blob);
    // Emits the opcode YSOPC_PUSH_F32_1P into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_push_f32_1p(uint8_list* blob);
    // Emits the opcode YSOPC_PUSH_F32_1N into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_push_f32_1n(uint8_list* blob);
    // Emits the opcode YSOPC_PUSH_F64_0 into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_push_f64_0(uint8_list* blob);
    // Emits the opcode YSOPC_PUSH_F64_1P into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_push_f64_1p(uint8_list* blob);
    // Emits the opcode YSOPC_PUSH_F64_1N into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_push_f64_1n(uint8_list* blob);
    // Emits the opcode YSOPC_m1_CAST_F32_TO_32_v into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_m1_cast_f32_to_32_v(uint8_list* blob);
    // Emits the opcode YSOPC_m1_CAST_F64_TO_64_v into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_m1_cast_f64_to_64_v(uint8_list* blob);
    // Emits the opcode YSOPC_m1_ADD_d_d into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_m1_add_d_d(uint8_list* blob);
    // Emits the opcode YSOPC_m1_SUBTRACT_d_d into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_m1_subtract_d_d(uint8_list* blob);
    // Emits the opcode YSOPC_m1_MULTIPLY_d_d into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_m1_multiply_d_d(uint8_list* blob);
    // Emits the opcode YSOPC_m1_DIVIDE_d_d into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_m1_divide_d_d(uint8_list* blob);
    // Emits the opcode YSOPC_m1_REMAINDER_d_d into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_m1_remainder_d_d(uint8_list* blob);
    // Emits the opcode YSOPC_m1_BIT_LEFT_SHIFT_d_d into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_m1_bit_left_shift_d_d(uint8_list* blob);
    // Emits the opcode YSOPC_m1_BIT_RIGHT_SHIFT_d_d into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_m1_bit_right_shift_d_d(uint8_list* blob);
    // Emits the opcode YSOPC_m1_BIT_AND_d_d into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_m1_bit_and_d_d(uint8_list* blob);
    // Emits the opcode YSOPC_m1_BIT_OR_d_d into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_m1_bit_or_d_d(uint8_list* blob);
    // Emits the opcode YSOPC_m1_BIT_INVERT_d into the blob.
    // @param blob The uint8 data that represents the bytecode
    // @return 0 on success, 1 if allocation for additional space failed.
    int leaf_emit_m1_bit_invert_d(uint8_list* blob);

#ifdef __cplusplus
}
#endif
#endif
