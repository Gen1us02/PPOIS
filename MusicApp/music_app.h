#ifndef MUSIC_APP
#define MUSIC_APP
#include "../Buttons/ArtistInfoButton/artist_info_button.h"
#include "../Buttons/MarkFavouriteButton/mark_favourite_button.h"
#include "../Buttons/NextTrackButton/next_track_button.h"
#include "../Buttons/PreviousTrackButton/previous_track_button.h"
#include "../Buttons/NowPlayingButton/now_playing_button.h"
#include "../Buttons/PlayButton/play_button.h"
#include "../Buttons/TrackTextButton/track_text_button.h"
#include "../Buttons/VolumeButton/volume_button.h"
#include "../Bars/TrackDurationBar/track_duration_bar.h"
#include "../Bars/VolumeBar/volume_bar.h"
#include "../Queue/queue.h"
#include "../Profile/profile.h"
#include "../MediaLibrary/media_library.h"


class MusicApp
{
public:
    MusicApp();
    ~MusicApp();
    MusicApp(const ArtistInfoButton& artistInfoButton, const MarkFavouriteButton& markFavouriteButton,
             const NextTrackButton& nextTrackButton, const PreviousTrackButton& previousTrackButton,
             const NowPlayingButton& nowPlayingButton, const PlayButton& playButton,
             const TrackTextButton& trackTextButton, const VolumeButton& volumeButton,
             const TrackDurationBar& trackDurationBar, const VolumeBar& volumeBar, const Queue& queue,
             const Profile& profile, const MediaLibrary& mediaLibrary);
    void PlayTrack();
    std::string PauseTrack();
    std::string TurnOffVolume();
    std::string TurnOnVolume();
    std::string SetVolume(int volume);
    std::string ShowArtistInfo(const Artist& artist);
    std::string ShowNowPlayingTrackInfo() const;
    void MarkFavouriteTrack();
    void UnmarkFavouriteTrack();
    void NextTrack();
    void PreviousTrack();
    std::string ShowProfileInfo();
    void AddTrackToQueue(const Track& track);
    void RemoveTrackFromQueue(const Track& track);

private:
    Track currentTrack_;
    int currentTrackIndex_ {0};
    int currentVolume_{0};
    int lastVolume_{0};
    ArtistInfoButton artistInfoButton_;
    MarkFavouriteButton markFavouriteButton_;
    NextTrackButton nextTrackButton_;
    PreviousTrackButton previousTrackButton_;
    NowPlayingButton nowPlayingButton_;
    PlayButton playButton_;
    TrackTextButton trackTextButton_;
    VolumeButton volumeButton_;
    TrackDurationBar trackDurationBar_;
    VolumeBar volumeBar_;
    Queue queue_;
    Profile profile_;
    MediaLibrary mediaLibrary_;
};


#endif
