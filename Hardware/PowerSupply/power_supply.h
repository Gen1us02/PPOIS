#ifndef POWERSUPPLY
#define POWRSUPPLY
#include <string>
#include "hardware.h"
#include "power_supply_cooler.h"

class PowerSupply : public Hardware{
public:
    PowerSupply();
    PowerSupply(int, int, int, int, int);
    void SetPower(int);
    int GetPower() const;
    void SetEfficiency(int);
    int GetEfficiency() const;
    void SetCoolerCurrentSpeed(int);
    void SetMinVoltage(int);
    int GetMinVoltage() const;
    void SetMaxVoltage(int);
    int GetMaxVoltage() const;
    bool VoltageSupply(int) const;
    std::string VoltageSupplyMessage(int) const;
private:
    int power_ {0};
    int efficiency_ {0};
    int minVoltage_ {0};
    int maxVoltage_ {0};
    PowerSupplyCooler cooler_;
};


#endif