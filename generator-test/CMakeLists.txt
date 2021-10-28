# CMakeList.txt : CMake project for generator-test, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (generator-test  "main.cpp"
                                "main.hpp"
                                "parser.hpp"
                                "parser.cpp"
                                "runtime/leaf_string.h"
                                "runtime/leaf_string.c"
                                "runtime/leaf_type.h"
                                "runtime/leaf_type.c"
                                "runtime/leaf_macros.h"
                                "runtime/leaf_library.h"
                                "runtime/leaf_library.c"
                                "runtime/leaf_emit.h"
                                "runtime/leaf_opcodes.h"
                                "compilation/leaf_compiler.hpp"
                                "compilation/leaf_compiler.cpp"
                                "compilation/leaf_reporting.hpp"
                                "compilation/stages/stage_base.hpp"
                                "compilation/stages/stage_base.cpp"
                                "compilation/stages/0_register_types.hpp"
                                "compilation/stages/0_register_types.cpp"
                                "compilation/stages/1_register_contents.cpp"
                                "compilation/stages/1_register_contents.hpp"
                                "compilation/stages/2_set_type_size.hpp"
                                "compilation/stages/2_set_type_size.cpp"
                                "compilation/stages/3_emit_bytecode.hpp"
                                "compilation/stages/3_emit_bytecode.cpp" compilation/visitors/type_from_expression.cpp compilation/visitors/type_from_expression.hpp compilation/value_reference.hpp compilation/conversion_solver.hpp compilation/method_call_solver.hpp compilation/method_builder.hpp compilation/builders/class_builder.cpp compilation/builders/class_builder.hpp compilation/builders/template_definition_item.hpp compilation/builders/encapsulation_enum.hpp compilation/builders/type_builder.cpp compilation/builders/type_builder.hpp compilation/builders/type_candidate.hpp compilation/builders/field_builder.cpp compilation/builders/field_builder.hpp compilation/builders/method_builder.cpp compilation/builders/method_builder.hpp compilation/builders/variable_declaration.hpp compilation/builders/property_builder.cpp compilation/builders/property_builder.hpp compilation/builders/alias_declaration.hpp compilation/builders/encapsulated_alias_declaration.hpp)

# TODO: Add tests and install targets if needed.
