#include "track_text_button.h"

TrackTextButton::TrackTextButton() = default;

TrackTextButton::~TrackTextButton() = default;

TrackTextButton::TrackTextButton(int width, int height) : width_(width), height_(height)
{
}

void TrackTextButton::SetWidth(int width)
{
    this->width_ = width;
}

int TrackTextButton::GetWidth() const
{
    return this->width_;
}

void TrackTextButton::SetHeight(int height)
{
    this->height_ = height;
}

int TrackTextButton::GetHeight() const
{
    return this->height_;
}

std::string TrackTextButton::GetTrackText(const Track& track)
{
    return track.GetText();
}
