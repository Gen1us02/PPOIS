#include "../Computer/computer.h"
#include "gtest/gtest.h"

class TestingComputer : public ::testing::Test {
protected:
    void SetUp() override {
        std::vector<CaseCooler> caseCoolers = {
            CaseCooler(15,150, "in"),
            CaseCooler(15,150, "in"),
            CaseCooler(15,150, "in"),
            CaseCooler(15,150, "out"),
            CaseCooler(15,150, "out"),
        };
        motherboard_battery = MotherBoardBattery(3, "lithium", 230);
        motherboard = MotherBoard("AM5", motherboard_battery, 4, "DDR5", "B650");
        usbPort = USB();
        cpuCooler = CPUCooler(15,120, "AM5");
        gpu = GPU(15, 120, true, 12, 2);
        powerSupply = PowerSupply(15, 120, 750, 87, 100, 240);
        computerCase = Case(4, usbPort, caseCoolers, motherboard, gpu, powerSupply, cpuCooler);
        mouse = Mouse(150, 800, "optical", 12000);
        keyboard = KeyBoard("mechanic");
        display = Display("1920x1080", 4.1, 120, "1920x1080", 165, 27);
        speakers = Speakers(2, 70, 3.5, 250);
        microphone = Microphone("dynamic", 14000, 90);
        wifiAdapter = WiFiAdapter();
        bluetoothAdapter = BluetoothAdapter();
        computer = Computer(computerCase, display, microphone, speakers, wifiAdapter, bluetoothAdapter, keyboard, mouse);
    }

    MotherBoard motherboard;
    CPUCooler cpuCooler;
    GPU gpu;
    USB usbPort;
    PowerSupply powerSupply;
    MotherBoardBattery motherboard_battery;
    Case computerCase;
    Display display;
    Mouse mouse;
    Speakers speakers;
    Microphone microphone;
    KeyBoard keyboard;
    WiFiAdapter wifiAdapter;
    BluetoothAdapter bluetoothAdapter;
    Computer computer;
};

TEST_F(TestingComputer, TestBuildComputer) {
    ASSERT_TRUE(computer.BuildComputer());
    ASSERT_FALSE(computer.BuildComputer());
}

TEST_F(TestingComputer, TestTurnOn){
    ASSERT_EQ(computer.TurnOn(100, 220), "Computer turn on\nThe power supply is connected to the mains with voltage 220\nCooler speed 100 rpm");
    ASSERT_EQ(computer.TurnOn(200, 300), "Computer turn on\nThe power supply is broken.\nIncorrect speed");
}

TEST_F(TestingComputer, TestTurnOff) {
    ASSERT_EQ(computer.TurnOff(), "Computer turn off");
}

TEST(TestComputer, TestConstructor) {
    std::vector<CaseCooler> caseCoolers = {
        CaseCooler(15,150, "in"),
        CaseCooler(15,150, "in"),
        CaseCooler(15,150, "in"),
        CaseCooler(15,150, "out"),
        CaseCooler(15,150, "out"),
    };
    auto motherboard_battery = MotherBoardBattery(3, "lithium", 230);
    auto motherboard = MotherBoard("AM5", motherboard_battery, 4, "DDR5", "B650");
    auto usbPort = USB();
    auto cpuCooler = CPUCooler(15,120, "AM5");
    auto gpu = GPU(15, 120, true, 12, 2);
    auto powerSupply = PowerSupply(15, 120, 750, 87, 100, 240);
    auto computerCase = Case(4, usbPort, caseCoolers, motherboard, gpu, powerSupply, cpuCooler);
    auto mouse = Mouse(150, 800, "optical", 12000);
    auto keyboard = KeyBoard("mechanic");
    auto display = Display("1920x1080", 4.1, 120, "1920x1080", 165, 27);
    auto speakers = Speakers(2, 70, 3.5, 250);
    auto microphone = Microphone("dynamic", 14000, 90);
    auto wifiAdapter = WiFiAdapter();
    auto bluetoothAdapter = BluetoothAdapter();
    auto computer = Computer(computerCase, display, microphone, speakers, wifiAdapter, bluetoothAdapter, keyboard, mouse);
    ASSERT_TRUE(computer.BuildComputer());
}