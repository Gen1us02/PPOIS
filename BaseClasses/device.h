#ifndef DEVICE
#define DEVICE
#include <iostream>
#include <string>
#include "port_type.h"

class Device{
public:
    virtual ~Device() = default;
    virtual bool SupportsPort(PortType p) const{
    return this->port_ == p;
    }
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
    void TurnOn(){
        this->isPowered_ = true;
    }
    void TurnOff(){
        this->isPowered_ = false;
    }
protected:
    bool isConnected_ {false};
    bool isPowered_ {false};
    PortType port_ {PortType::None};
};

#endif