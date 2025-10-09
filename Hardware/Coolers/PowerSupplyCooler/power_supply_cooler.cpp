#include "power_supply_cooler.h"
#include "../Exceptions/exceptions.h"

PowerSupplyCooler::PowerSupplyCooler() = default;

PowerSupplyCooler::PowerSupplyCooler(int minSpeed, int maxSpeed) : minSpeed_(minSpeed), maxSpeed_(maxSpeed) {
}

void PowerSupplyCooler::SetMinSpeed(int minSpeed) {
    this->minSpeed_ = minSpeed;
}

int PowerSupplyCooler::GetMinSpeed() const {
    return this->minSpeed_;
}

void PowerSupplyCooler::SetMaxSpeed(int maxSpeed) {
    this->maxSpeed_ = maxSpeed;
}

int PowerSupplyCooler::GetMaxSpeed() const {
    return this->maxSpeed_;
}

std::string PowerSupplyCooler::GetType() const {
    return this->type_;
}

std::string PowerSupplyCooler::SetCurrentSpeed(int speed) const {
    if (speed < this->minSpeed_ || speed > this->maxSpeed_) {
        throw ExceptionIncorrectSpeed("Incorrect speed");
    }
    return "Cooler speed " + std::to_string(speed) + " rpm";
}
