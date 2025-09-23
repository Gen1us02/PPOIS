#ifndef KEYBOARD
#define KEYBOARD
#include "input_device.h"


class KeyBoard : public Input_Device{
private:
    std::string _type {"membrane"};
public:
    KeyBoard();
    KeyBoard(const std::string&);
    void set_type(const std::string&);
    std::string get_type() const;
    std::string pressButton(const std::string&);
};

#endif