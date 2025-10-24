/*! \file favourite_playlist.h
 *  \brief Заголовочный файл с описанием класса FavouritePlaylist
 *  \details Содержит объявление класса FavouritePlaylist, представляющего плейлист избранного.
 *           Класс наследует Playlist и реализует интерфейс для работы с пользовательскими
 *           коллекциями любимых треков.
 */
#ifndef FAVOURITE_PLAYLIST
#define FAVOURITE_PLAYLIST
#include "playlist.h"
#include "../../EnumClasses/playlist_type.h"
#include "../Exceptions/exceptions.h"
#include <vector>

/*! \class FavouritePlaylist
 *  \brief Модель плейлиста избранного
 *  \details FavouritePlaylist наследуется от Playlist и предоставляет методы для управления
 *           пользовательской коллекцией любимых треков. Включает функциональность для
 *           добавления и удаления треков из избранного.
 */
class FavouritePlaylist : public Playlist
{
public:
    /*! \brief Конструктор по умолчанию
     *  \details Инициализирует плейлист избранного с пустым названием и списком треков.
     */
    FavouritePlaylist();

    /*! \brief Деструктор
     *  \details Обеспечивает корректное уничтожение объекта плейлиста избранного.
     */
    ~FavouritePlaylist();

    /*! \brief Конструктор с инициализацией названия и треков
     *  \param title Название плейлиста избранного
     *  \param tracks Вектор треков для добавления в плейлист
     *  \details Позволяет создать плейлист избранного с заданным названием и предустановленным списком треков.
     */
    FavouritePlaylist(const std::string& title, const std::vector<Track>& tracks);

    /*! \brief Получить тип плейлиста
     *  \return Строка с описанием типа плейлиста
     *  \details Возвращает тип плейлиста, соответствующий значению PlaylistType::FavouritePlaylist.
     */
    std::string GetPlaylistType() const override;

    /*! \brief Установить название плейлиста
     *  \param title Новое название плейлиста
     *  \details Сохраняет название плейлиста избранного.
     */
    void SetTitle(const std::string& title) override;

    /*! \brief Получить название плейлиста
     *  \return Строка с названием плейлиста
     *  \details Возвращает текущее установленное название плейлиста избранного.
     */
    std::string GetTitle() const override;

    /*! \brief Добавить трек в плейлист
     *  \param track Трек для добавления в плейлист
     *  \details Добавляет переданный трек в конец списка треков плейлиста избранного.
     */
    void AddTrack(const Track& track) override;

    /*! \brief Удалить трек из плейлиста
     *  \param track Трек для удаления из плейлиста
     *  \details Удаляет указанный трек из плейлиста избранного.
     */
    void RemoveTrack(const Track& track);

    /*! \brief Получить список треков плейлиста
     *  \return Строка с отформатированным списком треков
     *  \details Возвращает строковое представление всех треков в плейлисте избранного.
     */
    std::string GetTrackList() const override;

    /*! \brief Получить количество треков в плейлисте
     *  \return Количество треков в плейлисте
     *  \details Возвращает общее количество треков, содержащихся в плейлисте избранного.
     */
    int GetTrackCount() const override;

private:
    std::string title_; /*!< Название плейлиста избранного */
    std::vector<Track> tracks_; /*!< Вектор треков, содержащихся в плейлисте */
    PlaylistType type_{PlaylistType::FavouritePlaylist}; /*!< Тип плейлиста - избранное */
};

#endif
