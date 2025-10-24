/*! \file playlist_type.h
*  \brief Заголовочный файл с описанием перечисления PlaylistType и вспомогательных функций
 *  \details Содержит объявление перечисления типов плейлистов и функцию
 *           для преобразования значений перечисления в строковое представление.
 */
#ifndef PLAYLIST_TYPE
#define PLAYLIST_TYPE
#include <string>

/*! \enum PlaylistType
 *  \brief Перечисление типов плейлистов
 *  \details Определяет различные категории плейлистов для классификации
 *           музыкальных подборок по их содержанию и назначению.
 */
enum class PlaylistType
{
    DailyPlaylist, /*!< Ежедневный плейлист - автоматически обновляемая подборка треков */
    ArtistPlaylist, /*!< Плейлист исполнителя - подборка треков конкретного артиста */
    FavouritePlaylist, /*!< Плейлист избранного - пользовательская коллекция любимых треков */
    GenrePlaylist /*!< Жанровый плейлист - подборка треков определенного музыкального жанра */
};

/*! \brief Преобразовать тип плейлиста в строковое представление
 *  \param playlist_type Тип плейлиста из перечисления PlaylistType
 *  \return Строковое описание типа плейлиста
 *  \details Функция преобразует значение перечисления PlaylistType в человеко-читаемую
 *           строку для отображения в пользовательском интерфейсе или отчетах.
 */
inline std::string PlaylistTypeToString(PlaylistType playlist_type)
{
    switch (playlist_type)
    {
    case PlaylistType::DailyPlaylist: return "Daily Playlist";
    case PlaylistType::ArtistPlaylist: return "Artist Playlist";
    case PlaylistType::FavouritePlaylist: return "Favourite Playlist";
    case PlaylistType::GenrePlaylist: return "Genre Playlist";
    default: return "Unknown";
    }
}

#endif
