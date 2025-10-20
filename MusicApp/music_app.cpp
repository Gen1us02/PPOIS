#include "music_app.h"

MusicApp::MusicApp() = default;

MusicApp::~MusicApp() = default;

MusicApp::MusicApp(const ArtistInfoButton& artistInfoButton, const MarkFavouriteButton& markFavouriteButton,
                   const NextTrackButton& nextTrackButton, const PreviousTrackButton& previousTrackButton,
                   const NowPlayingButton& nowPlayingButton, const PlayButton& playButton,
                   const TrackTextButton& trackTextButton, const VolumeButton& volumeButton,
                   const TrackDurationBar& trackDurationBar, const VolumeBar& volumeBar, const Queue& queue,
                   const Profile& profile, const MediaLibrary& mediaLibrary) : artistInfoButton_(artistInfoButton),
                                                                               markFavouriteButton_(
                                                                                   markFavouriteButton),
                                                                               nextTrackButton_(nextTrackButton),
                                                                               previousTrackButton_(
                                                                                   previousTrackButton),
                                                                               nowPlayingButton_(nowPlayingButton),
                                                                               playButton_(playButton),
                                                                               trackTextButton_(trackTextButton),
                                                                               volumeButton_(volumeButton),
                                                                               trackDurationBar_(trackDurationBar),
                                                                               volumeBar_(volumeBar), queue_(queue),
                                                                               profile_(profile),
                                                                               mediaLibrary_(mediaLibrary)

{
    this->currentTrack_ = queue_.GetTracks()[0];
}

void MusicApp::PlayTrack()
{
    try
    {
        playButton_.PlayTrack(this->currentTrack_);
    }
    catch (const ExceptionTrackPlaying& ex)
    {
        std::cout << ex.what();
    }
}

std::string MusicApp::PauseTrack()
{
    try
    {
        return playButton_.PauseTrack(this->currentTrack_);
    }
    catch (const ExceptionTrackPaused& ex)
    {
        return ex.what();
    }

}

std::string MusicApp::TurnOffVolume()
{
    volumeButton_.DisableVolume(this->currentVolume_);
    return "Volume disabled";
}

std::string MusicApp::TurnOnVolume()
{
    volumeButton_.EnableVolume(this->currentVolume_, this->lastVolume_);
    return "Volume enabled";
}

std::string MusicApp::SetVolume(int volume)
{
    try
    {
        return volumeBar_.SetVolume(volume);
    }
    catch (const ExceptionIncorrectVolume& ex)
    {
        return ex.what();
    }
}

std::string MusicApp::ShowProfileInfo()
{
    return profile_.GetProfileInfo();
}

void MusicApp::AddTrackToQueue(const Track& track)
{
    try
    {
        queue_.AddTrack(track);
    }
    catch (const ExceptionIncorrectTrack& ex)
    {
        std::cout << ex.what();
    }
}

void MusicApp::RemoveTrackFromQueue(const Track& track)
{
    try
    {
        queue_.RemoveTrack(track);
    }
    catch (const ExceptionIncorrectTrack& ex)
    {
        std::cout << ex.what();
    }
}

void MusicApp::MarkFavouriteTrack()
{
    try
    {
        markFavouriteButton_.MarkFavourite(this->currentTrack_, mediaLibrary_.GetFavouritePlaylist());
    }
    catch (const ExceptionMarkFailed& ex)
    {
        std::cout << ex.what();
    }
}

void MusicApp::UnmarkFavouriteTrack()
{
    try
    {
        markFavouriteButton_.UnmarkFavourite(this->currentTrack_, mediaLibrary_.GetFavouritePlaylist());
    }
    catch (const ExceptionUnmarkFailed& ex)
    {
        std::cout << ex.what();
    }
}

std::string MusicApp::ShowNowPlayingTrackInfo() const
{
    return nowPlayingButton_.ShowNowPlayingTrackInfo(this->currentTrack_);
}

void MusicApp::NextTrack()
{
    nextTrackButton_.GetNextTrackIndex(this->currentTrackIndex_);
    if (this->currentTrackIndex_ >= 0 && this->currentTrackIndex_ < queue_.GetTracks().size())
    {
        this->currentTrack_ = queue_.GetTracks()[this->currentTrackIndex_];
        trackDurationBar_.SetDuration(this->currentTrack_.GetDuration());
    }
}

void MusicApp::PreviousTrack()
{
    previousTrackButton_.GetPreviousTrackIndex(this->currentTrackIndex_);
    if (this->currentTrackIndex_ >= 0 && this->currentTrackIndex_ <= queue_.GetTracks().size())
    {
        this->currentTrack_ = queue_.GetTracks()[this->currentTrackIndex_];
        trackDurationBar_.SetDuration(this->currentTrack_.GetDuration());
    }
}

std::string MusicApp::ShowArtistInfo(const Artist& artist)
{
    return artistInfoButton_.GetArtistInfo(artist);
}
