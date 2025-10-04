#include "usb.h"
#include "../Exceptions/exceptions.h"

USB::USB() = default;

bool USB::ConnectDevice(const Device& device){
    try{
        if (this->device_.has_value()){
            throw ExceptionIsOccupiedError("Порт занят");
        }
        if (!CanAccept(device)) return false;
        this->device_.emplace(device);
        return true;
    }
    catch (const ExceptionIsOccupiedError& ex){
        std::cout << ex.what();
        return false;
    }
}

bool USB::DisconnectDevice(){
    try{
        if (!this->device_.has_value()) {
            throw ExceptionNotIsOccupiedError("Порт свободен");
        }
        this->device_.reset();
        return true;
    }
    catch (const ExceptionNotIsOccupiedError& ex){
        std::cout << ex.what();
        return false;
    }
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