#ifndef GENRE_TYPE
#define GENRE_TYPE
#include <string>

enum class GenreType {None, Phonk, Rap, Rock, Blues, Jazz};

inline std::string GenreTypeToString(GenreType genreType)
{
    switch (genreType)
    {
        case GenreType::Phonk: return "Phonk";
        case GenreType::Rap: return "Rap";
        case GenreType::Rock: return "Rock";
        case GenreType::Jazz: return "Jazz";
        case GenreType::Blues: return "Blues";
        default: return "Unknown";
    }
}

inline GenreType StringToGenreType(const std::string& genreType)
{
    if (genreType == "Phonk")
    {
        return GenreType::Phonk;
    }

    if (genreType == "Rap")
    {
        return GenreType::Rap;
    }

    if (genreType == "Rock")
    {
        return GenreType::Rock;
    }

    if (genreType == "Jazz")
    {
        return GenreType::Jazz;
    }

    if (genreType == "Blues")
    {
        return GenreType::Blues;
    }

    return GenreType::None;
}

#endif