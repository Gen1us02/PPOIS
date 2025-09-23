#include "speakers.h"

Speakers::Speakers() = default;

Speakers::Speakers(int dynamicCount, int power, double weight, int maxRate):
_dynamicCount(dynamicCount), _power(power), _weight(weight), _maxRate(maxRate){}

void Speakers::setDynamicCount(int dynamicCount){
    this->_dynamicCount = dynamicCount;
}

int Speakers::getDynamicCount() const{
    return this->_dynamicCount;
}

void Speakers::setPower(int power){
    this->_power = power;
}

int Speakers::getPower() const{
    return this->_power;
}

void Speakers::setWeight(double weight){
    this->_weight = weight;
}

double Speakers::getWeight() const{
    return this->_weight;
}

void Speakers::setMaxRate(int maxRate){
    this->_maxRate = maxRate;
}

int Speakers::getMaxRate() const{
    return this->_maxRate;
}

std::string Speakers::displayInput(const Input_Device& microphone) const{
    // Проверка на микрофон
    return "Звук от пользователя:\n" + microphone.getInput();
}

std::string Speakers::changeVolume(int volumeValue) const{
    // Проверка на валидность звука
    return "Значение звука изменено на " + std::to_string(volumeValue);
}