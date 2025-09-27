#ifndef SSDDEVICE
#define SSDDEVICE
#include <string>
#include "memory_device.h"
#include "hardware.h"
#include "port_type.h"

class SSD : public MemoryDevice, public Hardware{
public:
    SSD();
    SSD(int, int, int, int);
    void SetMemorySize(int) override;
    int GetMemorySize() const override;
    void SetReadSpeed(int);
    int GetReadSpeed() const;
    void SetWriteSpeed(int);
    bool SupportsPort(PortType) const;
    int GetWriteSpeed() const;
    void SetTimeBeforeBreak(int);
    int GetTimeBeforeBreak() const;
    double ReadTime(int);
    double WriteTime(int);
private:
    int memorySize_ {0};
    int readSpeed_ {0};
    int writeSpeed_ {0};
    int timeBeforeBreak_ {0};
    PortType port_ {PortType::M2};
};


#endif