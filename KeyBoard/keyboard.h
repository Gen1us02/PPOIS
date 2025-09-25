#ifndef KEYBOARD
#define KEYBOARD
#include "input_device.h"


class KeyBoard : public InputDevice{
public:
    KeyBoard();
    KeyBoard(const std::string&);
    void SetType(const std::string&);
    std::string GetType() const;
    std::string PressButton(const std::string&);
private:
    std::string type_ {""};
};

#endif