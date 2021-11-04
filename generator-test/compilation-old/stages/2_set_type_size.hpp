#pragma once
#include "../compiler.hpp"
#include "stage_base.hpp"
#include <vector>
#include <string>
#include <string_view>

namespace leaf::compilation::stages
{
    struct set_type_size : public stage_base
    {
        const size_t max_visits = 10;
        virtual bool execute(leaf::compilation::compilation_unit& c) override
        {
            if (++m_visits > max_visits)
            {
                // ToDo: Report error
                return false;
            }
            return stage_base::execute(c);
        }
        set_type_size() : m_visits(0) { }
    protected:
        virtual bool visit_enter(std::shared_ptr<leaf::parsing::instance::namespace_> node) override;
        virtual bool visit_enter(std::shared_ptr<leaf::parsing::instance::class_> node) override;
    private:
        size_t m_visits;
    };
}