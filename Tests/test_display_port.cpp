#include "../Ports/DisplayPort/displayport.h"
#include "../Display/display.h"
#include "../Exceptions/exceptions.h"
#include "gtest/gtest.h"

class TestingDisplayPort : public ::testing::Test {
protected:
    void SetUp() override {
        display_port = DisplayPort();
        display = display = Display("1920x1080", 4.1,
                                    120, "1920x1080", 165, 21);
    }

    DisplayPort display_port;
    Display display;
};

TEST_F(TestingDisplayPort, TestConnectDeviceTrue) {
    ASSERT_TRUE(display_port.ConnectDevice(display));
}

TEST_F(TestingDisplayPort, TestConnectDeviceFalse) {
    display_port.ConnectDevice(display);
    ASSERT_THROW(display_port.ConnectDevice(display), ExceptionIsOccupiedError);
    display_port.DisconnectDevice();
    ASSERT_TRUE(display_port.ConnectDevice(display));
}

TEST_F(TestingDisplayPort, TestDisconnectDeviceTrue) {
    display_port.ConnectDevice(display);
    ASSERT_TRUE(display_port.DisconnectDevice());
}

TEST_F(TestingDisplayPort, TestDisconnectDeviceFalse) {
    ASSERT_THROW(display_port.DisconnectDevice(), ExceptionNotIsOccupiedError);
}

TEST_F(TestingDisplayPort, TestIsOccupied) {
    display_port.ConnectDevice(display);
    ASSERT_TRUE(display_port.IsOccupied());
    display_port.DisconnectDevice();
    ASSERT_FALSE(display_port.IsOccupied());
}

TEST_F(TestingDisplayPort, TestCanAcceptTrue) {
    ASSERT_TRUE(display_port.CanAccept(display));
}

TEST_F(TestingDisplayPort, TestGetType) {
    ASSERT_EQ(display_port.GetType(), "DisplayPort");
}
