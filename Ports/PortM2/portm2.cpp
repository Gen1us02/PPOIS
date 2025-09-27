#include "portm2.h"

PortM2::PortM2() = default;

bool PortM2::ConnectDevice(const SSD& ssd){
    if (this->ssd_.has_value()) return false;
    if (!CanAccept(ssd)) return false;
    this->ssd_.emplace(ssd);
    return true;
}

bool PortM2::DisconnectDevice(){
    if (!this->ssd_.has_value()) return false;
    this->ssd_.reset();
    return true;
}

bool PortM2::CanAccept(const SSD& ssd) const{
    return ssd.SupportsPort(this->type_);
}

std::string PortM2::GetType() const{
    return ToString(this->type_);
}

int PortM2::GetSSDSize() const{
    if (!this->ssd_.has_value()) return 0;
    return ssd_->GetMemorySize();
}