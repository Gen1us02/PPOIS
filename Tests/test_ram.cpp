#include "../Exceptions/exceptions.h"
#include "../Hardware/RAM/ram.h"
#include "gtest/gtest.h"

class TestingRAM : public ::testing::Test {
protected:
    void SetUp() override {
        ram = RAM(16, "DDR4", 6000);
    }

    RAM ram;
};

TEST_F(TestingRAM, TestSetMemory) {
    ASSERT_EQ(ram.GetMemory(), 16);
    ram.SetMemory(32);
    ASSERT_EQ(ram.GetMemory(), 32);
}

TEST_F(TestingRAM, TestGetDynamicCount) {
    ASSERT_EQ(ram.GetMemory(), 16);
}

TEST_F(TestingRAM, TestSetType) {
    ASSERT_EQ(ram.GetType(), "DDR4");
    ram.SetType("DDR5");
    ASSERT_EQ(ram.GetType(), "DDR5");
}

TEST_F(TestingRAM, TestGetType) {
    ASSERT_EQ(ram.GetType(), "DDR4");
}

TEST_F(TestingRAM, TestSetFrequency) {
    ASSERT_EQ(ram.GetFrequency(), 6000);
    ram.SetFrequency(5000);
    ASSERT_EQ(ram.GetFrequency(), 5000);
}

TEST_F(TestingRAM, TestGetFrequency) {
    ASSERT_EQ(ram.GetFrequency(), 6000);
}

TEST_F(TestingRAM, TestSetEnabled) {
    ram.SetEnabled(true);
    ASSERT_TRUE(ram.IsEnabled());
    ram.SetEnabled(false);
    ASSERT_FALSE(ram.IsEnabled());
}

TEST_F(TestingRAM, TestIsEnabled) {
    ASSERT_FALSE(ram.IsEnabled());
}

TEST_F(TestingRAM, TestRamStatusCorrect) {
    ram.SetEnabled(true);
    ASSERT_EQ(ram.RamStatus(), "RAM is working. Application data is collecting");
}

TEST_F(TestingRAM, TestRamStatusIncorrect) {
    ASSERT_THROW(ram.RamStatus(), ExceptionRAMStatusError);
}

TEST_F(TestingRAM, TestInstall) {
    ram.Install();
    ASSERT_TRUE(ram.IsInstaled());
}

TEST_F(TestingRAM, TestUninstall) {
    ram.Install();
    ASSERT_TRUE(ram.IsInstaled());
    ram.Uninstall();
    ASSERT_FALSE(ram.IsInstaled());
}

TEST_F(TestingRAM, TestIsInstaled) {
    ASSERT_FALSE(ram.IsInstaled());
    ram.Install();
    ASSERT_TRUE(ram.IsInstaled());
}

TEST(TestRAM, TestConstructor) {
    auto ram = RAM(64, "DDR5", 8000);
    ASSERT_EQ(ram.GetMemory(), 64);
    ASSERT_EQ(ram.GetType(), "DDR5");
    ASSERT_EQ(ram.GetFrequency(), 8000);
}
