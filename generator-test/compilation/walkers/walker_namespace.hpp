//
// Created by marco.silipo on 04.11.2021.
//

#ifndef SOLUTION_WALKER_NAMESPACE_HPP
#define SOLUTION_WALKER_NAMESPACE_HPP

#include "../../parser.hpp"
#include "../compilation_unit.hpp"
#include "../data/pragma.hpp"


namespace leaf::compilation::walkers
{
    class walker_namespace
    {
    private:
        const leaf::parsing::instance::namespace_ &m_node;
    public:
        walker_namespace(const leaf::parsing::instance::namespace_ &node) : m_node(node)
        {
        }

        void register_contents(compilation_unit cu);
    };
}


#endif //SOLUTION_WALKER_NAMESPACE_HPP
