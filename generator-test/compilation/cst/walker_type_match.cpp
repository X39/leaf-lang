//
// Created by marco.silipo on 06.02.2022.
//

#include "walker_type_match.hpp"

std::shared_ptr<leaf::compilation::cst::ast_type_reference>
leaf::compilation::cst::walker_type_match::solve_for_type_reference(
        leaf::compilation::cst::compilation_unit &cu,
        const leaf::parsing::instance::type_match_no_allocator &node) const
{
    // ToDo: Implement
    return std::shared_ptr<leaf::compilation::cst::ast_type_reference>();
}
std::shared_ptr<leaf::compilation::cst::ast_type_reference>
leaf::compilation::cst::walker_type_match::solve_for_type_reference(
        leaf::compilation::cst::compilation_unit &cu,
        const leaf::parsing::instance::type_match_with_allocator &node) const
{
    // ToDo: Implement
    return std::shared_ptr<leaf::compilation::cst::ast_type_reference>();
}
