#pragma once
#include "stage_base.hpp"

namespace leaf::compilation::stages
{
    struct register_types : public stage_base
    {
    protected:
        virtual bool visit_enter(std::shared_ptr<leaf::parsing::instance::namespace_> node) override;
        virtual bool visit_enter(std::shared_ptr<leaf::parsing::instance::class_> node) override;
    };
}