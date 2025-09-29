#include "power_supply.h"
#include "exceptions.h"

PowerSupply::PowerSupply() = default;

PowerSupply::PowerSupply(int minSpeed, int maxSpeed, int power, int efficiency, int minVoltage, int maxVoltage):
power_(power), efficiency_(efficiency), minVoltage_(minVoltage), maxVoltage_(maxVoltage), cooler_(minSpeed, maxSpeed){}

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

void PowerSupply::SetMinVoltage(int minVoltage){
    this->minVoltage_ = minVoltage;
}

int PowerSupply::GetMinVoltage() const{
    return this->minVoltage_;
}

void PowerSupply::SetMaxVoltage(int maxVoltage){
    this->maxVoltage_ = maxVoltage;
}

int PowerSupply::GetMaxVoltage() const{
    return this->maxVoltage_;
}

std::string PowerSupply::SetCoolerCurrentSpeed(int speed){
    return this->cooler_.SetCurrentSpeed(speed);
}

bool PowerSupply::VoltageSupply(int voltage) const{
    return voltage >= this->minVoltage_ && voltage <= this->maxVoltage_;
}

std::string PowerSupply::VoltageSupplyMessage(int voltage) const{
    try{
        if (!VoltageSupply(voltage)){
            throw ExceptionIncorrectVoltage("Блок питания сломался.");
        }
        return "Блок питания включен в сеть с напряжением " + std::to_string(voltage);
    }
    catch (const ExceptionIncorrectVoltage& ex){
        return ex.what();
    }
}