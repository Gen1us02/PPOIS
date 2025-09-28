#ifndef WEBCAMERA
#define WEBCAMERA
#include "input_device.h"
#include "camera.h"


class WebCamera: public InputDevice, public Camera{
public:
    WebCamera();
    WebCamera(const std::string&, double, int);
    void SetMaxResolution(const std::string&);
    std::string GetMaxResolution() const;
    void SetMegapixels(double);
    double GetMegapixels() const;
    void SetMaxFps(int);
    int GetMaxFps() const;
    std::string MakeVideo(int seconds) override;
    void ReadInput(const std::string&);
private:
    std::string maxResolution_ {""};
    double megapixels_ {0.0};
    int maxFps_ {0};
};

#endif