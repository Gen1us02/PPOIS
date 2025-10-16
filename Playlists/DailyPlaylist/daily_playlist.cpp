#include "daily_playlist.h"

DailyPlaylist::DailyPlaylist() = default;

DailyPlaylist::DailyPlaylist(const std::string& title, const std::vector<Track>& tracks) : title_(title), tracks_(tracks)
{
    auto now = std::chrono::system_clock::now();
    std::time_t curr_date = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&curr_date), "%d.%m.%Y");

    this->date_ = ss.str();
}

DailyPlaylist::~DailyPlaylist() = default;

std::string DailyPlaylist::GetPlaylistType() const
{
    return PlaylistTypeToString(this->type_);
}

void DailyPlaylist::SetTitle(const std::string& title)
{
    this->title_ = title;
}

std::string DailyPlaylist::GetTitle() const
{
    return this->title_;
}

void DailyPlaylist::AddTrack(const Track& track)
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

int DailyPlaylist::GetTrackCount() const
{
    return this->tracks_.size();
}

void DailyPlaylist::UpdateDate()
{
    auto now = std::chrono::system_clock::now();
    std::time_t curr_date = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&curr_date), "%d.%m.%Y");

    this->date_ = ss.str();
}

std::string DailyPlaylist::GetDate() const
{
    return this->date_;
}

std::string DailyPlaylist::GetTrackList() const
{
    std::string result;
    for (const auto& track : this->tracks_)
    {
        result += track.GetName() + "\n";
    }

    return result;
}
