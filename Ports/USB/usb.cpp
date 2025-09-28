#include "usb.h"

USB::USB() = default;

bool USB::ConnectDevice(const Device& device){
    if (this->device_.has_value()) return false;
    if (!CanAccept(device)) return false;
    this->device_.emplace(device);
    return true;
}

bool USB::DisconnectDevice(){
    if (!this->device_.has_value()) return false;
    this->device_.reset();
    return true;
}

bool USB::IsOccupied() const{
    return this->device_.has_value();
}

bool USB::CanAccept(const Device& device) const{
    return device.SupportsPort(this->type_);
}

std::string USB::GetType() const{
    return ToString(this->type_);
}