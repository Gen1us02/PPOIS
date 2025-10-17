#include "next_track_button.h"

NextTrackButton::NextTrackButton() = default;

NextTrackButton::~NextTrackButton() = default;

NextTrackButton::NextTrackButton(int width, int height) : width_(width), height_(height)
{
}

void NextTrackButton::SetWidth(int width)
{
    this->width_ = width;
}

int NextTrackButton::GetWidth() const
{
    return this->width_;
}

void NextTrackButton::SetHeight(int height)
{
    this->height_ = height;
}

int NextTrackButton::GetHeight() const
{
    return this->height_;
}

void NextTrackButton::GetNextTrackIndex(int& currentTrackIndex)
{
    currentTrackIndex += 1;
}
