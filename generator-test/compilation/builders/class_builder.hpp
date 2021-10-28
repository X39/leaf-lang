//
// Created by marco.silipo on 29.09.2021.
//

#ifndef SOLUTION_CLASS_BUILDER_HPP
#define SOLUTION_CLASS_BUILDER_HPP

#include "template_definition_item.hpp"
#include "encapsulation_enum.hpp"
#include "encapsulated_alias_declaration.hpp"
#include "type_builder.hpp"
#include "method_builder.hpp"
#include "field_builder.hpp"
#include "property_builder.hpp"
#include "../../parser.hpp"

#include <string>
#include <utility>
#include <vector>
#include <memory>

namespace leaf::compilation::builders
{
    class class_builder
    {
    public:
        using sptr = std::shared_ptr<class_builder>;
        using template_definition_item_iterator = std::vector<template_definition_item>::iterator;
        using type_builder_iterator = std::vector<type_builder::sptr>::iterator;
        using class_builder_iterator = std::vector<class_builder::sptr>::iterator;
        using field_builder_iterator = std::vector<field_builder::sptr>::iterator;
        using method_builder_iterator = std::vector<method_builder::sptr>::iterator;
        using property_builder_iterator = std::vector<property_builder::sptr>::iterator;
        using alias_iterator = std::vector<encapsulated_alias_declaration>::iterator;
    private:
        encapsulation_enum m_encapsulation;
        std::string m_name;
        std::vector<template_definition_item> m_template_definition_items;
        std::vector<type_builder::sptr> m_inherited_types;
        std::vector<class_builder::sptr> m_sub_classes;
        std::vector<field_builder::sptr> m_fields;
        std::vector<method_builder::sptr> m_methods;
        std::vector<property_builder::sptr> m_properties;
        std::vector<encapsulated_alias_declaration> m_aliases;
    public:
        class_builder() = default;

        void name(std::string value) { m_name = std::move(value); }
        [[nodiscard]] std::string_view name() const { return m_name; }

        void encapsulation(encapsulation_enum value) { m_encapsulation = value; }
        [[nodiscard]] encapsulation_enum encapsulation() const { return m_encapsulation; }

        template_definition_item_iterator template_definition_items_begin() { return m_template_definition_items.begin(); }
        template_definition_item_iterator template_definition_items_end() { return m_template_definition_items.end(); }
        void push_template_definition_item_back(template_definition_item&& value) { m_template_definition_items.push_back(value); }
        void push_template_definition_item_back(const template_definition_item& value) { m_template_definition_items.push_back(value); }

        type_builder_iterator inherited_types_begin() { return m_inherited_types.begin(); }
        type_builder_iterator inherited_types_end() { return m_inherited_types.end(); }
        void push_inherited_type_back(type_builder::sptr&& value) { m_inherited_types.push_back(value); }
        void push_inherited_type_back(const type_builder::sptr& value) { m_inherited_types.push_back(value); }

        class_builder_iterator sub_classes_begin() { return m_sub_classes.begin(); }
        class_builder_iterator sub_classes_end() { return m_sub_classes.end(); }
        void push_sub_class_back(class_builder::sptr&& value) { m_sub_classes.push_back(value); }
        void push_sub_class_back(const class_builder::sptr& value) { m_sub_classes.push_back(value); }

        method_builder_iterator fields_begin() { return m_methods.begin(); }
        method_builder_iterator fields_end() { return m_methods.end(); }
        void push_field_back(method_builder::sptr&& value) { m_methods.push_back(value); }
        void push_field_back(const method_builder::sptr& value) { m_methods.push_back(value); }

        method_builder_iterator methods_begin() { return m_methods.begin(); }
        method_builder_iterator methods_end() { return m_methods.end(); }
        void push_method_back(method_builder::sptr&& value) { m_methods.push_back(value); }
        void push_method_back(const method_builder::sptr& value) { m_methods.push_back(value); }

        property_builder_iterator properties_begin() { return m_properties.begin(); }
        property_builder_iterator properties_end() { return m_properties.end(); }
        void push_property_back(property_builder::sptr&& value) { m_properties.push_back(value); }
        void push_property_back(const property_builder::sptr& value) { m_properties.push_back(value); }

        alias_iterator aliases_begin() { return m_aliases.begin(); }
        alias_iterator aliases_end() { return m_aliases.end(); }
        void push_alias_back(encapsulated_alias_declaration&& value) { m_aliases.push_back(value); }
        void push_alias_back(const encapsulated_alias_declaration& value) { m_aliases.push_back(value); }
    };
}

/*
public class foo<T, identifier T2> : bar, with_bar<T>
{
    public class sub { }

    private T _field1;
    private int _field2;

    public T property { ... }

    public void method(T arg1, int arg2) { ... }

    public alias list<T> = list_of_ts;
}

 */

#endif //SOLUTION_CLASS_BUILDER_HPP
