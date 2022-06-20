#include "logger.h"

#include <chrono>
#include <format>
#include <iostream>
#include <unordered_map>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/daily_file_sink.h"

namespace core {
namespace logger {
namespace {
    std::shared_ptr<spdlog::logger> construct()
    {
        using namespace std::chrono;
        try
        {
            auto currentTime = duration_cast<seconds>(system_clock::now().time_since_epoch());
            auto logFile = std::format("logs/{}.log", currentTime.count());
            auto logger = spdlog::daily_logger_mt("codeSource", logFile, 0, 0);
            logger->set_pattern("[%D %H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
            logger->set_level(spdlog::level::trace);
            return logger;
        }
        catch (const spdlog::spdlog_ex &ex)
        {
            std::cerr << "Log init failed: " << ex.what() << std::endl;
            throw;
        }
    }
} // unnamed namespace

    spdlog::logger &get()
    {
        static std::shared_ptr<spdlog::logger> ptr = construct();
        return *ptr;
    }

    void setLevel(const std::string &level)
    {
        static const std::unordered_map<std::string, spdlog::level::level_enum> map = {
            { "trace", spdlog::level::trace },
            { "debug", spdlog::level::debug },
            { "info", spdlog::level::info },
            { "warn", spdlog::level::warn },
            { "error", spdlog::level::err },
            { "critical", spdlog::level::critical }
        };
        auto it = map.find(level);
        if (it != map.end())
        {
            get().set_level(it->second);
            INFOLOG("change logger level to {}", level);
        }
    }

} // namespace logger
} // namespace core
