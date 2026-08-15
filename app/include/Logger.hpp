// brukt til å logge meldinger med forskjellige alvorlighetsnivåer


#pragma once

#include <string>


class Logger {
public:
    static void Normal(const std::string& message);
    static void Warning(const std::string& message);
    static void Error(const std::string& message);

private:
    static void log(const std::string& level, const std::string& message);
};