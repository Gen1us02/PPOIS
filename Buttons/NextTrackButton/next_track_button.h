#ifndef NEXT_TRACK_BUTTON
#define NEXT_TRACK_BUTTON
#include "button.h"


class NextTrackButton : public Button
{
public:
    NextTrackButton();
    ~NextTrackButton();
    NextTrackButton(int width, int height);
    void SetWidth(int width);
    int GetWidth() const;
    void SetHeight(int height);
    int GetHeight() const;
    void GetNextTrackIndex(int& currentTrackIndex);

private:
    int width_{0};
    int height_{0};
};


#endif
