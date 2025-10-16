#ifndef LAB3_ALBUM_H
#define LAB3_ALBUM_H
#include <string>
#include "../Track/track.h"
#include "music_collection.h"
#include "../Exceptions/exceptions.h"

class Album : public MusicCollection
{
public:
    virtual ~Album() = default;
    virtual void SetTitle(const std::string& title) = 0;
    virtual std::string GetTitle() const = 0;
    virtual void AddTrack(const Track& track) = 0;
    virtual int GetTrackCount() const = 0;
    virtual int GetTotalDuration() const = 0;
    virtual std::string GetAlbumType() const = 0;
};


#endif
