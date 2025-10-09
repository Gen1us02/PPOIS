#include "display.h"
#include "../Exceptions/exceptions.h"

Display::Display() {
    port_ = PortType::DisplayPort;
};

Display::Display(const std::string &maxCamResolution, double megapixels, int max_fps,
                 const std::string &resolution, int refreshRate, int diagonal) : webcamera_(maxCamResolution,
        megapixels, max_fps),
    resolution_(resolution), refreshRate_(refreshRate), diagonal_(diagonal) {
    port_ = PortType::DisplayPort;
    webcamera_.Connect();
}

void Display::SetResolution(const std::string &resolution) {
    this->resolution_ = resolution;
}

std::string Display::GetResolution() const {
    return this->resolution_;
}

void Display::SetRefreshRate(int refreshRate) {
    this->refreshRate_ = refreshRate;
}

int Display::GetRefreshRate() const {
    return this->refreshRate_;
}

void Display::SetDiagonal(int diagonal) {
    this->diagonal_ = diagonal;
}

int Display::GetDiagonal() const {
    return this->diagonal_;
}

std::string Display::DisplaySettings() const {
    return "Display settings: \n"
           + std::string("Resolution: ") + this->resolution_ + "\n"
           + "Refresh rate: " + std::to_string(this->refreshRate_) + "\n"
           + "Display diagonal: " + std::to_string(this->diagonal_);
}

std::string Display::DisplayInput(const InputDevice &inputDevice) const {
    if (!(typeid(inputDevice) == typeid(KeyBoard) || typeid(inputDevice) == typeid(Mouse))) {
        throw ExceptionIncorrectInstance("Device is not keyboard or mouse");
    }
    return "User input:\n" + inputDevice.GetInput();
}

std::string Display::WebCameraVideo(int seconds) {
    return this->webcamera_.MakeVideo(seconds);
}

bool Display::SupportsPort(PortType p) const {
    return this->port_ == p || this->portHDMI_ == p;
}

void Display::ConnectCamera() {
    this->webcamera_.Connect();
    this->webcamera_.TurnOn();
}

void Display::DisconnectCamera() {
    this->webcamera_.Disconnect();
    this->webcamera_.TurnOff();
}

bool Display::IsCameraConnected() const {
    return this->webcamera_.IsConnected();
}
