// lagrer målinger i en CSV-fil

# pragma once

# include <string>
#include <cstddef>


class CsvLogger {
public:
    CsvLogger(
    const std::string& filename,
    std::size_t maxMeasurements
);

    void logData(const std::string& timestamp, double temperature);

   private:
    std::string filename_;
    std::size_t maxMeasurements_;
    void keepLatestMeasurements();
};