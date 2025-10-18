#include "gtest/gtest.h"
#include "../Bars/TrackDurationBar/track_duration_bar.h"
#include "../Track/track.h"

class TestingTrackDurationBar : public ::testing::Test
{
protected:
    void SetUp() override
    {
        track = Track("Dancing Nihilist", "", 3853903, "Artemdjdj",156, GenreType::Phonk);
        int duration = track.GetDuration();
        trackDurationBar = TrackDurationBar(100, duration);
    }

    TrackDurationBar trackDurationBar;
    Track track;
};

TEST_F(TestingTrackDurationBar, TestSetLength)
{
    ASSERT_EQ(trackDurationBar.GetLength(), 100);
    trackDurationBar.SetLength(200);
    ASSERT_EQ(trackDurationBar.GetLength(), 200);
}

TEST_F(TestingTrackDurationBar, TestGetLength)
{
    ASSERT_EQ(trackDurationBar.GetLength(), 100);
}

TEST_F(TestingTrackDurationBar, TestSetDuration)
{
    auto track = Track("Bad Boys", "Bad boys bad boys what you gonna do when they come for you", 8370593, "Artemdjdj",139,
                       GenreType::Rap);
    ASSERT_EQ(trackDurationBar.GetDuration(), 156);
    trackDurationBar.SetDuration(track.GetDuration());
    ASSERT_EQ(trackDurationBar.GetDuration(), 139);
}

TEST_F(TestingTrackDurationBar, TestGetDuration)
{
    ASSERT_EQ(trackDurationBar.GetDuration(), 156);
}

TEST_F(TestingTrackDurationBar, TestRewindTrackDuration)
{
    ASSERT_EQ(trackDurationBar.RewindTrackDuration(78), "Трек перемотан на время 78");
    ASSERT_THROW(trackDurationBar.RewindTrackDuration(345), ExceptionIncorrectDuration);
    ASSERT_THROW(trackDurationBar.RewindTrackDuration(-435), ExceptionIncorrectDuration);
}

TEST(TestTrackDurationBar, TestConstructor)
{
    auto trackDurationBar = TrackDurationBar(120, 192);
    ASSERT_EQ(trackDurationBar.GetLength(), 120);
    ASSERT_EQ(trackDurationBar.GetDuration(), 192);
}
