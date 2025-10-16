#include "studio_album.h"

StudioAlbum::StudioAlbum() = default;

StudioAlbum::StudioAlbum(const std::string& title, const std::vector<Track>& tracks) : title_(title)
{
    tracks_ = tracks;
}

StudioAlbum::~StudioAlbum() = default;

void StudioAlbum::SetTitle(const std::string& title)
{
    this->title_ = title;
}

std::string StudioAlbum::GetTitle() const
{
    return this->title_;
}

void StudioAlbum::AddTrack(const Track& track)
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

int StudioAlbum::GetTrackCount() const
{
    return this->tracks_.size();
}

int StudioAlbum::GetTotalDuration() const
{
    int total_duration = 0;
    for (const auto& track : this->tracks_)
    {
        total_duration += track.GetDuration();
    }

    return total_duration;
}

std::string StudioAlbum::GetAlbumType() const
{
    return AlbumTypeToString(this->albumType_);
}

std::string StudioAlbum::GetTrackList() const
{
    std::string result;
    for (const auto& track : this->tracks_)
    {
        result += track.GetName() + "\n";
    }

    return result;
}
