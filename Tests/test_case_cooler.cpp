#include "../Hardware/Coolers/CaseCooler/case_cooler.h"
#include "gtest/gtest.h"

class TestingCaseCooler : public ::testing::Test {
protected:
    void SetUp() override {
        case_cooler = CaseCooler(15, 120, "in");
    }

    CaseCooler case_cooler;
};

TEST_F(TestingCaseCooler, TestSetMinSpeed) {
    ASSERT_EQ(case_cooler.GetMinSpeed(), 15);
    case_cooler.SetMinSpeed(30);
    ASSERT_EQ(case_cooler.GetMinSpeed(), 30);
}

TEST_F(TestingCaseCooler, TestGetMinSpeed){
    ASSERT_EQ(case_cooler.GetMinSpeed(), 15);
}

TEST_F(TestingCaseCooler, TestSetMaxSpeed) {
    ASSERT_EQ(case_cooler.GetMaxSpeed(), 120);
    case_cooler.SetMaxSpeed(140);
    ASSERT_EQ(case_cooler.GetMaxSpeed(), 140);
}

TEST_F(TestingCaseCooler, TestGetMaxSpeed) {
    ASSERT_EQ(case_cooler.GetMaxSpeed(), 120);
}

TEST_F(TestingCaseCooler, TestSetSocket) {
    ASSERT_EQ(case_cooler.GetDirection(), "in");
    case_cooler.SetDirection("out");
    ASSERT_EQ(case_cooler.GetDirection(), "out");
}

TEST_F(TestingCaseCooler, TestGetSocket) {
    ASSERT_EQ(case_cooler.GetDirection(), "in");
}

TEST_F(TestingCaseCooler, TestGetType) {
    ASSERT_EQ(case_cooler.GetType(), "case");
}

TEST_F(TestingCaseCooler, TestSetCurrentSpeed) {
    ASSERT_EQ(case_cooler.SetCurrentSpeed(100), "Cooler speed 100 rpm");
    ASSERT_EQ(case_cooler.SetCurrentSpeed(200), "Incorrect speed");
}

TEST_F(TestingCaseCooler, TestInstall) {
    case_cooler.Install();
    ASSERT_TRUE(case_cooler.IsInstaled());
}

TEST_F(TestingCaseCooler, TestUninstall) {
    case_cooler.Install();
    ASSERT_TRUE(case_cooler.IsInstaled());
    case_cooler.Uninstall();
    ASSERT_FALSE(case_cooler.IsInstaled());
}

TEST_F(TestingCaseCooler, TestIsInstaled) {
    ASSERT_FALSE(case_cooler.IsInstaled());
    case_cooler.Install();
    ASSERT_TRUE(case_cooler.IsInstaled());
}

TEST(TestCaseCooler, TestConstructor) {
    auto case_cooler = CaseCooler(30, 160, "out");
    ASSERT_EQ(case_cooler.GetMinSpeed(), 30);
    ASSERT_EQ(case_cooler.GetMaxSpeed(), 160);
    ASSERT_EQ(case_cooler.GetType(), "case");
}