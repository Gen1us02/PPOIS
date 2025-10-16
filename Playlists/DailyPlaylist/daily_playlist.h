#ifndef DAILY_PLAYLIST
#define DAILY_PLAYLIST
#include <vector>
#include <chrono>
#include "playlist_type.h"
#include "../Exceptions/exceptions.h"
#include "playlist.h"


class DailyPlaylist : public Playlist
{
public:
    DailyPlaylist();
    ~DailyPlaylist();
    DailyPlaylist(const std::string& title, const std::vector<Track>& tracks);
    std::string GetPlaylistType() const override;
    void SetTitle(const std::string& title) override;
    std::string GetTitle() const override;
    void AddTrack(const Track& track) override;
    int GetTrackCount() const override;
    void UpdateDate();
    std::string GetDate() const;
    std::string GetTrackList() const override;

private:
    std::string title_{""};
    std::vector<Track> tracks_;
    std::string date_;
    PlaylistType type_{PlaylistType::DailyPlaylist};
};


#endif
