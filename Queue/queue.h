#ifndef QUEUE
#define QUEUE
#include "music_collection.h"
#include <vector>
#include "../Track/track.h"
#include "../Exceptions/exceptions.h"


class Queue : public MusicCollection
{
public:
    Queue();
    ~Queue();
    explicit Queue(const std::vector<Track>& tracks);
    void SetTracks(const std::vector<Track>& tracks);
    std::vector<Track> GetTracks() const;
    void AddTrack(const Track& track);
    void RemoveTrack(const Track& track);
    std::string GetTrackList() const override;
private:
    std::vector<Track> tracks_;
};


#endif