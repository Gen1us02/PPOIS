#ifndef NOW_PLAYING_BUTTON
#define NOW_PLAYING_BUTTON
#include "button.h"
#include "../Track/track.h"
#include <string>


class NowPlayingButton : public Button
{
public:
    NowPlayingButton();
    ~NowPlayingButton();
    NowPlayingButton(int width, int height);
    void SetWidth(int width) override;
    int GetWidth() const override;
    void SetHeight(int height) override;
    int GetHeight() const override;
    std::string ShowNowPlayingTrackInfo(const Track& track) const;

private:
    int width_{0};
    int height_{0};
};

#endif
