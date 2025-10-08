#include "../Hardware/CPU/cpu.h"
#include "gtest/gtest.h"

class TestingCPU : public ::testing::Test {
protected:
    void SetUp() override {
        cpu = CPU("AM4", 6, 12, 3.5, 4.4);
    }

    CPU cpu;
};

TEST_F(TestingCPU, TestSetSocketType) {
    ASSERT_EQ(cpu.GetSocketType(), "AM4");
    cpu.SetSocketType("AM5");
    ASSERT_EQ(cpu.GetSocketType(), "AM5");
}

TEST_F(TestingCPU, TestGetSocketType) {
    ASSERT_EQ(cpu.GetSocketType(), "AM4");
}

TEST_F(TestingCPU, TestSetCoreCount) {
    ASSERT_EQ(cpu.GetCoreCount(), 6);
    cpu.SetCoreCount(8);
    ASSERT_EQ(cpu.GetCoreCount(), 8);
}

TEST_F(TestingCPU, TestGetCoreCount) {
    ASSERT_EQ(cpu.GetCoreCount(), 6);
}

TEST_F(TestingCPU, TestSetMaxThreadCount) {
    ASSERT_EQ(cpu.GetMaxTreadCount(), 12);
    cpu.SetMaxTreadCount(16);
    ASSERT_EQ(cpu.GetMaxTreadCount(), 16);
}

TEST_F(TestingCPU, TestGetMaxThreadCount) {
    ASSERT_EQ(cpu.GetMaxTreadCount(), 12);
}

TEST_F(TestingCPU, TestSetBaseFrequency) {
    ASSERT_EQ(cpu.GetBaseFrequency(), 3.5);
    cpu.SetBaseFrequency(4.5);
    ASSERT_EQ(cpu.GetBaseFrequency(), 4.5);
}

TEST_F(TestingCPU, TestGetBaseFrequency) {
    ASSERT_EQ(cpu.GetBaseFrequency(), 3.5);
}

TEST_F(TestingCPU, TestSetMaxFrequency) {
    ASSERT_EQ(cpu.GetMaxFrequency(), 4.4);
    cpu.SetMaxFrequency(5.5);
    ASSERT_EQ(cpu.GetMaxFrequency(), 5.5);
}

TEST_F(TestingCPU, TestSetDlssModeIncorrect) {
    ASSERT_EQ(cpu.GetMaxFrequency(), 4.4);
}

TEST_F(TestingCPU, TestSetTurboMode) {
    ASSERT_EQ(cpu.SetTurboMode(true), "The processor is accelerated to the maximum frequency 4.4");
    ASSERT_EQ(cpu.SetTurboMode(false), "The processor is running at the base frequency 3.5");
}

TEST_F(TestingCPU, TestInstall) {
    cpu.Install();
    ASSERT_TRUE(cpu.IsInstaled());
}

TEST_F(TestingCPU, TestUninstall) {
    cpu.Install();
    ASSERT_TRUE(cpu.IsInstaled());
    cpu.Uninstall();
    ASSERT_FALSE(cpu.IsInstaled());
}

TEST_F(TestingCPU, TestIsInstaled) {
    ASSERT_FALSE(cpu.IsInstaled());
    cpu.Install();
    ASSERT_TRUE(cpu.IsInstaled());
}

TEST(TestCPU, TestConstructor) {
    auto cpu = CPU("LGA1700", 14, 20, 3.5, 4.4);
    ASSERT_EQ(cpu.GetSocketType(), "LGA1700");
    ASSERT_EQ(cpu.GetCoreCount(), 14);
    ASSERT_EQ(cpu.GetMaxTreadCount(), 20);
    ASSERT_EQ(cpu.GetBaseFrequency(), 3.5);
    ASSERT_EQ(cpu.GetMaxFrequency(), 4.4);
}
