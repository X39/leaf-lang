//
// Created by marco.silipo on 29.09.2021.
//

#ifndef SOLUTION_PROPERTY_BUILDER_HPP
#define SOLUTION_PROPERTY_BUILDER_HPP


#include "encapsulation_enum.hpp"
#include "type_candidate.hpp"

#include <string>
#include <utility>


namespace leaf::compilation::builders
{
    class property_builder
    {
    public:
        using sptr = std::shared_ptr<property_builder>;
    private:
        encapsulation_enum m_encapsulation;
        type_candidate m_candidate;
        std::string m_name;
    public:
        property_builder() : m_encapsulation(encapsulation_enum::PRIVATE) {}


        void name(std::string value) { m_name = std::move(value); }
        [[nodiscard]] std::string_view name() const { return m_name; }

        void encapsulation(encapsulation_enum value) { m_encapsulation = value; }
        [[nodiscard]] encapsulation_enum encapsulation() const { return m_encapsulation; }

        void candidate(type_candidate value) { m_candidate = std::move(value); }
        [[nodiscard]] type_candidate return_candidate() const { return m_candidate; }
    };
}


#endif //SOLUTION_PROPERTY_BUILDER_HPP
