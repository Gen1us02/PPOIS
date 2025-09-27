#include "micin.h"

MicIn::MicIn() = default;

bool MicIn::ConnectDevice(const Microphone& microphone){
    if (this->microphone_.has_value()) return false;
    if (!CanAccept(microphone)) return false;
    this->microphone_.emplace(microphone);
    return true;
}

bool MicIn::DisconnectDevice(){
    if (!this->microphone_.has_value()) return false;
    this->microphone_.reset();
    return true;
}

bool MicIn::CanAccept(const Microphone& microphone) const{
    return microphone.SupportsPort(this->type_);
}

std::string MicIn::GetType() const{
    return ToString(this->type_);
}

bool MicIn::DetectMicriphone() const{
    return this->microphone_.has_value();
}