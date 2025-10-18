#ifndef TRACK
#define TRACK
#include <string>
#include "../BaseClasses/genre_type.h"


class Track
{
public:
    Track();
    Track(const std::string& name, const std::string& text, int listenings, const std::string& pseudonym,int duration, GenreType genreType);
    ~Track();
    void SetName(const std::string& name);
    std::string GetName() const;
    void SetText(const std::string& text);
    std::string GetText() const;
    void SetDuration(int duration);
    int GetDuration() const;
    void SetListenings(int duration);
    int GetListenings() const;
    void MarkFavourite();
    void UnmarkFavourite();
    bool IsFavourite() const;
    void Play();
    void Pause();
    bool IsPlaying() const;
    std::string GetArtistPseudonym() const;
    void SetGenreType(GenreType genreType);
    std::string GetGenreType() const;

private:
    std::string name_{""};
    std::string text_{""};
    int listenings_ {0};
    int duration_{0};
    std::string artistPseudonym_;
    bool isFavourite_ {false};
    bool isPlaying_ {false};
    GenreType genre_;
};


#endif
