/*! \file previous_track_button.h
 *  \brief Заголовочный файл с описанием класса PreviousTrackButton
 *  \details Содержит объявление класса PreviousTrackButton, представляющего кнопку
 *           переключения на предыдущий трек. Класс наследует Button и реализует
 *           интерфейс для управления размерами кнопки и функциональностью переключения треков.
 */
#ifndef PREVIOUS_TRACK_BUTTON
#define PREVIOUS_TRACK_BUTTON
#include "button.h"

/*! \class PreviousTrackButton
 *  \brief Модель кнопки переключения на предыдущий трек
 *  \details PreviousTrackButton наследуется от Button и предоставляет методы для управления
 *           размерами кнопки и переключения на предыдущий трек в плейлисте или альбоме.
 *           Используется в пользовательском интерфейсе медиаплеера для навигации по трекам.
 */
class PreviousTrackButton : public Button
{
public:
    /*! \brief Конструктор по умолчанию
     *  \details Инициализирует кнопку с нулевыми значениями ширины и высоты.
     */
    PreviousTrackButton();

    /*! \brief Деструктор
     *  \details Обеспечивает корректное уничтожение объекта кнопки.
     */
    ~PreviousTrackButton();

    /*! \brief Конструктор с инициализацией размеров
     *  \param width Ширина кнопки
     *  \param height Высота кнопки
     *  \details Позволяет создать кнопку с заданными размерами.
     */
    PreviousTrackButton(int width, int height);

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

    /*! \brief Получить индекс предыдущего трека
     *  \param currentTrackIndex Текущий индекс трека (входной и выходной параметр)
     *  \details Уменьшает переданный индекс текущего трека для перехода к предыдущему треку
     *           в последовательности воспроизведения.
     */
    void GetPreviousTrackIndex(int& currentTrackIndex);

private:
    int width_{0}; /*!< Ширина кнопки */
    int height_{0}; /*!< Высота кнопки */
};

#endif
