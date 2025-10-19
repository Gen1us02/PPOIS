#include "genre_playlist.h"

GenrePlaylist::GenrePlaylist() = default;

GenrePlaylist::GenrePlaylist(const std::string& title, const std::vector<Track>& tracks, GenreType genre) : title_(title), tracks_(tracks), genre_(genre)
{
}

GenrePlaylist::~GenrePlaylist() = default;

std::string GenrePlaylist::GetPlaylistType() const
{
    return PlaylistTypeToString(this->type_);
}

void GenrePlaylist::SetTitle(const std::string& title)
{
    this->title_ = title;
}

std::string GenrePlaylist::GetTitle() const
{
    return this->title_;
}

void GenrePlaylist::AddTrack(const Track& track)
{
    for (const auto& curr_track : tracks_)
    {
        if (curr_track.GetName() == track.GetName())
        {
            throw ExceptionIncorrectTrack("This track is already in playlist");
        }

        if (track.GetGenreType() != GenreTypeToString(this->genre_))
        {
            throw ExceptionInvalidGenre("Track is not of this genre");
        }
    }

    this->tracks_.push_back(track);
}

int GenrePlaylist::GetTrackCount() const
{
    return this->tracks_.size();
}

std::string GenrePlaylist::GetTrackList() const
{
    std::string result;
    for (const auto& track : this->tracks_)
    {
        result += track.GetName() + "\n";
    }

    return result;
}

std::string GenrePlaylist::GetGenreType() const
{
    return GenreTypeToString(this->genre_);
}
