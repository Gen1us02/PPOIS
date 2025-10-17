#include "gtest/gtest.h"
#include "../Buttons/PreviousTrackButton/previous_track_button.h"

class TestingPreviousTrackButton : public ::testing::Test
{
protected:
    void SetUp() override
    {
        previousTrackButton = PreviousTrackButton(100, 200);
    }

    PreviousTrackButton previousTrackButton;
};

TEST_F(TestingPreviousTrackButton, TestSetWidth)
{
    ASSERT_EQ(previousTrackButton.GetWidth(), 100);
    previousTrackButton.SetWidth(150);
    ASSERT_EQ(previousTrackButton.GetWidth(), 150);
}

TEST_F(TestingPreviousTrackButton, TestGetWidth)
{
    ASSERT_EQ(previousTrackButton.GetWidth(), 100);
}

TEST_F(TestingPreviousTrackButton, TestSetHeight)
{
    ASSERT_EQ(previousTrackButton.GetHeight(), 200);
    previousTrackButton.SetHeight(400);
    ASSERT_EQ(previousTrackButton.GetHeight(), 400);
}

TEST_F(TestingPreviousTrackButton, TestGetHeight)
{
    ASSERT_EQ(previousTrackButton.GetHeight(), 200);
}

TEST_F(TestingPreviousTrackButton, TestGetPreviousTrack)
{
    int index = 5;
    previousTrackButton.GetPreviousTrackIndex(index);
    ASSERT_EQ(index, 4);
    previousTrackButton.GetPreviousTrackIndex(index);
    ASSERT_EQ(index, 3);
}

TEST(TestPreviousTrackButton, TestConstructor)
{
    auto previousTrackButton = PreviousTrackButton(120, 370);
    ASSERT_EQ(previousTrackButton.GetWidth(), 120);
    ASSERT_EQ(previousTrackButton.GetHeight(), 370);
}
