#include "gtest/gtest.h"
#include "../Playlists/ArtistPlaylist/artist_playlist.h"

class TestingArtistPlaylist : public ::testing::Test
{
protected:
    void SetUp() override
    {
        artist = Artist("Дима", 19, 32409, "DjBulka");
        artistPlaylist = ArtistPlaylist(artist, "MyArtistPlaylist");
    }

    ArtistPlaylist artistPlaylist;
    Artist artist;
};

TEST_F(TestingArtistPlaylist, TestSetTitle)
{
    ASSERT_EQ(artistPlaylist.GetTitle(), "MyArtistPlaylist");
    artistPlaylist.SetTitle("MyArtistPlaylist2");
    ASSERT_EQ(artistPlaylist.GetTitle(), "MyArtistPlaylist2");
}

TEST_F(TestingArtistPlaylist, TestGetTitle)
{
    ASSERT_EQ(artistPlaylist.GetTitle(), "MyArtistPlaylist");
}

TEST_F(TestingArtistPlaylist, TestAddTrack)
{
    testing::internal::CaptureStdout();
    artistPlaylist.AddTrack(Track("28 Days Later", "", 1341515, 146, GenreType::Phonk));
    ASSERT_EQ(artistPlaylist.GetTrackCount(), 1);
    artistPlaylist.AddTrack(Track("Killer", "", 94992, 221, GenreType::Phonk));
    ASSERT_EQ(artistPlaylist.GetTrackCount(), 2);
    artistPlaylist.AddTrack(Track("Killer", "", 94992, 221, GenreType::Phonk));
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_FALSE(output.empty());
    ASSERT_EQ(output, "This track is already released");

}

TEST_F(TestingArtistPlaylist, TestGetTrackCount)
{
    artistPlaylist.AddTrack(Track("Killer", "", 94992, 221, GenreType::Phonk));
    ASSERT_EQ(artistPlaylist.GetTrackCount(), 1);
}


TEST_F(TestingArtistPlaylist, TestGetTrackList)
{
    artistPlaylist.AddTrack(Track("Killer", "", 94992, 221, GenreType::Phonk));
    ASSERT_EQ(artistPlaylist.GetTrackList(), "Killer\n");
}

TEST_F(TestingArtistPlaylist, TestGetPlaylistType)
{
    ASSERT_EQ(artistPlaylist.GetPlaylistType(), "Artist Playlist");
}

TEST(TestArtistPlaylist, TestConstructor)
{
    auto artist = Artist("Дима", 19, 32409, "DjBulka");
    auto artistPlaylist = ArtistPlaylist(artist, "NewArtistPlaylist");
    artistPlaylist.AddTrack(Track("The Farewell", "", 4590433, 71, GenreType::Jazz));
    ASSERT_EQ(artistPlaylist.GetTitle(), "NewArtistPlaylist");
    ASSERT_EQ(artistPlaylist.GetTrackCount(), 1);
    ASSERT_EQ(artistPlaylist.GetTrackList(), "The Farewell\n");
}