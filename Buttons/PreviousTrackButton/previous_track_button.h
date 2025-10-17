#ifndef PREVIOUS_TRACK_BUTTON
#define PREVIOUS_TRACK_BUTTON
#include "button.h"


class PreviousTrackButton : public Button
{
public:
    PreviousTrackButton();
    ~PreviousTrackButton();
    PreviousTrackButton(int width, int height);
    void SetWidth(int width) override;
    int GetWidth() const override;
    void SetHeight(int height) override;
    int GetHeight() const override;
    void GetPreviousTrackIndex(int& currentTrackIndex);

private:
    int width_{0};
    int height_{0};
};


#endif
