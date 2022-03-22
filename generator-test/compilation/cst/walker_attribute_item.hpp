//
// Created by marco.silipo on 15.11.2021.
//

#ifndef SOLUTION_WALKER_ATTRIBUTE_ITEM_HPP
#define SOLUTION_WALKER_ATTRIBUTE_ITEM_HPP

#include "../../parser.hpp"
#include "../utility.hpp"
#include "compilation_unit.hpp"
#include "../data/pragma.hpp"
#include "../data/ast/type.hpp"
#include "ast_type_builder.hpp"

namespace leaf::compilation::cst
{
    class walker_attribute_item
    {
    private:
        ast_type_builder *m_type_builder;
        const leaf::parsing::instance::attribute_item &m_node;
    public:
        walker_attribute_item(ast_type_builder* type_builder, const leaf::parsing::instance::attribute_item &node)
        : m_type_builder(type_builder), m_node(node)
        {
        }

        void register_contents(compilation_unit& cu);
    };
}



#endif //SOLUTION_WALKER_ATTRIBUTE_ITEM_HPP
