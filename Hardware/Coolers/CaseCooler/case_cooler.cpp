#include "case_cooler.h"
#include "exceptions.h"

CaseCooler::CaseCooler() = default;

CaseCooler::CaseCooler(int minSpeed, int maxSpeed, const std::string& direction):
minSpeed_(minSpeed), maxSpeed_(maxSpeed), direction_(direction){}

void CaseCooler::SetMinSpeed(int minSpeed){
    this->minSpeed_ = minSpeed;
}

int CaseCooler::GetMinSpeed() const{
    return this->minSpeed_;
}

void CaseCooler::SetMaxSpeed(int maxSpeed){
    this->maxSpeed_ = maxSpeed;
}

int CaseCooler::GetMaxSpeed() const{
    return this->maxSpeed_;
}

void CaseCooler::SetDirection(const std::string& direction){
    this->direction_ = direction;
}

std::string CaseCooler::GetType() const{
    return this->type_;
}

std::string CaseCooler::GetDirection() const{
    return this->direction_;
}

std::string CaseCooler::SetCurrentSpeed(int speed) const {
    try{
        if (speed < this->minSpeed_ || speed > this->maxSpeed_)
        {
            throw ExceptionIncorrectSpeed("Невалидная скорость вентилятора");
        }
        return "Скорость работы вентиляторов" + std::to_string(speed) + "об/мин"; 
    }
    catch(const ExceptionIncorrectSpeed& ex){
        return ex.what();
    }
        
}