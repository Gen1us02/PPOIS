/*! \file play_button.h
 *  \brief Заголовочный файл с описанием класса PlayButton
 *  \details Содержит объявление класса PlayButton, представляющего кнопку
 *           воспроизведения и паузы трека. Класс наследует Button и реализует
 *           интерфейс для управления размерами кнопки и функциональностью
 *           воспроизведения музыкальных треков.
 */
#ifndef PLAY_BUTTON
#define PLAY_BUTTON
#include "button.h"
#include <cstring>
#include <vector>
#include <chrono>
#include <iostream>
#include <thread>
#include "../Track/track.h"
#include "../Exceptions/exceptions.h"

/*! \class PlayButton
 *  \brief Модель кнопки воспроизведения и паузы трека
 *  \details PlayButton наследуется от Button и предоставляет методы для управления
 *           размерами кнопки и управления воспроизведением музыкальных треков.
 *           Используется в пользовательском интерфейсе медиаплеера для контроля
 *           воспроизведения аудиоконтента.
 */
class PlayButton : public Button
{
public:
    /*! \brief Конструктор по умолчанию
     *  \details Инициализирует кнопку с нулевыми значениями ширины и высоты.
     */
    PlayButton();

    /*! \brief Деструктор
     *  \details Обеспечивает корректное уничтожение объекта кнопки.
     */
    ~PlayButton();

    /*! \brief Конструктор с инициализацией размеров
     *  \param width Ширина кнопки
     *  \param height Высота кнопки
     *  \details Позволяет создать кнопку с заданными размерами.
     */
    PlayButton(int width, int height);

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

    /*! \brief Воспроизвести трек
     *  \param track Трек для воспроизведения
     *  \details Запускает воспроизведение указанного трека, имитируя процесс
     *           проигрывания аудио с учетом длительности трека.
     */
    void PlayTrack(Track& track) const;

    /*! \brief Поставить трек на паузу
     *  \param track Трек для постановки на паузу
     *  \return Строка с подтверждением постановки на паузу
     *  \details Приостанавливает воспроизведение указанного трека и возвращает
     *           сообщение о текущем статусе воспроизведения.
     */
    std::string PauseTrack(Track& track) const;

private:
    int width_{0}; /*!< Ширина кнопки */
    int height_{0}; /*!< Высота кнопки */
};

#endif
