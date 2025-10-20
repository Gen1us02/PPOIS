#ifndef ARTIST
#define ARTIST
#include <string>
#include <vector>
#include <iostream>
#include <memory>

#include "../Track/track.h"
#include "../BaseClasses/human.h"
#include "../BaseClasses/album.h"
#include "../BaseClasses/album_type.h"

class Artist : public Human
{
public:
    Artist();
    Artist(const std::string& name, int age, int listeners, const std::string& pseudonym);
    ~Artist();
    void SetName(const std::string& name) override;
    std::string GetName() const override;
    void SetAge(int age) override;
    int GetAge() const override;
    void SetListeners(int listeners);
    int GetListeners() const;
    void SetPseudonym(const std::string& pseudonym);
    std::string GetPseudonym() const;
    std::string GetArtistInfo() const;
    std::string GetTrackList() const;
    std::string GetAlbumList() const;
    std::string RealeseTrack(const std::string& name, const std::string& text, int duration, GenreType genre);
    void AddTrackToAlbum(const std::string& albumTitle, const std::string& trackName);
    std::string RealeseAlbum(AlbumType type, const std::string& albumTitle, const std::vector<Track>& albumTracks);

private:
    std::string name_;
    int age_ {0};
    int listeners_{0};
    std::string pseudonym_;
    std::vector<Track> tracks_;
    std::vector<std::shared_ptr<Album>> albums_;
};

#endif
