#include "leaf_compiler.hpp"
#include <stdexcept>
#include <charconv>

leaf::compilation::compilation_unit::constant_type leaf::compilation::compilation_unit::get(const std::shared_ptr<leaf::parsing::instance::exp_constant>& node) const
{
    if (node->name)
    {
        // ToDo: Implement
        throw std::runtime_error("Not Implemented.");
    }
    else if (node->type)
    {
        // ToDo: Implement
        throw std::runtime_error("Not Implemented.");
    }
    else if (node->t.type == leaf::parsing::instance::tok::SCALAR)
    {
        auto val = get(node->t);
        double d;
        if (auto [p, ec] = std::from_chars(val.data(), val.data() + val.length(), d); ec == std::errc())
        {
            return { d };
        }
        else
        {
            throw std::runtime_error("Failed to parse scalar.");
        }
    }
    else if (node->t.type == leaf::parsing::instance::tok::BOOLEAN)
    {
        auto val = get(node->t);
        if (val.length() > 1 && val[0] == 't')
        {
            return { true };
        }
        else if (val.length() > 1 && val[0] == 'f')
        {
            return { false };
        }
        else
        {
            throw std::runtime_error("Failed to parse boolean.");
        }
    }
    else if (node->t.type == leaf::parsing::instance::tok::INTEGER)
    {
        auto val = get(node->t);
        if (val.length() > 1 && (val[0] == '+' || val[0] == '-'))
        {
            int64_t i;
            if (auto [p, ec] = std::from_chars(val.data(), val.data() + val.length(), i); ec == std::errc())
            {
                return { i };
            }
            else
            {
                throw std::runtime_error("Failed to parse integer.");
            }
        }
        else
        {
            uint64_t i;
            if (auto [p, ec] = std::from_chars(val.data(), val.data() + val.length(), i); ec == std::errc())
            {
                return { i };
            }
            else
            {
                throw std::runtime_error("Failed to parse integer.");
            }
        }
    }
    else
    {
        throw std::runtime_error("Unknown exp-constant.");
    }
}
