#include "gtest/gtest.h"
#include "../Buttons/VolumeButton/volume_button.h"

class TestingVolumeButton : public ::testing::Test
{
protected:
    void SetUp() override
    {
        volumeButton = VolumeButton(100, 200);
    }

    VolumeButton volumeButton;
};

TEST_F(TestingVolumeButton, TestSetWidth)
{
    ASSERT_EQ(volumeButton.GetWidth(), 100);
    volumeButton.SetWidth(150);
    ASSERT_EQ(volumeButton.GetWidth(), 150);
}

TEST_F(TestingVolumeButton, TestGetWidth)
{
    ASSERT_EQ(volumeButton.GetWidth(), 100);
}

TEST_F(TestingVolumeButton, TestSetHeight)
{
    ASSERT_EQ(volumeButton.GetHeight(), 200);
    volumeButton.SetHeight(400);
    ASSERT_EQ(volumeButton.GetHeight(), 400);
}

TEST_F(TestingVolumeButton, TestGetHeight)
{
    ASSERT_EQ(volumeButton.GetHeight(), 200);
}

TEST_F(TestingVolumeButton, TestDisableVolume)
{
    auto volume = 25;
    volumeButton.DisableVolume(volume);
    ASSERT_EQ(volume, 0);
}

TEST_F(TestingVolumeButton, TestEnableVolume)
{
    auto volume = 25;
    auto lastVolume = volume;
    volumeButton.DisableVolume(volume);
    ASSERT_EQ(volume, 0);
    volumeButton.EnableVolume(volume, lastVolume);
    ASSERT_EQ(volume, 25);
}

TEST(TestVolumeButton, TestConstructor)
{
    auto volumeButton = VolumeButton(120, 370);
    ASSERT_EQ(volumeButton.GetWidth(), 120);
    ASSERT_EQ(volumeButton.GetHeight(), 370);
}
