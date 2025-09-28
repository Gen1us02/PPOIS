#include "micin.h"
#include "exceptions.h"

MicIn::MicIn() = default;

bool MicIn::ConnectDevice(const Microphone& microphone){
    try{
        if (this->microphone_.has_value()){
            throw ExceptionIsOccupiedError("Порт занят");
        }
        if (!CanAccept(microphone)) return false;
        this->microphone_.emplace(microphone);
        return true;
    }
    catch (const ExceptionIsOccupiedError& ex){
        std::cout << ex.what();
        return false;
    }
}

bool MicIn::DisconnectDevice(){
    try{
        if (!this->microphone_.has_value()) {
            throw ExceptionNotIsOccupiedError("Порт свободен");
        }
        this->microphone_.reset();
        return true;
    }
    catch (const ExceptionNotIsOccupiedError& ex){
        std::cout << ex.what();
        return false;
    }
}

bool MicIn::IsOccupied() const{
    return this->microphone_.has_value();
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