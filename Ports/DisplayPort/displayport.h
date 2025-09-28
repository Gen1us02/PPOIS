#ifndef DISPLAY_PORT
#define DISPLAY_PORT
#include "optional"
#include "port.h"
#include "display.h"
#include "port_type.h"

class DisplayPort : public Port{
public:
    DisplayPort();
    bool ConnectDevice(const Display&);
    bool DisconnectDevice() override;
    bool IsOccupied() const;
    bool CanAccept(const Display&) const;
    std::string GetType() const override;
private:
    PortType type_ {PortType::DisplayPort};
    std::optional<Display> display_;
};

#endif