/*! \file mark_favourite_button.h
 *  \brief Заголовочный файл с описанием класса MarkFavouriteButton
 *  \details Содержит объявление класса MarkFavouriteButton, представляющего кнопку
 *           для добавления и удаления треков из избранного. Класс наследует Button
 *           и реализует интерфейс для управления размерами кнопки и работы с избранными треками.
 */
#ifndef MARK_FAVOURITE_BUTTON
#define MARK_FAVOURITE_BUTTON
#include "button.h"
#include "../Track/track.h"
#include "../Playlists/FavouritePlaylist/favourite_playlist.h"

/*! \class MarkFavouriteButton
 *  \brief Модель кнопки для управления избранными треками
 *  \details MarkFavouriteButton наследуется от Button и предоставляет методы для управления
 *           размерами кнопки и выполнения операций добавления/удаления треков из плейлиста избранного.
 *           Используется в пользовательском интерфейсе для управления предпочтениями пользователя.
 */
class MarkFavouriteButton : public Button
{
public:
    /*! \brief Конструктор по умолчанию
     *  \details Инициализирует кнопку с нулевыми значениями ширины и высоты.
     */
    MarkFavouriteButton();

    /*! \brief Деструктор
     *  \details Обеспечивает корректное уничтожение объекта кнопки.
     */
    ~MarkFavouriteButton();

    /*! \brief Конструктор с инициализацией размеров
     *  \param width Ширина кнопки
     *  \param height Высота кнопки
     *  \details Позволяет создать кнопку с заданными размерами.
     */
    MarkFavouriteButton(int width, int height);

    /*! \brief Установить ширину кнопки
     *  \param width Новая ширина кнопки
     *  \details Устанавливает ширину визуального представления кнопки.
     */
    void SetWidth(int width) override;

    /*! \brief Получить ширину кнопки
     *  \return Ширина кнопки
     *  \details Возвращает текущую установленную ширину кнопки.
     */
    int GetWidth() const override;

    /*! \brief Установить высоту кнопки
     *  \param height Новая высота кнопки
     *  \details Устанавливает высоту визуального представления кнопки.
     */
    void SetHeight(int height) override;

    /*! \brief Получить высоту кнопки
     *  \return Высота кнопки
     *  \details Возвращает текущую установленную высоту кнопки.
     */
    int GetHeight() const override;

    /*! \brief Добавить трек в избранное
     *  \param track Трек для добавления в избранное
     *  \param playlist Плейлист избранного для добавления трека
     *  \details Помечает указанный трек как избранный и добавляет его в плейлист избранного.
     */
    void MarkFavourite(Track& track, FavouritePlaylist& playlist);

    /*! \brief Удалить трек из избранного
     *  \param track Трек для удаления из избранного
     *  \param playlist Плейлист избранного для удаления трека
     *  \details Убирает пометку избранного с указанного трека и удаляет его из плейлиста избранного.
     */
    void UnmarkFavourite(Track& track, FavouritePlaylist& playlist);

private:
    int width_{0}; /*!< Ширина кнопки */
    int height_{0}; /*!< Высота кнопки */
};

#endif
