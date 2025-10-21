/*! \file genre_playlist.h
 *  \brief Заголовочный файл с описанием класса GenrePlaylist
 *  \details Содержит объявление класса GenrePlaylist, представляющего жанровый плейлист.
 *           Класс наследует Playlist и реализует интерфейс для работы с плейлистами,
 *           содержащими треки определенного музыкального жанра.
 */
#ifndef GENRE_PLAYLIST
#define GENRE_PLAYLIST
#include "playlist.h"
#include "playlist_type.h"
#include "../Exceptions/exceptions.h"
#include "../BaseClasses/genre_type.h"
#include <vector>

/*! \class GenrePlaylist
 *  \brief Модель жанрового плейлиста
 *  \details GenrePlaylist наследуется от Playlist и предоставляет методы для управления
 *           плейлистом, содержащим треки определенного музыкального жанра. Обеспечивает
 *           проверку соответствия добавляемых треков заданному жанру.
 */
class GenrePlaylist : public Playlist
{
public:
    /*! \brief Конструктор по умолчанию
     *  \details Инициализирует жанровый плейлист с пустым названием, списком треков
     *           и неопределенным жанром.
     */
    GenrePlaylist();

    /*! \brief Деструктор
     *  \details Обеспечивает корректное уничтожение объекта жанрового плейлиста.
     */
    ~GenrePlaylist();

    /*! \brief Конструктор с инициализацией названия, треков и жанра
     *  \param title Название жанрового плейлиста
     *  \param track_ Вектор треков для добавления в плейлист
     *  \param genre Жанр плейлиста
     *  \details Позволяет создать жанровый плейлист с заданным названием, предустановленным
     *           списком треков и определенным жанром.
     */
    GenrePlaylist(const std::string& title, const std::vector<Track>& track_, GenreType genre);

    /*! \brief Получить тип плейлиста
     *  \return Строка с описанием типа плейлиста
     *  \details Возвращает тип плейлиста, соответствующий значению PlaylistType::GenrePlaylist.
     */
    std::string GetPlaylistType() const override;

    /*! \brief Установить название плейлиста
     *  \param title Новое название плейлиста
     *  \details Сохраняет название жанрового плейлиста.
     */
    void SetTitle(const std::string& title) override;

    /*! \brief Получить название плейлиста
     *  \return Строка с названием плейлиста
     *  \details Возвращает текущее установленное название жанрового плейлиста.
     */
    std::string GetTitle() const override;

    /*! \brief Добавить трек в плейлист
     *  \param track Трек для добавления в плейлист
     *  \details Добавляет переданный трек в конец списка треков жанрового плейлиста.
     *           Проверяет соответствие жанра трека жанру плейлиста.
     */
    void AddTrack(const Track& track) override;

    /*! \brief Получить список треков плейлиста
     *  \return Строка с отформатированным списком треков
     *  \details Возвращает строковое представление всех треков в жанровом плейлисте.
     */
    std::string GetTrackList() const override;

    /*! \brief Получить количество треков в плейлисте
     *  \return Количество треков в плейлисте
     *  \details Возвращает общее количество треков, содержащихся в жанровом плейлисте.
     */
    int GetTrackCount() const override;

    /*! \brief Получить тип жанра плейлиста
     *  \return Строка с описанием жанра плейлиста
     *  \details Возвращает строковое представление жанра, связанного с данным плейлистом.
     */
    std::string GetGenreType() const;

private:
    std::string title_; /*!< Название жанрового плейлиста */
    std::vector<Track> tracks_; /*!< Вектор треков, содержащихся в плейлисте */
    PlaylistType type_{PlaylistType::GenrePlaylist}; /*!< Тип плейлиста - жанровый */
    GenreType genre_; /*!< Музыкальный жанр плейлиста */
};

#endif
