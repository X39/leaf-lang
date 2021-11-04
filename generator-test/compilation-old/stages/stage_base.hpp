#pragma once
#include "../compiler.hpp"
#include <vector>
#include <string>
#include <string_view>

namespace leaf::compilation::stages
{
    struct stage_base : public compilation_stage, public leaf::parsing::instance::visitor
    {
        virtual bool execute(leaf::compilation::compilation_unit& c) override
        {
            m_cu = &c;
            return visit(m_cu->cst());
        }
        stage_base()
        {
            helper.push_scope();
        }
        union constants_union
        {
            uint8_t ui8;
            uint16_t ui16;
            uint32_t ui32;
            uint64_t ui64;
            int8_t i8;
            int16_t i16;
            int32_t i32;
            int64_t i64;
            float f32;
            double f64;
            bool b;
        };
    protected:
        struct value_tuple
        {
            constants_union as;
            bool has_constant;
            std::string name;
            leaf_type_reference type_reference;
            leaf_type_ptr type_ptr;
            size_t size;
            size_t negative_offset;
            bool is_return_value;

            // Whether this value_tuple is actually owned by a scope_meta where it was received from
            bool is_owned_by_scope;
        };
        struct using_tuple
        {
            std::string alias;
            std::string full_name;
        };
        struct type_conversion_tuple
        {
            leaf_method_info_ptr conversion_method_info;
            leaf_type_ptr source_type;
            leaf_type_ptr target_type;
        };
        class using_helper_class;
        class scope_meta
        {
            friend class using_helper_class;
            std::vector<type_conversion_tuple> m_type_conversion_tuple;
            std::vector<using_tuple> m_usings;
            std::vector<value_tuple> m_values;
        public:
            scope_meta() { }
            scope_meta(const scope_meta& orig)
            {
                m_values = orig.m_values;
                for (auto& it : m_values)
                {
                    it.is_owned_by_scope = false;
                }
            }
            uint8_list* bytecode;
            // Checks whether a given variable is contained inside of this scope_meta
            // @param name The variable name to check
            // @return True if the variable exists, false if not.
            bool contains_variable(std::string_view name) const
            {
                auto res = std::find_if(m_values.begin(), m_values.end(), [&name](const value_tuple& t) -> bool { return t.name == name; });
                return res != m_values.end();
            }

            size_t values_size() const { return m_values.size(); }

            // Attempts to receive the given variable_tuple via its name.
            // @param name The variable name to check
            // @param out The out pointer that may get altered if the variable_tuple was found.
            // @return True if the variable exists, false if not.
            bool try_get_variable(std::string_view name, value_tuple& out) const
            {
                auto res = std::find_if(m_values.begin(), m_values.end(), [&name](const value_tuple& t) -> bool { return t.name == name; });
                if (res != m_values.end())
                {
                    out = *res;
                    return true;
                }
                return false;
            }

            // Pushes a new variable to the scope_meta,
            // adjusting the offsets etc. to prior variable types accordingly.
            // Variables may only be pushed when no value is on stack. An exception will be thrown in those cases where that is true.
            // @param name The name of the variable to add
            // @param type The type of the variable to add
            value_tuple push_variable(std::string_view name, leaf_type_reference type_reference, leaf_type_ptr type_ptr)
            {
                if (!m_values.empty() && m_values.back().name.empty()) { throw std::runtime_error("Cannot add variable while value is on stack."); }
                value_tuple t;
                t.name = std::string(name.begin(), name.end());
                t.type_reference = type_reference;
                t.type_ptr = type_ptr;
                t.size = type_reference.flags == YSF_POINTER ? leaf_POINTER_SIZE : type_ptr->instance_size;
                t.negative_offset = t.size;
                t.is_owned_by_scope = true;
                t.is_return_value = false;
                t.has_constant = false;
                t.as = { 0 };
                for (auto& it : m_values)
                {
                    it.negative_offset += t.size;
                }
                m_values.push_back(t);
                return t;
            }

            // Pushes a new value to the scope_meta,
            // adjusting the offsets etc. to prior variable types accordingly.
            // @param name The name of the variable to add
            // @param type The type of the variable to add
            value_tuple push_value(leaf_type_reference type_reference, leaf_type_ptr type_ptr)
            {
                value_tuple t;
                t.name = {};
                t.type_reference = type_reference;
                t.type_ptr = type_ptr;
                t.size = type_reference.flags == YSF_POINTER ? leaf_POINTER_SIZE : type_ptr->instance_size;
                t.negative_offset = t.size;
                t.is_return_value = false;
                t.is_owned_by_scope = true;
                t.as = { 0 };
                t.has_constant = true;
                for (auto& it : m_values)
                {
                    it.negative_offset += t.size;
                }
                m_values.push_back(t);
                return t;
            }
            void push_type_conversion(leaf_method_info_ptr involved_method, leaf_type_ptr source_type, leaf_type_ptr target_type)
            {
                m_type_conversion_tuple.push_back({ involved_method, source_type, target_type });
            }
            bool try_get_conversions(leaf_type_ptr source_type, leaf_type_ptr target_type, std::vector<type_conversion_tuple>& out_tuples)
            {
                // If equal, return true without modifying out_tuples as no conversion is needed
                if (source_type == target_type) { return true; }

                // iterate over types to find possible conversions
                bool conversions_located = false;
                for (auto& t : m_type_conversion_tuple)
                {
                    if (t.target_type == target_type && t.source_type == source_type)
                    {
                        conversions_located = true;
                        out_tuples.push_back(t);
                    }
                }

                return conversions_located;
            }

            // Pushes a new value to the scope_meta,
            // adjusting the offsets etc. to prior variable types accordingly.
            // @param name The name of the variable to add
            // @param type The type of the variable to add
            // @param as A constant value if available
            value_tuple push_value(leaf_type_reference type_reference, leaf_type_ptr type_ptr, constants_union as)
            {
                value_tuple t;
                t.name = {};
                t.type_reference = type_reference;
                t.type_ptr = type_ptr;
                t.size = type_reference.flags == YSF_POINTER ? leaf_POINTER_SIZE : type_ptr->instance_size;
                t.negative_offset = t.size;
                t.is_return_value = false;
                t.is_reference = false;
                t.is_owned_by_scope = true;
                t.as = as;
                t.has_constant = true;
                for (auto& it : m_values)
                {
                    it.negative_offset += t.size;
                }
                m_values.push_back(t);
                return t;
            }

            void mark_last_value_as_return_value()
            {
                m_values.back().is_return_value = true;
            }

            // Pushes a new value to the scope_meta,
            // adjusting the offsets etc. to prior variable types accordingly.
            // @param name The name of the variable to add
            // @param type The type of the variable to add
            void push_value_tuple(value_tuple in)
            {
                in.is_reference = true;
                in.is_owned_by_scope = true;
                m_values.push_back(in);
            }

            void pop_value()
            {
                if (m_values.empty()) { return; }
                if (!m_values.back().name.empty()) { throw std::runtime_error("Cannot pop value as no more values are on stack."); }
                pop();
            }
            void pop()
            {
                if (m_values.empty()) { return; }
                value_tuple t = m_values.back();
                m_values.pop_back();
                for (auto& it : m_values)
                {
                    it.negative_offset -= t.size;
                }
            }
            void pop_to(size_t targeted_size)
            {
                while (m_values.size() > targeted_size)
                {
                    pop();
                }
            }

            void push_using(using_tuple ut)
            {
                m_usings.push_back(ut);
            }
            void pop_using()
            {
                m_usings.pop_back();
            }

            // Returns a given value tuple from the values.
            // Will throw an exception if an invalid index is attempted to be accessed.
            // @param negative_index The index of the value where 0 is the latest one added
            // @return A value_tuple that is valid.
            value_tuple at(size_t negative_index)
            {
                if (negative_index == SIZE_MAX) { throw std::runtime_error("negative_index is equivalent to SIZE_MAX (out of bounds)."); }
                if (m_values.size() >= (m_values.size() - negative_index - 1)) { throw std::runtime_error("negative_index is larger then the available pool of variables (out of bounds)."); }
                return m_values[m_values.size() - negative_index - 1];
            }
            // Equivalent to calling scope_meta::at(0).
            // @return The last value_tuple that is valid.
            inline value_tuple values_back() { return at(0); }



            // Clones the source value to the target, possibly calling a copy-constructor if needed.
            // @param source_negative_index The index that the source lives at where 0 is the latest one added.
            // @param target_negative_index The index that the target lives at where 0 is the latest one added.
            void clone(size_t source_negative_index, size_t target_negative_index);
            // Moves the source value to the target.
            // @param source_negative_index The index that the source lives at where 0 is the latest one added.
            // @param target_negative_index The index that the target lives at where 0 is the latest one added.
            void move(size_t source_negative_index, size_t target_negative_index);
            // Destroys the element at the given index, possibly calling a destructor if needed.
            // @param negative_index The index of the value where 0 is the latest one added
            void destroy(size_t negative_index);

            // Pops the latest element added, possibly calling a destructor if needed.
            void pop_destroy()
            {
                destroy(0);
                pop();
            }
            // Destroys all elements on this value stack. A grace range is possible to provide to allow
            // to easily destroy everything but the returned values. In that case, the graced values
            // will be moved to the end.
            // @param grace Amount of values to not destroy at the end
            void destroy_all(size_t grace = 0)
            {
                if (values_size() > 1 && grace < values_size())
                {
                    for (size_t i = values_size() - grace; i != (~(size_t)0) && m_values[i].is_owned_by_scope; i--)
                    {
                        destroy(i);
                    }
                    for (size_t i = 0; i < grace; i++)
                    {
                        // ToDo: Implement Move
                    }
                }
            }
        };
        class using_helper_class
        {
            std::vector<scope_meta> m_scopes;
            std::vector<leaf_type_ptr> m_types;
        public:
            using iterator = std::vector<std::vector<using_tuple>>::iterator;
            void push_type(leaf_type_ptr type_ptr)
            {
                m_types.push_back(type_ptr);
            }
            void pop_type()
            {
                m_types.pop_back();
            }
            leaf_type_ptr current_type() const
            {
                if (m_types.empty()) { throw std::runtime_error("No using scope set."); }
                return m_types.back();
            }
            bool has_type() const
            {
                return !m_types.empty();
            }


            void push_scope()
            {
                auto scope = current_scope();
                m_scopes.push_back(scope);
            }
            void pop_scope()
            {
                m_scopes.pop_back();
            }
            scope_meta& current_scope()
            {
                if (m_scopes.empty()) { throw std::runtime_error("No scope set."); }
                return m_scopes.back();
            }
            bool push_using(const compilation_unit& cu, std::string name, std::string alias = "")
            {
                current_scope().push_using({ name, alias });
            }
            void pop_using()
            {
                current_scope().pop_using();
            }

            // Iterates over all available using_tuple's.
            // @param func The function to execute for each using.
            void iterate(std::function<void(std::string_view full_name, std::string_view alias)> func)
            {
                for (auto scope = m_scopes.rbegin(); scope != m_scopes.rend(); ++scope)
                {
                    for (auto using_ = scope->m_usings.begin(); using_ != scope->m_usings.end(); ++using_)
                    {
                        func(using_->full_name, using_->alias);
                    }
                }
            }
            // Pops the required amount of values from value stack and
            // emits the given operator to stack. May call operator methods if needed.
            // @param r The reporter to report messages to.
            // @param method_info_type The operator type to be emitted. Only Operator-Types are allowed!
            // @return True if the operation was successful, false if not (eg. type has that operator not implementation)
            bool emit_operator(can_report& r, enum leaf_method_info_type method_info_type);

            // Pops a value from stack and emits code to transform it into another type.
            // @param r The reporter to report messages to.
            // @param type_reference The type reference of the target type
            // @param type_ptr The type of the target type
            // @return True if the operation was successful, false if not (eg. type cannot be casted to given type)
            bool emit_cast(can_report& r, leaf_type_reference type_reference, leaf_type_ptr type_ptr);
        };
        using_helper_class helper;
        leaf::compilation::compilation_unit* m_cu;

        virtual bool visit_enter(std::shared_ptr<leaf::parsing::instance::namespace_> node) override;
        virtual bool visit_leave(std::shared_ptr<leaf::parsing::instance::namespace_> node) override;

        virtual bool visit_enter(std::shared_ptr<leaf::parsing::instance::class_> node) override;
        virtual bool visit_leave(std::shared_ptr<leaf::parsing::instance::class_> node) override;

        virtual bool visit_enter(std::shared_ptr<leaf::parsing::instance::property> node) override;
        virtual bool visit_leave(std::shared_ptr<leaf::parsing::instance::property> node) override;

        virtual bool visit_enter(std::shared_ptr<leaf::parsing::instance::method> node) override;
        virtual bool visit_leave(std::shared_ptr<leaf::parsing::instance::method> node) override;

        virtual bool visit_enter(std::shared_ptr<leaf::parsing::instance::field> node) override;
        virtual bool visit_leave(std::shared_ptr<leaf::parsing::instance::field> node) override;

        virtual bool visit_enter(std::shared_ptr<leaf::parsing::instance::pragma_disable> node) override;
        virtual bool visit_enter(std::shared_ptr<leaf::parsing::instance::pragma_enable> node) override;

        std::string get_ident(std::shared_ptr<leaf::parsing::instance::ident_navigation> data)
        {
            size_t first_end_index;
            return get_ident(data, first_end_index);
        }
        std::string get_ident(std::shared_ptr<leaf::parsing::instance::ident_navigation> data, size_t& first_end_index)
        {
            std::vector<std::string_view> local_stack;
            get_ident_recursive(local_stack, data);
            if (local_stack.empty()) { return {}; }

            size_t capacity = 0;
            for (auto view : local_stack)
            {
                view.length();
            }
            capacity += local_stack.size() - 1;
            std::string out;
            out.reserve(capacity);
            for (auto view : local_stack)
            {
                if (!out.empty())
                {
                    out.append(".");
                }
                else
                {
                    first_end_index = view.length();
                }
                out.append(view.begin(), view.end());
            }
            return out;
        }
        void get_ident_recursive(std::vector<std::string_view>& local_stack, std::shared_ptr<leaf::parsing::instance::ident_navigation> data);
        std::string name_from_nav_stack(int offset = 0)
        {
            if (offset > 0) { return {}; }
            if (-offset >= m_nav_stack.size()) { return {}; }
            if (m_nav_stack.empty()) { return {}; }

            size_t capacity = 0;
            for (auto it = m_nav_stack.begin(); it != offset + m_nav_stack.end(); ++it)
            {
                it->length();
            }
            capacity += m_nav_stack.size() - 1;
            std::string out;
            out.reserve(capacity);
            for (auto it = m_nav_stack.begin(); it != offset + m_nav_stack.end(); ++it)
            {
                if (!out.empty())
                {
                    out.append(".");
                }
                if (!out.empty())
                {
                    out.append(it->begin(), it->end());
                }
            }
            return out;
        }

        bool try_resolve_type_name(std::string type_ident,
            leaf_type_reference& out_type_reference,
            leaf_type_ptr& out_type_ptr);
        bool try_resolve_type_name(std::shared_ptr<leaf::parsing::instance::type_navigation> type_navigation,
            leaf_type_reference& out_type_reference,
            leaf_type_ptr& out_type_ptr);
        bool fill_type_reference(leaf_type_reference& ref, const std::shared_ptr<leaf::parsing::instance::type_match>& node);
        bool fill_type_reference_void(leaf_type_reference& ref);
        bool get_type_reference_index(leaf_type_ptr type, size_t& out_index);
        bool get_type_from_reference_index(size_t index, leaf_type_ptr& out_type);
    private:
        std::vector<std::string> m_nav_stack;
    };
}