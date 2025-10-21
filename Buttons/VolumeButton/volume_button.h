/*! \file volume_button.h
 *  \brief Заголовочный файл с описанием класса VolumeButton
 *  \details Содержит объявление класса VolumeButton, представляющего кнопку
 *           управления громкостью. Класс наследует Button и реализует
 *           интерфейс для управления размерами кнопки и функциональностью
 *           включения/выключения звука.
 */
#ifndef VOLUME_BUTTON
#define VOLUME_BUTTON
#include "button.h"

/*! \class VolumeButton
 *  \brief Модель кнопки управления громкостью
 *  \details VolumeButton наследуется от Button и предоставляет методы для управления
 *           размерами кнопки и контроля уровня громкости. Используется в пользовательском
 *           интерфейсе медиаплеера для включения, выключения и восстановления уровня громкости.
 */
class VolumeButton : public Button
{
public:
    /*! \brief Конструктор по умолчанию
     *  \details Инициализирует кнопку с нулевыми значениями ширины и высоты.
     */
    VolumeButton();

    /*! \brief Деструктор
     *  \details Обеспечивает корректное уничтожение объекта кнопки.
     */
    ~VolumeButton();

    /*! \brief Конструктор с инициализацией размеров
     *  \param width Ширина кнопки
     *  \param height Высота кнопки
     *  \details Позволяет создать кнопку с заданными размерами.
     */
    VolumeButton(int width, int height);

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

    /*! \brief Отключить громкость
     *  \param volume Текущая громкость (будет установлена в 0)
     *  \details Устанавливает уровень громкости в 0, эффективно отключая звук.
     */
    void DisableVolume(int& volume);

    /*! \brief Включить громкость
     *  \param volume Переменная для установки уровня громкости
     *  \param lastVolume Предыдущее значение громкости для восстановления
     *  \details Восстанавливает уровень громкости до предыдущего значения
     *           после отключения звука.
     */
    void EnableVolume(int& volume, int lastVolume);

private:
    int width_{0}; /*!< Ширина кнопки */
    int height_{0}; /*!< Высота кнопки */
};

#endif
