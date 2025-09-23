#ifndef MOUSE
#define MOUSE
#include "input_device.h"

class Mouse:public Input_Device{
private:
    int _cursor_x {0};
    int _cursor_y {0};
    std::string _sensor_type {"laser"};
    int _dpi {2000};
public:
    Mouse();
    Mouse(int, int, const std::string&, int);
    void set_cursor_x(int);
    int get_cursor_x() const;
    void set_cursor_y(int);
    int get_cursor_y() const;
    void set_sensor_type(const std::string&);
    std::string get_sensor_type() const;
    void set_dpi(int);
    int get_dpi() const;
    void MoveCursor(int, int);
};

#endif