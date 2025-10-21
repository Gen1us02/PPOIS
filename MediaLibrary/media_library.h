/*! \file media_library.h
 *  \brief Заголовочный файл с описанием класса MediaLibrary
 *  \details Содержит объявление класса MediaLibrary, представляющего медиатеку пользователя.
 *           Класс наследует MediaCollection и реализует интерфейс для управления коллекцией
 *           плейлистов различных типов.
 */
#ifndef MEDIA_LIBRARY
#define MEDIA_LIBRARY
#include "media_collection.h"
#include "../Playlists/GenrePlaylist/genre_playlist.h"
#include "../Playlists/FavouritePlaylist/favourite_playlist.h"
#include "../Playlists/ArtistPlaylist/artist_playlist.h"
#include "../Playlists/DailyPlaylist/daily_playlist.h"
#include "../User/user.h"
#include <vector>
#include <optional>

/*! \class MediaLibrary
 *  \brief Модель медиатеки пользователя
 *  \details MediaLibrary наследуется от MediaCollection и предоставляет методы для управления
 *           коллекцией плейлистов различных типов: плейлисты исполнителей, жанровые плейлисты,
 *           плейлист избранного и ежедневный плейлист.
 */
class MediaLibrary : public MediaCollection
{
public:
    /*! \brief Конструктор по умолчанию
     *  \details Инициализирует медиатеку с пустым названием и пустыми коллекциями плейлистов.
     */
    MediaLibrary();

    /*! \brief Деструктор
     *  \details Обеспечивает корректное уничтожение объекта медиатеки.
     */
    ~MediaLibrary();

    /*! \brief Конструктор с инициализацией параметров
     *  \param title Название медиатеки
     *  \param artistsPlaylists Вектор плейлистов исполнителей
     *  \param genrePlaylists Вектор жанровых плейлистов
     *  \param favouritePlaylist Плейлист избранного
     *  \details Позволяет создать медиатеку с заданными параметрами и предустановленными плейлистами.
     */
    MediaLibrary(const std::string& title, const std::vector<ArtistPlaylist>& artistsPlaylists,
                 const std::vector<GenrePlaylist>& genrePlaylists, const FavouritePlaylist& favouritePlaylist);

    /*! \brief Получить плейлисты исполнителей
     *  \return Константная ссылка на вектор плейлистов исполнителей
     *  \details Возвращает все плейлисты исполнителей, содержащиеся в медиатеке.
     */
    const std::vector<ArtistPlaylist>& GetArtistPlaylists() const;

    /*! \brief Получить жанровые плейлисты
     *  \return Константная ссылка на вектор жанровых плейлистов
     *  \details Возвращает все жанровые плейлисты, содержащиеся в медиатеке.
     */
    const std::vector<GenrePlaylist>& GetGenrePlaylists() const;

    /*! \brief Получить плейлист избранного
     *  \return Ссылка на плейлист избранного
     *  \details Возвращает плейлист с избранными треками пользователя.
     */
    FavouritePlaylist& GetFavouritePlaylist();

    /*! \brief Получить ежедневный плейлист
     *  \return Константный optional с ежедневным плейлистом
     *  \details Возвращает ежедневный плейлист, если он установлен в медиатеке.
     */
    const std::optional<DailyPlaylist>& GetDailyPlaylist() const;

    /*! \brief Добавить плейлист исполнителя
     *  \param artistPlaylist Плейлист исполнителя для добавления
     *  \return true если плейлист успешно добавлен, false в противном случае
     *  \details Добавляет указанный плейлист исполнителя в коллекцию медиатеки.
     */
    bool AddArtistPlaylist(const ArtistPlaylist& artistPlaylist);

    /*! \brief Удалить плейлист исполнителя
     *  \param artistPlaylist Плейлист исполнителя для удаления
     *  \return true если плейлист успешно удален, false в противном случае
     *  \details Удаляет указанный плейлист исполнителя из коллекции медиатеки.
     */
    bool RemoveArtistPlaylist(const ArtistPlaylist& artistPlaylist);

    /*! \brief Добавить жанровый плейлист
     *  \param genrePlaylist Жанровый плейлист для добавления
     *  \return true если плейлист успешно добавлен, false в противном случае
     *  \details Добавляет указанный жанровый плейлист в коллекцию медиатеки.
     */
    bool AddGenrePlaylist(const GenrePlaylist& genrePlaylist);

    /*! \brief Удалить жанровый плейлист
     *  \param genrePlaylist Жанровый плейлист для удаления
     *  \return true если плейлист успешно удален, false в противном случае
     *  \details Удаляет указанный жанровый плейлист из коллекции медиатеки.
     */
    bool RemoveGenrePlaylist(const GenrePlaylist& genrePlaylist);

    /*! \brief Добавить ежедневный плейлист
     *  \param dailyPlaylist Ежедневный плейлист для добавления
     *  \return true если плейлист успешно добавлен, false в противном случае
     *  \details Устанавливает ежедневный плейлист в медиатеке.
     */
    bool AddDailyPlaylist(const DailyPlaylist& dailyPlaylist);

    /*! \brief Удалить ежедневный плейлист
     *  \param dailyPlaylist Ежедневный плейлист для удаления
     *  \return true если плейлист успешно удален, false в противном случае
     *  \details Удаляет ежедневный плейлист из медиатеки.
     */
    bool RemoveDailyPlaylist(const DailyPlaylist& dailyPlaylist);

    /*! \brief Получить список плейлистов
     *  \return Строка с отформатированным списком всех плейлистов
     *  \details Возвращает строковое представление всех плейлистов в медиатеке.
     */
    std::string GetPlaylistList() const override;

private:
    std::string title_; /*!< Название медиатеки */
    std::vector<ArtistPlaylist> artistsPlaylists_; /*!< Вектор плейлистов исполнителей */
    std::vector<GenrePlaylist> genrePlaylists_; /*!< Вектор жанровых плейлистов */
    FavouritePlaylist favouritePlaylist_; /*!< Плейлист избранного */
    std::optional<DailyPlaylist> dailyPlaylist_; /*!< Опциональный ежедневный плейлист */
};

#endif
