#ifndef STUDIO_ALBUM
#define STUDIO_ALBUM
#include "album.h"
#include <vector>

#include "album_type.h"

class StudioAlbum : public Album
{
public:
    StudioAlbum();
    StudioAlbum(const std::string& title, const std::vector<Track>& tracks);
    ~StudioAlbum();
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
    AlbumType albumType_{AlbumType::StudioAlbum};
};


#endif
