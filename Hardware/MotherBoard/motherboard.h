#ifndef MOTHERBOARD
#define MOTHERBOARD
#include <string>
#include <optional>
#include "vector"
#include "hardware.h"
#include "cpu.h"
#include "ssd.h"
#include "ram.h"
#include "motherboard_battery.h"

class MotherBoard: public Hardware{
public:
    MotherBoard();
    MotherBoard(const std::string&, const SSD&, const MotherBoardBattery&, 
                int, const std::string&, const std::string&);
    void SetSocket(const std::string&);
    std::string GetSocket() const;
    bool InstallCPU(const CPU&);
    bool UninstallCPU();
    bool AddRAM(int, const RAM&);
    bool RemoveRAMByIndex(int);
    bool IsBatteryHealthy() const;
    void SetRamCount(int);
    int GetRamCount() const;
    void SetRamType(const std::string&);
    std::string GetRamType() const;
    void SetChipset(const std::string&);
    std::string GetChipset() const;
private:
    bool IsCPUCompatibility(const CPU&) const;
    bool IsRAMCompatibility(const RAM&) const;
    std::string socket_ {""};
    std::optional<CPU> processor_;
    std::vector<std::optional<RAM>> ramModules_;
    std::optional<SSD> ssd_;
    MotherBoardBattery battery_;
    int ramCount_ {0};
    std::string ramType_ {""};
    std::string chipset_ {""};
};


#endif