#include <keyboard.h>

KeyBoard::KeyBoard() = default;

KeyBoard::KeyBoard(const std::string& type):
_type(type) {};

void KeyBoard::set_type(const std::string& type){
    this->_type = type;
}

std::string KeyBoard::get_type() const{
    return this->_type;
}

std::string KeyBoard::pressButton(const std::string& key){
    readInput(key);
    return "Нажата кнопка " + key; 
}