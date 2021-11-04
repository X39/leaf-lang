//
// Created by marco.silipo on 29.09.2021.
//

#ifndef SOLUTION_METHOD_BUILDER_HPP
#define SOLUTION_METHOD_BUILDER_HPP


#include "encapsulation_enum.hpp"
#include "type_candidate.hpp"
#include "variable_declaration.hpp"

#include <string>
#include <utility>
#include <vector>


namespace leaf::compilation::builders
{
    class method_builder
    {
    public:
        using sptr = std::shared_ptr<method_builder>;
        using parameter_iterator = std::vector<variable_declaration>::iterator;
    private:
        encapsulation_enum m_encapsulation;
        type_candidate m_return_candidate;
        std::string m_name;
        std::vector<variable_declaration> m_parameters;
    public:
        method_builder() : m_encapsulation(encapsulation_enum::PRIVATE) {}


        void name(std::string value) { m_name = std::move(value); }
        [[nodiscard]] std::string_view name() const { return m_name; }

        void encapsulation(encapsulation_enum value) { m_encapsulation = value; }
        [[nodiscard]] encapsulation_enum encapsulation() const { return m_encapsulation; }

        void return_candidate(type_candidate value) { m_return_candidate = std::move(value); }
        [[nodiscard]] type_candidate return_candidate() const { return m_return_candidate; }


        parameter_iterator parameters_begin() { return m_parameters.begin(); }
        parameter_iterator parameters_end() { return m_parameters.end(); }
        void push_parameter_back(variable_declaration&& value) { m_parameters.push_back(value); }
        void push_parameter_back(const variable_declaration& value) { m_parameters.push_back(value); }

    };
}


#endif //SOLUTION_METHOD_BUILDER_HPP
