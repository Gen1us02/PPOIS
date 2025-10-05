#include "wifi_adapter.h"

WiFiAdapter::WiFiAdapter() {
    port_ = PortType::USB;
};

WiFiAdapter::WiFiAdapter(const std::string& connectionInterface, int speed, double frequencyRange):
connectionInterface_(connectionInterface), speed_(speed), frequencyRange_(frequencyRange){
    port_  = PortType::USB;
}

void WiFiAdapter::SetConnectionInterface(const std::string& connectionInterface){
    this->connectionInterface_ = connectionInterface;
}

std::string WiFiAdapter::GetConnectionInterface() const{
    return this->connectionInterface_;
}

void WiFiAdapter::SetSpeed(int speed){
    this->speed_ = speed;
}

int WiFiAdapter::GetSpeed() const{
    return this->speed_;
}

void WiFiAdapter::SetFrequencyRange(double frequencyRange){
    this->frequencyRange_ = frequencyRange;
}

double WiFiAdapter::GetFrequencyRange() const{
    return this->frequencyRange_;
}

void WiFiAdapter::ConnectWiFi(){
    this->isConnectWiFi_ = true;
}

void WiFiAdapter::DisconnectWiFi(){
    this->isConnectWiFi_ = false;
}

bool WiFiAdapter::IsConnectWiFi() const{
    return this->isConnectWiFi_;
}