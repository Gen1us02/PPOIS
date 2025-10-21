/*! \file now_playing_button.h
 *  \brief Заголовочный файл с описанием класса NowPlayingButton
 *  \details Содержит объявление класса NowPlayingButton, представляющего кнопку
 *           отображения текущего играющего трека. Класс наследует Button и реализует
 *           интерфейс для управления размерами кнопки и отображения информации о текущем треке.
 */
#ifndef NOW_PLAYING_BUTTON
#define NOW_PLAYING_BUTTON
#include "button.h"
#include "../Track/track.h"
#include <string>

/*! \class NowPlayingButton
 *  \brief Модель кнопки отображения текущего играющего трека
 *  \details NowPlayingButton наследуется от Button и предоставляет методы для управления
 *           размерами кнопки и отображения информации о текущем воспроизводимом треке.
 *           Используется в пользовательском интерфейсе медиаплеера для показа информации
 *           о треке, который играет в данный момент.
 */
class NowPlayingButton : public Button
{
public:
    /*! \brief Конструктор по умолчанию
     *  \details Инициализирует кнопку с нулевыми значениями ширины и высоты.
     */
    NowPlayingButton();

    /*! \brief Деструктор
     *  \details Обеспечивает корректное уничтожение объекта кнопки.
     */
    ~NowPlayingButton();

    /*! \brief Конструктор с инициализацией размеров
     *  \param width Ширина кнопки
     *  \param height Высота кнопки
     *  \details Позволяет создать кнопку с заданными размерами.
     */
    NowPlayingButton(int width, int height);

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

    /*! \brief Показать информацию о текущем играющем треке
     *  \param track Ссылка на объект текущего трека
     *  \return Строка с форматированной информацией о текущем треке
     *  \details Возвращает подробную информацию об указанном треке
     *           в удобочитаемом строковом формате, включая название,
     *           исполнителя и другую релевантную информацию.
     */
    std::string ShowNowPlayingTrackInfo(const Track& track) const;

private:
    int width_{0}; /*!< Ширина кнопки */
    int height_{0}; /*!< Высота кнопки */
};

#endif
