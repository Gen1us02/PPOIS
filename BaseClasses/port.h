#ifndef PORT
#define PORT
#include "device.h"

class Port{
    virtual ~Port() = default;
    virtual bool ConnectDevice(const Device&);
    virtual bool DisconnectDevice();
    virtual bool CanAccept(const Device&) const;
    virtual std::string GetType() const = 0;
};

#endif