#include "../Adapters/BluetoothAdapter/bluetooth_adapter.h"
#include "gtest/gtest.h"

class TestingBluetoothAdapter : public ::testing::Test {
protected:
    void SetUp() override {
        bluetooth_adapter = BluetoothAdapter("USB2.0", 3, 100);
    }

    BluetoothAdapter bluetooth_adapter;
};

TEST_F(TestingBluetoothAdapter, TestConnectionInterface) {
    ASSERT_EQ(bluetooth_adapter.GetConnectionInterface(), "USB2.0");
    bluetooth_adapter.SetConnectionInterface("USB");
    ASSERT_EQ(bluetooth_adapter.GetConnectionInterface(), "USB");
}

TEST_F(TestingBluetoothAdapter, TestGetConnectionInterface){
    ASSERT_EQ(bluetooth_adapter.GetConnectionInterface(), "USB2.0");
}

TEST_F(TestingBluetoothAdapter, TestSetSpeed) {
    ASSERT_EQ(bluetooth_adapter.GetSpeed(), 3);
    bluetooth_adapter.SetSpeed(8);
    ASSERT_EQ(bluetooth_adapter.GetSpeed(), 8);
}

TEST_F(TestingBluetoothAdapter, TestGetSpeed) {
    ASSERT_EQ(bluetooth_adapter.GetSpeed(), 3);
}

TEST_F(TestingBluetoothAdapter, TestSetCoverageRadius) {
    ASSERT_EQ(bluetooth_adapter.GetCoverageRadius(), 100);
    bluetooth_adapter.SetCoverageRadius(50);
    ASSERT_EQ(bluetooth_adapter.GetCoverageRadius(), 50);
}

TEST_F(TestingBluetoothAdapter, TestGetCoverageRadius) {
    ASSERT_EQ(bluetooth_adapter.GetCoverageRadius(), 100);
}

TEST_F(TestingBluetoothAdapter, TestConnectBluetooth) {
    ASSERT_FALSE(bluetooth_adapter.IsConnectBluetooth());
    bluetooth_adapter.ConnectBluetooth();
    ASSERT_TRUE(bluetooth_adapter.IsConnectBluetooth());
}

TEST_F(TestingBluetoothAdapter, TestDisconnectBluetooth) {
    bluetooth_adapter.ConnectBluetooth();
    ASSERT_TRUE(bluetooth_adapter.IsConnectBluetooth());
    bluetooth_adapter.DisconnectBluetooth();
    ASSERT_FALSE(bluetooth_adapter.IsConnectBluetooth());
}

TEST_F(TestingBluetoothAdapter, TestIsCisconnectWiFi) {
    ASSERT_FALSE(bluetooth_adapter.IsConnectBluetooth());
}

TEST_F(TestingBluetoothAdapter, TestSupportsPortTrue) {
    ASSERT_TRUE(bluetooth_adapter.SupportsPort(PortType::USB));
}

TEST_F(TestingBluetoothAdapter, TestSupportsPortFalse) {
    ASSERT_FALSE(bluetooth_adapter.SupportsPort(PortType::DisplayPort));
}

TEST_F(TestingBluetoothAdapter, TestConnect) {
    ASSERT_FALSE(bluetooth_adapter.IsConnected());
    bluetooth_adapter.Connect();
    ASSERT_TRUE(bluetooth_adapter.IsConnected());
}

TEST_F(TestingBluetoothAdapter, TestDisconnect) {
    bluetooth_adapter.Connect();
    ASSERT_TRUE(bluetooth_adapter.IsConnected());
    bluetooth_adapter.Disconnect();
    ASSERT_FALSE(bluetooth_adapter.IsConnected());
}

TEST_F(TestingBluetoothAdapter, TestIsConnected) {
    ASSERT_FALSE(bluetooth_adapter.IsConnected());
}

TEST(TestBluetoothAdapter, TestConstructor) {
    auto bluetooth_adapter = BluetoothAdapter("USB2.0", 45, 30);
    ASSERT_EQ(bluetooth_adapter.GetConnectionInterface(), "USB2.0");
    ASSERT_EQ(bluetooth_adapter.GetSpeed(), 45);
    ASSERT_EQ(bluetooth_adapter.GetCoverageRadius(), 30);
}