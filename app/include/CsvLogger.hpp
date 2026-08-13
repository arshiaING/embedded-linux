# pragma once

# include <string>
#include <cstddef>


class CsvLogger {
public:
    explicit CsvLogger(const std::string& filename);

    void logData(const std::string& timestamp, double temperature);

   private:
    std::string filename_;
    static constexpr std::size_t maxMeasurements_ = 10;
    void keepLatestMeasurements();
};