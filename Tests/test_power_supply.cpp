#include "../Exceptions/exceptions.h"
#include "../Hardware/PowerSupply/power_supply.h"
#include "gtest/gtest.h"

class TestingPowerSupply : public ::testing::Test {
protected:
    void SetUp() override {
        power_supply = PowerSupply(15, 120, 750, 87, 100, 240);
    }

    PowerSupply power_supply;
};

TEST_F(TestingPowerSupply, TestSetPower) {
    ASSERT_EQ(power_supply.GetPower(), 750);
    power_supply.SetPower(800);
    ASSERT_EQ(power_supply.GetPower(), 800);
}

TEST_F(TestingPowerSupply, TestGetDynamicCount) {
    ASSERT_EQ(power_supply.GetPower(), 750);
}

TEST_F(TestingPowerSupply, TestSetEfficiency) {
    ASSERT_EQ(power_supply.GetEfficiency(), 87);
    power_supply.SetEfficiency(90);
    ASSERT_EQ(power_supply.GetEfficiency(), 90);
}

TEST_F(TestingPowerSupply, TestGetEfficiency) {
    ASSERT_EQ(power_supply.GetEfficiency(), 87);
}

TEST_F(TestingPowerSupply, TestSetMinVoltage) {
    ASSERT_EQ(power_supply.GetMinVoltage(), 100);
    power_supply.SetMinVoltage(200);
    ASSERT_EQ(power_supply.GetMinVoltage(), 200);
}

TEST_F(TestingPowerSupply, TestGetMinVoltage) {
    ASSERT_EQ(power_supply.GetMinVoltage(), 100);
}

TEST_F(TestingPowerSupply, TestSetMaxVoltage) {
    ASSERT_EQ(power_supply.GetMaxVoltage(), 240);
    power_supply.SetMaxVoltage(280);
    ASSERT_EQ(power_supply.GetMaxVoltage(), 280);
}

TEST_F(TestingPowerSupply, TestGetMaxVoltage) {
    ASSERT_EQ(power_supply.GetMaxVoltage(), 240);
}

TEST_F(TestingPowerSupply, TestSetCoolerCurrentSpeedCorrect) {
    ASSERT_EQ(power_supply.SetCoolerCurrentSpeed(100), "Cooler speed 100 rpm");
}

TEST_F(TestingPowerSupply, TestSetCoolerCurrentSpeedIncorrect) {
    ASSERT_EQ(power_supply.SetCoolerCurrentSpeed(200), "Incorrect speed");
}

TEST_F(TestingPowerSupply, TestVoltageMessageCorrect) {
    ASSERT_EQ(power_supply.VoltageSupplyMessage(150), "The power supply is connected to the mains with voltage 150");
}

TEST_F(TestingPowerSupply, TestVoltageMessageIncorrect) {
    ASSERT_THROW(power_supply.VoltageSupplyMessage(280), ExceptionIncorrectVoltage);
}

TEST_F(TestingPowerSupply, TestInstall) {
    power_supply.Install();
    ASSERT_TRUE(power_supply.IsInstaled());
}

TEST_F(TestingPowerSupply, TestUninstall) {
    power_supply.Install();
    ASSERT_TRUE(power_supply.IsInstaled());
    power_supply.Uninstall();
    ASSERT_FALSE(power_supply.IsInstaled());
}

TEST_F(TestingPowerSupply, TestIsInstaled) {
    ASSERT_FALSE(power_supply.IsInstaled());
    power_supply.Install();
    ASSERT_TRUE(power_supply.IsInstaled());
}

TEST(TestPowerSupply, TestConstructor) {
    auto power_supply = PowerSupply(15, 120, 800, 80, 100, 240);
    ASSERT_EQ(power_supply.GetPower(), 800);
    ASSERT_EQ(power_supply.GetEfficiency(), 80);
    ASSERT_EQ(power_supply.GetMinVoltage(), 100);
    ASSERT_EQ(power_supply.GetMaxVoltage(), 240);
}
