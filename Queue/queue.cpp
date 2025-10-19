#include "queue.h"

Queue::Queue() = default;

Queue::~Queue() = default;

Queue::Queue(const std::vector<Track>& tracks) : tracks_(tracks)
{
}

void Queue::SetTracks(const std::vector<Track>& tracks)
{
    this->tracks_ = tracks;
}

std::vector<Track> Queue::GetTracks() const
{
    return this->tracks_;
}

void Queue::AddTrack(const Track& track)
{
    for (const auto& curr_track : tracks_)
    {
        if (curr_track.GetName() == track.GetName())
        {
            throw ExceptionIncorrectTrack("This track is already in queue");
        }
    }

    this->tracks_.push_back(track);
}

void Queue::RemoveTrack(const Track& track)
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

std::string Queue::GetTrackList() const
{
    std::string result;
    for (auto const& track : this->tracks_)
    {
        result += track.GetName() + "\n";
    }

    return result;
}
