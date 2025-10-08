#include "motherboard.h"
#include "../Exceptions/exceptions.h"

MotherBoard::MotherBoard() = default;

MotherBoard::MotherBoard(const std::string &socket, const MotherBoardBattery &battery,
                         int ramCount, const std::string &ramType, const std::string &chipset) : socket_(socket),
    battery_(battery), ramCount_(ramCount), ramType_(ramType), chipset_(chipset) {
    ramModules_.resize(ramCount);
}

std::string MotherBoard::GetSocket() const {
    return this->socket_;
}

bool MotherBoard::InstallCPU(const CPU &processor) {
    if (processor_.has_value()) return false;
    if (!IsCPUCompatibility(processor)) return false;
    this->processor_.emplace(processor);
    processor_->Install();
    return true;
}

bool MotherBoard::UninstallCPU() {
    if (!processor_.has_value()) return false;
    processor_->Uninstall();
    processor_.reset();
    return true;
}

bool MotherBoard::AddRAM(int slotIndex, const RAM &module) {
    if (slotIndex < 0 || slotIndex >= this->ramCount_) return false;
    if (!IsRAMCompatibility(module)) return false;
    if (ramModules_[slotIndex].has_value()) return false;
    this->ramModules_[slotIndex].emplace(module);
    return true;
}

bool MotherBoard::RemoveRAMByIndex(int slotIndex) {
    if (slotIndex < 0 || slotIndex >= this->ramCount_) return false;
    if (this->ramModules_.size() <= slotIndex) return false;
    if (!ramModules_[slotIndex].has_value()) return false;
    this->ramModules_[slotIndex].reset();
    return true;
}

bool MotherBoard::IsBatteryHealthy() const {
    return this->battery_.IsAlive();
}

int MotherBoard::GetRamCount() const {
    return this->ramCount_;
}

std::string MotherBoard::GetRamType() const {
    return this->ramType_;
}

std::string MotherBoard::GetChipset() const {
    return this->chipset_;
}

bool MotherBoard::IsCPUCompatibility(const CPU &processor) const {
    return processor.GetSocketType() == this->socket_;
}

bool MotherBoard::IsRAMCompatibility(const RAM &module) const {
    return module.GetType() == this->ramType_;
}

bool MotherBoard::InstallSSD(const SSD &ssd) {
    try {
        if (ssdPort_.IsOccupied()) {
            throw ExceptionIsOccupiedError("Порт занят");
        }
        this->ssd_.emplace(ssd);
        ssd_->Install();
        return ssdPort_.ConnectDevice(ssd);
    } catch (const ExceptionIsOccupiedError &ex) {
        std::cout << ex.what();
        return false;
    }
}

bool MotherBoard::UninstallSSD() {
    try {
        if (!ssdPort_.IsOccupied()) {
            throw ExceptionNotIsOccupiedError("Порт свободен");
        }
        ssd_->Uninstall();
        this->ssd_.reset();
        return ssdPort_.DisconnectDevice();
    } catch (const ExceptionNotIsOccupiedError &ex) {
        std::cout << ex.what();
        return false;
    }
}
