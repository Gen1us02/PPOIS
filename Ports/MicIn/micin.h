#ifndef MICIN_PORT
#define MICIN_PORT
#include "optional"
#include "port.h"
#include "microphone.h"
#include "port_type.h"

class MicIn : public Port{
public:
    MicIn();
    bool ConnectDevice(const Microphone&);
    bool DisconnectDevice() override;
    bool IsOccupied() const;
    bool CanAccept(const Microphone&) const;
    std::string GetType() const override;
    bool DetectMicriphone() const;
private:
    PortType type_ {PortType::MicIn};
    std::optional<Microphone> microphone_;
};

#endif