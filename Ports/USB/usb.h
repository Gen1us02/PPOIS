#ifndef USB_PORT
#define USB_PORT
#include "optional"
#include "port.h"
#include "port_type.h"

class USB : public Port{
public:
    USB();
    bool ConnectDevice(const Device&) override;
    bool DisconnectDevice() override;
    bool IsOccupied() const;
    bool CanAccept(const Device&) const override;
    std::string GetType() const override;
private:
    PortType type_ {PortType::USB};
    std::optional<Device> device_;
};

#endif