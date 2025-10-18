#include "gtest/gtest.h"
#include "../Buttons/MarkFavouriteButton/mark_favourite_button.h"

class TestingMarkFavouriteButton : public ::testing::Test
{
protected:
    void SetUp() override
    {
        std::vector<Track> tracks = {
            Track("Killer", "", 1823479, "Artemdjdj",96, GenreType::Blues),
            Track("Kerosene", "", 408600,"Artemdjdj",153, GenreType::Blues),
        };
        favouritePlaylist = FavouritePlaylist("MyFavouritePlaylist", tracks);
        markFavouriteButton = MarkFavouriteButton(100, 200);
    }

    FavouritePlaylist favouritePlaylist;
    MarkFavouriteButton markFavouriteButton;
};

TEST_F(TestingMarkFavouriteButton, TestSetWidth)
{
    ASSERT_EQ(markFavouriteButton.GetWidth(), 100);
    markFavouriteButton.SetWidth(150);
    ASSERT_EQ(markFavouriteButton.GetWidth(), 150);
}

TEST_F(TestingMarkFavouriteButton, TestGetWidth)
{
    ASSERT_EQ(markFavouriteButton.GetWidth(), 100);
}

TEST_F(TestingMarkFavouriteButton, TestSetHeight)
{
    ASSERT_EQ(markFavouriteButton.GetHeight(), 200);
    markFavouriteButton.SetHeight(400);
    ASSERT_EQ(markFavouriteButton.GetHeight(), 400);
}

TEST_F(TestingMarkFavouriteButton, TestGetHeight)
{
    ASSERT_EQ(markFavouriteButton.GetHeight(), 200);
}

TEST_F(TestingMarkFavouriteButton, TestMarkFavourite)
{
    testing::internal::CaptureStdout();
    auto track = Track("28 Days Later", "", 1341515, "Artemdjdj",146, GenreType::Blues);
    markFavouriteButton.MarkFavourite(track, favouritePlaylist);
    ASSERT_EQ(favouritePlaylist.GetTrackCount(), 3);
    ASSERT_TRUE(track.IsFavourite());
    markFavouriteButton.MarkFavourite(track, favouritePlaylist);
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_FALSE(output.empty());
    ASSERT_EQ(output, "This track is already in playlist");
}

TEST_F(TestingMarkFavouriteButton, TestMarkUnmarkFavourite)
{
    testing::internal::CaptureStdout();
    auto track = Track("28 Days Later", "", 1341515, "Artemdjdj",146, GenreType::Blues);
    markFavouriteButton.MarkFavourite(track, favouritePlaylist);
    ASSERT_EQ(favouritePlaylist.GetTrackCount(), 3);
    ASSERT_TRUE(track.IsFavourite());
    markFavouriteButton.UnmarkFavourite(track, favouritePlaylist);
    ASSERT_EQ(favouritePlaylist.GetTrackCount(), 2);
    ASSERT_FALSE(track.IsFavourite());
    markFavouriteButton.UnmarkFavourite(track, favouritePlaylist);
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_FALSE(output.empty());
    ASSERT_EQ(output, "This track is not in playlist");
}

TEST(TestMarkFavouriteButton, TestConstructor)
{
    auto markFavouriteButton = MarkFavouriteButton(120, 370);
    ASSERT_EQ(markFavouriteButton.GetWidth(), 120);
    ASSERT_EQ(markFavouriteButton.GetHeight(), 370);
}
