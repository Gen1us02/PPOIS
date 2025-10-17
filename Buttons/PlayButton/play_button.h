#ifndef PLAY_BUTTON
#define PLAY_BUTTON
#include "button.h"
#include <cstring>
#include <vector>
#include <chrono>
#include <iostream>
#include <thread>
#include "../Track/track.h"
#include "../Exceptions/exceptions.h"


class PlayButton : public Button
{
public:
    PlayButton();
    ~PlayButton();
    PlayButton(int width, int height);
    void SetWidth(int width) override;
    int GetWidth() const override;
    void SetHeight(int height) override;
    int GetHeight() const override;
    void PlayTrack(Track& track) const;
    std::string PauseTrack(Track& track) const;
private:
    int width_ {0};
    int height_ {0};
};


#endif