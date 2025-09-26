#ifndef HDDDEVICE
#define HDDDEVICE
#include <string>
#include "memory_device.h"
#include "hardware.h"

class HDD : public MemoryDevice, public Hardware{
public:
    HDD();
    HDD(int, int, const std::string&);
    void SetMemorySize(int) override;
    int GetMemorySize() const override;
    void SetSpindleSpeed(int);
    int GetSpindleSpeed() const;
    void SetRecordTechnology(const std::string&);
    std::string GetRecordTechnology() const;
private:
    int memorySize_ {0};
    int spindleSpeed_ {0};
    std::string recordTechnology_ {""};
};


#endif