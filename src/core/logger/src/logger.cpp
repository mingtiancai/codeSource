#include <iostream>
#include <chrono>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/daily_file_sink.h"

#include "logger.h"

namespace core
{
    Logger::Logger()
    {
        loggerLevelMap_ = {
            {"trance", spdlog::level::trace},
            {"debug", spdlog::level::debug},
            {"info", spdlog::level::info},
            {"warn", spdlog::level::warn},
            {"error", spdlog::level::err},
            {"critical", spdlog::level::critical}};

        try
        {
            std::chrono::seconds currentTime = std::chrono::duration_cast<std::chrono::seconds>(
                std::chrono::system_clock::now().time_since_epoch());

            std::string logFile = std::string("logs/") + std::to_string(currentTime.count()) + std::string(".log");

            logger_ = spdlog::daily_logger_mt("codeSource", logFile, 0, 0);
            logger_->set_pattern("[%D %H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
            logger_->set_level(spdlog::level::trace);
        }
        catch (const spdlog::spdlog_ex &ex)
        {
            std::cout << "Log init failed: " << ex.what() << std::endl;
            exit(1);
        }
    }
    void Logger::setLoggerLevel(std::string level)
    {
        if (loggerLevelMap_.find(level) != loggerLevelMap_.end())
        {
            logger_->set_level(loggerLevelMap_[level]);
            INFOLOG("change logger level to {}", level);
        }
    }
}
