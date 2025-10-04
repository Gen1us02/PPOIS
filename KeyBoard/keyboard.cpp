#include "keyboard.h"
#include "../Exceptions/exceptions.h"

KeyBoard::KeyBoard(): InputDevice() {
    port_ = PortType::USB;
};

KeyBoard::KeyBoard(const std::string& type):
type_(type) {
    port_ = PortType::USB;
};

void KeyBoard::SetType(const std::string& type){
    this->type_ = type;
}

std::string KeyBoard::GetType() const{
    return this->type_;
}

std::string KeyBoard::PressButton(const std::string& key){
    try{
        if (key.size() != 1){
            throw ExceptionManyKeysPressed("Pressed a lot of buttons");
        }
        ReadInput(key);
        return "Button pressed " + key;
    }
    catch(const ExceptionManyKeysPressed& ex) {
        return ex.what();
    }
}