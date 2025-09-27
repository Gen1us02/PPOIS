#ifndef MOTHERBOARDBATTERY
#define MOTHERBOARDBATTERY
#include "battery.h"

class MotherBoardBattery : public Battery{
public:
    MotherBoardBattery();
    MotherBoardBattery(int, const std::string&, int);
    void SetVoltage(int) override;
    int GetVoltage() const override;
    void SetType(const std::string&) override;
    std::string GetType() const override;
    void SetCapacity(int);
    int GetCapacity() const;
    bool IsAlive() const;
private:
    int voltage_ {0};
    std::string type_ {""};
    int capacity_ {0};
};


#endif