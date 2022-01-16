//
// Created by marco.silipo on 04.11.2021.
//

#include "compilation_unit.hpp"

leaf::compilation::cst::compilation_unit::using_scope leaf::compilation::cst::compilation_unit::with_using_scope()
{
    return { };
}

std::shared_ptr<leaf::compilation::cst::ast_type_builder>
leaf::compilation::cst::compilation_unit::get_type_builder(std::string_view name)
{
    return std::shared_ptr<leaf::compilation::cst::ast_type_builder>();
}

std::string_view leaf::compilation::cst::compilation_unit::contents()
{
    return std::string_view();
}

void leaf::compilation::cst::compilation_unit::push_back(leaf::compilation::data::using_ node)
{

}

void leaf::compilation::cst::compilation_unit::push_back(leaf::compilation::data::pragma node)
{

}

std::shared_ptr<leaf::compilation::cst::ast_type_reference>
leaf::compilation::cst::compilation_unit::get_type_reference(std::string_view name)
{
    // ToDo: Unless name starts with ::, solve with usings
    return std::shared_ptr<leaf::compilation::cst::ast_type_reference>();
}
