#ifndef GPUCOOLER
#define GPUCOOLER
#include "cooler.h"
#include "hardware.h"

class GPUCooler:public Cooler, public Hardware{
public:
    GPUCooler();
    GPUCooler(int, int);
    void SetMinSpeed(int) override;
    int GetMinSpeed() const override;
    void SetMaxSpeed(int) override;
    int GetMaxSpeed() const override;
    std::string GetType() const override;
private:
    int minSpeed_ {0};
    int maxSpeed_ {0};
    std::string type_ {"gpu"};
};

#endif