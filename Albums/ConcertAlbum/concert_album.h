/*! \file concert_album.h
 *  \brief Заголовочный файл с описанием класса ConcertAlbum
 *  \details Содержит объявление класса ConcertAlbum, представляющего концертный альбом.
 *           Класс наследует Album и реализует интерфейс для работы с записями живых выступлений.
 */
#ifndef CONCERT_ALBUM
#define CONCERT_ALBUM
#include "album.h"
#include "../../EnumClasses/album_type.h"
#include <string>
#include <vector>

/*! \class ConcertAlbum
 *  \brief Модель концертного альбома
 *  \details ConcertAlbum наследуется от Album, предоставляя методы для управления
 *           названием альбома, добавления и получения треков, вычисления общей длительности
 *           и получения информации о типе альбома. Специализирован для работы с записями
 *           живых выступлений и концертов.
 */
class ConcertAlbum : public Album
{
public:
    /*! \brief Конструктор по умолчанию
     *  \details Инициализирует концертный альбом с пустым названием и списком треков.
     */
    ConcertAlbum();

    /*! \brief Конструктор с инициализацией названия и треков
     *  \param title Название концертного альбома
     *  \param tracks Вектор треков для добавления в альбом
     *  \details Позволяет создать альбом с заданным названием и предустановленным списком треков.
     */
    ConcertAlbum(const std::string& title, const std::vector<Track>& tracks);

    /*! \brief Деструктор
     *  \details Обеспечивает корректное уничтожение объекта концертного альбома.
     */
    ~ConcertAlbum();

    /*! \brief Установить название альбома
     *  \param title Новое название альбома
     *  \details Сохраняет название концертного альбома.
     */
    void SetTitle(const std::string& title) override;

    /*! \brief Получить название альбома
     *  \return Строка с названием альбома
     *  \details Возвращает текущее установленное название концертного альбома.
     */
    std::string GetTitle() const override;

    /*! \brief Добавить трек в альбом
     *  \param track Трек для добавления
     *  \details Добавляет переданный трек в конец списка треков концертного альбома.
     */
    void AddTrack(const Track& track) override;

    /*! \brief Получить количество треков в альбоме
     *  \return Количество треков в альбоме
     *  \details Возвращает общее количество треков, содержащихся в концертном альбоме.
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
     *  \details Возвращает тип альбома, соответствующий значению AlbumType::ConcertAlbum.
     */
    std::string GetAlbumType() const override;

private:
    std::string title_; /*!< Название концертного альбома */
    std::vector<Track> tracks_; /*!< Вектор треков, содержащихся в альбоме */
    AlbumType albumType_{AlbumType::ConcertAlbum}; /*!< Тип альбома - концертный */
};

#endif
