#pragma once
#include "stage_base.hpp"

#include <vector>
#include <algorithm>

namespace leaf::compilation::stages
{
    struct emit_bytecode : public stage_base
    {
        emit_bytecode() { }
    private:


        // Parses any string that conforms to `0b[01_]+` into a uint64_t.
        // No checks will be performed whether a string starts with `0b` or is correct!
        static uint64_t from_binary_string(std::string_view view)
        {
            uint64_t output = 0;
            for (size_t i = 2; i < view.length(); i++)
            {
                char c = view[i];
                switch (c) {
                    case '1':
                        output << 1;
                        output |= 1;
                        break;
                    case '0':
                        output << 1;
                        output |= 0;
                        break;
                    case '_':
                        break;
                }
            }
            return output;
        }
        // Parses any string that conforms to `0x[0-9a-fA-F_]+` into a uint64_t.
        // No checks will be performed whether a string starts with `0x` or is correct!
        static uint64_t from_hex_string(std::string_view view)
        {
            uint64_t output = 0;
            for (size_t i = 2; i < view.length(); i++)
            {
                char c = view[i];
                switch (c) {
                    case '0':
                        output << 4;
                        output |= 0x0;
                        break;
                    case '1':
                        output << 4;
                        output |= 0x1;
                        break;
                    case '2':
                        output << 4;
                        output |= 0x2;
                        break;
                    case '3':
                        output << 4;
                        output |= 0x3;
                        break;
                    case '4':
                        output << 4;
                        output |= 0x4;
                        break;
                    case '5':
                        output << 4;
                        output |= 0x5;
                        break;
                    case '6':
                        output << 4;
                        output |= 0x6;
                        break;
                    case '7':
                        output << 4;
                        output |= 0x7;
                        break;
                    case '8':
                        output << 4;
                        output |= 0x8;
                        break;
                    case '9':
                        output << 4;
                        output |= 0x9;
                        break;
                    case 'a': case 'A':
                        output << 4;
                        output |= 0xA;
                        break;
                    case 'b': case 'B':
                        output << 4;
                        output |= 0xB;
                        break;
                    case 'c': case 'C':
                        output << 4;
                        output |= 0xC;
                        break;
                    case 'd': case 'D':
                        output << 4;
                        output |= 0xD;
                        break;
                    case 'e': case 'E':
                        output << 4;
                        output |= 0xE;
                        break;
                    case 'f': case 'F':
                        output << 4;
                        output |= 0xF;
                        break;
                    case '_':
                        break;
                }
            }
            return output;
        }
        static uint64_t from_integer_string(std::string_view view)
        {
            uint64_t output = 0;
            size_t left_index = 0;
            for (; left_index < view.length(); left_index++)
            {
                char c = view[left_index];
                switch (c) {
                    case '0':
                        output *= 10;
                        output += 0;
                        break;
                    case '1':
                        output *= 10;
                        output += 1;
                        break;
                    case '2':
                        output *= 10;
                        output += 2;
                        break;
                    case '3':
                        output *= 10;
                        output += 3;
                        break;
                    case '4':
                        output *= 10;
                        output += 4;
                        break;
                    case '5':
                        output *= 10;
                        output += 5;
                        break;
                    case '6':
                        output *= 10;
                        output += 6;
                        break;
                    case '7':
                        output *= 10;
                        output += 7;
                        break;
                    case '8':
                        output *= 10;
                        output += 8;
                        break;
                    case '9':
                        output *= 10;
                        output += 9;
                        break;
                    case '_':
                        break;
                }
            }
            return output;
        }
        // Parses any string that conforms to `[0-9]+\.[0-9]+` into a double.
        // No checks will be performed whether a string is correct!
        static double from_scalar_string(std::string_view view)
        {
            double output_natural = 0;
            double output_real = 0;
            size_t left_index = 0;
            for (; left_index < view.length(); left_index++)
            {
                char c = view[left_index];
                switch (c) {
                    case '.': goto loop_end;
                    case '0':
                        output_natural *= 10;
                        output_natural += 0;
                        break;
                    case '1':
                        output_natural *= 10;
                        output_natural += 1;
                        break;
                    case '2':
                        output_natural *= 10;
                        output_natural += 2;
                        break;
                    case '3':
                        output_natural *= 10;
                        output_natural += 3;
                        break;
                    case '4':
                        output_natural *= 10;
                        output_natural += 4;
                        break;
                    case '5':
                        output_natural *= 10;
                        output_natural += 5;
                        break;
                    case '6':
                        output_natural *= 10;
                        output_natural += 6;
                        break;
                    case '7':
                        output_natural *= 10;
                        output_natural += 7;
                        break;
                    case '8':
                        output_natural *= 10;
                        output_natural += 8;
                        break;
                    case '9':
                        output_natural *= 10;
                        output_natural += 9;
                        break;
                    case '_':
                        break;
                }
            }
loop_end:

            left_index;

            // Skip zeros on right side
            size_t right_index = view.length() - 1;
            for (; right_index > left_index && view[right_index] == '0'; right_index--) { }

            // Format XXX.000
            if (left_index == right_index) { return output_natural; }


            for (; right_index > left_index; right_index--)
            {
                char c = view[left_index];
                switch (c) {
                    case '0':
                        output_real /= 10;
                        output_real += 0.0;
                        break;
                    case '1':
                        output_real /= 10;
                        output_real += 0.1;
                        break;
                    case '2':
                        output_real /= 10;
                        output_real += 0.2;
                        break;
                    case '3':
                        output_real /= 10;
                        output_real += 0.3;
                        break;
                    case '4':
                        output_real /= 10;
                        output_real += 0.4;
                        break;
                    case '5':
                        output_real /= 10;
                        output_real += 0.5;
                        break;
                    case '6':
                        output_real /= 10;
                        output_real += 0.6;
                        break;
                    case '7':
                        output_real /= 10;
                        output_real += 0.7;
                        break;
                    case '8':
                        output_real /= 10;
                        output_real += 0.8;
                        break;
                    case '9':
                        output_real /= 10;
                        output_real += 0.9;
                        break;
                    case '_':
                        break;
                }
            }
            return output_natural + output_real;
        }
    protected:
        bool visit_enter(std::shared_ptr<leaf::parsing::instance::property> node) override;
        bool visit_enter(std::shared_ptr<leaf::parsing::instance::method> node) override;
        bool visit_enter(std::shared_ptr<leaf::parsing::instance::field> node) override;
        bool visit_enter(std::shared_ptr<leaf::parsing::instance::conversion> node) override;
        bool visit_enter(std::shared_ptr<leaf::parsing::instance::operator_binary_overload> node) override;
        bool visit_enter(std::shared_ptr<leaf::parsing::instance::operator_unary_overload> node) override;
        bool visit_enter(std::shared_ptr<leaf::parsing::instance::constructor> node) override;
        bool visit_enter(std::shared_ptr<leaf::parsing::instance::copystructor> node) override;
        bool visit_enter(std::shared_ptr<leaf::parsing::instance::destructor> node) override;
        bool visit_enter(std::shared_ptr<leaf::parsing::instance::method_arglist_item> node) override;
        bool emit_exp(const std::shared_ptr<leaf::parsing::instance::scope>& node);
        bool emit_exp(const std::shared_ptr<leaf::parsing::instance::statement>& node);
        bool emit_exp(const std::shared_ptr<leaf::parsing::instance::pragma>& node);
        bool emit_exp(const std::shared_ptr<leaf::parsing::instance::expression>& node);
        bool emit_exp(const std::shared_ptr<leaf::parsing::instance::exp_or>& node);
        bool emit_exp(const std::shared_ptr<leaf::parsing::instance::exp_and>& node);
        bool emit_exp(const std::shared_ptr<leaf::parsing::instance::exp_equality>& node);
        bool emit_exp(const std::shared_ptr<leaf::parsing::instance::exp_compare>& node);
        bool emit_exp(const std::shared_ptr<leaf::parsing::instance::exp_arithmetic_1>& node);
        bool emit_exp(const std::shared_ptr<leaf::parsing::instance::exp_arithmetic_2>& node);
        bool emit_exp(const std::shared_ptr<leaf::parsing::instance::exp_binary_1>& node);
        bool emit_exp(const std::shared_ptr<leaf::parsing::instance::exp_binary_2>& node);
        bool emit_exp(const std::shared_ptr<leaf::parsing::instance::exp_binary_3>& node);
        bool emit_exp(const std::shared_ptr<leaf::parsing::instance::exp_binary_4>& node);
        bool emit_exp(const std::shared_ptr<leaf::parsing::instance::exp_unary>& node);
        bool emit_exp(const std::shared_ptr<leaf::parsing::instance::exp_nullar>& node);
        bool emit_exp(const std::shared_ptr<leaf::parsing::instance::exp_value>& node);
        bool emit_exp(const std::shared_ptr<leaf::parsing::instance::declaration>& node);
        bool emit_exp(const std::shared_ptr<leaf::parsing::instance::exp_chain>& node);
        bool emit_exp(const std::shared_ptr<leaf::parsing::instance::call_body>& node,
                      std::vector<std::tuple<leaf_type_reference, leaf_type_ptr>>& out_params);
        bool emit_exp(const std::shared_ptr<leaf::parsing::instance::alloc>& node);
        bool emit_exp(const std::shared_ptr<leaf::parsing::instance::scalar_literal>& node);
        bool emit_exp(const std::shared_ptr<leaf::parsing::instance::integer_binary_literal>& node);
        bool emit_exp(const std::shared_ptr<leaf::parsing::instance::integer_hex_literal>& node);
        bool emit_exp(const std::shared_ptr<leaf::parsing::instance::integer_literal>& node);
        bool emit_exp(const std::shared_ptr<leaf::parsing::instance::char_literal>& node);
        bool emit_exp(const std::shared_ptr<leaf::parsing::instance::string_literal>& node);
        bool emit_exp(const std::shared_ptr<leaf::parsing::instance::exp_constant>& node);
        bool emit_exp(const std::shared_ptr<leaf::parsing::instance::nameof>& node);
        bool emit_exp(const std::shared_ptr<leaf::parsing::instance::typeof_>& node);


        leaf_method_info_ptr find_matching_method(
                const std::vector<std::tuple<leaf_type_reference, leaf_type_ptr>>& params,
                const std::vector<leaf_method_info_ptr>& candidates);
    };
}