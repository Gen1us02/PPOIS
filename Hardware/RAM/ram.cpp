#include "ram.h"
#include "../Exceptions/exceptions.h"

RAM::RAM() = default;

RAM::RAM(int memory, const std::string &type, int frequency) : memory_(memory), type_(type), frequency_(frequency) {
}

void RAM::SetMemory(int memory) {
    this->memory_ = memory;
}

int RAM::GetMemory() const {
    return this->memory_;
}

void RAM::SetType(const std::string &type) {
    this->type_ = type;
}

std::string RAM::GetType() const {
    return this->type_;
}

void RAM::SetFrequency(int frequency) {
    this->frequency_ = frequency;
}

int RAM::GetFrequency() const {
    return this->frequency_;
}

void RAM::SetEnabled(bool enabled) {
    this->enabled_ = enabled;
}

bool RAM::IsEnabled() const {
    return this->enabled_;
}

std::string RAM::RamStatus() const {
    try {
        if (!this->enabled_) {
            throw ExceptionRAMStatusError("The computer turns off, the data is cleared");
        }
        return "RAM is working. Application data is collecting";
    } catch (const ExceptionRAMStatusError &ex) {
        return ex.what();
    }
}
