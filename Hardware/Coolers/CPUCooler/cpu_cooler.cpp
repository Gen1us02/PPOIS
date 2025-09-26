#include "cpu_cooler.h"

CPUCooler::CPUCooler() = default;

CPUCooler::CPUCooler(int minSpeed, int maxSpeed, const std::string& socket):
minSpeed_(minSpeed), maxSpeed_(maxSpeed), socket_(socket){}

void CPUCooler::SetMinSpeed(int minSpeed){
    this->minSpeed_ = minSpeed;
}

int CPUCooler::GetMinSpeed() const{
    return this->minSpeed_;
}

void CPUCooler::SetMaxSpeed(int maxSpeed){
    this->maxSpeed_ = maxSpeed;
}

int CPUCooler::GetMaxSpeed() const{
    return this->maxSpeed_;
}

void CPUCooler::SetSocket(const std::string& socket){
    this->socket_ = socket;
}

std::string CPUCooler::GetSocket() const{
    return this->socket_;
}

std::string CPUCooler::GetType() const{
    return this->type_;
}