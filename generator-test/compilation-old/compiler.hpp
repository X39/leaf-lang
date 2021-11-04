#pragma once
#include "leaf_reporting.hpp"
#include "../parser.hpp"
#include "leaf_library_wrapper.hpp"

#include <string>
#include <string_view>
#include <vector>
#include <memory>
#include <functional>

namespace leaf::compilation
{

    class compilation_unit;
    class compiler;
    struct compilation_stage
    {
        virtual ~compilation_stage() { }
        virtual bool execute(leaf::compilation::compilation_unit& c) = 0;
    };
    // ToDo: Somehow add a "library of libraries" in here to allow crossreferencing during compilation
    class compilation_unit : public can_report
    {
        using type_map = std::map<std::string, leaf_type>;
        std::vector<std::shared_ptr<compilation_stage>> m_compilation_stages;
        std::shared_ptr<leaf::parsing::instance::main> m_cst;
        std::shared_ptr<library_wrapper> m_library_in_compilation;
        library_collection& m_available_libraries;
        std::string_view m_contents;
        friend class compiler;
        size_t m_compilation_stage_index;
        bool m_redo_compilation_stage;
        class compiler* m_owner;

        // Executes the previously registered compilation stages in order as registered.
        // @return True if the compilation was successfull, false if not.
        bool execute()
        {
            if (m_compilation_stage_index >= m_compilation_stages.size()) { return true; }
            if (!m_compilation_stages[m_compilation_stage_index]->execute(*this)) { return false; }
            if (!m_redo_compilation_stage) { ++m_compilation_stage_index; }
            return true;
        }

    public:
        using constant_type = std::variant<bool, uint64_t, int64_t, double, std::string, leaf_type*>;
        compilation_unit(reporter& r, std::shared_ptr<leaf::parsing::instance::main> main, std::string_view contents, std::shared_ptr<library_wrapper> library_in_compilation, library_collection& available_libraries)
            : can_report(r),
            m_library_in_compilation(library_in_compilation),
            m_available_libraries(available_libraries),
            m_cst(main),
            m_contents(contents),
            m_compilation_stage_index(0),
            m_redo_compilation_stage(false)
        {
        }
        void rerun_stage() { m_redo_compilation_stage = true; }
        bool is_done() { return m_compilation_stage_index >= m_compilation_stages.size(); }

        std::string_view get(const leaf::parsing::instance::token& t) const { return m_contents.substr(t.offset, t.length); }
        constant_type get(const std::shared_ptr<leaf::parsing::instance::exp_constant>& node) const;

        library_wrapper& lib() { return *m_library_in_compilation; }
        const library_wrapper& lib() const { return *m_library_in_compilation; }
        library_collection& lib_collection() { return m_available_libraries; }
        const library_collection& lib_collection() const { return m_available_libraries; }

        std::shared_ptr<leaf::parsing::instance::main> cst() { return m_cst; }
        const std::shared_ptr<leaf::parsing::instance::main> cst() const { return m_cst; }

        using iterator = library_wrapper::iterator;
        iterator begin() { return m_library_in_compilation->begin(); }
        iterator end() { return m_library_in_compilation->end(); }
        using const_iterator = library_wrapper::const_iterator;
        const_iterator begin() const { return m_library_in_compilation->begin(); }
        const_iterator end() const { return m_library_in_compilation->end(); }

        // Allows to register an additional compilation stage.
        // Compilation stages are executed in order as registered.
        void register_compilation_stage(std::shared_ptr<compilation_stage> stage)
        {
            m_compilation_stages.push_back(stage);
        }
    };
    class compiler
    {
        std::vector<compilation_unit*> m_compilation_units;
        std::shared_ptr<library_wrapper> m_library_in_compilation;
        library_collection m_library_collection;
    public:
        // Initializes a new compiler class.
        // @param factory A factory that will create all compilation_units needed.
        //                Once the compilation_unit is created, compiler will own that compilation_unit and take care of deleting it!
        //                Will get called automatically by the compiler to yield all available compilation_units.
        //                Returning a nullptr instructs the compiler to stop to continue yielding and exit the constructor.
        compiler(
            std::function<compilation_unit*(compiler& c, std::shared_ptr<library_wrapper> library_in_compilation, library_collection& available_libraries)> factory)
            :
            m_library_in_compilation(std::make_shared<library_wrapper>(new leaf_library()))
        {
            m_library_collection.push_back(m_library_in_compilation);
            
            // Yield all compilation_units
            compilation_unit* cu;
            while (cu = factory(*this, m_library_in_compilation, m_library_collection))
            {
                m_compilation_units.push_back(cu);
            }
        }
        ~compiler()
        {
            for (auto cu : m_compilation_units)
            {
                delete cu;
            }
        }

        void append_library(leaf_library* ptr)
        {
            m_library_collection.push_back(std::make_shared<library_wrapper>(ptr));
        }

        bool execute()
        {
            bool done = false;
            while (!done)
            {
                bool rerun = false;
                for (auto& cu : m_compilation_units)
                {
                    cu->m_owner = this;
                    if (!cu->execute())
                    {
                        return false;
                    }
                    rerun |= cu->m_redo_compilation_stage;
                }
                while (rerun)
                {
                    rerun = false;
                    for (auto& cu : m_compilation_units)
                    {
                        cu->m_owner = this;
                        if (!cu->m_redo_compilation_stage) { continue; }
                        if (!cu->execute())
                        {
                            return false;
                        }
                        rerun |= cu->m_redo_compilation_stage;
                    }
                }
            }
            return true;
        }
    };
}