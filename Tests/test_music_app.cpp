#include "gtest/gtest.h"
#include "../MusicApp/music_app.h"

class TestingMusicApp : public ::testing::Test
{
protected:
    void SetUp() override
    {
        auto artist = Artist("Иван", 30, 150000, "ivan_artist");
        auto track1 = Track("Утренний трек", "Иван Иванов", 1000000, "ivan_artist", 180, GenreType::Phonk);
        auto track2 = Track("Вечерний трек", "Иван Иванов", 2000000, "ivan_artist", 240, GenreType::Rock);
        auto track3 = Track("Ночной трек", "Петр Петров", 1500000, "peter_artist", 200, GenreType::Jazz);

        std::vector<Track> tracks = {track1, track2};
        auto queue = Queue(tracks);

        auto user = User("Евгений", "Кулик", 25, "example@mail.com", "user", "M40815m@");
        std::unordered_set<GenreType> preferences = {GenreType::Phonk, GenreType::Rock};
        auto profile = Profile(user, "Люблю музыку", "Male", preferences);

        std::vector<ArtistPlaylist> artistsPlaylists = {ArtistPlaylist(artist, "ivan_artist")};
        std::vector<GenrePlaylist> genrePlaylists = {GenrePlaylist("Hits", {track1}, GenreType::Phonk)};
        auto favouritePlaylist = FavouritePlaylist("MyFavorites", {track1});
        auto mediaLibrary = MediaLibrary("MyLibrary", artistsPlaylists, genrePlaylists, favouritePlaylist);

        auto artistInfoButton = ArtistInfoButton(100, 50);
        auto markFavouriteButton = MarkFavouriteButton(100, 50);
        auto nextTrackButton = NextTrackButton(100, 50);
        auto previousTrackButton = PreviousTrackButton(100, 50);
        auto nowPlayingButton = NowPlayingButton(100, 50);
        auto playButton = PlayButton(100, 50);
        auto trackTextButton = TrackTextButton(100, 50);
        auto volumeButton = VolumeButton(100, 50);
        auto trackDurationBar = TrackDurationBar(200, 300);
        auto volumeBar = VolumeBar(150);

        musicApp = MusicApp(artistInfoButton, markFavouriteButton, nextTrackButton,
                           previousTrackButton, nowPlayingButton, playButton,
                           trackTextButton, volumeButton, trackDurationBar,
                           volumeBar, queue, profile, mediaLibrary);
    }

    MusicApp musicApp;
};

TEST_F(TestingMusicApp, TestPlayTrack)
{
    testing::internal::CaptureStdout();
    auto track = Track("Тестовый трек", "Тестовый артист", 1000000, "test_artist", 180, GenreType::Phonk);
    musicApp.AddTrackToQueue(track);
    ASSERT_NO_THROW(musicApp.PlayTrack());
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_FALSE(output.empty());
    ASSERT_EQ(output, "Иван Иванов\n");
}

TEST_F(TestingMusicApp, TestPauseTrack)
{
    testing::internal::CaptureStdout();
    musicApp.PlayTrack();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_FALSE(output.empty());
    ASSERT_EQ(output, "Иван Иванов\n");
    ASSERT_EQ(musicApp.PauseTrack(), "Track paused");
    ASSERT_EQ(musicApp.PauseTrack(), "Track is not playing");
}

TEST_F(TestingMusicApp, TestVolumeOperations)
{
    ASSERT_EQ(musicApp.TurnOffVolume(), "Volume disabled");
    ASSERT_EQ(musicApp.TurnOnVolume(), "Volume enabled");
}

TEST_F(TestingMusicApp, TestSetVolume)
{
   ASSERT_EQ(musicApp.SetVolume(56), "Значение звука установлено на 56");
   ASSERT_EQ(musicApp.SetVolume(120),"The volume is out of range." );
}

TEST_F(TestingMusicApp, TestShowProfileInfo)
{
    std::string result = musicApp.ShowProfileInfo();

    ASSERT_TRUE(result.find("Имя: Евгений") != std::string::npos);
    ASSERT_TRUE(result.find("Фамилия: Кулик") != std::string::npos);
    ASSERT_TRUE(result.find("Возраст: 25") != std::string::npos);
    ASSERT_TRUE(result.find("Имя пользователя: user") != std::string::npos);
    ASSERT_TRUE(result.find("Email: example@mail.com") != std::string::npos);
    ASSERT_TRUE(result.find("Пароль: M40815m@") != std::string::npos);
    ASSERT_TRUE(result.find("Описание профиля: Люблю музыку") != std::string::npos);
    ASSERT_TRUE(result.find("Пол: Male") != std::string::npos);
    ASSERT_TRUE(result.find("Phonk") != std::string::npos);
    ASSERT_TRUE(result.find("Rock") != std::string::npos);
}

TEST_F(TestingMusicApp, TestQueueOperations)
{
    auto newTrack = Track("Новый трек", "Новый артист", 1200000, "new_artist", 210, GenreType::Phonk);

    ASSERT_NO_THROW(musicApp.AddTrackToQueue(newTrack));
    ASSERT_NO_THROW(musicApp.RemoveTrackFromQueue(newTrack));
}

TEST_F(TestingMusicApp, TestFavouriteTrackOperations)
{

    auto track = Track("Трек для избранного", "Артист", 900000, "artist", 160, GenreType::Blues);
    musicApp.AddTrackToQueue(track);
    musicApp.NextTrack();

    ASSERT_NO_THROW(musicApp.MarkFavouriteTrack());
    ASSERT_NO_THROW(musicApp.UnmarkFavouriteTrack());
}

TEST_F(TestingMusicApp, TestNowPlayingTrackInfo)
{
    ASSERT_EQ(musicApp.ShowNowPlayingTrackInfo(), "Утренний трек\nivan_artist");

}

TEST_F(TestingMusicApp, TestTrackNavigation)
{
    ASSERT_NO_THROW(musicApp.NextTrack());

    auto afterNext = musicApp.ShowNowPlayingTrackInfo();
    ASSERT_FALSE(afterNext.empty());

    ASSERT_NO_THROW(musicApp.PreviousTrack());

    auto afterPrevious = musicApp.ShowNowPlayingTrackInfo();
    ASSERT_FALSE(afterPrevious.empty());
}

TEST_F(TestingMusicApp, TestArtistInfo)
{
    auto artist = Artist("Елена Прекрасная", 28, 500000, "elena_singer");
    auto result = musicApp.ShowArtistInfo(artist);

    ASSERT_FALSE(result.empty());
    ASSERT_TRUE(result.find("Елена Прекрасная") != std::string::npos);
    ASSERT_TRUE(result.find("28") != std::string::npos);
}

TEST_F(TestingMusicApp, TestVolumeSequence)
{
    ASSERT_NO_THROW(musicApp.SetVolume(50));
    ASSERT_NO_THROW(musicApp.TurnOffVolume());
    ASSERT_NO_THROW(musicApp.TurnOnVolume());
    ASSERT_NO_THROW(musicApp.SetVolume(80));

    auto volumeOff = musicApp.TurnOffVolume();
    ASSERT_EQ(volumeOff, "Volume disabled");

    auto volumeOn = musicApp.TurnOnVolume();
    ASSERT_EQ(volumeOn, "Volume enabled");
}

TEST(TestMusicApp, TestConstructorWithDifferentParameters)
{
    auto artist = Artist("Тестовый артист", 35, 100000, "test_artist");
    auto track = Track("Тестовый трек", "Тестовый артист", 1000000, "test_artist", 180, GenreType::Phonk);
    std::vector<Track> tracks = {track};
    auto queue = Queue(tracks);

    auto user = User("Евгений", "Кулик", 30, "test@mail.com", "user", "M40815m@");
    std::unordered_set<GenreType> preferences = {GenreType::Phonk};
    auto profile = Profile(user, "", "Male", preferences);

    std::vector<ArtistPlaylist> artistsPlaylists = {ArtistPlaylist(artist, "test_artist")};
    std::vector<GenrePlaylist> genrePlaylists = {GenrePlaylist("Поп-музыка", tracks, GenreType::Phonk)};
    auto favouritePlaylist = FavouritePlaylist("Избранное", tracks);
    auto mediaLibrary = MediaLibrary("MyTestLibrary", artistsPlaylists, genrePlaylists, favouritePlaylist);

    auto artistInfoButton = ArtistInfoButton(120, 60);
    auto markFavouriteButton = MarkFavouriteButton(120, 60);
    auto nextTrackButton = NextTrackButton(120, 60);
    auto previousTrackButton = PreviousTrackButton(120, 60);
    auto nowPlayingButton = NowPlayingButton(120, 60);
    auto playButton = PlayButton(120, 60);
    auto trackTextButton = TrackTextButton(120, 60);
    auto volumeButton = VolumeButton(120, 60);
    auto trackDurationBar = TrackDurationBar(250, 360);
    auto volumeBar = VolumeBar(180);

    auto musicApp = MusicApp(artistInfoButton, markFavouriteButton, nextTrackButton,
                            previousTrackButton, nowPlayingButton, playButton,
                            trackTextButton, volumeButton, trackDurationBar,
                            volumeBar, queue, profile, mediaLibrary);

    auto profileInfo = musicApp.ShowProfileInfo();
    ASSERT_TRUE(profileInfo.find("Имя: Евгений") != std::string::npos);
    ASSERT_TRUE(profileInfo.find("Фамилия: Кулик") != std::string::npos);
    ASSERT_TRUE(profileInfo.find("Возраст: 30") != std::string::npos);
    ASSERT_TRUE(profileInfo.find("Имя пользователя: user") != std::string::npos);
    ASSERT_TRUE(profileInfo.find("Email: test@mail.com") != std::string::npos);
    ASSERT_TRUE(profileInfo.find("Пароль: M40815m@") != std::string::npos);
    ASSERT_TRUE(profileInfo.find("Описание профиля:") != std::string::npos);
    ASSERT_TRUE(profileInfo.find("Пол: Male") != std::string::npos);
    ASSERT_TRUE(profileInfo.find("Phonk") != std::string::npos);
    ASSERT_EQ(musicApp.SetVolume(50), "Значение звука установлено на 50");
}