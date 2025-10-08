#include "../Ports/HDMI/hdmi.h"
#include "../Display/display.h"
#include "../Microphone/microphone.h"
#include "gtest/gtest.h"

class TestingHDMI : public ::testing::Test {
protected:
    void SetUp() override {
        hdmi_port = HDMI();
        display = display = Display("1920x1080", 4.1,
                                    120, "1920x1080", 165, 21);
        microphone = Microphone();
    }

    HDMI hdmi_port;
    Display display;
    Microphone microphone;
};

TEST_F(TestingHDMI, TestConnectDeviceTrue) {
    ASSERT_TRUE(hdmi_port.ConnectDevice(display));
}

TEST_F(TestingHDMI, TestConnectDeviceFalse) {
    hdmi_port.ConnectDevice(display);
    ASSERT_FALSE(hdmi_port.ConnectDevice(display));
    hdmi_port.DisconnectDevice();
    ASSERT_FALSE(hdmi_port.ConnectDevice(microphone));
}

TEST_F(TestingHDMI, TestDisconnectDeviceTrue) {
    hdmi_port.ConnectDevice(display);
    ASSERT_TRUE(hdmi_port.DisconnectDevice());
}

TEST_F(TestingHDMI, TestDisconnectDeviceFalse) {
    ASSERT_FALSE(hdmi_port.DisconnectDevice());
}

TEST_F(TestingHDMI, TestIsOccupied) {
    hdmi_port.ConnectDevice(display);
    ASSERT_TRUE(hdmi_port.IsOccupied());
    hdmi_port.DisconnectDevice();
    ASSERT_FALSE(hdmi_port.IsOccupied());
}

TEST_F(TestingHDMI, TestCanAcceptTrue) {
    ASSERT_TRUE(hdmi_port.CanAccept(display));
}

TEST_F(TestingHDMI, TestCanAcceptFalse) {
    ASSERT_FALSE(hdmi_port.CanAccept(microphone));
}

TEST_F(TestingHDMI, TestGetType) {
    ASSERT_EQ(hdmi_port.GetType(), "HDMI");
}
