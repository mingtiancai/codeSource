#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <nlohmann/json.hpp>

namespace core
{
    class Config
    {
    public:
        explicit Config(std::string configFilePath);
        bool hasValue(std::string key);
        std::string getValue(std::string key);

    private:
        nlohmann::json configData;
    };
}

#endif