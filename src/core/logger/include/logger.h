#ifndef LOGGER_H
#define LOGGER_H

#include <string>

#include <spdlog/logger.h>

#define SPDLOG_BASE(logger, level, ...) (logger).log(::spdlog::source_loc{__FILE__, __LINE__, __func__}, level, __VA_ARGS__)
#define TRACELOG(...) SPDLOG_BASE(::core::logger::get(), ::spdlog::level::trace, __VA_ARGS__)
#define DEBUGLOG(...) SPDLOG_BASE(::core::logger::get(), ::spdlog::level::debug, __VA_ARGS__)
#define INFOLOG(...) SPDLOG_BASE(::core::logger::get(), ::spdlog::level::info, __VA_ARGS__)
#define WARNLOG(...) SPDLOG_BASE(::core::logger::get(), ::spdlog::level::warn, __VA_ARGS__)
#define ERRORLOG(...) SPDLOG_BASE(::core::logger::get(), ::spdlog::level::err, __VA_ARGS__)
#define CRITICALLOG(...) SPDLOG_BASE(::core::logger::get(), ::spdlog::level::critical, __VA_ARGS__)

namespace core
{
    namespace logger
    {

        spdlog::logger &get();
        void setLevel(const std::string &level);

    } // namespace logger
} // namespace core

#endif
