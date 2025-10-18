#ifndef EXCEPTIONS
#define EXCEPTIONS
#include <string>
#include <exception>

class Exception : public std::exception {
public:
    explicit Exception(const char *message);
    const char *what() const noexcept override;

private:
    std::string message_;
};


class ExceptionIncorrectTrack : public Exception {
public:
    explicit ExceptionIncorrectTrack(const char *message);
};

class ExceptionIncorrectAlbum : public Exception {
public:
    explicit ExceptionIncorrectAlbum(const char *message);
};

class ExceptionTrackLimit : public Exception {
public:
    explicit ExceptionTrackLimit(const char *message);
};

class ExceptionInvalidGenre : public Exception {
public:
    explicit ExceptionInvalidGenre(const char *message);
};

class ExceptionTrackReleased : public Exception {
public:
    explicit ExceptionTrackReleased(const char *message);
};

class ExceptionTrackPaused : public Exception {
public:
    explicit ExceptionTrackPaused(const char *message);
};

class ExceptionTrackPlaying : public Exception {
public:
    explicit ExceptionTrackPlaying(const char *message);
};

class ExceptionIncorrectVolume : public Exception {
public:
    explicit ExceptionIncorrectVolume(const char *message);
};

class ExceptionIncorrectDuration : public Exception {
public:
    explicit ExceptionIncorrectDuration(const char *message);
};

class ExceptionInvalidPassword : public Exception {
public:
    explicit ExceptionInvalidPassword(const char *message);
};

class ExceptionInvalidEmail : public Exception {
public:
    explicit ExceptionInvalidEmail(const char *message);
};

class ExceptionIncorrectArtist : public Exception {
public:
    explicit ExceptionIncorrectArtist(const char *message);
};

#endif