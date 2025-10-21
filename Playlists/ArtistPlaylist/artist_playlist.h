/*! \file artist_playlist.h
 *  \brief Заголовочный файл с описанием класса ArtistPlaylist
 *  \details Содержит объявление класса ArtistPlaylist, представляющего плейлист исполнителя.
 *           Класс наследует Playlist и реализует интерфейс для работы с плейлистами,
 *           содержащими треки конкретного исполнителя.
 */
#ifndef ARTIST_PLAYLIST
#define ARTIST_PLAYLIST
#include "../Artist/artist.h"
#include "playlist.h"
#include "playlist_type.h"

/*! \class ArtistPlaylist
 *  \brief Модель плейлиста исполнителя
 *  \details ArtistPlaylist наследуется от Playlist и предоставляет методы для управления
 *           плейлистом, связанным с конкретным исполнителем. Содержит треки одного артиста
 *           и предоставляет информацию об исполнителе.
 */
class ArtistPlaylist : public Playlist
{
public:
    /*! \brief Конструктор по умолчанию
     *  \details Инициализирует плейлист исполнителя с пустым названием и исполнителем по умолчанию.
     */
    ArtistPlaylist();

    /*! \brief Деструктор
     *  \details Обеспечивает корректное уничтожение объекта плейлиста исполнителя.
     */
    ~ArtistPlaylist();

    /*! \brief Конструктор с инициализацией исполнителя и названия
     *  \param artist Исполнитель плейлиста
     *  \param title Название плейлиста
     *  \details Позволяет создать плейлист исполнителя с заданным исполнителем и названием.
     */
    ArtistPlaylist(const Artist& artist, const std::string& title);

    /*! \brief Получить тип плейлиста
     *  \return Строка с описанием типа плейлиста
     *  \details Возвращает тип плейлиста, соответствующий значению PlaylistType::ArtistPlaylist.
     */
    std::string GetPlaylistType() const override;

    /*! \brief Установить название плейлиста
     *  \param title Новое название плейлиста
     *  \details Сохраняет название плейлиста исполнителя.
     */
    void SetTitle(const std::string& title) override;

    /*! \brief Получить название плейлиста
     *  \return Строка с названием плейлиста
     *  \details Возвращает текущее установленное название плейлиста исполнителя.
     */
    std::string GetTitle() const override;

    /*! \brief Добавить трек в плейлист
     *  \param track Трек для добавления в плейлист
     *  \details Добавляет переданный трек в конец списка треков плейлиста исполнителя.
     */
    void AddTrack(const Track& track) override;

    /*! \brief Получить количество треков в плейлисте
     *  \return Количество треков в плейлисте
     *  \details Возвращает общее количество треков, содержащихся в плейлисте исполнителя.
     */
    int GetTrackCount() const override;

    /*! \brief Получить список треков плейлиста
     *  \return Строка с отформатированным списком треков
     *  \details Возвращает строковое представление всех треков в плейлисте исполнителя.
     */
    std::string GetTrackList() const override;

    /*! \brief Получить псевдоним исполнителя
     *  \return Строка с псевдонимом исполнителя
     *  \details Возвращает псевдоним исполнителя, связанного с данным плейлистом.
     */
    std::string GetArtistPseudonym() const;

private:
    std::string title_; /*!< Название плейлиста исполнителя */
    Artist artist_; /*!< Исполнитель, связанный с плейлистом */
    std::vector<Track> tracks_; /*!< Вектор треков, содержащихся в плейлисте */
    PlaylistType type_{PlaylistType::ArtistPlaylist}; /*!< Тип плейлиста - исполнительский */
};

#endif
