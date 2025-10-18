#include "volume_bar.h"
#include <format>

VolumeBar::VolumeBar() = default;

VolumeBar::~VolumeBar() = default;

VolumeBar::VolumeBar(int length) : length_(length)
{
}

void VolumeBar::SetLength(int length)
{
    this->length_ = length;
}

int VolumeBar::GetLength() const
{
    return this->length_;
}

std::string VolumeBar::SetVolume(int volume)
{
    if (volume < minVolume || volume > maxVolume)
    {
        throw ExceptionIncorrectVolume("The volume is out of range.");
    }

    return std::format("Значение звука установлено на {}", volume);
}
