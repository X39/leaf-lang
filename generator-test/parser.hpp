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
        class resetable;
    public:
        class token;
        class attribute_arg_item_a;
        class attribute_arg_item_b;
        class attribute_args_a;
        class attribute_args_b;
        class attribute_item;
        class attribute;
        class scope;
        class scope_getset;
        class control_structure_body;
        class while_loop;
        class if_body;
        class else_body;
        class if_else;
        class switch_case;
        class switch_;
        class assembly_terminate;
        class assembly;
        class control_structure;
        class exp_chain_start;
        class exp_constant;
        class exp_value;
        class exp_nullar;
        class exp_unary;
        class expression;
        class encapsulation;
        class namespace_;
        class class_;
        class method_arglist_item_with_default;
        class method_arglist_item;
        class method_arglist;
        class method_arglist_indexer;
        class method;
        class constructor;
        class destructor;
        class copystructor;
        class conversion;
        class indexer;
        class operator_binary_overload;
        class operator_unary_overload;
        class property;
        class field;
        class using_;
        class call;
        class call_body;
        class free;
        class alloc;
        class template_usage_item;
        class template_usage;
        class template_definition_item;
        class template_definition;
        class typeof_;
        class nameof;
        class sizeof_;
        class type_match;
        class string_formatable;
        class string_literal;
        class scalar_literal;
        class integer_hex_literal;
        class integer_binary_literal;
        class integer_literal;
        class char_literal;
        class declaration;
        class statement;
        class pragma;
        class pragma_align;
        class pragma_size;
        class pragma_disable;
        class pragma_enable;
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
        class scope_state;
        class scope_getset_state;
        class control_structure_body_state;
        class while_loop_state;
        class if_body_state;
        class else_body_state;
        class if_else_state;
        class switch_case_state;
        class switch__state;
        class assembly_terminate_state;
        class assembly_state;
        class control_structure_state;
        class exp_chain_start_state;
        class exp_constant_state;
        class exp_value_state;
        class exp_nullar_state;
        class exp_unary_state;
        class expression_state;
        class encapsulation_state;
        class namespace__state;
        class class__state;
        class method_arglist_item_with_default_state;
        class method_arglist_item_state;
        class method_arglist_state;
        class method_arglist_indexer_state;
        class method_state;
        class constructor_state;
        class destructor_state;
        class copystructor_state;
        class conversion_state;
        class indexer_state;
        class operator_binary_overload_state;
        class operator_unary_overload_state;
        class property_state;
        class field_state;
        class using__state;
        class call_state;
        class call_body_state;
        class free_state;
        class alloc_state;
        class template_usage_item_state;
        class template_usage_state;
        class template_definition_item_state;
        class template_definition_state;
        class typeof__state;
        class nameof_state;
        class sizeof__state;
        class type_match_state;
        class string_formatable_state;
        class string_literal_state;
        class scalar_literal_state;
        class integer_hex_literal_state;
        class integer_binary_literal_state;
        class integer_literal_state;
        class char_literal_state;
        class declaration_state;
        class statement_state;
        class pragma_state;
        class pragma_align_state;
        class pragma_size_state;
        class pragma_disable_state;
        class pragma_enable_state;
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
        class resetable
        {
        public:
            instance& m_ref;
            std::string_view m_contents;
            std::string m_file;
            size_t m_line;
            size_t m_column;
            size_t m_offset;
             resetable(instance& ref);
            void reset();
        };
        friend class resetable;
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
        std::optional<size_t> token__round_bracked_open(size_t depth);
        std::optional<size_t> token__round_bracked_close(size_t depth);
        std::optional<size_t> token__square_bracked_open(size_t depth);
        std::optional<size_t> token__square_bracked_close(size_t depth);
        std::optional<size_t> token__curly_bracked_open(size_t depth);
        std::optional<size_t> token__curly_bracked_close(size_t depth);
        std::optional<size_t> token__get(size_t depth);
        std::optional<size_t> token__set(size_t depth);
        std::optional<size_t> token__while(size_t depth);
        std::optional<size_t> token__if(size_t depth);
        std::optional<size_t> token__else(size_t depth);
        std::optional<size_t> token__case(size_t depth);
        std::optional<size_t> token__switch(size_t depth);
        std::optional<size_t> token__default(size_t depth);
        std::optional<size_t> token__eol(size_t depth);
        std::optional<size_t> token__assembly(size_t depth);
        std::optional<size_t> token__dot(size_t depth);
        std::optional<size_t> token__exclamation(size_t depth);
        std::optional<size_t> token__tilde(size_t depth);
        std::optional<size_t> token__less_then_less_then(size_t depth);
        std::optional<size_t> token__greater_then_greater_then(size_t depth);
        std::optional<size_t> token__less_then_less_then_less_then(size_t depth);
        std::optional<size_t> token__greater_then_greater_then_greater_then(size_t depth);
        std::optional<size_t> token__ampersand(size_t depth);
        std::optional<size_t> token__circumflex(size_t depth);
        std::optional<size_t> token__vertical_bar(size_t depth);
        std::optional<size_t> token__less_then_equal(size_t depth);
        std::optional<size_t> token__less_then(size_t depth);
        std::optional<size_t> token__greater_then_equal(size_t depth);
        std::optional<size_t> token__greater_then(size_t depth);
        std::optional<size_t> token__exclamation_equal(size_t depth);
        std::optional<size_t> token__equal_equal_equal(size_t depth);
        std::optional<size_t> token__equal_equal(size_t depth);
        std::optional<size_t> token__tilde_equal(size_t depth);
        std::optional<size_t> token__ampersand_ampersand(size_t depth);
        std::optional<size_t> token__vertical_bar_vertical_bar(size_t depth);
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
        std::optional<size_t> token__operator(size_t depth);
        std::optional<size_t> token__semicolon(size_t depth);
        std::optional<size_t> token__using(size_t depth);
        std::optional<size_t> token__free(size_t depth);
        std::optional<size_t> token__alloc(size_t depth);
        std::optional<size_t> token__stack(size_t depth);
        std::optional<size_t> token__heap(size_t depth);
        std::optional<size_t> token__typeof(size_t depth);
        std::optional<size_t> token__nameof(size_t depth);
        std::optional<size_t> token__sizeof(size_t depth);
        std::optional<size_t> token__return(size_t depth);
        std::optional<size_t> token__auto_626(size_t depth);
        std::optional<size_t> token__exclamation_greater_then(size_t depth);
        std::optional<size_t> token__align(size_t depth);
        std::optional<size_t> token__size(size_t depth);
        std::optional<size_t> token__disable(size_t depth);
        std::optional<size_t> token__enable(size_t depth);
        bool m_expor_92(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_arg_item_a>& actual, leaf::parsing::instance::attribute_arg_item_a_state& state, size_t depth);
        bool p_can_attribute_arg_item_a(size_t depth);
        std::shared_ptr<leaf::parsing::instance::attribute_arg_item_a> p_match_attribute_arg_item_a(size_t depth);
        bool m_ident_colon_expor_93(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_arg_item_b>& actual, leaf::parsing::instance::attribute_arg_item_b_state& state, size_t depth);
        bool p_can_attribute_arg_item_b(size_t depth);
        std::shared_ptr<leaf::parsing::instance::attribute_arg_item_b> p_match_attribute_arg_item_b(size_t depth);
        bool m_attributeargitema_94(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_a>& actual, leaf::parsing::instance::attribute_args_a_state& state, size_t depth);
        bool m_attributeargitema_95(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_a>& actual, leaf::parsing::instance::attribute_args_a_state& state, size_t depth);
        bool m_comma_attributeargitema_96(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_a>& actual, leaf::parsing::instance::attribute_args_a_state& state, size_t depth);
        bool while97_98(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_a>& actual, leaf::parsing::instance::attribute_args_a_state& state, size_t depth);
        bool m_comma_99(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_a>& actual, leaf::parsing::instance::attribute_args_a_state& state, size_t depth);
        bool m_comma_100(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_a>& actual, leaf::parsing::instance::attribute_args_a_state& state, size_t depth);
        bool if101_102(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_a>& actual, leaf::parsing::instance::attribute_args_a_state& state, size_t depth);
        bool p_can_attribute_args_a(size_t depth);
        std::shared_ptr<leaf::parsing::instance::attribute_args_a> p_match_attribute_args_a(size_t depth);
        bool m_attributeargitemb_103(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_b>& actual, leaf::parsing::instance::attribute_args_b_state& state, size_t depth);
        bool m_attributeargitemb_104(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_b>& actual, leaf::parsing::instance::attribute_args_b_state& state, size_t depth);
        bool m_comma_attributeargitemb_105(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_b>& actual, leaf::parsing::instance::attribute_args_b_state& state, size_t depth);
        bool while106_107(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_b>& actual, leaf::parsing::instance::attribute_args_b_state& state, size_t depth);
        bool m_comma_108(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_b>& actual, leaf::parsing::instance::attribute_args_b_state& state, size_t depth);
        bool m_comma_109(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_b>& actual, leaf::parsing::instance::attribute_args_b_state& state, size_t depth);
        bool if110_111(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_b>& actual, leaf::parsing::instance::attribute_args_b_state& state, size_t depth);
        bool p_can_attribute_args_b(size_t depth);
        std::shared_ptr<leaf::parsing::instance::attribute_args_b> p_match_attribute_args_b(size_t depth);
        bool m_typematch_112(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_item>& actual, leaf::parsing::instance::attribute_item_state& state, size_t depth);
        bool m_typematch_roundbrackedopen_roundbrackedclose_113(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_item>& actual, leaf::parsing::instance::attribute_item_state& state, size_t depth);
        bool m_typematch_roundbrackedopen_attributeargsa_attributeargsb_roundbrackedclose_114(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_item>& actual, leaf::parsing::instance::attribute_item_state& state, size_t depth);
        bool m_typematch_roundbrackedopen_attributeargsa_roundbrackedclose_115(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_item>& actual, leaf::parsing::instance::attribute_item_state& state, size_t depth);
        bool m_typematch_roundbrackedopen_attributeargsb_roundbrackedclose_116(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_item>& actual, leaf::parsing::instance::attribute_item_state& state, size_t depth);
        bool alternatives117(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_item>& actual, leaf::parsing::instance::attribute_item_state& state, size_t depth);
        bool p_can_attribute_item(size_t depth);
        std::shared_ptr<leaf::parsing::instance::attribute_item> p_match_attribute_item(size_t depth);
        bool m_squarebrackedopen_118(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute>& actual, leaf::parsing::instance::attribute_state& state, size_t depth);
        bool m_attributeitem_119(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute>& actual, leaf::parsing::instance::attribute_state& state, size_t depth);
        bool m_attributeitem_120(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute>& actual, leaf::parsing::instance::attribute_state& state, size_t depth);
        bool m_attributeitem_121(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute>& actual, leaf::parsing::instance::attribute_state& state, size_t depth);
        bool m_comma_attributeitem_122(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute>& actual, leaf::parsing::instance::attribute_state& state, size_t depth);
        bool while123_124(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute>& actual, leaf::parsing::instance::attribute_state& state, size_t depth);
        bool m_comma_125(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute>& actual, leaf::parsing::instance::attribute_state& state, size_t depth);
        bool m_comma_126(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute>& actual, leaf::parsing::instance::attribute_state& state, size_t depth);
        bool if127_128(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute>& actual, leaf::parsing::instance::attribute_state& state, size_t depth);
        bool if129_130(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute>& actual, leaf::parsing::instance::attribute_state& state, size_t depth);
        bool m_squarebrackedclose_131(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute>& actual, leaf::parsing::instance::attribute_state& state, size_t depth);
        bool p_can_attribute(size_t depth);
        std::shared_ptr<leaf::parsing::instance::attribute> p_match_attribute(size_t depth);
        bool m_curlybrackedopen_132(bool is_can, std::shared_ptr<leaf::parsing::instance::scope>& actual, leaf::parsing::instance::scope_state& state, size_t depth);
        bool m_curlybrackedclose_133(bool is_can, std::shared_ptr<leaf::parsing::instance::scope>& actual, leaf::parsing::instance::scope_state& state, size_t depth);
        bool m_using_134(bool is_can, std::shared_ptr<leaf::parsing::instance::scope>& actual, leaf::parsing::instance::scope_state& state, size_t depth);
        bool m_controlstructure_135(bool is_can, std::shared_ptr<leaf::parsing::instance::scope>& actual, leaf::parsing::instance::scope_state& state, size_t depth);
        bool m_statement_136(bool is_can, std::shared_ptr<leaf::parsing::instance::scope>& actual, leaf::parsing::instance::scope_state& state, size_t depth);
        bool alternatives137(bool is_can, std::shared_ptr<leaf::parsing::instance::scope>& actual, leaf::parsing::instance::scope_state& state, size_t depth);
        bool while138_139(bool is_can, std::shared_ptr<leaf::parsing::instance::scope>& actual, leaf::parsing::instance::scope_state& state, size_t depth);
        bool m_curlybrackedclose_140(bool is_can, std::shared_ptr<leaf::parsing::instance::scope>& actual, leaf::parsing::instance::scope_state& state, size_t depth);
        bool p_can_scope(size_t depth);
        std::shared_ptr<leaf::parsing::instance::scope> p_match_scope(size_t depth);
        bool m_curlybrackedopen_141(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_getset>& actual, leaf::parsing::instance::scope_getset_state& state, size_t depth);
        bool m_get_scope_set_scope_142(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_getset>& actual, leaf::parsing::instance::scope_getset_state& state, size_t depth);
        bool m_set_scope_get_scope_143(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_getset>& actual, leaf::parsing::instance::scope_getset_state& state, size_t depth);
        bool m_get_scope_144(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_getset>& actual, leaf::parsing::instance::scope_getset_state& state, size_t depth);
        bool m_set_scope_145(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_getset>& actual, leaf::parsing::instance::scope_getset_state& state, size_t depth);
        bool alternatives146(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_getset>& actual, leaf::parsing::instance::scope_getset_state& state, size_t depth);
        bool m_curlybrackedclose_147(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_getset>& actual, leaf::parsing::instance::scope_getset_state& state, size_t depth);
        bool p_can_scope_getset(size_t depth);
        std::shared_ptr<leaf::parsing::instance::scope_getset> p_match_scope_getset(size_t depth);
        bool m_scope_148(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure_body>& actual, leaf::parsing::instance::control_structure_body_state& state, size_t depth);
        bool m_controlstructure_149(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure_body>& actual, leaf::parsing::instance::control_structure_body_state& state, size_t depth);
        bool m_statement_150(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure_body>& actual, leaf::parsing::instance::control_structure_body_state& state, size_t depth);
        bool alternatives151(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure_body>& actual, leaf::parsing::instance::control_structure_body_state& state, size_t depth);
        bool p_can_control_structure_body(size_t depth);
        std::shared_ptr<leaf::parsing::instance::control_structure_body> p_match_control_structure_body(size_t depth);
        bool m_while_roundbrackedopen_expression_roundbrackedclose_controlstructurebody_152(bool is_can, std::shared_ptr<leaf::parsing::instance::while_loop>& actual, leaf::parsing::instance::while_loop_state& state, size_t depth);
        bool p_can_while_loop(size_t depth);
        std::shared_ptr<leaf::parsing::instance::while_loop> p_match_while_loop(size_t depth);
        bool m_if_roundbrackedopen_expression_roundbrackedclose_controlstructurebody_153(bool is_can, std::shared_ptr<leaf::parsing::instance::if_body>& actual, leaf::parsing::instance::if_body_state& state, size_t depth);
        bool p_can_if_body(size_t depth);
        std::shared_ptr<leaf::parsing::instance::if_body> p_match_if_body(size_t depth);
        bool m_else_controlstructurebody_154(bool is_can, std::shared_ptr<leaf::parsing::instance::else_body>& actual, leaf::parsing::instance::else_body_state& state, size_t depth);
        bool p_can_else_body(size_t depth);
        std::shared_ptr<leaf::parsing::instance::else_body> p_match_else_body(size_t depth);
        bool m_ifbody_155(bool is_can, std::shared_ptr<leaf::parsing::instance::if_else>& actual, leaf::parsing::instance::if_else_state& state, size_t depth);
        bool m_elsebody_156(bool is_can, std::shared_ptr<leaf::parsing::instance::if_else>& actual, leaf::parsing::instance::if_else_state& state, size_t depth);
        bool m_elsebody_157(bool is_can, std::shared_ptr<leaf::parsing::instance::if_else>& actual, leaf::parsing::instance::if_else_state& state, size_t depth);
        bool if158_159(bool is_can, std::shared_ptr<leaf::parsing::instance::if_else>& actual, leaf::parsing::instance::if_else_state& state, size_t depth);
        bool p_can_if_else(size_t depth);
        std::shared_ptr<leaf::parsing::instance::if_else> p_match_if_else(size_t depth);
        bool m_case_expvalue_colon_controlstructurebody_160(bool is_can, std::shared_ptr<leaf::parsing::instance::switch_case>& actual, leaf::parsing::instance::switch_case_state& state, size_t depth);
        bool p_can_switch_case(size_t depth);
        std::shared_ptr<leaf::parsing::instance::switch_case> p_match_switch_case(size_t depth);
        bool m_switch_roundbrackedopen_expression_roundbrackedclose_161(bool is_can, std::shared_ptr<leaf::parsing::instance::switch_>& actual, leaf::parsing::instance::switch__state& state, size_t depth);
        bool m_curlybrackedclose_162(bool is_can, std::shared_ptr<leaf::parsing::instance::switch_>& actual, leaf::parsing::instance::switch__state& state, size_t depth);
        bool m_switchcase_163(bool is_can, std::shared_ptr<leaf::parsing::instance::switch_>& actual, leaf::parsing::instance::switch__state& state, size_t depth);
        bool if164_165(bool is_can, std::shared_ptr<leaf::parsing::instance::switch_>& actual, leaf::parsing::instance::switch__state& state, size_t depth);
        bool m_default_colon_controlstructurebody_166(bool is_can, std::shared_ptr<leaf::parsing::instance::switch_>& actual, leaf::parsing::instance::switch__state& state, size_t depth);
        bool m_pragma_167(bool is_can, std::shared_ptr<leaf::parsing::instance::switch_>& actual, leaf::parsing::instance::switch__state& state, size_t depth);
        bool alternatives168(bool is_can, std::shared_ptr<leaf::parsing::instance::switch_>& actual, leaf::parsing::instance::switch__state& state, size_t depth);
        bool while169_170(bool is_can, std::shared_ptr<leaf::parsing::instance::switch_>& actual, leaf::parsing::instance::switch__state& state, size_t depth);
        bool m_curlybrackedclose_171(bool is_can, std::shared_ptr<leaf::parsing::instance::switch_>& actual, leaf::parsing::instance::switch__state& state, size_t depth);
        bool p_can_switch_(size_t depth);
        std::shared_ptr<leaf::parsing::instance::switch_> p_match_switch_(size_t depth);
        bool m_eol_172(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly_terminate>& actual, leaf::parsing::instance::assembly_terminate_state& state, size_t depth);
        bool m_curlybrackedclose_173(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly_terminate>& actual, leaf::parsing::instance::assembly_terminate_state& state, size_t depth);
        bool alternatives174(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly_terminate>& actual, leaf::parsing::instance::assembly_terminate_state& state, size_t depth);
        bool p_can_assembly_terminate(size_t depth);
        std::shared_ptr<leaf::parsing::instance::assembly_terminate> p_match_assembly_terminate(size_t depth);
        bool m_assembly_curlybrackedopen_175(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth);
        bool m_curlybrackedclose_176(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth);
        bool m_assemblyterminate_177(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth);
        bool m_scalar_178(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth);
        bool m_integerbinary_179(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth);
        bool m_integerhex_180(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth);
        bool m_integer_181(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth);
        bool alternatives182(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth);
        bool while183_184(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth);
        bool m_ident_185(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth);
        bool while186_187(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth);
        bool m_curlybrackedclose_188(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth);
        bool p_can_assembly(size_t depth);
        std::shared_ptr<leaf::parsing::instance::assembly> p_match_assembly(size_t depth);
        bool m_pragma_189(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure>& actual, leaf::parsing::instance::control_structure_state& state, size_t depth);
        bool m_whileloop_190(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure>& actual, leaf::parsing::instance::control_structure_state& state, size_t depth);
        bool m_ifelse_191(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure>& actual, leaf::parsing::instance::control_structure_state& state, size_t depth);
        bool m_switch_192(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure>& actual, leaf::parsing::instance::control_structure_state& state, size_t depth);
        bool m_scope_193(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure>& actual, leaf::parsing::instance::control_structure_state& state, size_t depth);
        bool m_assembly_194(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure>& actual, leaf::parsing::instance::control_structure_state& state, size_t depth);
        bool alternatives195(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure>& actual, leaf::parsing::instance::control_structure_state& state, size_t depth);
        bool p_can_control_structure(size_t depth);
        std::shared_ptr<leaf::parsing::instance::control_structure> p_match_control_structure(size_t depth);
        bool m_alloc_196(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_chain_start>& actual, leaf::parsing::instance::exp_chain_start_state& state, size_t depth);
        bool m_free_197(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_chain_start>& actual, leaf::parsing::instance::exp_chain_start_state& state, size_t depth);
        bool m_call_198(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_chain_start>& actual, leaf::parsing::instance::exp_chain_start_state& state, size_t depth);
        bool m_ident_199(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_chain_start>& actual, leaf::parsing::instance::exp_chain_start_state& state, size_t depth);
        bool alternatives200(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_chain_start>& actual, leaf::parsing::instance::exp_chain_start_state& state, size_t depth);
        bool p_can_exp_chain_start(size_t depth);
        std::shared_ptr<leaf::parsing::instance::exp_chain_start> p_match_exp_chain_start(size_t depth);
        bool m_typeof_201(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth);
        bool m_nameof_202(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth);
        bool m_sizeof_203(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth);
        bool m_scalar_204(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth);
        bool m_false_205(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth);
        bool m_true_206(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth);
        bool m_integerhex_207(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth);
        bool m_integerbinary_208(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth);
        bool m_integer_209(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth);
        bool m_string_210(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth);
        bool m_char_211(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth);
        bool alternatives212(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth);
        bool p_can_exp_constant(size_t depth);
        std::shared_ptr<leaf::parsing::instance::exp_constant> p_match_exp_constant(size_t depth);
        bool m_scalarliteral_213(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_value>& actual, leaf::parsing::instance::exp_value_state& state, size_t depth);
        bool m_integerhexliteral_214(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_value>& actual, leaf::parsing::instance::exp_value_state& state, size_t depth);
        bool m_integerbinaryliteral_215(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_value>& actual, leaf::parsing::instance::exp_value_state& state, size_t depth);
        bool m_integerliteral_216(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_value>& actual, leaf::parsing::instance::exp_value_state& state, size_t depth);
        bool m_charliteral_217(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_value>& actual, leaf::parsing::instance::exp_value_state& state, size_t depth);
        bool m_stringliteral_218(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_value>& actual, leaf::parsing::instance::exp_value_state& state, size_t depth);
        bool m_expconstant_219(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_value>& actual, leaf::parsing::instance::exp_value_state& state, size_t depth);
        bool alternatives220(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_value>& actual, leaf::parsing::instance::exp_value_state& state, size_t depth);
        bool p_can_exp_value(size_t depth);
        std::shared_ptr<leaf::parsing::instance::exp_value> p_match_exp_value(size_t depth);
        bool m_roundbrackedopen_expression_roundbrackedclose_221(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_nullar>& actual, leaf::parsing::instance::exp_nullar_state& state, size_t depth);
        bool m_expchain_222(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_nullar>& actual, leaf::parsing::instance::exp_nullar_state& state, size_t depth);
        bool m_expvalue_223(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_nullar>& actual, leaf::parsing::instance::exp_nullar_state& state, size_t depth);
        bool alternatives224(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_nullar>& actual, leaf::parsing::instance::exp_nullar_state& state, size_t depth);
        bool p_can_exp_nullar(size_t depth);
        std::shared_ptr<leaf::parsing::instance::exp_nullar> p_match_exp_nullar(size_t depth);
        bool m_exclamation_expunary_225(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_unary>& actual, leaf::parsing::instance::exp_unary_state& state, size_t depth);
        bool m_tilde_expunary_226(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_unary>& actual, leaf::parsing::instance::exp_unary_state& state, size_t depth);
        bool m_minus_expunary_227(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_unary>& actual, leaf::parsing::instance::exp_unary_state& state, size_t depth);
        bool m_plus_expunary_228(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_unary>& actual, leaf::parsing::instance::exp_unary_state& state, size_t depth);
        bool m_roundbrackedopen_typematch_roundbrackedclose_expunary_229(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_unary>& actual, leaf::parsing::instance::exp_unary_state& state, size_t depth);
        bool m_expnullar_230(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_unary>& actual, leaf::parsing::instance::exp_unary_state& state, size_t depth);
        bool alternatives231(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_unary>& actual, leaf::parsing::instance::exp_unary_state& state, size_t depth);
        bool p_can_exp_unary(size_t depth);
        std::shared_ptr<leaf::parsing::instance::exp_unary> p_match_exp_unary(size_t depth);
        bool m_expor_equal_expression_232(bool is_can, std::shared_ptr<leaf::parsing::instance::expression>& actual, leaf::parsing::instance::expression_state& state, size_t depth);
        bool m_expor_233(bool is_can, std::shared_ptr<leaf::parsing::instance::expression>& actual, leaf::parsing::instance::expression_state& state, size_t depth);
        bool p_can_expression(size_t depth);
        std::shared_ptr<leaf::parsing::instance::expression> p_match_expression(size_t depth);
        bool m_public_234(bool is_can, std::shared_ptr<leaf::parsing::instance::encapsulation>& actual, leaf::parsing::instance::encapsulation_state& state, size_t depth);
        bool m_local_235(bool is_can, std::shared_ptr<leaf::parsing::instance::encapsulation>& actual, leaf::parsing::instance::encapsulation_state& state, size_t depth);
        bool m_derived_236(bool is_can, std::shared_ptr<leaf::parsing::instance::encapsulation>& actual, leaf::parsing::instance::encapsulation_state& state, size_t depth);
        bool m_private_237(bool is_can, std::shared_ptr<leaf::parsing::instance::encapsulation>& actual, leaf::parsing::instance::encapsulation_state& state, size_t depth);
        bool alternatives238(bool is_can, std::shared_ptr<leaf::parsing::instance::encapsulation>& actual, leaf::parsing::instance::encapsulation_state& state, size_t depth);
        bool p_can_encapsulation(size_t depth);
        std::shared_ptr<leaf::parsing::instance::encapsulation> p_match_encapsulation(size_t depth);
        bool m_attribute_239(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool m_attribute_240(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool while241_242(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool m_namespace_identnavigation_243(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool m_curlybrackedopen_244(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool m_curlybrackedclose_245(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool m_using_246(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool m_namespace_247(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool m_conversion_248(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool m_class_249(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool m_method_250(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool m_property_251(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool m_field_252(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool m_pragma_253(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool alternatives254(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool while255_256(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool m_curlybrackedclose_257(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth);
        bool p_can_namespace_(size_t depth);
        std::shared_ptr<leaf::parsing::instance::namespace_> p_match_namespace_(size_t depth);
        bool m_attribute_258(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_attribute_259(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool while260_261(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_encapsulation_class_ident_262(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_curlybrackedopen_263(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_curlybrackedclose_264(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_using_265(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_indexer_266(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_operatorbinaryoverload_267(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_operatorunaryoverload_268(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_conversion_269(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_class_270(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_constructor_271(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_destructor_272(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_copystructor_273(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_property_274(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_field_275(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_method_276(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_pragma_277(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool alternatives278(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool while279_280(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool m_curlybrackedclose_281(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth);
        bool p_can_class_(size_t depth);
        std::shared_ptr<leaf::parsing::instance::class_> p_match_class_(size_t depth);
        bool m_attribute_282(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_item_with_default>& actual, leaf::parsing::instance::method_arglist_item_with_default_state& state, size_t depth);
        bool m_attribute_283(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_item_with_default>& actual, leaf::parsing::instance::method_arglist_item_with_default_state& state, size_t depth);
        bool while284_285(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_item_with_default>& actual, leaf::parsing::instance::method_arglist_item_with_default_state& state, size_t depth);
        bool m_typematch_ident_286(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_item_with_default>& actual, leaf::parsing::instance::method_arglist_item_with_default_state& state, size_t depth);
        bool m_equal_287(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_item_with_default>& actual, leaf::parsing::instance::method_arglist_item_with_default_state& state, size_t depth);
        bool m_equal_expvalue_288(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_item_with_default>& actual, leaf::parsing::instance::method_arglist_item_with_default_state& state, size_t depth);
        bool if289_290(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_item_with_default>& actual, leaf::parsing::instance::method_arglist_item_with_default_state& state, size_t depth);
        bool p_can_method_arglist_item_with_default(size_t depth);
        std::shared_ptr<leaf::parsing::instance::method_arglist_item_with_default> p_match_method_arglist_item_with_default(size_t depth);
        bool m_attribute_291(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_item>& actual, leaf::parsing::instance::method_arglist_item_state& state, size_t depth);
        bool m_attribute_292(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_item>& actual, leaf::parsing::instance::method_arglist_item_state& state, size_t depth);
        bool while293_294(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_item>& actual, leaf::parsing::instance::method_arglist_item_state& state, size_t depth);
        bool m_typematch_ident_295(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_item>& actual, leaf::parsing::instance::method_arglist_item_state& state, size_t depth);
        bool p_can_method_arglist_item(size_t depth);
        std::shared_ptr<leaf::parsing::instance::method_arglist_item> p_match_method_arglist_item(size_t depth);
        bool m_roundbrackedopen_296(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth);
        bool m_methodarglistitemwithdefault_297(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth);
        bool m_methodarglistitemwithdefault_298(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth);
        bool m_roundbrackedclose_299(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth);
        bool m_comma_methodarglistitemwithdefault_300(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth);
        bool alternatives301(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth);
        bool while302_303(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth);
        bool m_comma_304(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth);
        bool m_comma_305(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth);
        bool if306_307(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth);
        bool if308_309(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth);
        bool m_roundbrackedclose_310(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth);
        bool p_can_method_arglist(size_t depth);
        std::shared_ptr<leaf::parsing::instance::method_arglist> p_match_method_arglist(size_t depth);
        bool m_squarebrackedopen_311(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_indexer>& actual, leaf::parsing::instance::method_arglist_indexer_state& state, size_t depth);
        bool m_methodarglistitem_312(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_indexer>& actual, leaf::parsing::instance::method_arglist_indexer_state& state, size_t depth);
        bool m_squarebrackedclose_313(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_indexer>& actual, leaf::parsing::instance::method_arglist_indexer_state& state, size_t depth);
        bool m_comma_methodarglistitem_314(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_indexer>& actual, leaf::parsing::instance::method_arglist_indexer_state& state, size_t depth);
        bool alternatives315(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_indexer>& actual, leaf::parsing::instance::method_arglist_indexer_state& state, size_t depth);
        bool while316_317(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_indexer>& actual, leaf::parsing::instance::method_arglist_indexer_state& state, size_t depth);
        bool m_comma_318(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_indexer>& actual, leaf::parsing::instance::method_arglist_indexer_state& state, size_t depth);
        bool m_comma_319(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_indexer>& actual, leaf::parsing::instance::method_arglist_indexer_state& state, size_t depth);
        bool if320_321(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_indexer>& actual, leaf::parsing::instance::method_arglist_indexer_state& state, size_t depth);
        bool m_squarebrackedclose_322(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_indexer>& actual, leaf::parsing::instance::method_arglist_indexer_state& state, size_t depth);
        bool p_can_method_arglist_indexer(size_t depth);
        std::shared_ptr<leaf::parsing::instance::method_arglist_indexer> p_match_method_arglist_indexer(size_t depth);
        bool m_attribute_323(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth);
        bool m_attribute_324(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth);
        bool while325_326(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth);
        bool m_encapsulation_327(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth);
        bool m_sealed_328(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth);
        bool m_sealed_329(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth);
        bool if330_331(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth);
        bool m_virtual_332(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth);
        bool m_virtual_333(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth);
        bool if334_335(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth);
        bool m_unbound_336(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth);
        bool m_unbound_337(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth);
        bool if338_339(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth);
        bool m_inline_340(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth);
        bool m_inline_341(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth);
        bool if342_343(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth);
        bool m_typematch_344(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth);
        bool m_ident_345(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth);
        bool m_templatedefinition_346(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth);
        bool m_templatedefinition_347(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth);
        bool if348_349(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth);
        bool m_methodarglist_scope_350(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth);
        bool p_can_method(size_t depth);
        std::shared_ptr<leaf::parsing::instance::method> p_match_method(size_t depth);
        bool m_attribute_351(bool is_can, std::shared_ptr<leaf::parsing::instance::constructor>& actual, leaf::parsing::instance::constructor_state& state, size_t depth);
        bool m_attribute_352(bool is_can, std::shared_ptr<leaf::parsing::instance::constructor>& actual, leaf::parsing::instance::constructor_state& state, size_t depth);
        bool while353_354(bool is_can, std::shared_ptr<leaf::parsing::instance::constructor>& actual, leaf::parsing::instance::constructor_state& state, size_t depth);
        bool m_encapsulation_355(bool is_can, std::shared_ptr<leaf::parsing::instance::constructor>& actual, leaf::parsing::instance::constructor_state& state, size_t depth);
        bool m_templatedefinition_356(bool is_can, std::shared_ptr<leaf::parsing::instance::constructor>& actual, leaf::parsing::instance::constructor_state& state, size_t depth);
        bool m_templatedefinition_357(bool is_can, std::shared_ptr<leaf::parsing::instance::constructor>& actual, leaf::parsing::instance::constructor_state& state, size_t depth);
        bool if358_359(bool is_can, std::shared_ptr<leaf::parsing::instance::constructor>& actual, leaf::parsing::instance::constructor_state& state, size_t depth);
        bool m_methodarglist_scope_360(bool is_can, std::shared_ptr<leaf::parsing::instance::constructor>& actual, leaf::parsing::instance::constructor_state& state, size_t depth);
        bool p_can_constructor(size_t depth);
        std::shared_ptr<leaf::parsing::instance::constructor> p_match_constructor(size_t depth);
        bool m_attribute_361(bool is_can, std::shared_ptr<leaf::parsing::instance::destructor>& actual, leaf::parsing::instance::destructor_state& state, size_t depth);
        bool m_attribute_362(bool is_can, std::shared_ptr<leaf::parsing::instance::destructor>& actual, leaf::parsing::instance::destructor_state& state, size_t depth);
        bool while363_364(bool is_can, std::shared_ptr<leaf::parsing::instance::destructor>& actual, leaf::parsing::instance::destructor_state& state, size_t depth);
        bool m_encapsulation_tilde_365(bool is_can, std::shared_ptr<leaf::parsing::instance::destructor>& actual, leaf::parsing::instance::destructor_state& state, size_t depth);
        bool m_templatedefinition_366(bool is_can, std::shared_ptr<leaf::parsing::instance::destructor>& actual, leaf::parsing::instance::destructor_state& state, size_t depth);
        bool m_templatedefinition_367(bool is_can, std::shared_ptr<leaf::parsing::instance::destructor>& actual, leaf::parsing::instance::destructor_state& state, size_t depth);
        bool if368_369(bool is_can, std::shared_ptr<leaf::parsing::instance::destructor>& actual, leaf::parsing::instance::destructor_state& state, size_t depth);
        bool m_methodarglist_scope_370(bool is_can, std::shared_ptr<leaf::parsing::instance::destructor>& actual, leaf::parsing::instance::destructor_state& state, size_t depth);
        bool p_can_destructor(size_t depth);
        std::shared_ptr<leaf::parsing::instance::destructor> p_match_destructor(size_t depth);
        bool m_attribute_371(bool is_can, std::shared_ptr<leaf::parsing::instance::copystructor>& actual, leaf::parsing::instance::copystructor_state& state, size_t depth);
        bool m_attribute_372(bool is_can, std::shared_ptr<leaf::parsing::instance::copystructor>& actual, leaf::parsing::instance::copystructor_state& state, size_t depth);
        bool while373_374(bool is_can, std::shared_ptr<leaf::parsing::instance::copystructor>& actual, leaf::parsing::instance::copystructor_state& state, size_t depth);
        bool m_encapsulation_plus_375(bool is_can, std::shared_ptr<leaf::parsing::instance::copystructor>& actual, leaf::parsing::instance::copystructor_state& state, size_t depth);
        bool m_templatedefinition_376(bool is_can, std::shared_ptr<leaf::parsing::instance::copystructor>& actual, leaf::parsing::instance::copystructor_state& state, size_t depth);
        bool m_templatedefinition_377(bool is_can, std::shared_ptr<leaf::parsing::instance::copystructor>& actual, leaf::parsing::instance::copystructor_state& state, size_t depth);
        bool if378_379(bool is_can, std::shared_ptr<leaf::parsing::instance::copystructor>& actual, leaf::parsing::instance::copystructor_state& state, size_t depth);
        bool m_methodarglist_380(bool is_can, std::shared_ptr<leaf::parsing::instance::copystructor>& actual, leaf::parsing::instance::copystructor_state& state, size_t depth);
        bool m_scope_381(bool is_can, std::shared_ptr<leaf::parsing::instance::copystructor>& actual, leaf::parsing::instance::copystructor_state& state, size_t depth);
        bool m_equal_delete_382(bool is_can, std::shared_ptr<leaf::parsing::instance::copystructor>& actual, leaf::parsing::instance::copystructor_state& state, size_t depth);
        bool alternatives383(bool is_can, std::shared_ptr<leaf::parsing::instance::copystructor>& actual, leaf::parsing::instance::copystructor_state& state, size_t depth);
        bool p_can_copystructor(size_t depth);
        std::shared_ptr<leaf::parsing::instance::copystructor> p_match_copystructor(size_t depth);
        bool m_attribute_384(bool is_can, std::shared_ptr<leaf::parsing::instance::conversion>& actual, leaf::parsing::instance::conversion_state& state, size_t depth);
        bool m_attribute_385(bool is_can, std::shared_ptr<leaf::parsing::instance::conversion>& actual, leaf::parsing::instance::conversion_state& state, size_t depth);
        bool while386_387(bool is_can, std::shared_ptr<leaf::parsing::instance::conversion>& actual, leaf::parsing::instance::conversion_state& state, size_t depth);
        bool m_encapsulation_unbound_conversion_typematch_388(bool is_can, std::shared_ptr<leaf::parsing::instance::conversion>& actual, leaf::parsing::instance::conversion_state& state, size_t depth);
        bool m_roundbrackedopen_typematch_ident_roundbrackedclose_389(bool is_can, std::shared_ptr<leaf::parsing::instance::conversion>& actual, leaf::parsing::instance::conversion_state& state, size_t depth);
        bool m_scope_390(bool is_can, std::shared_ptr<leaf::parsing::instance::conversion>& actual, leaf::parsing::instance::conversion_state& state, size_t depth);
        bool p_can_conversion(size_t depth);
        std::shared_ptr<leaf::parsing::instance::conversion> p_match_conversion(size_t depth);
        bool m_attribute_391(bool is_can, std::shared_ptr<leaf::parsing::instance::indexer>& actual, leaf::parsing::instance::indexer_state& state, size_t depth);
        bool m_attribute_392(bool is_can, std::shared_ptr<leaf::parsing::instance::indexer>& actual, leaf::parsing::instance::indexer_state& state, size_t depth);
        bool while393_394(bool is_can, std::shared_ptr<leaf::parsing::instance::indexer>& actual, leaf::parsing::instance::indexer_state& state, size_t depth);
        bool m_encapsulation_typematch_395(bool is_can, std::shared_ptr<leaf::parsing::instance::indexer>& actual, leaf::parsing::instance::indexer_state& state, size_t depth);
        bool m_templatedefinition_396(bool is_can, std::shared_ptr<leaf::parsing::instance::indexer>& actual, leaf::parsing::instance::indexer_state& state, size_t depth);
        bool m_templatedefinition_397(bool is_can, std::shared_ptr<leaf::parsing::instance::indexer>& actual, leaf::parsing::instance::indexer_state& state, size_t depth);
        bool if398_399(bool is_can, std::shared_ptr<leaf::parsing::instance::indexer>& actual, leaf::parsing::instance::indexer_state& state, size_t depth);
        bool m_methodarglistindexer_scopegetset_400(bool is_can, std::shared_ptr<leaf::parsing::instance::indexer>& actual, leaf::parsing::instance::indexer_state& state, size_t depth);
        bool p_can_indexer(size_t depth);
        std::shared_ptr<leaf::parsing::instance::indexer> p_match_indexer(size_t depth);
        bool m_attribute_401(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_attribute_402(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool while403_404(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_encapsulation_unbound_405(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_inline_406(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool if407_408(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_typematch_operator_409(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_templatedefinition_410(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_templatedefinition_411(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool if412_413(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_roundbrackedopen_methodarglistitem_roundbrackedclose_414(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_plus_415(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_minus_416(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_star_417(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_slash_418(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_lessthenlessthenlessthen_419(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_lessthenlessthen_420(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_lessthenequal_421(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_lessthen_422(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_greaterthengreaterthengreaterthen_423(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_greaterthengreaterthen_424(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_greaterthenequal_425(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_greaterthen_426(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_verticalbarverticalbar_427(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_verticalbar_428(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_ampersandampersand_429(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_ampersand_430(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_equalequalequal_431(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_equalequal_432(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_exclamationequal_433(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_circumflex_434(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool alternatives435(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_roundbrackedopen_methodarglistitem_roundbrackedclose_436(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool m_scope_437(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth);
        bool p_can_operator_binary_overload(size_t depth);
        std::shared_ptr<leaf::parsing::instance::operator_binary_overload> p_match_operator_binary_overload(size_t depth);
        bool m_attribute_438(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth);
        bool m_attribute_439(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth);
        bool while440_441(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth);
        bool m_encapsulation_unbound_442(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth);
        bool m_inline_443(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth);
        bool if444_445(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth);
        bool m_typematch_operator_446(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth);
        bool m_templatedefinition_447(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth);
        bool m_templatedefinition_448(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth);
        bool if449_450(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth);
        bool m_plus_451(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth);
        bool m_minus_452(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth);
        bool m_exclamation_453(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth);
        bool m_tilde_454(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth);
        bool alternatives455(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth);
        bool m_roundbrackedopen_methodarglistitem_roundbrackedclose_456(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth);
        bool m_scope_457(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth);
        bool p_can_operator_unary_overload(size_t depth);
        std::shared_ptr<leaf::parsing::instance::operator_unary_overload> p_match_operator_unary_overload(size_t depth);
        bool m_attribute_458(bool is_can, std::shared_ptr<leaf::parsing::instance::property>& actual, leaf::parsing::instance::property_state& state, size_t depth);
        bool m_attribute_459(bool is_can, std::shared_ptr<leaf::parsing::instance::property>& actual, leaf::parsing::instance::property_state& state, size_t depth);
        bool while460_461(bool is_can, std::shared_ptr<leaf::parsing::instance::property>& actual, leaf::parsing::instance::property_state& state, size_t depth);
        bool m_encapsulation_462(bool is_can, std::shared_ptr<leaf::parsing::instance::property>& actual, leaf::parsing::instance::property_state& state, size_t depth);
        bool m_sealed_463(bool is_can, std::shared_ptr<leaf::parsing::instance::property>& actual, leaf::parsing::instance::property_state& state, size_t depth);
        bool m_sealed_464(bool is_can, std::shared_ptr<leaf::parsing::instance::property>& actual, leaf::parsing::instance::property_state& state, size_t depth);
        bool if465_466(bool is_can, std::shared_ptr<leaf::parsing::instance::property>& actual, leaf::parsing::instance::property_state& state, size_t depth);
        bool m_virtual_467(bool is_can, std::shared_ptr<leaf::parsing::instance::property>& actual, leaf::parsing::instance::property_state& state, size_t depth);
        bool m_virtual_468(bool is_can, std::shared_ptr<leaf::parsing::instance::property>& actual, leaf::parsing::instance::property_state& state, size_t depth);
        bool if469_470(bool is_can, std::shared_ptr<leaf::parsing::instance::property>& actual, leaf::parsing::instance::property_state& state, size_t depth);
        bool m_unbound_471(bool is_can, std::shared_ptr<leaf::parsing::instance::property>& actual, leaf::parsing::instance::property_state& state, size_t depth);
        bool m_unbound_472(bool is_can, std::shared_ptr<leaf::parsing::instance::property>& actual, leaf::parsing::instance::property_state& state, size_t depth);
        bool if473_474(bool is_can, std::shared_ptr<leaf::parsing::instance::property>& actual, leaf::parsing::instance::property_state& state, size_t depth);
        bool m_typematch_ident_scopegetset_475(bool is_can, std::shared_ptr<leaf::parsing::instance::property>& actual, leaf::parsing::instance::property_state& state, size_t depth);
        bool p_can_property(size_t depth);
        std::shared_ptr<leaf::parsing::instance::property> p_match_property(size_t depth);
        bool m_attribute_476(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth);
        bool m_attribute_477(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth);
        bool while478_479(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth);
        bool m_encapsulation_480(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth);
        bool m_sealed_481(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth);
        bool m_sealed_482(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth);
        bool if483_484(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth);
        bool m_virtual_485(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth);
        bool m_virtual_486(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth);
        bool if487_488(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth);
        bool m_unbound_489(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth);
        bool m_unbound_490(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth);
        bool if491_492(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth);
        bool m_typematch_ident_semicolon_493(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth);
        bool p_can_field(size_t depth);
        std::shared_ptr<leaf::parsing::instance::field> p_match_field(size_t depth);
        bool m_using_494(bool is_can, std::shared_ptr<leaf::parsing::instance::using_>& actual, leaf::parsing::instance::using__state& state, size_t depth);
        bool m_namespace_identnavigation_495(bool is_can, std::shared_ptr<leaf::parsing::instance::using_>& actual, leaf::parsing::instance::using__state& state, size_t depth);
        bool m_class_identnavigation_496(bool is_can, std::shared_ptr<leaf::parsing::instance::using_>& actual, leaf::parsing::instance::using__state& state, size_t depth);
        bool alternatives497(bool is_can, std::shared_ptr<leaf::parsing::instance::using_>& actual, leaf::parsing::instance::using__state& state, size_t depth);
        bool m_equal_498(bool is_can, std::shared_ptr<leaf::parsing::instance::using_>& actual, leaf::parsing::instance::using__state& state, size_t depth);
        bool m_equal_ident_499(bool is_can, std::shared_ptr<leaf::parsing::instance::using_>& actual, leaf::parsing::instance::using__state& state, size_t depth);
        bool if500_501(bool is_can, std::shared_ptr<leaf::parsing::instance::using_>& actual, leaf::parsing::instance::using__state& state, size_t depth);
        bool p_can_using_(size_t depth);
        std::shared_ptr<leaf::parsing::instance::using_> p_match_using_(size_t depth);
        bool m_ident_callbody_502(bool is_can, std::shared_ptr<leaf::parsing::instance::call>& actual, leaf::parsing::instance::call_state& state, size_t depth);
        bool p_can_call(size_t depth);
        std::shared_ptr<leaf::parsing::instance::call> p_match_call(size_t depth);
        bool m_roundbrackedopen_503(bool is_can, std::shared_ptr<leaf::parsing::instance::call_body>& actual, leaf::parsing::instance::call_body_state& state, size_t depth);
        bool m_expression_504(bool is_can, std::shared_ptr<leaf::parsing::instance::call_body>& actual, leaf::parsing::instance::call_body_state& state, size_t depth);
        bool m_expression_505(bool is_can, std::shared_ptr<leaf::parsing::instance::call_body>& actual, leaf::parsing::instance::call_body_state& state, size_t depth);
        bool m_roundbrackedclose_506(bool is_can, std::shared_ptr<leaf::parsing::instance::call_body>& actual, leaf::parsing::instance::call_body_state& state, size_t depth);
        bool m_comma_expression_507(bool is_can, std::shared_ptr<leaf::parsing::instance::call_body>& actual, leaf::parsing::instance::call_body_state& state, size_t depth);
        bool m_comma_508(bool is_can, std::shared_ptr<leaf::parsing::instance::call_body>& actual, leaf::parsing::instance::call_body_state& state, size_t depth);
        bool alternatives509(bool is_can, std::shared_ptr<leaf::parsing::instance::call_body>& actual, leaf::parsing::instance::call_body_state& state, size_t depth);
        bool while510_511(bool is_can, std::shared_ptr<leaf::parsing::instance::call_body>& actual, leaf::parsing::instance::call_body_state& state, size_t depth);
        bool if512_513(bool is_can, std::shared_ptr<leaf::parsing::instance::call_body>& actual, leaf::parsing::instance::call_body_state& state, size_t depth);
        bool m_roundbrackedclose_514(bool is_can, std::shared_ptr<leaf::parsing::instance::call_body>& actual, leaf::parsing::instance::call_body_state& state, size_t depth);
        bool p_can_call_body(size_t depth);
        std::shared_ptr<leaf::parsing::instance::call_body> p_match_call_body(size_t depth);
        bool m_free_expression_515(bool is_can, std::shared_ptr<leaf::parsing::instance::free>& actual, leaf::parsing::instance::free_state& state, size_t depth);
        bool p_can_free(size_t depth);
        std::shared_ptr<leaf::parsing::instance::free> p_match_free(size_t depth);
        bool m_alloc_stack_typenavigation_squarebrackedopen_expression_squarebrackedclose_516(bool is_can, std::shared_ptr<leaf::parsing::instance::alloc>& actual, leaf::parsing::instance::alloc_state& state, size_t depth);
        bool m_alloc_stack_typenavigation_callbody_517(bool is_can, std::shared_ptr<leaf::parsing::instance::alloc>& actual, leaf::parsing::instance::alloc_state& state, size_t depth);
        bool m_alloc_heap_typenavigation_squarebrackedopen_expression_squarebrackedclose_518(bool is_can, std::shared_ptr<leaf::parsing::instance::alloc>& actual, leaf::parsing::instance::alloc_state& state, size_t depth);
        bool m_alloc_heap_typenavigation_callbody_519(bool is_can, std::shared_ptr<leaf::parsing::instance::alloc>& actual, leaf::parsing::instance::alloc_state& state, size_t depth);
        bool alternatives520(bool is_can, std::shared_ptr<leaf::parsing::instance::alloc>& actual, leaf::parsing::instance::alloc_state& state, size_t depth);
        bool p_can_alloc(size_t depth);
        std::shared_ptr<leaf::parsing::instance::alloc> p_match_alloc(size_t depth);
        bool m_ident_521(bool is_can, std::shared_ptr<leaf::parsing::instance::template_usage_item>& actual, leaf::parsing::instance::template_usage_item_state& state, size_t depth);
        bool p_can_template_usage_item(size_t depth);
        std::shared_ptr<leaf::parsing::instance::template_usage_item> p_match_template_usage_item(size_t depth);
        bool m_lessthen_522(bool is_can, std::shared_ptr<leaf::parsing::instance::template_usage>& actual, leaf::parsing::instance::template_usage_state& state, size_t depth);
        bool m_templateusageitem_523(bool is_can, std::shared_ptr<leaf::parsing::instance::template_usage>& actual, leaf::parsing::instance::template_usage_state& state, size_t depth);
        bool m_comma_524(bool is_can, std::shared_ptr<leaf::parsing::instance::template_usage>& actual, leaf::parsing::instance::template_usage_state& state, size_t depth);
        bool m_comma_templateusageitem_525(bool is_can, std::shared_ptr<leaf::parsing::instance::template_usage>& actual, leaf::parsing::instance::template_usage_state& state, size_t depth);
        bool alternatives526(bool is_can, std::shared_ptr<leaf::parsing::instance::template_usage>& actual, leaf::parsing::instance::template_usage_state& state, size_t depth);
        bool while527_528(bool is_can, std::shared_ptr<leaf::parsing::instance::template_usage>& actual, leaf::parsing::instance::template_usage_state& state, size_t depth);
        bool m_greaterthen_529(bool is_can, std::shared_ptr<leaf::parsing::instance::template_usage>& actual, leaf::parsing::instance::template_usage_state& state, size_t depth);
        bool p_can_template_usage(size_t depth);
        std::shared_ptr<leaf::parsing::instance::template_usage> p_match_template_usage(size_t depth);
        bool m_ident_530(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition_item>& actual, leaf::parsing::instance::template_definition_item_state& state, size_t depth);
        bool m_equal_531(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition_item>& actual, leaf::parsing::instance::template_definition_item_state& state, size_t depth);
        bool m_equal_expvalue_532(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition_item>& actual, leaf::parsing::instance::template_definition_item_state& state, size_t depth);
        bool if533_534(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition_item>& actual, leaf::parsing::instance::template_definition_item_state& state, size_t depth);
        bool p_can_template_definition_item(size_t depth);
        std::shared_ptr<leaf::parsing::instance::template_definition_item> p_match_template_definition_item(size_t depth);
        bool m_lessthen_535(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition>& actual, leaf::parsing::instance::template_definition_state& state, size_t depth);
        bool m_templatedefinitionitem_536(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition>& actual, leaf::parsing::instance::template_definition_state& state, size_t depth);
        bool m_comma_537(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition>& actual, leaf::parsing::instance::template_definition_state& state, size_t depth);
        bool m_comma_templatedefinitionitem_538(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition>& actual, leaf::parsing::instance::template_definition_state& state, size_t depth);
        bool alternatives539(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition>& actual, leaf::parsing::instance::template_definition_state& state, size_t depth);
        bool while540_541(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition>& actual, leaf::parsing::instance::template_definition_state& state, size_t depth);
        bool m_greaterthen_542(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition>& actual, leaf::parsing::instance::template_definition_state& state, size_t depth);
        bool p_can_template_definition(size_t depth);
        std::shared_ptr<leaf::parsing::instance::template_definition> p_match_template_definition(size_t depth);
        bool m_typeof_roundbrackedopen_typematch_roundbrackedclose_543(bool is_can, std::shared_ptr<leaf::parsing::instance::typeof_>& actual, leaf::parsing::instance::typeof__state& state, size_t depth);
        bool p_can_typeof_(size_t depth);
        std::shared_ptr<leaf::parsing::instance::typeof_> p_match_typeof_(size_t depth);
        bool m_nameof_roundbrackedopen_expor_roundbrackedclose_544(bool is_can, std::shared_ptr<leaf::parsing::instance::nameof>& actual, leaf::parsing::instance::nameof_state& state, size_t depth);
        bool p_can_nameof(size_t depth);
        std::shared_ptr<leaf::parsing::instance::nameof> p_match_nameof(size_t depth);
        bool m_sizeof_roundbrackedopen_typematch_roundbrackedclose_545(bool is_can, std::shared_ptr<leaf::parsing::instance::sizeof_>& actual, leaf::parsing::instance::sizeof__state& state, size_t depth);
        bool p_can_sizeof_(size_t depth);
        std::shared_ptr<leaf::parsing::instance::sizeof_> p_match_sizeof_(size_t depth);
        bool m_typenavigation_squarebrackedopen_squarebrackedclose_star_546(bool is_can, std::shared_ptr<leaf::parsing::instance::type_match>& actual, leaf::parsing::instance::type_match_state& state, size_t depth);
        bool m_typenavigation_star_547(bool is_can, std::shared_ptr<leaf::parsing::instance::type_match>& actual, leaf::parsing::instance::type_match_state& state, size_t depth);
        bool m_typenavigation_548(bool is_can, std::shared_ptr<leaf::parsing::instance::type_match>& actual, leaf::parsing::instance::type_match_state& state, size_t depth);
        bool alternatives549(bool is_can, std::shared_ptr<leaf::parsing::instance::type_match>& actual, leaf::parsing::instance::type_match_state& state, size_t depth);
        bool p_can_type_match(size_t depth);
        std::shared_ptr<leaf::parsing::instance::type_match> p_match_type_match(size_t depth);
        bool m_stringformatablestart_550(bool is_can, std::shared_ptr<leaf::parsing::instance::string_formatable>& actual, leaf::parsing::instance::string_formatable_state& state, size_t depth);
        bool m_expression_551(bool is_can, std::shared_ptr<leaf::parsing::instance::string_formatable>& actual, leaf::parsing::instance::string_formatable_state& state, size_t depth);
        bool m_stringformatableend_552(bool is_can, std::shared_ptr<leaf::parsing::instance::string_formatable>& actual, leaf::parsing::instance::string_formatable_state& state, size_t depth);
        bool m_stringformatablecontinuation_553(bool is_can, std::shared_ptr<leaf::parsing::instance::string_formatable>& actual, leaf::parsing::instance::string_formatable_state& state, size_t depth);
        bool m_expression_554(bool is_can, std::shared_ptr<leaf::parsing::instance::string_formatable>& actual, leaf::parsing::instance::string_formatable_state& state, size_t depth);
        bool while555_556(bool is_can, std::shared_ptr<leaf::parsing::instance::string_formatable>& actual, leaf::parsing::instance::string_formatable_state& state, size_t depth);
        bool m_stringformatableend_557(bool is_can, std::shared_ptr<leaf::parsing::instance::string_formatable>& actual, leaf::parsing::instance::string_formatable_state& state, size_t depth);
        bool p_can_string_formatable(size_t depth);
        std::shared_ptr<leaf::parsing::instance::string_formatable> p_match_string_formatable(size_t depth);
        bool m_ident_stringformatable_ident_558(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth);
        bool m_stringformatable_ident_559(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth);
        bool m_ident_stringformatable_560(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth);
        bool m_stringformatable_561(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth);
        bool m_ident_stringformatablefake_ident_562(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth);
        bool m_stringformatablefake_ident_563(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth);
        bool m_ident_stringformatablefake_564(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth);
        bool m_stringformatablefake_565(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth);
        bool m_ident_string_ident_566(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth);
        bool m_string_ident_567(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth);
        bool m_ident_string_568(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth);
        bool m_string_569(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth);
        bool alternatives570(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth);
        bool p_can_string_literal(size_t depth);
        std::shared_ptr<leaf::parsing::instance::string_literal> p_match_string_literal(size_t depth);
        bool m_ident_scalar_ident_571(bool is_can, std::shared_ptr<leaf::parsing::instance::scalar_literal>& actual, leaf::parsing::instance::scalar_literal_state& state, size_t depth);
        bool m_scalar_ident_572(bool is_can, std::shared_ptr<leaf::parsing::instance::scalar_literal>& actual, leaf::parsing::instance::scalar_literal_state& state, size_t depth);
        bool m_ident_scalar_573(bool is_can, std::shared_ptr<leaf::parsing::instance::scalar_literal>& actual, leaf::parsing::instance::scalar_literal_state& state, size_t depth);
        bool m_scalar_574(bool is_can, std::shared_ptr<leaf::parsing::instance::scalar_literal>& actual, leaf::parsing::instance::scalar_literal_state& state, size_t depth);
        bool alternatives575(bool is_can, std::shared_ptr<leaf::parsing::instance::scalar_literal>& actual, leaf::parsing::instance::scalar_literal_state& state, size_t depth);
        bool p_can_scalar_literal(size_t depth);
        std::shared_ptr<leaf::parsing::instance::scalar_literal> p_match_scalar_literal(size_t depth);
        bool m_ident_integerhex_ident_576(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_hex_literal>& actual, leaf::parsing::instance::integer_hex_literal_state& state, size_t depth);
        bool m_integerhex_ident_577(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_hex_literal>& actual, leaf::parsing::instance::integer_hex_literal_state& state, size_t depth);
        bool m_ident_integerhex_578(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_hex_literal>& actual, leaf::parsing::instance::integer_hex_literal_state& state, size_t depth);
        bool m_integerhex_579(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_hex_literal>& actual, leaf::parsing::instance::integer_hex_literal_state& state, size_t depth);
        bool alternatives580(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_hex_literal>& actual, leaf::parsing::instance::integer_hex_literal_state& state, size_t depth);
        bool p_can_integer_hex_literal(size_t depth);
        std::shared_ptr<leaf::parsing::instance::integer_hex_literal> p_match_integer_hex_literal(size_t depth);
        bool m_ident_integerbinary_ident_581(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_binary_literal>& actual, leaf::parsing::instance::integer_binary_literal_state& state, size_t depth);
        bool m_integerbinary_ident_582(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_binary_literal>& actual, leaf::parsing::instance::integer_binary_literal_state& state, size_t depth);
        bool m_ident_integerbinary_583(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_binary_literal>& actual, leaf::parsing::instance::integer_binary_literal_state& state, size_t depth);
        bool m_integerbinary_584(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_binary_literal>& actual, leaf::parsing::instance::integer_binary_literal_state& state, size_t depth);
        bool alternatives585(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_binary_literal>& actual, leaf::parsing::instance::integer_binary_literal_state& state, size_t depth);
        bool p_can_integer_binary_literal(size_t depth);
        std::shared_ptr<leaf::parsing::instance::integer_binary_literal> p_match_integer_binary_literal(size_t depth);
        bool m_ident_integer_ident_586(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_literal>& actual, leaf::parsing::instance::integer_literal_state& state, size_t depth);
        bool m_integer_ident_587(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_literal>& actual, leaf::parsing::instance::integer_literal_state& state, size_t depth);
        bool m_ident_integer_588(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_literal>& actual, leaf::parsing::instance::integer_literal_state& state, size_t depth);
        bool m_integer_589(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_literal>& actual, leaf::parsing::instance::integer_literal_state& state, size_t depth);
        bool alternatives590(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_literal>& actual, leaf::parsing::instance::integer_literal_state& state, size_t depth);
        bool p_can_integer_literal(size_t depth);
        std::shared_ptr<leaf::parsing::instance::integer_literal> p_match_integer_literal(size_t depth);
        bool m_ident_char_ident_591(bool is_can, std::shared_ptr<leaf::parsing::instance::char_literal>& actual, leaf::parsing::instance::char_literal_state& state, size_t depth);
        bool m_char_ident_592(bool is_can, std::shared_ptr<leaf::parsing::instance::char_literal>& actual, leaf::parsing::instance::char_literal_state& state, size_t depth);
        bool m_ident_char_593(bool is_can, std::shared_ptr<leaf::parsing::instance::char_literal>& actual, leaf::parsing::instance::char_literal_state& state, size_t depth);
        bool m_char_594(bool is_can, std::shared_ptr<leaf::parsing::instance::char_literal>& actual, leaf::parsing::instance::char_literal_state& state, size_t depth);
        bool alternatives595(bool is_can, std::shared_ptr<leaf::parsing::instance::char_literal>& actual, leaf::parsing::instance::char_literal_state& state, size_t depth);
        bool p_can_char_literal(size_t depth);
        std::shared_ptr<leaf::parsing::instance::char_literal> p_match_char_literal(size_t depth);
        bool m_typematch_ident_596(bool is_can, std::shared_ptr<leaf::parsing::instance::declaration>& actual, leaf::parsing::instance::declaration_state& state, size_t depth);
        bool p_can_declaration(size_t depth);
        std::shared_ptr<leaf::parsing::instance::declaration> p_match_declaration(size_t depth);
        bool m_return_expression_semicolon_597(bool is_can, std::shared_ptr<leaf::parsing::instance::statement>& actual, leaf::parsing::instance::statement_state& state, size_t depth);
        bool m_declaration_equal_expression_semicolon_598(bool is_can, std::shared_ptr<leaf::parsing::instance::statement>& actual, leaf::parsing::instance::statement_state& state, size_t depth);
        bool m_declaration_semicolon_599(bool is_can, std::shared_ptr<leaf::parsing::instance::statement>& actual, leaf::parsing::instance::statement_state& state, size_t depth);
        bool m_expression_semicolon_600(bool is_can, std::shared_ptr<leaf::parsing::instance::statement>& actual, leaf::parsing::instance::statement_state& state, size_t depth);
        bool m_semicolon_601(bool is_can, std::shared_ptr<leaf::parsing::instance::statement>& actual, leaf::parsing::instance::statement_state& state, size_t depth);
        bool m_pragma_602(bool is_can, std::shared_ptr<leaf::parsing::instance::statement>& actual, leaf::parsing::instance::statement_state& state, size_t depth);
        bool alternatives603(bool is_can, std::shared_ptr<leaf::parsing::instance::statement>& actual, leaf::parsing::instance::statement_state& state, size_t depth);
        bool p_can_statement(size_t depth);
        std::shared_ptr<leaf::parsing::instance::statement> p_match_statement(size_t depth);
        bool m_auto626_604(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma>& actual, leaf::parsing::instance::pragma_state& state, size_t depth);
        bool m_exclamationgreaterthen_605(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma>& actual, leaf::parsing::instance::pragma_state& state, size_t depth);
        bool m_pragmadisable_606(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma>& actual, leaf::parsing::instance::pragma_state& state, size_t depth);
        bool m_pragmaenable_607(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma>& actual, leaf::parsing::instance::pragma_state& state, size_t depth);
        bool m_pragmasize_608(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma>& actual, leaf::parsing::instance::pragma_state& state, size_t depth);
        bool m_pragmaalign_609(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma>& actual, leaf::parsing::instance::pragma_state& state, size_t depth);
        bool alternatives610(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma>& actual, leaf::parsing::instance::pragma_state& state, size_t depth);
        bool while611_612(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma>& actual, leaf::parsing::instance::pragma_state& state, size_t depth);
        bool m_exclamationgreaterthen_613(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma>& actual, leaf::parsing::instance::pragma_state& state, size_t depth);
        bool p_can_pragma(size_t depth);
        std::shared_ptr<leaf::parsing::instance::pragma> p_match_pragma(size_t depth);
        bool m_align_614(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_align>& actual, leaf::parsing::instance::pragma_align_state& state, size_t depth);
        bool m_integerbinary_615(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_align>& actual, leaf::parsing::instance::pragma_align_state& state, size_t depth);
        bool m_integerhex_616(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_align>& actual, leaf::parsing::instance::pragma_align_state& state, size_t depth);
        bool m_integer_617(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_align>& actual, leaf::parsing::instance::pragma_align_state& state, size_t depth);
        bool alternatives618(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_align>& actual, leaf::parsing::instance::pragma_align_state& state, size_t depth);
        bool p_can_pragma_align(size_t depth);
        std::shared_ptr<leaf::parsing::instance::pragma_align> p_match_pragma_align(size_t depth);
        bool m_size_619(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_size>& actual, leaf::parsing::instance::pragma_size_state& state, size_t depth);
        bool m_integerbinary_620(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_size>& actual, leaf::parsing::instance::pragma_size_state& state, size_t depth);
        bool m_integerhex_621(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_size>& actual, leaf::parsing::instance::pragma_size_state& state, size_t depth);
        bool m_integer_622(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_size>& actual, leaf::parsing::instance::pragma_size_state& state, size_t depth);
        bool alternatives623(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_size>& actual, leaf::parsing::instance::pragma_size_state& state, size_t depth);
        bool p_can_pragma_size(size_t depth);
        std::shared_ptr<leaf::parsing::instance::pragma_size> p_match_pragma_size(size_t depth);
        bool m_disable_624(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_disable>& actual, leaf::parsing::instance::pragma_disable_state& state, size_t depth);
        bool m_ident_625(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_disable>& actual, leaf::parsing::instance::pragma_disable_state& state, size_t depth);
        bool p_can_pragma_disable(size_t depth);
        std::shared_ptr<leaf::parsing::instance::pragma_disable> p_match_pragma_disable(size_t depth);
        bool m_enable_626(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_enable>& actual, leaf::parsing::instance::pragma_enable_state& state, size_t depth);
        bool m_ident_627(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_enable>& actual, leaf::parsing::instance::pragma_enable_state& state, size_t depth);
        bool p_can_pragma_enable(size_t depth);
        std::shared_ptr<leaf::parsing::instance::pragma_enable> p_match_pragma_enable(size_t depth);
        bool m_using_628(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth);
        bool m_using_629(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth);
        bool m_using_630(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth);
        bool while631_632(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth);
        bool if633_634(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth);
        bool m_namespace_635(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth);
        bool m_conversion_636(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth);
        bool m_class_637(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth);
        bool m_method_638(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth);
        bool m_property_639(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth);
        bool m_field_640(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth);
        bool m_pragma_641(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth);
        bool alternatives642(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth);
        bool while643_644(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth);
        bool p_can_main(size_t depth);
        std::shared_ptr<leaf::parsing::instance::main> p_match_main(size_t depth);
        bool m_expchain_dot_call_645(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_chain>& actual, leaf::parsing::instance::exp_chain_state& state, size_t depth);
        bool m_expchain_dot_ident_646(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_chain>& actual, leaf::parsing::instance::exp_chain_state& state, size_t depth);
        bool m_expchain_squarebrackedopen_expression_squarebrackedclose_647(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_chain>& actual, leaf::parsing::instance::exp_chain_state& state, size_t depth);
        bool m_expchain_templateusage_648(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_chain>& actual, leaf::parsing::instance::exp_chain_state& state, size_t depth);
        bool m_expchainstart_649(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_chain>& actual, leaf::parsing::instance::exp_chain_state& state, size_t depth);
        bool lr_can_exp_chain(size_t depth);
        std::shared_ptr<leaf::parsing::instance::exp_chain> lr_match_exp_chain(size_t depth);
        bool m_expbinary4_lessthenlessthen_expunary_650(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_binary_4>& actual, leaf::parsing::instance::exp_binary_4_state& state, size_t depth);
        bool m_expbinary4_greaterthengreaterthen_expunary_651(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_binary_4>& actual, leaf::parsing::instance::exp_binary_4_state& state, size_t depth);
        bool m_expbinary4_lessthenlessthenlessthen_expunary_652(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_binary_4>& actual, leaf::parsing::instance::exp_binary_4_state& state, size_t depth);
        bool m_expbinary4_greaterthengreaterthengreaterthen_expunary_653(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_binary_4>& actual, leaf::parsing::instance::exp_binary_4_state& state, size_t depth);
        bool m_expunary_654(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_binary_4>& actual, leaf::parsing::instance::exp_binary_4_state& state, size_t depth);
        bool lr_can_exp_binary_4(size_t depth);
        std::shared_ptr<leaf::parsing::instance::exp_binary_4> lr_match_exp_binary_4(size_t depth);
        bool m_expbinary3_ampersand_expbinary4_655(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_binary_3>& actual, leaf::parsing::instance::exp_binary_3_state& state, size_t depth);
        bool m_expbinary4_656(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_binary_3>& actual, leaf::parsing::instance::exp_binary_3_state& state, size_t depth);
        bool lr_can_exp_binary_3(size_t depth);
        std::shared_ptr<leaf::parsing::instance::exp_binary_3> lr_match_exp_binary_3(size_t depth);
        bool m_expbinary2_circumflex_expbinary3_657(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_binary_2>& actual, leaf::parsing::instance::exp_binary_2_state& state, size_t depth);
        bool m_expbinary3_658(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_binary_2>& actual, leaf::parsing::instance::exp_binary_2_state& state, size_t depth);
        bool lr_can_exp_binary_2(size_t depth);
        std::shared_ptr<leaf::parsing::instance::exp_binary_2> lr_match_exp_binary_2(size_t depth);
        bool m_expbinary1_verticalbar_expbinary2_659(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_binary_1>& actual, leaf::parsing::instance::exp_binary_1_state& state, size_t depth);
        bool m_expbinary2_660(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_binary_1>& actual, leaf::parsing::instance::exp_binary_1_state& state, size_t depth);
        bool lr_can_exp_binary_1(size_t depth);
        std::shared_ptr<leaf::parsing::instance::exp_binary_1> lr_match_exp_binary_1(size_t depth);
        bool m_exparithmetic2_slash_expbinary1_661(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_arithmetic_2>& actual, leaf::parsing::instance::exp_arithmetic_2_state& state, size_t depth);
        bool m_exparithmetic2_star_expbinary1_662(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_arithmetic_2>& actual, leaf::parsing::instance::exp_arithmetic_2_state& state, size_t depth);
        bool m_expbinary1_663(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_arithmetic_2>& actual, leaf::parsing::instance::exp_arithmetic_2_state& state, size_t depth);
        bool lr_can_exp_arithmetic_2(size_t depth);
        std::shared_ptr<leaf::parsing::instance::exp_arithmetic_2> lr_match_exp_arithmetic_2(size_t depth);
        bool m_exparithmetic1_plus_exparithmetic2_664(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_arithmetic_1>& actual, leaf::parsing::instance::exp_arithmetic_1_state& state, size_t depth);
        bool m_exparithmetic1_minus_exparithmetic2_665(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_arithmetic_1>& actual, leaf::parsing::instance::exp_arithmetic_1_state& state, size_t depth);
        bool m_exparithmetic2_666(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_arithmetic_1>& actual, leaf::parsing::instance::exp_arithmetic_1_state& state, size_t depth);
        bool lr_can_exp_arithmetic_1(size_t depth);
        std::shared_ptr<leaf::parsing::instance::exp_arithmetic_1> lr_match_exp_arithmetic_1(size_t depth);
        bool m_expcompare_lessthenequal_exparithmetic1_667(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_compare>& actual, leaf::parsing::instance::exp_compare_state& state, size_t depth);
        bool m_expcompare_lessthen_exparithmetic1_668(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_compare>& actual, leaf::parsing::instance::exp_compare_state& state, size_t depth);
        bool m_expcompare_greaterthenequal_exparithmetic1_669(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_compare>& actual, leaf::parsing::instance::exp_compare_state& state, size_t depth);
        bool m_expcompare_greaterthen_exparithmetic1_670(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_compare>& actual, leaf::parsing::instance::exp_compare_state& state, size_t depth);
        bool m_exparithmetic1_671(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_compare>& actual, leaf::parsing::instance::exp_compare_state& state, size_t depth);
        bool lr_can_exp_compare(size_t depth);
        std::shared_ptr<leaf::parsing::instance::exp_compare> lr_match_exp_compare(size_t depth);
        bool m_expequality_exclamationequal_expcompare_672(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_equality>& actual, leaf::parsing::instance::exp_equality_state& state, size_t depth);
        bool m_expequality_equalequalequal_expcompare_673(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_equality>& actual, leaf::parsing::instance::exp_equality_state& state, size_t depth);
        bool m_expequality_equalequal_expcompare_674(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_equality>& actual, leaf::parsing::instance::exp_equality_state& state, size_t depth);
        bool m_expequality_tildeequal_expcompare_675(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_equality>& actual, leaf::parsing::instance::exp_equality_state& state, size_t depth);
        bool m_expcompare_676(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_equality>& actual, leaf::parsing::instance::exp_equality_state& state, size_t depth);
        bool lr_can_exp_equality(size_t depth);
        std::shared_ptr<leaf::parsing::instance::exp_equality> lr_match_exp_equality(size_t depth);
        bool m_expand_ampersandampersand_expequality_677(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_and>& actual, leaf::parsing::instance::exp_and_state& state, size_t depth);
        bool m_expequality_678(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_and>& actual, leaf::parsing::instance::exp_and_state& state, size_t depth);
        bool lr_can_exp_and(size_t depth);
        std::shared_ptr<leaf::parsing::instance::exp_and> lr_match_exp_and(size_t depth);
        bool m_expor_verticalbarverticalbar_expand_679(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_or>& actual, leaf::parsing::instance::exp_or_state& state, size_t depth);
        bool m_expand_680(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_or>& actual, leaf::parsing::instance::exp_or_state& state, size_t depth);
        bool lr_can_exp_or(size_t depth);
        std::shared_ptr<leaf::parsing::instance::exp_or> lr_match_exp_or(size_t depth);
        bool m_identnavigation_dot_ident_681(bool is_can, std::shared_ptr<leaf::parsing::instance::ident_navigation>& actual, leaf::parsing::instance::ident_navigation_state& state, size_t depth);
        bool m_ident_682(bool is_can, std::shared_ptr<leaf::parsing::instance::ident_navigation>& actual, leaf::parsing::instance::ident_navigation_state& state, size_t depth);
        bool lr_can_ident_navigation(size_t depth);
        std::shared_ptr<leaf::parsing::instance::ident_navigation> lr_match_ident_navigation(size_t depth);
        bool m_typenavigation_dot_ident_templateusage_683(bool is_can, std::shared_ptr<leaf::parsing::instance::type_navigation>& actual, leaf::parsing::instance::type_navigation_state& state, size_t depth);
        bool m_typenavigation_dot_ident_684(bool is_can, std::shared_ptr<leaf::parsing::instance::type_navigation>& actual, leaf::parsing::instance::type_navigation_state& state, size_t depth);
        bool m_typenavigation_templateusage_685(bool is_can, std::shared_ptr<leaf::parsing::instance::type_navigation>& actual, leaf::parsing::instance::type_navigation_state& state, size_t depth);
        bool m_ident_686(bool is_can, std::shared_ptr<leaf::parsing::instance::type_navigation>& actual, leaf::parsing::instance::type_navigation_state& state, size_t depth);
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
            _ROUND_BRACKED_OPEN,
            _ROUND_BRACKED_CLOSE,
            _SQUARE_BRACKED_OPEN,
            _SQUARE_BRACKED_CLOSE,
            _CURLY_BRACKED_OPEN,
            _CURLY_BRACKED_CLOSE,
            _GET,
            _SET,
            _WHILE,
            _IF,
            _ELSE,
            _CASE,
            _SWITCH,
            _DEFAULT,
            _EOL,
            _ASSEMBLY,
            _DOT,
            _EXCLAMATION,
            _TILDE,
            _LESS_THEN_LESS_THEN,
            _GREATER_THEN_GREATER_THEN,
            _LESS_THEN_LESS_THEN_LESS_THEN,
            _GREATER_THEN_GREATER_THEN_GREATER_THEN,
            _AMPERSAND,
            _CIRCUMFLEX,
            _VERTICAL_BAR,
            _LESS_THEN_EQUAL,
            _LESS_THEN,
            _GREATER_THEN_EQUAL,
            _GREATER_THEN,
            _EXCLAMATION_EQUAL,
            _EQUAL_EQUAL_EQUAL,
            _EQUAL_EQUAL,
            _TILDE_EQUAL,
            _AMPERSAND_AMPERSAND,
            _VERTICAL_BAR_VERTICAL_BAR,
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
            _OPERATOR,
            _SEMICOLON,
            _USING,
            _FREE,
            _ALLOC,
            _STACK,
            _HEAP,
            _TYPEOF,
            _NAMEOF,
            _SIZEOF,
            _RETURN,
            _AUTO_626,
            _EXCLAMATION_GREATER_THEN,
            _ALIGN,
            _SIZE,
            _DISABLE,
            _ENABLE,
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
        class scope
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
            std::variant<std::shared_ptr<while_loop>, std::shared_ptr<if_else>, std::shared_ptr<switch_>, std::shared_ptr<scope>, std::shared_ptr<assembly>> content;
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
        class exp_value
        {
        public:
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
            std::vector<std::shared_ptr<using_>> usings;
            std::vector<std::shared_ptr<indexer>> indexers;
            std::vector<std::shared_ptr<operator_binary_overload>> operators_binary;
            std::vector<std::shared_ptr<operator_unary_overload>> operators_unary;
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
        class method_arglist_item_with_default
        {
        public:
            std::vector<std::shared_ptr<attribute>> attributes;
            std::shared_ptr<type_match> type;
            token name;
            std::shared_ptr<exp_value> value;
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
            std::vector<std::shared_ptr<method_arglist_item_with_default>> args;
        };
        class method_arglist_indexer
        {
        public:
            std::vector<std::shared_ptr<method_arglist_item>> args;
        };
        class method
        {
        public:
            std::optional<bool> is_sealed;
            std::optional<bool> is_virtual;
            std::optional<bool> is_static;
            std::optional<bool> is_inline;
            std::vector<std::shared_ptr<attribute>> attributes;
            std::shared_ptr<encapsulation> encaps;
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
            std::shared_ptr<encapsulation> encaps;
            std::shared_ptr<type_match> target_type;
            std::shared_ptr<type_match> source_type;
            token name;
            std::shared_ptr<scope> body;
        };
        class indexer
        {
        public:
            std::vector<std::shared_ptr<attribute>> attributes;
            std::shared_ptr<encapsulation> encaps;
            std::shared_ptr<type_match> target_type;
            std::shared_ptr<template_definition> template_;
            std::shared_ptr<method_arglist_indexer> arglist;
            std::shared_ptr<scope_getset> body;
        };
        class operator_binary_overload
        {
        public:
            std::optional<bool> is_inline;
            std::vector<std::shared_ptr<attribute>> attributes;
            std::shared_ptr<encapsulation> encaps;
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
            std::optional<bool> is_inline;
            std::vector<std::shared_ptr<attribute>> attributes;
            std::shared_ptr<encapsulation> encaps;
            std::shared_ptr<type_match> target_type;
            std::shared_ptr<template_definition> template_;
            token operator_;
            std::shared_ptr<method_arglist_item> right;
            std::shared_ptr<scope> body;
        };
        class property
        {
        public:
            std::optional<bool> is_sealed;
            std::optional<bool> is_virtual;
            std::optional<bool> is_static;
            std::vector<std::shared_ptr<attribute>> attributes;
            std::shared_ptr<encapsulation> encaps;
            std::shared_ptr<type_match> target_type;
            token name;
            std::shared_ptr<scope_getset> body;
        };
        class field
        {
        public:
            std::optional<bool> is_sealed;
            std::optional<bool> is_virtual;
            std::optional<bool> is_static;
            std::vector<std::shared_ptr<attribute>> attributes;
            std::shared_ptr<encapsulation> encaps;
            std::shared_ptr<type_match> target_type;
            token name;
        };
        class using_
        {
        public:
            std::optional<bool> is_namespace;
            std::optional<bool> is_class;
            std::shared_ptr<ident_navigation> ident;
            token alias;
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
        class template_definition_item
        {
        public:
            token key;
            std::shared_ptr<exp_value> value;
        };
        class template_definition
        {
        public:
            std::vector<std::shared_ptr<template_definition_item>> items;
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
        class type_match
        {
        public:
            std::optional<bool> is_array;
            std::optional<bool> is_heap;
            std::shared_ptr<type_navigation> base;
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
        class statement
        {
        public:
            std::shared_ptr<expression> ret;
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
        class main
        {
        public:
            std::vector<std::shared_ptr<using_>> usings;
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
        class scope_state
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
        class method_arglist_item_with_default_state
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
        class property_state
        {
        };
        class field_state
        {
        };
        class using__state
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
        class template_usage_item_state
        {
        };
        class template_usage_state
        {
        };
        class template_definition_item_state
        {
        };
        class template_definition_state
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
        std::vector<std::string> create_string_tree(std::shared_ptr<scope> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<scope_getset> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<control_structure_body> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<while_loop> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<if_body> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<else_body> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<if_else> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<switch_case> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<switch_> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<assembly_terminate> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<assembly> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<control_structure> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<exp_chain_start> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<exp_constant> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<exp_value> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<exp_nullar> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<exp_unary> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<expression> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<encapsulation> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<namespace_> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<class_> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<method_arglist_item_with_default> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<method_arglist_item> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<method_arglist> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<method_arglist_indexer> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<method> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<constructor> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<destructor> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<copystructor> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<conversion> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<indexer> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<operator_binary_overload> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<operator_unary_overload> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<property> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<field> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<using_> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<call> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<call_body> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<free> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<alloc> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<template_usage_item> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<template_usage> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<template_definition_item> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<template_definition> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<typeof_> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<nameof> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<sizeof_> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<type_match> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<string_formatable> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<string_literal> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<scalar_literal> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<integer_hex_literal> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<integer_binary_literal> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<integer_literal> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<char_literal> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<declaration> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<statement> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<pragma> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<pragma_align> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<pragma_size> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<pragma_disable> node, std::string_view contents);
        std::vector<std::string> create_string_tree(std::shared_ptr<pragma_enable> node, std::string_view contents);
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
            bool visit(std::shared_ptr<scope> node);
            bool visit(std::shared_ptr<scope_getset> node);
            bool visit(std::shared_ptr<control_structure_body> node);
            bool visit(std::shared_ptr<while_loop> node);
            bool visit(std::shared_ptr<if_body> node);
            bool visit(std::shared_ptr<else_body> node);
            bool visit(std::shared_ptr<if_else> node);
            bool visit(std::shared_ptr<switch_case> node);
            bool visit(std::shared_ptr<switch_> node);
            bool visit(std::shared_ptr<assembly_terminate> node);
            bool visit(std::shared_ptr<assembly> node);
            bool visit(std::shared_ptr<control_structure> node);
            bool visit(std::shared_ptr<exp_chain_start> node);
            bool visit(std::shared_ptr<exp_constant> node);
            bool visit(std::shared_ptr<exp_value> node);
            bool visit(std::shared_ptr<exp_nullar> node);
            bool visit(std::shared_ptr<exp_unary> node);
            bool visit(std::shared_ptr<expression> node);
            bool visit(std::shared_ptr<encapsulation> node);
            bool visit(std::shared_ptr<namespace_> node);
            bool visit(std::shared_ptr<class_> node);
            bool visit(std::shared_ptr<method_arglist_item_with_default> node);
            bool visit(std::shared_ptr<method_arglist_item> node);
            bool visit(std::shared_ptr<method_arglist> node);
            bool visit(std::shared_ptr<method_arglist_indexer> node);
            bool visit(std::shared_ptr<method> node);
            bool visit(std::shared_ptr<constructor> node);
            bool visit(std::shared_ptr<destructor> node);
            bool visit(std::shared_ptr<copystructor> node);
            bool visit(std::shared_ptr<conversion> node);
            bool visit(std::shared_ptr<indexer> node);
            bool visit(std::shared_ptr<operator_binary_overload> node);
            bool visit(std::shared_ptr<operator_unary_overload> node);
            bool visit(std::shared_ptr<property> node);
            bool visit(std::shared_ptr<field> node);
            bool visit(std::shared_ptr<using_> node);
            bool visit(std::shared_ptr<call> node);
            bool visit(std::shared_ptr<call_body> node);
            bool visit(std::shared_ptr<free> node);
            bool visit(std::shared_ptr<alloc> node);
            bool visit(std::shared_ptr<template_usage_item> node);
            bool visit(std::shared_ptr<template_usage> node);
            bool visit(std::shared_ptr<template_definition_item> node);
            bool visit(std::shared_ptr<template_definition> node);
            bool visit(std::shared_ptr<typeof_> node);
            bool visit(std::shared_ptr<nameof> node);
            bool visit(std::shared_ptr<sizeof_> node);
            bool visit(std::shared_ptr<type_match> node);
            bool visit(std::shared_ptr<string_formatable> node);
            bool visit(std::shared_ptr<string_literal> node);
            bool visit(std::shared_ptr<scalar_literal> node);
            bool visit(std::shared_ptr<integer_hex_literal> node);
            bool visit(std::shared_ptr<integer_binary_literal> node);
            bool visit(std::shared_ptr<integer_literal> node);
            bool visit(std::shared_ptr<char_literal> node);
            bool visit(std::shared_ptr<declaration> node);
            bool visit(std::shared_ptr<statement> node);
            bool visit(std::shared_ptr<pragma> node);
            bool visit(std::shared_ptr<pragma_align> node);
            bool visit(std::shared_ptr<pragma_size> node);
            bool visit(std::shared_ptr<pragma_disable> node);
            bool visit(std::shared_ptr<pragma_enable> node);
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
            virtual bool visit_enter(std::shared_ptr<scope> node);
            virtual bool visit_enter(std::shared_ptr<scope_getset> node);
            virtual bool visit_enter(std::shared_ptr<control_structure_body> node);
            virtual bool visit_enter(std::shared_ptr<while_loop> node);
            virtual bool visit_enter(std::shared_ptr<if_body> node);
            virtual bool visit_enter(std::shared_ptr<else_body> node);
            virtual bool visit_enter(std::shared_ptr<if_else> node);
            virtual bool visit_enter(std::shared_ptr<switch_case> node);
            virtual bool visit_enter(std::shared_ptr<switch_> node);
            virtual bool visit_enter(std::shared_ptr<assembly_terminate> node);
            virtual bool visit_enter(std::shared_ptr<assembly> node);
            virtual bool visit_enter(std::shared_ptr<control_structure> node);
            virtual bool visit_enter(std::shared_ptr<exp_chain_start> node);
            virtual bool visit_enter(std::shared_ptr<exp_constant> node);
            virtual bool visit_enter(std::shared_ptr<exp_value> node);
            virtual bool visit_enter(std::shared_ptr<exp_nullar> node);
            virtual bool visit_enter(std::shared_ptr<exp_unary> node);
            virtual bool visit_enter(std::shared_ptr<expression> node);
            virtual bool visit_enter(std::shared_ptr<encapsulation> node);
            virtual bool visit_enter(std::shared_ptr<namespace_> node);
            virtual bool visit_enter(std::shared_ptr<class_> node);
            virtual bool visit_enter(std::shared_ptr<method_arglist_item_with_default> node);
            virtual bool visit_enter(std::shared_ptr<method_arglist_item> node);
            virtual bool visit_enter(std::shared_ptr<method_arglist> node);
            virtual bool visit_enter(std::shared_ptr<method_arglist_indexer> node);
            virtual bool visit_enter(std::shared_ptr<method> node);
            virtual bool visit_enter(std::shared_ptr<constructor> node);
            virtual bool visit_enter(std::shared_ptr<destructor> node);
            virtual bool visit_enter(std::shared_ptr<copystructor> node);
            virtual bool visit_enter(std::shared_ptr<conversion> node);
            virtual bool visit_enter(std::shared_ptr<indexer> node);
            virtual bool visit_enter(std::shared_ptr<operator_binary_overload> node);
            virtual bool visit_enter(std::shared_ptr<operator_unary_overload> node);
            virtual bool visit_enter(std::shared_ptr<property> node);
            virtual bool visit_enter(std::shared_ptr<field> node);
            virtual bool visit_enter(std::shared_ptr<using_> node);
            virtual bool visit_enter(std::shared_ptr<call> node);
            virtual bool visit_enter(std::shared_ptr<call_body> node);
            virtual bool visit_enter(std::shared_ptr<free> node);
            virtual bool visit_enter(std::shared_ptr<alloc> node);
            virtual bool visit_enter(std::shared_ptr<template_usage_item> node);
            virtual bool visit_enter(std::shared_ptr<template_usage> node);
            virtual bool visit_enter(std::shared_ptr<template_definition_item> node);
            virtual bool visit_enter(std::shared_ptr<template_definition> node);
            virtual bool visit_enter(std::shared_ptr<typeof_> node);
            virtual bool visit_enter(std::shared_ptr<nameof> node);
            virtual bool visit_enter(std::shared_ptr<sizeof_> node);
            virtual bool visit_enter(std::shared_ptr<type_match> node);
            virtual bool visit_enter(std::shared_ptr<string_formatable> node);
            virtual bool visit_enter(std::shared_ptr<string_literal> node);
            virtual bool visit_enter(std::shared_ptr<scalar_literal> node);
            virtual bool visit_enter(std::shared_ptr<integer_hex_literal> node);
            virtual bool visit_enter(std::shared_ptr<integer_binary_literal> node);
            virtual bool visit_enter(std::shared_ptr<integer_literal> node);
            virtual bool visit_enter(std::shared_ptr<char_literal> node);
            virtual bool visit_enter(std::shared_ptr<declaration> node);
            virtual bool visit_enter(std::shared_ptr<statement> node);
            virtual bool visit_enter(std::shared_ptr<pragma> node);
            virtual bool visit_enter(std::shared_ptr<pragma_align> node);
            virtual bool visit_enter(std::shared_ptr<pragma_size> node);
            virtual bool visit_enter(std::shared_ptr<pragma_disable> node);
            virtual bool visit_enter(std::shared_ptr<pragma_enable> node);
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
            virtual bool visit_leave(std::shared_ptr<scope> node);
            virtual bool visit_leave(std::shared_ptr<scope_getset> node);
            virtual bool visit_leave(std::shared_ptr<control_structure_body> node);
            virtual bool visit_leave(std::shared_ptr<while_loop> node);
            virtual bool visit_leave(std::shared_ptr<if_body> node);
            virtual bool visit_leave(std::shared_ptr<else_body> node);
            virtual bool visit_leave(std::shared_ptr<if_else> node);
            virtual bool visit_leave(std::shared_ptr<switch_case> node);
            virtual bool visit_leave(std::shared_ptr<switch_> node);
            virtual bool visit_leave(std::shared_ptr<assembly_terminate> node);
            virtual bool visit_leave(std::shared_ptr<assembly> node);
            virtual bool visit_leave(std::shared_ptr<control_structure> node);
            virtual bool visit_leave(std::shared_ptr<exp_chain_start> node);
            virtual bool visit_leave(std::shared_ptr<exp_constant> node);
            virtual bool visit_leave(std::shared_ptr<exp_value> node);
            virtual bool visit_leave(std::shared_ptr<exp_nullar> node);
            virtual bool visit_leave(std::shared_ptr<exp_unary> node);
            virtual bool visit_leave(std::shared_ptr<expression> node);
            virtual bool visit_leave(std::shared_ptr<encapsulation> node);
            virtual bool visit_leave(std::shared_ptr<namespace_> node);
            virtual bool visit_leave(std::shared_ptr<class_> node);
            virtual bool visit_leave(std::shared_ptr<method_arglist_item_with_default> node);
            virtual bool visit_leave(std::shared_ptr<method_arglist_item> node);
            virtual bool visit_leave(std::shared_ptr<method_arglist> node);
            virtual bool visit_leave(std::shared_ptr<method_arglist_indexer> node);
            virtual bool visit_leave(std::shared_ptr<method> node);
            virtual bool visit_leave(std::shared_ptr<constructor> node);
            virtual bool visit_leave(std::shared_ptr<destructor> node);
            virtual bool visit_leave(std::shared_ptr<copystructor> node);
            virtual bool visit_leave(std::shared_ptr<conversion> node);
            virtual bool visit_leave(std::shared_ptr<indexer> node);
            virtual bool visit_leave(std::shared_ptr<operator_binary_overload> node);
            virtual bool visit_leave(std::shared_ptr<operator_unary_overload> node);
            virtual bool visit_leave(std::shared_ptr<property> node);
            virtual bool visit_leave(std::shared_ptr<field> node);
            virtual bool visit_leave(std::shared_ptr<using_> node);
            virtual bool visit_leave(std::shared_ptr<call> node);
            virtual bool visit_leave(std::shared_ptr<call_body> node);
            virtual bool visit_leave(std::shared_ptr<free> node);
            virtual bool visit_leave(std::shared_ptr<alloc> node);
            virtual bool visit_leave(std::shared_ptr<template_usage_item> node);
            virtual bool visit_leave(std::shared_ptr<template_usage> node);
            virtual bool visit_leave(std::shared_ptr<template_definition_item> node);
            virtual bool visit_leave(std::shared_ptr<template_definition> node);
            virtual bool visit_leave(std::shared_ptr<typeof_> node);
            virtual bool visit_leave(std::shared_ptr<nameof> node);
            virtual bool visit_leave(std::shared_ptr<sizeof_> node);
            virtual bool visit_leave(std::shared_ptr<type_match> node);
            virtual bool visit_leave(std::shared_ptr<string_formatable> node);
            virtual bool visit_leave(std::shared_ptr<string_literal> node);
            virtual bool visit_leave(std::shared_ptr<scalar_literal> node);
            virtual bool visit_leave(std::shared_ptr<integer_hex_literal> node);
            virtual bool visit_leave(std::shared_ptr<integer_binary_literal> node);
            virtual bool visit_leave(std::shared_ptr<integer_literal> node);
            virtual bool visit_leave(std::shared_ptr<char_literal> node);
            virtual bool visit_leave(std::shared_ptr<declaration> node);
            virtual bool visit_leave(std::shared_ptr<statement> node);
            virtual bool visit_leave(std::shared_ptr<pragma> node);
            virtual bool visit_leave(std::shared_ptr<pragma_align> node);
            virtual bool visit_leave(std::shared_ptr<pragma_size> node);
            virtual bool visit_leave(std::shared_ptr<pragma_disable> node);
            virtual bool visit_leave(std::shared_ptr<pragma_enable> node);
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
