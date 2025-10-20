#ifndef CONCERT_ALBUM
#define CONCERT_ALBUM
#include "album.h"
#include "album_type.h"
#include <string>
#include <vector>

class ConcertAlbum : public Album
{
public:
    ConcertAlbum();
    ConcertAlbum(const std::string& title, const std::vector<Track>& tracks);
    ~ConcertAlbum();
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
    AlbumType albumType_ {AlbumType::ConcertAlbum};
};

#endif
