//
// Created by marco.silipo on 04.11.2021.
//

#ifndef SOLUTION_FILE_BUILDER_HPP
#define SOLUTION_FILE_BUILDER_HPP

#include "../../parser.hpp"


class file_builder
{
private:
    const leaf::parsing::instance::main& m_node;
public:
    file_builder(const leaf::parsing::instance::main& node) : m_node(node) {}

    void register_contents()
    {
    }
};


#endif //SOLUTION_FILE_BUILDER_HPP
