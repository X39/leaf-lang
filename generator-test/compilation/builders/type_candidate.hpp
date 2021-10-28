//
// Created by marco.silipo on 29.09.2021.
//

#ifndef SOLUTION_TYPE_CANDIDATE_HPP
#define SOLUTION_TYPE_CANDIDATE_HPP

#include "template_definition_item.hpp"
#include "type_builder.hpp"

#include <optional>
#include <variant>

namespace leaf::compilation::builders
{
    class type_candidate
    {
    public:
        enum class type_enum {
            empty,
            templated,
            typed,
        };
    private:
        std::variant<std::monostate, template_definition_item, type_builder::sptr> m_data;
    public:
        type_candidate() : m_data(std::monostate{}) {}
        type_candidate(template_definition_item data) : m_data(data) {} // NOLINT(google-explicit-constructor)
        type_candidate(type_builder::sptr data) : m_data(data) {} // NOLINT(google-explicit-constructor)
        [[nodiscard]] type_enum type() const {
            if (std::holds_alternative<template_definition_item>(m_data)) { return type_enum::templated; }
            if (std::holds_alternative<type_builder::sptr>(m_data)) { return type_enum::typed; }
            return type_enum::empty;
        }
        [[nodiscard]] std::optional<template_definition_item> templated()
        { return type() != type_enum::templated ? std::optional<template_definition_item>{} : std::get<template_definition_item>(m_data); }
        [[nodiscard]] std::optional<type_builder::sptr> typed()
        { return type() != type_enum::templated ? std::optional<type_builder::sptr>{} : std::get<type_builder::sptr>(m_data); }
    };
}

#endif //SOLUTION_TYPE_CANDIDATE_HPP
