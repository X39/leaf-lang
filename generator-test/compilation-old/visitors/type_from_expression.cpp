//
// Created by marco.silipo on 04.08.2021.
//

#include "type_from_expression.hpp"

bool leaf::compilation::visitors::type_from_expression::visit_enter(
        std::shared_ptr<leaf::parsing::instance::exp_chain_start> node)
{
    return visitor::visit_enter(node);
}

bool leaf::compilation::visitors::type_from_expression::visit_leave(
        std::shared_ptr<leaf::parsing::instance::exp_chain_start> node)
{
    return visitor::visit_leave(node);
}

bool leaf::compilation::visitors::type_from_expression::visit_enter(
        std::shared_ptr<leaf::parsing::instance::exp_constant> node)
{
    return visitor::visit_enter(node);
}

bool leaf::compilation::visitors::type_from_expression::visit_leave(
        std::shared_ptr<leaf::parsing::instance::exp_constant> node)
{
    return visitor::visit_leave(node);
}

bool leaf::compilation::visitors::type_from_expression::visit_enter(
        std::shared_ptr<leaf::parsing::instance::exp_value> node)
{
    return visitor::visit_enter(node);
}

bool leaf::compilation::visitors::type_from_expression::visit_leave(
        std::shared_ptr<leaf::parsing::instance::exp_value> node)
{
    return visitor::visit_leave(node);
}

bool leaf::compilation::visitors::type_from_expression::visit_enter(
        std::shared_ptr<leaf::parsing::instance::exp_nullar> node)
{
    return visitor::visit_enter(node);
}

bool leaf::compilation::visitors::type_from_expression::visit_leave(
        std::shared_ptr<leaf::parsing::instance::exp_nullar> node)
{
    return visitor::visit_leave(node);
}

bool leaf::compilation::visitors::type_from_expression::visit_enter(
        std::shared_ptr<leaf::parsing::instance::exp_unary> node)
{
    return visitor::visit_enter(node);
}

bool leaf::compilation::visitors::type_from_expression::visit_leave(
        std::shared_ptr<leaf::parsing::instance::exp_unary> node)
{
    return visitor::visit_leave(node);
}

bool leaf::compilation::visitors::type_from_expression::visit_enter(
        std::shared_ptr<leaf::parsing::instance::exp_chain> node)
{
    return visitor::visit_enter(node);
}

bool leaf::compilation::visitors::type_from_expression::visit_leave(
        std::shared_ptr<leaf::parsing::instance::exp_chain> node)
{
    return visitor::visit_leave(node);
}

bool leaf::compilation::visitors::type_from_expression::visit_enter(
        std::shared_ptr<leaf::parsing::instance::exp_binary_4> node)
{
    return visitor::visit_enter(node);
}

bool leaf::compilation::visitors::type_from_expression::visit_leave(
        std::shared_ptr<leaf::parsing::instance::exp_binary_4> node)
{
    return visitor::visit_leave(node);
}

bool leaf::compilation::visitors::type_from_expression::visit_enter(
        std::shared_ptr<leaf::parsing::instance::exp_binary_3> node)
{
    return visitor::visit_enter(node);
}

bool leaf::compilation::visitors::type_from_expression::visit_leave(
        std::shared_ptr<leaf::parsing::instance::exp_binary_3> node)
{
    return visitor::visit_leave(node);
}

bool leaf::compilation::visitors::type_from_expression::visit_enter(
        std::shared_ptr<leaf::parsing::instance::exp_binary_2> node)
{
    return visitor::visit_enter(node);
}

bool leaf::compilation::visitors::type_from_expression::visit_leave(
        std::shared_ptr<leaf::parsing::instance::exp_binary_2> node)
{
    return visitor::visit_leave(node);
}

bool leaf::compilation::visitors::type_from_expression::visit_enter(
        std::shared_ptr<leaf::parsing::instance::exp_binary_1> node)
{
    return visitor::visit_enter(node);
}

bool leaf::compilation::visitors::type_from_expression::visit_leave(
        std::shared_ptr<leaf::parsing::instance::exp_binary_1> node)
{
    return visitor::visit_leave(node);
}

bool leaf::compilation::visitors::type_from_expression::visit_enter(
        std::shared_ptr<leaf::parsing::instance::exp_arithmetic_2> node)
{
    return visitor::visit_enter(node);
}

bool leaf::compilation::visitors::type_from_expression::visit_leave(
        std::shared_ptr<leaf::parsing::instance::exp_arithmetic_2> node)
{
    return visitor::visit_leave(node);
}

bool leaf::compilation::visitors::type_from_expression::visit_enter(
        std::shared_ptr<leaf::parsing::instance::exp_arithmetic_1> node)
{
    return visitor::visit_enter(node);
}

bool leaf::compilation::visitors::type_from_expression::visit_leave(
        std::shared_ptr<leaf::parsing::instance::exp_arithmetic_1> node)
{
    return visitor::visit_leave(node);
}

bool leaf::compilation::visitors::type_from_expression::visit_enter(
        std::shared_ptr<leaf::parsing::instance::exp_compare> node)
{
    return visitor::visit_enter(node);
}

bool leaf::compilation::visitors::type_from_expression::visit_leave(
        std::shared_ptr<leaf::parsing::instance::exp_compare> node)
{
    return visitor::visit_leave(node);
}

bool leaf::compilation::visitors::type_from_expression::visit_enter(
        std::shared_ptr<leaf::parsing::instance::exp_equality> node)
{
    return visitor::visit_enter(node);
}

bool leaf::compilation::visitors::type_from_expression::visit_leave(
        std::shared_ptr<leaf::parsing::instance::exp_equality> node)
{
    return visitor::visit_leave(node);
}

bool leaf::compilation::visitors::type_from_expression::visit_enter(
        std::shared_ptr<leaf::parsing::instance::exp_and> node)
{
    return visitor::visit_enter(node);
}

bool leaf::compilation::visitors::type_from_expression::visit_leave(
        std::shared_ptr<leaf::parsing::instance::exp_and> node)
{
    return visitor::visit_leave(node);
}

bool leaf::compilation::visitors::type_from_expression::visit_enter(
        std::shared_ptr<leaf::parsing::instance::exp_or> node)
{
    return visitor::visit_enter(node);
}

bool leaf::compilation::visitors::type_from_expression::visit_leave(
        std::shared_ptr<leaf::parsing::instance::exp_or> node)
{
    return visitor::visit_leave(node);
}

bool leaf::compilation::visitors::type_from_expression::visit_enter(
        std::shared_ptr<leaf::parsing::instance::expression> node)
{
    return visitor::visit_enter(node);
}

bool leaf::compilation::visitors::type_from_expression::visit_leave(
        std::shared_ptr<leaf::parsing::instance::expression> node)
{
    return visitor::visit_leave(node);
}
