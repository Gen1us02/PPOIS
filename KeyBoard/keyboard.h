/*! \file keyboard.h
 *  \brief Заголовочный файл с описанием класса KeyBoard
 *  \details Содержит объявление класса KeyBoard, представляющего клавиатуру
 *           как реализацию интерфейса InputDevice. Класс предоставляет методы
 *           для установки и получения типа клавиатуры и обработки нажатий клавиш.
 */
#ifndef KEYBOARD
#define KEYBOARD
#include "input_device.h"

/*! \class KeyBoard
 *  \brief Класс, моделирующий клавиатуру
 *  \details Наследуется от InputDevice и реализует базовую функциональность
 *           клавиатуры: хранение типа устройства и обработку нажатий кнопок.
 */
class KeyBoard : public InputDevice{
public:
    /*! \brief Конструктор по умолчанию */
    KeyBoard();

    /*! \brief Конструктор с установкой типа клавиатуры
     *  \param type Строка, описывающая тип клавиатуры
     */
    KeyBoard(const std::string& type);

    /*! \brief Установить тип клавиатуры
     *  \param type Новое значение типа клавиатуры
     */
    void SetType(const std::string& type);

    /*! \brief Получить тип клавиатуры
     *  \return Строка с текущим типом клавиатуры
     */
    std::string GetType() const;

    /*! \brief Обработать нажатие кнопки
     *  \param key Строка с именем или кодом нажатой кнопки
     *  \return Строковое сообщение о результате нажатия
     */
    std::string PressButton(const std::string& key);
private:
    std::string type_ {""}; /*!< Тип клавиатуры */
};

#endif
