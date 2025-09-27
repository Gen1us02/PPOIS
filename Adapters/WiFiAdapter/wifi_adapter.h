#ifndef WIFIADAPTER
#define WIFIADAPTER
#include <iostream>
#include "adapter.h"

class WiFiAdapter : public Adapter{
public:
    WiFiAdapter();
    WiFiAdapter(const std::string&, int, double);
    void SetConnectionInterface(const std::string&) override;
    std::string GetConnectionInterface() const;
    void SetSpeed(int);
    int GetSpeed() const;
    void SetFrequencyRange(double);
    double GetFrequencyRange() const;
    bool IsConnectWiFi() const;
    void ConnectWiFi();
    void DisconnectWiFi();
private:
    std::string connectionInterface_ {""};
    int speed_ {0};
    double frequencyRange_ {0};
    bool isConnectWiFi_ {false};
};

#endif