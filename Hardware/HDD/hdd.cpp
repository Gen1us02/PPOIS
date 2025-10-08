#include "hdd.h"

HDD::HDD() = default;

HDD::HDD(int memorySize, int spindleSpeed, const std::string &recordTechnology) : memorySize_(memorySize),
    spindleSpeed_(spindleSpeed), recordTechnology_(recordTechnology) {
}

void HDD::SetMemorySize(int memorySize) {
    this->memorySize_ = memorySize;
}

int HDD::GetMemorySize() const {
    return this->memorySize_;
}

void HDD::SetSpindleSpeed(int spindleSpeed) {
    this->spindleSpeed_ = spindleSpeed;
}

int HDD::GetSpindleSpeed() const {
    return this->spindleSpeed_;
}

void HDD::SetRecordTechnology(const std::string &recordTechnology) {
    this->recordTechnology_ = recordTechnology;
}

std::string HDD::GetRecordTechnology() const {
    return this->recordTechnology_;
}
