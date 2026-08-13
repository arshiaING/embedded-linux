# include "CsvLogger.hpp"
# include "TimeUtils.hpp"

# include <fstream>
# include <iostream>
#include <filesystem>
#include <cstdint>
#include <vector>

CsvLogger::CsvLogger(const std::string& filename)
    : filename_(filename) {
}

void CsvLogger::logData(const std::string& timestamp, double temperature) {
    keepLatestMeasurements();


    std::ofstream file(filename_, std::ios::app);
    if (!file.is_open()) {
        std::cerr << " kan ikke åpne filen " << filename_ << std::endl;
        return;
    }
    if (file.tellp() == 0) {
        file << "Timestamp,Temperature\n";
    }

    file << timestamp << "," << temperature << "\n";
}


void CsvLogger::keepLatestMeasurements() {
    std::ifstream file(filename_);
    if (!file.is_open()) {
        std::cerr << " kan ikke åpne filen " << filename_ << std::endl;
        return;
    }
    
    std::string header;
    std::getline(file, header);

    std::vector<std::string> mesurements;
    std::string line;


    while (std::getline(file, line)) {
        if (!line.empty()) {
            mesurements.push_back(line);
        }
}
    if (mesurements.size() <= maxMeasurements_) {
        return;
    }

    std::ofstream outputFile(filename_, std::ios::trunc);

    if (!outputFile.is_open()) {
        std::cerr << "Kan ikke skrive filen: " << filename_ << "\n";
        return;
    }
    outputFile << header << "\n";

    const std::size_t firstToKeep =
        mesurements.size() - maxMeasurements_;

    for (std::size_t i = firstToKeep; i < mesurements.size(); ++i) {
        outputFile << mesurements[i] << "\n";



}}