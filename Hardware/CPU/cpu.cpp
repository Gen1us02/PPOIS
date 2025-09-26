#include "cpu.h"

CPU::CPU() = default;

CPU::CPU(const std::string& socketType, int coreCount, int maxThreadCount, double baseFrequency, double maxFrequency):
socketType_(socketType), 
coreCount_(coreCount), 
maxThreadCount_(maxThreadCount), 
baseFrequency_(baseFrequency),
maxFrequency_(maxFrequency){}

void CPU::SetSocketType(const std::string& socketType){
    this->socketType_ = socketType;
}

std::string CPU::GetSocketType() const{
    return this->socketType_;
}

void CPU::SetCoreCount(int coreCount){
    this->coreCount_ = coreCount;
}

int CPU::GetCoreCount() const{
    return this->coreCount_;
}

void CPU::SetMaxTreadCount(int maxThreadCount){
    this->maxThreadCount_ = maxThreadCount;
}

int CPU::GetMaxTreadCount() const{
    return this->maxThreadCount_;
}

void CPU::SetBaseFrequency(double baseFrequency){
    this->baseFrequency_ = baseFrequency;
}

double CPU::GetBaseFrequency() const{
    return this->baseFrequency_;
}

void CPU::SetMaxFrequency(double maxFrequency){
    this->maxFrequency_ = maxFrequency;
}

double CPU::GetMaxFrequency() const{
    return this->maxFrequency_;
}

std::string CPU::SetTurboMode(bool mode) const{
    return mode ? "Процессор ускорен до максимальной частоты " + std::to_string(this->maxFrequency_) :
    "Процессор работает на базовой частоте " + std::to_string(this->baseFrequency_);
}