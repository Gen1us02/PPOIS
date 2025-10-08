#include "../Hardware/Coolers/GPUCooler/gpu_cooler.h"
#include "gtest/gtest.h"

class TestingGPUCooler : public ::testing::Test {
protected:
    void SetUp() override {
        gpu_cooler = GPUCooler(15, 120);
    }

    GPUCooler gpu_cooler;
};

TEST_F(TestingGPUCooler, TestSetMinSpeed) {
    ASSERT_EQ(gpu_cooler.GetMinSpeed(), 15);
    gpu_cooler.SetMinSpeed(30);
    ASSERT_EQ(gpu_cooler.GetMinSpeed(), 30);
}

TEST_F(TestingGPUCooler, TestGetMinSpeed) {
    ASSERT_EQ(gpu_cooler.GetMinSpeed(), 15);
}

TEST_F(TestingGPUCooler, TestSetMaxSpeed) {
    ASSERT_EQ(gpu_cooler.GetMaxSpeed(), 120);
    gpu_cooler.SetMaxSpeed(140);
    ASSERT_EQ(gpu_cooler.GetMaxSpeed(), 140);
}

TEST_F(TestingGPUCooler, TestGetMaxSpeed) {
    ASSERT_EQ(gpu_cooler.GetMaxSpeed(), 120);
}

TEST_F(TestingGPUCooler, TestGetType) {
    ASSERT_EQ(gpu_cooler.GetType(), "gpu");
}

TEST_F(TestingGPUCooler, TestSetCurrentSpeed) {
    ASSERT_EQ(gpu_cooler.SetCurrentSpeed(100), "Cooler speed 100 rpm");
    ASSERT_EQ(gpu_cooler.SetCurrentSpeed(200), "Incorrect speed");
}

TEST_F(TestingGPUCooler, TestInstall) {
    gpu_cooler.Install();
    ASSERT_TRUE(gpu_cooler.IsInstaled());
}

TEST_F(TestingGPUCooler, TestUninstall) {
    gpu_cooler.Install();
    ASSERT_TRUE(gpu_cooler.IsInstaled());
    gpu_cooler.Uninstall();
    ASSERT_FALSE(gpu_cooler.IsInstaled());
}

TEST_F(TestingGPUCooler, TestIsInstaled) {
    ASSERT_FALSE(gpu_cooler.IsInstaled());
    gpu_cooler.Install();
    ASSERT_TRUE(gpu_cooler.IsInstaled());
}

TEST(TestGPUCooler, TestConstructor) {
    auto gpu_cooler = GPUCooler(30, 160);
    ASSERT_EQ(gpu_cooler.GetMinSpeed(), 30);
    ASSERT_EQ(gpu_cooler.GetMaxSpeed(), 160);
    ASSERT_EQ(gpu_cooler.GetType(), "gpu");
}
