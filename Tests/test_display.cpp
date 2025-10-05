#include "../Display/display.h"
#include "../Microphone/microphone.h"
#include "../Mouse/mouse.h"
#include "gtest/gtest.h"

class TestingDisplay : public ::testing::Test {
protected:
    void SetUp() override {
        display = Display("1920x1080", 4.1,
            120, "1920x1080", 165, 21);
        mouse = Mouse(100, 150, "lazer", 8000);
    }

    Display display;
    Mouse mouse;
};

TEST_F(TestingDisplay, TestSetResolution) {
    ASSERT_EQ(display.GetResolution(), "1920x1080");
    display.SetResolution("2560x1440");
    ASSERT_EQ(display.GetResolution(), "2560x1440");
}

TEST_F(TestingDisplay, TestGetType){
    ASSERT_EQ(display.GetResolution(), "1920x1080");
}

TEST_F(TestingDisplay, TestSetRefreshRate) {
    ASSERT_EQ(display.GetRefreshRate(), 165);
    display.SetRefreshRate(240);
    ASSERT_EQ(display.GetRefreshRate(), 240);
}

TEST_F(TestingDisplay, TestGetRefreshRate) {
    ASSERT_EQ(display.GetRefreshRate(), 165);
}

TEST_F(TestingDisplay, TestSetDiagonal) {
    ASSERT_EQ(display.GetDiagonal(), 21);
    display.SetDiagonal(27);
    ASSERT_EQ(display.GetDiagonal(), 27);
}

TEST_F(TestingDisplay, TestGetDiagonal) {
    ASSERT_EQ(display.GetDiagonal(), 21);
}

TEST_F(TestingDisplay, TestSupportsPortTrue) {
    ASSERT_TRUE(display.SupportsPort(PortType::DisplayPort));
    ASSERT_TRUE(display.SupportsPort(PortType::HDMI));
}

TEST_F(TestingDisplay, TestSupportsPortFalse) {
    ASSERT_FALSE(display.SupportsPort(PortType::USB));
}
TEST_F(TestingDisplay, TestDisplayInputCorrect) {
    mouse.MoveCursor(500, 400);
    ASSERT_EQ(display.DisplayInput(mouse), "User input:\nx: 500 y: 400");
}

TEST_F(TestingDisplay, TestDisplayInputIncorrrect) {
    auto microphone = Microphone();
    ASSERT_EQ(display.DisplayInput(microphone), "Device is not keyboard or mouse");
}

TEST_F(TestingDisplay, TestWebCameraVideo) {
    ASSERT_EQ(display.WebCameraVideo(10), "Record stopped: 1200 frames.\nresolution=1920x1080 | mp=4.1 | fps=120");
}

TEST_F(TestingDisplay, TestDisplaySettings) {
    ASSERT_EQ(display.DisplaySettings(), "Display settings: \nResolution: 1920x1080\nRefresh rate: 165\n""Display diagonal: 21");
}

TEST_F(TestingDisplay, TestConnect) {
    ASSERT_FALSE(display.IsConnected());
    display.Connect();
    ASSERT_TRUE(display.IsConnected());
}

TEST_F(TestingDisplay, TestDisconnect) {
    display.Connect();
    ASSERT_TRUE(display.IsConnected());
    display.Disconnect();
    ASSERT_FALSE(display.IsConnected());
}

TEST_F(TestingDisplay, TestIsConnected) {
    ASSERT_FALSE(display.IsConnected());
}

TEST_F(TestingDisplay, TestConnectCamera){
    ASSERT_TRUE(display.IsCameraConnected());
}

TEST_F(TestingDisplay, TestDisconnectCamera){
    display.DisconnectCamera();
    ASSERT_FALSE(display.IsCameraConnected());
}

TEST(TestDisplay, TestConstructor) {
    auto display = Display("1920x1080", 4.1,
            120, "1920x1080", 144, 18);
    ASSERT_EQ(display.GetResolution(), "1920x1080");
    ASSERT_EQ(display.GetRefreshRate(), 144);
    ASSERT_EQ(display.GetDiagonal(), 18);
}