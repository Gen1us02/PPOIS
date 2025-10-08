#include "hdmi.h"
#include "../Exceptions/exceptions.h"

HDMI::HDMI() = default;

bool HDMI::ConnectDevice(const Device &device) {
    try {
        if (this->device_.has_value()) {
            throw ExceptionIsOccupiedError("The port is busy");
        }
        if (!CanAccept(device)) return false;
        this->device_.emplace(device);
        return true;
    } catch (const ExceptionIsOccupiedError &ex) {
        std::cout << ex.what();
        return false;
    }
}

bool HDMI::DisconnectDevice() {
    try {
        if (!this->device_.has_value()) {
            throw ExceptionNotIsOccupiedError("The port is free");
        }
        this->device_.reset();
        return true;
    } catch (const ExceptionNotIsOccupiedError &ex) {
        std::cout << ex.what();
        return false;
    }
}

bool HDMI::IsOccupied() const {
    return this->device_.has_value();
}

bool HDMI::CanAccept(const Device &device) const {
    return device.SupportsPort(this->type_);
}

std::string HDMI::GetType() const {
    return ToString(this->type_);
}
