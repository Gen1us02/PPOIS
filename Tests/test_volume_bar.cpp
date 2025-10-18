#include "gtest/gtest.h"
#include "../Bars/VolumeBar/volume_bar.h"

class TestingVolumeBar : public ::testing::Test
{
protected:
    void SetUp() override
    {
        volumeBar = VolumeBar(100);
    }

    VolumeBar volumeBar;
};

TEST_F(TestingVolumeBar, TestSetLength)
{
    ASSERT_EQ(volumeBar.GetLength(), 100);
    volumeBar.SetLength(200);
    ASSERT_EQ(volumeBar.GetLength(), 200);
}

TEST_F(TestingVolumeBar, TestGetLength)
{
    ASSERT_EQ(volumeBar.GetLength(), 100);
}

TEST_F(TestingVolumeBar, TestSetVolume)
{
   ASSERT_EQ(volumeBar.SetVolume(67), "Значение звука установлено на 67");
   ASSERT_THROW(volumeBar.SetVolume(128), ExceptionIncorrectVolume);
   ASSERT_THROW(volumeBar.SetVolume(-34), ExceptionIncorrectVolume);
}

TEST(TestVolumeBar, TestConstructor)
{
    auto volumeBar = VolumeBar(120);
    ASSERT_EQ(volumeBar.GetLength(), 120);
}
