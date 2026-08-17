#pragma once

#include <cstddef>
#include <string>

struct Config {
    std::size_t maxMeasurements = 10;
    std::string sensorMode = "fake"; // viktig å endre at om feil skjer at den ikke automtisk går til fake 
    int sleepTime = 1;
    std::string csvFilename = "measurements.csv"; 
}; // bruker dette om config ini for feil tall kan den gå til defult 

Config loadConfig(const std::string& filePath);