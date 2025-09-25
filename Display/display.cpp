#include "display.h"

Display::Display() = default;

Display::Display(const std::string& max_cam_resolution, int megapixels, int max_fps,
    const std::string& resolution, int refreshRate, int diagonal): 
    webcamera_(max_cam_resolution, megapixels, max_fps),
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

std::string Display::DisplaySettings() const{
    return "Настройки монитора: \n" 
            + std::string("Разрешение: ") + this->_resolution + "\n"
            + "Частота обновления экрана: " + std::to_string(this->_refreshRate) + "\n"
            + "Диагональ монитора: " + std::to_string(this->_diagonal);
}

std::string DisplayInput(const InputDevice& inputDevice){
    // Проверка на сущность клавиатуры или мыши
    return "Ввод пользователя:\n" + inputDevice.GetInput();
}

std::string Display::WebCameraVideo(int seconds){
    return this->webcamera_.MakeVideo(seconds);
}