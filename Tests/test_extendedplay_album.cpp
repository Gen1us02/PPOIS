#include "gtest/gtest.h"
#include "../Albums/ExtendedPlayAlbum/extendedplay_album.h"

class TestingExtendedPlayAlbum : public ::testing::Test
{
protected:
    void SetUp() override
    {
        std::vector<Track> tracks = {
            Track("Killer", "", 1000000, 96, GenreType::Phonk),
        };
        extendedPlayAlbum = ExtendedPlayAlbum("MyExtendedPlayAlbum", tracks);
    }

    ExtendedPlayAlbum extendedPlayAlbum;
};

TEST_F(TestingExtendedPlayAlbum, TestSetTitle)
{
    ASSERT_EQ(extendedPlayAlbum.GetTitle(), "MyExtendedPlayAlbum");
    extendedPlayAlbum.SetTitle("MyExtendedPlayAlbum2");
    ASSERT_EQ(extendedPlayAlbum.GetTitle(), "MyExtendedPlayAlbum2");
}

TEST_F(TestingExtendedPlayAlbum, TestGetTitle)
{
    ASSERT_EQ(extendedPlayAlbum.GetTitle(), "MyExtendedPlayAlbum");
}

TEST_F(TestingExtendedPlayAlbum, TestAddTrack)
{
    extendedPlayAlbum.AddTrack(Track("Boys Interface", "", 1341515, 86, GenreType::Blues));
    ASSERT_EQ(extendedPlayAlbum.GetTrackCount(), 2);
    ASSERT_THROW(extendedPlayAlbum.AddTrack(Track("Killer", "", 1000000, 96,GenreType::Phonk)), ExceptionIncorrectTrack);
    auto track1 = Track("SHADOW", "", 3048201, 145, GenreType::Phonk);
    extendedPlayAlbum.AddTrack(track1);
    ASSERT_EQ(extendedPlayAlbum.GetTrackCount(), 3);
    auto track2 = Track("Neon Blade", "", 1309893, 189, GenreType::Phonk);
    ASSERT_THROW(extendedPlayAlbum.AddTrack(track2), ExceptionTrackLimit);
}

TEST_F(TestingExtendedPlayAlbum, TestGetTrackCount)
{
    ASSERT_EQ(extendedPlayAlbum.GetTrackCount(), 1);
}

TEST_F(TestingExtendedPlayAlbum, TestGetTotalDuration)
{
    ASSERT_EQ(extendedPlayAlbum.GetTotalDuration(), 96);
}

TEST_F(TestingExtendedPlayAlbum, TestGetTrackList)
{
    ASSERT_EQ(extendedPlayAlbum.GetTrackList(), "Killer\n");
}

TEST_F(TestingExtendedPlayAlbum, TestGetAlbumType)
{
    ASSERT_EQ(extendedPlayAlbum.GetAlbumType(), "Extended Play Album");
}

TEST(TestExtendedPlayAlbum, TestConstructor)
{
    std::vector<Track> tracks = {
        Track("Boys Interface", "", 2884789, 106, GenreType::Jazz),
        Track("OneShot", "", 408600,123, GenreType::Rock)
    };
    auto extendedPlayAlbum = ExtendedPlayAlbum("NewExtendedPlayAlbum", tracks);
    ASSERT_EQ(extendedPlayAlbum.GetTitle(), "NewExtendedPlayAlbum");
    ASSERT_EQ(extendedPlayAlbum.GetTrackCount(), 2);
    ASSERT_EQ(extendedPlayAlbum.GetTotalDuration(), 229);
    ASSERT_EQ(extendedPlayAlbum.GetTrackList(), "Boys Interface\nOneShot\n");
}