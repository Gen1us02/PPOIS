#include "../Mouse/mouse.h"
#include "gtest/gtest.h"

class TestingMouse : public ::testing::Test {
protected:
    void SetUp() override {
        mouse = Mouse(100, 150, "lazer", 8000);
    }

    Mouse mouse;
};

TEST_F(TestingMouse, TestSetCursorX) {
    mouse.SetCursorX(200);
    ASSERT_EQ(mouse.GetCursorX(), 200);
}

TEST_F(TestingMouse, TestGetDynamicCount){
    ASSERT_EQ(mouse.GetCursorX(), 100);
}

TEST_F(TestingMouse, TestSetCursorY) {
    ASSERT_EQ(mouse.GetCursorY(), 150);
    mouse.SetCursorY(300);
    ASSERT_EQ(mouse.GetCursorY(), 300);
}

TEST_F(TestingMouse, TestGetCursorY) {
    ASSERT_EQ(mouse.GetCursorY(), 150);
}

TEST_F(TestingMouse, TestSetSensorType) {
    ASSERT_EQ(mouse.GetSensorType(), "lazer");
    mouse.SetSensorType("optical");
    ASSERT_EQ(mouse.GetSensorType(), "optical");
}

TEST_F(TestingMouse, TestGetSensorType) {
    ASSERT_EQ(mouse.GetSensorType(), "lazer");
}

TEST_F(TestingMouse, TestSetDpi) {
    ASSERT_EQ(mouse.GetDpi(), 8000);
    mouse.SetDpi(10000);
    ASSERT_EQ(mouse.GetDpi(), 10000);
}

TEST_F(TestingMouse, TestGetDpi) {
    ASSERT_EQ(mouse.GetDpi(), 8000);
}

TEST_F(TestingMouse, TestMoveCursor) {
    mouse.MoveCursor(150, 500);
    ASSERT_EQ(mouse.GetInput(), "x: 150 y: 500");
}

TEST_F(TestingMouse, TestConnect) {
    mouse.Connect();
    ASSERT_TRUE(mouse.IsConnected());
}

TEST_F(TestingMouse, TestDisconnect) {
    mouse.Connect();
    ASSERT_TRUE(mouse.IsConnected());
    mouse.Disconnect();
    ASSERT_FALSE(mouse.IsConnected());
}

TEST_F(TestingMouse, TestIsConnected) {
    ASSERT_FALSE(mouse.IsConnected());
    mouse.Connect();
    ASSERT_TRUE(mouse.IsConnected());
}

TEST_F(TestingMouse, TestSupportsPortTrue) {
    ASSERT_TRUE(mouse.SupportsPort(PortType::USB));
}

TEST_F(TestingMouse, TestSupportsPortFalse) {
    ASSERT_FALSE(mouse.SupportsPort(PortType::M2));
}

TEST(TestMouse, TestConstructor) {
    auto mouse = Mouse(300, 450, "optical", 12000);
    ASSERT_EQ(mouse.GetCursorX(), 300);
    ASSERT_EQ(mouse.GetCursorY(), 450);
    ASSERT_EQ(mouse.GetSensorType(), "optical");
    ASSERT_EQ(mouse.GetDpi(), 12000);
}