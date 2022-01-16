#include "3_emit_bytecode.hpp"
#include "../../runtime/leaf_emit.h"
#include <charconv>

#define BLOB &helper.current_type()->bytecode

using namespace std::string_literals;
using namespace std::string_view_literals;

bool leaf::compilation::stages::emit_bytecode::visit_enter(
        std::shared_ptr<leaf::parsing::instance::property> node) {
    return false;
}

bool leaf::compilation::stages::emit_bytecode::visit_enter(
        std::shared_ptr<leaf::parsing::instance::method> node) {
    return false;
}

bool leaf::compilation::stages::emit_bytecode::visit_enter(
        std::shared_ptr<leaf::parsing::instance::field> node) {
    return false;
}

bool leaf::compilation::stages::emit_bytecode::visit_enter(
        std::shared_ptr<leaf::parsing::instance::conversion> node) {
    return false;
}

bool leaf::compilation::stages::emit_bytecode::visit_enter(
        std::shared_ptr<leaf::parsing::instance::operator_binary_overload> node) {
    return false;
}

bool leaf::compilation::stages::emit_bytecode::visit_enter(
        std::shared_ptr<leaf::parsing::instance::operator_unary_overload> node) {
    return false;
}

bool leaf::compilation::stages::emit_bytecode::visit_enter(
        std::shared_ptr<leaf::parsing::instance::constructor> node) {
    return false;
}

bool leaf::compilation::stages::emit_bytecode::visit_enter(
        std::shared_ptr<leaf::parsing::instance::copystructor> node) {
    return false;
}

bool leaf::compilation::stages::emit_bytecode::visit_enter(
        std::shared_ptr<leaf::parsing::instance::destructor> node) {
    return false;
}

bool leaf::compilation::stages::emit_bytecode::visit_enter(
        std::shared_ptr<leaf::parsing::instance::method_arglist_item> node) {
    return false;
}




bool leaf::compilation::stages::emit_bytecode::emit_exp(
        const std::shared_ptr<leaf::parsing::instance::expression> &node) {
    if (node->assign_to) {
        // ToDo: Rewrite Section
        //       - Assign Stack & Heap via function call
        //       - Both Stack & Heap want direct memory modification (heap just is not that local)
        //       - Figure out a way to handle properties properly as assignment means
        //       - we have a problem as GET is not enough
        if (!emit_exp(node->assign_to)) { return false; }
        if (!emit_exp(node->value)) { return false; }
        helper.current_scope().clone(0, 1);
        helper.current_scope().pop_destroy();
    } else if (node->exp) {
        if (!emit_exp(node->exp)) { return false; }
    } else {
        throw std::runtime_error("Not all variant paths are handled.");
    }
    return true;
}


bool leaf::compilation::stages::emit_bytecode::emit_exp(
        const std::shared_ptr<leaf::parsing::instance::exp_chain> &node) {
    return false;
}
bool leaf::compilation::stages::emit_bytecode::emit_exp(
        const std::shared_ptr<leaf::parsing::instance::call_body> &node,
        std::vector<std::tuple<leaf_type_reference, leaf_type_ptr>>& out_params) {
    // ToDo: Rearrange into separate call resolution class
    //       - Class should be responsible for actually emiting the entire call code
    //       - Parameter finding must happen one-by-one or once first and then again
    //         to support proper conversion and copy-handling/avoidance
    //       - Should be used instead of whatever is used now in alloc and operators
    //       - A copy only has to be made if a type wants a non-heap version.
    //       - Lifetime is questionable at best for heap-versions, figure out a way to handle those
    //         when eg. a stack value is moved into a reference spot and the callee might assume it is
    //         some heap value.
    // ToDo: Figure out a way how to handle reference vs copy in calls

    // Store current value stack index to read in parameter types later
    auto current_stack_index = helper.current_scope().values_size();

    // Build types out to the max using normal emitting
    for (auto param : node->args)
    {
        if (!emit_exp(param))
        {
            return false;
        }
    }
    for (auto t = current_stack_index; t < helper.current_scope().values_size(); t++)
    {
        auto ref = helper.current_scope().at(t);
        out_params.push_back({ ref.type_reference, ref.type_ptr });
    }
    return true;
}

bool leaf::compilation::stages::emit_bytecode::emit_exp(
        const std::shared_ptr<leaf::parsing::instance::scalar_literal>& node) {
    return false;
}
bool leaf::compilation::stages::emit_bytecode::emit_exp(
        const std::shared_ptr<leaf::parsing::instance::integer_binary_literal>& node) {
    return false;
}
bool leaf::compilation::stages::emit_bytecode::emit_exp(
        const std::shared_ptr<leaf::parsing::instance::integer_hex_literal>& node) {
    return false;
}
bool leaf::compilation::stages::emit_bytecode::emit_exp(
        const std::shared_ptr<leaf::parsing::instance::integer_literal>& node) {
    return false;
}
bool leaf::compilation::stages::emit_bytecode::emit_exp(
        const std::shared_ptr<leaf::parsing::instance::char_literal>& node) {
    return false;
}
bool leaf::compilation::stages::emit_bytecode::emit_exp(
        const std::shared_ptr<leaf::parsing::instance::string_literal> &node) {
    return false;
}

bool leaf::compilation::stages::emit_bytecode::emit_exp(
        const std::shared_ptr<leaf::parsing::instance::exp_constant> &node) {
    if (node->typeof_)
    {
        if (!emit_exp(node->typeof_)) { return false; }
    }
    else if (node->nameof)
    {
        if (!emit_exp(node->nameof)) { return false; }
    }
    else if (node->sizeof_)
    {
        if (!emit_exp(node->sizeof_)) { return false; }
    }
    else if (node->t.type != leaf::parsing::instance::tok::__UNSET__)
    {
        leaf_type_ptr type_ptr;
        leaf_type_reference type_reference;
        auto contents = m_cu->get(node->t);

        if (node->t.type == leaf::parsing::instance::tok::SCALAR)
        {
            if (!try_resolve_type_name("leaf::ui64", type_reference, type_ptr))
            {
                // ToDo: Report error
                return false;
            }
            auto result = from_scalar_string(contents);
            leaf_emit_push(BLOB, result);
        }
        else if (node->t.type == leaf::parsing::instance::tok::TRUE_)
        {
            if (!try_resolve_type_name("leaf::bool", type_reference, type_ptr))
            {
                // ToDo: Report error
                return false;
            }
            helper.current_scope().push_value(type_reference, type_ptr);
            leaf_emit_push(BLOB);
        }
        else if (node->t.type == leaf::parsing::instance::tok::FALSE_)
        {
            if (!try_resolve_type_name("leaf::bool", type_reference, type_ptr))
            {
                // ToDo: Report error
                return false;
            }
            helper.current_scope().push_value(type_reference, type_ptr);
            leaf_emit_push(BLOB);
        }
        else if (node->t.type == leaf::parsing::instance::tok::INTEGER)
        {
            if (!try_resolve_type_name("leaf::ui64", type_reference, type_ptr))
            {
                // ToDo: Report error
                return false;
            }
            auto result = from_integer_string(contents);
            helper.current_scope().push_value(type_reference, type_ptr);
            leaf_emit_push(BLOB, result);
        }
        else if (node->t.type == leaf::parsing::instance::tok::INTEGER_BINARY)
        {
            if (!try_resolve_type_name("leaf::ui64", type_reference, type_ptr))
            {
                // ToDo: Report error
                return false;
            }
            auto result = from_binary_string(contents);
            helper.current_scope().push_value(type_reference, type_ptr);
            leaf_emit_push(BLOB, result);
        }
        else if (node->t.type == leaf::parsing::instance::tok::INTEGER_HEX)
        {
            if (!try_resolve_type_name("leaf::ui64", type_reference, type_ptr))
            {
                // ToDo: Report error
                return false;
            }
            auto result = from_hex_string(contents);
            helper.current_scope().push_value(type_reference, type_ptr);
            leaf_emit_push(BLOB, result);
        }
        else if (node->t.type == leaf::parsing::instance::tok::STRING)
        {
            auto result = from_hex_string(contents);
            // ToDo: Push correct value to value-stack
        }
        else if (node->t.type == leaf::parsing::instance::tok::CHAR_)
        {
            auto result = from_hex_string(contents);
            // ToDo: Push correct value to value-stack
        }
        else
        {
            throw std::runtime_error("Not all paths are handled.");
        }
    }
    else
    {
        throw std::runtime_error("Not all paths are handled.");
    }
    return true;
}

bool leaf::compilation::stages::emit_bytecode::emit_exp(
        const std::shared_ptr<leaf::parsing::instance::typeof_> &node) {
    return false;
}
bool leaf::compilation::stages::emit_bytecode::emit_exp(
        const std::shared_ptr<leaf::parsing::instance::nameof> &node) {
    return false;
}


#pragma region Other Methods

leaf_method_info_ptr leaf::compilation::stages::emit_bytecode::find_matching_method(
        const std::vector<std::tuple<leaf_type_reference, leaf_type_ptr>>& params,
        const std::vector<leaf_method_info_ptr>& candidates)
{

    // Method Count Check
    std::vector<leaf_method_info_ptr> candidates_correct_count;
    {
        for (auto ptr : candidates)
        {
            if (ptr->parameters.size == params.size())
            {
                candidates_correct_count.push_back(ptr);
            }
        }
        if (candidates_correct_count.size() == 0)
        {
            // ToDo: Report error - Too many args
            return nullptr;
        }
    }

    // Try to find perfect match
    leaf_method_info_ptr candidate_perfect_match = nullptr;
    {
        for (auto ptr : candidates_correct_count)
        {
            size_t arg_index = 0;
            for (auto [type_reference, type_ptr] : params)
            {
                auto parameter = ptr->parameters.data[arg_index++];
                if (parameter.ast_type_reference != type_reference)
                {
                    break;
                }
            }
            if (arg_index == ptr->parameters.size)
            {
                if (!candidate_perfect_match)
                {
                    candidate_perfect_match = ptr;
                }
                else
                {
                    // ToDo: Report multiple possible methods match error
                    return nullptr;
                }
            }
        }
    }

    if (!candidate_perfect_match)
    {
        // ToDo: Implement a nice way to find implicit conversion opportunities
        // ToDo: Report error that implicit conversion is not yet supported
        return nullptr;
    }

    return candidate_perfect_match;
}

#pragma endregion

#pragma region DONE

bool leaf::compilation::stages::emit_bytecode::emit_exp(
        const std::shared_ptr<leaf::parsing::instance::statement> &node) {
    if (node->pragma) {
        if (!emit_exp(node->pragma)) { return false; }
    } else if (node->fwrd_decl) {
        /* Declare Variable */
        {
            auto name = m_cu->get(node->fwrd_decl->name);
            if (helper.current_scope().contains_variable(name)) {
                // ToDo: Write out warning about hiding prior variable declaration.
            }
            leaf_type_reference type_reference;
            leaf_type_ptr type_ptr;
            if (!this->fill_type_reference(type_reference, node->fwrd_decl->type)) { return false; }
            if (!this->get_type_from_reference_index(type_reference.index, type_ptr)) { return false; }
            if (leaf_emit_i_stack_reserve(
                    BLOB,
                    helper.current_scope().push_variable(
                            name,
                            type_reference,
                            type_ptr).size))
            {
                throw std::bad_alloc();
            }
        }

        /* Define Variable ? */
        if (node->exp) {
            if (!emit_exp(node->exp)) { return false; }
            // Clone the resulting value to target and pop the original afterwards.
            helper.current_scope().clone(0, 1);
            helper.current_scope().pop_destroy();
        }

        return false;
    } else if (node->ret) {
        if (!emit_exp(node->ret)) { return false; }
        helper.current_scope().destroy_all(1);
        return false;
    } else if (node->exp) {
        if (!emit_exp(node->exp)) { return false; }
        helper.current_scope().pop_destroy();
    } else {
        throw std::runtime_error("Not all variant paths are handled.");
    }
    return true;
}

bool leaf::compilation::stages::emit_bytecode::emit_exp(
        const std::shared_ptr<leaf::parsing::instance::pragma> &node) {
    for (auto &data : node->contents) {
        if (std::holds_alternative<std::shared_ptr<leaf::parsing::instance::pragma_disable>>(data)) {
            auto pragma_disable = std::get<std::shared_ptr<leaf::parsing::instance::pragma_disable>>(data);
            m_cu->disable(m_cu->get(pragma_disable->code));
        } else if (std::holds_alternative<std::shared_ptr<leaf::parsing::instance::pragma_enable>>(data)) {
            auto pragma_enable = std::get<std::shared_ptr<leaf::parsing::instance::pragma_enable>>(data);
            m_cu->enable(m_cu->get(pragma_enable->code));
        } else if (std::holds_alternative<std::shared_ptr<leaf::parsing::instance::pragma_size>>(data)) {
            /* EMPTY */
        } else if (std::holds_alternative<std::shared_ptr<leaf::parsing::instance::pragma_align>>(data)) {
            /* EMPTY */
        } else {
            throw std::runtime_error("Not all variant paths are handled.");
        }
    }
    return true;
}
bool leaf::compilation::stages::emit_bytecode::emit_exp(
        const std::shared_ptr<leaf::parsing::instance::exp_or> &node) {
    if (std::holds_alternative<std::shared_ptr<leaf::parsing::instance::exp_or>>(node->left)) {
        auto &exp_or = std::get<std::shared_ptr<leaf::parsing::instance::exp_or>>(node->left);
        if (!emit_exp(exp_or)) { return false; }
    } else if (std::holds_alternative<std::shared_ptr<leaf::parsing::instance::exp_and>>(node->left)) {
        auto &exp_and = std::get<std::shared_ptr<leaf::parsing::instance::exp_and>>(node->left);
        if (!emit_exp(exp_and)) { return false; }
    } else {
        throw std::runtime_error("Not all variant paths are handled.");
    }
    if (node->right) {
        if (!emit_exp(node->right)) { return false; }
        switch (node->operator_.type) {
            case leaf::parsing::instance::tok::_VERTICAL_BAR_VERTICAL_BAR:
                if (!helper.emit_operator(*m_cu, YSMIT_OPBINARY_LOGICAL_OR)) { return false; }
                break;
            default:
                throw std::runtime_error("Not all paths are handled.");
        }
    }
    return true;
}

bool leaf::compilation::stages::emit_bytecode::emit_exp(
        const std::shared_ptr<leaf::parsing::instance::exp_and> &node) {
    if (std::holds_alternative<std::shared_ptr<leaf::parsing::instance::exp_and>>(node->left)) {
        auto &exp_and = std::get<std::shared_ptr<leaf::parsing::instance::exp_and>>(node->left);
        if (!emit_exp(exp_and)) { return false; }
    } else if (std::holds_alternative<std::shared_ptr<leaf::parsing::instance::exp_equality>>(node->left)) {
        auto &exp_equality = std::get<std::shared_ptr<leaf::parsing::instance::exp_equality>>(node->left);
        if (!emit_exp(exp_equality)) { return false; }
    } else {
        throw std::runtime_error("Not all variant paths are handled.");
    }
    if (node->right) {
        if (!emit_exp(node->right)) { return false; }
        switch (node->operator_.type) {
            case leaf::parsing::instance::tok::_AMPERSAND_AMPERSAND:
                if (!helper.emit_operator(*m_cu, YSMIT_OPBINARY_LOGICAL_AND)) { return false; }
                break;
            default:
                throw std::runtime_error("Not all paths are handled.");
        }
    }
    return true;
}

bool leaf::compilation::stages::emit_bytecode::emit_exp(
        const std::shared_ptr<leaf::parsing::instance::exp_equality> &node) {
    if (std::holds_alternative<std::shared_ptr<leaf::parsing::instance::exp_equality>>(node->left)) {
        auto &exp_equality = std::get<std::shared_ptr<leaf::parsing::instance::exp_equality>>(node->left);
        if (!emit_exp(exp_equality)) { return false; }
    } else if (std::holds_alternative<std::shared_ptr<leaf::parsing::instance::exp_compare>>(node->left)) {
        auto &exp_compare = std::get<std::shared_ptr<leaf::parsing::instance::exp_compare>>(node->left);
        if (!emit_exp(exp_compare)) { return false; }
    } else {
        throw std::runtime_error("Not all variant paths are handled.");
    }
    if (node->right) {
        if (!emit_exp(node->right)) { return false; }
        switch (node->operator_.type) {
            case leaf::parsing::instance::tok::_TILDE_EQUAL:
                if (!helper.emit_operator(*m_cu, YSMIT_OPBINARY_APPROXIMATION_EQUAL)) { return false; }
                break;
            case leaf::parsing::instance::tok::_EQUAL_EQUAL:
                if (!helper.emit_operator(*m_cu, YSMIT_OPBINARY_EQUAL)) { return false; }
                break;
            case leaf::parsing::instance::tok::_EQUAL_EQUAL_EQUAL:
                if (!helper.emit_operator(*m_cu, YSMIT_OPBINARY_SAME)) { return false; }
                break;
            case leaf::parsing::instance::tok::_EXCLAMATION_EQUAL:
                if (!helper.emit_operator(*m_cu,
                        YSMIT_OPBINARY_NOT_EQUAL)) { return false; }
                break;
            default:
                throw std::runtime_error("Not all paths are handled.");
        }
    }
    return true;
}

bool leaf::compilation::stages::emit_bytecode::emit_exp(
        const std::shared_ptr<leaf::parsing::instance::exp_compare> &node) {
    if (std::holds_alternative<std::shared_ptr<leaf::parsing::instance::exp_compare>>(node->left)) {
        auto &exp_compare = std::get<std::shared_ptr<leaf::parsing::instance::exp_compare>>(node->left);
        if (!emit_exp(exp_compare)) { return false; }
    } else if (std::holds_alternative<std::shared_ptr<leaf::parsing::instance::exp_arithmetic_1>>(node->left)) {
        auto &exp_arithmetic_1 = std::get<std::shared_ptr<leaf::parsing::instance::exp_arithmetic_1>>(node->left);
        if (!emit_exp(exp_arithmetic_1)) { return false; }
    } else {
        throw std::runtime_error("Not all variant paths are handled.");
    }
    if (node->right) {
        if (!emit_exp(node->right)) { return false; }
        switch (node->operator_.type) {
            case leaf::parsing::instance::tok::_LESS_THEN:
                if (!helper.emit_operator(*m_cu, YSMIT_OPBINARY_LESS_THEN)) { return false; }
                break;
            case leaf::parsing::instance::tok::_LESS_THEN_EQUAL:
                if (!helper.emit_operator(*m_cu,
                        YSMIT_OPBINARY_LESS_THEN_OR_EQUAL)) { return false; }
                break;
            case leaf::parsing::instance::tok::_GREATER_THEN:
                if (!helper.emit_operator(*m_cu, YSMIT_OPBINARY_GREATER_THEN)) { return false; }
                break;
            case leaf::parsing::instance::tok::_GREATER_THEN_EQUAL:
                if (!helper.emit_operator(*m_cu,
                        YSMIT_OPBINARY_GREATER_THEN_OR_EQUAL)) { return false; }
                break;
            default:
                throw std::runtime_error("Not all paths are handled.");
        }
    }
    return true;
}

bool leaf::compilation::stages::emit_bytecode::emit_exp(
        const std::shared_ptr<leaf::parsing::instance::exp_arithmetic_1> &node) {
    if (std::holds_alternative<std::shared_ptr<leaf::parsing::instance::exp_arithmetic_1>>(node->left)) {
        auto &exp_arithmetic_1 = std::get<std::shared_ptr<leaf::parsing::instance::exp_arithmetic_1>>(node->left);
        if (!emit_exp(exp_arithmetic_1)) { return false; }
    } else if (std::holds_alternative<std::shared_ptr<leaf::parsing::instance::exp_arithmetic_2>>(node->left)) {
        auto &exp_arithmetic_2 = std::get<std::shared_ptr<leaf::parsing::instance::exp_arithmetic_2>>(node->left);
        if (!emit_exp(exp_arithmetic_2)) { return false; }
    } else {
        throw std::runtime_error("Not all variant paths are handled.");
    }
    if (node->right) {
        if (!emit_exp(node->right)) { return false; }
        switch (node->operator_.type) {
            case leaf::parsing::instance::tok::PLUS:
                if (!helper.emit_operator(*m_cu, YSMIT_OPBINARY_ADD)) { return false; }
                break;
            case leaf::parsing::instance::tok::MINUS:
                if (!helper.emit_operator(*m_cu, YSMIT_OPBINARY_SUBTRACT)) { return false; }
                break;
            default:
                throw std::runtime_error("Not all paths are handled.");
        }
    }
    return true;
}

bool leaf::compilation::stages::emit_bytecode::emit_exp(
        const std::shared_ptr<leaf::parsing::instance::exp_arithmetic_2> &node) {
    if (std::holds_alternative<std::shared_ptr<leaf::parsing::instance::exp_arithmetic_2>>(node->left)) {
        auto &exp_arithmetic_2 = std::get<std::shared_ptr<leaf::parsing::instance::exp_arithmetic_2>>(node->left);
        if (!emit_exp(exp_arithmetic_2)) { return false; }
    } else if (std::holds_alternative<std::shared_ptr<leaf::parsing::instance::exp_binary_1>>(node->left)) {
        auto &exp_binary_1 = std::get<std::shared_ptr<leaf::parsing::instance::exp_binary_1>>(node->left);
        if (!emit_exp(exp_binary_1)) { return false; }
    } else {
        throw std::runtime_error("Not all variant paths are handled.");
    }
    if (node->right) {
        if (!emit_exp(node->right)) { return false; }
        switch (node->operator_.type) {
            case leaf::parsing::instance::tok::SLASH:
                if (!helper.emit_operator(*m_cu, YSMIT_OPBINARY_DIVIDE)) { return false; }
                break;
            case leaf::parsing::instance::tok::STAR:
                if (!helper.emit_operator(*m_cu, YSMIT_OPBINARY_MULTIPLY)) { return false; }
                break;
            default:
                throw std::runtime_error("Not all paths are handled.");
        }
    }
    return true;
}

bool leaf::compilation::stages::emit_bytecode::emit_exp(
        const std::shared_ptr<leaf::parsing::instance::exp_binary_1> &node) {
    if (std::holds_alternative<std::shared_ptr<leaf::parsing::instance::exp_binary_1>>(node->left)) {
        auto &exp_binary_1 = std::get<std::shared_ptr<leaf::parsing::instance::exp_binary_1>>(node->left);
        if (!emit_exp(exp_binary_1)) { return false; }
    } else if (std::holds_alternative<std::shared_ptr<leaf::parsing::instance::exp_binary_2>>(node->left)) {
        auto &exp_binary_2 = std::get<std::shared_ptr<leaf::parsing::instance::exp_binary_2>>(node->left);
        if (!emit_exp(exp_binary_2)) { return false; }
    } else {
        throw std::runtime_error("Not all variant paths are handled.");
    }
    if (node->right) {
        if (!emit_exp(node->right)) { return false; }
        switch (node->operator_.type) {
            case leaf::parsing::instance::tok::_VERTICAL_BAR:
                if (!helper.emit_operator(*m_cu, YSMIT_OPBINARY_BITWISE_OR)) { return false; }
                break;
            default:
                throw std::runtime_error("Not all paths are handled.");
        }
    }
    return true;
}

bool leaf::compilation::stages::emit_bytecode::emit_exp(
        const std::shared_ptr<leaf::parsing::instance::exp_binary_2> &node) {
    if (std::holds_alternative<std::shared_ptr<leaf::parsing::instance::exp_binary_2>>(node->left)) {
        auto &exp_binary_2 = std::get<std::shared_ptr<leaf::parsing::instance::exp_binary_2>>(node->left);
        if (!emit_exp(exp_binary_2)) { return false; }
    } else if (std::holds_alternative<std::shared_ptr<leaf::parsing::instance::exp_binary_3>>(node->left)) {
        auto &exp_binary_3 = std::get<std::shared_ptr<leaf::parsing::instance::exp_binary_3>>(node->left);
        if (!emit_exp(exp_binary_3)) { return false; }
    } else {
        throw std::runtime_error("Not all variant paths are handled.");
    }
    if (node->right) {
        if (!emit_exp(node->right)) { return false; }
        switch (node->operator_.type) {
            case leaf::parsing::instance::tok::_CIRCUMFLEX:
                if (!helper.emit_operator(*m_cu, YSMIT_OPBINARY_BITWISE_XOR)) { return false; }
                break;
            default:
                throw std::runtime_error("Not all paths are handled.");
        }
    }
    return true;
}
bool leaf::compilation::stages::emit_bytecode::emit_exp(
        const std::shared_ptr<leaf::parsing::instance::exp_binary_3> &node) {
    if (std::holds_alternative<std::shared_ptr<leaf::parsing::instance::exp_binary_3>>(node->left)) {
        auto &exp_binary_3 = std::get<std::shared_ptr<leaf::parsing::instance::exp_binary_3>>(node->left);
        if (!emit_exp(exp_binary_3)) { return false; }
    } else if (std::holds_alternative<std::shared_ptr<leaf::parsing::instance::exp_binary_4>>(node->left)) {
        auto &exp_binary_4 = std::get<std::shared_ptr<leaf::parsing::instance::exp_binary_4>>(node->left);
        if (!emit_exp(exp_binary_4)) { return false; }
    } else {
        throw std::runtime_error("Not all variant paths are handled.");
    }
    if (node->right) {
        if (!emit_exp(node->right)) { return false; }
        switch (node->operator_.type) {
            case leaf::parsing::instance::tok::_AMPERSAND:
                if (!helper.emit_operator(*m_cu, YSMIT_OPBINARY_BITWISE_AND)) { return false; }
                break;
            default:
                throw std::runtime_error("Not all paths are handled.");
        }
    }
    return true;
}

bool leaf::compilation::stages::emit_bytecode::emit_exp(
        const std::shared_ptr<leaf::parsing::instance::exp_binary_4> &node) {
    if (std::holds_alternative<std::shared_ptr<leaf::parsing::instance::exp_binary_4>>(node->left)) {
        auto &exp_binary_4 = std::get<std::shared_ptr<leaf::parsing::instance::exp_binary_4>>(node->left);
        if (!emit_exp(exp_binary_4)) { return false; }
    } else if (std::holds_alternative<std::shared_ptr<leaf::parsing::instance::exp_unary>>(node->left)) {
        auto &exp_unary = std::get<std::shared_ptr<leaf::parsing::instance::exp_unary>>(node->left);
        if (!emit_exp(exp_unary)) { return false; }
    } else {
        throw std::runtime_error("Not all variant paths are handled.");
    }
    if (node->right) {
        if (!emit_exp(node->right)) { return false; }
        switch (node->operator_.type) {
            case leaf::parsing::instance::tok::_LESS_THEN_LESS_THEN:
                if (!helper.emit_operator(
                        *m_cu,
                        YSMIT_OPBINARY_DOUBLE_SHIFT_LEFT)) { return false; }
                break;
            case leaf::parsing::instance::tok::_LESS_THEN_LESS_THEN_LESS_THEN:
                if (!helper.emit_operator(
                        *m_cu,
                        YSMIT_OPBINARY_TRIPPLE_SHIFT_LEFT)) { return false; }
                break;
            case leaf::parsing::instance::tok::_GREATER_THEN_GREATER_THEN:
                if (!helper.emit_operator(
                        *m_cu,
                        YSMIT_OPBINARY_DOUBLE_SHIFT_RIGHT)) { return false; }
                break;
            case leaf::parsing::instance::tok::_GREATER_THEN_GREATER_THEN_GREATER_THEN:
                if (!helper.emit_operator(
                        *m_cu,
                        YSMIT_OPBINARY_TRIPPLE_SHIFT_RIGHT)) { return false; }
                break;
            default:
                throw std::runtime_error("Not all paths are handled.");
        }
    }
    return true;
}

bool leaf::compilation::stages::emit_bytecode::emit_exp(
        const std::shared_ptr<leaf::parsing::instance::exp_unary> &node) {
    // Always emit value first
    if (std::holds_alternative<std::shared_ptr<leaf::parsing::instance::exp_unary>>(node->value)) {
        auto &exp_unary = std::get<std::shared_ptr<leaf::parsing::instance::exp_unary>>(node->value);
        if (!emit_exp(exp_unary)) { return false; }
    } else if (std::holds_alternative<std::shared_ptr<leaf::parsing::instance::exp_nullar>>(node->value)) {
        auto &exp_nullar = std::get<std::shared_ptr<leaf::parsing::instance::exp_nullar>>(node->value);
        if (!emit_exp(exp_nullar)) { return false; }
    } else {
        throw std::runtime_error("Not all variant paths are handled.");
    }

    if (node->cast_target) {
        leaf_type_reference type_reference;
        leaf_type_ptr type_ptr;
        if (!this->fill_type_reference(type_reference, node->cast_target)) { return false; }
        if (!this->get_type_from_reference_index(type_reference.index, type_ptr)) { return false; }

        if (!helper.emit_cast(*m_cu, type_reference, type_ptr)) { return false; }
    } else if (node->operator_.type == leaf::parsing::instance::tok::_EXCLAMATION) {
        if (!helper.emit_operator(*m_cu, YSMIT_OPUNARY_LOGICAL_NOT)) { return false; }
    } else if (node->operator_.type == leaf::parsing::instance::tok::_TILDE) {
        if (!helper.emit_operator(*m_cu, YSMIT_OPUNARY_BITWISE_NOT)) { return false; }
    } else if (node->operator_.type == leaf::parsing::instance::tok::MINUS) {
        if (!helper.emit_operator(*m_cu, YSMIT_OPUNARY_MINUS)) { return false; }
    } else if (node->operator_.type == leaf::parsing::instance::tok::PLUS) {
        if (!helper.emit_operator(*m_cu, YSMIT_OPUNARY_PLUS)) { return false; }
    } else if (node->operator_.type == leaf::parsing::instance::tok::__UNSET__) {
        return false;
    } else {
        throw std::runtime_error("Not all variant paths are handled.");
    }
    return true;
}

bool leaf::compilation::stages::emit_bytecode::emit_exp(
        const std::shared_ptr<leaf::parsing::instance::exp_nullar> &node) {
    if (std::holds_alternative<std::shared_ptr<leaf::parsing::instance::expression>>(node->value)) {
        auto &expression = std::get<std::shared_ptr<leaf::parsing::instance::expression>>(node->value);
        if (!emit_exp(expression)) { return false; }
    } else if (std::holds_alternative<std::shared_ptr<leaf::parsing::instance::exp_chain>>(node->value)) {
        auto &exp_chain = std::get<std::shared_ptr<leaf::parsing::instance::exp_chain>>(node->value);
        if (!emit_exp(exp_chain)) { return false; }
    } else if (std::holds_alternative<std::shared_ptr<leaf::parsing::instance::exp_value>>(node->value)) {
        auto &exp_value = std::get<std::shared_ptr<leaf::parsing::instance::exp_value>>(node->value);
        if (!emit_exp(exp_value)) { return false; }
    } else {
        throw std::runtime_error("Not all variant paths are handled.");
    }
    return true;
}

bool leaf::compilation::stages::emit_bytecode::emit_exp(
        const std::shared_ptr<leaf::parsing::instance::exp_value> &node) {
    if (node->constant) {
        if (!emit_exp(node->constant)) { return false; }
    } else if (node->scalar) {
        if (!emit_exp(node->scalar)) { return false; }
    } else if (node->integer_hex) {
        if (!emit_exp(node->integer_hex)) { return false; }
    } else if (node->integer_binary) {
        if (!emit_exp(node->integer_binary)) { return false; }
    } else if (node->integer) {
        if (!emit_exp(node->integer)) { return false; }
    } else if (node->character) {
        if (!emit_exp(node->character)) { return false; }
    } else if (node->string) {
        if (!emit_exp(node->string)) { return false; }
    } else {
        throw std::runtime_error("Not all variant paths are handled.");
    }
    return true;
}

bool leaf::compilation::stages::emit_bytecode::emit_exp(
        const std::shared_ptr<leaf::parsing::instance::declaration> &node) {

    auto name = m_cu->get(node->name);
    leaf_type_reference type_reference;
    if (!fill_type_reference(type_reference, node->type))
    {
        // ToDo: Report error about type not found
    }
    leaf_type_ptr type_ptr;
    if (!get_type_from_reference_index(type_reference.index, type_ptr))
    {
        // ToDo: Report error
    }

    helper.current_scope().push_variable(name, type_reference, type_ptr);
    return false;
}

bool leaf::compilation::stages::emit_bytecode::emit_exp(
        const std::shared_ptr<leaf::parsing::instance::alloc> &node) {

    leaf_type_ptr type_ptr;
    leaf_type_reference type_reference;
    if (!try_resolve_type_name(node->type, type_reference, type_ptr))
    {
        // ToDo: Report error
        return false;
    }
    if (node->exp)
    {
        type_reference.flags |= YSF_ARRAY;

        if (!emit_exp(node->exp)) { return false; }
        // Create instance in memory
        {
            auto tuple = helper.current_scope().values_back();
            if (node->is_heap)
            {
                if (tuple.has_constant)
                {
                    // ToDo: Do something against value-stack pollution due to direct constant usage
                    if (tuple.type_ptr == "leaf::ui8"sv)  { leaf_emit_i_heap_alloc(BLOB, tuple.type_ptr->instance_size * tuple.as.ui8); }
                    else if (tuple.type_ptr == "leaf::ui16"sv) { leaf_emit_i_heap_alloc(BLOB, tuple.type_ptr->instance_size * tuple.as.ui16); }
                    else if (tuple.type_ptr == "leaf::ui32"sv) { leaf_emit_i_heap_alloc(BLOB, tuple.type_ptr->instance_size * tuple.as.ui32); }
                    else if (tuple.type_ptr == "leaf::ui64"sv) { leaf_emit_i_heap_alloc(BLOB, tuple.type_ptr->instance_size * tuple.as.ui64); }
                    else if (tuple.type_ptr == "leaf::i8"sv)   { leaf_emit_i_heap_alloc(BLOB, tuple.type_ptr->instance_size * tuple.as.i8); }
                    else if (tuple.type_ptr == "leaf::i16"sv)  { leaf_emit_i_heap_alloc(BLOB, tuple.type_ptr->instance_size * tuple.as.i16); }
                    else if (tuple.type_ptr == "leaf::i32"sv)  { leaf_emit_i_heap_alloc(BLOB, tuple.type_ptr->instance_size * tuple.as.i32); }
                    else if (tuple.type_ptr == "leaf::i64"sv)  { leaf_emit_i_heap_alloc(BLOB, tuple.type_ptr->instance_size * tuple.as.i64); }
                    else
                    {
                        // ToDo: Implement a nice way to find implicit conversion opportunities
                        // ToDo: Report error that implicit conversion is not yet supported
                        return false;
                    }
                }
                else
                {
                    if (tuple.type_ptr == "leaf::ui8"sv)  { leaf_emit_i_m1_heap_alloc_d(BLOB, tuple.type_ptr->instance_size, YSOPC_M1_UI8); }
                    else if (tuple.type_ptr == "leaf::ui16"sv) { leaf_emit_i_m1_heap_alloc_d(BLOB, tuple.type_ptr->instance_size, YSOPC_M1_UI16); }
                    else if (tuple.type_ptr == "leaf::ui32"sv) { leaf_emit_i_m1_heap_alloc_d(BLOB, tuple.type_ptr->instance_size, YSOPC_M1_UI32); }
                    else if (tuple.type_ptr == "leaf::ui64"sv) { leaf_emit_i_m1_heap_alloc_d(BLOB, tuple.type_ptr->instance_size, YSOPC_M1_UI16); }
                    else if (tuple.type_ptr == "leaf::i8"sv)   { leaf_emit_i_m1_heap_alloc_d(BLOB, tuple.type_ptr->instance_size, YSOPC_M1_I8); }
                    else if (tuple.type_ptr == "leaf::i16"sv)  { leaf_emit_i_m1_heap_alloc_d(BLOB, tuple.type_ptr->instance_size, YSOPC_M1_I16); }
                    else if (tuple.type_ptr == "leaf::i32"sv)  { leaf_emit_i_m1_heap_alloc_d(BLOB, tuple.type_ptr->instance_size, YSOPC_M1_I32); }
                    else if (tuple.type_ptr == "leaf::i64"sv)  { leaf_emit_i_m1_heap_alloc_d(BLOB, tuple.type_ptr->instance_size, YSOPC_M1_I64); }
                    else
                    {
                        // ToDo: Implement a nice way to find implicit conversion opportunities
                        // ToDo: Report error that implicit conversion is not yet supported
                        return false;
                    }
                }
                type_reference.flags |= YSF_POINTER;
                helper.current_scope().push_value(type_reference, type_ptr);
            }
            else if (node->is_stack)
            {
                if (tuple.has_constant)
                {
                    // ToDo: Do something against value-stack pollution due to direct constant usage
                    if (tuple.type_ptr == "leaf::ui8"sv)  { leaf_emit_i_stack_reserve(BLOB, tuple.type_ptr->instance_size * tuple.as.ui8); }
                    else if (tuple.type_ptr == "leaf::ui16"sv) { leaf_emit_i_stack_reserve(BLOB, tuple.type_ptr->instance_size * tuple.as.ui16); }
                    else if (tuple.type_ptr == "leaf::ui32"sv) { leaf_emit_i_stack_reserve(BLOB, tuple.type_ptr->instance_size * tuple.as.ui32); }
                    else if (tuple.type_ptr == "leaf::ui64"sv) { leaf_emit_i_stack_reserve(BLOB, tuple.type_ptr->instance_size * tuple.as.ui64); }
                    else if (tuple.type_ptr == "leaf::i8"sv)   { leaf_emit_i_stack_reserve(BLOB, tuple.type_ptr->instance_size * tuple.as.i8); }
                    else if (tuple.type_ptr == "leaf::i16"sv)  { leaf_emit_i_stack_reserve(BLOB, tuple.type_ptr->instance_size * tuple.as.i16); }
                    else if (tuple.type_ptr == "leaf::i32"sv)  { leaf_emit_i_stack_reserve(BLOB, tuple.type_ptr->instance_size * tuple.as.i32); }
                    else if (tuple.type_ptr == "leaf::i64"sv)  { leaf_emit_i_stack_reserve(BLOB, tuple.type_ptr->instance_size * tuple.as.i64); }
                    else
                    {
                        // ToDo: Implement a nice way to find implicit conversion opportunities
                        // ToDo: Report error that implicit conversion is not yet supported
                        return false;
                    }
                }
                else
                {
                    if (tuple.type_ptr == "leaf::ui8"sv)  { leaf_emit_i_m1_stack_reserve_d(BLOB, tuple.type_ptr->instance_size, YSOPC_M1_UI8); }
                    else if (tuple.type_ptr == "leaf::ui16"sv) { leaf_emit_i_m1_stack_reserve_d(BLOB, tuple.type_ptr->instance_size, YSOPC_M1_UI16); }
                    else if (tuple.type_ptr == "leaf::ui32"sv) { leaf_emit_i_m1_stack_reserve_d(BLOB, tuple.type_ptr->instance_size, YSOPC_M1_UI32); }
                    else if (tuple.type_ptr == "leaf::ui64"sv) { leaf_emit_i_m1_stack_reserve_d(BLOB, tuple.type_ptr->instance_size, YSOPC_M1_UI16); }
                    else if (tuple.type_ptr == "leaf::i8"sv)   { leaf_emit_i_m1_stack_reserve_d(BLOB, tuple.type_ptr->instance_size, YSOPC_M1_I8); }
                    else if (tuple.type_ptr == "leaf::i16"sv)  { leaf_emit_i_m1_stack_reserve_d(BLOB, tuple.type_ptr->instance_size, YSOPC_M1_I16); }
                    else if (tuple.type_ptr == "leaf::i32"sv)  { leaf_emit_i_m1_stack_reserve_d(BLOB, tuple.type_ptr->instance_size, YSOPC_M1_I32); }
                    else if (tuple.type_ptr == "leaf::i64"sv)  { leaf_emit_i_m1_stack_reserve_d(BLOB, tuple.type_ptr->instance_size, YSOPC_M1_I64); }
                    else
                    {
                        // ToDo: Implement a nice way to find implicit conversion opportunities
                        // ToDo: Report error that implicit conversion is not yet supported
                        return false;
                    }
                }
                helper.current_scope().push_value(type_reference, type_ptr);
            }
            else { throw std::runtime_error("Not all paths are handled."); }
        }

    }
    else if (node->body)
    {
        // Create instance in memory
        {
            if (node->is_heap)
            {
                leaf_emit_i_heap_alloc(BLOB, type_ptr->instance_size);
                type_reference.flags |= YSF_POINTER;
                helper.current_scope().push_value(type_reference, type_ptr);
            }
            else if (node->is_stack)
            {
                leaf_emit_i_stack_reserve(BLOB, type_ptr->instance_size);
                helper.current_scope().push_value(type_reference, type_ptr);
            }
            else { throw std::runtime_error("Not all paths are handled."); }
        }

        // Emit args and get method parameter types, resetting value_stack_index afterwards
        std::vector<std::tuple<leaf_type_reference, leaf_type_ptr>> params;
        {
            size_t value_stack_index = helper.current_scope().values_size();
            if (!emit_exp(node->body, params)) { return false; }

            // Safe because the called is responsible for cleanup
            helper.current_scope().pop_to(value_stack_index);
        }

        // Find matching constructor
        leaf_method_info_ptr matching_constructor;
        {
            std::vector<leaf_method_info_ptr> constructors;
            for (leaf_method_info_ptr method_info_ptr = type_ptr->methods.data;
                 method_info_ptr != type_ptr->methods.size + type_ptr->methods.data;
                 ++method_info_ptr)
            {
                if (method_info_ptr->type == YSMIT_CONSTRUCTOR)
                {
                    constructors.push_back(method_info_ptr);
                }
            }
            matching_constructor = find_matching_method(params, constructors);
            if (!matching_constructor)
            {
                return false;
            }
        }

        // Call the constructor found
        leaf_emit_static_call(helper.current_type(), matching_constructor);
    }
    else { throw std::runtime_error("Not all paths are handled."); }
    return false;
}
bool leaf::compilation::stages::emit_bytecode::emit_exp(
        const std::shared_ptr<leaf::parsing::instance::scope> &node) {
    // push additional scope to resolution stack
    auto& current_scope = helper.current_scope();
    helper.push_scope();

    // Emit opcodes
    for (auto &body_part : node->body) {
        if (std::holds_alternative<std::shared_ptr<leaf::parsing::instance::control_structure>>(body_part)) {
            auto &control_structure = std::get<std::shared_ptr<leaf::parsing::instance::control_structure>>(
                    body_part);
        } else if (std::holds_alternative<std::shared_ptr<leaf::parsing::instance::statement>>(body_part)) {
            auto &statement = std::get<std::shared_ptr<leaf::parsing::instance::statement>>(body_part);
            if (!emit_exp(statement)) { return false; }
        } else {
            throw std::runtime_error("Not all variant paths are handled.");
        }
    }

    // Cleanup Scope
    if (helper.current_scope().values_back().is_return_value)
    {
        helper.current_scope().destroy_all(1);
        current_scope.push_value(helper.current_scope().values_back().type_reference, helper.current_scope().values_back().type_ptr);
    }
    else
    {
        helper.current_scope().destroy_all();
    }
    return true;
}


#pragma endregion