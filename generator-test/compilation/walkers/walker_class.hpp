//
// Created by marco.silipo on 04.11.2021.
//

#ifndef SOLUTION_WALKER_CLASS_HPP
#define SOLUTION_WALKER_CLASS_HPP

#include "../../parser.hpp"
#include "../compilation_unit.hpp"
#include "../data/pragma.hpp"


namespace leaf::compilation::walkers
{
    class walker_class
    {
    private:
        const leaf::parsing::instance::class_ &m_node;
    public:
        walker_class(const leaf::parsing::instance::class_ &node) : m_node(node)
        {
        }

        void register_contents(compilation_unit cu);
    };
}

#endif //SOLUTION_WALKER_CLASS_HPP
