#include "track.h"
#include <vector>
#include <cstring>
#include <chrono>
#include <iostream>
#include <thread>

Track::Track() = default;

Track::Track(const std::string& name, const std::string& text, int listenings, int duration, GenreType genre) :
    name_(name), text_(text),
    duration_(duration), listenings_(listenings), genre_(genre)
{
}

Track::~Track() = default;

void Track::SetName(const std::string& name)
{
    this->name_ = name;
}

std::string Track::GetName() const
{
    return this->name_;
}

void Track::SetText(const std::string& text)
{
    this->text_ = text;
}

std::string Track::GetText() const
{
    return this->text_;
}

void Track::SetListenings(int listenings)
{
    this->listenings_ = listenings;
}

int Track::GetListenings() const
{
    return this->listenings_;
}

void Track::SetDuration(int duration)
{
    this->duration_ = duration;
}

int Track::GetDuration() const
{
    return this->duration_;
}

void Track::MarkFavourite()
{
    this->isFavourite_ = true;
}

void Track::UnmarkFavourite()
{
    this->isFavourite_ = false;
}

bool Track::IsFavourite() const
{
    return this->isFavourite_;
}

void Track::SetGenreType(GenreType genre)
{
    this->genre_ = genre;
}

std::string Track::GetGenreType() const
{
    return GenreTypeToString(this->genre_);
}

void Track::Play()
{
    this->isPlaying_= true;
}

void Track::Pause()
{
    this->isPlaying_ = false;
}

bool Track::IsPlaying() const
{
    return this->isPlaying_;
}

