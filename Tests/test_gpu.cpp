#include "../Hardware/GPU/gpu.h"
#include "gtest/gtest.h"

class TestingGPU : public ::testing::Test {
protected:
    void SetUp() override {
        gpu = GPU(15, 120, true, 12, 2);
    }

    GPU gpu;
};

TEST_F(TestingGPU, TestSetRtxSupport) {
    ASSERT_EQ(gpu.GetRtxSupport(), true);
    gpu.SetRtxSupport(false);
    ASSERT_EQ(gpu.GetRtxSupport(), false);
}

TEST_F(TestingGPU, TestGetRtxSupport){
    ASSERT_EQ(gpu.GetRtxSupport(), true);
}

TEST_F(TestingGPU, TestSetVideoMemory) {
    ASSERT_EQ(gpu.GetVideoMemory(), 12);
    gpu.SetVideoMemory(16);
    ASSERT_EQ(gpu.GetVideoMemory(), 16);
}

TEST_F(TestingGPU, TestGetVideoMemory) {
    ASSERT_EQ(gpu.GetVideoMemory(), 12);
}


TEST_F(TestingGPU, TestGetCoolersCount) {
    ASSERT_EQ(gpu.GetCoolerCount(), 2);
}

TEST_F(TestingGPU, TestSetCoolersCurrentSpeed) {
    ASSERT_EQ(gpu.SetCoolerCurrentSpeed(100), "Cooler speed 100 rpm");
    ASSERT_EQ(gpu.SetCoolerCurrentSpeed(250), "Incorrect speed");
}

TEST_F(TestingGPU, TestSetVsync) {
    ASSERT_EQ(gpu.SetVsync(true), "Vsync enabled");
    ASSERT_EQ(gpu.SetVsync(false), "Vsync disabled");
}

TEST_F(TestingGPU, TestSetDlssModeCorrect) {
    ASSERT_EQ(gpu.SetDlssMode("Balanced"), "DLSS mode is set to Balanced");
}

TEST_F(TestingGPU, TestSetDlssModeIncorrect) {
    ASSERT_EQ(gpu.SetDlssMode(""), "DLSS mode cannot be empty");
    ASSERT_EQ(gpu.SetDlssMode("agfafafs"), "Invalid DLSS mode. Valid modes: Ultra Performance, Performance, Balanced, Quality, Ultra Quality");
}

TEST_F(TestingGPU, TestInstall) {
    gpu.Install();
    ASSERT_TRUE(gpu.IsInstaled());
}

TEST_F(TestingGPU, TestUninstall) {
    gpu.Install();
    ASSERT_TRUE(gpu.IsInstaled());
    gpu.Uninstall();
    ASSERT_FALSE(gpu.IsInstaled());
}

TEST_F(TestingGPU, TestIsInstaled) {
    ASSERT_FALSE(gpu.IsInstaled());
    gpu.Install();
    ASSERT_TRUE(gpu.IsInstaled());
}

TEST(TestGPU, TestConstructor) {
    auto gpu = GPU(15, 120, true, 24, 3);
    ASSERT_EQ(gpu.GetRtxSupport(), true);
    ASSERT_EQ(gpu.GetVideoMemory(), 24);
    ASSERT_EQ(gpu.GetCoolerCount(), 3);
}