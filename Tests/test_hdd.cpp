#include "../Hardware/HDD/hdd.h"
#include "gtest/gtest.h"

class TestingHDD : public ::testing::Test {
protected:
    void SetUp() override {
        hdd = HDD(1024, 5400, "CMR");
    }

    HDD hdd;
};

TEST_F(TestingHDD, TestSetMemorySize) {
    ASSERT_EQ(hdd.GetMemorySize(), 1024);
    hdd.SetMemorySize(2048);
    ASSERT_EQ(hdd.GetMemorySize(), 2048);
}

TEST_F(TestingHDD, TestGetMemorySize){
    ASSERT_EQ(hdd.GetMemorySize(), 1024);
}

TEST_F(TestingHDD, TestSetSpindleSpeed) {
    ASSERT_EQ(hdd.GetSpindleSpeed(), 5400);
    hdd.SetSpindleSpeed(6000);
    ASSERT_EQ(hdd.GetSpindleSpeed(), 6000);
}

TEST_F(TestingHDD, TestGetSpindleSpeed) {
    ASSERT_EQ(hdd.GetSpindleSpeed(), 5400);
}

TEST_F(TestingHDD, TestSetRecordTechnolgy) {
    ASSERT_EQ(hdd.GetRecordTechnology(), "CMR");
    hdd.SetRecordTechnology("SMR");
    ASSERT_EQ(hdd.GetRecordTechnology(), "SMR");
}

TEST_F(TestingHDD, TestGetRecordtechnology) {
    ASSERT_EQ(hdd.GetRecordTechnology(), "CMR");
}

TEST_F(TestingHDD, TestInstall) {
    hdd.Install();
    ASSERT_TRUE(hdd.IsInstaled());
}

TEST_F(TestingHDD, TestWriteData) {
    hdd.WriteData("data");
    ASSERT_EQ(hdd.ReadData(), "data\n");
}

TEST_F(TestingHDD, TestClearData) {
    hdd.WriteData("data");
    ASSERT_EQ(hdd.ReadData(), "data\n");
    hdd.ClearData();
    ASSERT_EQ(hdd.ReadData(), "");
}

TEST_F(TestingHDD, TestUninstall) {
    hdd.Install();
    ASSERT_TRUE(hdd.IsInstaled());
    hdd.Uninstall();
    ASSERT_FALSE(hdd.IsInstaled());
}

TEST_F(TestingHDD, TestIsInstaled) {
    ASSERT_FALSE(hdd.IsInstaled());
    hdd.Install();
    ASSERT_TRUE(hdd.IsInstaled());
}

TEST(TestHDD, TestConstructor) {
    auto hdd = HDD(4096, 6400, "SMR");
    ASSERT_EQ(hdd.GetMemorySize(), 4096);
    ASSERT_EQ(hdd.GetSpindleSpeed(), 6400);
    ASSERT_EQ(hdd.GetRecordTechnology(), "SMR");
}