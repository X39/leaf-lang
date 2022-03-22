//
// Created by marco.silipo on 15.11.2021.
//

#include "walker_attribute_item.hpp"
#include "walker_type_match.hpp"

void leaf::compilation::cst::walker_attribute_item::register_contents(leaf::compilation::cst::compilation_unit &cu)
{
    auto type_match_walker = walker_type_match(cu, *m_node.target_type);
    type_match_walker.get_type_reference();
    for (auto it : m_node.args_a)
    {

    }
    for (auto it : m_node.args_b)
    {

    }
}
