#ifndef LOGGER_H
#define LOGGER_H

#include <spdlog/logger.h>

#include <ostream>
#include <string>

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
        class Level
        {
            using level_enum = spdlog::level::level_enum;

        public:
            Level(level_enum level = spdlog::level::trace);
            Level(const std::string &level);

            operator level_enum() const noexcept
            {
                return levelEnum;
            }
            operator const std::string &() const noexcept
            {
                return *levelStr;
            }

            friend bool operator ==(Level a, Level b) noexcept
            {
                return a.levelEnum == b.levelEnum;
            }
            friend bool operator !=(Level a, Level b) noexcept
            {
                return !(a == b);
            }
            friend std::ostream &operator <<(std::ostream &os, Level level)
            {
                return os << static_cast<const std::string &>(level);
            }

            static const Level trace;
            static const Level debug;
            static const Level info;
            static const Level warn;
            static const Level error;
            static const Level critical;

        private:
            Level(level_enum levelEnum, const std::string &levelStr) noexcept
                : levelEnum(levelEnum)
                , levelStr(&levelStr)
                {}

            level_enum levelEnum;
            const std::string *levelStr;

            static const std::string traceStr;
            static const std::string debugStr;
            static const std::string infoStr;
            static const std::string warnStr;
            static const std::string errorStr;
            static const std::string criticalStr;
        };

        spdlog::logger &get();

    } // namespace logger
} // namespace core

#endif
