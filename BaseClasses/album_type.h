/*! \file album_type.h
*  \brief Заголовочный файл с описанием перечисления AlbumType и вспомогательных функций
 *  \details Содержит объявление перечисления типов музыкальных альбомов и функцию
 *           для преобразования значений перечисления в строковое представление.
 */
#ifndef ALBUM_TYPE
#define ALBUM_TYPE
#include <string>

/*! \enum AlbumType
 *  \brief Перечисление типов музыкальных альбомов
 *  \details Определяет различные категории музыкальных альбомов для классификации
 *           музыкальных релизов по их содержанию и формату.
 */
enum class AlbumType
{
    CompilationAlbum, /*!< Компиляционный альбом - сборник треков от разных исполнителей */
    ConcertAlbum, /*!< Концертный альбом - запись живого выступления */
    ExtendedAlbum, /*!< Мини-альбом (EP) - содержит меньше треков, чем студийный альбом */
    StudioAlbum /*!< Студийный альбом - основной музыкальный релиз, записанный в студии */
};

/*! \brief Преобразовать тип альбома в строковое представление
 *  \param albumType Тип альбома из перечисления AlbumType
 *  \return Строковое описание типа альбома
 *  \details Функция преобразует значение перечисления AlbumType в
 *           строку для отображения в пользовательском интерфейсе или отчетах.
 */
inline std::string AlbumTypeToString(AlbumType albumType)
{
    switch (albumType)
    {
    case AlbumType::CompilationAlbum: return "Compilation Album";
    case AlbumType::ConcertAlbum: return "Concert Album";
    case AlbumType::ExtendedAlbum: return "Extended Play Album";
    case AlbumType::StudioAlbum: return "Studio Album";
    default: return "Unknown";
    }
}

#endif
