#ifndef MEDIA_COLLECTION
#define MEDIA_COLLECTION
#include <string>


class MediaCollection
{
public:
    virtual ~MediaCollection() = default;
    virtual std::string GetPlaylistList() const = 0;
};

#endif