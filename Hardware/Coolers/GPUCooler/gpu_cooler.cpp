#include "gpu_cooler.h"

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