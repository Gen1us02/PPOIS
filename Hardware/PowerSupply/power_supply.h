#ifndef POWERSUPPLY
#define POWERSUPPLY
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
    std::string VoltageSupplyMessage(int) const;
private:
    bool VoltageSupply(int) const;
    int power_ {0};
    int efficiency_ {0};
    int minVoltage_ {0};
    int maxVoltage_ {0};
    PowerSupplyCooler cooler_;
};


#endif