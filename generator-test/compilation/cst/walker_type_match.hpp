//
// Created by marco.silipo on 06.02.2022.
//

#ifndef SOLUTION_WALKER_TYPE_MATCH_HPP
#define SOLUTION_WALKER_TYPE_MATCH_HPP

#include "../../parser.hpp"
#include "../utility.hpp"
#include "compilation_unit.hpp"
#include "../data/pragma.hpp"
#include "../data/ast/type.hpp"
#include "ast_type_reference.hpp"

namespace leaf::compilation::cst
{
    class walker_type_match
    {
    private:
        std::shared_ptr<leaf::compilation::cst::ast_type_reference> m_type_reference;

        [[nodiscard]] std::shared_ptr<leaf::compilation::cst::ast_type_reference> solve_for_type_reference(
                compilation_unit& cu,
                const leaf::parsing::instance::type_match_no_allocator &node
                ) const;
        [[nodiscard]] std::shared_ptr<leaf::compilation::cst::ast_type_reference> solve_for_type_reference(
                compilation_unit& cu,
                const leaf::parsing::instance::type_match_with_allocator &node
                ) const;

    public:
        walker_type_match(compilation_unit& cu, const leaf::parsing::instance::type_match_no_allocator &node)
        {
            m_type_reference = solve_for_type_reference(cu, node);
        }
        walker_type_match(compilation_unit& cu, const leaf::parsing::instance::type_match_with_allocator &node)
        {
            m_type_reference = solve_for_type_reference(cu, node);
        }
        walker_type_match(compilation_unit& cu, const leaf::parsing::instance::type_match &node)
        {
            if (std::holds_alternative<std::shared_ptr<leaf::parsing::instance::type_match_with_allocator>>(node.match))
            {
                m_type_reference = solve_for_type_reference(
                        cu,
                        *std::get<std::shared_ptr<leaf::parsing::instance::type_match_with_allocator>>(
                                node.match));
            }
            else if (std::holds_alternative<std::shared_ptr<leaf::parsing::instance::type_match_no_allocator>>(node.match))
            {
                m_type_reference = solve_for_type_reference(
                        cu,
                        *std::get<std::shared_ptr<leaf::parsing::instance::type_match_no_allocator>>(
                                node.match));
            }
            else
            {
                throw std::runtime_error("Cannot resolve type reference due to no matching resolve method.");
            }
        }

        [[nodiscard]] std::shared_ptr<leaf::compilation::cst::ast_type_reference> get_type_reference() const {
            return m_type_reference;
        }
    };
}



#endif //SOLUTION_WALKER_TYPE_MATCH_HPP
