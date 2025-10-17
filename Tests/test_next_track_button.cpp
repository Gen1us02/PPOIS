#include "gtest/gtest.h"
#include "../Buttons/NextTrackButton/next_track_button.h"

class TestingNextTrackButton : public ::testing::Test
{
protected:
    void SetUp() override
    {
        nextTrackButton = NextTrackButton(100, 200);
    }

    NextTrackButton nextTrackButton;
};

TEST_F(TestingNextTrackButton, TestSetWidth)
{
    ASSERT_EQ(nextTrackButton.GetWidth(), 100);
    nextTrackButton.SetWidth(150);
    ASSERT_EQ(nextTrackButton.GetWidth(), 150);
}

TEST_F(TestingNextTrackButton, TestGetWidth)
{
    ASSERT_EQ(nextTrackButton.GetWidth(), 100);
}

TEST_F(TestingNextTrackButton, TestSetHeight)
{
    ASSERT_EQ(nextTrackButton.GetHeight(), 200);
    nextTrackButton.SetHeight(400);
    ASSERT_EQ(nextTrackButton.GetHeight(), 400);
}

TEST_F(TestingNextTrackButton, TestGetHeight)
{
    ASSERT_EQ(nextTrackButton.GetHeight(), 200);
}

TEST_F(TestingNextTrackButton, TestGetNextTrack)
{
    int index = 0;
    nextTrackButton.GetNextTrackIndex(index);
    ASSERT_EQ(index, 1);
    nextTrackButton.GetNextTrackIndex(index);
    ASSERT_EQ(index, 2);
}

TEST(TestNextTrackButton, TestConstructor)
{
    auto nextTrackButton = NextTrackButton(120, 370);
    ASSERT_EQ(nextTrackButton.GetWidth(), 120);
    ASSERT_EQ(nextTrackButton.GetHeight(), 370);
}
