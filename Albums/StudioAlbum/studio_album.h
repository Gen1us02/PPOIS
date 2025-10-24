/*! \file studio_album.h
 *  \brief Заголовочный файл с описанием класса StudioAlbum
 *  \details Содержит объявление класса StudioAlbum, представляющего студийный альбом.
 *           Класс наследует Album и реализует интерфейс для работы со студийными записями,
 *           которые обычно представляют собой основные музыкальные релизы исполнителей.
 */
#ifndef STUDIO_ALBUM
#define STUDIO_ALBUM
#include "album.h"
#include <vector>

#include "../../EnumClasses/album_type.h"

/*! \class StudioAlbum
 *  \brief Модель студийного альбома
 *  \details StudioAlbum наследуется отAlbum, предоставляя методы для управления
 *           названием альбома, добавления и получения треков, вычисления общей длительности
 *           и получения информации о типе альбома. Специализирован для работы с основными
 *           студийными релизами исполнителей.
 */
class StudioAlbum : public Album
{
public:
    /*! \brief Конструктор по умолчанию
     *  \details Инициализирует студийный альбом с пустым названием и списком треков.
     */
    StudioAlbum();

    /*! \brief Конструктор с инициализацией названия и треков
     *  \param title Название студийного альбома
     *  \param tracks Вектор треков для добавления в альбом
     *  \details Позволяет создать альбом с заданным названием и предустановленным списком треков.
     */
    StudioAlbum(const std::string& title, const std::vector<Track>& tracks);

    /*! \brief Деструктор
     *  \details Обеспечивает корректное уничтожение объекта студийного альбома.
     */
    ~StudioAlbum();

    /*! \brief Установить название альбома
     *  \param title Новое название альбома
     *  \details Сохраняет название студийного альбома.
     */
    void SetTitle(const std::string& title) override;

    /*! \brief Получить название альбома
     *  \return Строка с названием альбома
     *  \details Возвращает текущее установленное название студийного альбома.
     */
    std::string GetTitle() const override;

    /*! \brief Добавить трек в альбом
     *  \param track Трек для добавления
     *  \details Добавляет переданный трек в конец списка треков студийного альбома.
     */
    void AddTrack(const Track& track) override;

    /*! \brief Получить количество треков в альбоме
     *  \return Количество треков в альбоме
     *  \details Возвращает общее количество треков, содержащихся в студийном альбоме.
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
     *  \details Возвращает тип альбома, соответствующий значению AlbumType::StudioAlbum.
     */
    std::string GetAlbumType() const;

private:
    std::string title_; /*!< Название студийного альбома */
    std::vector<Track> tracks_; /*!< Вектор треков, содержащихся в альбоме */
    AlbumType albumType_{AlbumType::StudioAlbum}; /*!< Тип альбома - студийный */
};

#endif
