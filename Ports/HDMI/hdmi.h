#ifndef HDMI_PORT
#define HDMI_PORT
#include "optional"
#include "port.h"
#include "port_type.h"

class HDMI : public Port{
public:
    HDMI();
    bool ConnectDevice(const Device&) override;
    bool DisconnectDevice() override;
    bool IsOccupied() const;
    bool CanAccept(const Device&) const override;
    std::string GetType() const override;
private:
    PortType type_ {PortType::HDMI};
    std::optional<Device> device_;
};

#endif