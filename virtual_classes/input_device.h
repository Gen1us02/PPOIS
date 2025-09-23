#ifndef IDEVICE
#define IDEVICE
#include <iostream>
#include <string>
#include "device.h"

class Input_Device: public Device{
public:
    void readInput(const std::string& input){
        this->_input = input;
    };
    std::string getInput() const{
        return this->_input;
    };
protected:
    std::string _input {""};
};

#endif