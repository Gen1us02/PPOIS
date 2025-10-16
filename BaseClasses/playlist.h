#ifndef PLAYLIST
#define PLAYLIST
#include "music_collection.h"
#include "../Track/track.h"

class  Playlist : public MusicCollection
{
public:
    virtual ~Playlist() = default;
    virtual std::string GetPlaylistType() const = 0;
    virtual void SetTitle(const std::string& title) = 0;
    virtual std::string GetTitle() const = 0;
    virtual void AddTrack(const Track& track) = 0;
    virtual int GetTrackCount() const = 0;
};

#endif
