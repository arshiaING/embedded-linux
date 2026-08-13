
//hpp 
#include "FakeSensor.hpp"
#include "TimeUtils.hpp"

//biblotek 
#include <chrono>
#include <iostream>
#include <thread>
#include <atomic>
#include <csignal>



std::atomic<bool> running{true};

void handleSignal(int) {
    running = false;
}







int main() {
    FakeSensor sensor;
    std::signal(SIGINT, handleSignal);
    int SleepTime = 1; // seconds


    while (running) {
        const double temperature = sensor.readTemperature();

        std::cout << getCurrentTimeStamp()
          << " - Fake Temperature: "
          << temperature
          << " C\n";

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "Sensor stopped cleanly.\n";

return 0;
}