/*! \file music_collection.h
*  \brief Заголовочный файл с описанием абстрактного класса MusicCollection
 *  \details Содержит объявление абстрактного класса MusicCollection, представляющего базовый интерфейс
 *           для музыкальных коллекций, таких как плейлисты, альбомы и другие собрания музыкального контента.
 */
#ifndef PLAYLIST_COLLECTION
#define PLAYLIST_COLLECTION
#include <string>

/*! \class MusicCollection
 *  \brief Абстрактный базовый класс для музыкальных коллекций
 *  \details MusicCollection определяет базовый интерфейс для всех видов музыкальных коллекций,
 *           предоставляя метод для получения списка треков. Является родительским
 *           классом для специализированных типов музыкальных коллекций.
 */
class MusicCollection
{
public:
    /*! \brief Виртуальный деструктор по умолчанию
     *  \details Обеспечивает корректное уничтожение объектов производных классов.
     */
    virtual ~MusicCollection() = default;

    /*! \brief Получить список треков
     *  \return Строка со списком треков
     *  \details Возвращает строковое представление всех треков в музыкальной коллекции.
     */
    virtual std::string GetTrackList() const = 0;
};

#endif
