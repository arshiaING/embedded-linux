#include "FakeSensor.hpp"

#include <cstdlib>

int readFakeTemperature() {
    return std::rand() % 21;
}