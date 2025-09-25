#ifndef IDEVICE
#define IDEVICE
#include <iostream>
#include <string>
#include "device.h"

class InputDevice: public Device{
public:
    void ReadInput(const std::string& input){
        this->input_ = input;
    };
    std::string GetInput() const{
        return this->input_;
    };
protected:
    std::string input_ {""};
};

#endif