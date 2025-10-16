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
