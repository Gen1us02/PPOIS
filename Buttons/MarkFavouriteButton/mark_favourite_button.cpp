#include "mark_favourite_button.h"
#include <iostream>

MarkFavouriteButton::MarkFavouriteButton() = default;

MarkFavouriteButton::~MarkFavouriteButton() = default;

MarkFavouriteButton::MarkFavouriteButton(int width, int height) : width_(width), height_(height)
{
}

void MarkFavouriteButton::SetWidth(int width)
{
    this->width_ = width;
}

int MarkFavouriteButton::GetWidth() const
{
    return this->width_;
}

void MarkFavouriteButton::SetHeight(int height)
{
    this->height_ = height;
}

int MarkFavouriteButton::GetHeight() const
{
    return this->height_;
}

void MarkFavouriteButton::MarkFavourite(Track& track, FavouritePlaylist& playlist)
{
    try
    {
        track.MarkFavourite();
        playlist.AddTrack(track);
    }
    catch (const ExceptionIncorrectTrack& ex)
    {
        std::string errorMessage = "Mark failed: ";
        errorMessage += ex.what();
        throw ExceptionMarkFailed(errorMessage.c_str());
    }
}

void MarkFavouriteButton::UnmarkFavourite(Track& track, FavouritePlaylist& playlist)
{
    try
    {
        playlist.RemoveTrack(track);
        track.UnmarkFavourite();
    }
    catch (const ExceptionIncorrectTrack& ex)
    {
        std::string errorMessage = "Unmark failed: ";
        errorMessage += ex.what();
        throw ExceptionUnmarkFailed(errorMessage.c_str());
    }
}
