#include "gtest/gtest.h"
#include "../Buttons/PlayButton/play_button.h"

class TestingPlayButton : public ::testing::Test
{
protected:
    void SetUp() override
    {
        playButton = PlayButton(100, 200);
    }

    PlayButton playButton;
};

TEST_F(TestingPlayButton, TestSetWidth)
{
    ASSERT_EQ(playButton.GetWidth(), 100);
    playButton.SetWidth(150);
    ASSERT_EQ(playButton.GetWidth(), 150);
}

TEST_F(TestingPlayButton, TestGetWidth)
{
    ASSERT_EQ(playButton.GetWidth(), 100);
}

TEST_F(TestingPlayButton, TestSetHeight)
{
    ASSERT_EQ(playButton.GetHeight(), 200);
    playButton.SetHeight(400);
    ASSERT_EQ(playButton.GetHeight(), 400);
}

TEST_F(TestingPlayButton, TestGetHeight)
{
    ASSERT_EQ(playButton.GetHeight(), 200);
}

TEST_F(TestingPlayButton, TestPlayTrack)
{
    testing::internal::CaptureStdout();
    auto track = Track("Smells like teen spirit", "With the lights out, it's less dangerous\n", 0, "Artemdjdj",100,
                       GenreType::Blues);
    playButton.PlayTrack(track);
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_FALSE(output.empty());
    ASSERT_EQ(output, "With the lights out, it's less dangerous\n");
    ASSERT_TRUE(track.IsPlaying());
    ASSERT_THROW(playButton.PlayTrack(track), ExceptionTrackPlaying);
}

TEST_F(TestingPlayButton, TestPauseTrack)
{
    auto track = Track("Smells like teen spirit", "With the lights out, it's less dangerous\n", 0, "Artemdjdj",100,
                       GenreType::Blues);
    track.Play();
    ASSERT_EQ(playButton.PauseTrack(track), "Track paused");
    ASSERT_FALSE(track.IsPlaying());
    ASSERT_THROW(playButton.PauseTrack(track), ExceptionTrackPaused);
}

TEST(TestPlayButton, TestConstructor)
{
    auto playButton = PlayButton(120, 370);
    ASSERT_EQ(playButton.GetWidth(), 120);
    ASSERT_EQ(playButton.GetHeight(), 370);
}
