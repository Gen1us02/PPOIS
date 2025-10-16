#include "gtest/gtest.h"
#include "../Albums/CompilationAlbum/compilation_album.h"

class TestingCompilationAlbum : public ::testing::Test
{
protected:
    void SetUp() override
    {
        std::vector<Track> tracks = {
            Track("Killer", "", 1000000, 96, GenreType::Phonk),
            Track("Kerosene", "", 408600, 153, GenreType::Phonk),
        };
        compilationAlbum = CompilationAlbum("MyCompilationAlbum", tracks);
    }

    CompilationAlbum compilationAlbum;
};

TEST_F(TestingCompilationAlbum, TestSetTitle)
{
    ASSERT_EQ(compilationAlbum.GetTitle(), "MyCompilationAlbum");
    compilationAlbum.SetTitle("MyCompilationAlbum2");
    ASSERT_EQ(compilationAlbum.GetTitle(), "MyCompilationAlbum2");
}

TEST_F(TestingCompilationAlbum, TestGetTitle)
{
    ASSERT_EQ(compilationAlbum.GetTitle(), "MyCompilationAlbum");
}

TEST_F(TestingCompilationAlbum, TestAddTrack)
{
    compilationAlbum.AddTrack(Track("Boys Interface", "", 1341515, 86, GenreType::Phonk));
    ASSERT_EQ(compilationAlbum.GetTrackCount(), 3);
    ASSERT_THROW(compilationAlbum.AddTrack(Track("Killer", "", 1000000, 96, GenreType::Blues)), ExceptionIncorrectTrack);
}

TEST_F(TestingCompilationAlbum, TestGetTrackCount)
{
    ASSERT_EQ(compilationAlbum.GetTrackCount(), 2);
}

TEST_F(TestingCompilationAlbum, TestGetTotalDuration)
{
    ASSERT_EQ(compilationAlbum.GetTotalDuration(), 249);
}

TEST_F(TestingCompilationAlbum, TestGetTrackList)
{
    ASSERT_EQ(compilationAlbum.GetTrackList(), "Killer\nKerosene\n");
}

TEST_F(TestingCompilationAlbum, TestGetAlbumType)
{
    ASSERT_EQ(compilationAlbum.GetAlbumType(), "Compilation Album");
}

TEST(TestCompilationAlbum, TestConstructor)
{
    std::vector<Track> tracks = {
        Track("Boys Interface", "", 2884789, 106, GenreType::Phonk),
        Track("OneShot", "", 408600, 123, GenreType::Jazz)
    };
    auto compilationAlbum = CompilationAlbum("NewCompilationAlbum", tracks);
    ASSERT_EQ(compilationAlbum.GetTitle(), "NewCompilationAlbum");
    ASSERT_EQ(compilationAlbum.GetTrackCount(), 2);
    ASSERT_EQ(compilationAlbum.GetTotalDuration(), 229);
    ASSERT_EQ(compilationAlbum.GetTrackList(), "Boys Interface\nOneShot\n");
}
