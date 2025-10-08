#include "../Ports/LineOut/lineout.h"
#include "../Speakers/speakers.h"
#include "gtest/gtest.h"

class TestingLineOut : public ::testing::Test {
protected:
    void SetUp() override {
        lineout_port = LineOut();
        speakers = Speakers(2, 70, 2.5, 14000);
    }

    LineOut lineout_port;
    Speakers speakers;
};

TEST_F(TestingLineOut, TestConnectDeviceTrue) {
    ASSERT_TRUE(lineout_port.ConnectDevice(speakers));
}

TEST_F(TestingLineOut, TestConnectDeviceFalse) {
    lineout_port.ConnectDevice(speakers);
    ASSERT_FALSE(lineout_port.ConnectDevice(speakers));
    lineout_port.DisconnectDevice();
    ASSERT_TRUE(lineout_port.ConnectDevice(speakers));
}

TEST_F(TestingLineOut, TestDisconnectDeviceTrue) {
    lineout_port.ConnectDevice(speakers);
    ASSERT_TRUE(lineout_port.DisconnectDevice());
}

TEST_F(TestingLineOut, TestDisconnectDeviceFalse) {
    ASSERT_FALSE(lineout_port.DisconnectDevice());
}

TEST_F(TestingLineOut, TestIsOccupied) {
    lineout_port.ConnectDevice(speakers);
    ASSERT_TRUE(lineout_port.IsOccupied());
    lineout_port.DisconnectDevice();
    ASSERT_FALSE(lineout_port.IsOccupied());
}

TEST_F(TestingLineOut, TestCanAcceptTrue) {
    ASSERT_TRUE(lineout_port.CanAccept(speakers));
}

TEST_F(TestingLineOut, TestGetType) {
    ASSERT_EQ(lineout_port.GetType(), "LineOut");
}

TEST_F(TestingLineOut, TestDetectSpeakersTrue) {
    lineout_port.ConnectDevice(speakers);
    ASSERT_EQ(lineout_port.DetectSpeakers(), "Speakers detected");
}

TEST_F(TestingLineOut, TestDetectSpeakersFalse) {
    ASSERT_EQ(lineout_port.DetectSpeakers(), "No speakers");
}
