#pragma once
#include <memory>
#include <utility>
#include "../value_reference.hpp"
#include "../../parser.hpp"
#include "../../runtime/leaf_type.h"
#include "../conversion_solver.hpp"
namespace leaf::compilation::visitors
{
    class type_from_expression : private leaf::parsing::instance::visitor
    {
        value_reference m_value;
        std::shared_ptr<leaf::parsing::instance::expression> m_expression;
        bool m_has_visited;
        conversion_solver& m_solver;
    public:
        type_from_expression(conversion_solver& solver, std::shared_ptr<leaf::parsing::instance::expression> expression) :
            m_value({}),
            m_expression(std::move(expression)),
            m_has_visited(false),
            m_solver(solver)
        {
        }
        value_reference get()
        {
            if (!m_has_visited)
            {
                visit_enter(m_expression);
                visit_leave(m_expression);
                m_has_visited = true;
            }
            return m_value;
        }
        bool visit_enter(std::shared_ptr<leaf::parsing::instance::exp_chain_start> node) override;
        bool visit_leave(std::shared_ptr<leaf::parsing::instance::exp_chain_start> node) override;

        bool visit_enter(std::shared_ptr<leaf::parsing::instance::exp_constant> node) override;
        bool visit_leave(std::shared_ptr<leaf::parsing::instance::exp_constant> node) override;

        bool visit_enter(std::shared_ptr<leaf::parsing::instance::exp_value> node) override;
        bool visit_leave(std::shared_ptr<leaf::parsing::instance::exp_value> node) override;

        bool visit_enter(std::shared_ptr<leaf::parsing::instance::exp_nullar> node) override;
        bool visit_leave(std::shared_ptr<leaf::parsing::instance::exp_nullar> node) override;

        bool visit_enter(std::shared_ptr<leaf::parsing::instance::exp_unary> node) override;
        bool visit_leave(std::shared_ptr<leaf::parsing::instance::exp_unary> node) override;

        bool visit_enter(std::shared_ptr<leaf::parsing::instance::exp_chain> node) override;
        bool visit_leave(std::shared_ptr<leaf::parsing::instance::exp_chain> node) override;

        bool visit_enter(std::shared_ptr<leaf::parsing::instance::exp_binary_4> node) override;
        bool visit_leave(std::shared_ptr<leaf::parsing::instance::exp_binary_4> node) override;

        bool visit_enter(std::shared_ptr<leaf::parsing::instance::exp_binary_3> node) override;
        bool visit_leave(std::shared_ptr<leaf::parsing::instance::exp_binary_3> node) override;

        bool visit_enter(std::shared_ptr<leaf::parsing::instance::exp_binary_2> node) override;
        bool visit_leave(std::shared_ptr<leaf::parsing::instance::exp_binary_2> node) override;

        bool visit_enter(std::shared_ptr<leaf::parsing::instance::exp_binary_1> node) override;
        bool visit_leave(std::shared_ptr<leaf::parsing::instance::exp_binary_1> node) override;

        bool visit_enter(std::shared_ptr<leaf::parsing::instance::exp_arithmetic_2> node) override;
        bool visit_leave(std::shared_ptr<leaf::parsing::instance::exp_arithmetic_2> node) override;

        bool visit_enter(std::shared_ptr<leaf::parsing::instance::exp_arithmetic_1> node) override;
        bool visit_leave(std::shared_ptr<leaf::parsing::instance::exp_arithmetic_1> node) override;

        bool visit_enter(std::shared_ptr<leaf::parsing::instance::exp_compare> node) override;
        bool visit_leave(std::shared_ptr<leaf::parsing::instance::exp_compare> node) override;

        bool visit_enter(std::shared_ptr<leaf::parsing::instance::exp_equality> node) override;
        bool visit_leave(std::shared_ptr<leaf::parsing::instance::exp_equality> node) override;

        bool visit_enter(std::shared_ptr<leaf::parsing::instance::exp_and> node) override;
        bool visit_leave(std::shared_ptr<leaf::parsing::instance::exp_and> node) override;

        bool visit_enter(std::shared_ptr<leaf::parsing::instance::exp_or> node) override;
        bool visit_leave(std::shared_ptr<leaf::parsing::instance::exp_or> node) override;

        bool visit_enter(std::shared_ptr<leaf::parsing::instance::expression> node) override;
        bool visit_leave(std::shared_ptr<leaf::parsing::instance::expression> node) override;
    };
}