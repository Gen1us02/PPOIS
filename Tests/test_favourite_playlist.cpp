#include "gtest/gtest.h"
#include "../Playlists/FavouritePlaylist/favourite_playlist.h"

class TestingFavouritePlaylist : public ::testing::Test
{
protected:
    void SetUp() override
    {
        std::vector<Track> tracks = {
            Track("Killer", "", 1823479, 96, GenreType::Blues),
            Track("Kerosene", "", 408600,153, GenreType::Blues),
        };
        favouritePlaylist = FavouritePlaylist("MyFavouritePlaylist", tracks);
    }

    FavouritePlaylist favouritePlaylist;
};

TEST_F(TestingFavouritePlaylist, TestSetTitle)
{
    ASSERT_EQ(favouritePlaylist.GetTitle(), "MyFavouritePlaylist");
    favouritePlaylist.SetTitle("MyFavouritePlaylist2");
    ASSERT_EQ(favouritePlaylist.GetTitle(), "MyFavouritePlaylist2");
}

TEST_F(TestingFavouritePlaylist, TestGetTitle)
{
    ASSERT_EQ(favouritePlaylist.GetTitle(), "MyFavouritePlaylist");
}

TEST_F(TestingFavouritePlaylist, TestAddTrack)
{
    favouritePlaylist.AddTrack(Track("28 Days Later", "", 1341515, 146, GenreType::Blues));
    ASSERT_EQ(favouritePlaylist.GetTrackCount(), 3);
    ASSERT_THROW(favouritePlaylist.AddTrack(Track("Killer", "", 148249213, 163, GenreType::Rock)), ExceptionIncorrectTrack);
}

TEST_F(TestingFavouritePlaylist, TestGetTrackCount)
{
    ASSERT_EQ(favouritePlaylist.GetTrackCount(), 2);
}


TEST_F(TestingFavouritePlaylist, TestGetTrackList)
{
    ASSERT_EQ(favouritePlaylist.GetTrackList(), "Killer\nKerosene\n");
}

TEST_F(TestingFavouritePlaylist, TestGetPlaylistType)
{
    ASSERT_EQ(favouritePlaylist.GetPlaylistType(), "Favourite Playlist");
}

TEST(TestFavouritePlaylist, TestConstructor)
{
    std::vector<Track> tracks = {
        Track("Boys Interface", "", 2884789, 106, GenreType::Jazz),
        Track("OneShot", "", 408600, 123, GenreType::Jazz),
    };
    auto favouritePlaylist = FavouritePlaylist("NewFavouritePlaylist", tracks);
    ASSERT_EQ(favouritePlaylist.GetTitle(), "NewFavouritePlaylist");
    ASSERT_EQ(favouritePlaylist.GetTrackCount(), 2);
    ASSERT_EQ(favouritePlaylist.GetTrackList(), "Boys Interface\nOneShot\n");
}