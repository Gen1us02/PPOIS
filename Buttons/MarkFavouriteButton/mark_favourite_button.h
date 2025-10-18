#ifndef MARK_FAVOURITE_BUTTON
#define MARK_FAVOURITE_BUTTON
#include "button.h"
#include "../Track/track.h"
#include "../Playlists/FavouritePlaylist/favourite_playlist.h"


class MarkFavouriteButton : public Button
{
public:
    MarkFavouriteButton();
    ~MarkFavouriteButton();
    MarkFavouriteButton(int width, int height);
    void SetWidth(int width) override;
    int GetWidth() const override;
    void SetHeight(int height) override;
    int GetHeight() const override;
    void MarkFavourite(Track& track, FavouritePlaylist& playlist);
    void UnmarkFavourite(Track& track, FavouritePlaylist& playlist);

private:
    int width_{0};
    int height_{0};
};


#endif
