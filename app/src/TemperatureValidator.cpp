#include "TemperatureValidator.hpp"

#include <cmath>

bool isTemperatureValid(
    double temperature,
    double minimum,
    double maximum
) {
    return std::isfinite(temperature)
        && temperature >= minimum
        && temperature <= maximum;
} // vil gi false om temperaturen er mer en minimum eller storre en maksimum eller om den er uendelig eller ikke et tall