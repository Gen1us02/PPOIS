/*! \file input_device.h
 *  \brief Заголовочный файл с описанием класса InputDevice
 *  \details Содержит объявление класса InputDevice, представляющего базовый интерфейс
 *           для устройств ввода в системе. Класс наследует Device и предоставляет простую
 *           реализацию приёма текстовых входных данных, хранение последнего введённого
 *           значения и доступ к нему. Предназначен для моделирования клавиатур, мышей,
 *           веб-камер и других источников ввода в тестах и симуляциях.
 */
#ifndef IDEVICE
#define IDEVICE
#include <iostream>
#include <string>
#include "device.h"

/*! \class InputDevice
 *  \brief Базовый класс для устройств ввода
 *  \details InputDevice реализует общий контракт для устройств, принимающих текстовые
 *           команды или события. Класс хранит последнее полученное входное значение
 *           и предоставляет методы для установки и получения этого значения. Может быть
 *           унаследован конкретными реализациями ввода для расширения поведения.
 */
class InputDevice: public Device{
public:
    /*! \brief Виртуальный деструктор
     *  \details Обеспечивает корректное разрушение производных классов через указатель
     *           на базовый тип InputDevice.
     */
    virtual ~InputDevice() = default;

    InputDevice() = default;

    InputDevice(const InputDevice& other)
        : Device(other),
          input_(other.input_) {}

    InputDevice& operator=(const InputDevice& other) {
        if (this != &other) {
            Device::operator=(other);
            input_ = other.input_;
        }
        return *this;
    }

    /*! \brief Получить последнее сохранённое входное значение
     *  \return Строка с последним вводом
     *  \details Возвращает текущее содержимое внутреннего поля input_.
     */
    std::string GetInput() const{
        return this->input_;
    };

protected:
    /*! \brief Обработать и сохранить входную строку
     *  \param input Входная строка данных
     *  \details Метод сохраняет переданную строку во внутреннее поле для последующего
     *           использования или получения внешними компонентами системы.
     */
    void ReadInput(const std::string& input){
        this->input_ = input;
    };

    std::string input_ {""}; /*!< Внутренний буфер для ввода */
};

#endif