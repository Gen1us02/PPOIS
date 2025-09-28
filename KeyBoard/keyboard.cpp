#include <keyboard.h>
#include "exceptions.h"

KeyBoard::KeyBoard() = default;

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
            throw ExceptionManyKeysPressed("Нажато слишком много клавиш");
        }
        ReadInput(key);
        return "Нажата кнопка " + key;
    }
    catch(const ExceptionManyKeysPressed& ex) {
        return ex.what();
    }
}