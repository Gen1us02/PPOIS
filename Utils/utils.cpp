#include "utils.h"
#include "algorithm"
#include "../Albums/CompilationAlbum/compilation_album.h"
#include "../Albums/ConcertAlbum/concert_album.h"
#include "../Albums/ExtendedPlayAlbum/extendedplay_album.h"
#include "../Albums/StudioAlbum/studio_album.h"

std::shared_ptr<Album> AlbumFactory(AlbumType type,
                                    const std::string& albumTitle,
                                    const std::vector<Track>& tracks)
{
    switch (type)
    {
    case AlbumType::CompilationAlbum:
        return std::make_shared<CompilationAlbum>(albumTitle, tracks);
    case AlbumType::ConcertAlbum:
        return std::make_shared<ConcertAlbum>(albumTitle, tracks);
    case AlbumType::ExtendedAlbum:
        return std::make_shared<ExtendedPlayAlbum>(albumTitle, tracks);
    case AlbumType::StudioAlbum:
        return std::make_shared<StudioAlbum>(albumTitle, tracks);
    default:
        throw ExceptionIncorrectAlbum("Unknown album type");
    }
}

bool PasswordValidator(const std::string& password)
{
    const std::regex passwordRegex("(^[a-zA-Z0-9.-@]{8,25}$)");
    return std::regex_match(password, passwordRegex);
}

bool EmailValidator(const std::string& email)
{
    const std::regex emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4})");
    return std::regex_match(email, emailRegex);
}
