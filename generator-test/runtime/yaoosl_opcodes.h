#ifndef __leaf_OPCODES_H__
#define __leaf_OPCODES_H__
#ifdef __cplusplus
extern "C" {
#endif
#define YSOPC_M1_SIGNED_FLAG    0x01
#define YSOPC_M1_FLOAT_FLAG     0x02
#define YSOPC_M1_CHAR_FLAG      0x04
#define YSOPC_M1_BOOL_FLAG      0x08
#define YSOPC_M1_8              0x10
#define YSOPC_M1_16             0x20
#define YSOPC_M1_32             0x40
#define YSOPC_M1_64             0x80

#define YSOPC_M1_UI8            YSOPC_M1_8
#define YSOPC_M1_UI16           YSOPC_M1_16
#define YSOPC_M1_UI32           YSOPC_M1_32
#define YSOPC_M1_UI64           YSOPC_M1_64
#define YSOPC_M1_I8             (YSOPC_M1_8  | YSOPC_M1_SIGNED_FLAG)
#define YSOPC_M1_I16            (YSOPC_M1_16 | YSOPC_M1_SIGNED_FLAG)
#define YSOPC_M1_I32            (YSOPC_M1_32 | YSOPC_M1_SIGNED_FLAG)
#define YSOPC_M1_I64            (YSOPC_M1_64 | YSOPC_M1_SIGNED_FLAG)
#define YSOPC_M1_F32            (YSOPC_M1_32 | YSOPC_M1_FLOAT_FLAG)
#define YSOPC_M1_F64            (YSOPC_M1_64 | YSOPC_M1_FLOAT_FLAG)

    // The leaf opcodes as available.
    // Syntax (concated using underscore '_'):
    //     YSOPC {bytecode-args} {opcode-name} {value-stack-args}
    // Abbrevations:
    //     SS   -> Value-Stack start. The 0 index of the stack.
    //     SE   -> Value-Stack end. The index + 1 of the last byte on the stack.
    //     SL   -> Last element on the Value-Stack.
    // Prefix Meanings:
    //     i8   -> Immediate ui8
    //     i16  -> Immediate ui16
    //     i32  -> Immediate ui32
    //     i64  -> Immediate ui64
    //     o8   -> Stack Offset ui8. Stack offset is always applied in a negative relation to SE (SE - o8).
    //     o16  -> Stack Offset ui16. Stack offset is always applied in a negative relation to SE (SE - o16).
    //     o32  -> Stack Offset ui32. Stack offset is always applied in a negative relation to SE (SE - o32).
    //     o64  -> Stack Offset ui64. Stack offset is always applied in a negative relation to SE (SE - o64).
    //     v8   -> SL with ui8 size.
    //     v16  -> SL with ui16 size.
    //     v32  -> SL with ui32 size.
    //     v64  -> SL with ui64 size.
    //     c    -> SL with class-instance type.
    //     d    -> SL with varying size, defined by some immediate argument of the opcode.
    //     m1   -> Modifier flag of ui8 size. Flags:
    //               0: Signed Flag     0x01
    //               1: Float Flag      0x02
    //               2: Char Flag       0x04
    //               3: Bool Flag       0x08
    //               4: 8               0x10
    //               5: 16              0x20
    //               6: 32              0x40
    //               7: 64              0x80
    enum leaf_opcodes
    {
        // No operation will be done.
        YSOPC_NOP = 0,
        // Halts execution.
        YSOPC_HALT,

        // Arg1: The amount of bytes to reserve.
        // Reserves bytes on the stack and pushes a reference to the first element.
        YSOPC_i8_STACK_RESERVE,
        // Arg1: The amount of bytes to reserve.
        // Reserves bytes on the stack and pushes a reference to the first element.
        YSOPC_i16_STACK_RESERVE,
        // Arg1: The amount of bytes to reserve.
        // Reserves bytes on the stack and pushes a reference to the first element.
        YSOPC_i32_STACK_RESERVE,
        // Arg1: The amount of bytes to reserve.
        // Reserves bytes on the stack and pushes a reference to the first element.
        YSOPC_i64_STACK_RESERVE,

        // Arg1: Size multiplier.
        // Arg2: Modifier flags that describe the value stack arg
        // Reserves bytes on the stack and pushes a reference to the first element.
        YSOPC_i8_m1_STACK_RESERVE_d,
        // Arg1: Size multiplier.
        // Arg2: Modifier flags that describe the value stack arg
        // Reserves bytes on the stack and pushes a reference to the first element.
        YSOPC_i16_m1_STACK_RESERVE_d,
        // Arg1: Size multiplier.
        // Arg2: Modifier flags that describe the value stack arg
        // Reserves bytes on the stack and pushes a reference to the first element.
        YSOPC_i32_m1_STACK_RESERVE_d,
        // Arg1: Size multiplier.
        // Arg2: Modifier flags that describe the value stack arg
        // Reserves bytes on the stack and pushes a reference to the first element.
        YSOPC_i64_m1_STACK_RESERVE_d,

        // Arg1: The amount of bytes to reserve.
        // Reserves bytes on the heap and pushes a reference to the first element.
        YSOPC_i8_HEAP_ALLOC,
        // Arg1: The amount of bytes to reserve.
        // Reserves bytes on the heap and pushes a reference to the first element.
        YSOPC_i16_HEAP_ALLOC,
        // Arg1: The amount of bytes to reserve.
        // Reserves bytes on the heap and pushes a reference to the first element.
        YSOPC_i32_HEAP_ALLOC,
        // Arg1: The amount of bytes to reserve.
        // Reserves bytes on the heap and pushes a reference to the first element.
        YSOPC_i64_HEAP_ALLOC,

        // Arg1: Size multiplier.
        // Arg2: Modifier flags that describe the value stack arg
        // Reserves bytes on the heap and pushes a reference to the first element.
        YSOPC_i8_m1_HEAP_ALLOC_d,
        // Arg1: Size multiplier.
        // Arg2: Modifier flags that describe the value stack arg
        // Reserves bytes on the heap and pushes a reference to the first element.
        YSOPC_i16_m1_HEAP_ALLOC_d,
        // Arg1: Size multiplier.
        // Arg2: Modifier flags that describe the value stack arg
        // Reserves bytes on the heap and pushes a reference to the first element.
        YSOPC_i32_m1_HEAP_ALLOC_d,
        // Arg1: Size multiplier.
        // Arg2: Modifier flags that describe the value stack arg
        // Reserves bytes on the heap and pushes a reference to the first element.
        YSOPC_i64_m1_HEAP_ALLOC_d,

        // Arg1: The amount of bytes to free.
        // Reserves bytes on the stack and pushes a reference to the first element.
        YSOPC_i8_STACK_FREE,
        // Arg1: The amount of bytes to free.
        // Reserves bytes on the stack and pushes a reference to the first element.
        YSOPC_i16_STACK_FREE,
        // Arg1: The amount of bytes to free.
        // Reserves bytes on the stack and pushes a reference to the first element.
        YSOPC_i32_STACK_FREE,
        // Arg1: The amount of bytes to free.
        // Reserves bytes on the stack and pushes a reference to the first element.
        YSOPC_i64_STACK_FREE,

        // Arg1: The offset of targeted the value on the value stack
        // Arg2: The size of the value on the value stack at SL
        // Pop the value from SL with the size as given by Arg2 and replace the data at Arg1 with it.
        YSOPC_o8_v8_MOVE_d,
        // Arg1: The offset of targeted the value on the value stack
        // Arg2: The size of the value on the value stack at SL
        // Pop the value from SL with the size as given by Arg2 and replace the data at Arg1 with it.
        YSOPC_o8_v16_MOVE_d,
        // Arg1: The offset of targeted the value on the value stack
        // Arg2: The size of the value on the value stack at SL
        // Pop the value from SL with the size as given by Arg2 and replace the data at Arg1 with it.
        YSOPC_o16_v8_MOVE_d,
        // Arg1: The offset of targeted the value on the value stack
        // Arg2: The size of the value on the value stack at SL
        // Pop the value from SL with the size as given by Arg2 and replace the data at Arg1 with it.
        YSOPC_o16_v16_MOVE_d,
        // Arg1: The offset of targeted the value on the value stack
        // Arg2: The size of the value on the value stack at SL
        // Pop the value from SL with the size as given by Arg2 and replace the data at Arg1 with it.
        YSOPC_o32_v32_MOVE_d,
        // Arg1: The offset of targeted the value on the value stack
        // Arg2: The size of the value on the value stack at SL
        // Pop the value from SL with the size as given by Arg2 and replace the data at Arg1 with it.
        YSOPC_o64_v64_MOVE_d,

        // Arg1: The offset of the to dereference pointer
        // Arg2: The offset to the value inside the dereferenced pointer
        // Arg3: The length of the value inside the dereferenced pointer
        // Dereference the address at Arg1 push a value of it at Arg2 of Arg3 length onto value stack
        YSOPC_o8_o8_i8_GET_DEREF,
        // Arg1: The offset of the to dereference pointer
        // Arg2: The offset to the value inside the dereferenced pointer
        // Arg3: The length of the value inside the dereferenced pointer
        // Dereference the address at Arg1 push a value of it at Arg2 of Arg3 length onto value stack
        YSOPC_o8_o8_i16_GET_DEREF,
        // Arg1: The offset of the to dereference pointer
        // Arg2: The offset to the value inside the dereferenced pointer
        // Arg3: The length of the value inside the dereferenced pointer
        // Dereference the address at Arg1 push a value of it at Arg2 of Arg3 length onto value stack
        YSOPC_o8_o16_i8_GET_DEREF,
        // Arg1: The offset of the to dereference pointer
        // Arg2: The offset to the value inside the dereferenced pointer
        // Arg3: The length of the value inside the dereferenced pointer
        // Dereference the address at Arg1 push a value of it at Arg2 of Arg3 length onto value stack
        YSOPC_o8_o16_i16_GET_DEREF,
        // Arg1: The offset of the to dereference pointer
        // Arg2: The offset to the value inside the dereferenced pointer
        // Arg3: The length of the value inside the dereferenced pointer
        // Dereference the address at Arg1 push a value of it at Arg2 of Arg3 length onto value stack
        YSOPC_o16_o8_i8_GET_DEREF,
        // Arg1: The offset of the to dereference pointer
        // Arg2: The offset to the value inside the dereferenced pointer
        // Arg3: The length of the value inside the dereferenced pointer
        // Dereference the address at Arg1 push a value of it at Arg2 of Arg3 length onto value stack
        YSOPC_o16_o8_i16_GET_DEREF,
        // Arg1: The offset of the to dereference pointer
        // Arg2: The offset to the value inside the dereferenced pointer
        // Arg3: The length of the value inside the dereferenced pointer
        // Dereference the address at Arg1 push a value of it at Arg2 of Arg3 length onto value stack
        YSOPC_o16_o16_i8_GET_DEREF,
        // Arg1: The offset of the to dereference pointer
        // Arg2: The offset to the value inside the dereferenced pointer
        // Arg3: The length of the value inside the dereferenced pointer
        // Dereference the address at Arg1 push a value of it at Arg2 of Arg3 length onto value stack
        YSOPC_o16_o16_i16_GET_DEREF,
        // Arg1: The offset of the to dereference pointer
        // Arg2: The offset to the value inside the dereferenced pointer
        // Arg3: The length of the value inside the dereferenced pointer
        // Dereference the address at Arg1 push a value of it at Arg2 of Arg3 length onto value stack
        YSOPC_o32_o32_i32_GET_DEREF,
        // Arg1: The offset of the to dereference pointer
        // Arg2: The offset to the value inside the dereferenced pointer
        // Arg3: The length of the value inside the dereferenced pointer
        // Dereference the address at Arg1 push a value of it at Arg2 of Arg3 length onto value stack
        YSOPC_o64_o64_i64_GET_DEREF,

        // Arg1: The offset of the to dereference pointer
        // Arg2: The offset to the value inside the dereferenced pointer
        // Dereference the address at Arg1 push a value of it at Arg2 of as reference onto value stack
        YSOPC_o8_o8_GET_REF,
        // Arg1: The offset of the to dereference pointer
        // Arg2: The offset to the value inside the dereferenced pointer
        // Dereference the address at Arg1 push a value of it at Arg2 of as reference onto value stack
        YSOPC_o8_o16_GET_REF,
        // Arg1: The offset of the to dereference pointer
        // Arg2: The offset to the value inside the dereferenced pointer
        // Dereference the address at Arg1 push a value of it at Arg2 of as reference onto value stack
        YSOPC_o16_o8_GET_REF,
        // Arg1: The offset of the to dereference pointer
        // Arg2: The offset to the value inside the dereferenced pointer
        // Dereference the address at Arg1 push a value of it at Arg2 of as reference onto value stack
        YSOPC_o16_o16_GET_REF,
        // Arg1: The offset of the to dereference pointer
        // Arg2: The offset to the value inside the dereferenced pointer
        // Dereference the address at Arg1 push a value of it at Arg2 of as reference onto value stack
        YSOPC_o32_o32_GET_REF,
        // Arg1: The offset of the to dereference pointer
        // Arg2: The offset to the value inside the dereferenced pointer
        // Dereference the address at Arg1 push a value of it at Arg2 of as reference onto value stack
        YSOPC_o64_o64_GET_REF,

        // Arg1: The offset to the value in the value stack
        // Takes a value at Arg1 and packs it into a reference and pushes that reference to the value stack
        YSOPC_o8_VALUE_REF,
        // Arg1: The offset to the value in the value stack
        // Takes a value at Arg1 and packs it into a reference and pushes that reference to the value stack
        YSOPC_o16_VALUE_REF,
        // Arg1: The offset to the value in the value stack
        // Takes a value at Arg1 and packs it into a reference and pushes that reference to the value stack
        YSOPC_o32_VALUE_REF,
        // Arg1: The offset to the value in the value stack
        // Takes a value at Arg1 and packs it into a reference and pushes that reference to the value stack
        YSOPC_o64_VALUE_REF,



        ////////////////////////////////////////////////
        // EVERYTHING BELOW HERE IS SUBJECT TO CHANGE //
        ////////////////////////////////////////////////

        // Arg1: The address to call.
        // Does the following things:
        // 1. Push return address to ReturnStack
        // 2. Push Scope to CallStack
        // 3. Set this in current CallStack scope
        // 4. Move InstructionPointer to given address in Arg1
        YSOPC_i64_CALL,
        // Does the following things:
        // 1. Pop Scope from CallStack (call destructors where needed)
        // 2. Pop return address from ReturnStack
        // 3. Move InstructionPointer to poped return address
        //
        // If CallStack is empty after 1., execution will stop.
        YSOPC_RETURN,

        // Stack1: The class-instance to copy
        // Take SL and call copy-constructor on it, effectifly copying it to SL.
        YSOPC_COPY_c,
        // Stack1: The class-instance to copy
        // Pop SL and call copy-constructor on it, effectifly copying it to SL.
        YSOPC_COPY_POP_c,
        // Arg1: The offset on the value
        // Stack1: The class-instance to copy
        // Take value at offset and call copy-constructor on it, effectifly copying it to SL.
        YSOPC_o8_COPY,
        // Arg1: The offset on the value
        // Stack1: The class-instance to copy
        // Take value at offset and call copy-constructor on it, effectifly copying it to SL.
        YSOPC_o16_COPY,
        // Arg1: The offset on the value
        // Stack1: The class-instance to copy
        // Take value at offset and call copy-constructor on it, effectifly copying it to SL.
        YSOPC_o32_COPY,
        // Arg1: The offset on the value
        // Stack1: The class-instance to copy
        // Take value at offset and call copy-constructor on it, effectifly copying it to SL.
        YSOPC_o64_COPY,
        // Stack1: The value to copy
        // Take SL and push a copy of it onto the value stack.
        YSOPC_COPY_PRIMITIVE_v8,
        // Stack1: The value to copy
        // Take SL and push a copy of it onto the value stack.
        YSOPC_COPY_PRIMITIVE_v16,
        // Stack1: The value to copy
        // Take SL and push a copy of it onto the value stack.
        YSOPC_COPY_PRIMITIVE_v32,
        // Stack1: The value to copy
        // Take SL and push a copy of it onto the value stack.
        YSOPC_COPY_PRIMITIVE_v64,
        // Arg1: The offset on the value
        // Arg2: The size of the value on the value stack
        // Take value at offset and push a copy of it onto the value stack.
        YSOPC_o8_o8_CLONE_d,
        // Arg1: The offset on the value
        // Arg2: The size of the value on the value stack
        // Take value at offset and push a copy of it onto the value stack.
        YSOPC_o16_o8_CLONE_d,
        // Arg1: The offset on the value
        // Arg2: The size of the value on the value stack
        // Take value at offset and push a copy of it onto the value stack.
        YSOPC_o8_o16_CLONE_d,
        // Arg1: The offset on the value
        // Arg2: The size of the value on the value stack
        // Take value at offset and push a copy of it onto the value stack.
        YSOPC_o16_o16_CLONE_d,
        // Arg1: The offset on the value
        // Arg2: The size of the value on the value stack
        // Take value at offset and push a copy of it onto the value stack.
        YSOPC_o32_o32_CLONE_d,
        // Arg1: The offset on the value
        // Arg2: The size of the value on the value stack
        // Take value at offset and push a copy of it onto the value stack.
        YSOPC_o64_o64_CLONE_d,

        // Arg1: The offset of the to dereference pointer inside this
        // Arg2: The offset to the value inside the dereferenced pointer
        // Arg3: The length of the value inside the dereferenced pointer
        // Dereference the address at Arg1 relative to this push a value of it at Arg2 of Arg3 length onto value stack
        YSOPC_i8_i8_i8_THIS_GET_DEREF,
        // Arg1: The offset of the to dereference pointer inside this
        // Arg2: The offset to the value inside the dereferenced pointer
        // Arg3: The length of the value inside the dereferenced pointer
        // Dereference the address at Arg1 relative to this push a value of it at Arg2 of Arg3 length onto value stack
        YSOPC_i8_i8_i16_THIS_GET_DEREF,
        // Arg1: The offset of the to dereference pointer inside this
        // Arg2: The offset to the value inside the dereferenced pointer
        // Arg3: The length of the value inside the dereferenced pointer
        // Dereference the address at Arg1 relative to this push a value of it at Arg2 of Arg3 length onto value stack
        YSOPC_i8_i16_i8_THIS_GET_DEREF,
        // Arg1: The offset of the to dereference pointer inside this
        // Arg2: The offset to the value inside the dereferenced pointer
        // Arg3: The length of the value inside the dereferenced pointer
        // Dereference the address at Arg1 relative to this push a value of it at Arg2 of Arg3 length onto value stack
        YSOPC_i8_i16_i16_THIS_GET_DEREF,
        // Arg1: The offset of the to dereference pointer inside this
        // Arg2: The offset to the value inside the dereferenced pointer
        // Arg3: The length of the value inside the dereferenced pointer
        // Dereference the address at Arg1 relative to this push a value of it at Arg2 of Arg3 length onto value stack
        YSOPC_i16_i8_i8_THIS_GET_DEREF,
        // Arg1: The offset of the to dereference pointer inside this
        // Arg2: The offset to the value inside the dereferenced pointer
        // Arg3: The length of the value inside the dereferenced pointer
        // Dereference the address at Arg1 relative to this push a value of it at Arg2 of Arg3 length onto value stack
        YSOPC_i16_i8_i16_THIS_GET_DEREF,
        // Arg1: The offset of the to dereference pointer inside this
        // Arg2: The offset to the value inside the dereferenced pointer
        // Arg3: The length of the value inside the dereferenced pointer
        // Dereference the address at Arg1 relative to this push a value of it at Arg2 of Arg3 length onto value stack
        YSOPC_i16_i16_i8_THIS_GET_DEREF,
        // Arg1: The offset of the to dereference pointer inside this
        // Arg2: The offset to the value inside the dereferenced pointer
        // Arg3: The length of the value inside the dereferenced pointer
        // Dereference the address at Arg1 relative to this push a value of it at Arg2 of Arg3 length onto value stack
        YSOPC_i16_i16_i16_THIS_GET_DEREF,
        // Arg1: The offset of the to dereference pointer inside this
        // Arg2: The offset to the value inside the dereferenced pointer
        // Arg3: The length of the value inside the dereferenced pointer
        // Dereference the address at Arg1 relative to this push a value of it at Arg2 of Arg3 length onto value stack
        YSOPC_i32_i32_i32_THIS_GET_DEREF,
        // Arg1: The offset of the to dereference pointer inside this
        // Arg2: The offset to the value inside the dereferenced pointer
        // Arg3: The length of the value inside the dereferenced pointer
        // Dereference the address at Arg1 relative to this push a value of it at Arg2 of Arg3 length onto value stack
        YSOPC_i64_i64_i64_THIS_GET_DEREF,

        // Pops a value from the value stack.
        YSOPC_POP,
        // Arg1: The value type to push
        // Arg2: The value to push
        // Pushes a value of the type Arg1 with a value of Arg2 onto the value stack.
        YOPC_m1_i8_PUSH,
        // Arg1: The value type to push
        // Arg2: The value to push
        // Pushes a value of the type Arg1 with a value of Arg2 onto the value stack.
        YOPC_m1_i16_PUSH,
        // Arg1: The value type to push
        // Arg2: The value to push
        // Pushes a value of the type Arg1 with a value of Arg2 onto the value stack.
        YOPC_m1_i32_PUSH,
        // Arg1: The value type to push
        // Arg2: The value to push
        // Pushes a value of the type Arg1 with a value of Arg2 onto the value stack.
        YOPC_m1_i64_PUSH,
        // Pushes a boolean that is true onto the value stack.
        YSOPC_PUSH_TRUE,
        // Pushes a boolean that is false onto the value stack.
        YSOPC_PUSH_FALSE,
        // Pushes ui8 zero onto the value stack.
        YSOPC_PUSH_UI8_0,
        // Pushes ui8 one (positive) onto the value stack.
        YSOPC_PUSH_UI8_1P,
        // Pushes i8 zero onto the value stack.
        YSOPC_PUSH_I8_0,
        // Pushes i8 one (positive) onto the value stack.
        YSOPC_PUSH_I8_1P,
        // Pushes i8 one (negative) onto the value stack.
        YSOPC_PUSH_I8_1N,
        // Pushes ui16 zero onto the value stack.
        YSOPC_PUSH_UI16_0,
        // Pushes ui16 one (positive) onto the value stack.
        YSOPC_PUSH_UI16_1P,
        // Pushes i16 zero onto the value stack.
        YSOPC_PUSH_I16_0,
        // Pushes i16 one (positive) onto the value stack.
        YSOPC_PUSH_I16_1P,
        // Pushes i16 one (negative) onto the value stack.
        YSOPC_PUSH_I16_1N,
        // Pushes ui32 zero onto the value stack.
        YSOPC_PUSH_UI32_0,
        // Pushes ui32 one (positive) onto the value stack.
        YSOPC_PUSH_UI32_1P,
        // Pushes i32 zero onto the value stack.
        YSOPC_PUSH_I32_0,
        // Pushes i32 one (positive) onto the value stack.
        YSOPC_PUSH_I32_1P,
        // Pushes i32 one (negative) onto the value stack.
        YSOPC_PUSH_I32_1N,
        // Pushes ui64 zero onto the value stack.
        YSOPC_PUSH_UI64_0,
        // Pushes ui64 one (positive) onto the value stack.
        YSOPC_PUSH_UI64_1P,
        // Pushes i64 zero onto the value stack.
        YSOPC_PUSH_I64_0,
        // Pushes i64 one (positive) onto the value stack.
        YSOPC_PUSH_I64_1P,
        // Pushes i64 one (negative) onto the value stack.
        YSOPC_PUSH_I64_1N,
        // Pushes f32 zero onto the value stack.
        YSOPC_PUSH_F32_0,
        // Pushes f32 one (positive) onto the value stack.
        YSOPC_PUSH_F32_1P,
        // Pushes f32 one (negative) onto the value stack.
        YSOPC_PUSH_F32_1N,
        // Pushes f64 zero onto the value stack.
        YSOPC_PUSH_F64_0,
        // Pushes f64 one (positive) onto the value stack.
        YSOPC_PUSH_F64_1P,
        // Pushes f64 one (negative) onto the value stack.
        YSOPC_PUSH_F64_1N,


        // Arg1: Modifier flags that describe what is targeted
        // Stack 1: The value to cast
        // Casts the value to the other size.
        YSOPC_m1_CAST_UI8_TO_8_v,
        // Arg1: Modifier flags that describe what is targeted
        // Stack 1: The value to cast
        // Casts the value to the other size.
        YSOPC_m1_CAST_UI16_TO_16_v,
        // Arg1: Modifier flags that describe what is targeted
        // Stack 1: The value to cast
        // Casts the value to the other size.
        YSOPC_m1_CAST_UI32_TO_32_v,
        // Arg1: Modifier flags that describe what is targeted
        // Stack 1: The value to cast
        // Casts the value to the other size.
        YSOPC_m1_CAST_UI64_TO_64_v,
        // Arg1: Modifier flags that describe what is targeted
        // Stack 1: The value to cast
        // Casts the value to the other size.
        YSOPC_m1_CAST_I8_TO_8_v,
        // Arg1: Modifier flags that describe what is targeted
        // Stack 1: The value to cast
        // Casts the value to the other size.
        YSOPC_m1_CAST_I16_TO_16_v,
        // Arg1: Modifier flags that describe what is targeted
        // Stack 1: The value to cast
        // Casts the value to the other size.
        YSOPC_m1_CAST_I32_TO_32_v,
        // Arg1: Modifier flags that describe what is targeted
        // Stack 1: The value to cast
        // Casts the value to the other size.
        YSOPC_m1_CAST_I64_TO_64_v,
        // Arg1: Modifier flags that describe what is targeted
        // Stack 1: The value to cast
        // Casts the value to the other size.
        YSOPC_m1_CAST_F32_TO_32_v,
        // Arg1: Modifier flags that describe what is targeted
        // Stack 1: The value to cast
        // Casts the value to the other size.
        YSOPC_m1_CAST_F64_TO_64_v,

        // Arg1: The value type of SL and SL-1
        // Stack1: SL-1
        // Stack2: SL
        // Pops two values from value stack and pushes the added  (SL-1 + SL) result back onto stack
        YSOPC_m1_ADD_d_d,
        // Arg1: The value type of SL and SL-1
        // Stack1: SL-1
        // Stack2: SL
        // Pops two values from value stack and pushes the subtracted (SL-1 - SL) result back onto stack
        YSOPC_m1_SUBTRACT_d_d,
        // Arg1: The value type of SL and SL-1
        // Stack1: SL-1
        // Stack2: SL
        // Pops two values from value stack and pushes the multiplied (SL-1 * SL) result back onto stack
        YSOPC_m1_MULTIPLY_d_d,
        // Arg1: The value type of SL and SL-1
        // Stack1: SL-1
        // Stack2: SL
        // Pops two values from value stack and pushes the divided (SL-1 / SL) result back onto stack
        YSOPC_m1_DIVIDE_d_d,
        // Arg1: The value type of SL and SL-1
        // Stack1: SL-1
        // Stack2: SL
        // Pops two values from value stack and pushes the remainder (SL-1 % SL) result back onto stack
        YSOPC_m1_REMAINDER_d_d,
        // Arg1: The value type of SL and SL-1
        // Stack1: SL-1
        // Stack2: SL
        // Pops two values from value stack and pushes the bit shifted (SL-1 << SL) result back onto stack
        YSOPC_m1_BIT_LEFT_SHIFT_d_d,
        // Arg1: The value type of SL and SL-1
        // Stack1: SL-1
        // Stack2: SL
        // Pops two values from value stack and pushes the bit shifted (SL-1 >> SL) result back onto stack
        YSOPC_m1_BIT_RIGHT_SHIFT_d_d,
        // Arg1: The value type of SL and SL-1
        // Stack1: SL-1
        // Stack2: SL
        // Pops two values from value stack and pushes the bitwise anded (SL-1 & SL) result back onto stack
        YSOPC_m1_BIT_AND_d_d,
        // Arg1: The value type of SL and SL-1
        // Stack1: SL-1
        // Stack2: SL
        // Pops two values from value stack and pushes the bitwise orred (SL-1 | SL) result back onto stack
        YSOPC_m1_BIT_OR_d_d,
        // Arg1: The value type of SL
        // Stack1: SL-1
        // Stack2: SL
        // Pops a value from value stack and pushes the bitwise inverted (~SL) result back onto stack
        YSOPC_m1_BIT_INVERT_d,

    };

#ifdef __cplusplus
}
#endif
#endif
