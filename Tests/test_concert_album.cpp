#include "gtest/gtest.h"
#include "../Albums/ConcertAlbum/concert_album.h"

class TestingConcertAlbum : public ::testing::Test
{
protected:
    void SetUp() override
    {
        std::vector<Track> tracks = {
            Track("Killer", "", 1000000, "Artemdjdj",96, GenreType::Jazz),
            Track("Kerosene", "", 408600, "Artemdjdj",153, GenreType::Jazz),
        };
        concertAlbum = ConcertAlbum("MyConcertAlbum", tracks);
    }

    ConcertAlbum concertAlbum;
};

TEST_F(TestingConcertAlbum, TestSetTitle)
{
    ASSERT_EQ(concertAlbum.GetTitle(), "MyConcertAlbum");
    concertAlbum.SetTitle("MyConcertAlbum2");
    ASSERT_EQ(concertAlbum.GetTitle(), "MyConcertAlbum2");
}

TEST_F(TestingConcertAlbum, TestGetTitle)
{
    ASSERT_EQ(concertAlbum.GetTitle(), "MyConcertAlbum");
}

TEST_F(TestingConcertAlbum, TestAddTrack)
{
    concertAlbum.AddTrack(Track("Boys Interface", "", 1341515, "Artemdjdj",146, GenreType::Blues));
    ASSERT_EQ(concertAlbum.GetTrackCount(), 3);
    ASSERT_THROW(concertAlbum.AddTrack(Track("Killer", "", 148249213, "Artemdjdj",163, GenreType::Rock)), ExceptionIncorrectTrack);
}

TEST_F(TestingConcertAlbum, TestGetTrackCount)
{
    ASSERT_EQ(concertAlbum.GetTrackCount(), 2);
}

TEST_F(TestingConcertAlbum, TestGetTotalDuration)
{
    ASSERT_EQ(concertAlbum.GetTotalDuration(), 249);
}

TEST_F(TestingConcertAlbum, TestGetTrackList)
{
    ASSERT_EQ(concertAlbum.GetTrackList(), "Killer\nKerosene\n");
}

TEST_F(TestingConcertAlbum, TestGetAlbumType)
{
    ASSERT_EQ(concertAlbum.GetAlbumType(), "Concert Album");
}

TEST(TestConcertAlbum, TestConstructor)
{
    std::vector<Track> tracks = {
        Track("Boys Interface", "", 2884789, "Artemdjdj",106, GenreType::Phonk),
        Track("OneShot", "", 408600, "Artemdjdj",123, GenreType::Phonk),
    };
    auto concertAlbum = ConcertAlbum("NewConcertAlbum", tracks);
    ASSERT_EQ(concertAlbum.GetTitle(), "NewConcertAlbum");
    ASSERT_EQ(concertAlbum.GetTrackCount(), 2);
    ASSERT_EQ(concertAlbum.GetTotalDuration(), 229);
    ASSERT_EQ(concertAlbum.GetTrackList(), "Boys Interface\nOneShot\n");
}
