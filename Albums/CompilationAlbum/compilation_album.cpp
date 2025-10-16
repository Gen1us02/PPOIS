#include "compilation_album.h"

CompilationAlbum::CompilationAlbum() = default;

CompilationAlbum::CompilationAlbum(const std::string& title, const std::vector<Track>& tracks) : title_(title)
{
    tracks_ = tracks;
}

CompilationAlbum::~CompilationAlbum() = default;

void CompilationAlbum::SetTitle(const std::string& title)
{
    this->title_ = title;
}

std::string CompilationAlbum::GetTitle() const
{
    return this->title_;
}

void CompilationAlbum::AddTrack(const Track& track)
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

int CompilationAlbum::GetTrackCount() const
{
    return this->tracks_.size();
}

int CompilationAlbum::GetTotalDuration() const
{
    int total_duration = 0;
    for (const auto& track : this->tracks_)
    {
        total_duration += track.GetDuration();
    }

    return total_duration;
}

std::string CompilationAlbum::GetAlbumType() const
{
    return AlbumTypeToString(this->albumType_);
}

std::string CompilationAlbum::GetTrackList() const
{
    std::string result;
    for (const auto& track : this->tracks_)
    {
        result += track.GetName() + "\n";
    }

    return result;
}
