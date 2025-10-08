/*! \file mouse.h
 *  \brief Заголовочный файл с описанием класса Mouse
 *  \details Содержит объявление класса Mouse, представляющего мышь как реализацию
 *           интерфейса InputDevice. Класс управляет положением курсора, типом
 *           сенсора и разрешением в DPI, а также предоставляет метод для перемещения курсора.
 */
#ifndef MOUSE
#define MOUSE
#include "input_device.h"

/*! \class Mouse
 *  \brief Класс, моделирующий периферийное устройство мыши
 *  \details Наследует InputDevice и реализует функциональность управления курсором:
 *           установка и получение координат, тип сенсора, разрешение в DPI и перемещение курсора.
 */
class Mouse : public InputDevice {
public:
    /*! \brief Конструктор по умолчанию */
    Mouse();

    /*! \brief Конструктор с инициализацией параметров
     *  \param cursorX Начальная координата X курсора
     *  \param cursorY Начальная координата Y курсора
     *  \param sensorType Тип сенсора
     *  \param dpi Разрешение сенсора в DPI
     */
    Mouse(int cursorX, int cursorY, const std::string &sensorType, int dpi);

    /*! \brief Установить координату X курсора
     *  \param cursorX Новое значение координаты X
     */
    void SetCursorX(int cursorX);

    /*! \brief Получить текущую координату X курсора
     *  \return Текущее значение координаты X
     */
    int GetCursorX() const;

    /*! \brief Установить координату Y курсора
     *  \param cursorY Новое значение координаты Y
     */
    void SetCursorY(int cursorY);

    /*! \brief Получить текущую координату Y курсора
     *  \return Текущее значение координаты Y
     */
    int GetCursorY() const;

    /*! \brief Установить тип сенсора мыши
     *  \param sensorType Строка, описывающая тип сенсора (например, "optical", "laser")
     */
    void SetSensorType(const std::string &sensorType);

    /*! \brief Получить тип сенсора мыши
     *  \return Строка с типом сенсора
     */
    std::string GetSensorType() const;

    /*! \brief Установить значение DPI (разрешение) сенсора
     *  \param dpi Новое значение DPI
     */
    void SetDpi(int dpi);

    /*! \brief Получить текущее значение DPI
     *  \return Текущее значение DPI
     */
    int GetDpi() const;

    /*! \brief Переместить курсор на указанный вектор смещения
     *  \param x Смещение по оси X
     *  \param y Смещение по оси Y
     *  \details Метод изменяет внутренние координаты курсора с учётом переданных смещений.
     */
    void MoveCursor(int x, int y);

private:
    int cursorX_{0}; /*!< Текущая координата X курсора */
    int cursorY_{0}; /*!< Текущая координата Y курсора */
    std::string sensorType_{""}; /*!< Тип сенсора */
    int dpi_{0}; /*!< Чувствительность мыши */
};

#endif
