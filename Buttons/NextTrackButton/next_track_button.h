/*! \file next_track_button.h
 *  \brief Заголовочный файл с описанием класса NextTrackButton
 *  \details Содержит объявление класса NextTrackButton, представляющего кнопку
 *           переключения на следующий трек. Класс наследует Button и реализует
 *           интерфейс для управления размерами кнопки и функциональностью переключения треков.
 */
#ifndef NEXT_TRACK_BUTTON
#define NEXT_TRACK_BUTTON
#include "button.h"

/*! \class NextTrackButton
 *  \brief Модель кнопки переключения на следующий трек
 *  \details NextTrackButton наследуется от Button и предоставляет методы для управления
 *           размерами кнопки и переключения на следующий трек в плейлисте или альбоме.
 *           Используется в пользовательском интерфейсе медиаплеера для навигации по трекам.
 */
class NextTrackButton : public Button
{
public:
    /*! \brief Конструктор по умолчанию
     *  \details Инициализирует кнопку с нулевыми значениями ширины и высоты.
     */
    NextTrackButton();

    /*! \brief Деструктор
     *  \details Обеспечивает корректное уничтожение объекта кнопки.
     */
    ~NextTrackButton();

    /*! \brief Конструктор с инициализацией размеров
     *  \param width Ширина кнопки
     *  \param height Высота кнопки
     *  \details Позволяет создать кнопку с заданными размерами.
     */
    NextTrackButton(int width, int height);

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

    /*! \brief Получить индекс следующего трека
     *  \param currentTrackIndex Текущий индекс трека (входной и выходной параметр)
     *  \details Увеличивает переданный индекс текущего трека для перехода к следующему треку
     *           в последовательности воспроизведения.
     */
    void GetNextTrackIndex(int& currentTrackIndex);

private:
    int width_{0}; /*!< Ширина кнопки */
    int height_{0}; /*!< Высота кнопки */
};

#endif
