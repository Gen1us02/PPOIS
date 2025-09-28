#include "hdmi.h"

HDMI::HDMI() = default;

bool HDMI::ConnectDevice(const Device& device){
    if (this->device_.has_value()) return false;
    if (!CanAccept(device)) return false;
    this->device_.emplace(device);
    return true;
}

bool HDMI::DisconnectDevice(){
    if (!this->device_.has_value()) return false;
    this->device_.reset();
    return true;
}

bool HDMI::IsOccupied() const{
    return this->device_.has_value();
}

bool HDMI::CanAccept(const Device& device) const{
    return device.SupportsPort(this->type_);
}

std::string HDMI::GetType() const{
    return ToString(this->type_);
}