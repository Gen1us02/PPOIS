#include "gtest/gtest.h"
#include "../Playlists/GenrePlaylist/genre_playlist.h"

class TestingGenrePlaylist : public ::testing::Test
{
protected:
    void SetUp() override
    {
        std::vector<Track> tracks = {
            Track("Killer", "", 1823479, 96, GenreType::Phonk),
            Track("Kerosene", "", 408600,153, GenreType::Phonk)
        };
        genrePlaylist = GenrePlaylist("MyGenrePlaylist", tracks, GenreType::Phonk);
    }

    GenrePlaylist genrePlaylist;
};

TEST_F(TestingGenrePlaylist, TestSetTitle)
{
    ASSERT_EQ(genrePlaylist.GetTitle(), "MyGenrePlaylist");
    genrePlaylist.SetTitle("MyGenrePlaylist2");
    ASSERT_EQ(genrePlaylist.GetTitle(), "MyGenrePlaylist2");
}

TEST_F(TestingGenrePlaylist, TestGetTitle)
{
    ASSERT_EQ(genrePlaylist.GetTitle(), "MyGenrePlaylist");
}

TEST_F(TestingGenrePlaylist, TestAddTrack)
{
    genrePlaylist.AddTrack(Track("28 Days Later", "", 1341515, 146, GenreType::Phonk));
    ASSERT_EQ(genrePlaylist.GetTrackCount(), 3);
    ASSERT_THROW(genrePlaylist.AddTrack(Track("Killer", "", 148249213, 163, GenreType::Phonk)), ExceptionIncorrectTrack);
    ASSERT_THROW(genrePlaylist.AddTrack(Track("Rain", "", 1043813, 75 ,GenreType::Rap)), ExceptionInvalidGenre);
}

TEST_F(TestingGenrePlaylist, TestGetTrackCount)
{
    ASSERT_EQ(genrePlaylist.GetTrackCount(), 2);
}


TEST_F(TestingGenrePlaylist, TestGetTrackList)
{
    ASSERT_EQ(genrePlaylist.GetTrackList(), "Killer\nKerosene\n");
}

TEST_F(TestingGenrePlaylist, TestGetPlaylistType)
{
    ASSERT_EQ(genrePlaylist.GetPlaylistType(), "Genre Playlist");
}

TEST(TestGenrePlaylist, TestConstructor)
{
    std::vector<Track> tracks = {
        Track("Boys Interface", "", 2884789, 106, GenreType::Phonk),
        Track("OneShot", "", 408600, 123, GenreType::Phonk)
    };
    auto genrePlaylist = GenrePlaylist("NewGenrePlaylist", tracks, GenreType::Phonk);
    ASSERT_EQ(genrePlaylist.GetTitle(), "NewGenrePlaylist");
    ASSERT_EQ(genrePlaylist.GetTrackCount(), 2);
    ASSERT_EQ(genrePlaylist.GetTrackList(), "Boys Interface\nOneShot\n");
}