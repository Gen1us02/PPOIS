#include "gtest/gtest.h"
#include "../Buttons/NowPlayingButton/now_playing_button.h"

class TestingNowPlayingButton : public ::testing::Test
{
protected:
    void SetUp() override
    {
        nowPlayingButton = NowPlayingButton(100, 200);
    }

    NowPlayingButton nowPlayingButton;
};

TEST_F(TestingNowPlayingButton, TestSetWidth)
{
    ASSERT_EQ(nowPlayingButton.GetWidth(), 100);
    nowPlayingButton.SetWidth(150);
    ASSERT_EQ(nowPlayingButton.GetWidth(), 150);
}

TEST_F(TestingNowPlayingButton, TestGetWidth)
{
    ASSERT_EQ(nowPlayingButton.GetWidth(), 100);
}

TEST_F(TestingNowPlayingButton, TestSetHeight)
{
    ASSERT_EQ(nowPlayingButton.GetHeight(), 200);
    nowPlayingButton.SetHeight(400);
    ASSERT_EQ(nowPlayingButton.GetHeight(), 400);
}

TEST_F(TestingNowPlayingButton, TestGetHeight)
{
    ASSERT_EQ(nowPlayingButton.GetHeight(), 200);
}

TEST_F(TestingNowPlayingButton, TestShowNowPlayingTrackInfo)
{
    auto track = Track("28 Days Later", "", 1341515, "Artemdjdj",146, GenreType::Blues);
    ASSERT_EQ(nowPlayingButton.ShowNowPlayingTrackInfo(track), "28 Days Later\nArtemdjdj");
}

TEST(TestNowPlayingButton, TestConstructor)
{
    auto nowPlayingButton = NowPlayingButton(120, 370);
    ASSERT_EQ(nowPlayingButton.GetWidth(), 120);
    ASSERT_EQ(nowPlayingButton.GetHeight(), 370);
}
