#ifndef ARTIST_INFO_BUTTON
#define ARTIST_INFO_BUTTON
#include "button.h"
#include "../Artist/artist.h"
#include <string>


class ArtistInfoButton : public Button
{
public:
    ArtistInfoButton();
    ~ArtistInfoButton();
    ArtistInfoButton(int width, int height);
    void SetWidth(int width);
    int GetWidth() const;
    void SetHeight(int height);
    int GetHeight() const;
    std::string GetArtistInfo(const Artist& artist) const;

private:
    int width_{0};
    int height_{0};
};


#endif
