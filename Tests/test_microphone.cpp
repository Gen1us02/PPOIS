#include "../Exceptions/exceptions.h"
#include "../Microphone/microphone.h"
#include "gtest/gtest.h"

class TestingMicrophone : public ::testing::Test {
protected:
    void SetUp() override {
        microphone = Microphone("dynamic", 14000, 80);
    }

    Microphone microphone;
};

TEST_F(TestingMicrophone, TestSetType) {
    ASSERT_EQ(microphone.GetType(), "dynamic");
    microphone.SetType("electret");
    ASSERT_EQ(microphone.GetType(), "electret");
}

TEST_F(TestingMicrophone, TestGetType) {
    ASSERT_EQ(microphone.GetType(), "dynamic");
}

TEST_F(TestingMicrophone, TestSetMaxFrequency) {
    ASSERT_EQ(microphone.GetMaxFrequency(), 14000);
    microphone.SetMaxFrequency(15000);
    ASSERT_EQ(microphone.GetMaxFrequency(), 15000);
}

TEST_F(TestingMicrophone, TestGetCursorY) {
    ASSERT_EQ(microphone.GetMaxFrequency(), 14000);
}

TEST_F(TestingMicrophone, TestSetSignalNoiseRatio) {
    ASSERT_EQ(microphone.GetSignalNoiseRatio(), 80);
    microphone.SetSignalNoiseRatio(90);
    ASSERT_EQ(microphone.GetSignalNoiseRatio(), 90);
}

TEST_F(TestingMicrophone, TestGetSignalNoiseRatio) {
    ASSERT_EQ(microphone.GetSignalNoiseRatio(), 80);
}

TEST_F(TestingMicrophone, TestMute) {
    ASSERT_FALSE(microphone.IsMuted());
    microphone.Mute();
    ASSERT_TRUE(microphone.IsMuted());
}

TEST_F(TestingMicrophone, TestUnmute) {
    microphone.Mute();
    ASSERT_TRUE(microphone.IsMuted());
    microphone.Unmute();
    ASSERT_FALSE(microphone.IsMuted());
}

TEST_F(TestingMicrophone, TestIsMuted) {
    ASSERT_FALSE(microphone.IsMuted());
}

TEST_F(TestingMicrophone, TestReadSoundCorrect) {
    microphone.Connect();
    ASSERT_EQ(microphone.ReadSound(), "Microphone read: dynamic freq=14000 snr=80");
}

TEST_F(TestingMicrophone, TestReadSoundIncorrect) {
    ASSERT_THROW(microphone.ReadSound(), ExceptionConnection);
}

TEST_F(TestingMicrophone, TestConnect) {
    microphone.Connect();
    ASSERT_TRUE(microphone.IsConnected());
}

TEST_F(TestingMicrophone, TestDisconnect) {
    microphone.Connect();
    ASSERT_TRUE(microphone.IsConnected());
    microphone.Disconnect();
    ASSERT_FALSE(microphone.IsConnected());
}

TEST_F(TestingMicrophone, TestIsConnected) {
    ASSERT_FALSE(microphone.IsConnected());
    microphone.Connect();
    ASSERT_TRUE(microphone.IsConnected());
}

TEST_F(TestingMicrophone, TestSupportsPortTrue) {
    ASSERT_TRUE(microphone.SupportsPort(PortType::MicIn));
}

TEST_F(TestingMicrophone, TestSupportsPortFalse) {
    ASSERT_FALSE(microphone.SupportsPort(PortType::M2));
}

TEST(TestMicrophone, TestConstructor) {
    auto microphone = Microphone("dynamic", 16000, 95);
    ASSERT_EQ(microphone.GetType(), "dynamic");
    ASSERT_EQ(microphone.GetMaxFrequency(), 16000);
    ASSERT_EQ(microphone.GetSignalNoiseRatio(), 95);
}
