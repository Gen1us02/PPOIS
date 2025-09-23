#ifndef ODEVICE
#define ODEVICE
#include <string>
#include "device.h"
#include "input_device.h"

class Output_Device : public Device{
    virtual std::string displayInput(const Input_Device&) const = 0;
};

#endif