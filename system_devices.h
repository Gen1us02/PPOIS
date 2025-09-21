#ifndef SYSDEVICE
#define SYSDEVICE
#include <string>

class System_Device{
    virtual ~System_Device() = default;
    virtual bool IsConnected() const = 0;
    virtual void Connect() const = 0;
};


class GPU{};
class CPU{};
class MotherBoard{};
class SSD{};
class HDD{};
class PowerSuply{};
class RAM{};

#endif