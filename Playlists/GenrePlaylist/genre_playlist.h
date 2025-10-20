#ifndef GENRE_PLAYLIST
#define GENRE_PLAYLIST
#include "playlist.h"
#include "playlist_type.h"
#include "../Exceptions/exceptions.h"
#include "../BaseClasses/genre_type.h"
#include <vector>

class GenrePlaylist : public Playlist
{
public:
    GenrePlaylist();
    ~GenrePlaylist();
    GenrePlaylist(const std::string& title, const std::vector<Track>& track_, GenreType genre);
    std::string GetPlaylistType() const override;
    void SetTitle(const std::string& title) override;
    std::string GetTitle() const override;
    void AddTrack(const Track& track) override;
    std::string GetTrackList() const override;
    int GetTrackCount() const override;
    std::string GetGenreType() const;

private:
    std::string title_;
    std::vector<Track> tracks_;
    PlaylistType type_ {PlaylistType::GenrePlaylist};
    GenreType genre_;
};


#endif