#include "gtest/gtest.h"
#include "../Playlists/DailyPlaylist/daily_playlist.h"

class TestingDailyPlaylist : public ::testing::Test
{
protected:
    void SetUp() override
    {
        std::vector<Track> tracks = {
            Track("Killer", "", 1823479, 96, GenreType::Blues),
            Track("Kerosene", "", 408600,153, GenreType::Blues),
        };
        dailyPlaylist = DailyPlaylist("MyDailyPlaylist", tracks);
    }

    DailyPlaylist dailyPlaylist;
};

TEST_F(TestingDailyPlaylist, TestSetTitle)
{
    ASSERT_EQ(dailyPlaylist.GetTitle(), "MyDailyPlaylist");
    dailyPlaylist.SetTitle("MyDailyPlaylist2");
    ASSERT_EQ(dailyPlaylist.GetTitle(), "MyDailyPlaylist2");
}

TEST_F(TestingDailyPlaylist, TestGetTitle)
{
    ASSERT_EQ(dailyPlaylist.GetTitle(), "MyDailyPlaylist");
}

TEST_F(TestingDailyPlaylist, TestAddTrack)
{
    dailyPlaylist.AddTrack(Track("28 Days Later", "", 1341515, 146, GenreType::Blues));
    ASSERT_EQ(dailyPlaylist.GetTrackCount(), 3);
    ASSERT_THROW(dailyPlaylist.AddTrack(Track("Killer", "", 148249213, 163, GenreType::Phonk)), ExceptionIncorrectTrack);
}

TEST_F(TestingDailyPlaylist, TestGetTrackCount)
{
    ASSERT_EQ(dailyPlaylist.GetTrackCount(), 2);
}


TEST_F(TestingDailyPlaylist, TestGetTrackList)
{
    ASSERT_EQ(dailyPlaylist.GetTrackList(), "Killer\nKerosene\n");
}

TEST_F(TestingDailyPlaylist, TestGetPlaylistType)
{
    ASSERT_EQ(dailyPlaylist.GetPlaylistType(), "Daily Playlist");
}

TEST_F(TestingDailyPlaylist, TestGetDate)
{
    ASSERT_EQ(dailyPlaylist.GetDate(), "16.10.2025");
}

TEST(TestDailyPlaylist, TestConstructor)
{
    std::vector<Track> tracks = {
        Track("Boys Interface", "", 2884789, 106, GenreType::Blues),
        Track("OneShot", "", 408600, 123, GenreType::Blues),
    };
    auto dailyPlaylist = DailyPlaylist("NewDailyPlaylist", tracks);
    ASSERT_EQ(dailyPlaylist.GetTitle(), "NewDailyPlaylist");
    ASSERT_EQ(dailyPlaylist.GetTrackCount(), 2);
    ASSERT_EQ(dailyPlaylist.GetTrackList(), "Boys Interface\nOneShot\n");
}
