#include "extendedplay_album.h"

ExtendedPlayAlbum::ExtendedPlayAlbum() = default;

ExtendedPlayAlbum::ExtendedPlayAlbum(const std::string& title, const std::vector<Track>& tracks) : title_(title)
{
    tracks_ = tracks;
}

ExtendedPlayAlbum::~ExtendedPlayAlbum() = default;

void ExtendedPlayAlbum::SetTitle(const std::string& title)
{
    this->title_ = title;
}

std::string ExtendedPlayAlbum::GetTitle() const
{
    return this->title_;
}

void ExtendedPlayAlbum::AddTrack(const Track& track)
{
    if (tracks_.size() >= maxTracksCount_)
    {
        throw ExceptionTrackLimit("The limit for adding tracks has been reached");
    }
    for (const auto& cur_track : this->tracks_)
    {
        if (cur_track.GetName() == track.GetName())
        {
            throw ExceptionIncorrectTrack("Track is already in album");
        }
    }

    this->tracks_.push_back(track);
}

int ExtendedPlayAlbum::GetTrackCount() const
{
    return this->tracks_.size();
}

int ExtendedPlayAlbum::GetTotalDuration() const
{
    int total_duration = 0;
    for (const auto& track : this->tracks_)
    {
        total_duration += track.GetDuration();
    }

    return total_duration;
}

std::string ExtendedPlayAlbum::GetAlbumType() const
{
    return AlbumTypeToString(this->albumType_);
}

std::string ExtendedPlayAlbum::GetTrackList() const
{
    std::string result;
    for (const auto& track : this->tracks_)
    {
        result += track.GetName() + "\n";
    }

    return result;
}
