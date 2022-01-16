//
// Created by marco.silipo on 04.11.2021.
//

#ifndef SOLUTION_WALKER_CONTRACT_HPP
#define SOLUTION_WALKER_CONTRACT_HPP


#include "../../parser.hpp"
#include "compilation_unit.hpp"
#include "../data/pragma.hpp"


namespace leaf::compilation::cst
{
    class walker_contract
    {
    private:
        const leaf::parsing::instance::contract &m_node;
    public:
        walker_contract(const leaf::parsing::instance::contract &node) : m_node(node)
        {
        }

        void register_contents(compilation_unit cu);
    };
}


#endif //SOLUTION_WALKER_CONTRACT_HPP
