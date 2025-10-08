#include "../Hardware/SSD/ssd.h"
#include "gtest/gtest.h"

class TestingSSD : public ::testing::Test {
protected:
    void SetUp() override {
        ssd = SSD(1024, 14000, 13000, 2000000);
    }

    SSD ssd;
};

TEST_F(TestingSSD, TestSetMemorySize) {
    ASSERT_EQ(ssd.GetMemorySize(), 1024);
    ssd.SetMemorySize(2048);
    ASSERT_EQ(ssd.GetMemorySize(), 2048);
}

TEST_F(TestingSSD, TestGetMemorySize) {
    ASSERT_EQ(ssd.GetMemorySize(), 1024);
}

TEST_F(TestingSSD, TestSetReadSpeed) {
    ASSERT_EQ(ssd.GetReadSpeed(), 14000);
    ssd.SetReadSpeed(16000);
    ASSERT_EQ(ssd.GetReadSpeed(), 16000);
}

TEST_F(TestingSSD, TestGetPower) {
    ASSERT_EQ(ssd.GetReadSpeed(), 14000);
}

TEST_F(TestingSSD, TestSetWriteSpeed) {
    ASSERT_EQ(ssd.GetWriteSpeed(), 13000);
    ssd.SetWriteSpeed(15000);
    ASSERT_EQ(ssd.GetWriteSpeed(), 15000);
}

TEST_F(TestingSSD, TestGetWriteSpeed) {
    ASSERT_EQ(ssd.GetWriteSpeed(), 13000);
}

TEST_F(TestingSSD, TestSetTimeBeforeBreak) {
    ASSERT_EQ(ssd.GetTimeBeforeBreak(), 2000000);
    ssd.SetTimeBeforeBreak(1000000);
    ASSERT_EQ(ssd.GetTimeBeforeBreak(), 1000000);
}

TEST_F(TestingSSD, TestGetTimeBeforeBreak) {
    ASSERT_EQ(ssd.GetTimeBeforeBreak(), 2000000);
}

TEST_F(TestingSSD, TestSupportsPortTrue) {
    ASSERT_TRUE(ssd.SupportsPort(PortType::M2));
}

TEST_F(TestingSSD, TestSupportsPortFalse) {
    ASSERT_FALSE(ssd.SupportsPort(PortType::DisplayPort));
}

TEST_F(TestingSSD, TestWriteTime) {
    ASSERT_EQ(ssd.WriteTime(26000), 2.0);
}

TEST_F(TestingSSD, TestReadTime) {
    ASSERT_EQ(ssd.ReadTime(56000), 4.0);
}

TEST_F(TestingSSD, TestInstall) {
    ssd.Install();
    ASSERT_TRUE(ssd.IsInstaled());
}

TEST_F(TestingSSD, TestWriteData) {
    ssd.WriteData("data");
    ASSERT_EQ(ssd.ReadData(), "data\n");
}

TEST_F(TestingSSD, TestClearData) {
    ssd.WriteData("data");
    ASSERT_EQ(ssd.ReadData(), "data\n");
    ssd.ClearData();
    ASSERT_EQ(ssd.ReadData(), "");
}

TEST_F(TestingSSD, TestUninstall) {
    ssd.Install();
    ASSERT_TRUE(ssd.IsInstaled());
    ssd.Uninstall();
    ASSERT_FALSE(ssd.IsInstaled());
}

TEST_F(TestingSSD, TestIsInstaled) {
    ASSERT_FALSE(ssd.IsInstaled());
    ssd.Install();
    ASSERT_TRUE(ssd.IsInstaled());
}

TEST(TestSSD, TestConstructor) {
    auto ssd = SSD(2048, 16000, 18000, 2500000);
    ASSERT_EQ(ssd.GetMemorySize(), 2048);
    ASSERT_EQ(ssd.GetReadSpeed(), 16000);
    ASSERT_EQ(ssd.GetWriteSpeed(), 18000);
    ASSERT_EQ(ssd.GetTimeBeforeBreak(), 2500000);
}
