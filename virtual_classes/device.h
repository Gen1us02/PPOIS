#ifndef DEVICE
#define DEVICE
#include <iostream>
#include <string>

class Device{
public:
    void Connect(){
        if(isConnected_) return;
        this->isConnected_ = true;
    };
    void Disconnect(){
        if(!isConnected_) return;
        this->isConnected_ = false;
    }
    bool IsConnected() const{
        return this->isConnected_;
    }
protected:
    bool isConnected_ {false};
};

#endif