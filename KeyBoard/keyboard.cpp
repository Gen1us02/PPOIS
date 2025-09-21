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

void KeyBoard::Connect(){
    this->_is_connected = true;
}

void KeyBoard::Disconnect(){
    this->_is_connected = false;
}

bool KeyBoard::IsConnected() const{
    return this->_is_connected;
}

void KeyBoard::ReadInput(const std::string& user_input){
    this->_user_input = user_input;
}