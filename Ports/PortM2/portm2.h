#ifndef PORTM2
#define PORTM2
#include "optional"
#include "port.h"
#include "port_type.h"
#include "ssd.h"

class PortM2 : public Port{
public:
    PortM2();
    bool ConnectDevice(const SSD&);
    bool DisconnectDevice() override;
    bool IsOccupied() const;
    bool CanAccept(const SSD&) const;
    std::string GetType() const override;
    int GetSSDSize() const;
private:
    PortType type_ {PortType::M2};
    std::optional<SSD> ssd_;
};

#endif