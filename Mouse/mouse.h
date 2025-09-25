#ifndef MOUSE
#define MOUSE
#include "input_device.h"

class Mouse:public InputDevice{
public:
    Mouse();
    Mouse(int, int, const std::string&, int);
    void SetCursorX(int);
    int GetCursorX() const;
    void SetCursorY(int);
    int GetCursorY() const;
    void SetSensorType(const std::string&);
    std::string GetSensorType() const;
    void SetDpi(int);
    int GetDpi() const;
    void MoveCursor(int, int);
private:
    int cursorX_ {0};
    int cursorY_ {0};
    std::string sensorType_ {""};
    int dpi_ {};
};

#endif