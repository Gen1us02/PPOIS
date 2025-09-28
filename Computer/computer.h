#ifndef COMPUTER
#define COMPUTER
#include "case.h"
#include "display.h"
#include "microphone.h"
#include "speakers.h"
#include "wifi_adapter.h"
#include "bluetooth_adapter.h"
#include "keyboard.h"
#include "mouse.h"

class Computer{
public:
    Computer();
    Computer(const Case&, const Display&, const Microphone&, const Speakers&, 
            const WiFiAdapter&, const BluetoothAdapter&, const KeyBoard&, const Mouse&);
    bool BuildComputer();
    std::string TurnOn(int, int);
    std::string TurnOff();
private:
    Case case_;
    Display display_;
    Microphone microphone_;
    Speakers speakers_;
    WiFiAdapter wifiAdapter_;
    BluetoothAdapter bluetoothAdapter_;
    KeyBoard keyboard_;
    Mouse mouse_;
};

#endif