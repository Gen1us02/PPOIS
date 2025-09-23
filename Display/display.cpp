#include "display.h"

Display::Display() = default;

Display::Display(const std::string& resolution, int refreshRate, int diagonal):
_resolution(resolution), _refreshRate(refreshRate), _diagonal(diagonal){}

void Display::setResolution(const std::string& resolution){
    this->_resolution = resolution;
}

std::string Display::getResolution() const{
    return this->_resolution;
}

void Display::setRefreshRate(int refreshRate){
    this->_refreshRate = refreshRate;
}

int Display::getRefreshRate() const{
    return this->_refreshRate;
}

void Display::setDiagonal(int diagonal){
    this->_diagonal = diagonal;
}

int Display::getDiagonal() const{
    return this->_diagonal;
}

std::string Display::displaySettings() const{
    return "Настройки монитора: \n" 
            + std::string("Разрешение: ") + this->_resolution + "\n"
            + "Частота обновления экрана: " + std::to_string(this->_refreshRate) + "\n"
            + "Диагональ монитора: " + std::to_string(this->_diagonal);
}

std::string displayInput(const Input_Device& inputDevice){
    // Проверка на сущность камеры, клавиатуры или мыши
    return "Ввод пользователя:\n" + inputDevice.getInput();
}