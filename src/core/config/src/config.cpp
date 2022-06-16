#include <fstream>
#include <filesystem>
#include <iostream>

#include "config.h"

namespace core
{
    Config::Config(std::string configFilePath)
    {
        try
        {
            std::ifstream configFileStream(configFilePath);
            configData << configFileStream;
        }
        catch (std::exception &e)
        {
            std::cerr << "read config file failed!" << std::endl;
            std::cerr << e.what() << std::endl;
        }
    }

    bool Config::hasValue(std::string key)
    {
        if (!configData[key].is_null())
            return true;
        else
            return false;
    }

    std::string Config::getValue(std::string key)
    {
        return configData[key];
    }
}