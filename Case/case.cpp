#include "case.h"

Case::Case() = default;

Case::Case(int usbPortsCount, const USB &usbPort, const std::vector<CaseCooler> &coolers,
           const MotherBoard &motherBoard, const GPU &gpu, const PowerSupply &powerSupply,
           const CPUCooler &cpuCooler) : usbPortsCount_(usbPortsCount), usbPorts_(usbPortsCount, usbPort),
                                         motherBoard_(motherBoard), gpu_(gpu), powerSupply_(powerSupply),
                                         cpuCooler_(cpuCooler) {
    coolersCount_ = coolers.size();
    coolers_.resize(coolersCount_);
    for (int i = 0; i < coolersCount_; i++) {
        coolers_[i] = coolers[i];
        coolers_[i].Install();
    }
}

int Case::GetCoolerCount() const {
    return this->coolersCount_;
}

int Case::GetUSBPortsCount() const {
    return this->usbPortsCount_;
}

bool Case::InstallUSBDevice(const Device &device) {
    if (!device.SupportsPort(PortType::USB)) return false;
    for (int i = 0; i < this->usbPortsCount_; i++) {
        if (!usbPorts_[i].IsOccupied()) {
            return usbPorts_[i].ConnectDevice(device);
        }
    }

    return false;
}

bool Case::UninstallUSBDeviceByIndex(int portIndex) {
    if (portIndex < 0 || portIndex >= this->usbPortsCount_) return false;
    return usbPorts_[portIndex].DisconnectDevice();
}

bool Case::InstallDisplay(const Display &display, PortType port) {
    if (port == PortType::HDMI) {
        return hdmiPort_.ConnectDevice(display);
    }

    if (port == PortType::DisplayPort) {
        return displayPort_.ConnectDevice(display);
    }

    return false;
}

bool Case::UninstallDisplay() {
    if (displayPort_.IsOccupied()) {
        return displayPort_.DisconnectDevice();
    }

    if (hdmiPort_.IsOccupied()) {
        return hdmiPort_.DisconnectDevice();;
    }

    return false;
}

bool Case::InstallSpeakers(const Speakers &speakers) {
    return lineoutPort_.ConnectDevice(speakers);
}

bool Case::UninstallSpeakers() {
    return lineoutPort_.DisconnectDevice();
}

bool Case::InstallMicrophone(const Microphone &microphone) {
    return micinPort_.ConnectDevice(microphone);
}

bool Case::UninstallMicrophone() {
    return micinPort_.DisconnectDevice();
}

std::string Case::SetCaseCoolersSpeed(int speed) const {
    std::string result;
    for (const CaseCooler &cooler: coolers_) {
        result = cooler.SetCurrentSpeed(speed);
    }

    return result;
}

std::string Case::SetPowerSupplyCoolerSpeed(int speed) const {
    return powerSupply_.SetCoolerCurrentSpeed(speed);
}

std::string Case::SetCpuCoolerSpeed(int speed) const {
    return cpuCooler_.SetCurrentSpeed(speed);
}

std::string Case::SetGpuCoolersSpeed(int speed) const {
    return gpu_.SetCoolerCurrentSpeed(speed);
}

std::string Case::GetPowerSupplyVoltage(int voltage) const {
    return powerSupply_.VoltageSupplyMessage(voltage);
}
