#pragma once
#include <map>
#include <vector>
#include <tuple>
#include <shared_mutex>
#include <algorithm>
#include <array>
#include "../runtime/leaf_type.h"
#include "conversion_solver.hpp"
namespace leaf::compilation
{
    class method_call_solver
    {
    public:
        enum class solver_result
        {
            ok,
            no_match,
            more_than_one_match,
        };
    private:
        conversion_solver& m_conv_solver;
    public:
        explicit method_call_solver(conversion_solver& conv_solver) : m_conv_solver(conv_solver)
        {

        }

        template<size_t size, typename TIterator>
        solver_result try_solve_for(
                leaf_type_ptr type_ptr,
                leaf_method_info_type method_info_type,
                std::string_view method_name,
                std::array<type_info_ptr, size> args,
                leaf_method_info_ptr& out_method_info_ptr)
        {
            static_assert(
                    std::is_same<std::iterator_traits<TIterator>::value_type, method_info_ptr>::value,
                    "Iterator is not resolving to method_info_ptr.");


            out_method_info_ptr = nullptr;
            for (auto it = type_ptr->methods.data; it != type_ptr->methods.data + type_ptr->methods.size; ++it)
            {
                // 0. Filter method type
                if (it->type != method_info_type) { continue; }

                // 1. Find all candidates that match the name
                if (!matches_name(*it, method_name)) { continue; }
                // 2. Find all candidates that match the arg-count
                if (!matches_arg_count(*it, size)) { continue; }
                // 3. Try to find exact match (type-exact)
                // 4. Try to find match using contracts
                if (matches_arg_types(type_ptr, *it, args))
                {
                    if (out_method_info_ptr) { return solver_result::more_than_one_match; }
                    out_method_info_ptr = *it;
                }
                // ToDo: Finish
                // 5. Try to find match using templates
                // --> Needs some way to build a method right here to check whether a method actually can be build or not
                // --> Recursion Check required. No recursion may happen regarding a resolver conflict
                /*
                 * Example 1:
                 *     void method<T>(array<T> arr);
                 *     void method<T>(T t);
                 *     auto var = array<ui8>();
                 *     method(var);
                 * Example 2:
                 *     auto var = array<ui8>();
                 *     void method<T>(array<T> arr);
                 *     method(var);
                 */
                // 6. Try to find match using conversion
            }
        }

    private:
        static bool matches_name(leaf_method_info_ptr method_info_ptr, std::string_view method_name)
        {
            std::string_View actual_name(method_info_ptr->name.data, method_info_ptr->name.length);
            return actual_name == method_name;
        }
        static bool matches_arg_count(leaf_method_info_ptr method_info_ptr, size_t arg_count)
        {
            return method_info_ptr->parameters.size == arg_count;
        }
        template<size_t size>
        static bool matches_arg_types(
                leaf_type_ptr type_ptr,
                leaf_method_info_ptr method_info_ptr,
                std::array<type_info_ptr, size>& args)
        {
            for (size_t i = 0; i < size; ++i)
            {
                auto parameter_info = method_info_ptr->parameters.data[i];
                auto parameter_type = type_ptr->referred_types.data[parameter_info.type_reference.index];
                type_info_ptr argument_type = args[i];

                if (parameter_type->flags == YSF_CLASS
                    && parameter_type != argument_type) { return false; }
                if (parameter_type->flags == YSF_CONTRACT
                    && matches_contract(parameter_type, argument_type)) { return false; }
            }
            return true;
        }

        static bool matches_contract(
                leaf_type_ptr contract_type_ptr,
                leaf_type_ptr target_type_ptr)
        {
            for (size_t i = 0; i < contract_type_ptr->methods.size; ++i)
            {
                auto left = contract_type_ptr->methods.data + i;
                if (!has_matching_signature(contract_type_ptr, left, target_type_ptr)) { return false; }
            }
            for (size_t i = 0; i < contract_type_ptr->fields.size; ++i)
            {
                auto left = contract_type_ptr->fields.data + i;
                if (!has_matching_signature(contract_type_ptr, left, target_type_ptr)) { return false; }
            }
            return true;
        }

        static bool has_matching_signature(
                leaf_type_ptr source_type,
                leaf_method_info_ptr source_method,
                leaf_type_ptr target_type_ptr)
        {
            for (size_t i = 0; i < target_type_ptr->methods.size; ++i)
            {
                const auto& target = target_type_ptr->methods.data[i];
                if (target.type != source_method->type) { continue; }
                if (target.flags != source_method->flags) { continue; }
                if (target.parameters.size != source_method->parameters.size) { continue; }
                if (str(target.name) != str(source_method->name)) { continue; }
                if (target.return_type_reference.flags == source_method->flags)) { continue; }
                if (get_type_ptr(target_type_ptr, target.return_type_reference)
                    != get_type_ptr(source_type, source_method->return_type_reference)) { continue; }
                return true;
            }
            return false;
        }

        static bool has_matching_signature(
                leaf_type_ptr source_type,
                leaf_field_info_ptr source_field,
                leaf_type_ptr target_type_ptr)
        {
            for (size_t i = 0; i < target_type_ptr->fields.size; ++i)
            {
                const auto& target = target_type_ptr->fields.data[i];
                if (target.flags != source_field->flags) { continue; }
                if (str(target.name) != str(source_field->name)) { continue; }
                if (target.return_type_reference.flags == source_field->flags)) { continue; }
                if (get_type_ptr(target_type_ptr, target.data_type_reference)
                    != get_type_ptr(source_type, source_field->data_type_reference)) { continue; }
                return true;
            }
            return false;
        }

        static leaf_type_ptr get_type_ptr(leaf_type_ptr type_ptr, const leaf_type_reference& type_reference)
        {
            return type_ptr->referred_types.data[type_reference.index];
        }
        static std::string_view str(const leaf_string& str)
        {
            return { str.data, str.length };
        }
    };
}