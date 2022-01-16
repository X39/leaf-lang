//
// Created by marco.silipo on 29.09.2021.
//

#ifndef SOLUTION_AST_TYPE_BUILDER_HPP
#define SOLUTION_TYPE_BUILDER_HPP


#include <memory>

namespace leaf::compilation::builders
{
    class type_builder
    {
    public:
        using sptr = std::shared_ptr<type_builder>;
    };
}


#endif //SOLUTION_AST_TYPE_BUILDER_HPP
