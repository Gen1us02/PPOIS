#ifndef DEVICE
#define DEVICE
#include <iostream>
#include <string>

class Device{
public:
    void Connect(){
        if(_is_connected) return;
        this->_is_connected = true;
    };
    void Disconnect(){
        if(!_is_connected) return;
        this->_is_connected = false;
    }
    bool IsConnected() const{
        return this->_is_connected;
    }
protected:
    bool _is_connected {false};
};

#endif