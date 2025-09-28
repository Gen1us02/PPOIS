#include "ram.h"
#include "exceptions.h"

RAM::RAM() = default;

RAM::RAM(int moduleCount, int memory, const std::string& type, int frequency):
moduleCount_(moduleCount), memory_(memory), type_(type), frequency_(frequency){}

void RAM::SetModuleCount(int moduleCount){
    this->moduleCount_ = moduleCount;
}

int RAM::GetModuleCount() const{
    return this->moduleCount_;
}

void RAM::SetMemory(int memory){
    this->memory_ = memory;
}

int RAM::GetMemory() const{
    return this->memory_;
}

void RAM::SetType(const std::string& type){
    this->type_ = type;
}

std::string RAM::GetType() const{
    return this->type_;
}

void RAM::SetFrequency(int frequency){
    this->frequency_ = frequency;
}

int RAM::GetFrequency() const{
    return this->frequency_;
}

void RAM::SetEnabled(bool enabled){
    this->enabled_ = enabled;
}

bool RAM::IsEnabled() const{
    return this->enabled_;
}

std::string RAM::RamStatus() const{
    try{
        if(!this->enabled_){
            throw ExceptionRAMStatusError("Компьютер выключается, данные очищаются");
        }
        return "Оперативная память работает. Данные о приложениях собираются";
    }
    catch (const ExceptionRAMStatusError& ex){
        return ex.what();
    }
}