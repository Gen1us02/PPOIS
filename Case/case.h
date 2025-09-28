#ifndef CASE
#define CASE
#include <vector>
#include "case_cooler.h"
#include "displayport.h"
#include "hdmi.h"
#include "lineout.h"
#include "micin.h"
#include "usb.h"
#include "motherboard.h"
#include "power_supply.h"
#include "cpu_cooler.h"
#include "gpu.h"


class Case{
public:
    Case();
    Case(int, int, const USB&, const std::vector<CaseCooler>&, 
        const MotherBoard&, const GPU&, const PowerSupply&, const CPUCooler&);
    int GetCoolerCount() const;
    int GetUSBPortsCount() const;
    bool InstallUSBDevice(const Device&);
    bool InstallDisplay(const Display&, PortType);
    bool UninstallDisplay();
    bool InstallSpeakers(const Speakers&);
    void SetGpuCoolersSpeed(int);
    std::string GetPowerSupplyVoltage(int) const;
    bool UninstallSpeakers();
    bool InstallMicrophone(const Microphone&);
    bool UninstallMicrophone();
private:
    std::vector<CaseCooler> coolers_;
    const int coolersCount_ {0};
    CPUCooler cpuCooler_;
    DisplayPort displayPort_;
    HDMI hdmiPort_;
    LineOut lineoutPort_;
    MicIn micinPort_;
    std::vector<USB> usbPorts_;
    MotherBoard motherBoard_;
    GPU gpu_;
    PowerSupply powerSupply_;
    const int usbPortsCount_ {0};
};

#endif