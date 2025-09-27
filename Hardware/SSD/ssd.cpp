#include "ssd.h"
#include <cmath>

SSD::SSD() = default;

SSD::SSD(int memorySize, int readSpeed, int writeSpeed, int timeBeforeBreak):
memorySize_(memorySize), readSpeed_(readSpeed), writeSpeed_(writeSpeed), timeBeforeBreak_(timeBeforeBreak){}

void SSD::SetMemorySize(int memorySize){
    this->memorySize_ = memorySize;
}

int SSD::GetMemorySize() const{
    return this->memorySize_;
}

void SSD::SetReadSpeed(int readSpeed){
    this->readSpeed_ = readSpeed;
}

int SSD::GetReadSpeed() const {
    return this->readSpeed_;
}

void SSD::SetWriteSpeed(int writeSpeed){
    this->writeSpeed_ = writeSpeed;
}

int SSD::GetWriteSpeed() const{
    return this->writeSpeed_;
}

void SSD::SetTimeBeforeBreak(int timeBeforeBreak){
    this->timeBeforeBreak_ = timeBeforeBreak;
}

int SSD::GetTimeBeforeBreak() const{
    return this->timeBeforeBreak_;
}

double SSD::ReadTime(int dataSize){
    double readTime = static_cast<double>(dataSize) / this->readSpeed_;
    return std::round(readTime * 100.0) / 100.0;
}

double SSD::WriteTime(int dataSize){
    double writeTime = static_cast<double>(dataSize) / this->writeSpeed_;
    return std::round(writeTime * 100.0) / 100.0;
}

bool SSD::SupportsPort(PortType p) const{
    return this->port_ == p;
}