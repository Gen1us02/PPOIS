#include "gtest/gtest.h"
#include "../MediaLibrary/media_library.h"

class TestingMediaLibrary : public ::testing::Test
{
protected:
    void SetUp() override
    {
        Artist artist1 = Artist("Иван", 26, 100000, "famous");
        Artist artist2 = Artist("Дмитрий", 19, 908304, "DjBulka");
        std::vector<Track> tracks = {
            Track("Killer", "", 1000000, "famous", 96, GenreType::Phonk),
            Track("Kerosene", "", 408600, "famous", 153, GenreType::Phonk)
        };
        std::vector<ArtistPlaylist> artistsPlaylists = {
            ArtistPlaylist(artist1, "famous"),
            ArtistPlaylist(artist2, "DjBulka")
        };
        std::vector<GenrePlaylist> genrePlaylists = {
            GenrePlaylist("Phonk Hits", tracks, GenreType::Phonk)
        };
        favouritePlaylist_ = FavouritePlaylist("Favorites", tracks);
        mediaLibrary = MediaLibrary("MyMediaLibrary", artistsPlaylists, genrePlaylists, favouritePlaylist_);
    }

    MediaLibrary mediaLibrary;
    FavouritePlaylist favouritePlaylist_;
};

TEST_F(TestingMediaLibrary, TestAddArtistPlaylist)
{
    auto newArtist = Artist("Кирилл", 25, 50000, "Kirill");
    auto newPlaylist = ArtistPlaylist(newArtist, "Kirill");

    ASSERT_EQ(mediaLibrary.GetArtistPlaylists().size(), 2);
    mediaLibrary.AddArtistPlaylist(newPlaylist);
    ASSERT_EQ(mediaLibrary.GetArtistPlaylists().size(), 3);
    ASSERT_THROW(mediaLibrary.AddArtistPlaylist(newPlaylist), ExceptionIncorrectPlaylist);
}

TEST_F(TestingMediaLibrary, TestRemoveArtistPlaylist)
{
    auto artistToRemove = Artist("Иван", 26, 100000, "famous");
    auto playlistToRemove = ArtistPlaylist(artistToRemove, "famous");

    ASSERT_EQ(mediaLibrary.GetArtistPlaylists().size(), 2);
    mediaLibrary.RemoveArtistPlaylist(playlistToRemove);
    ASSERT_EQ(mediaLibrary.GetArtistPlaylists().size(), 1);
    ASSERT_THROW(mediaLibrary.RemoveArtistPlaylist(playlistToRemove), ExceptionIncorrectPlaylist);
}

TEST_F(TestingMediaLibrary, TestGetArtistPlaylists)
{
    auto playlists = mediaLibrary.GetArtistPlaylists();
    ASSERT_EQ(playlists.size(), 2);
    ASSERT_EQ(playlists[0].GetArtistPseudonym(), "famous");
    ASSERT_EQ(playlists[1].GetArtistPseudonym(), "DjBulka");
}

TEST_F(TestingMediaLibrary, TestAddGenrePlaylist)
{
    std::vector<Track> tracks = {
        Track("New Track", "", 1000000, "artist", 120, GenreType::Rap)
    };
    auto newPlaylist = GenrePlaylist("Rap Hits", tracks, GenreType::Rap);

    ASSERT_EQ(mediaLibrary.GetGenrePlaylists().size(), 1);
    mediaLibrary.AddGenrePlaylist(newPlaylist);
    ASSERT_EQ(mediaLibrary.GetGenrePlaylists().size(), 2);

    auto duplicatePlaylist = GenrePlaylist("Another Phonk", tracks, GenreType::Phonk);
    ASSERT_THROW(mediaLibrary.AddGenrePlaylist(duplicatePlaylist), ExceptionIncorrectPlaylist);
}

TEST_F(TestingMediaLibrary, TestRemoveGenrePlaylist)
{
    auto playlistToRemove = GenrePlaylist("Phonk Hits", {}, GenreType::Phonk);

    ASSERT_EQ(mediaLibrary.GetGenrePlaylists().size(), 1);
    mediaLibrary.RemoveGenrePlaylist(playlistToRemove);
    ASSERT_EQ(mediaLibrary.GetGenrePlaylists().size(), 0);
    ASSERT_THROW(mediaLibrary.RemoveGenrePlaylist(playlistToRemove), ExceptionIncorrectPlaylist);
}

TEST_F(TestingMediaLibrary, TestGetGenrePlaylists)
{
    auto playlists = mediaLibrary.GetGenrePlaylists();
    ASSERT_EQ(playlists.size(), 1);
    ASSERT_EQ(playlists[0].GetGenreType(), "Phonk");
    ASSERT_EQ(playlists[0].GetTitle(), "Phonk Hits");
}

TEST_F(TestingMediaLibrary, TestAddDailyPlaylist)
{
    std::vector<Track> tracks = {
        Track("Daily Track", "", 1000000, "artist", 120, GenreType::Phonk)
    };
    auto dailyPlaylist = DailyPlaylist("Today's Hits", tracks);

    ASSERT_FALSE(mediaLibrary.GetDailyPlaylist().has_value());
    mediaLibrary.AddDailyPlaylist(dailyPlaylist);
    ASSERT_TRUE(mediaLibrary.GetDailyPlaylist().has_value());
    ASSERT_EQ(mediaLibrary.GetDailyPlaylist()->GetTitle(), "Today's Hits");

    auto anotherDaily = DailyPlaylist("Another Daily", tracks);
    ASSERT_THROW(mediaLibrary.AddDailyPlaylist(anotherDaily), ExceptionIncorrectPlaylist);
}

TEST_F(TestingMediaLibrary, TestRemoveDailyPlaylist)
{
    std::vector<Track> tracks = {Track("Track", "", 1000000, "artist", 120, GenreType::Rock)};
    auto dailyPlaylist = DailyPlaylist("Today's Hits", tracks);

    mediaLibrary.AddDailyPlaylist(dailyPlaylist);
    ASSERT_TRUE(mediaLibrary.GetDailyPlaylist().has_value());
    mediaLibrary.RemoveDailyPlaylist(dailyPlaylist);
    ASSERT_FALSE(mediaLibrary.GetDailyPlaylist().has_value());
    ASSERT_THROW(mediaLibrary.RemoveDailyPlaylist(dailyPlaylist), ExceptionIncorrectPlaylist);
}

TEST_F(TestingMediaLibrary, TestGetDailyPlaylist)
{
    ASSERT_FALSE(mediaLibrary.GetDailyPlaylist().has_value());

    std::vector<Track> tracks = {Track("Track", "", 1000000, "artist", 120, GenreType::Rap)};
    auto dailyPlaylist = DailyPlaylist("Today's Hits", tracks);
    mediaLibrary.AddDailyPlaylist(dailyPlaylist);
    ASSERT_TRUE(mediaLibrary.GetDailyPlaylist().has_value());
    ASSERT_EQ(mediaLibrary.GetDailyPlaylist()->GetTitle(), "Today's Hits");
}

TEST_F(TestingMediaLibrary, TestGetPlaylistList)
{
    std::string playlistList = mediaLibrary.GetPlaylistList();

    ASSERT_TRUE(playlistList.find("famous") != std::string::npos);
    ASSERT_TRUE(playlistList.find("DjBulka") != std::string::npos);
    ASSERT_TRUE(playlistList.find("Phonk Hits") != std::string::npos);
    ASSERT_TRUE(playlistList.find("Favorites") != std::string::npos);

    std::vector<Track> tracks = {Track("Track", "", 1000000, "artist", 120, GenreType::Jazz)};
    auto dailyPlaylist = DailyPlaylist("Today's Picks", tracks);
    mediaLibrary.AddDailyPlaylist(dailyPlaylist);

    playlistList = mediaLibrary.GetPlaylistList();
    ASSERT_TRUE(playlistList.find("Today's Picks") != std::string::npos);
}

TEST(TestMediaLibrary, TestConstructor)
{
    auto artist = Artist("Артист", 30, 100000, "ArtistName");
    std::vector<Track> tracks = {
        Track("Boys Interface", "", 2884789, "Artemdjdj", 106, GenreType::Jazz),
        Track("OneShot", "", 408600, "Artemdjdj", 123, GenreType::Jazz),
    };
    std::vector<ArtistPlaylist> artistsPlaylists = {
        ArtistPlaylist(artist, "ArtistName")
    };
    std::vector<GenrePlaylist> genrePlaylists = {
        GenrePlaylist("Jazz Collection", tracks, GenreType::Jazz)
    };
    auto favouritePlaylist = FavouritePlaylist("My Favorites", tracks);
    auto mediaLibrary = MediaLibrary("Test Library", artistsPlaylists, genrePlaylists, favouritePlaylist);

    ASSERT_EQ(mediaLibrary.GetArtistPlaylists().size(), 1);
    ASSERT_EQ(mediaLibrary.GetGenrePlaylists().size(), 1);
    ASSERT_EQ(mediaLibrary.GetFavouritePlaylist().GetTitle(), "My Favorites");
    ASSERT_FALSE(mediaLibrary.GetDailyPlaylist().has_value());
}