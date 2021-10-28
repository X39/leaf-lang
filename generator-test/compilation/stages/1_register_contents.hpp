#pragma once
#include "stage_base.hpp"

namespace leaf::compilation::stages
{
    struct register_contents : public stage_base
    {
        register_contents() : m_parameter_info_list(nullptr) { }
    protected:
        virtual bool visit_enter(std::shared_ptr<leaf::parsing::instance::property> node) override;
        virtual bool visit_enter(std::shared_ptr<leaf::parsing::instance::method> node) override;
        virtual bool visit_enter(std::shared_ptr<leaf::parsing::instance::field> node) override;
        virtual bool visit_enter(std::shared_ptr<leaf::parsing::instance::conversion> node) override;
        virtual bool visit_enter(std::shared_ptr<leaf::parsing::instance::operator_binary_overload> node) override;
        virtual bool visit_enter(std::shared_ptr<leaf::parsing::instance::operator_unary_overload> node) override;
        virtual bool visit_enter(std::shared_ptr<leaf::parsing::instance::constructor> node) override;
        virtual bool visit_enter(std::shared_ptr<leaf::parsing::instance::copystructor> node) override;
        virtual bool visit_enter(std::shared_ptr<leaf::parsing::instance::destructor> node) override;
        virtual bool visit_enter(std::shared_ptr<leaf::parsing::instance::method_arglist_item> node) override;
    private:
        // Temporary hold the current methods parameter info list as pointer to auto-fill them via visiting
        leaf_parameter_info_list* m_parameter_info_list;
    };
}