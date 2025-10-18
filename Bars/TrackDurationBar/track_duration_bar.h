#ifndef TRACK_DURATION_BAR
#define TRACK_DURATION_BAR
#include "bar.h"
#include <string>
#include "../Exceptions/exceptions.h"


class TrackDurationBar : public Bar
{
public:
    TrackDurationBar();
    ~TrackDurationBar();
    TrackDurationBar(int length, int duration);
    void SetLength(int length) override;
    int GetLength() const override;
    void SetDuration(int duration);
    int GetDuration() const;
    std::string RewindTrackDuration(int duration);

private:
    int length_{0};
    int minDuration_{0};
    int maxDuration_{0};
};


#endif
