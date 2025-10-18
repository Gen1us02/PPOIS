#include "track_duration_bar.h"
#include <format>

TrackDurationBar::TrackDurationBar() = default;

TrackDurationBar::~TrackDurationBar() = default;

TrackDurationBar::TrackDurationBar(int length, int duration) : length_(length), maxDuration_(duration)
{
}

void TrackDurationBar::SetLength(int length)
{
    this->length_ = length;
}

int TrackDurationBar::GetLength() const
{
    return this->length_;
}

void TrackDurationBar::SetDuration(int duration)
{
    this->maxDuration_ = duration;
}

int TrackDurationBar::GetDuration() const
{
    return this->maxDuration_;
}

std::string TrackDurationBar::RewindTrackDuration(int duration)
{
    if (duration < this->minDuration_ || duration > this->maxDuration_)
    {
        throw ExceptionIncorrectDuration("The duration is out of range.");
    }

    return std::format("Трек перемотан на время {}", duration);
}
