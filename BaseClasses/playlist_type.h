#ifndef LAB3_PLAYLIST_TYPE_H
#define LAB3_PLAYLIST_TYPE_H
#include <string>

enum class PlaylistType { DailyPlaylist, ArtistPlaylist, FavouritePlaylist, GenrePlaylist };

inline std::string PlaylistTypeToString(PlaylistType playlist_type)
{
    switch (playlist_type)
    {
    case PlaylistType::DailyPlaylist: return "Daily Playlist";
    case PlaylistType::ArtistPlaylist: return "Artist Playlist";
    case PlaylistType::FavouritePlaylist: return "Favourite Playlist";
    case PlaylistType::GenrePlaylist: return "Genre Playlist";
    default: return "Unknown";
    }
}
#endif
