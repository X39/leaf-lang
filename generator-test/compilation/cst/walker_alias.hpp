//
// Created by marco.silipo on 04.11.2021.
//

#ifndef SOLUTION_WALKER_ALIAS_HPP
#define SOLUTION_WALKER_ALIAS_HPP


#include "../../parser.hpp"
#include "compilation_unit.hpp"
#include "../data/pragma.hpp"


namespace leaf::compilation::cst
{
    class walker_alias
    {
    private:
        ast_type_builder *m_type_builder;
        const leaf::parsing::instance::token m_encapsulation;
        const leaf::parsing::instance::alias &m_node;
    public:
        walker_alias(const leaf::parsing::instance::alias &node)
                : m_type_builder(nullptr), m_node(node),
                  m_encapsulation({ parsing::instance::tok::_PUBLIC, { }, SIZE_MAX, SIZE_MAX, SIZE_MAX, SIZE_MAX })
        {
        }

        walker_alias(ast_type_builder* type_builder, const leaf::parsing::instance::alias_encapsulated &node)
                : m_type_builder(type_builder), m_node(*node.actual), m_encapsulation(node.encaps->tok)
        {
        }

        void register_contents(compilation_unit cu);
    };
}


#endif //SOLUTION_WALKER_ALIAS_HPP
