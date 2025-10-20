#ifndef COMPILATION_ALBUM
#define COMPILATION_ALBUM
#include <vector>

#include "album.h"
#include "album_type.h"

class CompilationAlbum : public Album
{
public:
    CompilationAlbum();
    CompilationAlbum(const std::string& title, const std::vector<Track>& tracks);
    ~CompilationAlbum();
    void SetTitle(const std::string& title) override;
    std::string GetTitle() const override;
    void AddTrack(const Track& track) override;
    int GetTrackCount() const override;
    int GetTotalDuration() const override;
    std::string GetTrackList() const override;
    std::string GetAlbumType() const override;

private:
    std::string title_;
    std::vector<Track> tracks_;
    AlbumType albumType_ {AlbumType::CompilationAlbum};
};

#endif
