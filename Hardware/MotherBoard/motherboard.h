#ifndef MOTHERBOARD
#define MOTHERBOARD
#include <string>
#include <optional>
#include "vector"
#include "hardware.h"
#include "cpu.h"
#include "ssd.h"
#include "ram.h"
#include "portm2.h"
#include "motherboard_battery.h"

class MotherBoard: public Hardware{
public:
    MotherBoard();
    MotherBoard(const std::string&, const MotherBoardBattery&, 
                int, const std::string&, const std::string&);
    std::string GetSocket() const;
    bool InstallCPU(const CPU&);
    bool UninstallCPU();
    bool AddRAM(int, const RAM&);
    bool RemoveRAMByIndex(int);
    bool InstallSSD(const SSD&);
    bool UninstallSSD();
    bool IsBatteryHealthy() const;
    int GetRamCount() const;
    std::string GetRamType() const;
    std::string GetChipset() const;
private:
    bool IsCPUCompatibility(const CPU&) const;
    bool IsRAMCompatibility(const RAM&) const;
    const std::string socket_ {""};
    std::optional<CPU> processor_;
    std::vector<std::optional<RAM>> ramModules_;
    std::optional<SSD> ssd_;
    MotherBoardBattery battery_;
    PortM2 ssdPort_;
    const int ramCount_ {0};
    const std::string ramType_ {""};
    const std::string chipset_ {""};
};


#endif