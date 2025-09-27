#include "displayport.h"

DisplayPort::DisplayPort() = default;

bool DisplayPort::ConnectDevice(const Display& display){
    if (this->display_.has_value()) return false;
    if (!CanAccept(display)) return false;
    this->display_.emplace(display);
    return true;
}

bool DisplayPort::DisconnectDevice(){
    if (!this->display_.has_value()) return false;
    this->display_.reset();
    return true;
}

bool DisplayPort::CanAccept(const Display& display) const{
    return display.SupportsPort(this->type_);
}

std::string DisplayPort::GetType() const{
    return ToString(this->type_);
}

std::string DisplayPort::GetMaxResolution() const{
    if (!this->display_.has_value()) return "";
    return display_->GetResolution();
}