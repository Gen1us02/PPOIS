#ifndef VOLUME_BUTTON
#define VOLUME_BUTTON
#include "button.h"


class VolumeButton : public Button
{
public:
    VolumeButton();
    ~VolumeButton();
    VolumeButton(int width, int height);
    void SetWidth(int width) override;
    int GetWidth() const override;
    void SetHeight(int height) override;
    int GetHeight() const override;
    void DisableVolume(int& volume);
    void EnableVolume(int& volume);

private:
    int width_{0};
    int height_{0};
    int lastVolume_{0};
};


#endif
