#include "favourite_playlist.h"

FavouritePlaylist::FavouritePlaylist() = default;

FavouritePlaylist::FavouritePlaylist(const std::string& title, const std::vector<Track>& tracks) : title_(title), tracks_(tracks)
{
    for (auto& track : tracks_)
    {
        if (!track.IsFavourite())
        {
            track.MarkFavourite();
        }
    }
}

FavouritePlaylist::~FavouritePlaylist() = default;

std::string FavouritePlaylist::GetPlaylistType() const
{
    return PlaylistTypeToString(this->type_);
}

void FavouritePlaylist::SetTitle(const std::string& title)
{
    this->title_ = title;
}

std::string FavouritePlaylist::GetTitle() const
{
    return this->title_;
}

void FavouritePlaylist::AddTrack(const Track& track)
{
    for (const auto& curr_track : tracks_)
    {
        if (curr_track.GetName() == track.GetName())
        {
            throw ExceptionIncorrectTrack("This track is already in playlist");
        }
    }

    this->tracks_.push_back(track);
}

void FavouritePlaylist::RemoveTrack(const Track& track)
{
    int index = -1;
    for (int i = 0; i < this->tracks_.size(); i++)
    {
        if (tracks_[i].GetName() == track.GetName())
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        throw ExceptionIncorrectTrack("This track is not in playlist");
    }

    this->tracks_.erase(tracks_.begin() + index);
}

int FavouritePlaylist::GetTrackCount() const
{
    return this->tracks_.size();
}

std::string FavouritePlaylist::GetTrackList() const
{
    std::string result;
    for (const auto& track : this->tracks_)
    {
        result += track.GetName() + "\n";
    }

    return result;
}
