#include "logger.h"

#include <chrono>
#include <iostream>
#include <stdexcept>
#include <unordered_map>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/daily_file_sink.h"

namespace core
{
    namespace logger
    {
        namespace
        {
            std::shared_ptr<spdlog::logger> construct()
            {
                using namespace std::chrono;
                try
                {
                    auto currentTime = duration_cast<seconds>(system_clock::now().time_since_epoch());
                    std::string logFile = std::string("logs/") + std::to_string(currentTime.count()) + std::string(".log");
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

        Level::Level(level_enum level)
        {
            operator =(
                level == spdlog::level::trace ? trace :
                level == spdlog::level::debug ? debug :
                level == spdlog::level::info ? info :
                level == spdlog::level::warn ? warn :
                level == spdlog::level::err ? error :
                level == spdlog::level::critical ? critical :
                throw std::invalid_argument(
                    std::string("unrecognized spdlog::level::level_enum ") +
                    std::to_string(level))
            );
        }

        Level::Level(const std::string &level)
        {
            auto c = level.size() ? level[0] : '\0';
            operator =(
                c == 't' ? trace :
                c == 'd' ? debug :
                c == 'i' ? info :
                c == 'w' ? warn :
                c == 'e' ? error :
                c == 'c' ? critical :
                throw std::invalid_argument(
                    std::string("unrecognized core::logger::Level string '") +
                    level +
                    '\'')
            );
        }

        const std::string Level::traceStr("trace");
        const std::string Level::debugStr("debug");
        const std::string Level::infoStr("info");
        const std::string Level::warnStr("warn");
        const std::string Level::errorStr("error");
        const std::string Level::criticalStr("critical");

        const Level Level::trace(spdlog::level::trace, traceStr);
        const Level Level::debug(spdlog::level::debug, debugStr);
        const Level Level::info(spdlog::level::info, infoStr);
        const Level Level::warn(spdlog::level::warn, warnStr);
        const Level Level::error(spdlog::level::err, errorStr);
        const Level Level::critical(spdlog::level::critical, criticalStr);

        spdlog::logger &get()
        {
            static std::shared_ptr<spdlog::logger> ptr = construct();
            return *ptr;
        }

    } // namespace logger
} // namespace core
