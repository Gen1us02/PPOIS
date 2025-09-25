#ifndef CPUCOOLER
#define CPUCOOLER
#include "cooler.h"
#include "hardware.h"

class CPUCooler:public Cooler, public Hardware{
public:
    CPUCooler();
    CPUCooler(int, int, const std::string&);
    void SetMinSpeed(int) override;
    int GetMinSpeed() const override;
    void SetMaxSpeed(int) override;
    int GetMaxSpeed() const override;
    void SetSocket(const std::string&);
    std::string GetSocket() const;
private:
    int minSpeed_ {0};
    int maxSpeed_ {0};
    std::string socket_ {""};
};

#endif