/*! \file exceptions.h
 *  \brief Заголовочный файл с описанием иерархии классов исключений
 *  \details Содержит объявление базового класса Exception и специализированных
 *           классов исключений для различных ошибок в музыкальном приложении.
 */
#ifndef EXCEPTIONS
#define EXCEPTIONS
#include <string>
#include <exception>

/*! \class Exception
 *  \brief Базовый класс для всех исключений в приложении
 *  \details Наследуется от std::exception и предоставляет базовую функциональность
 *           для хранения и отображения сообщений об ошибках.
 */
class Exception : public std::exception
{
public:
    /*! \brief Конструктор с сообщением об ошибке
     *  \param message Сообщение об ошибке
     */
    explicit Exception(const char* message);

    /*! \brief Получить сообщение об ошибке
     *  \return Указатель на строку с сообщением об ошибке
     */
    const char* what() const noexcept override;

private:
    std::string message_; /*!< Сообщение об ошибке */
};

/*! \class ExceptionIncorrectTrack
 *  \brief Исключение для некорректных операций с треком
 *  \details Выбрасывается при попытке выполнить операцию с треком,
 *  который существует или не существует.
 */
class ExceptionIncorrectTrack : public Exception
{
public:
    explicit ExceptionIncorrectTrack(const char* message);
};

/*! \class ExceptionIncorrectAlbum
 *  \brief Исключение для некорректных операций с альбомом
 *  \details Выбрасывается при попытке выполнить операцию с альбомом,
 *  который существует или не существует.
 */
class ExceptionIncorrectAlbum : public Exception
{
public:
    explicit ExceptionIncorrectAlbum(const char* message);
};

/*! \class ExceptionTrackLimit
 *  \brief Исключение для превышения лимита треков
 *  \details Выбрасывается при попытке добавить трек, когда достигнут максимальный лимит.
 */
class ExceptionTrackLimit : public Exception
{
public:
    explicit ExceptionTrackLimit(const char* message);
};

/*! \class ExceptionInvalidGenre
 *  \brief Исключение для недопустимого жанра
 *  \details Выбрасывается при использовании недопустимого или неизвестного музыкального жанра.
 */
class ExceptionInvalidGenre : public Exception
{
public:
    explicit ExceptionInvalidGenre(const char* message);
};

/*! \class ExceptionTrackReleased
 *  \brief Исключение для уже выпущенного трека
 *  \details Выбрасывается при попытке выполнить операцию с уже выпущенным треком.
 */
class ExceptionTrackReleased : public Exception
{
public:
    explicit ExceptionTrackReleased(const char* message);
};

/*! \class ExceptionTrackPaused
 *  \brief Исключение для трека на паузе
 *  \details Выбрасывается при попытке выполнить недопустимую операцию с треком, находящимся на паузе.
 */
class ExceptionTrackPaused : public Exception
{
public:
    explicit ExceptionTrackPaused(const char* message);
};

/*! \class ExceptionTrackPlaying
 *  \brief Исключение для воспроизводящегося трека
 *  \details Выбрасывается при попытке выполнить недопустимую операцию с воспроизводящимся треком.
 */
class ExceptionTrackPlaying : public Exception
{
public:
    explicit ExceptionTrackPlaying(const char* message);
};

/*! \class ExceptionIncorrectVolume
 *  \brief Исключение для некорректной громкости
 *  \details Выбрасывается при установке громкости за пределами допустимого диапазона.
 */
class ExceptionIncorrectVolume : public Exception
{
public:
    explicit ExceptionIncorrectVolume(const char* message);
};

/*! \class ExceptionIncorrectDuration
 *  \brief Исключение для некорректной длительности
 *  \details Выбрасывается при установке некорректной длительности трека.
 */
class ExceptionIncorrectDuration : public Exception
{
public:
    explicit ExceptionIncorrectDuration(const char* message);
};

/*! \class ExceptionInvalidPassword
 *  \brief Исключение для недопустимого пароля
 *  \details Выбрасывается при вводе некорректного или несоответствующего требованиям пароля.
 */
class ExceptionInvalidPassword : public Exception
{
public:
    explicit ExceptionInvalidPassword(const char* message);
};

/*! \class ExceptionInvalidEmail
 *  \brief Исключение для недопустимого email
 *  \details Выбрасывается при вводе некорректного или несоответствующего формату email.
 */
class ExceptionInvalidEmail : public Exception
{
public:
    explicit ExceptionInvalidEmail(const char* message);
};

/*! \class ExceptionIncorrectArtist
 *  \brief Исключение для некорректного исполнителя
 *  \details Выбрасывается при попытке выполнить операцию с некорректным или несуществующим исполнителем.
 */
class ExceptionIncorrectArtist : public Exception
{
public:
    explicit ExceptionIncorrectArtist(const char* message);
};

/*! \class ExceptionIncorrectPlaylist
 *  \brief Исключение для некорректного плейлиста
 *  \details Выбрасывается при попытке выполнить операцию с плейлистом,
 *  который содержится или присутствует в медиатеке или у артиста.
 */
class ExceptionIncorrectPlaylist : public Exception
{
public:
    explicit ExceptionIncorrectPlaylist(const char* message);
};

/*! \class ExceptionMarkFailed
 *  \brief Исключение для неудачного добавления в избранное
 *  \details Выбрасывается при неудачной попытке пометить трек как избранный.
 */
class ExceptionMarkFailed : public Exception
{
public:
    explicit ExceptionMarkFailed(const char* message);
};

/*! \class ExceptionUnmarkFailed
 *  \brief Исключение для неудачного удаления из избранного
 *  \details Выбрасывается при неудачной попытке убрать пометку избранного с трека.
 */
class ExceptionUnmarkFailed : public Exception
{
public:
    explicit ExceptionUnmarkFailed(const char* message);
};

#endif
