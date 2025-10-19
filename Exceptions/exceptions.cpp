#include "exceptions.h"

Exception::Exception(const char* message) : message_(message)
{
}

const char* Exception::what() const noexcept
{
    return message_.c_str();
}

ExceptionIncorrectTrack::ExceptionIncorrectTrack(const char* message) : Exception(message)
{
}

ExceptionIncorrectAlbum::ExceptionIncorrectAlbum(const char* message) : Exception(message)
{
}

ExceptionTrackLimit::ExceptionTrackLimit(const char* message) : Exception(message)
{
}

ExceptionInvalidGenre::ExceptionInvalidGenre(const char* message) : Exception(message)
{
}

ExceptionTrackReleased::ExceptionTrackReleased(const char* message) : Exception(message)
{
}

ExceptionTrackPaused::ExceptionTrackPaused(const char* message) : Exception(message)
{
}

ExceptionTrackPlaying::ExceptionTrackPlaying(const char* message) : Exception(message)
{
}

ExceptionIncorrectVolume::ExceptionIncorrectVolume(const char* message) : Exception(message)
{
}

ExceptionIncorrectDuration::ExceptionIncorrectDuration(const char* message) : Exception(message)
{
}

ExceptionInvalidPassword::ExceptionInvalidPassword(const char* message) : Exception(message)
{
}

ExceptionInvalidEmail::ExceptionInvalidEmail(const char* message) : Exception(message)
{
}

ExceptionIncorrectArtist::ExceptionIncorrectArtist(const char* message) : Exception(message)
{
}

ExceptionIncorrectPlaylist::ExceptionIncorrectPlaylist(const char* message) : Exception(message)
{
}

ExceptionMarkFailed::ExceptionMarkFailed(const char* message) : Exception(message)
{
}
