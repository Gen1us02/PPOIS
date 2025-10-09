#include "../Exceptions/exceptions.h"
#include "../Hardware/Coolers/PowerSupplyCooler/power_supply_cooler.h"
#include "gtest/gtest.h"

class TestingPowerSupplyCooler : public ::testing::Test {
protected:
    void SetUp() override {
        power_supply_cooler = PowerSupplyCooler(15, 120);
    }

    PowerSupplyCooler power_supply_cooler;
};

TEST_F(TestingPowerSupplyCooler, TestSetMinSpeed) {
    ASSERT_EQ(power_supply_cooler.GetMinSpeed(), 15);
    power_supply_cooler.SetMinSpeed(30);
    ASSERT_EQ(power_supply_cooler.GetMinSpeed(), 30);
}

TEST_F(TestingPowerSupplyCooler, TestGetMinSpeed) {
    ASSERT_EQ(power_supply_cooler.GetMinSpeed(), 15);
}

TEST_F(TestingPowerSupplyCooler, TestSetMaxSpeed) {
    ASSERT_EQ(power_supply_cooler.GetMaxSpeed(), 120);
    power_supply_cooler.SetMaxSpeed(140);
    ASSERT_EQ(power_supply_cooler.GetMaxSpeed(), 140);
}

TEST_F(TestingPowerSupplyCooler, TestGetMaxSpeed) {
    ASSERT_EQ(power_supply_cooler.GetMaxSpeed(), 120);
}

TEST_F(TestingPowerSupplyCooler, TestGetType) {
    ASSERT_EQ(power_supply_cooler.GetType(), "psu");
}

TEST_F(TestingPowerSupplyCooler, TestSetCurrentSpeed) {
    ASSERT_EQ(power_supply_cooler.SetCurrentSpeed(100), "Cooler speed 100 rpm");
    ASSERT_THROW(power_supply_cooler.SetCurrentSpeed(200), ExceptionIncorrectSpeed);
}

TEST_F(TestingPowerSupplyCooler, TestInstall) {
    power_supply_cooler.Install();
    ASSERT_TRUE(power_supply_cooler.IsInstaled());
}

TEST_F(TestingPowerSupplyCooler, TestUninstall) {
    power_supply_cooler.Install();
    ASSERT_TRUE(power_supply_cooler.IsInstaled());
    power_supply_cooler.Uninstall();
    ASSERT_FALSE(power_supply_cooler.IsInstaled());
}

TEST_F(TestingPowerSupplyCooler, TestIsInstaled) {
    ASSERT_FALSE(power_supply_cooler.IsInstaled());
    power_supply_cooler.Install();
    ASSERT_TRUE(power_supply_cooler.IsInstaled());
}

TEST(TestPowerSupplyCooler, TestConstructor) {
    auto power_supply_cooler = PowerSupplyCooler(40, 150);
    ASSERT_EQ(power_supply_cooler.GetMinSpeed(), 40);
    ASSERT_EQ(power_supply_cooler.GetMaxSpeed(), 150);
    ASSERT_EQ(power_supply_cooler.GetType(), "psu");
}
