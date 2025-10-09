#include "case.h"

#include "../Exceptions/exceptions.h"

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
    try {
        if (port == PortType::HDMI) {
            return hdmiPort_.ConnectDevice(display);
        }

        if (port == PortType::DisplayPort) {
            return displayPort_.ConnectDevice(display);
        }

        return false;
    } catch (const ExceptionIsOccupiedError &ex) {
        std::cout << ex.what() << std::endl;
        return false;
    }
}

bool Case::UninstallDisplay() {
    try {
        if (displayPort_.IsOccupied()) {
            return displayPort_.DisconnectDevice();
        }

        if (hdmiPort_.IsOccupied()) {
            return hdmiPort_.DisconnectDevice();
        }

        return false;
    } catch (const ExceptionNotIsOccupiedError &ex) {
        std::cout << ex.what() << std::endl;
        return false;
    }
}

bool Case::InstallSpeakers(const Speakers &speakers) {
    try {
        return lineoutPort_.ConnectDevice(speakers);
    } catch (const ExceptionIsOccupiedError &ex) {
        std::cout << ex.what() << std::endl;
        return false;
    }
}

bool Case::UninstallSpeakers() {
    try {
        return lineoutPort_.DisconnectDevice();
    } catch (const ExceptionNotIsOccupiedError &ex) {
        std::cout << ex.what() << std::endl;
        return false;
    }
}

bool Case::InstallMicrophone(const Microphone &microphone) {
    try {
        return micinPort_.ConnectDevice(microphone);
    } catch (const ExceptionIsOccupiedError &ex) {
        std::cout << ex.what() << std::endl;
        return false;
    }
}

bool Case::UninstallMicrophone() {
    try {
        return micinPort_.DisconnectDevice();
    } catch (const ExceptionNotIsOccupiedError &ex) {
        std::cout << ex.what() << std::endl;
        return false;
    }
}

std::string Case::SetCaseCoolersSpeed(int speed) const {
    try {
        std::string result;
        for (const CaseCooler &cooler: coolers_) {
            result = cooler.SetCurrentSpeed(speed);
        }

        return result;
    } catch (const ExceptionIncorrectSpeed &ex) {
        return ex.what();
    }
}

std::string Case::SetPowerSupplyCoolerSpeed(int speed) const {
    try {
        return powerSupply_.SetCoolerCurrentSpeed(speed);
    } catch (const ExceptionIncorrectSpeed &ex) {
        return ex.what();
    }
}

std::string Case::SetCpuCoolerSpeed(int speed) const {
    try {
        return cpuCooler_.SetCurrentSpeed(speed);
    } catch (const ExceptionIncorrectSpeed &ex) {
        return ex.what();
    }
}

std::string Case::SetGpuCoolersSpeed(int speed) const {
    try {
        return gpu_.SetCoolerCurrentSpeed(speed);
    } catch (const ExceptionIncorrectSpeed &ex) {
        return ex.what();
    }
}

std::string Case::GetPowerSupplyVoltage(int voltage) const {
    try {
        return powerSupply_.VoltageSupplyMessage(voltage);
    } catch (const ExceptionIncorrectVoltage &ex) {
        return ex.what();
    }
}
