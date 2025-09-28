#ifndef RAMDEVICE
#define RAMDEVICE
#include <string>
#include "hardware.h"

class RAM : public Hardware{
public:
    RAM();
    RAM(int, int, const std::string&, int);
    void SetModuleCount(int);
    int GetModuleCount() const;
    void SetMemory(int);
    int GetMemory() const;
    void SetType(const std::string&);
    std::string GetType() const;
    void SetFrequency(int);
    int GetFrequency() const;
    void SetEnabled(bool);
    bool IsEnabled() const;
    std::string RamStatus() const;
private:
    int moduleCount_ {0};
    int memory_ {0};
    std::string type_ {0};
    int frequency_ {0};
    bool enabled_ {false};
};


#endif