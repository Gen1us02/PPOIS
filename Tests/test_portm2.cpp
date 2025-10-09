#include "../Exceptions/exceptions.h"
#include "../Ports/PortM2/portm2.h"
#include "../Hardware/SSD/ssd.h"
#include "gtest/gtest.h"

class TestingM2 : public ::testing::Test {
protected:
    void SetUp() override {
        m2_port = PortM2();
        ssd = SSD();
    }

    PortM2 m2_port;
    SSD ssd;
};

TEST_F(TestingM2, TestConnectDeviceTrue) {
    ASSERT_TRUE(m2_port.ConnectDevice(ssd));
}

TEST_F(TestingM2, TestConnectDeviceFalse) {
    m2_port.ConnectDevice(ssd);
    ASSERT_THROW(m2_port.ConnectDevice(ssd), ExceptionIsOccupiedError);
    m2_port.DisconnectDevice();
    ASSERT_TRUE(m2_port.ConnectDevice(ssd));
}

TEST_F(TestingM2, TestDisconnectDeviceTrue) {
    m2_port.ConnectDevice(ssd);
    ASSERT_TRUE(m2_port.DisconnectDevice());
}

TEST_F(TestingM2, TestDisconnectDeviceFalse) {
    ASSERT_THROW(m2_port.DisconnectDevice(), ExceptionNotIsOccupiedError);
}

TEST_F(TestingM2, TestIsOccupied) {
    m2_port.ConnectDevice(ssd);
    ASSERT_TRUE(m2_port.IsOccupied());
    m2_port.DisconnectDevice();
    ASSERT_FALSE(m2_port.IsOccupied());
}

TEST_F(TestingM2, TestCanAcceptTrue) {
    ASSERT_TRUE(m2_port.CanAccept(ssd));
}

TEST_F(TestingM2, TestGetType) {
    ASSERT_EQ(m2_port.GetType(), "M2");
}
