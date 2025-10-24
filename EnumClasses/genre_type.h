/*! \file genre_type.h
 *  \brief Заголовочный файл с описанием перечисления GenreType и вспомогательных функций
 *  \details Содержит объявление перечисления музыкальных жанров и функции
 *           для преобразования между значениями перечисления и строковым представлением.
 */
#ifndef GENRE_TYPE
#define GENRE_TYPE
#include <string>

/*! \enum GenreType
 *  \brief Перечисление музыкальных жанров
 *  \details Определяет различные музыкальные жанры для классификации
 *           треков по стилистической принадлежности.
 */
enum class GenreType
{
    None, /*!< Жанр не определен */
    Phonk, /*!< Фонк - жанр электронной музыки */
    Rap, /*!< Рэп - речитативный музыкальный стиль */
    Rock, /*!< Рок - жанр популярной музыки */
    Blues, /*!< Блюз - музыкальный жанр, зародившийся в афроамериканской общине */
    Jazz /*!< Джаз - музыкальный жанр, возникший в конце XIX — начале XX века */
};

/*! \brief Преобразовать тип жанра в строковое представление
 *  \param genreType Тип жанра из перечисления GenreType
 *  \return Строковое описание жанра
 *  \details Функция преобразует значение перечисления GenreType в человеко-читаемую
 *           строку для отображения в пользовательском интерфейсе или отчетах.
 */
inline std::string GenreTypeToString(GenreType genreType)
{
    switch (genreType)
    {
    case GenreType::Phonk: return "Phonk";
    case GenreType::Rap: return "Rap";
    case GenreType::Rock: return "Rock";
    case GenreType::Jazz: return "Jazz";
    case GenreType::Blues: return "Blues";
    default: return "Unknown";
    }
}

/*! \brief Преобразовать строку в тип жанра
 *  \param genreType Строковое представление жанра
 *  \return Значение перечисления GenreType, соответствующее строке
 *  \details Функция преобразует строковое представление жанра в значение
 *           перечисления GenreType. Если строка не соответствует ни одному
 *           известному жанру, возвращает GenreType::None.
 */
inline GenreType StringToGenreType(const std::string& genreType)
{
    if (genreType == "Phonk")
    {
        return GenreType::Phonk;
    }

    if (genreType == "Rap")
    {
        return GenreType::Rap;
    }

    if (genreType == "Rock")
    {
        return GenreType::Rock;
    }

    if (genreType == "Jazz")
    {
        return GenreType::Jazz;
    }

    if (genreType == "Blues")
    {
        return GenreType::Blues;
    }

    return GenreType::None;
}

#endif
