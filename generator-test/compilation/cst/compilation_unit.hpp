//
// Created by marco.silipo on 04.11.2021.
//

#ifndef SOLUTION_COMPILATION_UNIT_HPP
#define SOLUTION_COMPILATION_UNIT_HPP


#include "../data/pragma.hpp"
#include "ast_type_builder.hpp"
#include "ast_type_reference.hpp"
#include "../data/using.hpp"

namespace leaf::compilation::cst
{
    class compilation_unit
    {
    public:
        class using_scope
        {

        };

    public:
        void push_back(leaf::compilation::data::pragma node);

        void push_back(leaf::compilation::data::using_ node);

        std::string_view contents();

        std::shared_ptr<leaf::compilation::cst::ast_type_builder> get_type_builder(std::string_view name);

        std::shared_ptr<leaf::compilation::cst::ast_type_reference> get_type_reference(std::string_view name);

        using_scope with_using_scope();
    };
}

#endif //SOLUTION_COMPILATION_UNIT_HPP
