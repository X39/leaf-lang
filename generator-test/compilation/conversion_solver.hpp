#pragma once
#include <map>
#include <vector>
#include <tuple>
#include <shared_mutex>
#include <algorithm>
#include "../runtime/leaf_type.h"
namespace leaf::compilation
{
    class conversion_solver
    {
    public:
        enum class solve_result
        {
            // Solving for the type chain worked.
            ok,
            // The type conversion requested is not existing.
            not_found,
            // There is more then one conversion path available.
            multiple_paths_possible,
        };
    private:
        enum class solve_result_internal
        {
            // Solving for the type chain worked.
            ok,
            // The type conversion requested is not existing.
            not_found,
            // There is more then one conversion path available.
            multiple_paths_possible,
            // The type conversion requested is not existing.
            dead_end,
            // The type was already visited in another path.
            already_visited,
        };
        struct scope
        {
            struct tuple
            {
                solve_result result;
                std::vector<leaf_method_info_ptr> data;
            };
            std::map<leaf_type_ptr, std::vector<std::tuple<leaf_type_ptr, leaf_method_info_ptr>>> conversions;
            std::map<std::tuple<leaf_type_ptr, leaf_type_ptr>, tuple> cache;
            size_t index;
        };
        std::vector<scope> m_scopes;
        std::shared_mutex m_mutex;


        solve_result_internal solve_conversion(
                leaf_type_ptr from,
                leaf_type_ptr to,
                size_t depths,
                std::vector<leaf_type_ptr>& visited,
                std::vector<leaf_method_info_ptr>& chain,
                size_t& scope_index)
        {
            if (from == to) { return solve_result_internal::ok; }
            if (depths == 0) { return has_conversion(from, visited) ? solve_result_internal::not_found : solve_result_internal::dead_end; }
            if (std::find(visited.begin(), visited.end(), from) != visited.end()) { return solve_result_internal::already_visited; }

            visited.push_back(from);
            for (auto rit = m_scopes.rbegin(); rit != m_scopes.rend(); ++rit)
            {
                auto& scope = *rit;
                if (scope.conversions.contains(from))
                {
                    auto& it = scope.conversions.at(from);
                    bool found = false;
                    for (auto& tuple : it)
                    {
                        auto res = solve_conversion(
                                std::get<leaf_type_ptr>(tuple),
                                to,
                                depths - 1,
                                visited,
                                chain,
                                scope_index);
                        if (res == solve_result_internal::multiple_paths_possible) { return res; }
                        else if (res == solve_result_internal::ok && !found)
                        {
                            chain.push_back(std::get<leaf_method_info_ptr>(tuple));
                            found = true;
                        }
                        else if (res == solve_result_internal::ok && found) { return solve_result_internal::multiple_paths_possible; }
                    }
                    if (found)
                    {
                        scope_index = scope.index;
                        return solve_result_internal::ok;
                    }
                }
            }
            return has_conversion(from, visited) ? solve_result_internal::not_found : solve_result_internal::dead_end;
        }
    public:
        conversion_solver()
        {
        }

        void register_conversion(leaf_type_ptr from, leaf_type_ptr to, leaf_method_info_ptr conversion_method)
        {
            auto tuple = std::make_tuple(to, conversion_method);
            std::unique_lock l(m_mutex);
            m_scopes.back().conversions[from].push_back(tuple);
        }

        bool has_conversion(leaf_type_ptr type_ptr)
        {
            // Check if the given type has any conversions bound at all
            std::shared_lock sl(m_mutex);
            auto find_res = std::find(m_scopes.rbegin(), m_scopes.rend(),
                    [&](auto&& scope){ return scope.conversions.contains(type_ptr); });
            return find_res != m_scopes.rend();
        }
        bool has_conversion(leaf_type_ptr type_ptr, const std::vector<leaf_type_ptr>& except)
        {
            // Check if the given type has any conversions bound at all
            std::shared_lock sl(m_mutex);
            auto find_res = std::find(m_scopes.rbegin(), m_scopes.rend(),
                    [&](auto&& scope) {
                return scope.conversions.contains(type_ptr)
                && std::find(except.begin(), except.end(), type_ptr) == except.end(); });
            return find_res != m_scopes.rend();
        }

        solve_result try_solve(leaf_type_ptr from, leaf_type_ptr to, std::vector<leaf_method_info_ptr>& chain)
        {
            // Ensure chain parameter is empty
            chain.clear();

            // Barrier for conversion to self
            if (from == to) { return solve_result::ok; }

            // Create cache key
            auto cache_key = std::make_tuple(from, to);

            // Try to find a cached version first
            {
                std::shared_lock sl(m_mutex);
                auto find_res = std::find(m_scopes.rbegin(), m_scopes.rend(),
                        [&](auto&& scope){ return scope.cache.contains(cache_key); });
                bool has_cache = find_res != m_scopes.rend();
                if (has_cache)
                {
                    auto& tmp = find_res->cache.at(cache_key);
                    if (tmp.result == solve_result::ok)
                    {
                        chain.insert(chain.end(), tmp.data.begin(), tmp.data.end());
                    }
                    return tmp.result;
                }
            }

            // Check if the given type has any conversions bound at all
            if (!has_conversion(from))
            {
                return solve_result::not_found;
            }

            // Solve the conversion
            {
                size_t depth = 0;
                size_t scope_index = 0;
                solve_result_internal result_internal = solve_result_internal::not_found;
                while (result_internal != solve_result_internal::dead_end && result_internal != solve_result_internal::ok && result_internal != solve_result_internal::multiple_paths_possible)
                {
                    std::shared_lock sl(m_mutex);
                    ++depth;
                    scope_index = 0;
                    std::vector<leaf_type_ptr> visited;
                    chain.clear();
                    result_internal = solve_conversion(from, to, depth, visited, chain, scope_index);
                }
                std::unique_lock ul(m_mutex);
                if (result_internal == solve_result_internal::ok)
                {
                    std::reverse(chain.begin(), chain.end());
                    m_scopes[scope_index].cache[cache_key] = { solve_result::ok, chain };
                    return solve_result::ok;
                }
                else if (result_internal == solve_result_internal::multiple_paths_possible)
                {
                    m_scopes[scope_index].cache[cache_key] = { solve_result::multiple_paths_possible, { } };
                    return  solve_result::multiple_paths_possible;
                }
                else
                {
                    m_scopes[scope_index].cache[cache_key] = { solve_result::not_found, { } };
                    return  solve_result::not_found;
                }
            }
        }




#pragma region Scoping
        void push_scope()
        {
            std::unique_lock ul(m_mutex);
            m_scopes.push_back({});
            m_scopes.back().index = m_scopes.size() - 1;
        }
        void pop_scope()
        {
            std::unique_lock ul(m_mutex);
            m_scopes.pop_back();
        }
        class conversion_scope_lock {
            conversion_solver& m_ref;
            friend class conversion_solver;
            explicit conversion_scope_lock(conversion_solver& ref) : m_ref(ref) {
                m_ref.push_scope();
            }

        public:
            ~conversion_scope_lock() {
                m_ref.pop_scope();
            }
        };

        conversion_scope_lock lock_scope() {
            return conversion_scope_lock(*this);
        }

#pragma endregion
    };
}