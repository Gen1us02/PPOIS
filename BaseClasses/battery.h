#ifndef BATTERY
#define BATTERY
#include <string>

class Battery{
public:
    virtual ~Battery() = default;
    virtual void SetVoltage(int);
    virtual int GetVoltage() const;
    virtual void SetType(const std::string&);
    virtual std::string GetType() const;
};


#endif