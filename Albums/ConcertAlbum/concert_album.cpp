#include "concert_album.h"

ConcertAlbum::ConcertAlbum() = default;

ConcertAlbum::ConcertAlbum(const std::string& title, const std::vector<Track>& tracks) : title_(title)
{
    tracks_ = tracks;
}

ConcertAlbum::~ConcertAlbum() = default;

void ConcertAlbum::SetTitle(const std::string& title)
{
    this->title_ = title;
}

std::string ConcertAlbum::GetTitle() const
{
    return this->title_;
}

void ConcertAlbum::AddTrack(const Track& track)
{
    for (const auto& cur_track : this->tracks_)
    {
        if (cur_track.GetName() == track.GetName())
        {
            throw ExceptionIncorrectTrack("Track is already in album");
        }
    }

    this->tracks_.push_back(track);
}

int ConcertAlbum::GetTrackCount() const
{
    return this->tracks_.size();
}

int ConcertAlbum::GetTotalDuration() const
{
    int total_duration = 0;
    for (const auto& track : this->tracks_)
    {
        total_duration += track.GetDuration();
    }

    return total_duration;
}

std::string ConcertAlbum::GetAlbumType() const
{
    return AlbumTypeToString(this->albumType_);
}

std::string ConcertAlbum::GetTrackList() const
{
    std::string result;
    for (const auto& track : this->tracks_)
    {
        result += track.GetName() + "\n";
    }

    return result;
}
