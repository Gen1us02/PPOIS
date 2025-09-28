#include "case.h"

Case::Case() = default;
Case::Case(int coolersCount, int usbPortsCount, const USB& usbPort, const std::vector<CaseCooler>& coolers,
            const MotherBoard& motherBoard, const GPU& gpu, const PowerSupply& powerSupply, const CPUCooler& cpuCooler):
coolersCount_(coolersCount), usbPortsCount_(usbPortsCount), usbPorts_(usbPortsCount, usbPort), 
motherBoard_(motherBoard), gpu_(gpu), powerSupply_(powerSupply), cpuCooler_(cpuCooler){
    coolers_.resize(coolersCount);
    for (int i = 0; i < coolersCount; i++){
        coolers_[i] = coolers[i];
        coolers_[i].Install();
    }
}   

int Case::GetCoolerCount() const{
    return this->coolersCount_;
}

int Case::GetUSBPortsCount() const{
    return this->usbPortsCount_;
}

bool Case::InstallUSBDevice(const Device& device){
    if (!device.SupportsPort(PortType::USB)) return false;
    for(int i = 0; i < this->usbPortsCount_; i++){
        if (!usbPorts_[i].IsOccupied())
        {
            usbPorts_[i].ConnectDevice(device);
            return true;
        }
    }
    
    return false;
}

bool Case::InstallDisplay(const Display& display, PortType port){
    if (port == PortType::HDMI){
        return hdmiPort_.ConnectDevice(display);
    }
    
    if (port == PortType::DisplayPort){
        return displayPort_.ConnectDevice(display);
    }
    
    return false;
}

bool Case::UninstallDisplay(){
    if (displayPort_.IsOccupied()) {
        displayPort_.DisconnectDevice();
        return displayPort_.DisconnectDevice();
    }

    if (hdmiPort_.IsOccupied()){
        hdmiPort_.DisconnectDevice();
        return hdmiPort_.DisconnectDevice();;
    }

    return false;
}

bool Case::InstallSpeakers(const Speakers& speakers){
    return lineoutPort_.ConnectDevice(speakers);
}

bool Case::UninstallSpeakers(){
    return lineoutPort_.DisconnectDevice();
}

bool Case::InstallMicrophone(const Microphone& microphone){
    return micinPort_.ConnectDevice(microphone);
}

bool Case::UninstallMicrophone(){
    return micinPort_.DisconnectDevice();
}

void Case::SetGpuCoolersSpeed(int speed){
    return gpu_.SetCoolerCurrentSpeed(speed);
}

std::string Case::GetPowerSupplyVoltage(int voltage) const{
    return powerSupply_.VoltageSupplyMessage(voltage);
}