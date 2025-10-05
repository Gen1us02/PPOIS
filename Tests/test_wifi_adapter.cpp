#include "../Adapters/WiFiAdapter/wifi_adapter.h"
#include "gtest/gtest.h"

class TestingWiFiAdapter : public ::testing::Test {
protected:
    void SetUp() override {
        wifiadapter = WiFiAdapter("USB2.0", 200, 2.4);
    }

    WiFiAdapter wifiadapter;
};

TEST_F(TestingWiFiAdapter, TestSetConnectionInterface) {
    ASSERT_EQ(wifiadapter.GetConnectionInterface(), "USB2.0");
    wifiadapter.SetConnectionInterface("USB3.0");
    ASSERT_EQ(wifiadapter.GetConnectionInterface(), "USB3.0");
}

TEST_F(TestingWiFiAdapter, TestGetConnectionInterface){
    ASSERT_EQ(wifiadapter.GetConnectionInterface(), "USB2.0");
}

TEST_F(TestingWiFiAdapter, TestSetSpeed) {
    ASSERT_EQ(wifiadapter.GetSpeed(), 200);
    wifiadapter.SetSpeed(433);
    ASSERT_EQ(wifiadapter.GetSpeed(), 433);
}

TEST_F(TestingWiFiAdapter, TestGetSpeed) {
    ASSERT_EQ(wifiadapter.GetSpeed(), 200);
}

TEST_F(TestingWiFiAdapter, TestSetFrequencyRange) {
    ASSERT_EQ(wifiadapter.GetFrequencyRange(), 2.4);
    wifiadapter.SetFrequencyRange(5.0);
    ASSERT_EQ(wifiadapter.GetFrequencyRange(), 5.0);
}

TEST_F(TestingWiFiAdapter, TestGetFrequencyRange) {
    ASSERT_EQ(wifiadapter.GetFrequencyRange(), 2.4);
}

TEST_F(TestingWiFiAdapter, TestConnectWiFi) {
    ASSERT_FALSE(wifiadapter.IsConnectWiFi());
    wifiadapter.ConnectWiFi();
    ASSERT_TRUE(wifiadapter.IsConnectWiFi());
}

TEST_F(TestingWiFiAdapter, TestDisconnectWiFi) {
    wifiadapter.ConnectWiFi();
    ASSERT_TRUE(wifiadapter.IsConnectWiFi());
    wifiadapter.DisconnectWiFi();
    ASSERT_FALSE(wifiadapter.IsConnectWiFi());
}

TEST_F(TestingWiFiAdapter, TestIsCisconnectWiFi) {
    ASSERT_FALSE(wifiadapter.IsConnectWiFi());
}

TEST_F(TestingWiFiAdapter, TestSupportsPortTrue) {
    ASSERT_TRUE(wifiadapter.SupportsPort(PortType::USB));
}

TEST_F(TestingWiFiAdapter, TestSupportsPortFalse) {
    ASSERT_FALSE(wifiadapter.SupportsPort(PortType::DisplayPort));
}

TEST_F(TestingWiFiAdapter, TestConnect) {
    ASSERT_FALSE(wifiadapter.IsConnected());
    wifiadapter.Connect();
    ASSERT_TRUE(wifiadapter.IsConnected());
}

TEST_F(TestingWiFiAdapter, TestDisconnect) {
    wifiadapter.Connect();
    ASSERT_TRUE(wifiadapter.IsConnected());
    wifiadapter.Disconnect();
    ASSERT_FALSE(wifiadapter.IsConnected());
}

TEST_F(TestingWiFiAdapter, TestIsConnected) {
    ASSERT_FALSE(wifiadapter.IsConnected());
}

TEST(TestWiFiAdapter, TestConstructor) {
    auto wifiadapter = WiFiAdapter("USB2.0", 433, 2.4);
    ASSERT_EQ(wifiadapter.GetConnectionInterface(), "USB2.0");
    ASSERT_EQ(wifiadapter.GetSpeed(), 433);
    ASSERT_EQ(wifiadapter.GetFrequencyRange(), 2.4);
}