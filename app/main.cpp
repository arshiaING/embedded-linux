
//hpp 
#include "FakeSensor.hpp"
#include "TimeUtils.hpp"
#include "CsvLogger.hpp"



//biblotek 
#include <chrono>
#include <iostream>
#include <thread>
#include <atomic>
#include <csignal>



const int sleepTime = 1; // seconds





std::atomic<bool> running{true};

void handleSignal(int) {
    running = false;
}







int main() {
    FakeSensor sensor;
    CsvLogger csvLogger("measurements.csv");
    std::signal(SIGINT, handleSignal);
    


    while (running) {
        const double temperature = sensor.readTemperature();
        const std::string timestamp = getCurrentTimeStamp();
        csvLogger.logData(timestamp, temperature);

        std::cout << getCurrentTimeStamp()
          << " - Fake Temperature: "
          << temperature
          << " C\n";

        std::this_thread::sleep_for(std::chrono::seconds(sleepTime));
    }
    std::cout << "Sensor stopped cleanly.\n";

return 0;
}