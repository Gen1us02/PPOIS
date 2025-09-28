#ifndef ODEVICE
#define ODEVICE
#include <string>
#include "device.h"
#include "input_device.h"

class OutputDevice : public Device{
public:
    virtual ~OutputDevice() = default;
    virtual std::string DisplayInput(const InputDevice&) const = 0;
};

#endif