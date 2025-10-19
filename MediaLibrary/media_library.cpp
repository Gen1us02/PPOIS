#include "media_library.h"

MediaLibrary::MediaLibrary() = default;

MediaLibrary::~MediaLibrary() = default;

MediaLibrary::MediaLibrary(const std::string& title, const std::vector<ArtistPlaylist>& artistsPlaylists,
                           const std::vector<GenrePlaylist>& genrePlaylists, const FavouritePlaylist& favouritePlaylist) : title_(title), artistsPlaylists_(artistsPlaylists),
                                               genrePlaylists_(genrePlaylists), favouritePlaylist_(favouritePlaylist)
{
}

const std::vector<ArtistPlaylist>& MediaLibrary::GetArtistPlaylists() const
{
    return this->artistsPlaylists_;
}

const std::vector<GenrePlaylist>& MediaLibrary::GetGenrePlaylists() const
{
    return this->genrePlaylists_;
}

FavouritePlaylist& MediaLibrary::GetFavouritePlaylist()
{
    return this->favouritePlaylist_;
}

const std::optional<DailyPlaylist>& MediaLibrary::GetDailyPlaylist() const
{
    return this->dailyPlaylist_;
}

bool MediaLibrary::AddArtistPlaylist(const ArtistPlaylist& artistPlaylist)
{
    for (const auto& curr_artistPlaylist : artistsPlaylists_)
    {
        if (curr_artistPlaylist.GetArtistPseudonym() == artistPlaylist.GetArtistPseudonym())
        {
            throw ExceptionIncorrectPlaylist("Playlist with this artist already exists");
        }
    }

    this->artistsPlaylists_.push_back(artistPlaylist);
    return true;
}

bool MediaLibrary::RemoveArtistPlaylist(const ArtistPlaylist& artistPlaylist)
{
    int index = -1;
    for (int i = 0; i < this->artistsPlaylists_.size(); i++)
    {
        if (artistsPlaylists_[i].GetArtistPseudonym() == artistPlaylist.GetArtistPseudonym())
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        throw ExceptionIncorrectPlaylist("Playlist with this artist does not exist");
    }

    this->artistsPlaylists_.erase(this->artistsPlaylists_.begin() + index);
    return true;
}


bool MediaLibrary::AddGenrePlaylist(const GenrePlaylist& genrePlaylist)
{
    for (const auto& curr_genrePlaylist : genrePlaylists_)
    {
        if (curr_genrePlaylist.GetGenreType() == genrePlaylist.GetGenreType())
        {
            throw ExceptionIncorrectPlaylist("Playlist with this genre already exists");
        }
    }

    this->genrePlaylists_.push_back(genrePlaylist);
    return true;
}

bool MediaLibrary::RemoveGenrePlaylist(const GenrePlaylist& genrePlaylist)
{
    int index = -1;
    for (int i = 0; i < this->genrePlaylists_.size(); i++)
    {
        if (genrePlaylists_[i].GetGenreType() == genrePlaylist.GetGenreType())
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        throw ExceptionIncorrectPlaylist("Playlist with this genre does not exist");
    }

    this->genrePlaylists_.erase(this->genrePlaylists_.begin() + index);
    return true;
}

bool MediaLibrary::AddDailyPlaylist(const DailyPlaylist& dailyPlaylist)
{
    if (this->dailyPlaylist_.has_value())
    {
        throw ExceptionIncorrectPlaylist("Daily playlist already exists");
    }

    this->dailyPlaylist_ = dailyPlaylist;
    return true;
}

bool MediaLibrary::RemoveDailyPlaylist(const DailyPlaylist& dailyPlaylist)
{
    if (!this->dailyPlaylist_.has_value())
    {
        throw ExceptionIncorrectPlaylist("Daily playlist does not exist");
    }

    this->dailyPlaylist_.reset();
    return true;
}

std::string MediaLibrary::GetPlaylistList() const
{
    std::string artistList;
    std::string genreList;
    for (const auto& artistPlaylist : artistsPlaylists_)
    {
        artistList += artistPlaylist.GetTitle() + "\n";
    }

    for (const auto& genrePlaylist : genrePlaylists_)
    {
        genreList += genrePlaylist.GetTitle() + "\n";
    }

    if (dailyPlaylist_.has_value())
    {
        return artistList + genreList + favouritePlaylist_.GetTitle() + "\n" + dailyPlaylist_->GetTitle();
    }

    return artistList + genreList + favouritePlaylist_.GetTitle();
}
