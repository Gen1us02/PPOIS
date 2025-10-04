#include "displayport.h"
#include "../Exceptions/exceptions.h"

DisplayPort::DisplayPort() = default;

bool DisplayPort::ConnectDevice(const Display& display){
    try{
        if (this->display_.has_value()){
            throw ExceptionIsOccupiedError("Порт занят");
        }
        if (!CanAccept(display)) return false;
        this->display_.emplace(display);
        return true;
    }
    catch (const ExceptionIsOccupiedError& ex){
        std::cout << ex.what();
        return false;
    }
}

bool DisplayPort::DisconnectDevice(){
    try{
        if (!this->display_.has_value()) {
            throw ExceptionNotIsOccupiedError("Порт свободен");
        }
        this->display_.reset();
        return true;
    }
    catch (const ExceptionNotIsOccupiedError& ex){
        std::cout << ex.what();
        return false;
    }
}

bool DisplayPort::CanAccept(const Display& display) const{
    return display.SupportsPort(this->type_);
}

std::string DisplayPort::GetType() const{
    return ToString(this->type_);
}

bool DisplayPort::IsOccupied() const{
    return this->display_.has_value();
}