#ifndef DISPLAY
#define DISPLAY
#include "output_device.h"
#include "webcamera.h"


class Display : public OutputDevice{
public:
    Display();
    Display(const std::string&, int, int, const std::string&, int, int);
    void SetResolution(const std::string&);
    std::string GetResolution() const;
    void SetRefreshRate(int);
    int GetRefreshRate() const;
    void SetDiagonal(int);
    int GetDiagonal() const;
    bool SupportsPort(PortType) const override;
    std::string DisplayInput(const InputDevice&)const override;
    std::string WebCameraVideo(int);
    std::string DisplaySettings() const;
private:
    WebCamera webcamera_;
    std::string resolution_ {""};
    int refreshRate_ {0};
    int diagonal_ {0};
    PortType portHDMI_ {PortType::HDMI};
};


#endif