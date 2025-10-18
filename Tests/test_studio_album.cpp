#include "gtest/gtest.h"
#include "../Albums/StudioAlbum/studio_album.h"

class TestingStudioAlbum : public ::testing::Test
{
protected:
    void SetUp() override
    {
        std::vector<Track> tracks = {
            Track("Killer", "", 1823479, "Artemdjdj",96, GenreType::Phonk),
            Track("Kerosene", "", 408600,"Artemdjdj",153, GenreType::Rock)
        };
        studioAlbum = StudioAlbum("MyStudioAlbum", tracks);
    }

    StudioAlbum studioAlbum;
};

TEST_F(TestingStudioAlbum, TestSetTitle)
{
    ASSERT_EQ(studioAlbum.GetTitle(), "MyStudioAlbum");
    studioAlbum.SetTitle("MyStudioAlbum2");
    ASSERT_EQ(studioAlbum.GetTitle(), "MyStudioAlbum2");
}

TEST_F(TestingStudioAlbum, TestGetTitle)
{
    ASSERT_EQ(studioAlbum.GetTitle(), "MyStudioAlbum");
}

TEST_F(TestingStudioAlbum, TestAddTrack)
{
    studioAlbum.AddTrack(Track("28 Days Later", "", 1341515, "Artemdjdj",146, GenreType::Jazz));
    ASSERT_EQ(studioAlbum.GetTrackCount(), 3);
    ASSERT_THROW(studioAlbum.AddTrack(Track("Killer", "", 148249213, "Artemdjdj",163, GenreType::Rock)), ExceptionIncorrectTrack);
}

TEST_F(TestingStudioAlbum, TestGetTrackCount)
{
    ASSERT_EQ(studioAlbum.GetTrackCount(), 2);
}

TEST_F(TestingStudioAlbum, TestGetTotalDuration)
{
    ASSERT_EQ(studioAlbum.GetTotalDuration(), 249);
}

TEST_F(TestingStudioAlbum, TestGetTrackList)
{
    ASSERT_EQ(studioAlbum.GetTrackList(), "Killer\nKerosene\n");
}

TEST_F(TestingStudioAlbum, TestGetAlbumType)
{
    ASSERT_EQ(studioAlbum.GetAlbumType(), "Studio Album");
}

TEST(TestStudioAlbum, TestConstructor)
{
    std::vector<Track> tracks = {
        Track("Boys Interface", "", 2884789, "Artemdjdj",106, GenreType::Rock),
        Track("OneShot", "", 408600, "Artemdjdj",123, GenreType::Jazz),
    };
    auto studioAlbum = StudioAlbum("NewStudioAlbum", tracks);
    ASSERT_EQ(studioAlbum.GetTitle(), "NewStudioAlbum");
    ASSERT_EQ(studioAlbum.GetTrackCount(), 2);
    ASSERT_EQ(studioAlbum.GetTotalDuration(), 229);
    ASSERT_EQ(studioAlbum.GetTrackList(), "Boys Interface\nOneShot\n");
}
