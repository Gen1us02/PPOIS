#ifndef CAMERA
#define CAMERA
#include <string>

class Camera{
public:
    virtual ~Camera() = default;
    virtual std::string MakeVideo(int seconds) = 0;
};

#endif