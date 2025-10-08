#include "motherboard_battery.h"

MotherBoardBattery::MotherBoardBattery() = default;

MotherBoardBattery::MotherBoardBattery(int voltage, const std::string &type, int capacity) : voltage_(voltage),
    type_(type), capacity_(capacity) {
}

void MotherBoardBattery::SetVoltage(int voltage) {
    this->voltage_ = voltage;
}

int MotherBoardBattery::GetVoltage() const {
    return this->voltage_;
}

void MotherBoardBattery::SetType(const std::string &type) {
    this->type_ = type;
}

std::string MotherBoardBattery::GetType() const {
    return this->type_;
}

void MotherBoardBattery::SetCapacity(int capacity) {
    this->capacity_ = capacity;
}

int MotherBoardBattery::GetCapacity() const {
    return this->capacity_;
}

bool MotherBoardBattery::IsAlive() const {
    return this->capacity_ > 0;
}
