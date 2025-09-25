#ifndef CAMERA
#define CAMERA
#include <string>

class Camera{
public:
    virtual ~Camera();
    virtual std::string MakeVideo(int seconds) = 0;
};

#endif