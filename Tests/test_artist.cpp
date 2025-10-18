#include "../Artist/artist.h"
#include "gtest/gtest.h"

class TestingArtist : public ::testing::Test
{
protected:
    void SetUp() override
    {
        std::vector<Track> tracks = {
            Track("Killer", "", 1000000, "famous",96, GenreType::Jazz),
            Track("Kerosene", "", 408600,"famous",153, GenreType::Rap)
        };
        artist = Artist("Иван", 26, 100000, "famous");
        artist.RealeseTrack("Killer", "", 96, GenreType::Jazz);
        artist.RealeseTrack("Kerosene", "", 153, GenreType::Rap);
        artist.RealeseAlbum(AlbumType::StudioAlbum,"MyAlbum", tracks);
    }

    Artist artist;
};

TEST_F(TestingArtist, TestSetName)
{
    ASSERT_EQ(artist.GetName(), "Иван");
    artist.SetName("Петр");
    ASSERT_EQ(artist.GetName(), "Петр");
}

TEST_F(TestingArtist, TestGetName)
{
    ASSERT_EQ(artist.GetName(), "Иван");
}

TEST_F(TestingArtist, TestSetAge)
{
    ASSERT_EQ(artist.GetAge(), 26);
    artist.SetAge(30);
    ASSERT_EQ(artist.GetAge(), 30);
}

TEST_F(TestingArtist, TestGetAge)
{
    ASSERT_EQ(artist.GetAge(), 26);
}

TEST_F(TestingArtist, TestSetListeners)
{
    ASSERT_EQ(artist.GetListeners(), 100000);
    artist.SetListeners(405900);
    ASSERT_EQ(artist.GetListeners(), 405900);
}

TEST_F(TestingArtist, TestGetListeners)
{
    ASSERT_EQ(artist.GetListeners(), 100000);
}

TEST_F(TestingArtist, TestSetPseudonym)
{
    ASSERT_EQ(artist.GetPseudonym(), "famous");
    artist.SetPseudonym("ENCASSATOR");
    ASSERT_EQ(artist.GetPseudonym(), "ENCASSATOR");
}

TEST_F(TestingArtist, TestGetPseudonym)
{
    ASSERT_EQ(artist.GetPseudonym(), "famous");
}

TEST_F(TestingArtist, TestGetArtistInfo)
{
    ASSERT_EQ(artist.GetArtistInfo(),
              "Имя: Иван\n"
              "Возраст: 26\n"
              "Слушателей в месяц: 100000\n"
              "Псевдоним: famous");
}

TEST_F(TestingArtist, TestGetTrackList)
{
    artist.RealeseTrack("Boys Interface", "", 136, GenreType::Blues);
    ASSERT_EQ(artist.GetTrackList(), "Killer\nKerosene\nBoys Interface\n");
}

TEST_F(TestingArtist, TestRealeseAlbum)
{
    std::vector<Track> track1 = {Track("Killer", "", 1000000, "famous",96, GenreType::Jazz)};
    std::vector<Track> track2 = {Track("sgsgsgs", "", 1000000, "famous", 96, GenreType::Jazz)};
    std::vector<Track> track3 = {Track("Kerosene", "", 1000000, "jksdfks", 96, GenreType::Jazz)};
    ASSERT_EQ(artist.RealeseAlbum(AlbumType::StudioAlbum, "NewAlbum", track1), "Исполнитель famous, выпустил альбом NewAlbum");
    ASSERT_THROW(artist.RealeseAlbum(AlbumType::ExtendedAlbum, "NewAlbum", track1), ExceptionIncorrectAlbum);
    ASSERT_THROW(artist.RealeseAlbum(AlbumType::ConcertAlbum, "NewAlbum2", track2), ExceptionIncorrectTrack);
    ASSERT_THROW(artist.RealeseAlbum(AlbumType::ConcertAlbum, "NewAlbum3", track3), ExceptionIncorrectArtist);
}

TEST_F(TestingArtist, TestAddTrackToAlbum)
{
    testing::internal::CaptureStdout();
    ASSERT_THROW(artist.AddTrackToAlbum("MyAlbum", "adadad"), ExceptionIncorrectTrack);
    ASSERT_THROW(artist.AddTrackToAlbum("apkdakdj", "Killer"), ExceptionIncorrectAlbum);
    artist.AddTrackToAlbum("MyAlbum", "Killer");
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_FALSE(output.empty());
    ASSERT_EQ(output, "Track is already in album");
}

TEST(TestArtist, TestConstructor)
{
    auto artist = Artist("Артем", 18, 150000, "Artemdjdj");
    ASSERT_EQ(artist.GetName(), "Артем");
    ASSERT_EQ(artist.GetAge(), 18);
    ASSERT_EQ(artist.GetListeners(), 150000);
    ASSERT_EQ(artist.GetPseudonym(), "Artemdjdj");
}