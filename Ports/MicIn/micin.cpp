#include "micin.h"
#include "../Exceptions/exceptions.h"

MicIn::MicIn() = default;

bool MicIn::ConnectDevice(const Microphone &microphone) {
    if (this->microphone_.has_value()) {
        throw ExceptionIsOccupiedError("The port is busy");
    }
    if (!CanAccept(microphone)) return false;
    this->microphone_.emplace(microphone);
    return true;
}

bool MicIn::DisconnectDevice() {
    if (!this->microphone_.has_value()) {
        throw ExceptionNotIsOccupiedError("The port is free");
    }
    this->microphone_.reset();
    return true;
}

bool MicIn::IsOccupied() const {
    return this->microphone_.has_value();
}

bool MicIn::CanAccept(const Microphone &microphone) const {
    return microphone.SupportsPort(this->type_);
}

std::string MicIn::GetType() const {
    return ToString(this->type_);
}

std::string MicIn::DetectMicriphone() const {
    return this->microphone_.has_value() ? "Microphone detected" : "No microphone";
}
