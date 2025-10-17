#include "volume_button.h"

VolumeButton::VolumeButton() = default;

VolumeButton::~VolumeButton() = default;

VolumeButton::VolumeButton(int width, int height) : width_(width), height_(height)
{
}

void VolumeButton::SetWidth(int width)
{
    this->width_ = width;
}

int VolumeButton::GetWidth() const
{
    return this->width_;
}

void VolumeButton::SetHeight(int height)
{
    this->height_ = height;
}

int VolumeButton::GetHeight() const
{
    return this->height_;
}

void VolumeButton::DisableVolume(int& volume)
{
    this->lastVolume_ = volume;
    volume = 0;
}

void VolumeButton::EnableVolume(int& volume)
{
    volume = lastVolume_;
}
