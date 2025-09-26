#ifndef POWERSUPPLYCOOLER
#define POWERSUPPLYCOOLER
#include "cooler.h"
#include "hardware.h"

class PowerSupplyCooler:public Cooler, public Hardware{
public:
    PowerSupplyCooler();
    PowerSupplyCooler(int, int);
    void SetMinSpeed(int) override;
    int GetMinSpeed() const override;
    void SetMaxSpeed(int) override;
    int GetMaxSpeed() const override;
    std::string GetType() const override;
private:
    int minSpeed_ {0};
    int maxSpeed_ {0};
    std::string type_ {"psu"};
};

#endif