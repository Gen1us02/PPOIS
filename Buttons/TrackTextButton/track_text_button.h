#ifndef TRACK_TEXT_BUTTON
#define TRACK_TEXT_BUTTON
#include <string>
#include "button.h"
#include "../Track/track.h"

class TrackTextButton : public Button
{
public:
    TrackTextButton();
    ~TrackTextButton();
    TrackTextButton(int width, int height);
    void SetWidth(int width) override;
    int GetWidth() const override;
    void SetHeight(int height) override;
    int GetHeight() const override;
    std::string GetTrackText(const Track& track);

private:
    int width_{0};
    int height_{0};
};


#endif
