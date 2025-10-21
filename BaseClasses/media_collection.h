/*! \file media_collection.h
*  \brief Заголовочный файл с описанием абстрактного класса MediaCollection
 *  \details Содержит объявление абстрактного класса MediaCollection, представляющего базовый интерфейс
 *           для медиа-коллекций, таких как плейлисты, альбомы и другие собрания медиа-контента.
 */
#ifndef MEDIA_COLLECTION
#define MEDIA_COLLECTION
#include <string>

/*! \class MediaCollection
 *  \brief Абстрактный базовый класс для медиа-коллекций
 *  \details MediaCollection определяет базовый интерфейс для всех видов медиа-коллекций,
 *           предоставляя метод для получения списка плейлистов. Является родительским
 *           классом для специализированных типов медиа-коллекций.
 */
class MediaCollection
{
public:
    /*! \brief Виртуальный деструктор по умолчанию
     *  \details Обеспечивает корректное уничтожение объектов производных классов.
     */
    virtual ~MediaCollection() = default;

    /*! \brief Получить список плейлистов
     *  \return Строка со списком плейлистов
     *  \details Возвращает строковое представление всех плейлистов в медиа-коллекции.
     */
    virtual std::string GetPlaylistList() const = 0;
};

#endif
