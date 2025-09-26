#ifndef BATTERY
#define BATTERY
#include <string>

class Battery{
    virtual void SetVoltage(int);
    virtual int GetVoltage() const;
    virtual void SetType(const std::string&);
    virtual std::string GetType() const;
};


#endif