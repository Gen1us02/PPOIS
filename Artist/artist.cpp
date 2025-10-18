#include "artist.h"
#include <format>

#include "album_type.h"
#include "../Utils/utils.h"

Artist::Artist() = default;

Artist::Artist(const std::string& name, int age, int listeners, const std::string& pseudonym) : name_(name), age_(age),
    listeners_(listeners),
    pseudonym_(pseudonym)
{
}

Artist::~Artist() = default;

void Artist::SetName(const std::string& name)
{
    this->name_ = name;
}

std::string Artist::GetName() const
{
    return this->name_;
}

void Artist::SetAge(int age)
{
    this->age_ = age;
}

int Artist::GetAge() const
{
    return this->age_;
}

void Artist::SetListeners(int listeners)
{
    this->listeners_ = listeners;
}

int Artist::GetListeners() const
{
    return this->listeners_;
}

void Artist::SetPseudonym(const std::string& pseudonym)
{
    this->pseudonym_ = pseudonym;
}

std::string Artist::GetPseudonym() const
{
    return this->pseudonym_;
}

std::string Artist::GetArtistInfo() const
{
    return std::format("Имя: {}\nВозраст: {}\nСлушателей в месяц: {}\nПсевдоним: {}", this->name_, this->age_,
                       this->listeners_, this->pseudonym_);
}

std::string Artist::GetTrackList() const
{
    std::string result;
    for (int i = 0; i < this->tracks_.size(); i++)
    {
        result += tracks_[i].GetName() + "\n";
    }

    return result;
}

std::string Artist::GetAlbumList() const
{
    std::string result;
    for (int i = 0; i < this->albums_.size(); i++)
    {
        result += albums_[i]->GetTitle() + "\n";
    }

    return result;
}

std::string Artist::RealeseTrack(const std::string& name, const std::string& text, int duration, GenreType genre)
{
    for (const auto& track : this->tracks_)
    {
        if (track.GetName() == name)
        {
            throw ExceptionTrackReleased("This track is already released");
        }
    }

    auto track = Track(name, text, 0, this->pseudonym_, duration, genre);
    this->tracks_.push_back(track);
    return std::format("Исполнитель {}, выпустил трек {}", this->pseudonym_, name);
}

void Artist::AddTrackToAlbum(const std::string& albumTitle, const std::string& trackName)
{
    int trackIndex = -1;
    int albumIndex = -1;
    for (int i = 0; i < this->tracks_.size(); i++)
    {
        if (tracks_[i].GetName() == trackName)
        {
            trackIndex = i;
            break;
        }
    }

    if (trackIndex == -1)
    {
        throw ExceptionIncorrectTrack("Artist dont release this track");
    }

    for (int i = 0; i < this->albums_.size(); i++)
    {
        if (albums_[i]->GetTitle() == albumTitle)
        {
            albumIndex = i;
            break;
        }
    }

    if (albumIndex == -1)
    {
        throw ExceptionIncorrectAlbum("Artist dont release this album");
    }

    try
    {
        albums_[albumIndex]->AddTrack(tracks_[trackIndex]);
    }
    catch (const ExceptionIncorrectTrack& ex)
    {
        std::cout << ex.what();
    }
}


std::string Artist::RealeseAlbum(AlbumType type, const std::string& albumTitle, const std::vector<Track>& albumTracks)
{
    bool found = false;
    for (const auto& album : this->albums_)
    {
        if (album->GetTitle() == albumTitle)
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        throw ExceptionIncorrectAlbum("Artist already release this album");
    }

    for (const auto& track : albumTracks)
    {
        found = false;
        for (const auto& artistTrack : this->tracks_)
        {
            if (track.GetArtistPseudonym() != this->pseudonym_)
            {
                throw ExceptionIncorrectArtist("It is not this artists track");
            }
            if (track.GetName() == artistTrack.GetName())
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            throw ExceptionIncorrectTrack("Artist dont release this tracks");
        }
    }

    auto newAlbum = AlbumFactory(type, albumTitle, albumTracks);
    albums_.push_back(std::move(newAlbum));
    return std::format("Исполнитель {}, выпустил альбом {}", this->pseudonym_, albumTitle);
}
