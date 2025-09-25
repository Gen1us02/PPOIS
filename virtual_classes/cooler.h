#ifndef COOLER
#define COOLER
#include <iostream>
#include <string>

class Cooler{
public:
    virtual ~Cooler();
    virtual void SetMinSpeed(int) = 0;
    virtual int GetMinSpeed() const = 0;
    virtual void SetMaxSpeed(int) = 0;
    virtual int GetMaxSpeed() const = 0;
    std::string SetCurrentSpeed(int speed) const {
        //Проверка на минимальную максимальную скорость
        return "Скорость работы вентиляторов" + std::to_string(speed) + "об/мин"; 
    };
};

#endif