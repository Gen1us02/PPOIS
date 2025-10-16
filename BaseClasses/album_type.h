#ifndef ALBUM_TYPE
#define ALBUM_TYPE
#include <string>

enum class AlbumType { CompilationAlbum, ConcertAlbum, ExtendedAlbum, StudioAlbum };

inline std::string AlbumTypeToString(AlbumType albumType)
{
    switch (albumType)
    {
    case AlbumType::CompilationAlbum: return "Compilation Album";
    case AlbumType::ConcertAlbum: return "Concert Album";
    case AlbumType::ExtendedAlbum: return "Extended Play Album";
    case AlbumType::StudioAlbum: return "Studio Album";
    default: return "Unknown";
    }
}


#endif
