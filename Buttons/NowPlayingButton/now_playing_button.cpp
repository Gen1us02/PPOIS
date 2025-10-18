#include "now_playing_button.h"

NowPlayingButton::NowPlayingButton() = default;

NowPlayingButton::~NowPlayingButton() = default;

NowPlayingButton::NowPlayingButton(int width, int height) : width_(width), height_(height)
{
}

void NowPlayingButton::SetWidth(int width)
{
    this->width_ = width;
}

int NowPlayingButton::GetWidth() const
{
    return this->width_;
}

void NowPlayingButton::SetHeight(int height)
{
    this->height_ = height;
}

int NowPlayingButton::GetHeight() const
{
    return this->height_;
}

std::string NowPlayingButton::ShowNowPlayingTrackInfo(const Track& track) const
{
    return track.GetName() + "\n" + track.GetArtistPseudonym();
}
