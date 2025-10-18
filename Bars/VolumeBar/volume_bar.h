#ifndef VOLUME_BAR
#define VOLUME_BAR
#include "bar.h"
#include <string>
#include "../Exceptions/exceptions.h"


class VolumeBar : public Bar
{
public:
    VolumeBar();
    ~VolumeBar();
    explicit VolumeBar(int length);
    void SetLength(int length) override;
    int GetLength() const override;
    std::string SetVolume(int volume);

private:
    int length_{0};
    static constexpr int minVolume{0};
    static constexpr int maxVolume{100};
};


#endif
