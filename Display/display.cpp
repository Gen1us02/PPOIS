#include "display.h"

Display::Display() = default;

Display::Display(const std::string& max_cam_resolution, int megapixels, int max_fps,
    const std::string& resolution, int refreshRate, int diagonal): 
    webcamera_(max_cam_resolution, megapixels, max_fps),
    resolution_(resolution), refreshRate_(refreshRate), diagonal_(diagonal){
        port_ = PortType::DisplayPort;
    }

void Display::SetResolution(const std::string& resolution){
    this->resolution_ = resolution;
}

std::string Display::GetResolution() const{
    return this->resolution_;
}

void Display::SetRefreshRate(int refreshRate){
    this->refreshRate_ = refreshRate;
}

int Display::GetRefreshRate() const{
    return this->refreshRate_;
}

void Display::SetDiagonal(int diagonal){
    this->diagonal_ = diagonal;
}

int Display::GetDiagonal() const{
    return this->diagonal_;
}

std::string Display::DisplaySettings() const{
    return "Настройки монитора: \n" 
            + std::string("Разрешение: ") + this->resolution_ + "\n"
            + "Частота обновления экрана: " + std::to_string(this->refreshRate_) + "\n"
            + "Диагональ монитора: " + std::to_string(this->diagonal_);
}

std::string DisplayInput(const InputDevice& inputDevice){
    // Проверка на сущность клавиатуры или мыши
    return "Ввод пользователя:\n" + inputDevice.GetInput();
}

std::string Display::WebCameraVideo(int seconds){
    return this->webcamera_.MakeVideo(seconds);
}

bool Display::SupportsPort(PortType p) const{
    return this->port_ == p || this->portHDMI_ == p;
}