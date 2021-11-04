//
// Created by marco.silipo on 29.09.2021.
//

#ifndef SOLUTION_VARIABLE_DECLARATION_HPP
#define SOLUTION_VARIABLE_DECLARATION_HPP

#include "type_candidate.hpp"
#include <string>

namespace leaf::compilation::builders
{
    class variable_declaration
    {
        std::string m_name;
        type_candidate m_candidate;
    public:
        void name(std::string value) { m_name = std::move(value); }
        [[nodiscard]] std::string_view name() const { return m_name; }

        void candidate(type_candidate value) { m_candidate = std::move(value); }
        [[nodiscard]] type_candidate candidate() const { return m_candidate; }
    };
}

#endif //SOLUTION_VARIABLE_DECLARATION_HPP
