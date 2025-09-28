#ifndef SPEAKERS
#define SPEAKERS
#include <iostream>
#include <string>
#include "output_device.h"
#include "microphone.h"
#include "port_type.h"

class Speakers : public OutputDevice{
    public:
    Speakers();
    Speakers(int, int, double, int);
    void SetDynamicCount(int);
    int GetDynamicCount() const;
    void SetPower(int);
    int GetPower() const;
    void SetWeight(double);
    double GetWeight() const;
    void SetMaxRate(int);
    int GetMaxRate() const;
    std::string DisplayInput(const InputDevice&) const override;
    std::string ChangeVolume(int) const;
private:
    int dynamicCount_ {0};
    int power_ {0};
    double weight_ {0.0};
    int maxRate_ {0};
};

#endif