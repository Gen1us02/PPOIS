#ifndef DISPLAY
#define DISPLAY
#include "output_device.h"
#include "webcamera.h"


class Display : public OutputDevice{
public:
    Display();
    Display(const std::string&, int, int, const std::string&, int, int);
    void setResolution(const std::string&);
    std::string getResolution() const;
    void setRefreshRate(int);
    int getRefreshRate() const;
    void setDiagonal(int);
    int getDiagonal() const;
    std::string DisplayInput(const InputDevice&)const override;
    std::string WebCameraVideo(int);
    std::string DisplaySettings() const;
private:
    WebCamera webcamera_;
    std::string _resolution {"1920x1080"};
    int _refreshRate {60};
    int _diagonal {22};
};


#endif