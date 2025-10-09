#include "power_supply.h"
#include "../Exceptions/exceptions.h"

PowerSupply::PowerSupply() = default;

PowerSupply::PowerSupply(int minSpeed, int maxSpeed, int power, int efficiency, int minVoltage,
                         int maxVoltage) : power_(power), efficiency_(efficiency), minVoltage_(minVoltage),
                                           maxVoltage_(maxVoltage), cooler_(minSpeed, maxSpeed) {
}

void PowerSupply::SetPower(int power) {
    this->power_ = power;
}

int PowerSupply::GetPower() const {
    return this->power_;
}

void PowerSupply::SetEfficiency(int efficiency) {
    this->efficiency_ = efficiency;
}

int PowerSupply::GetEfficiency() const {
    return this->efficiency_;
}

void PowerSupply::SetMinVoltage(int minVoltage) {
    this->minVoltage_ = minVoltage;
}

int PowerSupply::GetMinVoltage() const {
    return this->minVoltage_;
}

void PowerSupply::SetMaxVoltage(int maxVoltage) {
    this->maxVoltage_ = maxVoltage;
}

int PowerSupply::GetMaxVoltage() const {
    return this->maxVoltage_;
}

std::string PowerSupply::SetCoolerCurrentSpeed(int speed) const {
    try {
        return this->cooler_.SetCurrentSpeed(speed);
    } catch (const ExceptionIncorrectSpeed &ex) {
        return ex.what();
    }
}

bool PowerSupply::VoltageSupply(int voltage) const {
    return voltage >= this->minVoltage_ && voltage <= this->maxVoltage_;
}

std::string PowerSupply::VoltageSupplyMessage(int voltage) const {
    if (!VoltageSupply(voltage)) {
        throw ExceptionIncorrectVoltage("The power supply is broken.");
    }
    return "The power supply is connected to the mains with voltage " + std::to_string(voltage);
}
