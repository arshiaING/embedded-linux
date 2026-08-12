
// .hpp filer
# include "FakeSensor.hpp"
// vanlig include guards
#include <iostream>
#include <chrono>
#include <thread>

int main() {

   for (int i = 0; i < 5; i++) {

    int temperature = readFakeTemperature();
    std::cout << "Fake Temperature: " << temperature << "°C" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));



   }
   return 0;

}