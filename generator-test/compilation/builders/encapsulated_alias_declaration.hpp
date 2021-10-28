//
// Created by marco.silipo on 29.09.2021.
//

#ifndef SOLUTION_ENCAPSULATED_ALIAS_DECLARATION_HPP
#define SOLUTION_ENCAPSULATED_ALIAS_DECLARATION_HPP

#include "alias_declaration.hpp"
#include "encapsulation_enum.hpp"

namespace leaf::compilation::builders
{
    class encapsulated_alias_declaration
    {
        encapsulation_enum m_encapsulation;
        alias_declaration m_alias;
    public:
        void encapsulation(encapsulation_enum value) { m_encapsulation = value; }
        [[nodiscard]] encapsulation_enum encapsulation() const { return m_encapsulation; }

        void alias(alias_declaration value) { m_alias = std::move(value); }
        [[nodiscard]] alias_declaration alias() const { return m_alias; }
    };
}

#endif //SOLUTION_ENCAPSULATED_ALIAS_DECLARATION_HPP
