#include "../Adapters/WiFiAdapter/wifi_adapter.h"
#include "../Hardware/MotherBoard/motherboard.h"
#include "../Case/case.h"
#include "gtest/gtest.h"

class TestingComputerCase : public ::testing::Test {
protected:
    void SetUp() override {
        std::vector<CaseCooler> caseCoolers = {
            CaseCooler(15, 150, "in"),
            CaseCooler(15, 150, "in"),
            CaseCooler(15, 150, "in"),
            CaseCooler(15, 150, "out"),
            CaseCooler(15, 150, "out"),
        };
        motherboard_battery = MotherBoardBattery(3, "lithium", 230);
        motherboard = MotherBoard("AM5", motherboard_battery, 4, "DDR5", "B650");
        usbPort = USB();
        cpuCooler = CPUCooler(15, 120, "AM5");
        gpu = GPU(15, 120, true, 12, 2);
        powerSupply = PowerSupply(15, 120, 750, 87, 100, 240);
        computerCase = Case(4, usbPort, caseCoolers, motherboard, gpu, powerSupply, cpuCooler);
    }

    MotherBoard motherboard;
    CPUCooler cpuCooler;
    GPU gpu;
    USB usbPort;
    PowerSupply powerSupply;
    MotherBoardBattery motherboard_battery;
    Case computerCase;
};

TEST_F(TestingComputerCase, TestGetCoolersCount) {
    ASSERT_EQ(computerCase.GetCoolerCount(), 5);
}

TEST_F(TestingComputerCase, TestUsbPortsCount) {
    ASSERT_EQ(computerCase.GetUSBPortsCount(), 4);
}

TEST_F(TestingComputerCase, TestInstallDisplay) {
    auto display = Display();
    ASSERT_TRUE(computerCase.InstallDisplay(display, PortType::DisplayPort));
    ASSERT_TRUE(computerCase.InstallDisplay(display, PortType::HDMI));
    ASSERT_FALSE(computerCase.InstallDisplay(display, PortType::DisplayPort));
    ASSERT_FALSE(computerCase.InstallDisplay(display, PortType::HDMI));
}

TEST_F(TestingComputerCase, TestUninstallDisplay) {
    auto display = Display();
    ASSERT_TRUE(computerCase.InstallDisplay(display, PortType::DisplayPort));
    ASSERT_TRUE(computerCase.InstallDisplay(display, PortType::HDMI));
    ASSERT_TRUE(computerCase.UninstallDisplay());
    ASSERT_TRUE(computerCase.UninstallDisplay());
    ASSERT_FALSE(computerCase.UninstallDisplay());
}

TEST_F(TestingComputerCase, TestInstallSpeakers) {
    auto speakers = Speakers();
    ASSERT_TRUE(computerCase.InstallSpeakers(speakers));
    ASSERT_FALSE(computerCase.InstallSpeakers(speakers));
}

TEST_F(TestingComputerCase, TestUninstallSpeakers) {
    auto speakers = Speakers();
    ASSERT_TRUE(computerCase.InstallSpeakers(speakers));
    ASSERT_TRUE(computerCase.UninstallSpeakers());
    ASSERT_FALSE(computerCase.UninstallSpeakers());
}

TEST_F(TestingComputerCase, TestInstallMicrophone) {
    auto microphone = Microphone();
    ASSERT_TRUE(computerCase.InstallMicrophone(microphone));
    ASSERT_FALSE(computerCase.InstallMicrophone(microphone));
}

TEST_F(TestingComputerCase, TestUninstallMicrophone) {
    auto microphone = Microphone();
    ASSERT_TRUE(computerCase.InstallMicrophone(microphone));
    ASSERT_TRUE(computerCase.UninstallMicrophone());
    ASSERT_FALSE(computerCase.UninstallMicrophone());
}

TEST_F(TestingComputerCase, TestSetGpuCoolerSpeed) {
    ASSERT_EQ(computerCase.SetGpuCoolersSpeed(100), "Cooler speed 100 rpm");
    ASSERT_EQ(computerCase.SetGpuCoolersSpeed(200), "Incorrect speed");
}

TEST_F(TestingComputerCase, TestSetCaseCoolerSpeed) {
    ASSERT_EQ(computerCase.SetCaseCoolersSpeed(130), "Cooler speed 130 rpm");
    ASSERT_EQ(computerCase.SetCaseCoolersSpeed(200), "Incorrect speed");
}

TEST_F(TestingComputerCase, TestSetPowerSupplyCoolerSpeed) {
    ASSERT_EQ(computerCase.SetPowerSupplyCoolerSpeed(80), "Cooler speed 80 rpm");
    ASSERT_EQ(computerCase.SetPowerSupplyCoolerSpeed(200), "Incorrect speed");
}

TEST_F(TestingComputerCase, TestSetCPUCoolerSpeed) {
    ASSERT_EQ(computerCase.SetCpuCoolerSpeed(80), "Cooler speed 80 rpm");
    ASSERT_EQ(computerCase.SetCpuCoolerSpeed(200), "Incorrect speed");
}

TEST_F(TestingComputerCase, TestGetPowerSupplyVoltageMessage) {
    ASSERT_EQ(computerCase.GetPowerSupplyVoltage(150), "The power supply is connected to the mains with voltage 150");
    ASSERT_EQ(computerCase.GetPowerSupplyVoltage(300), "The power supply is broken.");
}

TEST_F(TestingComputerCase, TestInstallUSBDevice) {
    auto wifiAdapter = WiFiAdapter();
    ASSERT_TRUE(computerCase.InstallUSBDevice(wifiAdapter));
    ASSERT_TRUE(computerCase.InstallUSBDevice(wifiAdapter));
    ASSERT_TRUE(computerCase.InstallUSBDevice(wifiAdapter));
    ASSERT_TRUE(computerCase.InstallUSBDevice(wifiAdapter));
    ASSERT_FALSE(computerCase.InstallUSBDevice(wifiAdapter));
}

TEST_F(TestingComputerCase, TestUninstallUSBDevice) {
    auto wifiAdapter = WiFiAdapter();
    ASSERT_TRUE(computerCase.InstallUSBDevice(wifiAdapter));
    ASSERT_TRUE(computerCase.InstallUSBDevice(wifiAdapter));
    ASSERT_FALSE(computerCase.UninstallUSBDeviceByIndex(-1));
    ASSERT_FALSE(computerCase.UninstallUSBDeviceByIndex(78));
    ASSERT_TRUE(computerCase.UninstallUSBDeviceByIndex(0));
    ASSERT_TRUE(computerCase.UninstallUSBDeviceByIndex(1));
}

TEST(TestCase, TestConstructor) {
    std::vector<CaseCooler> caseCoolers = {
        CaseCooler(15, 150, "in"),
        CaseCooler(15, 150, "in"),
        CaseCooler(15, 150, "in"),
        CaseCooler(15, 150, "out"),
        CaseCooler(15, 150, "out"),
    };
    auto motherboard_battery = MotherBoardBattery(3, "lithium", 230);
    auto motherboard = MotherBoard("AM5", motherboard_battery, 4, "DDR5", "B650");
    auto usbPort = USB();
    auto cpuCooler = CPUCooler(15, 120, "AM5");
    auto gpu = GPU(15, 120, true, 12, 2);
    auto powerSupply = PowerSupply(15, 120, 750, 87, 100, 240);
    auto computerCase = Case(4, usbPort, caseCoolers, motherboard, gpu, powerSupply, cpuCooler);
    ASSERT_EQ(computerCase.GetCoolerCount(), 5);
    ASSERT_EQ(computerCase.GetUSBPortsCount(), 4);
}
