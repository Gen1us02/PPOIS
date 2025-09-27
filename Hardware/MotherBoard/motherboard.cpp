#include "motherboard.h"

MotherBoard::MotherBoard() = default;

MotherBoard::MotherBoard(const std::string& socket, const SSD& ssd,const MotherBoardBattery& battery,
                         int ramCount, const std::string& ramType, const std::string& chipset):
socket_(socket), ssd_(ssd), battery_(battery), 
ramCount_(ramCount), ramType_(ramType), chipset_(chipset){
    ramModules_.resize(ramCount);
}

void MotherBoard::SetSocket(const std::string& socket){
    this->socket_ = socket;
}

std::string MotherBoard::GetSocket() const{
    return this->socket_;
}

bool MotherBoard::InstallCPU(const CPU& processor){
    if(processor_.has_value()) return false;
    if(!IsCPUCompatibility(processor)) return false;
    this->processor_.emplace(processor);
    return true;
}

bool MotherBoard::UninstallCPU(){
    if(!processor_.has_value()) return false;
    processor_.reset();
    return true;
}

bool MotherBoard::AddRAM(int slotIndex, const RAM& module){
    if (slotIndex < 0 || slotIndex >= this->ramCount_) return false;
    if (!IsRAMCompatibility(module)) return false;
    this->ramModules_[slotIndex].emplace(module);
    return true;
}

bool MotherBoard::RemoveRAMByIndex(int slotIndex){
    if (slotIndex < 0 || slotIndex >= this->ramCount_) return false;
    if (this->ramModules_.size() <= slotIndex) return false;
    this->ramModules_[slotIndex].reset();
    return true;
}

bool MotherBoard::IsBatteryHealthy() const{
    return this->battery_.IsAlive();
}

void MotherBoard::SetRamCount(int ramCount){
    this->ramCount_ = ramCount;
    this->ramModules_.resize(ramCount);
}

int MotherBoard::GetRamCount() const{
    return this->ramCount_;
}

void MotherBoard::SetRamType(const std::string& ramType){
    this->ramType_ = ramType;
}

std::string MotherBoard::GetRamType() const{
    return this->ramType_;
}

void MotherBoard::SetChipset(const std::string& chipset){
    this->chipset_ = chipset;
}

std::string MotherBoard::GetChipset() const{
    return this->chipset_;
}

bool MotherBoard::IsCPUCompatibility(const CPU& processor) const{
    return processor.GetSocketType() == this->socket_;
}

bool MotherBoard::IsRAMCompatibility(const RAM& module) const{
    return module.GetType() == this->ramType_;
}