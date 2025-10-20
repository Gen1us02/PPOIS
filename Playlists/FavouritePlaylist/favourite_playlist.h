#ifndef FAVOURITE_PLAYLIST
#define FAVOURITE_PLAYLIST
#include "playlist.h"
#include "playlist_type.h"
#include "../Exceptions/exceptions.h"
#include <vector>

class FavouritePlaylist : public Playlist
{
public:
    FavouritePlaylist();
    ~FavouritePlaylist();
    FavouritePlaylist(const std::string& title, const std::vector<Track>& tracks);
    std::string GetPlaylistType() const override;
    void SetTitle(const std::string& title) override;
    std::string GetTitle() const override;
    void AddTrack(const Track& track) override;
    void RemoveTrack(const Track& track);
    std::string GetTrackList() const override;
    int GetTrackCount() const override;
private:
    std::string title_;
    std::vector<Track> tracks_;
    PlaylistType type_ {PlaylistType::FavouritePlaylist};
};


#endif