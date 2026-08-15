
//hpp 
#include "FakeSensor.hpp"
#include "TimeUtils.hpp"
#include "CsvLogger.hpp"
#include "Logger.hpp"



//biblotek 
#include <chrono>
#include <iostream>
#include <thread>
#include <atomic>
#include <csignal>
#include <string>
#include <cstdlib>
#include <ctime>



const int sleepTime = 1; // seconds





std::atomic<bool> running{true};

void handleSignal(int) {
    running = false;
}







int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    FakeSensor sensor;
    CsvLogger csvLogger("measurements.csv");
    Logger::Normal("Sensor daemon started.");
    std::signal(SIGINT, handleSignal);
    


    while (running) {
       
        const double temperature = sensor.readTemperature();
        const std::string timestamp = getCurrentTimeStamp();
        csvLogger.logData(timestamp, temperature);

        Logger::Normal("Fake temperature: " + std::to_string(temperature) + " C");

        std::this_thread::sleep_for(std::chrono::seconds(sleepTime));
    }
    Logger::Normal("Sensorstopped cleanly.");

return 0;
}