#ifndef DISPLAY
#define DISPLAY
#include "output_device.h"


class Display : public Output_Device{
public:
    Display();
    Display(const std::string&, int, int);
    void setResolution(const std::string&);
    std::string getResolution() const;
    void setRefreshRate(int);
    int getRefreshRate() const;
    void setDiagonal(int);
    int getDiagonal() const;
    std::string displayInput(const Input_Device&)const override;
    std::string displaySettings() const;
private:
    std::string _resolution {"1920x1080"};
    int _refreshRate {60};
    int _diagonal {22};
};


#endif