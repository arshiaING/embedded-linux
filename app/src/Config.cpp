#include "Config.hpp"

#include "Logger.hpp"

#include <fstream>
#include <string>





std::string trim(const std::string& text) {
    const std::size_t first = text.find_first_not_of(" \t");

    if (first == std::string::npos) {
        return "";
    }

    const std::size_t last = text.find_last_not_of(" \t");

    return text.substr(first, last - first + 1);

}





Config loadConfig(const std::string& filePath) {
    Config config;

    std::ifstream file(filePath);



    if (!file.is_open()) {
        Logger::Warning("kunne ikke åpne konfigurasjonsfilen: " + filePath + ". Bruker standardverdier.");
        return config;
    } 
    
 
    
    
    
    std::string line;




    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#' || line[0] == '[') {
            continue;
        
        
        
        }

        const std::size_t equalsPosition = line.find('=');

        if (equalsPosition == std::string::npos) {
            continue;}

        const std::string key = trim(line.substr(0, equalsPosition));
        const std::string value = trim(line.substr(equalsPosition + 1));


        if (key == "csv_filename") { // bruker dette om config ini for feil tall kan den gå til defult burde i fremtiden se på ini bibloteket eller tomle eller yaml 

        if (!value.empty()) {
            config.csvFilename = value;} 


        else {

        Logger::Warning("CSV filename er tom");}}











        if (key == "sleeping_interval") {
    try {const int interval = std::stoi(value);

        if (interval > 0) {
            config.sleepTime = interval;} 
            else {
            Logger::Warning("Invalid time: " + value);
        }
    } catch (...) {
        Logger::Warning("Invalid time: " + value);
    }
}










if (key == "max_measurements") {
    try {
        const long long maximum = std::stoll(value);

        if (maximum > 0) {
            config.maxMeasurements =
                static_cast<std::size_t>(maximum);
        } else {
            Logger::Warning(
                "max_measurements må bli mer enn 0."
            );
        }
    } catch (...) {
        Logger::Warning(
            "Invalid max_measurements" + value
        );
    }
}


        







}return config;


}