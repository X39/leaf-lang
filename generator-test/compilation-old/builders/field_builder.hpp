//
// Created by marco.silipo on 29.09.2021.
//

#ifndef SOLUTION_FIELD_BUILDER_HPP
#define SOLUTION_FIELD_BUILDER_HPP

#include "encapsulation_enum.hpp"
#include "type_candidate.hpp"

#include <string>
#include <utility>

namespace leaf::compilation::builders
{
    class field_builder
    {
    public:
        using sptr = std::shared_ptr<field_builder>;
    private:
        encapsulation_enum m_encapsulation;
        type_candidate m_candidate;
        std::string m_name;
    public:
        field_builder() : m_encapsulation(encapsulation_enum::PRIVATE) {}


        void name(std::string value) { m_name = std::move(value); }
        [[nodiscard]] std::string_view name() const { return m_name; }

        void encapsulation(encapsulation_enum value) { m_encapsulation = value; }
        [[nodiscard]] encapsulation_enum encapsulation() const { return m_encapsulation; }

        void candidate(type_candidate value) { m_candidate = std::move(value); }
        [[nodiscard]] type_candidate candidate() const { return m_candidate; }

    };
}


#endif //SOLUTION_FIELD_BUILDER_HPP
