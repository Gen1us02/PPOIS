#include "../Speakers/speakers.h"
#include "../Microphone/microphone.h"
#include "../Mouse/mouse.h"
#include "port_type.h"
#include "gtest/gtest.h"

class TestingSpeakers : public ::testing::Test {
protected:
    void SetUp() override {
        speakers = Speakers(2, 70, 2.5, 150);
        microphone = Microphone("dynamic", 14000, 95);
        microphone.Connect();
        mouse = Mouse();
    }

    Speakers speakers;
    Microphone microphone;
    Mouse mouse;
};

TEST_F(TestingSpeakers, TestSetDynamicCount) {
    ASSERT_EQ(2, speakers.GetDynamicCount());
    speakers.SetDynamicCount(5);
    ASSERT_EQ(5, speakers.GetDynamicCount());
}

TEST_F(TestingSpeakers, TestGetDynamicCount){
    ASSERT_EQ(2, speakers.GetDynamicCount());
}

TEST_F(TestingSpeakers, TestSetPower) {
    ASSERT_EQ(speakers.GetPower(), 70);
    speakers.SetPower(100);
    ASSERT_EQ(speakers.GetPower(), 100);
}

TEST_F(TestingSpeakers, TestGetPower) {
    ASSERT_EQ(speakers.GetPower(), 70);
}

TEST_F(TestingSpeakers, TestSetWeight) {
    speakers.SetWeight(1.5);
    ASSERT_EQ(speakers.GetWeight(), 1.5);
}

TEST_F(TestingSpeakers, TestGetWeight) {
    ASSERT_EQ(speakers.GetWeight(), 2.5);
}

TEST_F(TestingSpeakers, TestSetMaxRate) {
    speakers.SetMaxRate(100);
    ASSERT_EQ(100, speakers.GetMaxRate());
}

TEST_F(TestingSpeakers, TestGetMaxRate) {
    ASSERT_EQ(150, speakers.GetMaxRate());
}

TEST_F(TestingSpeakers, TestDisplayInputCorrect) {
    microphone.ReadSound();
    ASSERT_EQ("User volume:\nMicrophone read: dynamic freq=14000 snr=95", speakers.DisplayInput(microphone));
}

TEST_F(TestingSpeakers, TestDisplayInputIncorrect) {
    ASSERT_EQ("Device isn't microphone", speakers.DisplayInput(mouse));
}

TEST_F(TestingSpeakers, TestChangeVolumeCorrect) {
    ASSERT_EQ("Volume change on 50", speakers.ChangeVolume(50));
}

TEST_F(TestingSpeakers, TestChangeVolumeIncorrect) {
    ASSERT_EQ("Incorrect volume value", speakers.ChangeVolume(150));
}

TEST_F(TestingSpeakers, TestConnect) {
    speakers.Connect();
    ASSERT_TRUE(speakers.IsConnected());
}

TEST_F(TestingSpeakers, TestDisconnect) {
    speakers.Connect();
    ASSERT_TRUE(speakers.IsConnected());
    speakers.Disconnect();
    ASSERT_FALSE(speakers.IsConnected());
}

TEST_F(TestingSpeakers, TestIsConnected) {
    ASSERT_FALSE(speakers.IsConnected());
    speakers.Connect();
    ASSERT_TRUE(speakers.IsConnected());
}

TEST_F(TestingSpeakers, TestSupportsPortTrue) {
    ASSERT_TRUE(speakers.SupportsPort(PortType::LineOut));
}

TEST_F(TestingSpeakers, TestSupportsPortFalse) {
    ASSERT_FALSE(speakers.SupportsPort(PortType::M2));
}

TEST(TestSpeakers, TestConstructor) {
    auto speakers = Speakers(2, 70, 1.5, 250);
    ASSERT_EQ(speakers.GetDynamicCount(), 2);
    ASSERT_EQ(speakers.GetPower(), 70);
    ASSERT_EQ(speakers.GetWeight(), 1.5);
    ASSERT_EQ(speakers.GetMaxRate(), 250);
}