#ifndef ODEVICE
#define ODEVICE
#include <string>

class Output_Device{
    virtual std::string Display() = 0;
    virtual bool IsConnected() const = 0;
    virtual void Connect() const = 0;
};


class Display : public Output_Device{};
class Speakers : public Output_Device{};


#endif