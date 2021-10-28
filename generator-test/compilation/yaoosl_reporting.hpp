#pragma once
#include <unordered_map>
#include <vector>
#include <string>
#include <string_view>

namespace leaf::compilation
{
    enum class eseverity
    {
        fatal,
        error,
        warning,
        info,
        verbose,
        trace,
        debug
    };
    struct message_base
    {
        std::string key;
        size_t line;
        size_t column;
        eseverity severity;
        std::string file;
        virtual std::string msg() const = 0;
    };
    struct can_report;
    class reporter
    {
        std::unordered_map<std::string, bool> m_message_enabled_map;
        std::unordered_map<eseverity, bool> m_severity_enabled_map;
        friend struct can_report;
    protected:
        virtual void do_report(message_base& msg) const = 0;
    public:

        void report(message_base& msg) const
        {
            // No empty keys
            if (msg.key.empty()) { return; }

            // Check we are reporting this individual message
            auto message_enabled = m_message_enabled_map.find(msg.key);
            if (message_enabled != m_message_enabled_map.end() && !message_enabled->second) { return; }

            // Check we are reporting this level
            auto severity_enabled = m_severity_enabled_map.find(msg.severity);
            if (severity_enabled != m_severity_enabled_map.end() && !severity_enabled->second
                && !(message_enabled != m_message_enabled_map.end() && message_enabled->second)) { return; }

            do_report(msg);
        }
    };
    struct can_report
    {
        can_report(reporter& r) : m_reporter(r) { }
        void report(message_base& msg) { m_reporter.report(msg); }
        void report(message_base&& msg) { m_reporter.report(msg); }


        void enable(std::string message_key) { m_reporter.m_message_enabled_map[message_key] = true; }
        void disable(std::string message_key) { m_reporter.m_message_enabled_map[message_key] = false; }

        void enable(std::string_view message_key) { std::string key(message_key.begin(), message_key.end()); m_reporter.m_message_enabled_map[key] = true; }
        void disable(std::string_view message_key) { std::string key(message_key.begin(), message_key.end()); m_reporter.m_message_enabled_map[key] = false; }

        void enable(eseverity severity) { m_reporter.m_severity_enabled_map[severity] = true; }
        void disable(eseverity severity) { m_reporter.m_severity_enabled_map[severity] = false; }
    private:
        reporter& m_reporter;
    };
}