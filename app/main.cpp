
//hpp 
#include "FakeSensor.hpp"
#include "TimeUtils.hpp"
#include "CsvLogger.hpp"
#include "Logger.hpp"
#include "Config.hpp"
#include "TemperatureValidator.hpp"



//biblotek 
#include <chrono>
#include <iostream>
#include <thread>
#include <atomic>
#include <csignal>
#include <string>
#include <cstdlib>
#include <ctime>









std::atomic<bool> running{true};

void handleSignal(int) {
    running = false;
}







int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    Config config = loadConfig("config/config.ini");
    FakeSensor sensor;
    
    
    CsvLogger csvLogger(
    config.csvFilename,
    config.maxMeasurements);


    Logger::Normal("Sensor daemon started.");
    std::signal(SIGINT, handleSignal);
   
    


    while (running) {
       
        const double temperature = sensor.readTemperature();

        if (isTemperatureValid(temperature, config.minValidTemperature, config.maxValidTemperature)){
            const std::string timestamp = getCurrentTimeStamp();
            csvLogger.logData(timestamp, temperature);
            Logger::Normal("Fake temperature: " + std::to_string(temperature) + "C");
            
    
    
    } else {
            Logger::Warning("Invalid temperature: " + std::to_string(temperature) + "C");
        
        
        
        }



        std::this_thread::sleep_for(std::chrono::seconds(config.sleepTime));
    }
    Logger::Normal("Sensorstopped cleanly.");

return 0;
}
