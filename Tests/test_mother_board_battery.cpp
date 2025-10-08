#include "../Hardware/MotherBoard/motherboard_battery.h"
#include "gtest/gtest.h"

class TestingMotherBoardBattery : public ::testing::Test {
protected:
    void SetUp() override {
        motherboard_battery = MotherBoardBattery(3, "lithium", 230);
    }

    MotherBoardBattery motherboard_battery;
};

TEST_F(TestingMotherBoardBattery, TestSetVoltage) {
    ASSERT_EQ(motherboard_battery.GetVoltage(), 3);
    motherboard_battery.SetVoltage(4);
    ASSERT_EQ(motherboard_battery.GetVoltage(), 4);
}

TEST_F(TestingMotherBoardBattery, TestGetVoltage) {
    ASSERT_EQ(motherboard_battery.GetVoltage(), 3);
}

TEST_F(TestingMotherBoardBattery, TestSetType) {
    ASSERT_EQ(motherboard_battery.GetType(), "lithium");
    motherboard_battery.SetType("alkaline");
    ASSERT_EQ(motherboard_battery.GetType(), "alkaline");
}

TEST_F(TestingMotherBoardBattery, TestGetType) {
    ASSERT_EQ(motherboard_battery.GetType(), "lithium");
}

TEST_F(TestingMotherBoardBattery, TestSetCapacity) {
    ASSERT_EQ(motherboard_battery.GetCapacity(), 230);
    motherboard_battery.SetCapacity(200);
    ASSERT_EQ(motherboard_battery.GetCapacity(), 200);
}

TEST_F(TestingMotherBoardBattery, TestGetCapacity) {
    ASSERT_EQ(motherboard_battery.GetCapacity(), 230);
}

TEST_F(TestingMotherBoardBattery, TestIsAlive) {
    ASSERT_TRUE(motherboard_battery.IsAlive());
    motherboard_battery.SetCapacity(0);
    ASSERT_FALSE(motherboard_battery.IsAlive());
}

TEST(TestMotherBoardBattery, TestConstructor) {
    auto motherboard_battery = MotherBoardBattery(4, "alkaline", 200);
    ASSERT_EQ(motherboard_battery.GetVoltage(), 4);
    ASSERT_EQ(motherboard_battery.GetType(), "alkaline");
    ASSERT_EQ(motherboard_battery.GetCapacity(), 200);
}
