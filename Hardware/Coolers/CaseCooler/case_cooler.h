#ifndef CASECOOLER
#define CASECOOLER
#include "cooler.h"
#include "hardware.h"

class CaseCooler:public Cooler, public Hardware{
public:
    CaseCooler();
    CaseCooler(int, int, const std::string&);
    void SetMinSpeed(int) override;
    int GetMinSpeed() const override;
    void SetMaxSpeed(int) override;
    int GetMaxSpeed() const override;
    void SetDirection(const std::string&);
    std::string GetDirection() const;
    std::string GetType() const override;
private:
    int minSpeed_ {0};
    int maxSpeed_ {0};
    std::string type_ {"case"};
    std::string direction_ {""};
};

#endif