#ifndef MEDIA_LIBRARY
#define MEDIA_LIBRARY
#include "media_collection.h"
#include "../Playlists/GenrePlaylist/genre_playlist.h"
#include "../Playlists/FavouritePlaylist/favourite_playlist.h"
#include "../Playlists/ArtistPlaylist/artist_playlist.h"
#include "../Playlists/DailyPlaylist/daily_playlist.h"
#include "../User/user.h"
#include <vector>
#include <optional>

class MediaLibrary : public MediaCollection
{
public:
    MediaLibrary();
    ~MediaLibrary();
    MediaLibrary(const std::string& title, const std::vector<ArtistPlaylist>& artistsPlaylists,
                 const std::vector<GenrePlaylist>& genrePlaylists, const FavouritePlaylist& favouritePlaylist);
    const std::vector<ArtistPlaylist>& GetArtistPlaylists() const;
    const std::vector<GenrePlaylist>& GetGenrePlaylists() const;
    FavouritePlaylist& GetFavouritePlaylist();
    const std::optional<DailyPlaylist>& GetDailyPlaylist() const;
    bool AddArtistPlaylist(const ArtistPlaylist& artistPlaylist);
    bool RemoveArtistPlaylist(const ArtistPlaylist& artistPlaylist);
    bool AddGenrePlaylist(const GenrePlaylist& genrePlaylist);
    bool RemoveGenrePlaylist(const GenrePlaylist& genrePlaylist);
    bool AddDailyPlaylist(const DailyPlaylist& dailyPlaylist);
    bool RemoveDailyPlaylist(const DailyPlaylist& dailyPlaylist);
    std::string GetPlaylistList() const override;

private:
    std::string title_;
    std::vector<ArtistPlaylist> artistsPlaylists_;
    std::vector<GenrePlaylist> genrePlaylists_;
    FavouritePlaylist favouritePlaylist_;
    std::optional<DailyPlaylist> dailyPlaylist_;
};


#endif
