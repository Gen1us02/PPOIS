#include "mouse.h"

Mouse::Mouse() : InputDevice() {
    port_ = PortType::USB;
}

Mouse::Mouse(int cursorX, int cursorY, const std::string &sensorType, int dpi) : cursorX_(cursorX), cursorY_(cursorY),
    sensorType_(sensorType), dpi_(dpi) {
    port_ = PortType::USB;
};

void Mouse::SetCursorX(int cursorX) {
    this->cursorX_ = cursorX;
}

int Mouse::GetCursorX() const {
    return this->cursorX_;
}

void Mouse::SetCursorY(int cursorY) {
    this->cursorY_ = cursorY;
}

int Mouse::GetCursorY() const {
    return this->cursorY_;
}

void Mouse::SetSensorType(const std::string &sensorType) {
    this->sensorType_ = sensorType;
}

std::string Mouse::GetSensorType() const {
    return this->sensorType_;
}

void Mouse::SetDpi(int dpi) {
    this->dpi_ = dpi;
}

int Mouse::GetDpi() const {
    return this->dpi_;
}

void Mouse::MoveCursor(int x, int y) {
    this->SetCursorX(x);
    this->SetCursorY(y);
    std::string coords = "x: " + std::to_string(this->cursorX_) + " y: " + std::to_string(this->cursorY_);
    ReadInput(coords);
}
