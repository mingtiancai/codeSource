#ifndef LOGGER_H
#define LOGGER_H

#include <memory>
#include <spdlog/logger.h>

namespace core
{
    class Logger
    {
    public:
        Logger();

        void run();

    private:
        std::shared_ptr<spdlog::logger> logger_;
    };
}

#endif