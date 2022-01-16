//
// Created by marco.silipo on 15.11.2021.
//

#include "utility.hpp"

#include <sstream>
using namespace std;

std::string leaf::compilation::utility::to_string(const char* text, leaf::parsing::instance::token token)
{
    return {text + token.offset, token.length };
}

std::string_view leaf::compilation::utility::to_string_view(const char* text, leaf::parsing::instance::token token)
{
    return {text + token.offset, token.length };
}

std::string leaf::compilation::utility::to_string(const char* text, std::shared_ptr<leaf::parsing::instance::ident_navigation> ident_navigation)
{
    stringstream sstream;
    while (holds_alternative<std::shared_ptr<leaf::parsing::instance::ident_navigation>>(ident_navigation->left))
    {
        sstream << "::" << to_string_view(text,ident_navigation->right);
        ident_navigation = get<std::shared_ptr<leaf::parsing::instance::ident_navigation>>(ident_navigation->left);
    }
    sstream << "::" << to_string_view(text,ident_navigation->right);
    return sstream.str();
}