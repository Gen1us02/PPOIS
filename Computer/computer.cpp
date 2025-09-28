#include "computer.h"

Computer::Computer() = default;

Computer::Computer(const Case& computerCase, const Display& display, const Microphone& microphone, const Speakers& speakers,
                    const WiFiAdapter& wifiAdapter, const BluetoothAdapter& bluetoothAdapter, const KeyBoard& keyboard, const Mouse& mouse):
case_(computerCase), display_(display), microphone_(microphone), speakers_(speakers), 
wifiAdapter_(wifiAdapter), bluetoothAdapter_(bluetoothAdapter), keyboard_(keyboard), mouse_(mouse){}

bool Computer::BuildComputer(){
    return case_.InstallDisplay(this->display_, PortType::DisplayPort) &&
            case_.InstallMicrophone(this->microphone_) &&
            case_.InstallSpeakers(this->speakers_) &&
            case_.InstallUSBDevice(this->wifiAdapter_) &&
            case_.InstallUSBDevice(this->bluetoothAdapter_) &&
            case_.InstallUSBDevice(this->keyboard_) &&
            case_.InstallUSBDevice(this->mouse_);
}

std::string Computer::TurnOn(int coolersSpeed, int powerSupplyVoltage){
    display_.TurnOn();
    microphone_.TurnOn();
    speakers_.TurnOn();
    wifiAdapter_.TurnOn();
    bluetoothAdapter_.TurnOn();
    keyboard_.TurnOn();
    mouse_.TurnOn();
    case_.SetGpuCoolersSpeed(coolersSpeed);
    return "Компьютер включен\n" + case_.GetPowerSupplyVoltage(powerSupplyVoltage);
}

std::string Computer::TurnOff(){
    display_.TurnOff();
    microphone_.TurnOff();
    speakers_.TurnOff();
    wifiAdapter_.TurnOff();
    bluetoothAdapter_.TurnOff();
    keyboard_.TurnOff();
    mouse_.TurnOff();
    case_.SetGpuCoolersSpeed(0);
    return "Компьютер выключен";
}