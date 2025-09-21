#ifndef CAMERA
#define CAMERA
#include <device.h>


class Camera: public Device{
private:
    std::string _max_resolution {"1920x1080"};
    double _megapixels {2.0};
    int _max_fps {30};
public:
    Camera();
    Camera(const std::string&, double, int);
    void set_max_resolution(const std::string&);
    std::string get_max_resolution() const;
    void set_megapixels(double);
    double get_megapixels() const;
    void set_max_fps(int);
    int get_max_fps() const;
    void Connect() override;
    void Disconnect() override;
    bool IsConnected() const override;
    void MakeVideo(int seconds);
};

#endif