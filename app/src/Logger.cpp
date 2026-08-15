#include "Logger.hpp"

#include "TimeUtils.hpp"

#include <iostream>


void Logger::Normal(const std::string& message) {
    log("NORMAL", message);
}

void Logger::Warning(const std::string& message) {
    log("WARNING", message);
}

void Logger::Error(const std::string& message) {
    log("ERROR", message);
}

void Logger::log(const std::string& level, const std::string& message) {
    const auto timestamp = getCurrentTimeStamp();
    std::cout << "[" << timestamp << "] " << level << ": " << message << std::endl;
}


// burde gi den faste verdier for året basert på tiden så om det blir - grader om sommeren vil den gi 