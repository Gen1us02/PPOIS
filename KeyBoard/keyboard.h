#ifndef KEYBOARD
#define KEYBOARD
#include <device.h>


class KeyBoard : public Device{
private:
    bool _is_connected {false};
    std::string _type {"membrane"};
    std::string _user_input {""};
public:
    KeyBoard();
    KeyBoard(const std::string&);
    void set_type(const std::string&);
    std::string get_type() const;
    void Connect() override;
    void Disconnect() override;
    bool IsConnected() const override;
    void ReadInput(const std::string&);
};

#endif