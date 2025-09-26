#include "power_supply.h"

PowerSupply::PowerSupply() = default;

PowerSupply::PowerSupply(int minSpeed, int maxSpeed, int power, int efficiency, int maxVoltage):
power_(power), efficiency_(efficiency), maxVoltage_(maxVoltage), cooler_(minSpeed, maxSpeed){}

void PowerSupply::SetPower(int power){
    this->power_ = power;
}

int PowerSupply::GetPower() const{
    return this->power_;
}

void PowerSupply::SetEfficiency(int efficiency){
    this->efficiency_ = efficiency;
}

int PowerSupply::GetEfficiency() const{
    return this->efficiency_;
}

void PowerSupply::SetMaxVoltage(int maxVoltage){
    this->maxVoltage_ = maxVoltage;
}

int PowerSupply::GetMaxVoltage() const{
    return this->maxVoltage_;
}

void PowerSupply::SetCoolerCurrentSpeed(int speed){
    this->cooler_.SetCurrentSpeed(speed);
}

bool PowerSupply::VoltageSupply(int voltage) const{
    return voltage >= this->minVoltage_ && voltage <= this->maxVoltage_;
}

std::string PowerSupply::VoltageSupplyMessage(int voltage) const{
    return VoltageSupply(voltage) ?
    "Блок питания включен в сеть с напряжением " + std::to_string(voltage) 
    : "Блок питания сломался.";
}