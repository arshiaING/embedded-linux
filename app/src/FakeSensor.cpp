#include "FakeSensor.hpp"

#include <cstdlib>

// Kjører én gang når vi lager: FakeSensor sensor;
FakeSensor::FakeSensor()
    : currentTemperature_(10.0 + (std::rand() % 1001) / 100.0) {
} // 

// Kjører én gang per måling.
double FakeSensor::readTemperature() {
    const double change = (std::rand() % 41 - 20) / 100.0; // endring mellom -0.2 og +0.2 grader fra forrige måling

    currentTemperature_ += change;

    return currentTemperature_;
} 