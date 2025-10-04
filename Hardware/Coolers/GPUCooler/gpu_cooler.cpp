#include "gpu_cooler.h"
#include "../Exceptions/exceptions.h"

GPUCooler::GPUCooler() = default;

GPUCooler::GPUCooler(int minSpeed, int maxSpeed):
minSpeed_(minSpeed), maxSpeed_(maxSpeed){}

void GPUCooler::SetMinSpeed(int minSpeed){
    this->minSpeed_ = minSpeed;
}

int GPUCooler::GetMinSpeed() const{
    return this->minSpeed_;
}

void GPUCooler::SetMaxSpeed(int maxSpeed){
    this->maxSpeed_ = maxSpeed;
}

int GPUCooler::GetMaxSpeed() const{
    return this->maxSpeed_;
}

std::string GPUCooler::GetType() const{
    return this->type_;
}

std::string GPUCooler::SetCurrentSpeed(int speed) const {
    try{
        if (speed < this->minSpeed_ || speed > this->maxSpeed_)
        {
            throw ExceptionIncorrectSpeed("Incorrect speed");
        }
        return "Cooler speed " + std::to_string(speed) + " rpm";
    }
    catch(const ExceptionIncorrectSpeed& ex){
        return ex.what();
    }
        
}