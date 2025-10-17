#include "gtest/gtest.h"
#include "../Track/track.h"

class TestingTrack : public ::testing::Test
{
protected:
    void SetUp() override
    {
        track = Track("Трава у дома",
                      "Земля в иллюминаторе\nЗемля в иллюминаторе\nЗемля в иллюминаторе\nКак сын грустит о матери как сын грустит о матери",
                      100000 ,200, GenreType::Blues);
    }

    Track track;
};

TEST_F(TestingTrack, TestSetName)
{
    ASSERT_EQ(track.GetName(), "Трава у дома");
    track.SetName("Прекрасное далеко");
    ASSERT_EQ(track.GetName(), "Прекрасное далеко");
}

TEST_F(TestingTrack, TestGetName)
{
    ASSERT_EQ(track.GetName(), "Трава у дома");
}

TEST_F(TestingTrack, TestSetText)
{
    ASSERT_EQ(track.GetText(),
              "Земля в иллюминаторе\nЗемля в иллюминаторе\nЗемля в иллюминаторе\nКак сын грустит о матери как сын грустит о матери");
    track.SetText(
        "А мы летим орбитами\nПутями не избитыми\nПрошит метеоритами простор\nОправдан риск и мужество космическая музыка");
    ASSERT_EQ(track.GetText(),
              "А мы летим орбитами\nПутями не избитыми\nПрошит метеоритами простор\nОправдан риск и мужество космическая музыка");
}

TEST_F(TestingTrack, TestGetText)
{
    ASSERT_EQ(track.GetText(),
              "Земля в иллюминаторе\nЗемля в иллюминаторе\nЗемля в иллюминаторе\nКак сын грустит о матери как сын грустит о матери");
}

TEST_F(TestingTrack, TestSetListenings)
{
    ASSERT_EQ(track.GetListenings(), 100000);
    track.SetListenings(23678090);
    ASSERT_EQ(track.GetListenings(), 23678090);
}

TEST_F(TestingTrack, TestGetListenings)
{
    ASSERT_EQ(track.GetListenings(), 100000);
}

TEST_F(TestingTrack, TestSetDuration)
{
    ASSERT_EQ(track.GetDuration(), 200);
    track.SetDuration(450);
    ASSERT_EQ(track.GetDuration(), 450);
}

TEST_F(TestingTrack, TestGetDuration)
{
    ASSERT_EQ(track.GetDuration(), 200);
}

TEST_F(TestingTrack, TestMarkFavourite)
{
    ASSERT_FALSE(track.IsFavourite());
    track.MarkFavourite();
    ASSERT_TRUE(track.IsFavourite());
}

TEST_F(TestingTrack, TestUnmarkFavourite)
{
    track.MarkFavourite();
    ASSERT_TRUE(track.IsFavourite());
    track.UnmarkFavourite();
    ASSERT_FALSE(track.IsFavourite());
}

TEST_F(TestingTrack, TestIsFavourite)
{
    ASSERT_FALSE(track.IsFavourite());
}

TEST_F(TestingTrack, TestPlay)
{
    ASSERT_FALSE(track.IsPlaying());
    track.Play();
    ASSERT_TRUE(track.IsPlaying());
}

TEST_F(TestingTrack, TestPause)
{
    track.Play();
    ASSERT_TRUE(track.IsPlaying());
    track.Pause();
    ASSERT_FALSE(track.IsPlaying());
}

TEST_F(TestingTrack, TestIsPlaying)
{
    ASSERT_FALSE(track.IsPlaying());
}

TEST_F(TestingTrack, TestSetGenre)
{
    ASSERT_EQ(track.GetGenreType(), "Blues");
    track.SetGenreType(GenreType::Phonk);
    ASSERT_EQ(track.GetGenreType(), "Phonk");
}

TEST_F(TestingTrack, TestGetGenre)
{
    ASSERT_EQ(track.GetGenreType(), "Blues");
}

TEST(TestTrack, TestConstructor)
{
    auto track = Track("Pulse", "", 1500000,300, GenreType::Phonk);
    ASSERT_EQ(track.GetName(), "Pulse");
    ASSERT_EQ(track.GetText(), "");
    ASSERT_EQ(track.GetListenings(), 1500000);
    ASSERT_EQ(track.GetDuration(), 300);
}
