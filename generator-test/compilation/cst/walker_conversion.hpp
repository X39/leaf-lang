//
// Created by marco.silipo on 04.11.2021.
//

#ifndef SOLUTION_WALKER_CONVERSION_HPP
#define SOLUTION_WALKER_CONVERSION_HPP


#include "../../parser.hpp"
#include "compilation_unit.hpp"
#include "../data/pragma.hpp"


namespace leaf::compilation::cst
{
    class walker_conversion
    {
    private:
        const leaf::parsing::instance::conversion &m_node;
    public:
        walker_conversion(const leaf::parsing::instance::conversion &node) : m_node(node)
        {
        }

        void register_contents(compilation_unit cu);
    };
}


#endif //SOLUTION_WALKER_CONVERSION_HPP
