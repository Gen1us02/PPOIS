#ifndef EXTENDEDPLAY_ALBUM
#define EXTENDEDPLAY_ALBUM

#include "album.h"
#include "album_type.h"
#include <vector>

class ExtendedPlayAlbum : public Album
{
public:
    ExtendedPlayAlbum();
    ExtendedPlayAlbum(const std::string& title, const std::vector<Track>& tracks);
    ~ExtendedPlayAlbum();
    void SetTitle(const std::string& title) override;
    std::string GetTitle() const override;
    void AddTrack(const Track& track) override;
    int GetTrackCount() const override;
    int GetTotalDuration() const override;
    std::string GetTrackList() const override;
    std::string GetAlbumType() const;

private:
    std::string title_;
    std::vector<Track> tracks_;
    AlbumType albumType_ {AlbumType::ExtendedAlbum};
    static constexpr int maxTracksCount_{3};
};


#endif
