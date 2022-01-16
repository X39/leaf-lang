//
// Created by marco.silipo on 04.11.2021.
//

#ifndef SOLUTION_WALKER_FIELD_HPP
#define SOLUTION_WALKER_FIELD_HPP


#include "../../parser.hpp"
#include "compilation_unit.hpp"
#include "../data/pragma.hpp"


namespace leaf::compilation::cst
{
    class walker_field
    {
    private:
        const leaf::parsing::instance::field &m_node;
    public:
        walker_field(const leaf::parsing::instance::field &node) : m_node(node)
        {
        }

        void register_contents(compilation_unit cu);
    };
}


#endif //SOLUTION_WALKER_FIELD_HPP
