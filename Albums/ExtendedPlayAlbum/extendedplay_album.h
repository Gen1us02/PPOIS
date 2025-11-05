/*! \file extendedplay_album.h
 *  \brief Заголовочный файл с описанием класса ExtendedPlayAlbum
 *  \details Содержит объявление класса ExtendedPlayAlbum, представляющего мини-альбом.
 *           Класс наследует Album и реализует интерфейс для работы с Extended Play альбомами,
 *           которые содержат меньше треков, чем полноценные студийные альбомы.
 */
#ifndef EXTENDEDPLAY_ALBUM
#define EXTENDEDPLAY_ALBUM

#include "album.h"
#include "../../EnumClasses/album_type.h"
#include <vector>

/*! \class ExtendedPlayAlbum
 *  \brief Модель мини-альбома
 *  \details ExtendedPlayAlbum наследуется от Album, предоставляя методы для управления
 *           названием альбома, добавления и получения треков, вычисления общей длительности
 *           и получения информации о типе альбома. Специализирован для работы с мини-альбомами,
 *           которые содержат ограниченное количество треков.
 */
class ExtendedPlayAlbum : public Album
{
public:
    /*! \brief Конструктор по умолчанию
     *  \details Инициализирует мини-альбом с пустым названием и списком треков.
     */
    ExtendedPlayAlbum();

    /*! \brief Конструктор с инициализацией названия и треков
     *  \param title Название мини-альбома
     *  \param tracks Вектор треков для добавления в альбом
     *  \details Позволяет создать альбом с заданным названием и предустановленным списком треков.
     *           Количество треков не должно превышать максимально допустимое для мини-альбома.
     */
    ExtendedPlayAlbum(const std::string& title, const std::vector<Track>& tracks);

    /*! \brief Деструктор
     *  \details Обеспечивает корректное уничтожение объекта мини-альбома.
     */
    ~ExtendedPlayAlbum();

    /*! \brief Установить название альбома
     *  \param title Новое название альбома
     *  \details Сохраняет название мини-альбома.
     */
    void SetTitle(const std::string& title) override;

    /*! \brief Получить название альбома
     *  \return Строка с названием альбома
     *  \details Возвращает текущее установленное название мини-альбома.
     */
    std::string GetTitle() const override;

    /*! \brief Добавить трек в альбом
     *  \param track Трек для добавления
     *  \details Добавляет переданный трек в конец списка треков мини-альбома, если не превышено
     *           максимальное количество треков.
     */
    void AddTrack(const Track& track) override;

    /*! \brief Получить количество треков в альбоме
     *  \return Количество треков в альбоме
     *  \details Возвращает общее количество треков, содержащихся в мини-альбоме.
     */
    int GetTrackCount() const override;

    /*! \brief Получить общую длительность альбома
     *  \return Общая длительность всех треков в секундах
     *  \details Вычисляет и возвращает сумму длительностей всех треков в альбоме.
     */
    int GetTotalDuration() const override;

    /*! \brief Получить список треков альбома
     *  \return Строка с отформатированным списком треков
     *  \details Возвращает строковое представление списка треков с их названиями и длительностями.
     */
    std::string GetTrackList() const override;

    /*! \brief Получить тип альбома
     *  \return Строка с описанием типа альбома
     *  \details Возвращает тип альбома, соответствующий значению AlbumType::ExtendedAlbum.
     */
    std::string GetAlbumType() const override;

private:
    std::string title_; /*!< Название мини-альбома */
    std::vector<Track> tracks_; /*!< Вектор треков, содержащихся в альбоме */
    AlbumType albumType_{AlbumType::ExtendedAlbum}; /*!< Тип альбома - мини-альбом */
    static constexpr int maxTracksCount_{3}; /*!< Максимальное количество треков в мини-альбоме */
};

#endif
