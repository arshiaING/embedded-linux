#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>

int main() {

    for (int i = 0; i < 5; ++i) {
        //fake temp verdi fra 0 til 20 c
        std::cout << rand() % 21 << "C" << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

 return 0;

}