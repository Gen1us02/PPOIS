#include "gtest/gtest.h"
#include "../Buttons/ArtistInfoButton/artist_info_button.h"

class TestingArtistInfoButton : public ::testing::Test
{
protected:
    void SetUp() override
    {
        artistInfoButton = ArtistInfoButton(100, 200);
    }

    ArtistInfoButton artistInfoButton;
};

TEST_F(TestingArtistInfoButton, TestSetWidth)
{
    ASSERT_EQ(artistInfoButton.GetWidth(), 100);
    artistInfoButton.SetWidth(150);
    ASSERT_EQ(artistInfoButton.GetWidth(), 150);
}

TEST_F(TestingArtistInfoButton, TestGetWidth)
{
    ASSERT_EQ(artistInfoButton.GetWidth(), 100);
}

TEST_F(TestingArtistInfoButton, TestSetHeight)
{
    ASSERT_EQ(artistInfoButton.GetHeight(), 200);
    artistInfoButton.SetHeight(400);
    ASSERT_EQ(artistInfoButton.GetHeight(), 400);
}

TEST_F(TestingArtistInfoButton, TestGetHeight)
{
    ASSERT_EQ(artistInfoButton.GetHeight(), 200);
}

TEST_F(TestingArtistInfoButton, TestGetArtistInfo)
{
    auto artist = Artist("Иван", 30, 1000000, "VaN0");
    ASSERT_EQ(artistInfoButton.GetArtistInfo(artist), "Имя: Иван\nВозраст: 30\nСлушателей в месяц: 1000000\nПсевдоним: VaN0");
}

TEST(TestArtistInfoButton, TestConstructor)
{
    auto artistInfoButton = ArtistInfoButton(120, 370);
    ASSERT_EQ(artistInfoButton.GetWidth(), 120);
    ASSERT_EQ(artistInfoButton.GetHeight(), 370);
}
