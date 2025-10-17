#include "artist_info_button.h"

ArtistInfoButton::ArtistInfoButton() = default;

ArtistInfoButton::~ArtistInfoButton() = default;

ArtistInfoButton::ArtistInfoButton(int width, int height) : width_(width), height_(height)
{
}

void ArtistInfoButton::SetWidth(int width)
{
    this->width_ = width;
}

int ArtistInfoButton::GetWidth() const
{
    return this->width_;
}

void ArtistInfoButton::SetHeight(int height)
{
    this->height_ = height;
}

int ArtistInfoButton::GetHeight() const
{
    return this->height_;
}

std::string ArtistInfoButton::GetArtistInfo(const Artist& artist) const
{
    return artist.GetArtistInfo();
}
