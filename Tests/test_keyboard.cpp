#include "../Exceptions/exceptions.h"
#include "../KeyBoard/keyboard.h"
#include "gtest/gtest.h"

class TestingKeyBoard : public ::testing::Test {
protected:
    void SetUp() override {
        keyboard = KeyBoard("mechanic");
    }

    KeyBoard keyboard;
};

TEST_F(TestingKeyBoard, TestSetType) {
    ASSERT_EQ(keyboard.GetType(), "mechanic");
    keyboard.SetType("membranic");
    ASSERT_EQ(keyboard.GetType(), "membranic");
}

TEST_F(TestingKeyBoard, TestGetType) {
    ASSERT_EQ(keyboard.GetType(), "mechanic");
}

TEST_F(TestingKeyBoard, TestPressButtonCorrect) {
    ASSERT_THROW(keyboard.PressButton("g"), ExceptionConnection);
    keyboard.Connect();
    ASSERT_EQ(keyboard.PressButton("f"), "Button pressed f");
}

TEST_F(TestingKeyBoard, TestPressButtonIncorrect) {
    ASSERT_THROW(keyboard.PressButton("f"), ExceptionConnection);
    keyboard.Connect();
    ASSERT_THROW(keyboard.PressButton("fsj"), ExceptionManyKeysPressed);
}

TEST_F(TestingKeyBoard, TestSupportsPortCorrrect) {
    ASSERT_TRUE(keyboard.SupportsPort(PortType::USB));
}

TEST_F(TestingKeyBoard, TestSupportsPortIncorrect) {
    ASSERT_FALSE(keyboard.SupportsPort(PortType::DisplayPort));
}

TEST_F(TestingKeyBoard, TestConnect) {
    ASSERT_FALSE(keyboard.IsConnected());
    keyboard.Connect();
    ASSERT_TRUE(keyboard.IsConnected());
}

TEST_F(TestingKeyBoard, TestDisconnect) {
    keyboard.Connect();
    ASSERT_TRUE(keyboard.IsConnected());
    keyboard.Disconnect();
    ASSERT_FALSE(keyboard.IsConnected());
}

TEST(TestKeyBoard, TestConstructor) {
    auto keyboard = KeyBoard("mechanic");
    ASSERT_EQ(keyboard.GetType(), "mechanic");
}
