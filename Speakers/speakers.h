#ifndef SPEAKERS
#define SPEAKERS
#include <iostream>
#include <string>
#include "output_device.h"

class Speakers : public Output_Device{
    public:
    Speakers();
    Speakers(int, int, double, int);
    void setDynamicCount(int);
    int getDynamicCount() const;
    void setPower(int);
    int getPower() const;
    void setWeight(double);
    double getWeight() const;
    void setMaxRate(int);
    int getMaxRate() const;
    std::string DisplayInput(const InputDevice&)const override;
    std::string changeVolume(int) const;
private:
    int _dynamicCount {0};
    int _power {0};
    double _weight {0.0};
    int _maxRate {0};
};

#endif