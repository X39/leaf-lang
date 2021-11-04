//
// Created by marco.silipo on 04.11.2021.
//

#ifndef SOLUTION_USING_HPP
#define SOLUTION_USING_HPP
#include "../../parser.hpp"

namespace leaf::compilation::data
{
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCInconsistentNamingInspection"
    class using_
#pragma clang diagnostic pop
    {
    public:
        explicit using_(parsing::instance::using_& node)
        {

        }
    };
}

#endif //SOLUTION_USING_HPP
