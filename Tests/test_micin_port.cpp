#include "../Exceptions/exceptions.h"
#include "../Ports/MicIn/micin.h"
#include "../Microphone/microphone.h"
#include "gtest/gtest.h"

class TestingMicIn : public ::testing::Test {
protected:
    void SetUp() override {
        micin_port = MicIn();
        microphone = Microphone("dynamic", 14000, 95);
    }

    MicIn micin_port;
    Microphone microphone;
};

TEST_F(TestingMicIn, TestConnectDeviceTrue) {
    ASSERT_TRUE(micin_port.ConnectDevice(microphone));
}

TEST_F(TestingMicIn, TestConnectDeviceFalse) {
    micin_port.ConnectDevice(microphone);
    ASSERT_THROW(micin_port.ConnectDevice(microphone), ExceptionIsOccupiedError);
    micin_port.DisconnectDevice();
    ASSERT_TRUE(micin_port.ConnectDevice(microphone));
}

TEST_F(TestingMicIn, TestDisconnectDeviceTrue) {
    micin_port.ConnectDevice(microphone);
    ASSERT_TRUE(micin_port.DisconnectDevice());
}

TEST_F(TestingMicIn, TestDisconnectDeviceFalse) {
    ASSERT_THROW(micin_port.DisconnectDevice(), ExceptionNotIsOccupiedError);
}

TEST_F(TestingMicIn, TestIsOccupied) {
    micin_port.ConnectDevice(microphone);
    ASSERT_TRUE(micin_port.IsOccupied());
    micin_port.DisconnectDevice();
    ASSERT_FALSE(micin_port.IsOccupied());
}

TEST_F(TestingMicIn, TestCanAcceptTrue) {
    ASSERT_TRUE(micin_port.CanAccept(microphone));
}

TEST_F(TestingMicIn, TestGetType) {
    ASSERT_EQ(micin_port.GetType(), "MicIn");
}

TEST_F(TestingMicIn, TestDetectMicrophoneTrue) {
    micin_port.ConnectDevice(microphone);
    ASSERT_EQ(micin_port.DetectMicriphone(), "Microphone detected");
}

TEST_F(TestingMicIn, TestDetectMicrophoneFalse) {
    ASSERT_EQ(micin_port.DetectMicriphone(), "No microphone");
}
