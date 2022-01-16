//
// Created by marco.silipo on 15.11.2021.
//

#ifndef SOLUTION_UTILITY_HPP
#define SOLUTION_UTILITY_HPP

#include "../parser.hpp"
#include <string>
#include <string_view>

namespace leaf::compilation::utility
{
    std::string to_string(const char* text, leaf::parsing::instance::token token);
    std::string to_string(std::string_view view, leaf::parsing::instance::token token)
    { return to_string(view.data(), token); }
    std::string_view to_string_view(const char* text, leaf::parsing::instance::token token);
    std::string_view to_string_view(std::string_view view, leaf::parsing::instance::token token)
    { return to_string_view(view.data(), token); }

    std::string to_string(const char* text, std::shared_ptr<leaf::parsing::instance::ident_navigation> ident_navigation);
    std::string to_string(std::string_view view, std::shared_ptr<leaf::parsing::instance::ident_navigation> ident_navigation)
    { return to_string(view.data(), ident_navigation); }
}


#endif //SOLUTION_UTILITY_HPP
