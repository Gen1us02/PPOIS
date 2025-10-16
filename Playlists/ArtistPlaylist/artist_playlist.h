#ifndef ARTIST_PLAYLIST
#define ARTIST_PLAYLIST
#include "../Artist/artist.h"
#include "playlist.h"
#include "playlist_type.h"


class ArtistPlaylist : public Playlist
{
public:
    ArtistPlaylist();
    ~ArtistPlaylist();
    ArtistPlaylist(const Artist& artist, const std::string& title);
    std::string GetPlaylistType() const override;
    void SetTitle(const std::string& title) override;
    std::string GetTitle() const override;
    void AddTrack(const Track& track) override;
    int GetTrackCount() const override;
    std::string GetTrackList() const override;

private:
    std::string title_{""};
    Artist artist_;
    std::vector<Track> tracks_;
    PlaylistType type_{PlaylistType::ArtistPlaylist};
};


#endif
