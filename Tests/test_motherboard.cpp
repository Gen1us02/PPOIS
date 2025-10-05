#include "../Hardware/MotherBoard/motherboard.h"
#include "gtest/gtest.h"

class TestingMotherBoard : public ::testing::Test {
protected:
    void SetUp() override {
        motherboard_battery = MotherBoardBattery(3, "lithium", 230);
        motherboard = MotherBoard("AM5", motherboard_battery, 4, "DDR5", "B650");
        cpu = CPU("AM5", 6, 12, 3.5, 4.4);
        ram = RAM(16, "DDR5", 6000);
        ssd = SSD(1024, 14000, 13000, 2000000);
    }

    MotherBoard motherboard;
    CPU cpu;
    RAM ram;
    SSD ssd;
    MotherBoardBattery motherboard_battery;
};

TEST_F(TestingMotherBoard, TestGetSocket) {
    ASSERT_EQ(motherboard.GetSocket(), "AM5");
}

TEST_F(TestingMotherBoard, TestInstallCPU){
    ASSERT_TRUE(motherboard.InstallCPU(cpu));
    ASSERT_FALSE(motherboard.InstallCPU(cpu));
    motherboard.UninstallCPU();
    cpu.SetSocketType("AM4");
    ASSERT_FALSE(motherboard.InstallCPU(cpu));
}

TEST_F(TestingMotherBoard, TestUninstallCPU) {
    ASSERT_TRUE(motherboard.InstallCPU(cpu));
    ASSERT_TRUE(motherboard.UninstallCPU());
    ASSERT_FALSE(motherboard.UninstallCPU());
}

TEST_F(TestingMotherBoard, TestAddRam) {
    ASSERT_TRUE(motherboard.AddRAM(0, ram));
    ASSERT_TRUE(motherboard.AddRAM(1, ram));
    ASSERT_TRUE(motherboard.AddRAM(2, ram));
    ASSERT_TRUE(motherboard.AddRAM(3, ram));
    ASSERT_FALSE(motherboard.AddRAM(0, ram));
    ASSERT_FALSE(motherboard.AddRAM(5, ram));
    ASSERT_TRUE(motherboard.RemoveRAMByIndex(0));
    ram.SetType("DDR4");
    ASSERT_FALSE(motherboard.AddRAM(0, ram));
}

TEST_F(TestingMotherBoard, TestRemoveRAMByIndex) {
    ASSERT_FALSE(motherboard.RemoveRAMByIndex(0));
    ASSERT_TRUE(motherboard.AddRAM(0,ram));
    ASSERT_TRUE(motherboard.RemoveRAMByIndex(0));
}

TEST_F(TestingMotherBoard, TestIsBatteryHealthy) {
    ASSERT_TRUE(motherboard.IsBatteryHealthy());
    motherboard_battery.SetCapacity(0);
    auto newMotherBoard = MotherBoard("AM5", motherboard_battery, 4, "DDR5", "B650");
    ASSERT_FALSE(newMotherBoard.IsBatteryHealthy());
}

TEST_F(TestingMotherBoard, TestGetRamType) {
    ASSERT_EQ(motherboard.GetRamType(), "DDR5");
}

TEST_F(TestingMotherBoard, TestGetChipset) {
    ASSERT_EQ(motherboard.GetChipset(), "B650");
}

TEST_F(TestingMotherBoard, TestInstallSSD) {
    ASSERT_TRUE(motherboard.InstallSSD(ssd));
    ASSERT_FALSE(motherboard.InstallSSD(ssd));
}

TEST_F(TestingMotherBoard, TestUninstallSSD) {
    ASSERT_TRUE(motherboard.InstallSSD(ssd));
    ASSERT_TRUE(motherboard.UninstallSSD());
    ASSERT_FALSE(motherboard.UninstallSSD());
}
TEST_F(TestingMotherBoard, TestInstall) {
    motherboard.Install();
    ASSERT_TRUE(motherboard.IsInstaled());
}

TEST_F(TestingMotherBoard, TestUninstall) {
    motherboard.Install();
    ASSERT_TRUE(motherboard.IsInstaled());
    motherboard.Uninstall();
    ASSERT_FALSE(motherboard.IsInstaled());
}

TEST_F(TestingMotherBoard, TestIsInstaled) {
    ASSERT_FALSE(motherboard.IsInstaled());
    motherboard.Install();
    ASSERT_TRUE(motherboard.IsInstaled());
}

TEST(TestMotherBoard, TestConstructor) {
    auto motherboard_battery = MotherBoardBattery(3, "lithium", 230);
    auto motherboard = MotherBoard("LGA1700", motherboard_battery, 2, "DDR4", "B650");
    ASSERT_EQ(motherboard.GetSocket(), "LGA1700");
    ASSERT_EQ(motherboard.GetRamType(), "DDR4");
    ASSERT_EQ(motherboard.GetChipset(), "B650");
    ASSERT_EQ(motherboard.GetRamCount(), 2);
}