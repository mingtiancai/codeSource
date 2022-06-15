#include <iostream>
#include <chrono>
#include <thread>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/sinks/daily_file_sink.h"

#include "logger.h"

namespace core
{
    Logger::Logger()
    {
        try
        {
            auto max_size = 1048576 * 5;
            auto max_files = 3;

            std::chrono::seconds currentTime = std::chrono::duration_cast<std::chrono::seconds>(
                std::chrono::system_clock::now().time_since_epoch());

            std::string logFile = std::string("logs/") + std::to_string(currentTime.count()) + std::string(".log");

            logger_ = spdlog::rotating_logger_mt("codeSource", logFile, max_size, max_files);
            logger_->set_pattern("[%D %H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
        }
        catch (const spdlog::spdlog_ex &ex)
        {
            std::cout << "Log init failed: " << ex.what() << std::endl;
        }
    }

    void Logger::run()
    {
        while (1)
        {
            logger_->set_level(spdlog::level::trace); // Set global log level to debug
            logger_->info("Welcome to spdlog!");
            logger_->error("Some error message with arg: {}", 1);

            logger_->warn("Easy padding in numbers like {:08d}", 12);
            logger_->critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
            logger_->info("Support for floats {:03.2f}", 1.23456);
            logger_->info("Positional args are {1} {0}..", "too", "supported");
            logger_->info("{:<30}", "left aligned");

            SPDLOG_TRACE("Some trace message with param {}", 42);
            SPDLOG_DEBUG("Some debug message");

            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
}
