#ifndef INCLUDE_GUARD_PARSER_CPP_INSTANCE
#define INCLUDE_GUARD_PARSER_CPP_INSTANCE
#include <memory>
#include <string>
#include <string_view>
#include <optional>
#include <variant>
#include <sstream>
#include <vector>

namespace leaf::parsing
{
    class instance
    {
    private:
        class resettable;
    public:
        class token;
        class attribute_arg_item_a;
        class attribute_arg_item_b;
        class attribute_args_a;
        class attribute_args_b;
        class attribute_item;
        class attribute;
        class contract;
        class contract_method;
        class contract_constructor;
        class contract_indexer;
        class contract_operator_binary_overload;
        class contract_operator_unary_overload;
        class contract_operator_nullar_overload;
        class contract_property;
        class contract_field;
        class contract_method_arglist;
        class contract_method_arglist_indexer;
        class scope;
        class scope_lambda;
        class scope_getset;
        class control_structure_body;
        class while_loop;
        class if_body;
        class else_body;
        class for_body;
        class for_each_body;
        class if_else;
        class switch_case;
        class switch_;
        class assembly_terminate;
        class assembly;
        class control_structure;
        class exp_chain_start;
        class exp_constant;
        class exp_lambda;
        class capture_list_item;
        class capture_list;
        class exp_value;
        class exp_nullar;
        class exp_unary;
        class expression;
        class encapsulation;
        class namespace_;
        class class_;
        class method_arglist_item;
        class method_arglist;
        class method_arglist_indexer;
        class method_meta;
        class method;
        class constructor;
        class destructor;
        class copystructor;
        class conversion;
        class indexer;
        class operator_binary_overload;
        class operator_unary_overload;
        class operator_nullar_overload;
        class property;
        class field;
        class constant;
        class using_;
        class alias_encapsulated;
        class alias;
        class call;
        class call_body;
        class free;
        class alloc;
        class typeof_;
        class nameof;
        class sizeof_;
        class lifetime;
        class type_match;
        class string_formatable;
        class string_literal;
        class scalar_literal;
        class integer_hex_literal;
        class integer_binary_literal;
        class integer_literal;
        class char_literal;
        class declaration;
        class return_statement;
        class statement;
        class pragma;
        class pragma_align;
        class pragma_size;
        class pragma_disable;
        class pragma_enable;
        class template_usage_item;
        class template_usage;
        class template_definition_item_direct_type;
        class template_definition_item_identifier;
        class template_definition;
        class main;
        class exp_chain;
        class exp_binary_4;
        class exp_binary_3;
        class exp_binary_2;
        class exp_binary_1;
        class exp_arithmetic_2;
        class exp_arithmetic_1;
        class exp_compare;
        class exp_equality;
        class exp_and;
        class exp_or;
        class ident_navigation;
        class type_navigation;
        class attribute_arg_item_a_state;
        class attribute_arg_item_b_state;
        class attribute_args_a_state;
        class attribute_args_b_state;
        class attribute_item_state;
        class attribute_state;
        class contract_state;
        class contract_method_state;
        class contract_constructor_state;
        class contract_indexer_state;
        class contract_operator_binary_overload_state;
        class contract_operator_unary_overload_state;
        class contract_operator_nullar_overload_state;
        class contract_property_state;
        class contract_field_state;
        class contract_method_arglist_state;
        class contract_method_arglist_indexer_state;
        class scope_state;
        class scope_lambda_state;
        class scope_getset_state;
        class control_structure_body_state;
        class while_loop_state;
        class if_body_state;
        class else_body_state;
        class for_body_state;
        class for_each_body_state;
        class if_else_state;
        class switch_case_state;
        class switch__state;
        class assembly_terminate_state;
        class assembly_state;
        class control_structure_state;
        class exp_chain_start_state;
        class exp_constant_state;
        class exp_lambda_state;
        class capture_list_item_state;
        class capture_list_state;
        class exp_value_state;
        class exp_nullar_state;
        class exp_unary_state;
        class expression_state;
        class encapsulation_state;
        class namespace__state;
        class class__state;
        class method_arglist_item_state;
        class method_arglist_state;
        class method_arglist_indexer_state;
        class method_meta_state;
        class method_state;
        class constructor_state;
        class destructor_state;
        class copystructor_state;
        class conversion_state;
        class indexer_state;
        class operator_binary_overload_state;
        class operator_unary_overload_state;
        class operator_nullar_overload_state;
        class property_state;
        class field_state;
        class constant_state;
        class using__state;
        class alias_encapsulated_state;
        class alias_state;
        class call_state;
        class call_body_state;
        class free_state;
        class alloc_state;
        class typeof__state;
        class nameof_state;
        class sizeof__state;
        class lifetime_state;
        class type_match_state;
        class string_formatable_state;
        class string_literal_state;
        class scalar_literal_state;
        class integer_hex_literal_state;
        class integer_binary_literal_state;
        class integer_literal_state;
        class char_literal_state;
        class declaration_state;
        class return_statement_state;
        class statement_state;
        class pragma_state;
        class pragma_align_state;
        class pragma_size_state;
        class pragma_disable_state;
        class pragma_enable_state;
        class template_usage_item_state;
        class template_usage_state;
        class template_definition_item_direct_type_state;
        class template_definition_item_identifier_state;
        class template_definition_state;
        class main_state;
        class exp_chain_state;
        class exp_binary_4_state;
        class exp_binary_3_state;
        class exp_binary_2_state;
        class exp_binary_1_state;
        class exp_arithmetic_2_state;
        class exp_arithmetic_1_state;
        class exp_compare_state;
        class exp_equality_state;
        class exp_and_state;
        class exp_or_state;
        class ident_navigation_state;
        class type_navigation_state;
        class visitor;
    private:
        class resettable
        {
        public:
            instance& m_ref;
            std::string_view m_contents;
            std::string m_file;
            size_t m_line;
            size_t m_column;
            size_t m_offset;
             resettable(instance& ref);
            void reset();
        };
        friend class resettable;
        bool next();
        char current();
        std::optional<size_t> token_integer_binary(size_t depth);
        std::optional<size_t> token_integer_hex(size_t depth);
        std::optional<size_t> token_integer_unsigned(size_t depth);
        std::optional<size_t> token_integer_signed_negative(size_t depth);
        std::optional<size_t> token_integer_signed_positive(size_t depth);
        std::optional<size_t> token_integer(size_t depth);
        std::optional<size_t> token_scalar(size_t depth);
        std::optional<size_t> token_slash(size_t depth);
        std::optional<size_t> token_star(size_t depth);
        std::optional<size_t> token_plus(size_t depth);
        std::optional<size_t> token_minus(size_t depth);
        std::optional<size_t> token_underscore(size_t depth);
        std::optional<size_t> token_true_(size_t depth);
        std::optional<size_t> token_false_(size_t depth);
        std::optional<size_t> token_ident(size_t depth);
        std::optional<size_t> token_string_formatable_start(size_t depth);
        std::optional<size_t> token_string_formatable_fake(size_t depth);
        std::optional<size_t> token_string_formatable_continuation(size_t depth);
        std::optional<size_t> token_string_formatable_end(size_t depth);
        std::optional<size_t> token_string_unescaped_ending(size_t depth);
        std::optional<size_t> token_string(size_t depth);
        std::optional<size_t> token_char_unescaped_ending(size_t depth);
        std::optional<size_t> token_char_(size_t depth);
        std::optional<size_t> token__colon(size_t depth);
        std::optional<size_t> token__comma(size_t depth);
        std::optional<size_t> token__round_bracket_open(size_t depth);
        std::optional<size_t> token__round_bracket_close(size_t depth);
        std::optional<size_t> token__square_bracket_open(size_t depth);
        std::optional<size_t> token__square_bracket_close(size_t depth);
        std::optional<size_t> token__contract(size_t depth);
        std::optional<size_t> token__curly_bracket_open(size_t depth);
        std::optional<size_t> token__curly_bracket_close(size_t depth);
        std::optional<size_t> token__semicolon(size_t depth);
        std::optional<size_t> token__get(size_t depth);
        std::optional<size_t> token__set(size_t depth);
        std::optional<size_t> token__operator(size_t depth);
        std::optional<size_t> token__less_then_less_then_less_then(size_t depth);
        std::optional<size_t> token__less_then_less_then(size_t depth);
        std::optional<size_t> token__less_then_equal(size_t depth);
        std::optional<size_t> token__less_then(size_t depth);
        std::optional<size_t> token__greater_then_greater_then_greater_then(size_t depth);
        std::optional<size_t> token__greater_then_greater_then(size_t depth);
        std::optional<size_t> token__greater_then_equal(size_t depth);
        std::optional<size_t> token__greater_then(size_t depth);
        std::optional<size_t> token__vertical_bar_vertical_bar(size_t depth);
        std::optional<size_t> token__vertical_bar(size_t depth);
        std::optional<size_t> token__ampersand_ampersand(size_t depth);
        std::optional<size_t> token__ampersand(size_t depth);
        std::optional<size_t> token__equal_equal_equal(size_t depth);
        std::optional<size_t> token__equal_equal(size_t depth);
        std::optional<size_t> token__exclamation_equal(size_t depth);
        std::optional<size_t> token__circumflex(size_t depth);
        std::optional<size_t> token__exclamation(size_t depth);
        std::optional<size_t> token__tilde(size_t depth);
        std::optional<size_t> token__dot(size_t depth);
        std::optional<size_t> token__minus_greater_then(size_t depth);
        std::optional<size_t> token__equal_greater_then(size_t depth);
        std::optional<size_t> token__while(size_t depth);
        std::optional<size_t> token__if(size_t depth);
        std::optional<size_t> token__else(size_t depth);
        std::optional<size_t> token__for(size_t depth);
        std::optional<size_t> token__case(size_t depth);
        std::optional<size_t> token__switch(size_t depth);
        std::optional<size_t> token__default(size_t depth);
        std::optional<size_t> token__eol(size_t depth);
        std::optional<size_t> token__assembly(size_t depth);
        std::optional<size_t> token__copy(size_t depth);
        std::optional<size_t> token__tilde_equal(size_t depth);
        std::optional<size_t> token__equal(size_t depth);
        std::optional<size_t> token__public(size_t depth);
        std::optional<size_t> token__local(size_t depth);
        std::optional<size_t> token__derived(size_t depth);
        std::optional<size_t> token__private(size_t depth);
        std::optional<size_t> token__namespace(size_t depth);
        std::optional<size_t> token__class(size_t depth);
        std::optional<size_t> token__sealed(size_t depth);
        std::optional<size_t> token__virtual(size_t depth);
        std::optional<size_t> token__unbound(size_t depth);
        std::optional<size_t> token__inline(size_t depth);
        std::optional<size_t> token__delete(size_t depth);
        std::optional<size_t> token__conversion(size_t depth);
        std::optional<size_t> token__const(size_t depth);
        std::optional<size_t> token__using(size_t depth);
        std::optional<size_t> token__alias(size_t depth);
        std::optional<size_t> token__free(size_t depth);
        std::optional<size_t> token__alloc(size_t depth);
        std::optional<size_t> token__stack(size_t depth);
        std::optional<size_t> token__heap(size_t depth);
        std::optional<size_t> token__typeof(size_t depth);
        std::optional<size_t> token__nameof(size_t depth);
        std::optional<size_t> token__sizeof(size_t depth);
        std::optional<size_t> token__single_quotation(size_t depth);
        std::optional<size_t> token__scope(size_t depth);
        std::optional<size_t> token__static(size_t depth);
        std::optional<size_t> token__return(size_t depth);
        std::optional<size_t> token__auto_815(size_t depth);
        std::optional<size_t> token__exclamation_greater_then(size_t depth);
        std::optional<size_t> token__align(size_t depth);
        std::optional<size_t> token__size(size_t depth);
        std::optional<size_t> token__disable(size_t depth);
        std::optional<size_t> token__enable(size_t depth);
        std::optional<size_t> token__identifier(size_t depth);
        bool m_expor_103(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_arg_item_a>& actual, leaf::parsing::instance::attribute_arg_item_a_state& state, size_t depth);
        bool p_can_attribute_arg_item_a(size_t depth);
        std::shared_ptr<leaf::parsing::instance::attribute_arg_item_a> p_match_attribute_arg_item_a(size_t depth);
        bool m_ident_colon_expor_104(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_arg_item_b>& actual, leaf::parsing::instance::attribute_arg_item_b_state& state, size_t depth);
        bool p_can_attribute_arg_item_b(size_t depth);
        std::shared_ptr<leaf::parsing::instance::attribute_arg_item_b> p_match_attribute_arg_item_b(size_t depth);
        bool m_attributeargitema_105(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_a>& actual, leaf::parsing::instance::attribute_args_a_state& state, size_t depth);
        bool m_attributeargitema_106(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_a>& actual, leaf::parsing::instance::attribute_args_a_state& state, size_t depth);
        bool m_comma_attributeargitema_107(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_a>& actual, leaf::parsing::instance::attribute_args_a_state& state, size_t depth);
        bool while108_109(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_a>& actual, leaf::parsing::instance::attribute_args_a_state& state, size_t depth);
        bool m_comma_110(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_a>& actual, leaf::parsing::instance::attribute_args_a_state& state, size_t depth);
        bool m_comma_111(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_a>& actual, leaf::parsing::instance::attribute_args_a_state& state, size_t depth);
        bool if112_113(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_a>& actual, leaf::parsing::instance::attribute_args_a_state& state, size_t depth);
        bool p_can_attribute_args_a(size_t depth);
        std::shared_ptr<leaf::parsing::instance::attribute_args_a> p_match_attribute_args_a(size_t depth);
        bool m_attributeargitemb_114(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_b>& actual, leaf::parsing::instance::attribute_args_b_state& state, size_t depth);
        bool m_attributeargitemb_115(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_b>& actual, leaf::parsing::instance::attribute_args_b_state& state, size_t depth);
        bool m_comma_attributeargitemb_116(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_b>& actual, leaf::parsing::instance::attribute_args_b_state& state, size_t depth);
        bool while117_118(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_b>& actual, leaf::parsing::instance::attribute_args_b_state& state, size_t depth);
        bool m_comma_119(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_b>& actual, leaf::parsing::instance::attribute_args_b_state& state, size_t depth);
        bool m_comma_120(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_b>& actual, leaf::parsing::instance::attribute_args_b_state& state, size_t depth);
        bool if121_122(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_b>& actual, leaf::parsing::instance::attribute_args_b_state& state, size_t depth);
        bool p_can_attribute_args_b(size_t depth);
        std::shared_ptr<leaf::parsing::instance::attribute_args_b> p_match_attribute_args_b(size_t depth);
        bool m_typematch_123(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_item>& actual, leaf::parsing::instance::attribute_item_state& state, size_t depth);
        bool m_typematch_roundbracketopen_roundbracketclose_124(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_item>& actual, leaf::parsing::instance::attribute_item_state& state, size_t depth);
        bool m_typematch_roundbracketopen_attributeargsa_attributeargsb_roundbracketclose_125(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_item>& actual, leaf::parsing::instance::attribute_item_state& state, size_t depth);
        bool m_typematch_roundbracketopen_attributeargsa_roundbracketclose_126(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_item>& actual, leaf::parsing::instance::attribute_item_state& state, size_t depth);
        bool m_typematch_roundbracketopen_attributeargsb_roundbracketclose_127(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_item>& actual, leaf::parsing::instance::attribute_item_state& state, size_t depth);
        bool alternatives128(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_item>& actual, leaf::parsing::instance::attribute_item_state& state, size_t depth);
        bool p_can_attribute_item(size_t depth);
        std::shared_ptr<leaf::parsing::instance::attribute_item> p_match_attribute_item(size_t depth);
        bool m_squarebracketopen_129(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute>& actual, leaf::parsing::instance::attribute_state& state, size_t depth);
        bool m_attributeitem_130(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute>& actual, leaf::parsing::instance::attribute_state& state, size_t depth);
        bool m_attributeitem_131(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute>& actual, leaf::parsing::instance::attribute_state& state, size_t depth);
        bool m_attributeitem_132(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute>& actual, leaf::parsing::instance::attribute_state& state, size_t depth);
        bool m_comma_attributeitem_133(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute>& actual, leaf::parsing::instance::attribute_state& state, size_t depth);
        bool while134_135(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute>& actual, leaf::parsing::instance::attribute_state& state, size_t depth);
        bool m_comma_136(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute>& actual, leaf::parsing::instance::attribute_state& state, size_t depth);
        bool m_comma_137(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute>& actual, leaf::parsing::instance::attribute_state& state, size_t depth);
        bool if138_139(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute>& actual, leaf::parsing::instance::attribute_state& state, size_t depth);
        bool if140_141(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute>& actual, leaf::parsing::instance::attribute_state& state, size_t depth);
        bool m_squarebracketclose_142(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute>& actual, leaf::parsing::instance::attribute_state& state, size_t depth);
        bool p_can_attribute(size_t depth);
        std::shared_ptr<leaf::parsing::instance::attribute> p_match_attribute(size_t depth);
        bool m_encapsulation_contract_ident_143(bool is_can, std::shared_ptr<leaf::parsing::instance::contract>& actual, leaf::parsing::instance::contract_state& state, size_t depth);
        bool m_templatedefinition_144(bool is_can, std::shared_ptr<leaf::parsing::instance::contract>& actual, leaf::parsing::instance::contract_state& state, size_t depth);
        bool m_templatedefinition_145(bool is_can, std::shared_ptr<leaf::parsing::instance::contract>& actual, leaf::parsing::instance::contract_state& state, size_t depth);
        bool if146_147(bool is_can, std::shared_ptr<leaf::parsing::instance::contract>& actual, leaf::parsing::instance::contract_state& state, size_t depth);
        bool m_curlybracketopen_148(bool is_can, std::shared_ptr<leaf::parsing::instance::contract>& actual, leaf::parsing::instance::contract_state& state, size_t depth);
        bool m_curlybracketclose_149(bool is_can, std::shared_ptr<leaf::parsing::instance::contract>& actual, leaf::parsing::instance::contract_state& state, size_t depth);
        bool m_contractmethod_150(bool is_can, std::shared_ptr<leaf::parsing::instance::contract>& actual, leaf::parsing::instance::contract_state& state, size_t depth);
        bool m_contractconstructor_151(bool is_can, std::shared_ptr<leaf::parsing::instance::contract>& actual, leaf::parsing::instance::contract_state& state, size_t depth);
        bool m_contractindexer_152(bool is_can, std::shared_ptr<leaf::parsing::instance::contract>& actual, leaf::parsing::instance::contract_state& state, size_t depth);
        bool m_contractoperatorbinaryoverload_153(bool is_can, std::shared_ptr<leaf::parsing::instance::contract>& actual, leaf::parsing::instance::contract_state& state, size_t depth);
        bool m_contractoperatorunaryoverload_154(bool is_can, std::shared_ptr<leaf::parsing::instance::contract>& actual, leaf::parsing::instance::contract_state& state, size_t depth);
        bool m_contractoperatornullaroverload_155(bool is_can, std::shared_ptr<leaf::parsing::instance::contract>& actual, leaf::parsing::instance::contract_state& state, size_t depth);
        bool m_contractproperty_156(bool is_can, std::shared_ptr<leaf::parsing::instance::contract>& actual, leaf::parsing::instance::contract_state& state, size_t depth);
        bool m_contractfield_157(bool is_can, std::shared_ptr<leaf::parsing::instance::contract>& actual, leaf::parsing::instance::contract_state& state, size_t depth);
        bool alternatives158(bool is_can, std::shared_ptr<leaf::parsing::instance::contract>& actual, leaf::parsing::instance::contract_state& state, size_t depth);
        bool while159_160(bool is_can, std::shared_ptr<leaf::parsing::instance::contract>& actual, leaf::parsing::instance::contract_state& state, size_t depth);
        bool m_curlybracketclose_161(bool is_can, std::shared_ptr<leaf::parsing::instance::contract>& actual, leaf::parsing::instance::contract_state& state, size_t depth);
        bool p_can_contract(size_t depth);
        std::shared_ptr<leaf::parsing::instance::contract> p_match_contract(size_t depth);
        bool m_typematch_ident_contractmethodarglist_semicolon_162(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_method>& actual, leaf::parsing::instance::contract_method_state& state, size_t depth);
        bool p_can_contract_method(size_t depth);
        std::shared_ptr<leaf::parsing::instance::contract_method> p_match_contract_method(size_t depth);
        bool m_ident_contractmethodarglist_semicolon_163(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_constructor>& actual, leaf::parsing::instance::contract_constructor_state& state, size_t depth);
        bool p_can_contract_constructor(size_t depth);
        std::shared_ptr<leaf::parsing::instance::contract_constructor> p_match_contract_constructor(size_t depth);
        bool m_typematch_contractmethodarglistindexer_164(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_indexer>& actual, leaf::parsing::instance::contract_indexer_state& state, size_t depth);
        bool m_curlybracketopen_get_semicolon_set_semicolon_curlybracketclose_165(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_indexer>& actual, leaf::parsing::instance::contract_indexer_state& state, size_t depth);
        bool m_curlybracketopen_get_semicolon_curlybracketclose_166(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_indexer>& actual, leaf::parsing::instance::contract_indexer_state& state, size_t depth);
        bool m_curlybracketopen_set_semicolon_curlybracketclose_167(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_indexer>& actual, leaf::parsing::instance::contract_indexer_state& state, size_t depth);
        bool alternatives168(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_indexer>& actual, leaf::parsing::instance::contract_indexer_state& state, size_t depth);
        bool p_can_contract_indexer(size_t depth);
        std::shared_ptr<leaf::parsing::instance::contract_indexer> p_match_contract_indexer(size_t depth);
        bool m_typematch_operator_169(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_binary_overload>& actual, leaf::parsing::instance::contract_operator_binary_overload_state& state, size_t depth);
        bool m_roundbracketopen_typematch_roundbracketclose_170(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_binary_overload>& actual, leaf::parsing::instance::contract_operator_binary_overload_state& state, size_t depth);
        bool m_plus_171(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_binary_overload>& actual, leaf::parsing::instance::contract_operator_binary_overload_state& state, size_t depth);
        bool m_minus_172(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_binary_overload>& actual, leaf::parsing::instance::contract_operator_binary_overload_state& state, size_t depth);
        bool m_star_173(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_binary_overload>& actual, leaf::parsing::instance::contract_operator_binary_overload_state& state, size_t depth);
        bool m_slash_174(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_binary_overload>& actual, leaf::parsing::instance::contract_operator_binary_overload_state& state, size_t depth);
        bool m_lessthenlessthenlessthen_175(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_binary_overload>& actual, leaf::parsing::instance::contract_operator_binary_overload_state& state, size_t depth);
        bool m_lessthenlessthen_176(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_binary_overload>& actual, leaf::parsing::instance::contract_operator_binary_overload_state& state, size_t depth);
        bool m_lessthenequal_177(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_binary_overload>& actual, leaf::parsing::instance::contract_operator_binary_overload_state& state, size_t depth);
        bool m_lessthen_178(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_binary_overload>& actual, leaf::parsing::instance::contract_operator_binary_overload_state& state, size_t depth);
        bool m_greaterthengreaterthengreaterthen_179(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_binary_overload>& actual, leaf::parsing::instance::contract_operator_binary_overload_state& state, size_t depth);
        bool m_greaterthengreaterthen_180(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_binary_overload>& actual, leaf::parsing::instance::contract_operator_binary_overload_state& state, size_t depth);
        bool m_greaterthenequal_181(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_binary_overload>& actual, leaf::parsing::instance::contract_operator_binary_overload_state& state, size_t depth);
        bool m_greaterthen_182(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_binary_overload>& actual, leaf::parsing::instance::contract_operator_binary_overload_state& state, size_t depth);
        bool m_verticalbarverticalbar_183(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_binary_overload>& actual, leaf::parsing::instance::contract_operator_binary_overload_state& state, size_t depth);
        bool m_verticalbar_184(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_binary_overload>& actual, leaf::parsing::instance::contract_operator_binary_overload_state& state, size_t depth);
        bool m_ampersandampersand_185(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_binary_overload>& actual, leaf::parsing::instance::contract_operator_binary_overload_state& state, size_t depth);
        bool m_ampersand_186(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_binary_overload>& actual, leaf::parsing::instance::contract_operator_binary_overload_state& state, size_t depth);
        bool m_equalequalequal_187(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_binary_overload>& actual, leaf::parsing::instance::contract_operator_binary_overload_state& state, size_t depth);
        bool m_equalequal_188(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_binary_overload>& actual, leaf::parsing::instance::contract_operator_binary_overload_state& state, size_t depth);
        bool m_exclamationequal_189(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_binary_overload>& actual, leaf::parsing::instance::contract_operator_binary_overload_state& state, size_t depth);
        bool m_circumflex_190(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_binary_overload>& actual, leaf::parsing::instance::contract_operator_binary_overload_state& state, size_t depth);
        bool alternatives191(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_binary_overload>& actual, leaf::parsing::instance::contract_operator_binary_overload_state& state, size_t depth);
        bool m_roundbracketopen_typematch_roundbracketclose_semicolon_192(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_binary_overload>& actual, leaf::parsing::instance::contract_operator_binary_overload_state& state, size_t depth);
        bool p_can_contract_operator_binary_overload(size_t depth);
        std::shared_ptr<leaf::parsing::instance::contract_operator_binary_overload> p_match_contract_operator_binary_overload(size_t depth);
        bool m_typematch_operator_193(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_unary_overload>& actual, leaf::parsing::instance::contract_operator_unary_overload_state& state, size_t depth);
        bool m_plus_194(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_unary_overload>& actual, leaf::parsing::instance::contract_operator_unary_overload_state& state, size_t depth);
        bool m_minus_195(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_unary_overload>& actual, leaf::parsing::instance::contract_operator_unary_overload_state& state, size_t depth);
        bool m_exclamation_196(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_unary_overload>& actual, leaf::parsing::instance::contract_operator_unary_overload_state& state, size_t depth);
        bool m_tilde_197(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_unary_overload>& actual, leaf::parsing::instance::contract_operator_unary_overload_state& state, size_t depth);
        bool alternatives198(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_unary_overload>& actual, leaf::parsing::instance::contract_operator_unary_overload_state& state, size_t depth);
        bool m_roundbracketopen_typematch_roundbracketclose_semicolon_199(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_unary_overload>& actual, leaf::parsing::instance::contract_operator_unary_overload_state& state, size_t depth);
        bool p_can_contract_operator_unary_overload(size_t depth);
        std::shared_ptr<leaf::parsing::instance::contract_operator_unary_overload> p_match_contract_operator_unary_overload(size_t depth);
        bool m_methodmeta_operator_200(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_nullar_overload>& actual, leaf::parsing::instance::contract_operator_nullar_overload_state& state, size_t depth);
        bool m_dot_201(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_nullar_overload>& actual, leaf::parsing::instance::contract_operator_nullar_overload_state& state, size_t depth);
        bool m_minusgreaterthen_202(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_nullar_overload>& actual, leaf::parsing::instance::contract_operator_nullar_overload_state& state, size_t depth);
        bool alternatives203(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_nullar_overload>& actual, leaf::parsing::instance::contract_operator_nullar_overload_state& state, size_t depth);
        bool m_semicolon_204(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_operator_nullar_overload>& actual, leaf::parsing::instance::contract_operator_nullar_overload_state& state, size_t depth);
        bool p_can_contract_operator_nullar_overload(size_t depth);
        std::shared_ptr<leaf::parsing::instance::contract_operator_nullar_overload> p_match_contract_operator_nullar_overload(size_t depth);
        bool m_typematch_ident_205(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_property>& actual, leaf::parsing::instance::contract_property_state& state, size_t depth);
        bool m_curlybracketopen_get_semicolon_set_semicolon_curlybracketclose_206(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_property>& actual, leaf::parsing::instance::contract_property_state& state, size_t depth);
        bool m_curlybracketopen_get_semicolon_curlybracketclose_207(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_property>& actual, leaf::parsing::instance::contract_property_state& state, size_t depth);
        bool m_curlybracketopen_set_semicolon_curlybracketclose_208(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_property>& actual, leaf::parsing::instance::contract_property_state& state, size_t depth);
        bool alternatives209(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_property>& actual, leaf::parsing::instance::contract_property_state& state, size_t depth);
        bool p_can_contract_property(size_t depth);
        std::shared_ptr<leaf::parsing::instance::contract_property> p_match_contract_property(size_t depth);
        bool m_typematch_ident_semicolon_210(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_field>& actual, leaf::parsing::instance::contract_field_state& state, size_t depth);
        bool p_can_contract_field(size_t depth);
        std::shared_ptr<leaf::parsing::instance::contract_field> p_match_contract_field(size_t depth);
        bool m_roundbracketopen_211(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_method_arglist>& actual, leaf::parsing::instance::contract_method_arglist_state& state, size_t depth);
        bool m_typematch_212(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_method_arglist>& actual, leaf::parsing::instance::contract_method_arglist_state& state, size_t depth);
        bool m_typematch_213(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_method_arglist>& actual, leaf::parsing::instance::contract_method_arglist_state& state, size_t depth);
        bool m_roundbracketclose_214(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_method_arglist>& actual, leaf::parsing::instance::contract_method_arglist_state& state, size_t depth);
        bool m_comma_typematch_215(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_method_arglist>& actual, leaf::parsing::instance::contract_method_arglist_state& state, size_t depth);
        bool m_comma_216(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_method_arglist>& actual, leaf::parsing::instance::contract_method_arglist_state& state, size_t depth);
        bool alternatives217(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_method_arglist>& actual, leaf::parsing::instance::contract_method_arglist_state& state, size_t depth);
        bool while218_219(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_method_arglist>& actual, leaf::parsing::instance::contract_method_arglist_state& state, size_t depth);
        bool if220_221(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_method_arglist>& actual, leaf::parsing::instance::contract_method_arglist_state& state, size_t depth);
        bool m_roundbracketclose_222(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_method_arglist>& actual, leaf::parsing::instance::contract_method_arglist_state& state, size_t depth);
        bool p_can_contract_method_arglist(size_t depth);
        std::shared_ptr<leaf::parsing::instance::contract_method_arglist> p_match_contract_method_arglist(size_t depth);
        bool m_squarebracketopen_223(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_method_arglist_indexer>& actual, leaf::parsing::instance::contract_method_arglist_indexer_state& state, size_t depth);
        bool m_typematch_224(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_method_arglist_indexer>& actual, leaf::parsing::instance::contract_method_arglist_indexer_state& state, size_t depth);
        bool m_squarebracketclose_225(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_method_arglist_indexer>& actual, leaf::parsing::instance::contract_method_arglist_indexer_state& state, size_t depth);
        bool m_comma_typematch_226(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_method_arglist_indexer>& actual, leaf::parsing::instance::contract_method_arglist_indexer_state& state, size_t depth);
        bool m_comma_227(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_method_arglist_indexer>& actual, leaf::parsing::instance::contract_method_arglist_indexer_state& state, size_t depth);
        bool alternatives228(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_method_arglist_indexer>& actual, leaf::parsing::instance::contract_method_arglist_indexer_state& state, size_t depth);
        bool while229_230(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_method_arglist_indexer>& actual, leaf::parsing::instance::contract_method_arglist_indexer_state& state, size_t depth);
        bool m_squarebracketclose_231(bool is_can, std::shared_ptr<leaf::parsing::instance::contract_method_arglist_indexer>& actual, leaf::parsing::instance::contract_method_arglist_indexer_state& state, size_t depth);
        bool p_can_contract_method_arglist_indexer(size_t depth);
        std::shared_ptr<leaf::parsing::instance::contract_method_arglist_indexer> p_match_contract_method_arglist_indexer(size_t depth);
        bool m_curlybracketclose_232(bool is_can, std::shared_ptr<leaf::parsing::instance::scope>& actual, leaf::parsing::instance::scope_state& state, size_t depth);
        bool m_using_233(bool is_can, std::shared_ptr<leaf::parsing::instance::scope>& actual, leaf::parsing::instance::scope_state& state, size_t depth);
        bool m_controlstructure_234(bool is_can, std::shared_ptr<leaf::parsing::instance::scope>& actual, leaf::parsing::instance::scope_state& state, size_t depth);
        bool m_statement_235(bool is_can, std::shared_ptr<leaf::parsing::instance::scope>& actual, leaf::parsing::instance::scope_state& state, size_t depth);
        bool alternatives236(bool is_can, std::shared_ptr<leaf::parsing::instance::scope>& actual, leaf::parsing::instance::scope_state& state, size_t depth);
        bool while237_238(bool is_can, std::shared_ptr<leaf::parsing::instance::scope>& actual, leaf::parsing::instance::scope_state& state, size_t depth);
        bool m_curlybracketclose_239(bool is_can, std::shared_ptr<leaf::parsing::instance::scope>& actual, leaf::parsing::instance::scope_state& state, size_t depth);
        bool m_curlybracketopen_240(bool is_can, std::shared_ptr<leaf::parsing::instance::scope>& actual, leaf::parsing::instance::scope_state& state, size_t depth);
        bool m_using_241(bool is_can, std::shared_ptr<leaf::parsing::instance::scope>& actual, leaf::parsing::instance::scope_state& state, size_t depth);
        bool m_controlstructure_242(bool is_can, std::shared_ptr<leaf::parsing::instance::scope>& actual, leaf::parsing::instance::scope_state& state, size_t depth);
        bool m_statement_243(bool is_can, std::shared_ptr<leaf::parsing::instance::scope>& actual, leaf::parsing::instance::scope_state& state, size_t depth);
        bool alternatives244(bool is_can, std::shared_ptr<leaf::parsing::instance::scope>& actual, leaf::parsing::instance::scope_state& state, size_t depth);
        bool m_equalgreaterthen_245(bool is_can, std::shared_ptr<leaf::parsing::instance::scope>& actual, leaf::parsing::instance::scope_state& state, size_t depth);
        bool alternatives246(bool is_can, std::shared_ptr<leaf::parsing::instance::scope>& actual, leaf::parsing::instance::scope_state& state, size_t depth);
        bool p_can_scope(size_t depth);
        std::shared_ptr<leaf::parsing::instance::scope> p_match_scope(size_t depth);
        bool m_curlybracketclose_247(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_lambda>& actual, leaf::parsing::instance::scope_lambda_state& state, size_t depth);
        bool m_using_248(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_lambda>& actual, leaf::parsing::instance::scope_lambda_state& state, size_t depth);
        bool m_controlstructure_249(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_lambda>& actual, leaf::parsing::instance::scope_lambda_state& state, size_t depth);
        bool m_statement_250(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_lambda>& actual, leaf::parsing::instance::scope_lambda_state& state, size_t depth);
        bool alternatives251(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_lambda>& actual, leaf::parsing::instance::scope_lambda_state& state, size_t depth);
        bool while252_253(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_lambda>& actual, leaf::parsing::instance::scope_lambda_state& state, size_t depth);
        bool m_curlybracketclose_254(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_lambda>& actual, leaf::parsing::instance::scope_lambda_state& state, size_t depth);
        bool m_curlybracketopen_255(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_lambda>& actual, leaf::parsing::instance::scope_lambda_state& state, size_t depth);
        bool m_using_256(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_lambda>& actual, leaf::parsing::instance::scope_lambda_state& state, size_t depth);
        bool m_controlstructure_257(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_lambda>& actual, leaf::parsing::instance::scope_lambda_state& state, size_t depth);
        bool m_statement_258(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_lambda>& actual, leaf::parsing::instance::scope_lambda_state& state, size_t depth);
        bool alternatives259(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_lambda>& actual, leaf::parsing::instance::scope_lambda_state& state, size_t depth);
        bool m_equalgreaterthen_260(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_lambda>& actual, leaf::parsing::instance::scope_lambda_state& state, size_t depth);
        bool alternatives261(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_lambda>& actual, leaf::parsing::instance::scope_lambda_state& state, size_t depth);
        bool p_can_scope_lambda(size_t depth);
        std::shared_ptr<leaf::parsing::instance::scope_lambda> p_match_scope_lambda(size_t depth);
        bool m_curlybracketopen_262(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_getset>& actual, leaf::parsing::instance::scope_getset_state& state, size_t depth);
        bool m_get_scope_set_scope_263(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_getset>& actual, leaf::parsing::instance::scope_getset_state& state, size_t depth);
        bool m_set_scope_get_scope_264(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_getset>& actual, leaf::parsing::instance::scope_getset_state& state, size_t depth);
        bool m_get_scope_265(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_getset>& actual, leaf::parsing::instance::scope_getset_state& state, size_t depth);
        bool m_set_scope_266(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_getset>& actual, leaf::parsing::instance::scope_getset_state& state, size_t depth);
        bool alternatives267(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_getset>& actual, leaf::parsing::instance::scope_getset_state& state, size_t depth);
        bool m_curlybracketclose_268(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_getset>& actual, leaf::parsing::instance::scope_getset_state& state, size_t depth);
        bool p_can_scope_getset(size_t depth);
        std::shared_ptr<leaf::parsing::instance::scope_getset> p_match_scope_getset(size_t depth);
        bool m_scope_269(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure_body>& actual, leaf::parsing::instance::control_structure_body_state& state, size_t depth);
        bool m_controlstructure_270(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure_body>& actual, leaf::parsing::instance::control_structure_body_state& state, size_t depth);
        bool m_statement_271(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure_body>& actual, leaf::parsing::instance::control_structure_body_state& state, size_t depth);
        bool alternatives272(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure_body>& actual, leaf::parsing::instance::control_structure_body_state& state, size_t depth);
        bool p_can_control_structure_body(size_t depth);
        std::shared_ptr<leaf::parsing::instance::control_structure_body> p_match_control_structure_body(size_t depth);
        bool m_while_roundbracketopen_expression_roundbracketclose_controlstructurebody_273(bool is_can, std::shared_ptr<leaf::parsing::instance::while_loop>& actual, leaf::parsing::instance::while_loop_state& state, size_t depth);
        bool p_can_while_loop(size_t depth);
        std::shared_ptr<leaf::parsing::instance::while_loop> p_match_while_loop(size_t depth);
        bool m_if_roundbracketopen_expression_roundbracketclose_controlstructurebody_274(bool is_can, std::shared_ptr<leaf::parsing::instance::if_body>& actual, leaf::parsing::instance::if_body_state& state, size_t depth);
        bool p_can_if_body(size_t depth);
        std::shared_ptr<leaf::parsing::instance::if_body> p_match_if_body(size_t depth);
        bool m_else_controlstructurebody_275(bool is_can, std::shared_ptr<leaf::parsing::instance::else_body>& actual, leaf::parsing::instance::else_body_state& state, size_t depth);
        bool p_can_else_body(size_t depth);
        std::shared_ptr<leaf::parsing::instance::else_body> p_match_else_body(size_t depth);
        bool m_for_roundbracketopen_276(bool is_can, std::shared_ptr<leaf::parsing::instance::for_body>& actual, leaf::parsing::instance::for_body_state& state, size_t depth);
        bool m_expression_277(bool is_can, std::shared_ptr<leaf::parsing::instance::for_body>& actual, leaf::parsing::instance::for_body_state& state, size_t depth);
        bool m_expression_278(bool is_can, std::shared_ptr<leaf::parsing::instance::for_body>& actual, leaf::parsing::instance::for_body_state& state, size_t depth);
        bool if279_280(bool is_can, std::shared_ptr<leaf::parsing::instance::for_body>& actual, leaf::parsing::instance::for_body_state& state, size_t depth);
        bool m_semicolon_281(bool is_can, std::shared_ptr<leaf::parsing::instance::for_body>& actual, leaf::parsing::instance::for_body_state& state, size_t depth);
        bool m_expression_282(bool is_can, std::shared_ptr<leaf::parsing::instance::for_body>& actual, leaf::parsing::instance::for_body_state& state, size_t depth);
        bool m_expression_283(bool is_can, std::shared_ptr<leaf::parsing::instance::for_body>& actual, leaf::parsing::instance::for_body_state& state, size_t depth);
        bool if284_285(bool is_can, std::shared_ptr<leaf::parsing::instance::for_body>& actual, leaf::parsing::instance::for_body_state& state, size_t depth);
        bool m_semicolon_286(bool is_can, std::shared_ptr<leaf::parsing::instance::for_body>& actual, leaf::parsing::instance::for_body_state& state, size_t depth);
        bool m_expression_287(bool is_can, std::shared_ptr<leaf::parsing::instance::for_body>& actual, leaf::parsing::instance::for_body_state& state, size_t depth);
        bool m_expression_288(bool is_can, std::shared_ptr<leaf::parsing::instance::for_body>& actual, leaf::parsing::instance::for_body_state& state, size_t depth);
        bool if289_290(bool is_can, std::shared_ptr<leaf::parsing::instance::for_body>& actual, leaf::parsing::instance::for_body_state& state, size_t depth);
        bool m_roundbracketclose_controlstructurebody_291(bool is_can, std::shared_ptr<leaf::parsing::instance::for_body>& actual, leaf::parsing::instance::for_body_state& state, size_t depth);
        bool p_can_for_body(size_t depth);
        std::shared_ptr<leaf::parsing::instance::for_body> p_match_for_body(size_t depth);
        bool m_for_roundbracketopen_declaration_colon_expression_roundbracketclose_controlstructurebody_292(bool is_can, std::shared_ptr<leaf::parsing::instance::for_each_body>& actual, leaf::parsing::instance::for_each_body_state& state, size_t depth);
        bool p_can_for_each_body(size_t depth);
        std::shared_ptr<leaf::parsing::instance::for_each_body> p_match_for_each_body(size_t depth);
        bool m_ifbody_293(bool is_can, std::shared_ptr<leaf::parsing::instance::if_else>& actual, leaf::parsing::instance::if_else_state& state, size_t depth);
        bool m_elsebody_294(bool is_can, std::shared_ptr<leaf::parsing::instance::if_else>& actual, leaf::parsing::instance::if_else_state& state, size_t depth);
        bool m_elsebody_295(bool is_can, std::shared_ptr<leaf::parsing::instance::if_else>& actual, leaf::parsing::instance::if_else_state& state, size_t depth);
        bool if296_297(bool is_can, std::shared_ptr<leaf::parsing::instance::if_else>& actual, leaf::parsing::instance::if_else_state& state, size_t depth);
        bool p_can_if_else(size_t depth);
        std::shared_ptr<leaf::parsing::instance::if_else> p_match_if_else(size_t depth);
        bool m_case_expvalue_colon_controlstructurebody_298(bool is_can, std::shared_ptr<leaf::parsing::instance::switch_case>& actual, leaf::parsing::instance::switch_case_state& state, size_t depth);
        bool p_can_switch_case(size_t depth);
        std::shared_ptr<leaf::parsing::instance::switch_case> p_match_switch_case(size_t depth);
        bool m_switch_roundbracketopen_expression_roundbracketclose_299(bool is_can, std::shared_ptr<leaf::parsing::instance::switch_>& actual, leaf::parsing::instance::switch__state& state, size_t depth);
        bool m_curlybracketclose_300(bool is_can, std::shared_ptr<leaf::parsing::instance::switch_>& actual, leaf::parsing::instance::switch__state& state, size_t depth);
        bool m_switchcase_301(bool is_can, std::shared_ptr<leaf::parsing::instance::switch_>& actual, leaf::parsing::instance::switch__state& state, size_t depth);
        bool if302_303(bool is_can, std::shared_ptr<leaf::parsing::instance::switch_>& actual, leaf::parsing::instance::switch__state& state, size_t depth);
        bool m_default_colon_controlstructurebody_304(bool is_can, std::shared_ptr<leaf::parsing::instance::switch_>& actual, leaf::parsing::instance::switch__state& state, size_t depth);
        bool m_pragma_305(bool is_can, std::shared_ptr<leaf::parsing::instance::switch_>& actual, leaf::parsing::instance::switch__state& state, size_t depth);
        bool alternatives306(bool is_can, std::shared_ptr<leaf::parsing::instance::switch_>& actual, leaf::parsing::instance::switch__state& state, size_t depth);
        bool while307_308(bool is_can, std::shared_ptr<leaf::parsing::instance::switch_>& actual, leaf::parsing::instance::switch__state& state, size_t depth);
        bool m_curlybracketclose_309(bool is_can, std::shared_ptr<leaf::parsing::instance::switch_>& actual, leaf::parsing::instance::switch__state& state, size_t depth);
        bool p_can_switch_(size_t depth);
        std::shared_ptr<leaf::parsing::instance::switch_> p_match_switch_(size_t depth);
        bool m_eol_310(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly_terminate>& actual, leaf::parsing::instance::assembly_terminate_state& state, size_t depth);
        bool m_curlybracketclose_311(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly_terminate>& actual, leaf::parsing::instance::assembly_terminate_state& state, size_t depth);
        bool alternatives312(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly_terminate>& actual, leaf::parsing::instance::assembly_terminate_state& state, size_t depth);
        bool p_can_assembly_terminate(size_t depth);
        std::shared_ptr<leaf::parsing::instance::assembly_terminate> p_match_assembly_terminate(size_t depth);
        bool m_assembly_curlybracketopen_313(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth);
        bool m_curlybracketclose_314(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth);
        bool m_assemblyterminate_315(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth);
        bool m_scalar_316(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth);
        bool m_integerbinary_317(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth);
        bool m_integerhex_318(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth);
        bool m_integer_319(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth);
        bool alternatives320(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth);
        bool while321_322(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth);
        bool m_ident_323(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth);
        bool while324_325(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth);
        bool m_curlybracketclose_326(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth);
        bool p_can_assembly(size_t depth);
        std::shared_ptr<leaf::parsing::instance::assembly> p_match_assembly(size_t depth);
        bool m_pragma_327(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure>& actual, leaf::parsing::instance::control_structure_state& state, size_t depth);
        bool m_whileloop_328(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure>& actual, leaf::parsing::instance::control_structure_state& state, size_t depth);
        bool m_forbody_329(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure>& actual, leaf::parsing::instance::control_structure_state& state, size_t depth);
        bool m_foreachbody_330(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure>& actual, leaf::parsing::instance::control_structure_state& state, size_t depth);
        bool m_ifelse_331(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure>& actual, leaf::parsing::instance::control_structure_state& state, size_t depth);
        bool m_switch_332(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure>& actual, leaf::parsing::instance::control_structure_state& state, size_t depth);
        bool m_scope_333(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure>& actual, leaf::parsing::instance::control_structure_state& state, size_t depth);
        bool m_assembly_334(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure>& actual, leaf::parsing::instance::control_structure_state& state, size_t depth);
        bool alternatives335(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure>& actual, leaf::parsing::instance::control_structure_state& state, size_t depth);
        bool p_can_control_structure(size_t depth);
        std::shared_ptr<leaf::parsing::instance::control_structure> p_match_control_structure(size_t depth);
        bool m_alloc_336(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_chain_start>& actual, leaf::parsing::instance::exp_chain_start_state& state, size_t depth);
        bool m_free_337(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_chain_start>& actual, leaf::parsing::instance::exp_chain_start_state& state, size_t depth);
        bool m_call_338(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_chain_start>& actual, leaf::parsing::instance::exp_chain_start_state& state, size_t depth);
        bool m_ident_339(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_chain_start>& actual, leaf::parsing::instance::exp_chain_start_state& state, size_t depth);
        bool alternatives340(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_chain_start>& actual, leaf::parsing::instance::exp_chain_start_state& state, size_t depth);
        bool p_can_exp_chain_start(size_t depth);
        std::shared_ptr<leaf::parsing::instance::exp_chain_start> p_match_exp_chain_start(size_t depth);
        bool m_typeof_341(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth);
        bool m_nameof_342(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth);
        bool m_sizeof_343(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth);
        bool m_scalar_344(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth);
        bool m_false_345(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth);
        bool m_true_346(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth);
        bool m_integerhex_347(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth);
        bool m_integerbinary_348(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth);
        bool m_integer_349(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth);
        bool m_string_350(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth);
        bool m_char_351(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth);
        bool alternatives352(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth);
        bool p_can_exp_constant(size_t depth);
        std::shared_ptr<leaf::parsing::instance::exp_constant> p_match_exp_constant(size_t depth);
        bool m_capturelist_methodarglist_scopelambda_353(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_lambda>& actual, leaf::parsing::instance::exp_lambda_state& state, size_t depth);
        bool m_methodarglist_scopelambda_354(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_lambda>& actual, leaf::parsing::instance::exp_lambda_state& state, size_t depth);
        bool alternatives355(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_lambda>& actual, leaf::parsing::instance::exp_lambda_state& state, size_t depth);
        bool p_can_exp_lambda(size_t depth);
        std::shared_ptr<leaf::parsing::instance::exp_lambda> p_match_exp_lambda(size_t depth);
        bool m_copy_356(bool is_can, std::shared_ptr<leaf::parsing::instance::capture_list_item>& actual, leaf::parsing::instance::capture_list_item_state& state, size_t depth);
        bool alternatives357(bool is_can, std::shared_ptr<leaf::parsing::instance::capture_list_item>& actual, leaf::parsing::instance::capture_list_item_state& state, size_t depth);
        bool m_ident_358(bool is_can, std::shared_ptr<leaf::parsing::instance::capture_list_item>& actual, leaf::parsing::instance::capture_list_item_state& state, size_t depth);
        bool p_can_capture_list_item(size_t depth);
        std::shared_ptr<leaf::parsing::instance::capture_list_item> p_match_capture_list_item(size_t depth);
        bool m_squarebracketopen_359(bool is_can, std::shared_ptr<leaf::parsing::instance::capture_list>& actual, leaf::parsing::instance::capture_list_state& state, size_t depth);
        bool m_capturelistitem_360(bool is_can, std::shared_ptr<leaf::parsing::instance::capture_list>& actual, leaf::parsing::instance::capture_list_state& state, size_t depth);
        bool m_capturelistitem_361(bool is_can, std::shared_ptr<leaf::parsing::instance::capture_list>& actual, leaf::parsing::instance::capture_list_state& state, size_t depth);
        bool m_capturelistitem_362(bool is_can, std::shared_ptr<leaf::parsing::instance::capture_list>& actual, leaf::parsing::instance::capture_list_state& state, size_t depth);
        bool m_comma_capturelistitem_363(bool is_can, std::shared_ptr<leaf::parsing::instance::capture_list>& actual, leaf::parsing::instance::capture_list_state& state, size_t depth);
        bool while364_365(bool is_can, std::shared_ptr<leaf::parsing::instance::capture_list>& actual, leaf::parsing::instance::capture_list_state& state, size_t depth);
        bool m_comma_366(bool is_can, std::shared_ptr<leaf::parsing::instance::capture_list>& actual, leaf::parsing::instance::capture_list_state& state, size_t depth);
        bool m_comma_367(bool is_can, std::shared_ptr<leaf::parsing::instance::capture_list>& actual, leaf::parsing::instance::capture_list_state& state, size_t depth);
        bool if368_369(bool is_can, std::shared_ptr<leaf::parsing::instance::capture_list>& actual, leaf::parsing::instance::capture_list_state& state, size_t depth);
        bool if370_371(bool is_can, std::shared_ptr<leaf::parsing::instance::capture_list>& actual, leaf::parsing::instance::capture_list_state& state, size_t depth);
        bool m_squarebracketclose_372(bool is_can, std::shared_ptr<leaf::parsing::instance::capture_list>& actual, leaf::parsing::instance::capture_list_state& state, size_t depth);
        bool p_can_capture_list(size_t depth);
        std::shared_ptr<leaf::parsing::instance::capture_list> p_match_capture_list(size_t depth);
        bool m_explambda_373(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_value>& actual, leaf::parsing::instance::exp_value_state& state, size_t depth);
        bool m_expconstant_374(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_value>& actual, leaf::parsing::instance::exp_value_state& state, size_t depth);
        bool m_scalarliteral_375(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_value>& actual, leaf::parsing::instance::exp_value_state& state, size_t depth);
        bool m_integerhexliteral_376(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_value>& actual, leaf::parsing::instance::exp_value_state& state, size_t depth);
        bool m_integerbinaryliteral_377(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_value>& actual, leaf::parsing::instance::exp_value_state& state, size_t depth);
        bool m_integerliteral_378(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_value>& actual, leaf::parsing::instance::exp_value_state& state, size_t depth);
        bool m_charliteral_379(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_value>& actual, leaf::parsing::instance::exp_value_state& state, size_t depth);
        bool m_stringliteral_380(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_value>& actual, leaf::parsing::instance::exp_value_state& state, size_t depth);
        bool m_expconstant_381(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_value>& actual, leaf::parsing::instance::exp_value_state& state, size_t depth);
        bool alternatives382(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_value>& actual, leaf::parsing::instance::exp_value_state& state, size_t depth);
        bool p_can_exp_value(size_t depth);
        std::shared_ptr<leaf::parsing::instance::exp_value> p_match_exp_value(size_t depth);
        bool m_roundbracketopen_expression_roundbracketclose_383(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_nullar>& actual, leaf::parsing::instance::exp_nullar_state& state, size_t depth);
        bool m_expchain_384(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_nullar>& actual, leaf::parsing::instance::exp_nullar_state& state, size_t depth);
        bool m_expvalue_385(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_nullar>& actual, leaf::parsing::instance::exp_nullar_state& state, size_t depth);
        bool alternatives386(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_nullar>& actual, leaf::parsing::instance::exp_nullar_state& state, size_t depth);
        bool p_can_exp_nullar(size_t depth);
        std::shared_ptr<leaf::parsing::instance::exp_nullar> p_match_exp_nullar(size_t depth);
        bool m_exclamation_expunary_387(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_unary>& actual, leaf::parsing::instance::exp_unary_state& state, size_t depth);
        bool m_tilde_expunary_388(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_unary>& actual, leaf::parsing::instance::exp_unary_state& state, size_t depth);
        bool m_minus_expunary_389(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_unary>& actual, leaf::parsing::instance::exp_unary_state& state, size_t depth);
        bool m_plus_expunary_390(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_unary>& actual, leaf::parsing::instance::exp_unary_state& state, size_t depth);
        bool m_roundbracketopen_typematch_roundbracketclose_expunary_391(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_unary>& actual, leaf::parsing::instance::exp_unary_state& state, size_t depth);
        bool m_expnullar_392(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_unary>& actual, leaf::parsing::instance::exp_unary_state& state, size_t depth);
        bool alternatives393(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_unary>& actual, leaf::parsing::instance::exp_unary_state& state, size_t depth);
        bool p_can_exp_unary(size_t depth);
        std::shared_ptr<leaf::parsing::instance::exp_unary> p_match_exp_unary(size_t depth);
        bool m_expor_equal_expression_394(bool is_can, std::shared_ptr<leaf::parsing::instance::expression>& actual, leaf::parsing::instance::expression_state& state, size_t depth);
        bool m_expor_395(bool is_can, std::shared_ptr<leaf::parsing::instance::expression>& actual, leaf::parsing::instance::expression_state& state, size_t depth);
        bool p_can_expression(size_t depth);
        std::shared_ptr<leaf::parsing::instance::expression> p_match_expression(size_t depth);
        bool m_public_396(bool is_can, std::shared_ptr<leaf::parsing::instance::encapsulation>& actual, leaf::parsing::instance::encapsulation_state& state, size_t depth);
        bool m_local_397(bool is_can, std::shared_ptr<leaf::parsing::instance::encapsulation>& actual, leaf::parsing::instance::encapsulation_state& state, size_t depth);
        bool m_derived_398(bool is_can, std::shared_ptr<leaf::parsing::instance::encapsulation>& actual, leaf::parsing::instance::encapsulation_state& state, size_t depth);
        bool m_private_399(bool is_can, std::shared_ptr<leaf::parsing::instance::encapsulation>& actual, leaf::parsing::instance::encapsulation_state& state, size_t depth);
        bool alternatives400(bool is_can, std::shared_ptr<leaf::parsing::instance::encapsulation>& actual, leaf::parsing::instance::encapsulation_state& state, size_t depth);
        bool p_can_encapsulation(size_t depth);
        std::shared_ptr<leaf::parsing::instance::encapsulation> p_match_encapsulation(size_t depth);
        bool m_attribute_401(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool m_attribute_402(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool while403_404(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool m_namespace_identnavigation_405(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool m_curlybracketopen_406(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool m_curlybracketclose_407(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool m_contract_408(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool m_aliasencapsulated_409(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool m_constant_410(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool m_using_411(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool m_namespace_412(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool m_conversion_413(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool m_class_414(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool m_method_415(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool m_property_416(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool m_field_417(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool m_pragma_418(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool alternatives419(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool while420_421(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool m_curlybracketclose_422(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool p_can_namespace_(size_t depth);
        std::shared_ptr<leaf::parsing::instance::namespace_> p_match_namespace_(size_t depth);
        bool m_attribute_423(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_attribute_424(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool while425_426(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_encapsulation_class_ident_427(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_templatedefinition_428(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_templatedefinition_429(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool if430_431(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_lifetime_432(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_lifetime_433(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool if434_435(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_curlybracketopen_436(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_curlybracketclose_437(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_contract_438(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_aliasencapsulated_439(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_constant_440(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_using_441(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_indexer_442(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_operatorbinaryoverload_443(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_operatorunaryoverload_444(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_operatornullaroverload_445(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_conversion_446(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_class_447(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_constructor_448(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_destructor_449(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_copystructor_450(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_property_451(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_field_452(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_method_453(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_pragma_454(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool alternatives455(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool while456_457(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_curlybracketclose_458(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool p_can_class_(size_t depth);
        std::shared_ptr<leaf::parsing::instance::class_> p_match_class_(size_t depth);
        bool m_attribute_459(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_item>& actual, leaf::parsing::instance::method_arglist_item_state& state, size_t depth);
        bool m_attribute_460(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_item>& actual, leaf::parsing::instance::method_arglist_item_state& state, size_t depth);
        bool while461_462(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_item>& actual, leaf::parsing::instance::method_arglist_item_state& state, size_t depth);
        bool m_typematch_ident_463(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_item>& actual, leaf::parsing::instance::method_arglist_item_state& state, size_t depth);
        bool p_can_method_arglist_item(size_t depth);
        std::shared_ptr<leaf::parsing::instance::method_arglist_item> p_match_method_arglist_item(size_t depth);
        bool m_roundbracketopen_464(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth);
        bool m_methodarglistitem_465(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth);
        bool m_methodarglistitem_466(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth);
        bool m_roundbracketclose_467(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth);
        bool m_comma_methodarglistitem_468(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth);
        bool alternatives469(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth);
        bool while470_471(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth);
        bool m_comma_472(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth);
        bool m_comma_473(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth);
        bool if474_475(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth);
        bool if476_477(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth);
        bool m_roundbracketclose_478(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth);
        bool p_can_method_arglist(size_t depth);
        std::shared_ptr<leaf::parsing::instance::method_arglist> p_match_method_arglist(size_t depth);
        bool m_squarebracketopen_479(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_indexer>& actual, leaf::parsing::instance::method_arglist_indexer_state& state, size_t depth);
        bool m_methodarglistitem_480(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_indexer>& actual, leaf::parsing::instance::method_arglist_indexer_state& state, size_t depth);
        bool m_squarebracketclose_481(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_indexer>& actual, leaf::parsing::instance::method_arglist_indexer_state& state, size_t depth);
        bool m_comma_methodarglistitem_482(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_indexer>& actual, leaf::parsing::instance::method_arglist_indexer_state& state, size_t depth);
        bool alternatives483(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_indexer>& actual, leaf::parsing::instance::method_arglist_indexer_state& state, size_t depth);
        bool while484_485(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_indexer>& actual, leaf::parsing::instance::method_arglist_indexer_state& state, size_t depth);
        bool m_comma_486(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_indexer>& actual, leaf::parsing::instance::method_arglist_indexer_state& state, size_t depth);
        bool m_comma_487(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_indexer>& actual, leaf::parsing::instance::method_arglist_indexer_state& state, size_t depth);
        bool if488_489(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_indexer>& actual, leaf::parsing::instance::method_arglist_indexer_state& state, size_t depth);
        bool m_squarebracketclose_490(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_indexer>& actual, leaf::parsing::instance::method_arglist_indexer_state& state, size_t depth);
        bool p_can_method_arglist_indexer(size_t depth);
        std::shared_ptr<leaf::parsing::instance::method_arglist_indexer> p_match_method_arglist_indexer(size_t depth);
        bool m_encapsulation_491(bool is_can, std::shared_ptr<leaf::parsing::instance::method_meta>& actual, leaf::parsing::instance::method_meta_state& state, size_t depth);
        bool m_sealed_492(bool is_can, std::shared_ptr<leaf::parsing::instance::method_meta>& actual, leaf::parsing::instance::method_meta_state& state, size_t depth);
        bool m_sealed_493(bool is_can, std::shared_ptr<leaf::parsing::instance::method_meta>& actual, leaf::parsing::instance::method_meta_state& state, size_t depth);
        bool if494_495(bool is_can, std::shared_ptr<leaf::parsing::instance::method_meta>& actual, leaf::parsing::instance::method_meta_state& state, size_t depth);
        bool m_virtual_496(bool is_can, std::shared_ptr<leaf::parsing::instance::method_meta>& actual, leaf::parsing::instance::method_meta_state& state, size_t depth);
        bool m_virtual_497(bool is_can, std::shared_ptr<leaf::parsing::instance::method_meta>& actual, leaf::parsing::instance::method_meta_state& state, size_t depth);
        bool if498_499(bool is_can, std::shared_ptr<leaf::parsing::instance::method_meta>& actual, leaf::parsing::instance::method_meta_state& state, size_t depth);
        bool m_unbound_500(bool is_can, std::shared_ptr<leaf::parsing::instance::method_meta>& actual, leaf::parsing::instance::method_meta_state& state, size_t depth);
        bool m_unbound_501(bool is_can, std::shared_ptr<leaf::parsing::instance::method_meta>& actual, leaf::parsing::instance::method_meta_state& state, size_t depth);
        bool if502_503(bool is_can, std::shared_ptr<leaf::parsing::instance::method_meta>& actual, leaf::parsing::instance::method_meta_state& state, size_t depth);
        bool m_inline_504(bool is_can, std::shared_ptr<leaf::parsing::instance::method_meta>& actual, leaf::parsing::instance::method_meta_state& state, size_t depth);
        bool m_inline_505(bool is_can, std::shared_ptr<leaf::parsing::instance::method_meta>& actual, leaf::parsing::instance::method_meta_state& state, size_t depth);
        bool if506_507(bool is_can, std::shared_ptr<leaf::parsing::instance::method_meta>& actual, leaf::parsing::instance::method_meta_state& state, size_t depth);
        bool p_can_method_meta(size_t depth);
        std::shared_ptr<leaf::parsing::instance::method_meta> p_match_method_meta(size_t depth);
        bool m_attribute_508(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth);
        bool m_attribute_509(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth);
        bool while510_511(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth);
        bool m_methodmeta_typematch_ident_512(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth);
        bool m_templatedefinition_513(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth);
        bool m_templatedefinition_514(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth);
        bool if515_516(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth);
        bool m_methodarglist_scope_517(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth);
        bool p_can_method(size_t depth);
        std::shared_ptr<leaf::parsing::instance::method> p_match_method(size_t depth);
        bool m_attribute_518(bool is_can, std::shared_ptr<leaf::parsing::instance::constructor>& actual, leaf::parsing::instance::constructor_state& state, size_t depth);
        bool m_attribute_519(bool is_can, std::shared_ptr<leaf::parsing::instance::constructor>& actual, leaf::parsing::instance::constructor_state& state, size_t depth);
        bool while520_521(bool is_can, std::shared_ptr<leaf::parsing::instance::constructor>& actual, leaf::parsing::instance::constructor_state& state, size_t depth);
        bool m_encapsulation_522(bool is_can, std::shared_ptr<leaf::parsing::instance::constructor>& actual, leaf::parsing::instance::constructor_state& state, size_t depth);
        bool m_templatedefinition_523(bool is_can, std::shared_ptr<leaf::parsing::instance::constructor>& actual, leaf::parsing::instance::constructor_state& state, size_t depth);
        bool m_templatedefinition_524(bool is_can, std::shared_ptr<leaf::parsing::instance::constructor>& actual, leaf::parsing::instance::constructor_state& state, size_t depth);
        bool if525_526(bool is_can, std::shared_ptr<leaf::parsing::instance::constructor>& actual, leaf::parsing::instance::constructor_state& state, size_t depth);
        bool m_methodarglist_scope_527(bool is_can, std::shared_ptr<leaf::parsing::instance::constructor>& actual, leaf::parsing::instance::constructor_state& state, size_t depth);
        bool p_can_constructor(size_t depth);
        std::shared_ptr<leaf::parsing::instance::constructor> p_match_constructor(size_t depth);
        bool m_attribute_528(bool is_can, std::shared_ptr<leaf::parsing::instance::destructor>& actual, leaf::parsing::instance::destructor_state& state, size_t depth);
        bool m_attribute_529(bool is_can, std::shared_ptr<leaf::parsing::instance::destructor>& actual, leaf::parsing::instance::destructor_state& state, size_t depth);
        bool while530_531(bool is_can, std::shared_ptr<leaf::parsing::instance::destructor>& actual, leaf::parsing::instance::destructor_state& state, size_t depth);
        bool m_encapsulation_tilde_532(bool is_can, std::shared_ptr<leaf::parsing::instance::destructor>& actual, leaf::parsing::instance::destructor_state& state, size_t depth);
        bool m_templatedefinition_533(bool is_can, std::shared_ptr<leaf::parsing::instance::destructor>& actual, leaf::parsing::instance::destructor_state& state, size_t depth);
        bool m_templatedefinition_534(bool is_can, std::shared_ptr<leaf::parsing::instance::destructor>& actual, leaf::parsing::instance::destructor_state& state, size_t depth);
        bool if535_536(bool is_can, std::shared_ptr<leaf::parsing::instance::destructor>& actual, leaf::parsing::instance::destructor_state& state, size_t depth);
        bool m_methodarglist_scope_537(bool is_can, std::shared_ptr<leaf::parsing::instance::destructor>& actual, leaf::parsing::instance::destructor_state& state, size_t depth);
        bool p_can_destructor(size_t depth);
        std::shared_ptr<leaf::parsing::instance::destructor> p_match_destructor(size_t depth);
        bool m_attribute_538(bool is_can, std::shared_ptr<leaf::parsing::instance::copystructor>& actual, leaf::parsing::instance::copystructor_state& state, size_t depth);
        bool m_attribute_539(bool is_can, std::shared_ptr<leaf::parsing::instance::copystructor>& actual, leaf::parsing::instance::copystructor_state& state, size_t depth);
        bool while540_541(bool is_can, std::shared_ptr<leaf::parsing::instance::copystructor>& actual, leaf::parsing::instance::copystructor_state& state, size_t depth);
        bool m_encapsulation_plus_542(bool is_can, std::shared_ptr<leaf::parsing::instance::copystructor>& actual, leaf::parsing::instance::copystructor_state& state, size_t depth);
        bool m_templatedefinition_543(bool is_can, std::shared_ptr<leaf::parsing::instance::copystructor>& actual, leaf::parsing::instance::copystructor_state& state, size_t depth);
        bool m_templatedefinition_544(bool is_can, std::shared_ptr<leaf::parsing::instance::copystructor>& actual, leaf::parsing::instance::copystructor_state& state, size_t depth);
        bool if545_546(bool is_can, std::shared_ptr<leaf::parsing::instance::copystructor>& actual, leaf::parsing::instance::copystructor_state& state, size_t depth);
        bool m_methodarglist_547(bool is_can, std::shared_ptr<leaf::parsing::instance::copystructor>& actual, leaf::parsing::instance::copystructor_state& state, size_t depth);
        bool m_scope_548(bool is_can, std::shared_ptr<leaf::parsing::instance::copystructor>& actual, leaf::parsing::instance::copystructor_state& state, size_t depth);
        bool m_equal_delete_549(bool is_can, std::shared_ptr<leaf::parsing::instance::copystructor>& actual, leaf::parsing::instance::copystructor_state& state, size_t depth);
        bool alternatives550(bool is_can, std::shared_ptr<leaf::parsing::instance::copystructor>& actual, leaf::parsing::instance::copystructor_state& state, size_t depth);
        bool p_can_copystructor(size_t depth);
        std::shared_ptr<leaf::parsing::instance::copystructor> p_match_copystructor(size_t depth);
        bool m_attribute_551(bool is_can, std::shared_ptr<leaf::parsing::instance::conversion>& actual, leaf::parsing::instance::conversion_state& state, size_t depth);
        bool m_attribute_552(bool is_can, std::shared_ptr<leaf::parsing::instance::conversion>& actual, leaf::parsing::instance::conversion_state& state, size_t depth);
        bool while553_554(bool is_can, std::shared_ptr<leaf::parsing::instance::conversion>& actual, leaf::parsing::instance::conversion_state& state, size_t depth);
        bool m_methodmeta_conversion_typematch_555(bool is_can, std::shared_ptr<leaf::parsing::instance::conversion>& actual, leaf::parsing::instance::conversion_state& state, size_t depth);
        bool m_roundbracketopen_typematch_ident_roundbracketclose_556(bool is_can, std::shared_ptr<leaf::parsing::instance::conversion>& actual, leaf::parsing::instance::conversion_state& state, size_t depth);
        bool m_scope_557(bool is_can, std::shared_ptr<leaf::parsing::instance::conversion>& actual, leaf::parsing::instance::conversion_state& state, size_t depth);
        bool p_can_conversion(size_t depth);
        std::shared_ptr<leaf::parsing::instance::conversion> p_match_conversion(size_t depth);
        bool m_attribute_558(bool is_can, std::shared_ptr<leaf::parsing::instance::indexer>& actual, leaf::parsing::instance::indexer_state& state, size_t depth);
        bool m_attribute_559(bool is_can, std::shared_ptr<leaf::parsing::instance::indexer>& actual, leaf::parsing::instance::indexer_state& state, size_t depth);
        bool while560_561(bool is_can, std::shared_ptr<leaf::parsing::instance::indexer>& actual, leaf::parsing::instance::indexer_state& state, size_t depth);
        bool m_methodmeta_typematch_562(bool is_can, std::shared_ptr<leaf::parsing::instance::indexer>& actual, leaf::parsing::instance::indexer_state& state, size_t depth);
        bool m_templatedefinition_563(bool is_can, std::shared_ptr<leaf::parsing::instance::indexer>& actual, leaf::parsing::instance::indexer_state& state, size_t depth);
        bool m_templatedefinition_564(bool is_can, std::shared_ptr<leaf::parsing::instance::indexer>& actual, leaf::parsing::instance::indexer_state& state, size_t depth);
        bool if565_566(bool is_can, std::shared_ptr<leaf::parsing::instance::indexer>& actual, leaf::parsing::instance::indexer_state& state, size_t depth);
        bool m_methodarglistindexer_scopegetset_567(bool is_can, std::shared_ptr<leaf::parsing::instance::indexer>& actual, leaf::parsing::instance::indexer_state& state, size_t depth);
        bool p_can_indexer(size_t depth);
        std::shared_ptr<leaf::parsing::instance::indexer> p_match_indexer(size_t depth);
        bool m_attribute_568(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_attribute_569(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool while570_571(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_methodmeta_typematch_operator_572(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_templatedefinition_573(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_templatedefinition_574(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool if575_576(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_roundbracketopen_methodarglistitem_roundbracketclose_577(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_plus_578(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_minus_579(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_star_580(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_slash_581(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_lessthenlessthenlessthen_582(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_lessthenlessthen_583(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_lessthenequal_584(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_lessthen_585(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_greaterthengreaterthengreaterthen_586(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_greaterthengreaterthen_587(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_greaterthenequal_588(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_greaterthen_589(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_verticalbarverticalbar_590(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_verticalbar_591(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_ampersandampersand_592(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_ampersand_593(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_equalequalequal_594(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_equalequal_595(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_exclamationequal_596(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_circumflex_597(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool alternatives598(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_roundbracketopen_methodarglistitem_roundbracketclose_599(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_scope_600(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool p_can_operator_binary_overload(size_t depth);
        std::shared_ptr<leaf::parsing::instance::operator_binary_overload> p_match_operator_binary_overload(size_t depth);
        bool m_attribute_601(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth);
        bool m_attribute_602(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth);
        bool while603_604(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth);
        bool m_methodmeta_typematch_operator_605(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth);
        bool m_templatedefinition_606(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth);
        bool m_templatedefinition_607(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth);
        bool if608_609(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth);
        bool m_plus_610(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth);
        bool m_minus_611(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth);
        bool m_exclamation_612(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth);
        bool m_tilde_613(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth);
        bool alternatives614(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth);
        bool m_roundbracketopen_methodarglistitem_roundbracketclose_615(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth);
        bool m_scope_616(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth);
        bool p_can_operator_unary_overload(size_t depth);
        std::shared_ptr<leaf::parsing::instance::operator_unary_overload> p_match_operator_unary_overload(size_t depth);
        bool m_attribute_617(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_nullar_overload>& actual, leaf::parsing::instance::operator_nullar_overload_state& state, size_t depth);
        bool m_attribute_618(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_nullar_overload>& actual, leaf::parsing::instance::operator_nullar_overload_state& state, size_t depth);
        bool while619_620(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_nullar_overload>& actual, leaf::parsing::instance::operator_nullar_overload_state& state, size_t depth);
        bool m_methodmeta_operator_621(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_nullar_overload>& actual, leaf::parsing::instance::operator_nullar_overload_state& state, size_t depth);
        bool m_templatedefinition_622(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_nullar_overload>& actual, leaf::parsing::instance::operator_nullar_overload_state& state, size_t depth);
        bool m_templatedefinition_623(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_nullar_overload>& actual, leaf::parsing::instance::operator_nullar_overload_state& state, size_t depth);
        bool if624_625(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_nullar_overload>& actual, leaf::parsing::instance::operator_nullar_overload_state& state, size_t depth);
        bool m_dot_626(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_nullar_overload>& actual, leaf::parsing::instance::operator_nullar_overload_state& state, size_t depth);
        bool m_minusgreaterthen_627(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_nullar_overload>& actual, leaf::parsing::instance::operator_nullar_overload_state& state, size_t depth);
        bool alternatives628(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_nullar_overload>& actual, leaf::parsing::instance::operator_nullar_overload_state& state, size_t depth);
        bool m_scope_629(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_nullar_overload>& actual, leaf::parsing::instance::operator_nullar_overload_state& state, size_t depth);
        bool p_can_operator_nullar_overload(size_t depth);
        std::shared_ptr<leaf::parsing::instance::operator_nullar_overload> p_match_operator_nullar_overload(size_t depth);
        bool m_attribute_630(bool is_can, std::shared_ptr<leaf::parsing::instance::property>& actual, leaf::parsing::instance::property_state& state, size_t depth);
        bool m_attribute_631(bool is_can, std::shared_ptr<leaf::parsing::instance::property>& actual, leaf::parsing::instance::property_state& state, size_t depth);
        bool while632_633(bool is_can, std::shared_ptr<leaf::parsing::instance::property>& actual, leaf::parsing::instance::property_state& state, size_t depth);
        bool m_methodmeta_typematch_ident_scopegetset_634(bool is_can, std::shared_ptr<leaf::parsing::instance::property>& actual, leaf::parsing::instance::property_state& state, size_t depth);
        bool p_can_property(size_t depth);
        std::shared_ptr<leaf::parsing::instance::property> p_match_property(size_t depth);
        bool m_attribute_635(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth);
        bool m_attribute_636(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth);
        bool while637_638(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth);
        bool m_encapsulation_639(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth);
        bool m_unbound_640(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth);
        bool m_unbound_641(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth);
        bool if642_643(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth);
        bool m_typematch_ident_semicolon_644(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth);
        bool p_can_field(size_t depth);
        std::shared_ptr<leaf::parsing::instance::field> p_match_field(size_t depth);
        bool m_const_typematch_ident_equal_expor_semicolon_645(bool is_can, std::shared_ptr<leaf::parsing::instance::constant>& actual, leaf::parsing::instance::constant_state& state, size_t depth);
        bool p_can_constant(size_t depth);
        std::shared_ptr<leaf::parsing::instance::constant> p_match_constant(size_t depth);
        bool m_using_646(bool is_can, std::shared_ptr<leaf::parsing::instance::using_>& actual, leaf::parsing::instance::using__state& state, size_t depth);
        bool m_namespace_identnavigation_647(bool is_can, std::shared_ptr<leaf::parsing::instance::using_>& actual, leaf::parsing::instance::using__state& state, size_t depth);
        bool m_class_identnavigation_648(bool is_can, std::shared_ptr<leaf::parsing::instance::using_>& actual, leaf::parsing::instance::using__state& state, size_t depth);
        bool alternatives649(bool is_can, std::shared_ptr<leaf::parsing::instance::using_>& actual, leaf::parsing::instance::using__state& state, size_t depth);
        bool m_equal_650(bool is_can, std::shared_ptr<leaf::parsing::instance::using_>& actual, leaf::parsing::instance::using__state& state, size_t depth);
        bool m_equal_ident_651(bool is_can, std::shared_ptr<leaf::parsing::instance::using_>& actual, leaf::parsing::instance::using__state& state, size_t depth);
        bool if652_653(bool is_can, std::shared_ptr<leaf::parsing::instance::using_>& actual, leaf::parsing::instance::using__state& state, size_t depth);
        bool p_can_using_(size_t depth);
        std::shared_ptr<leaf::parsing::instance::using_> p_match_using_(size_t depth);
        bool m_encapsulation_alias_654(bool is_can, std::shared_ptr<leaf::parsing::instance::alias_encapsulated>& actual, leaf::parsing::instance::alias_encapsulated_state& state, size_t depth);
        bool p_can_alias_encapsulated(size_t depth);
        std::shared_ptr<leaf::parsing::instance::alias_encapsulated> p_match_alias_encapsulated(size_t depth);
        bool m_alias_ident_equal_typematch_655(bool is_can, std::shared_ptr<leaf::parsing::instance::alias>& actual, leaf::parsing::instance::alias_state& state, size_t depth);
        bool p_can_alias(size_t depth);
        std::shared_ptr<leaf::parsing::instance::alias> p_match_alias(size_t depth);
        bool m_ident_callbody_656(bool is_can, std::shared_ptr<leaf::parsing::instance::call>& actual, leaf::parsing::instance::call_state& state, size_t depth);
        bool p_can_call(size_t depth);
        std::shared_ptr<leaf::parsing::instance::call> p_match_call(size_t depth);
        bool m_roundbracketopen_657(bool is_can, std::shared_ptr<leaf::parsing::instance::call_body>& actual, leaf::parsing::instance::call_body_state& state, size_t depth);
        bool m_expression_658(bool is_can, std::shared_ptr<leaf::parsing::instance::call_body>& actual, leaf::parsing::instance::call_body_state& state, size_t depth);
        bool m_expression_659(bool is_can, std::shared_ptr<leaf::parsing::instance::call_body>& actual, leaf::parsing::instance::call_body_state& state, size_t depth);
        bool m_roundbracketclose_660(bool is_can, std::shared_ptr<leaf::parsing::instance::call_body>& actual, leaf::parsing::instance::call_body_state& state, size_t depth);
        bool m_comma_expression_661(bool is_can, std::shared_ptr<leaf::parsing::instance::call_body>& actual, leaf::parsing::instance::call_body_state& state, size_t depth);
        bool m_comma_662(bool is_can, std::shared_ptr<leaf::parsing::instance::call_body>& actual, leaf::parsing::instance::call_body_state& state, size_t depth);
        bool alternatives663(bool is_can, std::shared_ptr<leaf::parsing::instance::call_body>& actual, leaf::parsing::instance::call_body_state& state, size_t depth);
        bool while664_665(bool is_can, std::shared_ptr<leaf::parsing::instance::call_body>& actual, leaf::parsing::instance::call_body_state& state, size_t depth);
        bool if666_667(bool is_can, std::shared_ptr<leaf::parsing::instance::call_body>& actual, leaf::parsing::instance::call_body_state& state, size_t depth);
        bool m_roundbracketclose_668(bool is_can, std::shared_ptr<leaf::parsing::instance::call_body>& actual, leaf::parsing::instance::call_body_state& state, size_t depth);
        bool p_can_call_body(size_t depth);
        std::shared_ptr<leaf::parsing::instance::call_body> p_match_call_body(size_t depth);
        bool m_free_expression_669(bool is_can, std::shared_ptr<leaf::parsing::instance::free>& actual, leaf::parsing::instance::free_state& state, size_t depth);
        bool p_can_free(size_t depth);
        std::shared_ptr<leaf::parsing::instance::free> p_match_free(size_t depth);
        bool m_alloc_stack_typenavigation_squarebracketopen_expression_squarebracketclose_670(bool is_can, std::shared_ptr<leaf::parsing::instance::alloc>& actual, leaf::parsing::instance::alloc_state& state, size_t depth);
        bool m_alloc_stack_typenavigation_callbody_671(bool is_can, std::shared_ptr<leaf::parsing::instance::alloc>& actual, leaf::parsing::instance::alloc_state& state, size_t depth);
        bool m_alloc_heap_typenavigation_squarebracketopen_expression_squarebracketclose_672(bool is_can, std::shared_ptr<leaf::parsing::instance::alloc>& actual, leaf::parsing::instance::alloc_state& state, size_t depth);
        bool m_alloc_heap_typenavigation_callbody_673(bool is_can, std::shared_ptr<leaf::parsing::instance::alloc>& actual, leaf::parsing::instance::alloc_state& state, size_t depth);
        bool alternatives674(bool is_can, std::shared_ptr<leaf::parsing::instance::alloc>& actual, leaf::parsing::instance::alloc_state& state, size_t depth);
        bool p_can_alloc(size_t depth);
        std::shared_ptr<leaf::parsing::instance::alloc> p_match_alloc(size_t depth);
        bool m_typeof_roundbracketopen_typematch_roundbracketclose_675(bool is_can, std::shared_ptr<leaf::parsing::instance::typeof_>& actual, leaf::parsing::instance::typeof__state& state, size_t depth);
        bool p_can_typeof_(size_t depth);
        std::shared_ptr<leaf::parsing::instance::typeof_> p_match_typeof_(size_t depth);
        bool m_nameof_roundbracketopen_expor_roundbracketclose_676(bool is_can, std::shared_ptr<leaf::parsing::instance::nameof>& actual, leaf::parsing::instance::nameof_state& state, size_t depth);
        bool p_can_nameof(size_t depth);
        std::shared_ptr<leaf::parsing::instance::nameof> p_match_nameof(size_t depth);
        bool m_sizeof_roundbracketopen_typematch_roundbracketclose_677(bool is_can, std::shared_ptr<leaf::parsing::instance::sizeof_>& actual, leaf::parsing::instance::sizeof__state& state, size_t depth);
        bool p_can_sizeof_(size_t depth);
        std::shared_ptr<leaf::parsing::instance::sizeof_> p_match_sizeof_(size_t depth);
        bool m_singlequotation_678(bool is_can, std::shared_ptr<leaf::parsing::instance::lifetime>& actual, leaf::parsing::instance::lifetime_state& state, size_t depth);
        bool m_scope_679(bool is_can, std::shared_ptr<leaf::parsing::instance::lifetime>& actual, leaf::parsing::instance::lifetime_state& state, size_t depth);
        bool m_static_680(bool is_can, std::shared_ptr<leaf::parsing::instance::lifetime>& actual, leaf::parsing::instance::lifetime_state& state, size_t depth);
        bool m_ident_681(bool is_can, std::shared_ptr<leaf::parsing::instance::lifetime>& actual, leaf::parsing::instance::lifetime_state& state, size_t depth);
        bool alternatives682(bool is_can, std::shared_ptr<leaf::parsing::instance::lifetime>& actual, leaf::parsing::instance::lifetime_state& state, size_t depth);
        bool p_can_lifetime(size_t depth);
        std::shared_ptr<leaf::parsing::instance::lifetime> p_match_lifetime(size_t depth);
        bool m_typenavigation_squarebracketopen_squarebracketclose_star_lifetime_683(bool is_can, std::shared_ptr<leaf::parsing::instance::type_match>& actual, leaf::parsing::instance::type_match_state& state, size_t depth);
        bool m_typenavigation_star_lifetime_684(bool is_can, std::shared_ptr<leaf::parsing::instance::type_match>& actual, leaf::parsing::instance::type_match_state& state, size_t depth);
        bool m_typenavigation_lifetime_685(bool is_can, std::shared_ptr<leaf::parsing::instance::type_match>& actual, leaf::parsing::instance::type_match_state& state, size_t depth);
        bool m_typenavigation_squarebracketopen_squarebracketclose_star_686(bool is_can, std::shared_ptr<leaf::parsing::instance::type_match>& actual, leaf::parsing::instance::type_match_state& state, size_t depth);
        bool m_typenavigation_star_687(bool is_can, std::shared_ptr<leaf::parsing::instance::type_match>& actual, leaf::parsing::instance::type_match_state& state, size_t depth);
        bool m_typenavigation_688(bool is_can, std::shared_ptr<leaf::parsing::instance::type_match>& actual, leaf::parsing::instance::type_match_state& state, size_t depth);
        bool alternatives689(bool is_can, std::shared_ptr<leaf::parsing::instance::type_match>& actual, leaf::parsing::instance::type_match_state& state, size_t depth);
        bool p_can_type_match(size_t depth);
        std::shared_ptr<leaf::parsing::instance::type_match> p_match_type_match(size_t depth);
        bool m_stringformatablestart_690(bool is_can, std::shared_ptr<leaf::parsing::instance::string_formatable>& actual, leaf::parsing::instance::string_formatable_state& state, size_t depth);
        bool m_expression_691(bool is_can, std::shared_ptr<leaf::parsing::instance::string_formatable>& actual, leaf::parsing::instance::string_formatable_state& state, size_t depth);
        bool m_stringformatableend_692(bool is_can, std::shared_ptr<leaf::parsing::instance::string_formatable>& actual, leaf::parsing::instance::string_formatable_state& state, size_t depth);
        bool m_stringformatablecontinuation_693(bool is_can, std::shared_ptr<leaf::parsing::instance::string_formatable>& actual, leaf::parsing::instance::string_formatable_state& state, size_t depth);
        bool m_expression_694(bool is_can, std::shared_ptr<leaf::parsing::instance::string_formatable>& actual, leaf::parsing::instance::string_formatable_state& state, size_t depth);
        bool while695_696(bool is_can, std::shared_ptr<leaf::parsing::instance::string_formatable>& actual, leaf::parsing::instance::string_formatable_state& state, size_t depth);
        bool m_stringformatableend_697(bool is_can, std::shared_ptr<leaf::parsing::instance::string_formatable>& actual, leaf::parsing::instance::string_formatable_state& state, size_t depth);
        bool p_can_string_formatable(size_t depth);
        std::shared_ptr<leaf::parsing::instance::string_formatable> p_match_string_formatable(size_t depth);
        bool m_ident_stringformatable_ident_698(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth);
        bool m_stringformatable_ident_699(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth);
        bool m_ident_stringformatable_700(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth);
        bool m_stringformatable_701(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth);
        bool m_ident_stringformatablefake_ident_702(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth);
        bool m_stringformatablefake_ident_703(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth);
        bool m_ident_stringformatablefake_704(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth);
        bool m_stringformatablefake_705(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth);
        bool m_ident_string_ident_706(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth);
        bool m_string_ident_707(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth);
        bool m_ident_string_708(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth);
        bool m_string_709(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth);
        bool alternatives710(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth);
        bool p_can_string_literal(size_t depth);
        std::shared_ptr<leaf::parsing::instance::string_literal> p_match_string_literal(size_t depth);
        bool m_ident_scalar_ident_711(bool is_can, std::shared_ptr<leaf::parsing::instance::scalar_literal>& actual, leaf::parsing::instance::scalar_literal_state& state, size_t depth);
        bool m_scalar_ident_712(bool is_can, std::shared_ptr<leaf::parsing::instance::scalar_literal>& actual, leaf::parsing::instance::scalar_literal_state& state, size_t depth);
        bool m_ident_scalar_713(bool is_can, std::shared_ptr<leaf::parsing::instance::scalar_literal>& actual, leaf::parsing::instance::scalar_literal_state& state, size_t depth);
        bool m_scalar_714(bool is_can, std::shared_ptr<leaf::parsing::instance::scalar_literal>& actual, leaf::parsing::instance::scalar_literal_state& state, size_t depth);
        bool alternatives715(bool is_can, std::shared_ptr<leaf::parsing::instance::scalar_literal>& actual, leaf::parsing::instance::scalar_literal_state& state, size_t depth);
        bool p_can_scalar_literal(size_t depth);
        std::shared_ptr<leaf::parsing::instance::scalar_literal> p_match_scalar_literal(size_t depth);
        bool m_ident_integerhex_ident_716(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_hex_literal>& actual, leaf::parsing::instance::integer_hex_literal_state& state, size_t depth);
        bool m_integerhex_ident_717(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_hex_literal>& actual, leaf::parsing::instance::integer_hex_literal_state& state, size_t depth);
        bool m_ident_integerhex_718(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_hex_literal>& actual, leaf::parsing::instance::integer_hex_literal_state& state, size_t depth);
        bool m_integerhex_719(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_hex_literal>& actual, leaf::parsing::instance::integer_hex_literal_state& state, size_t depth);
        bool alternatives720(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_hex_literal>& actual, leaf::parsing::instance::integer_hex_literal_state& state, size_t depth);
        bool p_can_integer_hex_literal(size_t depth);
        std::shared_ptr<leaf::parsing::instance::integer_hex_literal> p_match_integer_hex_literal(size_t depth);
        bool m_ident_integerbinary_ident_721(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_binary_literal>& actual, leaf::parsing::instance::integer_binary_literal_state& state, size_t depth);
        bool m_integerbinary_ident_722(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_binary_literal>& actual, leaf::parsing::instance::integer_binary_literal_state& state, size_t depth);
        bool m_ident_integerbinary_723(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_binary_literal>& actual, leaf::parsing::instance::integer_binary_literal_state& state, size_t depth);
        bool m_integerbinary_724(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_binary_literal>& actual, leaf::parsing::instance::integer_binary_literal_state& state, size_t depth);
        bool alternatives725(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_binary_literal>& actual, leaf::parsing::instance::integer_binary_literal_state& state, size_t depth);
        bool p_can_integer_binary_literal(size_t depth);
        std::shared_ptr<leaf::parsing::instance::integer_binary_literal> p_match_integer_binary_literal(size_t depth);
        bool m_ident_integer_ident_726(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_literal>& actual, leaf::parsing::instance::integer_literal_state& state, size_t depth);
        bool m_integer_ident_727(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_literal>& actual, leaf::parsing::instance::integer_literal_state& state, size_t depth);
        bool m_ident_integer_728(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_literal>& actual, leaf::parsing::instance::integer_literal_state& state, size_t depth);
        bool m_integer_729(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_literal>& actual, leaf::parsing::instance::integer_literal_state& state, size_t depth);
        bool alternatives730(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_literal>& actual, leaf::parsing::instance::integer_literal_state& state, size_t depth);
        bool p_can_integer_literal(size_t depth);
        std::shared_ptr<leaf::parsing::instance::integer_literal> p_match_integer_literal(size_t depth);
        bool m_ident_char_ident_731(bool is_can, std::shared_ptr<leaf::parsing::instance::char_literal>& actual, leaf::parsing::instance::char_literal_state& state, size_t depth);
        bool m_char_ident_732(bool is_can, std::shared_ptr<leaf::parsing::instance::char_literal>& actual, leaf::parsing::instance::char_literal_state& state, size_t depth);
        bool m_ident_char_733(bool is_can, std::shared_ptr<leaf::parsing::instance::char_literal>& actual, leaf::parsing::instance::char_literal_state& state, size_t depth);
        bool m_char_734(bool is_can, std::shared_ptr<leaf::parsing::instance::char_literal>& actual, leaf::parsing::instance::char_literal_state& state, size_t depth);
        bool alternatives735(bool is_can, std::shared_ptr<leaf::parsing::instance::char_literal>& actual, leaf::parsing::instance::char_literal_state& state, size_t depth);
        bool p_can_char_literal(size_t depth);
        std::shared_ptr<leaf::parsing::instance::char_literal> p_match_char_literal(size_t depth);
        bool m_typematch_ident_736(bool is_can, std::shared_ptr<leaf::parsing::instance::declaration>& actual, leaf::parsing::instance::declaration_state& state, size_t depth);
        bool p_can_declaration(size_t depth);
        std::shared_ptr<leaf::parsing::instance::declaration> p_match_declaration(size_t depth);
        bool m_return_semicolon_737(bool is_can, std::shared_ptr<leaf::parsing::instance::return_statement>& actual, leaf::parsing::instance::return_statement_state& state, size_t depth);
        bool m_return_expression_semicolon_738(bool is_can, std::shared_ptr<leaf::parsing::instance::return_statement>& actual, leaf::parsing::instance::return_statement_state& state, size_t depth);
        bool alternatives739(bool is_can, std::shared_ptr<leaf::parsing::instance::return_statement>& actual, leaf::parsing::instance::return_statement_state& state, size_t depth);
        bool p_can_return_statement(size_t depth);
        std::shared_ptr<leaf::parsing::instance::return_statement> p_match_return_statement(size_t depth);
        bool m_alias_740(bool is_can, std::shared_ptr<leaf::parsing::instance::statement>& actual, leaf::parsing::instance::statement_state& state, size_t depth);
        bool m_constant_741(bool is_can, std::shared_ptr<leaf::parsing::instance::statement>& actual, leaf::parsing::instance::statement_state& state, size_t depth);
        bool m_returnstatement_742(bool is_can, std::shared_ptr<leaf::parsing::instance::statement>& actual, leaf::parsing::instance::statement_state& state, size_t depth);
        bool m_declaration_equal_expression_semicolon_743(bool is_can, std::shared_ptr<leaf::parsing::instance::statement>& actual, leaf::parsing::instance::statement_state& state, size_t depth);
        bool m_declaration_semicolon_744(bool is_can, std::shared_ptr<leaf::parsing::instance::statement>& actual, leaf::parsing::instance::statement_state& state, size_t depth);
        bool m_expression_semicolon_745(bool is_can, std::shared_ptr<leaf::parsing::instance::statement>& actual, leaf::parsing::instance::statement_state& state, size_t depth);
        bool m_semicolon_746(bool is_can, std::shared_ptr<leaf::parsing::instance::statement>& actual, leaf::parsing::instance::statement_state& state, size_t depth);
        bool m_pragma_747(bool is_can, std::shared_ptr<leaf::parsing::instance::statement>& actual, leaf::parsing::instance::statement_state& state, size_t depth);
        bool alternatives748(bool is_can, std::shared_ptr<leaf::parsing::instance::statement>& actual, leaf::parsing::instance::statement_state& state, size_t depth);
        bool p_can_statement(size_t depth);
        std::shared_ptr<leaf::parsing::instance::statement> p_match_statement(size_t depth);
        bool m_auto815_749(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma>& actual, leaf::parsing::instance::pragma_state& state, size_t depth);
        bool m_exclamationgreaterthen_750(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma>& actual, leaf::parsing::instance::pragma_state& state, size_t depth);
        bool m_pragmadisable_751(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma>& actual, leaf::parsing::instance::pragma_state& state, size_t depth);
        bool m_pragmaenable_752(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma>& actual, leaf::parsing::instance::pragma_state& state, size_t depth);
        bool m_pragmasize_753(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma>& actual, leaf::parsing::instance::pragma_state& state, size_t depth);
        bool m_pragmaalign_754(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma>& actual, leaf::parsing::instance::pragma_state& state, size_t depth);
        bool alternatives755(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma>& actual, leaf::parsing::instance::pragma_state& state, size_t depth);
        bool while756_757(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma>& actual, leaf::parsing::instance::pragma_state& state, size_t depth);
        bool m_exclamationgreaterthen_758(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma>& actual, leaf::parsing::instance::pragma_state& state, size_t depth);
        bool p_can_pragma(size_t depth);
        std::shared_ptr<leaf::parsing::instance::pragma> p_match_pragma(size_t depth);
        bool m_align_759(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_align>& actual, leaf::parsing::instance::pragma_align_state& state, size_t depth);
        bool m_integerbinary_760(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_align>& actual, leaf::parsing::instance::pragma_align_state& state, size_t depth);
        bool m_integerhex_761(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_align>& actual, leaf::parsing::instance::pragma_align_state& state, size_t depth);
        bool m_integer_762(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_align>& actual, leaf::parsing::instance::pragma_align_state& state, size_t depth);
        bool alternatives763(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_align>& actual, leaf::parsing::instance::pragma_align_state& state, size_t depth);
        bool p_can_pragma_align(size_t depth);
        std::shared_ptr<leaf::parsing::instance::pragma_align> p_match_pragma_align(size_t depth);
        bool m_size_764(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_size>& actual, leaf::parsing::instance::pragma_size_state& state, size_t depth);
        bool m_integerbinary_765(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_size>& actual, leaf::parsing::instance::pragma_size_state& state, size_t depth);
        bool m_integerhex_766(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_size>& actual, leaf::parsing::instance::pragma_size_state& state, size_t depth);
        bool m_integer_767(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_size>& actual, leaf::parsing::instance::pragma_size_state& state, size_t depth);
        bool alternatives768(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_size>& actual, leaf::parsing::instance::pragma_size_state& state, size_t depth);
        bool p_can_pragma_size(size_t depth);
        std::shared_ptr<leaf::parsing::instance::pragma_size> p_match_pragma_size(size_t depth);
        bool m_disable_769(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_disable>& actual, leaf::parsing::instance::pragma_disable_state& state, size_t depth);
        bool m_ident_770(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_disable>& actual, leaf::parsing::instance::pragma_disable_state& state, size_t depth);
        bool p_can_pragma_disable(size_t depth);
        std::shared_ptr<leaf::parsing::instance::pragma_disable> p_match_pragma_disable(size_t depth);
        bool m_enable_771(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_enable>& actual, leaf::parsing::instance::pragma_enable_state& state, size_t depth);
        bool m_ident_772(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_enable>& actual, leaf::parsing::instance::pragma_enable_state& state, size_t depth);
        bool p_can_pragma_enable(size_t depth);
        std::shared_ptr<leaf::parsing::instance::pragma_enable> p_match_pragma_enable(size_t depth);
        bool m_ident_773(bool is_can, std::shared_ptr<leaf::parsing::instance::template_usage_item>& actual, leaf::parsing::instance::template_usage_item_state& state, size_t depth);
        bool p_can_template_usage_item(size_t depth);
        std::shared_ptr<leaf::parsing::instance::template_usage_item> p_match_template_usage_item(size_t depth);
        bool m_lessthen_774(bool is_can, std::shared_ptr<leaf::parsing::instance::template_usage>& actual, leaf::parsing::instance::template_usage_state& state, size_t depth);
        bool m_templateusageitem_775(bool is_can, std::shared_ptr<leaf::parsing::instance::template_usage>& actual, leaf::parsing::instance::template_usage_state& state, size_t depth);
        bool m_comma_776(bool is_can, std::shared_ptr<leaf::parsing::instance::template_usage>& actual, leaf::parsing::instance::template_usage_state& state, size_t depth);
        bool m_comma_templateusageitem_777(bool is_can, std::shared_ptr<leaf::parsing::instance::template_usage>& actual, leaf::parsing::instance::template_usage_state& state, size_t depth);
        bool alternatives778(bool is_can, std::shared_ptr<leaf::parsing::instance::template_usage>& actual, leaf::parsing::instance::template_usage_state& state, size_t depth);
        bool while779_780(bool is_can, std::shared_ptr<leaf::parsing::instance::template_usage>& actual, leaf::parsing::instance::template_usage_state& state, size_t depth);
        bool m_greaterthen_781(bool is_can, std::shared_ptr<leaf::parsing::instance::template_usage>& actual, leaf::parsing::instance::template_usage_state& state, size_t depth);
        bool p_can_template_usage(size_t depth);
        std::shared_ptr<leaf::parsing::instance::template_usage> p_match_template_usage(size_t depth);
        bool m_ident_782(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition_item_direct_type>& actual, leaf::parsing::instance::template_definition_item_direct_type_state& state, size_t depth);
        bool m_equal_783(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition_item_direct_type>& actual, leaf::parsing::instance::template_definition_item_direct_type_state& state, size_t depth);
        bool m_equal_expvalue_784(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition_item_direct_type>& actual, leaf::parsing::instance::template_definition_item_direct_type_state& state, size_t depth);
        bool if785_786(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition_item_direct_type>& actual, leaf::parsing::instance::template_definition_item_direct_type_state& state, size_t depth);
        bool p_can_template_definition_item_direct_type(size_t depth);
        std::shared_ptr<leaf::parsing::instance::template_definition_item_direct_type> p_match_template_definition_item_direct_type(size_t depth);
        bool m_identifier_ident_787(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition_item_identifier>& actual, leaf::parsing::instance::template_definition_item_identifier_state& state, size_t depth);
        bool p_can_template_definition_item_identifier(size_t depth);
        std::shared_ptr<leaf::parsing::instance::template_definition_item_identifier> p_match_template_definition_item_identifier(size_t depth);
        bool m_lessthen_788(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition>& actual, leaf::parsing::instance::template_definition_state& state, size_t depth);
        bool m_templatedefinitionitemidentifier_789(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition>& actual, leaf::parsing::instance::template_definition_state& state, size_t depth);
        bool m_templatedefinitionitemdirecttype_790(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition>& actual, leaf::parsing::instance::template_definition_state& state, size_t depth);
        bool alternatives791(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition>& actual, leaf::parsing::instance::template_definition_state& state, size_t depth);
        bool m_comma_792(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition>& actual, leaf::parsing::instance::template_definition_state& state, size_t depth);
        bool m_templatedefinitionitemidentifier_793(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition>& actual, leaf::parsing::instance::template_definition_state& state, size_t depth);
        bool m_templatedefinitionitemdirecttype_794(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition>& actual, leaf::parsing::instance::template_definition_state& state, size_t depth);
        bool m_comma_795(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition>& actual, leaf::parsing::instance::template_definition_state& state, size_t depth);
        bool alternatives796(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition>& actual, leaf::parsing::instance::template_definition_state& state, size_t depth);
        bool while797_798(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition>& actual, leaf::parsing::instance::template_definition_state& state, size_t depth);
        bool m_greaterthen_799(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition>& actual, leaf::parsing::instance::template_definition_state& state, size_t depth);
        bool p_can_template_definition(size_t depth);
        std::shared_ptr<leaf::parsing::instance::template_definition> p_match_template_definition(size_t depth);
        bool m_using_800(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth);
        bool m_using_801(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth);
        bool m_using_802(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth);
        bool while803_804(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth);
        bool if805_806(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth);
        bool m_contract_807(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth);
        bool m_alias_808(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth);
        bool m_namespace_809(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth);
        bool m_conversion_810(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth);
        bool m_class_811(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth);
        bool m_method_812(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth);
        bool m_property_813(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth);
        bool m_field_814(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth);
        bool m_pragma_815(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth);
        bool alternatives816(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth);
        bool while817_818(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth);
        bool p_can_main(size_t depth);
        std::shared_ptr<leaf::parsing::instance::main> p_match_main(size_t depth);
        bool m_expchain_dot_call_819(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_chain>& actual, leaf::parsing::instance::exp_chain_state& state, size_t depth);
        bool m_expchain_dot_ident_820(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_chain>& actual, leaf::parsing::instance::exp_chain_state& state, size_t depth);
        bool m_expchain_minusgreaterthen_call_821(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_chain>& actual, leaf::parsing::instance::exp_chain_state& state, size_t depth);
        bool m_expchain_minusgreaterthen_ident_822(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_chain>& actual, leaf::parsing::instance::exp_chain_state& state, size_t depth);
        bool m_expchain_squarebracketopen_expression_squarebracketclose_823(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_chain>& actual, leaf::parsing::instance::exp_chain_state& state, size_t depth);
        bool m_expchain_templateusage_824(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_chain>& actual, leaf::parsing::instance::exp_chain_state& state, size_t depth);
        bool m_expchainstart_825(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_chain>& actual, leaf::parsing::instance::exp_chain_state& state, size_t depth);
        bool lr_can_exp_chain(size_t depth);
        std::shared_ptr<leaf::parsing::instance::exp_chain> lr_match_exp_chain(size_t depth);
        bool m_expbinary4_lessthenlessthen_expunary_826(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_binary_4>& actual, leaf::parsing::instance::exp_binary_4_state& state, size_t depth);
        bool m_expbinary4_greaterthengreaterthen_expunary_827(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_binary_4>& actual, leaf::parsing::instance::exp_binary_4_state& state, size_t depth);
        bool m_expbinary4_lessthenlessthenlessthen_expunary_828(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_binary_4>& actual, leaf::parsing::instance::exp_binary_4_state& state, size_t depth);
        bool m_expbinary4_greaterthengreaterthengreaterthen_expunary_829(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_binary_4>& actual, leaf::parsing::instance::exp_binary_4_state& state, size_t depth);
        bool m_expunary_830(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_binary_4>& actual, leaf::parsing::instance::exp_binary_4_state& state, size_t depth);
        bool lr_can_exp_binary_4(size_t depth);
        std::shared_ptr<leaf::parsing::instance::exp_binary_4> lr_match_exp_binary_4(size_t depth);
        bool m_expbinary3_ampersand_expbinary4_831(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_binary_3>& actual, leaf::parsing::instance::exp_binary_3_state& state, size_t depth);
        bool m_expbinary4_832(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_binary_3>& actual, leaf::parsing::instance::exp_binary_3_state& state, size_t depth);
        bool lr_can_exp_binary_3(size_t depth);
        std::shared_ptr<leaf::parsing::instance::exp_binary_3> lr_match_exp_binary_3(size_t depth);
        bool m_expbinary2_circumflex_expbinary3_833(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_binary_2>& actual, leaf::parsing::instance::exp_binary_2_state& state, size_t depth);
        bool m_expbinary3_834(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_binary_2>& actual, leaf::parsing::instance::exp_binary_2_state& state, size_t depth);
        bool lr_can_exp_binary_2(size_t depth);
        std::shared_ptr<leaf::parsing::instance::exp_binary_2> lr_match_exp_binary_2(size_t depth);
        bool m_expbinary1_verticalbar_expbinary2_835(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_binary_1>& actual, leaf::parsing::instance::exp_binary_1_state& state, size_t depth);
        bool m_expbinary2_836(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_binary_1>& actual, leaf::parsing::instance::exp_binary_1_state& state, size_t depth);
        bool lr_can_exp_binary_1(size_t depth);
        std::shared_ptr<leaf::parsing::instance::exp_binary_1> lr_match_exp_binary_1(size_t depth);
        bool m_exparithmetic2_slash_expbinary1_837(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_arithmetic_2>& actual, leaf::parsing::instance::exp_arithmetic_2_state& state, size_t depth);
        bool m_exparithmetic2_star_expbinary1_838(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_arithmetic_2>& actual, leaf::parsing::instance::exp_arithmetic_2_state& state, size_t depth);
        bool m_expbinary1_839(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_arithmetic_2>& actual, leaf::parsing::instance::exp_arithmetic_2_state& state, size_t depth);
        bool lr_can_exp_arithmetic_2(size_t depth);
        std::shared_ptr<leaf::parsing::instance::exp_arithmetic_2> lr_match_exp_arithmetic_2(size_t depth);
        bool m_exparithmetic1_plus_exparithmetic2_840(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_arithmetic_1>& actual, leaf::parsing::instance::exp_arithmetic_1_state& state, size_t depth);
        bool m_exparithmetic1_minus_exparithmetic2_841(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_arithmetic_1>& actual, leaf::parsing::instance::exp_arithmetic_1_state& state, size_t depth);
        bool m_exparithmetic2_842(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_arithmetic_1>& actual, leaf::parsing::instance::exp_arithmetic_1_state& state, size_t depth);
        bool lr_can_exp_arithmetic_1(size_t depth);
        std::shared_ptr<leaf::parsing::instance::exp_arithmetic_1> lr_match_exp_arithmetic_1(size_t depth);
        bool m_expcompare_lessthenequal_exparithmetic1_843(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_compare>& actual, leaf::parsing::instance::exp_compare_state& state, size_t depth);
        bool m_expcompare_lessthen_exparithmetic1_844(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_compare>& actual, leaf::parsing::instance::exp_compare_state& state, size_t depth);
        bool m_expcompare_greaterthenequal_exparithmetic1_845(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_compare>& actual, leaf::parsing::instance::exp_compare_state& state, size_t depth);
        bool m_expcompare_greaterthen_exparithmetic1_846(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_compare>& actual, leaf::parsing::instance::exp_compare_state& state, size_t depth);
        bool m_exparithmetic1_847(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_compare>& actual, leaf::parsing::instance::exp_compare_state& state, size_t depth);
        bool lr_can_exp_compare(size_t depth);
        std::shared_ptr<leaf::parsing::instance::exp_compare> lr_match_exp_compare(size_t depth);
        bool m_expequality_exclamationequal_expcompare_848(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_equality>& actual, leaf::parsing::instance::exp_equality_state& state, size_t depth);
        bool m_expequality_equalequalequal_expcompare_849(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_equality>& actual, leaf::parsing::instance::exp_equality_state& state, size_t depth);
        bool m_expequality_equalequal_expcompare_850(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_equality>& actual, leaf::parsing::instance::exp_equality_state& state, size_t depth);
        bool m_expequality_tildeequal_expcompare_851(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_equality>& actual, leaf::parsing::instance::exp_equality_state& state, size_t depth);
        bool m_expcompare_852(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_equality>& actual, leaf::parsing::instance::exp_equality_state& state, size_t depth);
        bool lr_can_exp_equality(size_t depth);
        std::shared_ptr<leaf::parsing::instance::exp_equality> lr_match_exp_equality(size_t depth);
        bool m_expand_ampersandampersand_expequality_853(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_and>& actual, leaf::parsing::instance::exp_and_state& state, size_t depth);
        bool m_expequality_854(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_and>& actual, leaf::parsing::instance::exp_and_state& state, size_t depth);
        bool lr_can_exp_and(size_t depth);
        std::shared_ptr<leaf::parsing::instance::exp_and> lr_match_exp_and(size_t depth);
        bool m_expor_verticalbarverticalbar_expand_855(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_or>& actual, leaf::parsing::instance::exp_or_state& state, size_t depth);
        bool m_expand_856(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_or>& actual, leaf::parsing::instance::exp_or_state& state, size_t depth);
        bool lr_can_exp_or(size_t depth);
        std::shared_ptr<leaf::parsing::instance::exp_or> lr_match_exp_or(size_t depth);
        bool m_identnavigation_dot_ident_857(bool is_can, std::shared_ptr<leaf::parsing::instance::ident_navigation>& actual, leaf::parsing::instance::ident_navigation_state& state, size_t depth);
        bool m_ident_858(bool is_can, std::shared_ptr<leaf::parsing::instance::ident_navigation>& actual, leaf::parsing::instance::ident_navigation_state& state, size_t depth);
        bool lr_can_ident_navigation(size_t depth);
        std::shared_ptr<leaf::parsing::instance::ident_navigation> lr_match_ident_navigation(size_t depth);
        bool m_typenavigation_dot_ident_templateusage_859(bool is_can, std::shared_ptr<leaf::parsing::instance::type_navigation>& actual, leaf::parsing::instance::type_navigation_state& state, size_t depth);
        bool m_typenavigation_dot_ident_860(bool is_can, std::shared_ptr<leaf::parsing::instance::type_navigation>& actual, leaf::parsing::instance::type_navigation_state& state, size_t depth);
        bool m_typenavigation_templateusage_861(bool is_can, std::shared_ptr<leaf::parsing::instance::type_navigation>& actual, leaf::parsing::instance::type_navigation_state& state, size_t depth);
        bool m_ident_862(bool is_can, std::shared_ptr<leaf::parsing::instance::type_navigation>& actual, leaf::parsing::instance::type_navigation_state& state, size_t depth);
        bool lr_can_type_navigation(size_t depth);
        std::shared_ptr<leaf::parsing::instance::type_navigation> lr_match_type_navigation(size_t depth);
        void skip();
    protected:
        std::string_view m_contents;
        std::string m_file;
        size_t m_line;
        size_t m_column;
        size_t m_offset;
        virtual void report(std::string_view message, size_t depth);
    public:
        instance(std::string_view contents, std::string file) : m_contents(contents), m_file(file), m_line(1), m_column(1), m_offset(0)
        {
        }
        enum class tok
        {
            __UNSET__,
            INTEGER_BINARY,
            INTEGER_HEX,
            INTEGER_UNSIGNED,
            INTEGER_SIGNED_NEGATIVE,
            INTEGER_SIGNED_POSITIVE,
            INTEGER,
            SCALAR,
            SLASH,
            STAR,
            PLUS,
            MINUS,
            UNDERSCORE,
            TRUE_,
            FALSE_,
            IDENT,
            STRING_FORMATABLE_START,
            STRING_FORMATABLE_FAKE,
            STRING_FORMATABLE_CONTINUATION,
            STRING_FORMATABLE_END,
            STRING_UNESCAPED_ENDING,
            STRING,
            CHAR_UNESCAPED_ENDING,
            CHAR_,
            _COLON,
            _COMMA,
            _ROUND_BRACKET_OPEN,
            _ROUND_BRACKET_CLOSE,
            _SQUARE_BRACKET_OPEN,
            _SQUARE_BRACKET_CLOSE,
            _CONTRACT,
            _CURLY_BRACKET_OPEN,
            _CURLY_BRACKET_CLOSE,
            _SEMICOLON,
            _GET,
            _SET,
            _OPERATOR,
            _LESS_THEN_LESS_THEN_LESS_THEN,
            _LESS_THEN_LESS_THEN,
            _LESS_THEN_EQUAL,
            _LESS_THEN,
            _GREATER_THEN_GREATER_THEN_GREATER_THEN,
            _GREATER_THEN_GREATER_THEN,
            _GREATER_THEN_EQUAL,
            _GREATER_THEN,
            _VERTICAL_BAR_VERTICAL_BAR,
            _VERTICAL_BAR,
            _AMPERSAND_AMPERSAND,
            _AMPERSAND,
            _EQUAL_EQUAL_EQUAL,
            _EQUAL_EQUAL,
            _EXCLAMATION_EQUAL,
            _CIRCUMFLEX,
            _EXCLAMATION,
            _TILDE,
            _DOT,
            _MINUS_GREATER_THEN,
            _EQUAL_GREATER_THEN,
            _WHILE,
            _IF,
            _ELSE,
            _FOR,
            _CASE,
            _SWITCH,
            _DEFAULT,
            _EOL,
            _ASSEMBLY,
            _COPY,
            _TILDE_EQUAL,
            _EQUAL,
            _PUBLIC,
            _LOCAL,
            _DERIVED,
            _PRIVATE,
            _NAMESPACE,
            _CLASS,
            _SEALED,
            _VIRTUAL,
            _UNBOUND,
            _INLINE,
            _DELETE,
            _CONVERSION,
            _CONST,
            _USING,
            _ALIAS,
            _FREE,
            _ALLOC,
            _STACK,
            _HEAP,
            _TYPEOF,
            _NAMEOF,
            _SIZEOF,
            _SINGLE_QUOTATION,
            _SCOPE,
            _STATIC,
            _RETURN,
            _AUTO_815,
            _EXCLAMATION_GREATER_THEN,
            _ALIGN,
            _SIZE,
            _DISABLE,
            _ENABLE,
            _IDENTIFIER,
            __MAX__
        };
        class token
        {
        public:
            tok type;
            std::string file;
            size_t line;
            size_t column;
            size_t offset;
            size_t length;
        };
        leaf::parsing::instance::token create_token(size_t length, tok type);
        class attribute_arg_item_a
        {
        public:
            std::shared_ptr<exp_or> value;
        };
        class attribute_arg_item_b
        {
        public:
            token name;
            std::shared_ptr<exp_or> value;
        };
        class attribute_args_a
        {
        public:
            std::vector<std::shared_ptr<attribute_arg_item_a>> args;
        };
        class attribute_args_b
        {
        public:
            std::vector<std::shared_ptr<attribute_arg_item_b>> args;
        };
        class attribute_item
        {
        public:
            std::shared_ptr<type_match> target_type;
            std::variant<std::shared_ptr<attribute_args_a>, std::shared_ptr<attribute_args_b>> args;
        };
        class attribute
        {
        public:
            std::vector<std::shared_ptr<attribute_item>> items;
        };
        class contract
        {
        public:
            std::shared_ptr<encapsulation> scope;
            token name;
            std::shared_ptr<template_definition> template_;
        };
        class contract_method
        {
        public:
            std::shared_ptr<type_match> return_type;
            token name;
            std::shared_ptr<contract_method_arglist> arglist;
        };
        class contract_constructor
        {
        public:
            token name;
            std::shared_ptr<contract_method_arglist> arglist;
        };
        class contract_indexer
        {
        public:
            std::optional<bool> is_set;
            std::optional<bool> is_get;
            std::shared_ptr<type_match> target_type;
            std::shared_ptr<contract_method_arglist_indexer> arglist;
        };
        class contract_operator_binary_overload
        {
        public:
            std::shared_ptr<type_match> target_type;
            std::shared_ptr<type_match> left;
            token operator_;
            std::shared_ptr<type_match> right;
        };
        class contract_operator_unary_overload
        {
        public:
            std::shared_ptr<type_match> target_type;
            token operator_;
            std::shared_ptr<type_match> right;
        };
        class contract_operator_nullar_overload
        {
        public:
            std::shared_ptr<method_meta> meta;
            token operator_;
        };
        class contract_property
        {
        public:
            std::optional<bool> is_set;
            std::optional<bool> is_get;
            std::shared_ptr<type_match> target_type;
            token name;
        };
        class contract_field
        {
        public:
            std::shared_ptr<type_match> target_type;
            token name;
        };
        class contract_method_arglist
        {
        public:
            std::vector<std::shared_ptr<type_match>> args;
        };
        class contract_method_arglist_indexer
        {
        public:
            std::vector<std::shared_ptr<type_match>> args;
        };
        class scope
        {
        public:
            std::vector<std::shared_ptr<using_>> usings;
            std::vector<std::variant<std::shared_ptr<control_structure>, std::shared_ptr<statement>>> body;
        };
        class scope_lambda
        {
        public:
            std::vector<std::shared_ptr<using_>> usings;
            std::vector<std::variant<std::shared_ptr<control_structure>, std::shared_ptr<statement>>> body;
        };
        class scope_getset
        {
        public:
            std::shared_ptr<scope> get;
            std::shared_ptr<scope> set;
        };
        class control_structure_body
        {
        public:
            std::variant<std::shared_ptr<scope>, std::shared_ptr<control_structure>, std::shared_ptr<statement>> body;
        };
        class while_loop
        {
        public:
            std::shared_ptr<expression> condition;
            std::shared_ptr<control_structure_body> body;
        };
        class if_body
        {
        public:
            std::shared_ptr<expression> condition;
            std::shared_ptr<control_structure_body> body;
        };
        class else_body
        {
        public:
            std::shared_ptr<control_structure_body> else_body;
        };
        class for_body
        {
        public:
            std::shared_ptr<expression> pre;
            std::shared_ptr<expression> condition;
            std::shared_ptr<expression> post_inner;
            std::shared_ptr<control_structure_body> body;
        };
        class for_each_body
        {
        public:
            std::shared_ptr<declaration> pre;
            std::shared_ptr<expression> exp;
            std::shared_ptr<control_structure_body> body;
        };
        class if_else
        {
        public:
            std::shared_ptr<if_body> if_;
            std::shared_ptr<else_body> else_;
        };
        class switch_case
        {
        public:
            std::shared_ptr<exp_value> value;
            std::shared_ptr<control_structure_body> body;
        };
        class switch_
        {
        public:
            std::shared_ptr<expression> value;
            std::vector<std::shared_ptr<switch_case>> part;
            std::vector<std::shared_ptr<control_structure_body>> default_body;
            std::vector<std::shared_ptr<pragma>> pragmas;
        };
        class assembly_terminate
        {
        };
        class assembly
        {
        public:
            std::vector<token> args;
            std::vector<token> opcode;
        };
        class control_structure
        {
        public:
            std::shared_ptr<pragma> pragmas;
            std::variant<std::shared_ptr<while_loop>, std::shared_ptr<for_body>, std::shared_ptr<for_each_body>, std::shared_ptr<if_else>, std::shared_ptr<switch_>, std::shared_ptr<scope>, std::shared_ptr<assembly>> content;
        };
        class exp_chain_start
        {
        public:
            std::shared_ptr<alloc> part_alloc;
            std::shared_ptr<free> part_free;
            std::shared_ptr<call> part_call;
            token part_ident;
        };
        class exp_constant
        {
        public:
            std::shared_ptr<typeof_> typeof_;
            std::shared_ptr<nameof> nameof;
            std::shared_ptr<sizeof_> sizeof_;
            token t;
        };
        class exp_lambda
        {
        public:
            std::shared_ptr<capture_list> capture;
            std::shared_ptr<method_arglist> args;
            std::shared_ptr<scope_lambda> scope;
        };
        class capture_list_item
        {
        public:
            token capture_type;
            token variable;
        };
        class capture_list
        {
        public:
            std::vector<std::shared_ptr<capture_list_item>> items;
        };
        class exp_value
        {
        public:
            std::shared_ptr<exp_lambda> exp_lambda;
            std::shared_ptr<exp_constant> exp_constant;
            std::shared_ptr<scalar_literal> scalar;
            std::shared_ptr<integer_hex_literal> integer_hex;
            std::shared_ptr<integer_binary_literal> integer_binary;
            std::shared_ptr<integer_literal> integer;
            std::shared_ptr<char_literal> character;
            std::shared_ptr<string_literal> string;
            std::shared_ptr<exp_constant> constant;
        };
        class exp_nullar
        {
        public:
            std::variant<std::shared_ptr<expression>, std::shared_ptr<exp_chain>, std::shared_ptr<exp_value>> value;
        };
        class exp_unary
        {
        public:
            token operator_;
            std::variant<std::shared_ptr<exp_unary>, std::shared_ptr<exp_nullar>> value;
            std::shared_ptr<type_match> cast_target;
        };
        class expression
        {
        public:
            std::shared_ptr<exp_or> assign_to;
            std::shared_ptr<expression> value;
            std::shared_ptr<exp_or> exp;
        };
        class encapsulation
        {
        public:
            token tok;
        };
        class namespace_
        {
        public:
            std::vector<std::shared_ptr<attribute>> attributes;
            std::shared_ptr<ident_navigation> name;
            std::vector<std::shared_ptr<contract>> contracts;
            std::vector<std::shared_ptr<alias_encapsulated>> aliases;
            std::vector<std::shared_ptr<constant>> constants;
            std::vector<std::shared_ptr<using_>> usings;
            std::vector<std::shared_ptr<namespace_>> namespaces;
            std::vector<std::shared_ptr<conversion>> conversions;
            std::vector<std::shared_ptr<class_>> classes;
            std::vector<std::shared_ptr<method>> methods;
            std::vector<std::shared_ptr<property>> properties;
            std::vector<std::shared_ptr<field>> fields;
            std::vector<std::shared_ptr<pragma>> pragmas;
        };
        class class_
        {
        public:
            std::vector<std::shared_ptr<attribute>> attributes;
            std::shared_ptr<encapsulation> scope;
            token name;
            std::shared_ptr<template_definition> template_;
            std::shared_ptr<lifetime> lifetime;
            std::vector<std::shared_ptr<contract>> contracts;
            std::vector<std::shared_ptr<alias_encapsulated>> aliases;
            std::vector<std::shared_ptr<constant>> constants;
            std::vector<std::shared_ptr<using_>> usings;
            std::vector<std::shared_ptr<indexer>> indexers;
            std::vector<std::shared_ptr<operator_binary_overload>> operators_binary;
            std::vector<std::shared_ptr<operator_unary_overload>> operators_unary;
            std::vector<std::shared_ptr<operator_nullar_overload>> operators_nullar;
            std::vector<std::shared_ptr<conversion>> conversions;
            std::vector<std::shared_ptr<class_>> classes;
            std::vector<std::shared_ptr<constructor>> constructors;
            std::vector<std::shared_ptr<destructor>> destructors;
            std::vector<std::shared_ptr<copystructor>> copystructors;
            std::vector<std::shared_ptr<property>> properties;
            std::vector<std::shared_ptr<field>> fields;
            std::vector<std::shared_ptr<method>> methods;
            std::vector<std::shared_ptr<pragma>> pragmas;
        };
        class method_arglist_item
        {
        public:
            std::vector<std::shared_ptr<attribute>> attributes;
            std::shared_ptr<type_match> type;
            token name;
        };
        class method_arglist
        {
        public:
            std::vector<std::shared_ptr<method_arglist_item>> args;
        };
        class method_arglist_indexer
        {
        public:
            std::vector<std::shared_ptr<method_arglist_item>> args;
        };
        class method_meta
        {
        public:
            std::optional<bool> is_sealed;
            std::optional<bool> is_virtual;
            std::optional<bool> is_static;
            std::optional<bool> is_inline;
            std::shared_ptr<encapsulation> encaps;
        };
        class method
        {
        public:
            std::vector<std::shared_ptr<attribute>> attributes;
            std::shared_ptr<method_meta> meta;
            std::shared_ptr<type_match> return_type;
            token name;
            std::shared_ptr<template_definition> template_;
            std::shared_ptr<method_arglist> arglist;
            std::shared_ptr<scope> body;
        };
        class constructor
        {
        public:
            std::vector<std::shared_ptr<attribute>> attributes;
            std::shared_ptr<encapsulation> encaps;
            std::shared_ptr<template_definition> template_;
            std::shared_ptr<method_arglist> arglist;
            std::shared_ptr<scope> body;
        };
        class destructor
        {
        public:
            std::vector<std::shared_ptr<attribute>> attributes;
            std::shared_ptr<encapsulation> encaps;
            std::shared_ptr<template_definition> template_;
            std::shared_ptr<method_arglist> arglist;
            std::shared_ptr<scope> body;
        };
        class copystructor
        {
        public:
            std::vector<std::shared_ptr<attribute>> attributes;
            std::shared_ptr<encapsulation> encaps;
            std::shared_ptr<template_definition> template_;
            std::shared_ptr<method_arglist> arglist;
            std::shared_ptr<scope> body;
        };
        class conversion
        {
        public:
            std::vector<std::shared_ptr<attribute>> attributes;
            std::shared_ptr<method_meta> meta;
            std::shared_ptr<type_match> target_type;
            std::shared_ptr<type_match> source_type;
            token name;
            std::shared_ptr<scope> body;
        };
        class indexer
        {
        public:
            std::vector<std::shared_ptr<attribute>> attributes;
            std::shared_ptr<method_meta> meta;
            std::shared_ptr<type_match> target_type;
            std::shared_ptr<template_definition> template_;
            std::shared_ptr<method_arglist_indexer> arglist;
            std::shared_ptr<scope_getset> body;
        };
        class operator_binary_overload
        {
        public:
            std::vector<std::shared_ptr<attribute>> attributes;
            std::shared_ptr<method_meta> meta;
            std::shared_ptr<type_match> target_type;
            std::shared_ptr<template_definition> template_;
            std::shared_ptr<method_arglist_item> left;
            token operator_;
            std::shared_ptr<method_arglist_item> right;
            std::shared_ptr<scope> body;
        };
        class operator_unary_overload
        {
        public:
            std::vector<std::shared_ptr<attribute>> attributes;
            std::shared_ptr<method_meta> meta;
            std::shared_ptr<type_match> target_type;
            std::shared_ptr<template_definition> template_;
            token operator_;
            std::shared_ptr<method_arglist_item> right;
            std::shared_ptr<scope> body;
        };
        class operator_nullar_overload
        {
        public:
            std::vector<std::shared_ptr<attribute>> attributes;
            std::shared_ptr<method_meta> meta;
            std::shared_ptr<template_definition> template_;
            token operator_;
            std::shared_ptr<scope> body;
        };
        class property
        {
        public:
            std::vector<std::shared_ptr<attribute>> attributes;
            std::shared_ptr<method_meta> meta;
            std::shared_ptr<type_match> target_type;
            token name;
            std::shared_ptr<scope_getset> body;
        };
        class field
        {
        public:
            std::optional<bool> is_static;
            std::vector<std::shared_ptr<attribute>> attributes;
            std::shared_ptr<encapsulation> encaps;
            std::shared_ptr<type_match> target_type;
            token name;
        };
        class constant
        {
        public:
            std::shared_ptr<type_match> target_type;
            token name;
            std::shared_ptr<exp_or> value;
        };
        class using_
        {
        public:
            std::optional<bool> is_namespace;
            std::optional<bool> is_class;
            std::shared_ptr<ident_navigation> ident;
            token alias;
        };
        class alias_encapsulated
        {
        public:
            std::shared_ptr<encapsulation> encaps;
            std::shared_ptr<alias> actual;
        };
        class alias
        {
        public:
            token alias;
            std::shared_ptr<type_match> ident;
        };
        class call
        {
        public:
            token method;
            std::shared_ptr<call_body> body;
        };
        class call_body
        {
        public:
            std::vector<std::shared_ptr<expression>> args;
        };
        class free
        {
        public:
            std::shared_ptr<expression> value;
        };
        class alloc
        {
        public:
            std::optional<bool> is_stack;
            std::optional<bool> is_heap;
            std::shared_ptr<type_navigation> type;
            std::shared_ptr<expression> exp;
            std::shared_ptr<call_body> body;
        };
        class typeof_
        {
        public:
            std::shared_ptr<type_match> value;
        };
        class nameof
        {
        public:
            std::shared_ptr<exp_or> value;
        };
        class sizeof_
        {
        public:
            std::shared_ptr<type_match> type;
        };
        class lifetime
        {
        public:
            std::optional<bool> is_scope;
            std::optional<bool> is_static;
            token named;
        };
        class type_match
        {
        public:
            std::optional<bool> is_array;
            std::optional<bool> is_heap;
            std::shared_ptr<type_navigation> base;
            std::shared_ptr<lifetime> lifetime;
        };
        class string_formatable
        {
        public:
            std::vector<std::variant<token, std::shared_ptr<expression>>> parts;
        };
        class string_literal
        {
        public:
            token prefix;
            std::variant<std::shared_ptr<string_formatable>, token> value;
            token postfix;
        };
        class scalar_literal
        {
        public:
            token prefix;
            token value;
            token postfix;
        };
        class integer_hex_literal
        {
        public:
            token prefix;
            token value;
            token postfix;
        };
        class integer_binary_literal
        {
        public:
            token prefix;
            token value;
            token postfix;
        };
        class integer_literal
        {
        public:
            token prefix;
            token value;
            token postfix;
        };
        class char_literal
        {
        public:
            token prefix;
            token value;
            token postfix;
        };
        class declaration
        {
        public:
            std::shared_ptr<type_match> type;
            token name;
        };
        class return_statement
        {
        public:
            std::shared_ptr<expression> exp;
        };
        class statement
        {
        public:
            std::shared_ptr<alias> aliases;
            std::shared_ptr<constant> constants;
            std::shared_ptr<return_statement> ret;
            std::shared_ptr<declaration> fwrd_decl;
            std::shared_ptr<expression> exp;
            std::shared_ptr<pragma> pragma;
        };
        class pragma
        {
        public:
            std::vector<std::variant<std::shared_ptr<pragma_disable>, std::shared_ptr<pragma_enable>, std::shared_ptr<pragma_size>, std::shared_ptr<pragma_align>>> contents;
        };
        class pragma_align
        {
        public:
            token bytes;
        };
        class pragma_size
        {
        public:
            token bytes;
        };
        class pragma_disable
        {
        public:
            token code;
        };
        class pragma_enable
        {
        public:
            token code;
        };
        class template_usage_item
        {
        public:
            token key;
        };
        class template_usage
        {
        public:
            std::vector<std::shared_ptr<template_usage_item>> items;
        };
        class template_definition_item_direct_type
        {
        public:
            token key;
            std::shared_ptr<exp_value> value;
        };
        class template_definition_item_identifier
        {
        public:
            token key;
        };
        class template_definition
        {
        public:
            std::vector<std::variant<std::shared_ptr<template_definition_item_identifier>, std::shared_ptr<template_definition_item_direct_type>>> items;
        };
        class main
        {
        public:
            std::vector<std::shared_ptr<using_>> usings;
            std::vector<std::shared_ptr<contract>> contract;
            std::vector<std::shared_ptr<alias>> aliases;
            std::vector<std::shared_ptr<namespace_>> namespaces;
            std::vector<std::shared_ptr<conversion>> conversions;
            std::vector<std::shared_ptr<class_>> classes;
            std::vector<std::shared_ptr<method>> methods;
            std::vector<std::shared_ptr<property>> properties;
            std::vector<std::shared_ptr<field>> fields;
            std::vector<std::shared_ptr<pragma>> pragmas;
        };
        class exp_chain
        {
        public:
            std::variant<std::shared_ptr<exp_chain>, std::shared_ptr<exp_chain_start>> left;
            std::shared_ptr<call> chain_call;
            token chain_access;
            std::shared_ptr<call> indirection_call;
            token indirection_access;
            std::shared_ptr<expression> chain_indexer;
            std::shared_ptr<template_usage> chain_template;
        };
        class exp_binary_4
        {
        public:
            std::variant<std::shared_ptr<exp_binary_4>, std::shared_ptr<exp_unary>> left;
            token operator_;
            std::shared_ptr<exp_unary> right;
        };
        class exp_binary_3
        {
        public:
            std::variant<std::shared_ptr<exp_binary_3>, std::shared_ptr<exp_binary_4>> left;
            token operator_;
            std::shared_ptr<exp_binary_4> right;
        };
        class exp_binary_2
        {
        public:
            std::variant<std::shared_ptr<exp_binary_2>, std::shared_ptr<exp_binary_3>> left;
            token operator_;
            std::shared_ptr<exp_binary_3> right;
        };
        class exp_binary_1
        {
        public:
            std::variant<std::shared_ptr<exp_binary_1>, std::shared_ptr<exp_binary_2>> left;
            token operator_;
            std::shared_ptr<exp_binary_2> right;
        };
        class exp_arithmetic_2
        {
        public:
            std::variant<std::shared_ptr<exp_arithmetic_2>, std::shared_ptr<exp_binary_1>> left;
            token operator_;
            std::shared_ptr<exp_binary_1> right;
        };
        class exp_arithmetic_1
        {
        public:
            std::variant<std::shared_ptr<exp_arithmetic_1>, std::shared_ptr<exp_arithmetic_2>> left;
            token operator_;
            std::shared_ptr<exp_arithmetic_2> right;
        };
        class exp_compare
        {
        public:
            std::variant<std::shared_ptr<exp_compare>, std::shared_ptr<exp_arithmetic_1>> left;
            token operator_;
            std::shared_ptr<exp_arithmetic_1> right;
        };
        class exp_equality
        {
        public:
            std::variant<std::shared_ptr<exp_equality>, std::shared_ptr<exp_compare>> left;
            token operator_;
            std::shared_ptr<exp_compare> right;
        };
        class exp_and
        {
        public:
            std::variant<std::shared_ptr<exp_and>, std::shared_ptr<exp_equality>> left;
            token operator_;
            std::shared_ptr<exp_equality> right;
        };
        class exp_or
        {
        public:
            std::variant<std::shared_ptr<exp_or>, std::shared_ptr<exp_and>> left;
            token operator_;
            std::shared_ptr<exp_and> right;
        };
        class ident_navigation
        {
        public:
            std::variant<std::shared_ptr<ident_navigation>, token> left;
            token right;
        };
        class type_navigation
        {
        public:
            std::variant<std::shared_ptr<type_navigation>, token> left;
            token right;
            std::shared_ptr<template_usage> template_;
        };
        class attribute_arg_item_a_state
        {
        };
        class attribute_arg_item_b_state
        {
        };
        class attribute_args_a_state
        {
        };
        class attribute_args_b_state
        {
        };
        class attribute_item_state
        {
        };
        class attribute_state
        {
        };
        class contract_state
        {
        };
        class contract_method_state
        {
        };
        class contract_constructor_state
        {
        };
        class contract_indexer_state
        {
        };
        class contract_operator_binary_overload_state
        {
        };
        class contract_operator_unary_overload_state
        {
        };
        class contract_operator_nullar_overload_state
        {
        };
        class contract_property_state
        {
        };
        class contract_field_state
        {
        };
        class contract_method_arglist_state
        {
        };
        class contract_method_arglist_indexer_state
        {
        };
        class scope_state
        {
        };
        class scope_lambda_state
        {
        };
        class scope_getset_state
        {
        };
        class control_structure_body_state
        {
        };
        class while_loop_state
        {
        };
        class if_body_state
        {
        };
        class else_body_state
        {
        };
        class for_body_state
        {
        };
        class for_each_body_state
        {
        };
        class if_else_state
        {
        };
        class switch_case_state
        {
        };
        class switch__state
        {
        public:
            std::optional<bool> has_default;
        };
        class assembly_terminate_state
        {
        };
        class assembly_state
        {
        };
        class control_structure_state
        {
        };
        class exp_chain_start_state
        {
        };
        class exp_constant_state
        {
        };
        class exp_lambda_state
        {
        };
        class capture_list_item_state
        {
        };
        class capture_list_state
        {
        };
        class exp_value_state
        {
        };
        class exp_nullar_state
        {
        };
        class exp_unary_state
        {
        };
        class expression_state
        {
        };
        class encapsulation_state
        {
        };
        class namespace__state
        {
        };
        class class__state
        {
        };
        class method_arglist_item_state
        {
        };
        class method_arglist_state
        {
        };
        class method_arglist_indexer_state
        {
        };
        class method_meta_state
        {
        };
        class method_state
        {
        };
        class constructor_state
        {
        };
        class destructor_state
        {
        };
        class copystructor_state
        {
        };
        class conversion_state
        {
        };
        class indexer_state
        {
        };
        class operator_binary_overload_state
        {
        };
        class operator_unary_overload_state
        {
        };
        class operator_nullar_overload_state
        {
        };
        class property_state
        {
        };
        class field_state
        {
        };
        class constant_state
        {
        };
        class using__state
        {
        };
        class alias_encapsulated_state
        {
        };
        class alias_state
        {
        };
        class call_state
        {
        };
        class call_body_state
        {
        };
        class free_state
        {
        };
        class alloc_state
        {
        };
        class typeof__state
        {
        };
        class nameof_state
        {
        };
        class sizeof__state
        {
        };
        class lifetime_state
        {
        };
        class type_match_state
        {
        };
        class string_formatable_state
        {
        };
        class string_literal_state
        {
        };
        class scalar_literal_state
        {
        };
        class integer_hex_literal_state
        {
        };
        class integer_binary_literal_state
        {
        };
        class integer_literal_state
        {
        };
        class char_literal_state
        {
        };
        class declaration_state
        {
        };
        class return_statement_state
        {
        };
        class statement_state
        {
        };
        class pragma_state
        {
        };
        class pragma_align_state
        {
        };
        class pragma_size_state
        {
        };
        class pragma_disable_state
        {
        };
        class pragma_enable_state
        {
        };
        class template_usage_item_state
        {
        };
        class template_usage_state
        {
        };
        class template_definition_item_direct_type_state
        {
        };
        class template_definition_item_identifier_state
        {
        };
        class template_definition_state
        {
        };
        class main_state
        {
        };
        class exp_chain_state
        {
        };
        class exp_binary_4_state
        {
        };
        class exp_binary_3_state
        {
        };
        class exp_binary_2_state
        {
        };
        class exp_binary_1_state
        {
        };
        class exp_arithmetic_2_state
        {
        };
        class exp_arithmetic_1_state
        {
        };
        class exp_compare_state
        {
        };
        class exp_equality_state
        {
        };
        class exp_and_state
        {
        };
        class exp_or_state
        {
        };
        class ident_navigation_state
        {
        };
        class type_navigation_state
        {
        };
        std::shared_ptr<leaf::parsing::instance::main> parse();
        std::vector<std::string> create_string_tree(std::shared_ptr<attribute_arg_item_a> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<attribute_arg_item_b> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<attribute_args_a> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<attribute_args_b> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<attribute_item> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<attribute> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<contract> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<contract_method> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<contract_constructor> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<contract_indexer> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<contract_operator_binary_overload> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<contract_operator_unary_overload> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<contract_operator_nullar_overload> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<contract_property> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<contract_field> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<contract_method_arglist> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<contract_method_arglist_indexer> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<scope> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<scope_lambda> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<scope_getset> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<control_structure_body> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<while_loop> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<if_body> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<else_body> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<for_body> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<for_each_body> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<if_else> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<switch_case> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<switch_> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<assembly_terminate> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<assembly> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<control_structure> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<exp_chain_start> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<exp_constant> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<exp_lambda> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<capture_list_item> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<capture_list> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<exp_value> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<exp_nullar> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<exp_unary> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<expression> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<encapsulation> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<namespace_> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<class_> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<method_arglist_item> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<method_arglist> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<method_arglist_indexer> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<method_meta> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<method> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<constructor> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<destructor> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<copystructor> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<conversion> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<indexer> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<operator_binary_overload> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<operator_unary_overload> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<operator_nullar_overload> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<property> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<field> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<constant> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<using_> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<alias_encapsulated> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<alias> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<call> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<call_body> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<free> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<alloc> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<typeof_> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<nameof> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<sizeof_> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<lifetime> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<type_match> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<string_formatable> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<string_literal> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<scalar_literal> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<integer_hex_literal> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<integer_binary_literal> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<integer_literal> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<char_literal> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<declaration> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<return_statement> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<statement> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<pragma> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<pragma_align> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<pragma_size> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<pragma_disable> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<pragma_enable> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<template_usage_item> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<template_usage> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<template_definition_item_direct_type> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<template_definition_item_identifier> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<template_definition> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<main> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<exp_chain> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<exp_binary_4> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<exp_binary_3> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<exp_binary_2> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<exp_binary_1> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<exp_arithmetic_2> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<exp_arithmetic_1> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<exp_compare> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<exp_equality> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<exp_and> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<exp_or> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<ident_navigation> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<type_navigation> node, std::string_view contents);
        class visitor
        {
        private:
            bool visit(std::shared_ptr<attribute_arg_item_a> node);
            bool visit(std::shared_ptr<attribute_arg_item_b> node);
            bool visit(std::shared_ptr<attribute_args_a> node);
            bool visit(std::shared_ptr<attribute_args_b> node);
            bool visit(std::shared_ptr<attribute_item> node);
            bool visit(std::shared_ptr<attribute> node);
            bool visit(std::shared_ptr<contract> node);
            bool visit(std::shared_ptr<contract_method> node);
            bool visit(std::shared_ptr<contract_constructor> node);
            bool visit(std::shared_ptr<contract_indexer> node);
            bool visit(std::shared_ptr<contract_operator_binary_overload> node);
            bool visit(std::shared_ptr<contract_operator_unary_overload> node);
            bool visit(std::shared_ptr<contract_operator_nullar_overload> node);
            bool visit(std::shared_ptr<contract_property> node);
            bool visit(std::shared_ptr<contract_field> node);
            bool visit(std::shared_ptr<contract_method_arglist> node);
            bool visit(std::shared_ptr<contract_method_arglist_indexer> node);
            bool visit(std::shared_ptr<scope> node);
            bool visit(std::shared_ptr<scope_lambda> node);
            bool visit(std::shared_ptr<scope_getset> node);
            bool visit(std::shared_ptr<control_structure_body> node);
            bool visit(std::shared_ptr<while_loop> node);
            bool visit(std::shared_ptr<if_body> node);
            bool visit(std::shared_ptr<else_body> node);
            bool visit(std::shared_ptr<for_body> node);
            bool visit(std::shared_ptr<for_each_body> node);
            bool visit(std::shared_ptr<if_else> node);
            bool visit(std::shared_ptr<switch_case> node);
            bool visit(std::shared_ptr<switch_> node);
            bool visit(std::shared_ptr<assembly_terminate> node);
            bool visit(std::shared_ptr<assembly> node);
            bool visit(std::shared_ptr<control_structure> node);
            bool visit(std::shared_ptr<exp_chain_start> node);
            bool visit(std::shared_ptr<exp_constant> node);
            bool visit(std::shared_ptr<exp_lambda> node);
            bool visit(std::shared_ptr<capture_list_item> node);
            bool visit(std::shared_ptr<capture_list> node);
            bool visit(std::shared_ptr<exp_value> node);
            bool visit(std::shared_ptr<exp_nullar> node);
            bool visit(std::shared_ptr<exp_unary> node);
            bool visit(std::shared_ptr<expression> node);
            bool visit(std::shared_ptr<encapsulation> node);
            bool visit(std::shared_ptr<namespace_> node);
            bool visit(std::shared_ptr<class_> node);
            bool visit(std::shared_ptr<method_arglist_item> node);
            bool visit(std::shared_ptr<method_arglist> node);
            bool visit(std::shared_ptr<method_arglist_indexer> node);
            bool visit(std::shared_ptr<method_meta> node);
            bool visit(std::shared_ptr<method> node);
            bool visit(std::shared_ptr<constructor> node);
            bool visit(std::shared_ptr<destructor> node);
            bool visit(std::shared_ptr<copystructor> node);
            bool visit(std::shared_ptr<conversion> node);
            bool visit(std::shared_ptr<indexer> node);
            bool visit(std::shared_ptr<operator_binary_overload> node);
            bool visit(std::shared_ptr<operator_unary_overload> node);
            bool visit(std::shared_ptr<operator_nullar_overload> node);
            bool visit(std::shared_ptr<property> node);
            bool visit(std::shared_ptr<field> node);
            bool visit(std::shared_ptr<constant> node);
            bool visit(std::shared_ptr<using_> node);
            bool visit(std::shared_ptr<alias_encapsulated> node);
            bool visit(std::shared_ptr<alias> node);
            bool visit(std::shared_ptr<call> node);
            bool visit(std::shared_ptr<call_body> node);
            bool visit(std::shared_ptr<free> node);
            bool visit(std::shared_ptr<alloc> node);
            bool visit(std::shared_ptr<typeof_> node);
            bool visit(std::shared_ptr<nameof> node);
            bool visit(std::shared_ptr<sizeof_> node);
            bool visit(std::shared_ptr<lifetime> node);
            bool visit(std::shared_ptr<type_match> node);
            bool visit(std::shared_ptr<string_formatable> node);
            bool visit(std::shared_ptr<string_literal> node);
            bool visit(std::shared_ptr<scalar_literal> node);
            bool visit(std::shared_ptr<integer_hex_literal> node);
            bool visit(std::shared_ptr<integer_binary_literal> node);
            bool visit(std::shared_ptr<integer_literal> node);
            bool visit(std::shared_ptr<char_literal> node);
            bool visit(std::shared_ptr<declaration> node);
            bool visit(std::shared_ptr<return_statement> node);
            bool visit(std::shared_ptr<statement> node);
            bool visit(std::shared_ptr<pragma> node);
            bool visit(std::shared_ptr<pragma_align> node);
            bool visit(std::shared_ptr<pragma_size> node);
            bool visit(std::shared_ptr<pragma_disable> node);
            bool visit(std::shared_ptr<pragma_enable> node);
            bool visit(std::shared_ptr<template_usage_item> node);
            bool visit(std::shared_ptr<template_usage> node);
            bool visit(std::shared_ptr<template_definition_item_direct_type> node);
            bool visit(std::shared_ptr<template_definition_item_identifier> node);
            bool visit(std::shared_ptr<template_definition> node);
            bool visit(std::shared_ptr<exp_chain> node);
            bool visit(std::shared_ptr<exp_binary_4> node);
            bool visit(std::shared_ptr<exp_binary_3> node);
            bool visit(std::shared_ptr<exp_binary_2> node);
            bool visit(std::shared_ptr<exp_binary_1> node);
            bool visit(std::shared_ptr<exp_arithmetic_2> node);
            bool visit(std::shared_ptr<exp_arithmetic_1> node);
            bool visit(std::shared_ptr<exp_compare> node);
            bool visit(std::shared_ptr<exp_equality> node);
            bool visit(std::shared_ptr<exp_and> node);
            bool visit(std::shared_ptr<exp_or> node);
            bool visit(std::shared_ptr<ident_navigation> node);
            bool visit(std::shared_ptr<type_navigation> node);
        protected:
            virtual bool visit_enter(std::shared_ptr<attribute_arg_item_a> node);
            virtual bool visit_enter(std::shared_ptr<attribute_arg_item_b> node);
            virtual bool visit_enter(std::shared_ptr<attribute_args_a> node);
            virtual bool visit_enter(std::shared_ptr<attribute_args_b> node);
            virtual bool visit_enter(std::shared_ptr<attribute_item> node);
            virtual bool visit_enter(std::shared_ptr<attribute> node);
            virtual bool visit_enter(std::shared_ptr<contract> node);
            virtual bool visit_enter(std::shared_ptr<contract_method> node);
            virtual bool visit_enter(std::shared_ptr<contract_constructor> node);
            virtual bool visit_enter(std::shared_ptr<contract_indexer> node);
            virtual bool visit_enter(std::shared_ptr<contract_operator_binary_overload> node);
            virtual bool visit_enter(std::shared_ptr<contract_operator_unary_overload> node);
            virtual bool visit_enter(std::shared_ptr<contract_operator_nullar_overload> node);
            virtual bool visit_enter(std::shared_ptr<contract_property> node);
            virtual bool visit_enter(std::shared_ptr<contract_field> node);
            virtual bool visit_enter(std::shared_ptr<contract_method_arglist> node);
            virtual bool visit_enter(std::shared_ptr<contract_method_arglist_indexer> node);
            virtual bool visit_enter(std::shared_ptr<scope> node);
            virtual bool visit_enter(std::shared_ptr<scope_lambda> node);
            virtual bool visit_enter(std::shared_ptr<scope_getset> node);
            virtual bool visit_enter(std::shared_ptr<control_structure_body> node);
            virtual bool visit_enter(std::shared_ptr<while_loop> node);
            virtual bool visit_enter(std::shared_ptr<if_body> node);
            virtual bool visit_enter(std::shared_ptr<else_body> node);
            virtual bool visit_enter(std::shared_ptr<for_body> node);
            virtual bool visit_enter(std::shared_ptr<for_each_body> node);
            virtual bool visit_enter(std::shared_ptr<if_else> node);
            virtual bool visit_enter(std::shared_ptr<switch_case> node);
            virtual bool visit_enter(std::shared_ptr<switch_> node);
            virtual bool visit_enter(std::shared_ptr<assembly_terminate> node);
            virtual bool visit_enter(std::shared_ptr<assembly> node);
            virtual bool visit_enter(std::shared_ptr<control_structure> node);
            virtual bool visit_enter(std::shared_ptr<exp_chain_start> node);
            virtual bool visit_enter(std::shared_ptr<exp_constant> node);
            virtual bool visit_enter(std::shared_ptr<exp_lambda> node);
            virtual bool visit_enter(std::shared_ptr<capture_list_item> node);
            virtual bool visit_enter(std::shared_ptr<capture_list> node);
            virtual bool visit_enter(std::shared_ptr<exp_value> node);
            virtual bool visit_enter(std::shared_ptr<exp_nullar> node);
            virtual bool visit_enter(std::shared_ptr<exp_unary> node);
            virtual bool visit_enter(std::shared_ptr<expression> node);
            virtual bool visit_enter(std::shared_ptr<encapsulation> node);
            virtual bool visit_enter(std::shared_ptr<namespace_> node);
            virtual bool visit_enter(std::shared_ptr<class_> node);
            virtual bool visit_enter(std::shared_ptr<method_arglist_item> node);
            virtual bool visit_enter(std::shared_ptr<method_arglist> node);
            virtual bool visit_enter(std::shared_ptr<method_arglist_indexer> node);
            virtual bool visit_enter(std::shared_ptr<method_meta> node);
            virtual bool visit_enter(std::shared_ptr<method> node);
            virtual bool visit_enter(std::shared_ptr<constructor> node);
            virtual bool visit_enter(std::shared_ptr<destructor> node);
            virtual bool visit_enter(std::shared_ptr<copystructor> node);
            virtual bool visit_enter(std::shared_ptr<conversion> node);
            virtual bool visit_enter(std::shared_ptr<indexer> node);
            virtual bool visit_enter(std::shared_ptr<operator_binary_overload> node);
            virtual bool visit_enter(std::shared_ptr<operator_unary_overload> node);
            virtual bool visit_enter(std::shared_ptr<operator_nullar_overload> node);
            virtual bool visit_enter(std::shared_ptr<property> node);
            virtual bool visit_enter(std::shared_ptr<field> node);
            virtual bool visit_enter(std::shared_ptr<constant> node);
            virtual bool visit_enter(std::shared_ptr<using_> node);
            virtual bool visit_enter(std::shared_ptr<alias_encapsulated> node);
            virtual bool visit_enter(std::shared_ptr<alias> node);
            virtual bool visit_enter(std::shared_ptr<call> node);
            virtual bool visit_enter(std::shared_ptr<call_body> node);
            virtual bool visit_enter(std::shared_ptr<free> node);
            virtual bool visit_enter(std::shared_ptr<alloc> node);
            virtual bool visit_enter(std::shared_ptr<typeof_> node);
            virtual bool visit_enter(std::shared_ptr<nameof> node);
            virtual bool visit_enter(std::shared_ptr<sizeof_> node);
            virtual bool visit_enter(std::shared_ptr<lifetime> node);
            virtual bool visit_enter(std::shared_ptr<type_match> node);
            virtual bool visit_enter(std::shared_ptr<string_formatable> node);
            virtual bool visit_enter(std::shared_ptr<string_literal> node);
            virtual bool visit_enter(std::shared_ptr<scalar_literal> node);
            virtual bool visit_enter(std::shared_ptr<integer_hex_literal> node);
            virtual bool visit_enter(std::shared_ptr<integer_binary_literal> node);
            virtual bool visit_enter(std::shared_ptr<integer_literal> node);
            virtual bool visit_enter(std::shared_ptr<char_literal> node);
            virtual bool visit_enter(std::shared_ptr<declaration> node);
            virtual bool visit_enter(std::shared_ptr<return_statement> node);
            virtual bool visit_enter(std::shared_ptr<statement> node);
            virtual bool visit_enter(std::shared_ptr<pragma> node);
            virtual bool visit_enter(std::shared_ptr<pragma_align> node);
            virtual bool visit_enter(std::shared_ptr<pragma_size> node);
            virtual bool visit_enter(std::shared_ptr<pragma_disable> node);
            virtual bool visit_enter(std::shared_ptr<pragma_enable> node);
            virtual bool visit_enter(std::shared_ptr<template_usage_item> node);
            virtual bool visit_enter(std::shared_ptr<template_usage> node);
            virtual bool visit_enter(std::shared_ptr<template_definition_item_direct_type> node);
            virtual bool visit_enter(std::shared_ptr<template_definition_item_identifier> node);
            virtual bool visit_enter(std::shared_ptr<template_definition> node);
            virtual bool visit_enter(std::shared_ptr<main> node);
            virtual bool visit_enter(std::shared_ptr<exp_chain> node);
            virtual bool visit_enter(std::shared_ptr<exp_binary_4> node);
            virtual bool visit_enter(std::shared_ptr<exp_binary_3> node);
            virtual bool visit_enter(std::shared_ptr<exp_binary_2> node);
            virtual bool visit_enter(std::shared_ptr<exp_binary_1> node);
            virtual bool visit_enter(std::shared_ptr<exp_arithmetic_2> node);
            virtual bool visit_enter(std::shared_ptr<exp_arithmetic_1> node);
            virtual bool visit_enter(std::shared_ptr<exp_compare> node);
            virtual bool visit_enter(std::shared_ptr<exp_equality> node);
            virtual bool visit_enter(std::shared_ptr<exp_and> node);
            virtual bool visit_enter(std::shared_ptr<exp_or> node);
            virtual bool visit_enter(std::shared_ptr<ident_navigation> node);
            virtual bool visit_enter(std::shared_ptr<type_navigation> node);
            virtual bool visit_leave(std::shared_ptr<attribute_arg_item_a> node);
            virtual bool visit_leave(std::shared_ptr<attribute_arg_item_b> node);
            virtual bool visit_leave(std::shared_ptr<attribute_args_a> node);
            virtual bool visit_leave(std::shared_ptr<attribute_args_b> node);
            virtual bool visit_leave(std::shared_ptr<attribute_item> node);
            virtual bool visit_leave(std::shared_ptr<attribute> node);
            virtual bool visit_leave(std::shared_ptr<contract> node);
            virtual bool visit_leave(std::shared_ptr<contract_method> node);
            virtual bool visit_leave(std::shared_ptr<contract_constructor> node);
            virtual bool visit_leave(std::shared_ptr<contract_indexer> node);
            virtual bool visit_leave(std::shared_ptr<contract_operator_binary_overload> node);
            virtual bool visit_leave(std::shared_ptr<contract_operator_unary_overload> node);
            virtual bool visit_leave(std::shared_ptr<contract_operator_nullar_overload> node);
            virtual bool visit_leave(std::shared_ptr<contract_property> node);
            virtual bool visit_leave(std::shared_ptr<contract_field> node);
            virtual bool visit_leave(std::shared_ptr<contract_method_arglist> node);
            virtual bool visit_leave(std::shared_ptr<contract_method_arglist_indexer> node);
            virtual bool visit_leave(std::shared_ptr<scope> node);
            virtual bool visit_leave(std::shared_ptr<scope_lambda> node);
            virtual bool visit_leave(std::shared_ptr<scope_getset> node);
            virtual bool visit_leave(std::shared_ptr<control_structure_body> node);
            virtual bool visit_leave(std::shared_ptr<while_loop> node);
            virtual bool visit_leave(std::shared_ptr<if_body> node);
            virtual bool visit_leave(std::shared_ptr<else_body> node);
            virtual bool visit_leave(std::shared_ptr<for_body> node);
            virtual bool visit_leave(std::shared_ptr<for_each_body> node);
            virtual bool visit_leave(std::shared_ptr<if_else> node);
            virtual bool visit_leave(std::shared_ptr<switch_case> node);
            virtual bool visit_leave(std::shared_ptr<switch_> node);
            virtual bool visit_leave(std::shared_ptr<assembly_terminate> node);
            virtual bool visit_leave(std::shared_ptr<assembly> node);
            virtual bool visit_leave(std::shared_ptr<control_structure> node);
            virtual bool visit_leave(std::shared_ptr<exp_chain_start> node);
            virtual bool visit_leave(std::shared_ptr<exp_constant> node);
            virtual bool visit_leave(std::shared_ptr<exp_lambda> node);
            virtual bool visit_leave(std::shared_ptr<capture_list_item> node);
            virtual bool visit_leave(std::shared_ptr<capture_list> node);
            virtual bool visit_leave(std::shared_ptr<exp_value> node);
            virtual bool visit_leave(std::shared_ptr<exp_nullar> node);
            virtual bool visit_leave(std::shared_ptr<exp_unary> node);
            virtual bool visit_leave(std::shared_ptr<expression> node);
            virtual bool visit_leave(std::shared_ptr<encapsulation> node);
            virtual bool visit_leave(std::shared_ptr<namespace_> node);
            virtual bool visit_leave(std::shared_ptr<class_> node);
            virtual bool visit_leave(std::shared_ptr<method_arglist_item> node);
            virtual bool visit_leave(std::shared_ptr<method_arglist> node);
            virtual bool visit_leave(std::shared_ptr<method_arglist_indexer> node);
            virtual bool visit_leave(std::shared_ptr<method_meta> node);
            virtual bool visit_leave(std::shared_ptr<method> node);
            virtual bool visit_leave(std::shared_ptr<constructor> node);
            virtual bool visit_leave(std::shared_ptr<destructor> node);
            virtual bool visit_leave(std::shared_ptr<copystructor> node);
            virtual bool visit_leave(std::shared_ptr<conversion> node);
            virtual bool visit_leave(std::shared_ptr<indexer> node);
            virtual bool visit_leave(std::shared_ptr<operator_binary_overload> node);
            virtual bool visit_leave(std::shared_ptr<operator_unary_overload> node);
            virtual bool visit_leave(std::shared_ptr<operator_nullar_overload> node);
            virtual bool visit_leave(std::shared_ptr<property> node);
            virtual bool visit_leave(std::shared_ptr<field> node);
            virtual bool visit_leave(std::shared_ptr<constant> node);
            virtual bool visit_leave(std::shared_ptr<using_> node);
            virtual bool visit_leave(std::shared_ptr<alias_encapsulated> node);
            virtual bool visit_leave(std::shared_ptr<alias> node);
            virtual bool visit_leave(std::shared_ptr<call> node);
            virtual bool visit_leave(std::shared_ptr<call_body> node);
            virtual bool visit_leave(std::shared_ptr<free> node);
            virtual bool visit_leave(std::shared_ptr<alloc> node);
            virtual bool visit_leave(std::shared_ptr<typeof_> node);
            virtual bool visit_leave(std::shared_ptr<nameof> node);
            virtual bool visit_leave(std::shared_ptr<sizeof_> node);
            virtual bool visit_leave(std::shared_ptr<lifetime> node);
            virtual bool visit_leave(std::shared_ptr<type_match> node);
            virtual bool visit_leave(std::shared_ptr<string_formatable> node);
            virtual bool visit_leave(std::shared_ptr<string_literal> node);
            virtual bool visit_leave(std::shared_ptr<scalar_literal> node);
            virtual bool visit_leave(std::shared_ptr<integer_hex_literal> node);
            virtual bool visit_leave(std::shared_ptr<integer_binary_literal> node);
            virtual bool visit_leave(std::shared_ptr<integer_literal> node);
            virtual bool visit_leave(std::shared_ptr<char_literal> node);
            virtual bool visit_leave(std::shared_ptr<declaration> node);
            virtual bool visit_leave(std::shared_ptr<return_statement> node);
            virtual bool visit_leave(std::shared_ptr<statement> node);
            virtual bool visit_leave(std::shared_ptr<pragma> node);
            virtual bool visit_leave(std::shared_ptr<pragma_align> node);
            virtual bool visit_leave(std::shared_ptr<pragma_size> node);
            virtual bool visit_leave(std::shared_ptr<pragma_disable> node);
            virtual bool visit_leave(std::shared_ptr<pragma_enable> node);
            virtual bool visit_leave(std::shared_ptr<template_usage_item> node);
            virtual bool visit_leave(std::shared_ptr<template_usage> node);
            virtual bool visit_leave(std::shared_ptr<template_definition_item_direct_type> node);
            virtual bool visit_leave(std::shared_ptr<template_definition_item_identifier> node);
            virtual bool visit_leave(std::shared_ptr<template_definition> node);
            virtual bool visit_leave(std::shared_ptr<main> node);
            virtual bool visit_leave(std::shared_ptr<exp_chain> node);
            virtual bool visit_leave(std::shared_ptr<exp_binary_4> node);
            virtual bool visit_leave(std::shared_ptr<exp_binary_3> node);
            virtual bool visit_leave(std::shared_ptr<exp_binary_2> node);
            virtual bool visit_leave(std::shared_ptr<exp_binary_1> node);
            virtual bool visit_leave(std::shared_ptr<exp_arithmetic_2> node);
            virtual bool visit_leave(std::shared_ptr<exp_arithmetic_1> node);
            virtual bool visit_leave(std::shared_ptr<exp_compare> node);
            virtual bool visit_leave(std::shared_ptr<exp_equality> node);
            virtual bool visit_leave(std::shared_ptr<exp_and> node);
            virtual bool visit_leave(std::shared_ptr<exp_or> node);
            virtual bool visit_leave(std::shared_ptr<ident_navigation> node);
            virtual bool visit_leave(std::shared_ptr<type_navigation> node);
        public:
            bool visit(std::shared_ptr<main> node);
        };
    };
}
#endif // INCLUDE_GUARD_PARSER_CPP_INSTANCE
