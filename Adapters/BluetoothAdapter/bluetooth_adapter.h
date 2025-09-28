#ifndef BLUETOOTH_ADAPTER
#define BLUETOOTH_ADAPTER
#include <iostream>
#include "adapter.h"

class BluetoothAdapter : public Adapter{
public:
    BluetoothAdapter();
    BluetoothAdapter(const std::string&, int, int);
    void SetConnectionInterface(const std::string&) override;
    std::string GetConnectionInterface() const override;
    void SetSpeed(int) override;
    int GetSpeed() const override;
    void SetCoverageRadius(int);
    int GetCoverageRadius() const;
    void ConnectBluetooth();
    void DisconnectBluetooth();
    bool isConnectBluetooth() const;
private:
    std::string connectionInterface_ {""};
    int speed_ {0};
    int coverageRadius_ {0};
    bool isConnectBluetooth_ {false};
};

#endif