#include "artist_playlist.h"

ArtistPlaylist::ArtistPlaylist() = default;

ArtistPlaylist::~ArtistPlaylist() = default;

ArtistPlaylist::ArtistPlaylist(const Artist& artist, const std::string& title) : artist_(artist), title_(title)
{
}

std::string ArtistPlaylist::GetPlaylistType() const
{
    return PlaylistTypeToString(this->type_);
}

void ArtistPlaylist::SetTitle(const std::string& title)
{
    this->title_ = title;
}

std::string ArtistPlaylist::GetTitle() const
{
    return title_;
}

void ArtistPlaylist::AddTrack(const Track& track)
{
    try
    {
        this->artist_.RealeseTrack(track.GetName(), track.GetText(), track.GetDuration(),
                               StringToGenreType(track.GetGenreType()));
        this->tracks_.push_back(track);
    }
    catch (const ExceptionTrackReleased& ex)
    {
        std::cout << ex.what();
    }
}

int ArtistPlaylist::GetTrackCount() const
{
    return tracks_.size();
}

std::string ArtistPlaylist::GetTrackList() const
{
    std::string result;
    for (const auto& track : tracks_)
    {
        result += track.GetName() + "\n";
    }

    return result;
}