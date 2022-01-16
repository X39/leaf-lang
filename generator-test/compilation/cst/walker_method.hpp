//
// Created by marco.silipo on 04.11.2021.
//

#ifndef SOLUTION_WALKER_METHOD_HPP
#define SOLUTION_WALKER_METHOD_HPP



#include "../../parser.hpp"
#include "compilation_unit.hpp"
#include "../data/pragma.hpp"


namespace leaf::compilation::cst
{
    class walker_method
    {
    private:
        const leaf::parsing::instance::method &m_node;
    public:
        walker_method(const leaf::parsing::instance::method &node) : m_node(node)
        {
        }

        void register_contents(compilation_unit cu);
    };
}



#endif //SOLUTION_WALKER_METHOD_HPP
