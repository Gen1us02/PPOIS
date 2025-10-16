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

//Вынести в кнопку запуска трека
// void Track::PlayTrack()
// {
//     std::vector<std::string> lines;
//     char* token = std::strtok(this->text_.data(), "\n");
//     while (token != nullptr)
//     {
//         lines.push_back(token);
//         token = std::strtok(nullptr, "\n");
//     }
//     //int lineDelay = static_cast<int>((this->duration_ / static_cast<double>(lines.size())) * 1000);
//     for (int i = 0; i < lines.size(); i++)
//     {
//         //int charDelay = static_cast<int>((lineDelay / static_cast<double>(lines[i].size())) * 1000);
//         for (int j = 0; j < lines[i].size(); j++)
//         {
//             std::cout << lines[i][j];
//             std::cout.flush();
//             std::this_thread::sleep_for(std::chrono::milliseconds(100));
//         }
//         std::cout << "\n";
//         std::this_thread::sleep_for(std::chrono::milliseconds(300));
//     }
// }

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
