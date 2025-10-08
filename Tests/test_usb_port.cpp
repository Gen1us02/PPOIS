#include "../Ports/USB/usb.h"
#include "../Mouse/mouse.h"
#include "../Microphone/microphone.h"
#include "gtest/gtest.h"

class TestingUSB : public ::testing::Test {
protected:
    void SetUp() override {
        usb_port = USB();
        mouse = Mouse();
        microphone = Microphone();
    }

    USB usb_port;
    Mouse mouse;
    Microphone microphone;
};

TEST_F(TestingUSB, TestConnectDeviceTrue) {
    ASSERT_TRUE(usb_port.ConnectDevice(mouse));
}

TEST_F(TestingUSB, TestConnectDeviceFalse) {
    usb_port.ConnectDevice(mouse);
    ASSERT_FALSE(usb_port.ConnectDevice(mouse));
    usb_port.DisconnectDevice();
    ASSERT_FALSE(usb_port.ConnectDevice(microphone));
}

TEST_F(TestingUSB, TestDisconnectDeviceTrue) {
    usb_port.ConnectDevice(mouse);
    ASSERT_TRUE(usb_port.DisconnectDevice());
}

TEST_F(TestingUSB, TestDisconnectDeviceFalse) {
    ASSERT_FALSE(usb_port.DisconnectDevice());
}

TEST_F(TestingUSB, TestIsOccupied) {
    usb_port.ConnectDevice(mouse);
    ASSERT_TRUE(usb_port.IsOccupied());
    usb_port.DisconnectDevice();
    ASSERT_FALSE(usb_port.IsOccupied());
}

TEST_F(TestingUSB, TestCanAcceptTrue) {
    ASSERT_TRUE(usb_port.CanAccept(mouse));
}

TEST_F(TestingUSB, TestCanAcceptFalse) {
    ASSERT_FALSE(usb_port.CanAccept(microphone));
}

TEST_F(TestingUSB, TestGetType) {
    ASSERT_EQ(usb_port.GetType(), "USB");
}
