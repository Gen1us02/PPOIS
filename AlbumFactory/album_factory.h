/*! \file album_factory.h
 *  \brief Заголовочный файл с описанием класса AlbumFactory
 *  \details Содержит объявление класса AlbumFactory, реализующего паттерн "Фабрика"
 *           для создания объектов различных типов альбомов.
 */
#ifndef ALBUM_FACTORY
#define ALBUM_FACTORY

#include <vector>
#include <string>
#include <memory>
#include "album.h"
#include "../EnumClasses/album_type.h"

/*! \class AlbumFactory
 *  \brief Фабрика для создания объектов альбомов
 *  \details AlbumFactory метод для создания объектов альбомов различных типов.
 *           Класс инкапсулирует логику создания конкретных типов альбомов
 *           и возвращает базовый указатель на Album.
 */
class AlbumFactory {
public:
    /*! \brief Создать альбом указанного типа
     *  \param type Тип создаваемого альбома
     *  \param albumTitle Название альбома
     *  \param tracks Вектор треков для добавления в альбом
     *  \return Умный указатель на созданный объект альбома
     *  \details Создает и возвращает объект альбома указанного типа с заданным названием
     *           и списком треков. Поддерживает создание всех типов альбомов, определенных
     *           в перечислении AlbumType.
     */
    static std::shared_ptr<Album> CreateAlbum(AlbumType type,
                                              const std::string &albumTitle,
                                              const std::vector<Track> &tracks);
};

#endif