#include "../Hardware/Coolers/CPUCooler/cpu_cooler.h"
#include "gtest/gtest.h"

class TestingCPUCooler : public ::testing::Test {
protected:
    void SetUp() override {
        cpu_cooler = CPUCooler(15, 120, "AM4");
    }

    CPUCooler cpu_cooler;
};

TEST_F(TestingCPUCooler, TestSetMinSpeed) {
    ASSERT_EQ(cpu_cooler.GetMinSpeed(), 15);
    cpu_cooler.SetMinSpeed(30);
    ASSERT_EQ(cpu_cooler.GetMinSpeed(), 30);
}

TEST_F(TestingCPUCooler, TestGetMinSpeed) {
    ASSERT_EQ(cpu_cooler.GetMinSpeed(), 15);
}

TEST_F(TestingCPUCooler, TestSetMaxSpeed) {
    ASSERT_EQ(cpu_cooler.GetMaxSpeed(), 120);
    cpu_cooler.SetMaxSpeed(140);
    ASSERT_EQ(cpu_cooler.GetMaxSpeed(), 140);
}

TEST_F(TestingCPUCooler, TestGetMaxSpeed) {
    ASSERT_EQ(cpu_cooler.GetMaxSpeed(), 120);
}

TEST_F(TestingCPUCooler, TestSetSocket) {
    ASSERT_EQ(cpu_cooler.GetSocket(), "AM4");
    cpu_cooler.SetSocket("LGA1851");
    ASSERT_EQ(cpu_cooler.GetSocket(), "LGA1851");
}

TEST_F(TestingCPUCooler, TestGetSocket) {
    ASSERT_EQ(cpu_cooler.GetSocket(), "AM4");
}

TEST_F(TestingCPUCooler, TestGetType) {
    ASSERT_EQ(cpu_cooler.GetType(), "cpu");
}

TEST_F(TestingCPUCooler, TestSetCurrentSpeed) {
    ASSERT_EQ(cpu_cooler.SetCurrentSpeed(100), "Cooler speed 100 rpm");
    ASSERT_EQ(cpu_cooler.SetCurrentSpeed(200), "Incorrect speed");
}

TEST_F(TestingCPUCooler, TestInstall) {
    cpu_cooler.Install();
    ASSERT_TRUE(cpu_cooler.IsInstaled());
}

TEST_F(TestingCPUCooler, TestUninstall) {
    cpu_cooler.Install();
    ASSERT_TRUE(cpu_cooler.IsInstaled());
    cpu_cooler.Uninstall();
    ASSERT_FALSE(cpu_cooler.IsInstaled());
}

TEST_F(TestingCPUCooler, TestIsInstaled) {
    ASSERT_FALSE(cpu_cooler.IsInstaled());
    cpu_cooler.Install();
    ASSERT_TRUE(cpu_cooler.IsInstaled());
}

TEST(TestCPUCooler, TestConstructor) {
    auto cpu_cooler = CPUCooler(30, 160, "LGA1700");
    ASSERT_EQ(cpu_cooler.GetMinSpeed(), 30);
    ASSERT_EQ(cpu_cooler.GetMaxSpeed(), 160);
    ASSERT_EQ(cpu_cooler.GetType(), "cpu");
}
