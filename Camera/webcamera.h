#ifndef WEBCAMERA
#define WEBCAMERA
#include "input_device.h"
#include "camera.h"


class WebCamera: public Input_Device, public Camera{
public:
    WebCamera();
    WebCamera(const std::string&, double, int);
    void set_max_resolution(const std::string&);
    std::string get_max_resolution() const;
    void set_megapixels(double);
    double get_megapixels() const;
    void set_max_fps(int);
    int get_max_fps() const;
    std::string MakeVideo(int seconds) override;
    void readInput(const std::string&);
private:
    std::string _max_resolution {"1920x1080"};
    double _megapixels {2.0};
    int _max_fps {30};
};

#endif