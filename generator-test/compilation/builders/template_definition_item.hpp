//
// Created by marco.silipo on 29.09.2021.
//

#ifndef SOLUTION_TEMPLATE_DEFINITION_ITEM_HPP
#define SOLUTION_TEMPLATE_DEFINITION_ITEM_HPP

#include <string>
#include <string_view>

namespace leaf::compilation::builders
{
    class template_definition_item
    {
    public:
        enum class type_enum {
            direct_type,
            identifier,
        };
    private:
        type_enum m_type;
        std::string m_name;
    public:
        template_definition_item(std::string name, type_enum type) : m_type(type), m_name(name) {}
        [[nodiscard]] type_enum type() const { return m_type; }
        [[nodiscard]] std::string_view name() const { return m_name; }
    };
}

#endif //SOLUTION_TEMPLATE_DEFINITION_ITEM_HPP
