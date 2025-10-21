/*! \file playlist.h
*  \brief Заголовочный файл с описанием абстрактного класса Playlist
 *  \details Содержит объявление абстрактного класса Playlist, представляющего плейлист.
 *           Класс наследует MusicCollection и определяет интерфейс для работы с различными типами плейлистов.
 */
#ifndef PLAYLIST
#define PLAYLIST
#include "music_collection.h"
#include "../Track/track.h"

/*! \class Playlist
 *  \brief Абстрактный базовый класс для плейлистов
 *  \details Playlist наследуется от MusicCollection и определяет чистые виртуальные методы
 *           для управления названием плейлиста, добавления треков, получения информации
 *           о количестве треков и типе плейлиста.
 */
class Playlist : public MusicCollection
{
public:
    /*! \brief Виртуальный деструктор по умолчанию
     *  \details Обеспечивает корректное уничтожение объектов производных классов.
     */
    virtual ~Playlist() = default;

    /*! \brief Получить тип плейлиста
     *  \return Строка с описанием типа плейлиста
     */
    virtual std::string GetPlaylistType() const = 0;

    /*! \brief Установить название плейлиста
     *  \param title Новое название плейлиста
     */
    virtual void SetTitle(const std::string& title) = 0;

    /*! \brief Получить название плейлиста
     *  \return Строка с названием плейлиста
     */
    virtual std::string GetTitle() const = 0;

    /*! \brief Добавить трек в плейлист
     *  \param track Трек для добавления в плейлист
     */
    virtual void AddTrack(const Track& track) = 0;

    /*! \brief Получить количество треков в плейлисте
     *  \return Количество треков в плейлисте
     */
    virtual int GetTrackCount() const = 0;
};

#endif
