#pragma once

#include "../parser.hpp"


namespace leaf::compilation
{
    class method_builder
    {
        leaf::parsing::instance::scope& m_scope;
    public:
        explicit method_builder(leaf::parsing::instance::scope& s) : m_scope(s) {}


    };
}