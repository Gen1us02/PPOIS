#ifndef CPUDEVICE
#define CPUDEVICE
#include <iostream>
#include <string>
#include "hardware.h"

class CPU: public Hardware{
public:
    CPU();
    CPU(const std::string&, int, int, double, double);
    void SetSocketType(const std::string&);
    std::string GetSocketType() const;
    void SetCoreCount(int);
    int GetCoreCount() const;
    void SetMaxTreadCount(int);
    int GetMaxTreadCount() const;
    void SetBaseFrequency(double);
    double GetBaseFrequency() const;
    void SetMaxFrequency(double);
    double GetMaxFrequency() const;
    std::string SetTurboMode(bool) const;
private:
    std::string socketType_ {""};
    int coreCount_ {0};
    int maxThreadCount_ {0};
    double baseFrequency_ {0.0};
    double maxFrequency_ {0.0};
};

#endif