#ifndef LINEOUT_PORT
#define LINEOUT_PORT
#include "optional"
#include "port.h"
#include "speakers.h"
#include "port_type.h"

class LineOut : public Port{
public:
    LineOut();
    bool ConnectDevice(const Speakers&);
    bool DisconnectDevice() override;
    bool CanAccept(const Speakers&) const;
    std::string GetType() const override;
    bool DetectMicriphone() const;
private:
    PortType type_ {PortType::LineOut};
    std::optional<Speakers> speakers_;
};

#endif