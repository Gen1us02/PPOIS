#include <keyboard.h>

KeyBoard::KeyBoard() = default;

KeyBoard::KeyBoard(const std::string& type):
type_(type) {};

void KeyBoard::SetType(const std::string& type){
    this->type_ = type;
}

std::string KeyBoard::GetType() const{
    return this->type_;
}

std::string KeyBoard::PressButton(const std::string& key){
    ReadInput(key);
    return "Нажата кнопка " + key; 
}