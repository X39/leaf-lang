#pragma once
#include <memory>
#include <variant>
#include <string_view>
#include "../parser.hpp"
#include "../runtime/leaf_type.h"
namespace leaf::compilation::visitors
{
    class value_reference
    {
    public:
        using value_union = std::variant<
                uint8_t,
                uint16_t,
                uint32_t,
                uint64_t,
                int8_t,
                int16_t,
                int32_t,
                int64_t,
                float,
                double,
                bool,
                std::string
                >;
    private:
        bool m_holds_constant;
        value_union m_value;
        leaf_type_reference m_type_reference;
        leaf_type_ptr m_type_ptr;
    public:
        value_reference() :
                m_holds_constant(false),
                m_type_reference(),
                m_type_ptr(nullptr)
        {
            m_type_reference.index = leaf_TYPE_REFERENCE_VOID_INDEX;
        }
        value_reference(leaf_type_ptr type_ptr, leaf_type_reference type_reference) :
                m_holds_constant(false),
                m_type_reference(type_reference),
                m_type_ptr(type_ptr)
        {
        }

        void set_type(leaf_type_ptr type_ptr, leaf_type_reference type_reference)
        {
            m_type_ptr = type_ptr;
            m_type_reference = type_reference;
        }
        [[nodiscard]] leaf_type_ptr get_type_ptr() const { return m_type_ptr; }
        [[nodiscard]] leaf_type_reference get_type_reference() const { return m_type_reference; }
        [[nodiscard]] bool is_good() const { return m_type_ptr; }

        [[nodiscard]] std::string_view type_name() const
        {
            return std::string_view(m_type_ptr->name.data, m_type_ptr->name.length);
        }


        void set_constant(uint8_t value)        { if (type_name() != "leaf::ui8") { throw std::runtime_error("Type not matching."); } m_value = value; m_holds_constant = true; }
        void set_constant(uint16_t value)       { if (type_name() != "leaf::ui16") { throw std::runtime_error("Type not matching."); } m_value = value; m_holds_constant = true; }
        void set_constant(uint32_t value)       { if (type_name() != "leaf::ui32") { throw std::runtime_error("Type not matching."); } m_value = value; m_holds_constant = true; }
        void set_constant(uint64_t value)       { if (type_name() != "leaf::ui64") { throw std::runtime_error("Type not matching."); } m_value = value; m_holds_constant = true; }
        void set_constant(int8_t value)         { if (type_name() != "leaf::i8") { throw std::runtime_error("Type not matching."); } m_value = value; m_holds_constant = true; }
        void set_constant(int16_t value)        { if (type_name() != "leaf::i16") { throw std::runtime_error("Type not matching."); } m_value = value; m_holds_constant = true; }
        void set_constant(int32_t value)        { if (type_name() != "leaf::i32") { throw std::runtime_error("Type not matching."); } m_value = value; m_holds_constant = true; }
        void set_constant(int64_t value)        { if (type_name() != "leaf::i64") { throw std::runtime_error("Type not matching."); } m_value = value; m_holds_constant = true; }
        void set_constant(float value)          { if (type_name() != "leaf::f32") { throw std::runtime_error("Type not matching."); } m_value = value; m_holds_constant = true; }
        void set_constant(double value)         { if (type_name() != "leaf::f64") { throw std::runtime_error("Type not matching."); } m_value = value; m_holds_constant = true; }
        void set_constant(bool value)           { if (type_name() != "leaf::bool") { throw std::runtime_error("Type not matching."); } m_value = value; m_holds_constant = true; }
        void set_constant(std::string value)    { if (type_name() != "leaf::string") { throw std::runtime_error("Type not matching."); } m_value = value; m_holds_constant = true; }

        void clear_constant() { m_value = {}; m_holds_constant = false; }

        template<typename T>
        T get_constant<T>() const
        {
            if (m_holds_constant && std::holds_alternative<T>(m_value))
            {
                return std::get<T>(m_value);
            }
            else
            {
                throw std::runtime_error("Type not matching.");
            }
        }
    };
}