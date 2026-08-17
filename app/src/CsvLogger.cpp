# include "CsvLogger.hpp"
# include "TimeUtils.hpp"
#include "Logger.hpp"

# include <fstream>
# include <iostream>
#include <filesystem>
#include <cstdint>
#include <vector>

CsvLogger::CsvLogger(
    const std::string& filename,
    std::size_t maxMeasurements
)
    : filename_(filename),
      maxMeasurements_(maxMeasurements) {
}

void CsvLogger::logData(const std::string& timestamp, double temperature) {
   {


    std::ofstream file(filename_, std::ios::app);
    if (!file.is_open()) {
        Logger::Error("Kan ikke åpne CSV-filen: " + filename_);
        return;
    }
    if (file.tellp() == 0) {
        file << "Timestamp,Temperature\n";
    }

    file << timestamp << "," << temperature << "\n";
}
     keepLatestMeasurements();
}


void CsvLogger::keepLatestMeasurements() {
    std::ifstream file(filename_);
    if (!file.is_open()) {
        Logger::Error("Kan ikke åpne filen: " + filename_);
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
        Logger::Error("Kan ikke åpne filen for skriving: " + filename_);
        return;
    }
    outputFile << header << "\n";

    const std::size_t firstToKeep =
        mesurements.size() - maxMeasurements_;

    for (std::size_t i = firstToKeep; i < mesurements.size(); ++i) {
        outputFile << mesurements[i] << "\n";



}}