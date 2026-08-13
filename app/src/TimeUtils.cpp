# include "TimeUtils.hpp"



# include <chrono>
# include <iomanip>
# include <sstream>
#include <ctime>


// funksjon for å hente nåværende tid
std::string getCurrentTimeStamp() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm = *std::localtime(&now_time_t);

    std::ostringstream timestamp;
    timestamp << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S");
    
    return timestamp.str();
}