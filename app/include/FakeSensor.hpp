#pragma once 



class FakeSensor {
public:
    FakeSensor();

    double readTemperature();

private:
    double currentTemperature_;
};