#ifndef PLAYLIST_COLLECTION
#define PLAYLIST_COLLECTION
#include <string>

class MusicCollection
{
public:
    virtual ~MusicCollection() = default;
    virtual std::string GetTrackList() const = 0;
};

#endif