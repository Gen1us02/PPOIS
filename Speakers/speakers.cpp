#include "speakers.h"

Speakers::Speakers() = default;

Speakers::Speakers(int dynamicCount, int power, double weight, int maxRate):
dynamicCount_(dynamicCount), power_(power), weight_(weight), maxRate_(maxRate){}

void Speakers::SetDynamicCount(int dynamicCount){
    this->dynamicCount_ = dynamicCount;
}

int Speakers::GetDynamicCount() const{
    return this->dynamicCount_;
}

void Speakers::SetPower(int power){
    this->power_ = power;
}

int Speakers::GetPower() const{
    return this->power_;
}

void Speakers::SetWeight(double weight){
    this->weight_ = weight;
}

double Speakers::GetWeight() const{
    return this->weight_;
}

void Speakers::SetMaxRate(int maxRate){
    this->maxRate_ = maxRate;
}

int Speakers::GetMaxRate() const{
    return this->maxRate_;
}

std::string Speakers::DisplayInput(const InputDevice& microphone) const{
    // Проверка на микрофон
    return "Звук от пользователя:\n" + microphone.GetInput();
}

std::string Speakers::ChangeVolume(int volumeValue) const{
    // Проверка на валидность звука
    return "Значение звука изменено на " + std::to_string(volumeValue);
}
 
bool Speakers::SupportsPort(PortType p) const{
    return this->port_ == p;
}