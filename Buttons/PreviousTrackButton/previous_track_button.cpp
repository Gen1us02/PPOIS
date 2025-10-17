#include "previous_track_button.h"

PreviousTrackButton::PreviousTrackButton() = default;

PreviousTrackButton::~PreviousTrackButton() = default;

PreviousTrackButton::PreviousTrackButton(int width, int height) : width_(width), height_(height)
{
}

void PreviousTrackButton::SetWidth(int width)
{
    this->width_ = width;
}

int PreviousTrackButton::GetWidth() const
{
    return this->width_;
}

void PreviousTrackButton::SetHeight(int height)
{
    this->height_ = height;
}

int PreviousTrackButton::GetHeight() const
{
    return this->height_;
}

void PreviousTrackButton::GetPreviousTrackIndex(int &currentTrackIndex)
{
    currentTrackIndex -= 1;
}
