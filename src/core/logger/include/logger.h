#ifndef LOGGER_H
#define LOGGER_H

#include <memory>
#include <spdlog/logger.h>

#define SPDLOG_BASE(logger, level, ...) (logger)->log(spdlog::source_loc{__FILE__, __LINE__, __func__}, level, __VA_ARGS__)
#define TRACELOG(...) SPDLOG_BASE(core::Logger::getInstance()->logger(), spdlog::level::trace, __VA_ARGS__)
#define DEBUGLOG(...) SPDLOG_BASE(core::Logger::getInstance()->logger(), spdlog::level::debug, __VA_ARGS__)
#define INFOLOG(...) SPDLOG_BASE(core::Logger::getInstance()->logger(), spdlog::level::info, __VA_ARGS__)
#define WARNLOG(...) SPDLOG_BASE(core::Logger::getInstance()->logger(), spdlog::level::warn, __VA_ARGS__)
#define ERRORLOG(...) SPDLOG_BASE(core::Logger::getInstance()->logger(), spdlog::level::err, __VA_ARGS__)
#define CRITICALLOG(...) SPDLOG_BASE(core::Logger::getInstance()->logger(), spdlog::level::critical, __VA_ARGS__)

namespace core
{

    class Logger
    {
    public:
        Logger();

        static Logger *getInstance()
        {
            static Logger instance;
            return &instance;
        }

        Logger(const Logger &) = delete;
        Logger &operator=(const Logger &) = delete;

        auto logger()
        {
            return logger_;
        }

    private:
        std::shared_ptr<spdlog::logger> logger_;
    };
}

#endif