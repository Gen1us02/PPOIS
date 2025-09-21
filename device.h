#ifndef IDEVICE
#define IDEVICE
#include <iostream>
#include <string>

class Device{
protected:
    bool _is_connected {false};
public:
    virtual void Connect() = 0;
    virtual void Disconnect() = 0;
    virtual bool IsConnected() const = 0;
};

#endif