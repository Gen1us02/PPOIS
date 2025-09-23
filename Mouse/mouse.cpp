#include <mouse.h>

Mouse::Mouse() = default;

Mouse::Mouse(int cursor_x, int cursor_y, const std::string& sensor_type, int dpi):
_cursor_x(cursor_x), _cursor_y(cursor_y), _sensor_type(sensor_type), _dpi(dpi){};

void Mouse::set_cursor_x(int cursor_x){
    this->_cursor_x = cursor_x;
}

int Mouse::get_cursor_x() const{
    return this->_cursor_x;
}

void Mouse::set_cursor_y(int cursor_y){
    this->_cursor_y = cursor_y;
}

int Mouse::get_cursor_y() const{
    return this->_cursor_y;
}

void Mouse::set_sensor_type(const std::string& sensor_type){
    this->_sensor_type = sensor_type;
}

std::string Mouse::get_sensor_type() const{
    return this->_sensor_type;
}

void Mouse::set_dpi(int dpi){
    this->_dpi = dpi;
}

int Mouse::get_dpi() const{
    return this->_dpi;
}

void Mouse::MoveCursor(int x, int y){
    this->set_cursor_x(x);
    this->set_cursor_y(y);
    std::string coords = "x: " + std::to_string(this->_cursor_x)+ "y: " + std::to_string(this->_cursor_y);
    readInput(coords);
}