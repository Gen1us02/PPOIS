#include "gtest/gtest.h"
#include "../Buttons/TrackTextButton/track_text_button.h"

class TestingTrackTextButton : public ::testing::Test
{
protected:
    void SetUp() override
    {
        trackTextButton = TrackTextButton(100, 200);
    }

    TrackTextButton trackTextButton;
};

TEST_F(TestingTrackTextButton, TestSetWidth)
{
    ASSERT_EQ(trackTextButton.GetWidth(), 100);
    trackTextButton.SetWidth(150);
    ASSERT_EQ(trackTextButton.GetWidth(), 150);
}

TEST_F(TestingTrackTextButton, TestGetWidth)
{
    ASSERT_EQ(trackTextButton.GetWidth(), 100);
}

TEST_F(TestingTrackTextButton, TestSetHeight)
{
    ASSERT_EQ(trackTextButton.GetHeight(), 200);
    trackTextButton.SetHeight(400);
    ASSERT_EQ(trackTextButton.GetHeight(), 400);
}

TEST_F(TestingTrackTextButton, TestGetHeight)
{
    ASSERT_EQ(trackTextButton.GetHeight(), 200);
}

TEST_F(TestingTrackTextButton, TestGetTrackText)
{
    auto track = Track("A Real Hero", "Back against the wall and odds", 842348, "Artemdjdj",78, GenreType::Jazz);
    ASSERT_EQ(trackTextButton.GetTrackText(track), "Back against the wall and odds");
}

TEST(TestTrackTextButton, TestConstructor)
{
    auto trackTextButton = TrackTextButton(120, 370);
    ASSERT_EQ(trackTextButton.GetWidth(), 120);
    ASSERT_EQ(trackTextButton.GetHeight(), 370);
}
