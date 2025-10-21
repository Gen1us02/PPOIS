/*! \file album.h
*  \brief Заголовочный файл с описанием абстрактного класса Album
 *  \details Содержит объявление абстрактного класса Album, представляющего музыкальный альбом.
 *           Класс наследует MusicCollection и определяет интерфейс для работы с различными типами альбомов.
 */
#ifndef ALBUM
#define ALBUM
#include <string>
#include "../Track/track.h"
#include "music_collection.h"
#include "../Exceptions/exceptions.h"

/*! \class Album
 *  \brief Абстрактный базовый класс для музыкальных альбомов
 *  \details Album наследуется от MusicCollection и определяет чистые виртуальные методы
 *           для управления названием альбома, добавления треков, получения информации
 *           о количестве треков, общей длительности и типе альбома.
 */
class Album : public MusicCollection
{
public:
    /*! \brief Виртуальный деструктор по умолчанию
     *  \details Обеспечивает корректное уничтожение объектов производных классов.
     */
    virtual ~Album() = default;

    /*! \brief Установить название альбома
     *  \param title Новое название альбома
     */
    virtual void SetTitle(const std::string& title) = 0;

    /*! \brief Получить название альбома
     *  \return Строка с названием альбома
     */
    virtual std::string GetTitle() const = 0;

    /*! \brief Добавить трек в альбом
     *  \param track Трек для добавления в альбом
     */
    virtual void AddTrack(const Track& track) = 0;

    /*! \brief Получить количество треков в альбоме
     *  \return Количество треков в альбоме
     */
    virtual int GetTrackCount() const = 0;

    /*! \brief Получить общую длительность альбома
     *  \return Общая длительность всех треков в секундах
     */
    virtual int GetTotalDuration() const = 0;

    /*! \brief Получить тип альбома
     *  \return Строка с описанием типа альбома
     */
    virtual std::string GetAlbumType() const = 0;
};

#endif
