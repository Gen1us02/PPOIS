/*! \file track_text_button.h
 *  \brief Заголовочный файл с описанием класса TrackTextButton
 *  \details Содержит объявление класса TrackTextButton, представляющего кнопку
 *           для отображения текста трека. Класс наследует Button и реализует
 *           интерфейс для управления размерами кнопки и получения текстового
 *           содержимого трека.
 */
#ifndef TRACK_TEXT_BUTTON
#define TRACK_TEXT_BUTTON
#include <string>
#include "button.h"
#include "../Track/track.h"

/*! \class TrackTextButton
 *  \brief Модель кнопки для отображения текста трека
 *  \details TrackTextButton наследуется от Button и предоставляет методы для управления
 *           размерами кнопки и получения текстового содержимого указанного трека.
 *           Используется в пользовательском интерфейсе для отображения текста песен.
 */
class TrackTextButton : public Button
{
public:
    /*! \brief Конструктор по умолчанию
     *  \details Инициализирует кнопку с нулевыми значениями ширины и высоты.
     */
    TrackTextButton();

    /*! \brief Деструктор
     *  \details Обеспечивает корректное уничтожение объекта кнопки.
     */
    ~TrackTextButton();

    /*! \brief Конструктор с инициализацией размеров
     *  \param width Ширина кнопки
     *  \param height Высота кнопки
     *  \details Позволяет создать кнопку с заданными размерами.
     */
    TrackTextButton(int width, int height);

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

    /*! \brief Получить текст трека
     *  \param track Ссылка на объект трека
     *  \return Строка с текстом трека
     *  \details Возвращает текстовое содержимое (лирику) указанного трека.
     */
    std::string GetTrackText(const Track& track);

private:
    int width_{0}; /*!< Ширина кнопки */
    int height_{0}; /*!< Высота кнопки */
};

#endif
