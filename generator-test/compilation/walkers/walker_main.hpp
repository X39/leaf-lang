//
// Created by marco.silipo on 04.11.2021.
//

#ifndef SOLUTION_WALKER_MAIN_HPP
#define SOLUTION_WALKER_MAIN_HPP

#include "../../parser.hpp"
#include "../compilation_unit.hpp"

namespace leaf::compilation::walkers
{
    class walker_main
    {
    private:
        const leaf::parsing::instance::main &m_node;
    public:
        explicit walker_main(const leaf::parsing::instance::main &node) : m_node(node)
        {
        }

        void register_contents(compilation_unit cu);
    };
}


#endif //SOLUTION_WALKER_MAIN_HPP
