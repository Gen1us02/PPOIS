#include "bluetooth_adapter.h"

BluetoothAdapter::BluetoothAdapter() = default;

BluetoothAdapter::BluetoothAdapter(const std::string& connectionInterface, int speed, int coverageRadius):
connectionInterface_(connectionInterface), speed_(speed), coverageRadius_(coverageRadius){
    port_  = PortType::USB;
}

void BluetoothAdapter::SetConnectionInterface(const std::string& connectionInterface){
    this->connectionInterface_ = connectionInterface;
}

std::string BluetoothAdapter::GetConnectionInterface() const{
    return this->connectionInterface_;
}

void BluetoothAdapter::SetSpeed(int speed){
    this->speed_ = speed;
}

int BluetoothAdapter::GetSpeed() const{
    return this->speed_;
}

void BluetoothAdapter::SetCoverageRadius(int coverageRadius){
    this->coverageRadius_ = coverageRadius;
}

int BluetoothAdapter::GetCoverageRadius() const{
    return this->coverageRadius_;
}

void BluetoothAdapter::ConnectBluetooth(){
    this->isConnectBluetooth_ = true;
}

void BluetoothAdapter::DisconnectBluetooth(){
    this->isConnectBluetooth_ = false;
}

bool BluetoothAdapter::isConnectBluetooth() const{
    return this->isConnectBluetooth_;
}