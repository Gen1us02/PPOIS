#ifndef ADAPTER
#define ADAPTER
#include <iostream>
#include <string>
#include "device.h"

class Adapter : public Device{
public:
    virtual ~Adapter() = default;
    virtual void SetConnectionInterface(const std::string&) = 0;
    virtual std::string GetConnectionInterface() const = 0;
    virtual void SetSpeed(int) = 0;
    virtual int GetSpeed() const = 0;
};

#endif