# CMakeList.txt : CMake project for generator-test, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (generator-test
        main.cpp
        main.hpp
        parser.hpp
        parser.cpp
        runtime/leaf_string.h
        runtime/leaf_string.c
        runtime/leaf_type.h
        runtime/leaf_type.c
        runtime/leaf_macros.h
        runtime/leaf_library.h
        runtime/leaf_library.c
        runtime/leaf_emit.h
        runtime/leaf_opcodes.h
        compilation-old/compiler.hpp
        compilation-old/compiler.cpp
        compilation-old/leaf_reporting.hpp
        compilation-old/stages/stage_base.hpp
        compilation-old/stages/stage_base.cpp
        compilation-old/stages/0_register_types.hpp
        compilation-old/stages/0_register_types.cpp
        compilation-old/stages/1_register_contents.cpp
        compilation-old/stages/1_register_contents.hpp
        compilation-old/stages/2_set_type_size.hpp
        compilation-old/stages/2_set_type_size.cpp
        compilation-old/stages/3_emit_bytecode.hpp
        compilation-old/stages/3_emit_bytecode.cpp
        compilation-old/visitors/type_from_expression.cpp
        compilation-old/visitors/type_from_expression.hpp
        compilation-old/value_reference.hpp
        compilation-old/conversion_solver.hpp
        compilation-old/method_call_solver.hpp
        compilation-old/method_builder.hpp
        compilation-old/builders/class_builder.cpp
        compilation-old/builders/class_builder.hpp
        compilation-old/builders/template_definition_item.hpp
        compilation-old/builders/encapsulation_enum.hpp
        compilation-old/builders/type_builder.cpp
        compilation-old/builders/type_builder.hpp
        compilation-old/builders/type_candidate.hpp
        compilation-old/builders/field_builder.cpp
        compilation-old/builders/field_builder.hpp
        compilation-old/builders/method_builder.cpp
        compilation-old/builders/method_builder.hpp
        compilation-old/builders/variable_declaration.hpp
        compilation-old/builders/property_builder.cpp
        compilation-old/builders/property_builder.hpp
        compilation-old/builders/alias_declaration.hpp
        compilation-old/builders/encapsulated_alias_declaration.hpp
        compilation-old/builders/file_builder.cpp
        compilation-old/builders/file_builder.hpp
        compilation/walkers/walker_main.cpp
        compilation/walkers/walker_main.hpp
        compilation/compilation_unit.cpp
        compilation/compilation_unit.hpp
        compilation/walkers/walker_class.cpp
        compilation/walkers/walker_class.hpp
        compilation/data/pragma.hpp
        compilation/walkers/walker_namespace.cpp
        compilation/walkers/walker_namespace.hpp
        compilation/data/using.hpp
        compilation/walkers/walker_field.cpp
        compilation/walkers/walker_field.hpp
        compilation/walkers/walker_conversion.cpp
        compilation/walkers/walker_conversion.hpp
        compilation/walkers/walker_method.cpp
        compilation/walkers/walker_method.hpp
        compilation/walkers/walker_property.cpp
        compilation/walkers/walker_property.hpp
        compilation/walkers/walker_alias.cpp
        compilation/walkers/walker_alias.hpp
        compilation/walkers/walker_contract.cpp
        compilation/walkers/walker_contract.hpp)

# TODO: Add tests and install targets if needed.
