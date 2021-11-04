//
// Created by marco.silipo on 04.11.2021.
//

#ifndef SOLUTION_COMPILATION_UNIT_HPP
#define SOLUTION_COMPILATION_UNIT_HPP


#include "data/pragma.hpp"
#include "data/using.hpp"

class compilation_unit
{

public:
    void push_back(leaf::compilation::data::pragma node);
    void push_back(leaf::compilation::data::using_ node);
};


#endif //SOLUTION_COMPILATION_UNIT_HPP
