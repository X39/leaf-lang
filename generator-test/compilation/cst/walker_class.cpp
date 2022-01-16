//
// Created by marco.silipo on 04.11.2021.
//

#include "walker_class.hpp"

#include "walker_class.hpp"
#include "walker_namespace.hpp"
#include "walker_conversion.hpp"
#include "walker_field.hpp"
#include "walker_method.hpp"
#include "walker_property.hpp"
#include "walker_contract.hpp"
#include "walker_alias.hpp"
#include "walker_constant.hpp"
#include "walker_attribute.hpp"

void leaf::compilation::cst::walker_class::register_contents(leaf::compilation::cst::compilation_unit cu)
{
    auto t = cu.get_type_builder(utility::to_string(cu.contents(), m_node.name));
    auto using_scope = cu.with_using_scope();
    for (const auto &node: m_node.usings)
    {
        cu.push_back(data::using_(*node));
    }
    for (const auto &node: m_node.pragmas)
    {
        cu.push_back(data::pragma(*node));
    }
}
