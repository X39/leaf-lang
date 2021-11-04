//
// Created by marco.silipo on 04.11.2021.
//

#include "../data/pragma.hpp"
#include "../data/using.hpp"
#include "walker_main.hpp"

#include "walker_class.hpp"
#include "walker_namespace.hpp"
#include "walker_conversion.hpp"
#include "walker_field.hpp"
#include "walker_method.hpp"
#include "walker_property.hpp"
#include "walker_contract.hpp"
#include "walker_alias.hpp"

void leaf::compilation::walkers::walker_main::register_contents(compilation_unit cu)
{
    for (const auto &node: m_node.pragmas)
    {
        cu.push_back(data::pragma(*node));
    }
    for (const auto &node: m_node.usings)
    {
        cu.push_back(data::using_(*node));
    }
    for (const auto &node: m_node.namespaces)
    {
        walker_namespace(*node).register_contents(cu);
    }
    for (const auto &node: m_node.classes)
    {
        walker_class(*node).register_contents(cu);
    }
    for (const auto &node: m_node.conversions)
    {
        walker_conversion(*node).register_contents(cu);
    }
    for (const auto &node: m_node.fields)
    {
        walker_field(*node).register_contents(cu);
    }
    for (const auto &node: m_node.methods)
    {
        walker_method(*node).register_contents(cu);
    }
    for (const auto &node: m_node.properties)
    {
        walker_property(*node).register_contents(cu);
    }
    for (const auto &node: m_node.aliases)
    {
        walker_alias(*node).register_contents(cu);
    }
    for (const auto &node: m_node.contract)
    {
        walker_contract(*node).register_contents(cu);
    }
}
