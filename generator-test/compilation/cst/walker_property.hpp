//
// Created by marco.silipo on 04.11.2021.
//

#ifndef SOLUTION_WALKER_PROPERTY_HPP
#define SOLUTION_WALKER_PROPERTY_HPP


#include "../../parser.hpp"
#include "compilation_unit.hpp"
#include "../data/pragma.hpp"


namespace leaf::compilation::cst
{
    class walker_property
    {
    private:
        const leaf::parsing::instance::property &m_node;
    public:
        walker_property(const leaf::parsing::instance::property &node) : m_node(node)
        {
        }

        void register_contents(compilation_unit cu);
    };
}


#endif //SOLUTION_WALKER_PROPERTY_HPP
