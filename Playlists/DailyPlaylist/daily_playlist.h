/*! \file daily_playlist.h
 *  \brief Заголовочный файл с описанием класса DailyPlaylist
 *  \details Содержит объявление класса DailyPlaylist, представляющего ежедневный плейлист.
 *           Класс наследует Playlist и реализует интерфейс для работы с автоматически
 *           обновляемыми плейлистами, которые меняются ежедневно.
 */
#ifndef DAILY_PLAYLIST
#define DAILY_PLAYLIST
#include <vector>
#include <chrono>
#include "../../EnumClasses/playlist_type.h"
#include "../Exceptions/exceptions.h"
#include "playlist.h"

/*! \class DailyPlaylist
 *  \brief Модель ежедневного плейлиста
 *  \details DailyPlaylist наследуется от Playlist и предоставляет методы для управления
 *           ежедневно обновляемым плейлистом. Содержит функциональность для обновления даты
 *           и управления треками, которые автоматически меняются каждый день.
 */
class DailyPlaylist : public Playlist
{
public:
    /*! \brief Конструктор по умолчанию
     *  \details Инициализирует ежедневный плейлист с пустым названием, списком треков
     *           и устанавливает текущую дату.
     */
    DailyPlaylist();

    /*! \brief Деструктор
     *  \details Обеспечивает корректное уничтожение объекта ежедневного плейлиста.
     */
    ~DailyPlaylist();

    /*! \brief Конструктор с инициализацией названия и треков
     *  \param title Название ежедневного плейлиста
     *  \param tracks Вектор треков для добавления в плейлист
     *  \details Позволяет создать ежедневный плейлист с заданным названием и предустановленным списком треков.
     */
    DailyPlaylist(const std::string& title, const std::vector<Track>& tracks);

    /*! \brief Получить тип плейлиста
     *  \return Строка с описанием типа плейлиста
     *  \details Возвращает тип плейлиста, соответствующий значению PlaylistType::DailyPlaylist.
     */
    std::string GetPlaylistType() const override;

    /*! \brief Установить название плейлиста
     *  \param title Новое название плейлиста
     *  \details Сохраняет название ежедневного плейлиста.
     */
    void SetTitle(const std::string& title) override;

    /*! \brief Получить название плейлиста
     *  \return Строка с названием плейлиста
     *  \details Возвращает текущее установленное название ежедневного плейлиста.
     */
    std::string GetTitle() const override;

    /*! \brief Добавить трек в плейлист
     *  \param track Трек для добавления в плейлист
     *  \details Добавляет переданный трек в конец списка треков ежедневного плейлиста.
     */
    void AddTrack(const Track& track) override;

    /*! \brief Получить количество треков в плейлисте
     *  \return Количество треков в плейлисте
     *  \details Возвращает общее количество треков, содержащихся в ежедневном плейлисте.
     */
    int GetTrackCount() const override;

    /*! \brief Обновить дату плейлиста
     *  \details Устанавливает текущую дату для ежедневного плейлиста.
     *           Используется для отслеживания актуальности содержимого плейлиста.
     */
    void UpdateDate();

    /*! \brief Получить дату плейлиста
     *  \return Строка с датой плейлиста
     *  \details Возвращает дату, связанную с текущей версией ежедневного плейлиста.
     */
    std::string GetDate() const;

    /*! \brief Получить список треков плейлиста
     *  \return Строка с отформатированным списком треков
     *  \details Возвращает строковое представление всех треков в ежедневном плейлисте.
     */
    std::string GetTrackList() const override;

private:
    std::string title_; /*!< Название ежедневного плейлиста */
    std::vector<Track> tracks_; /*!< Вектор треков, содержащихся в плейлисте */
    std::string date_; /*!< Дата создания или последнего обновления плейлиста */
    PlaylistType type_{PlaylistType::DailyPlaylist}; /*!< Тип плейлиста - ежедневный */
};

#endif
