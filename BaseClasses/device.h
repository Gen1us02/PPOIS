/*! \file device.h
 *  \brief Заголовочный файл с описанием базового класса Device
 *  \details Содержит объявление класса Device, являющегося общей базой для аппаратных
 *           и логических устройств в системе. Класс хранит состояние подключения и питания,
 *           предоставляет методы включения/выключения, подключения/отключения и проверку
 *           поддержки типов портов. Предназначен для наследования конкретными устройствами.
 */
#ifndef DEVICE
#define DEVICE

#include <iostream>
#include <string>
#include "port_type.h"

/*! \class Device
 *  \brief Общая база для устройств системы
 *  \details Device инкапсулирует базовые свойства любого устройства: флаги подключения
 *           и питания, а также ассоциированный тип порта. Класс предоставляет виртуальный
 *           метод SupportsPort для проверки совместимости с конкретным типом интерфейса,
 *           методы управления состоянием подключения и питания, которые могут быть
 *           использованы или переопределены в производных классах.
 */
class Device {
public:
    /*! \brief Виртуальный деструктор
     *  \details Обеспечивает корректное уничтожение производных классов через указатель
     *           на базовый тип Device.
     */
    virtual ~Device() = default;

    Device() = default;

    Device(const Device &other)
        : isConnected_(other.isConnected_),
          isPowered_(other.isPowered_),
          port_(other.port_) {
    }

    Device &operator=(const Device &other) {
        if (this != &other) {
            isConnected_ = other.isConnected_;
            isPowered_ = other.isPowered_;
            port_ = other.port_;
        }
        return *this;
    }

    /*! \brief Проверить поддержку типа порта
     *  \param p Проверяемый тип порта
     *  \return true если устройство поддерживает указанный порт, false иначе
     *  \details Базовая реализация сравнивает переданный тип с внутренним полем port_.
     *           Производные классы могут переопределить поведение для более сложной логики.
     */
    virtual bool SupportsPort(PortType p) const {
        return this->port_ == p;
    }

    /*! \brief Подключить устройство
     *  \details Устанавливает флаг подключения в true. Если устройство уже подключено,
     *           повторный вызов игнорируется.
     */
    void Connect() {
        if (isConnected_) return;
        this->isConnected_ = true;
    };

    /*! \brief Отключить устройство
     *  \details Сбрасывает флаг подключения. Если устройство уже отключено, вызов игнорируется.
     */
    void Disconnect() {
        if (!isConnected_) return;
        this->isConnected_ = false;
    }

    /*! \brief Проверить, подключено ли устройство
     *  \return true если устройство подключено, false если нет
     */
    bool IsConnected() const {
        return this->isConnected_;
    }

    /*! \brief Включить питание устройства
     *  \details Устанавливает флаг питания в true. Производные классы могут расширить
     *           поведение дополнительной инициализацией.
     */
    void TurnOn() {
        this->isPowered_ = true;
    }

    /*! \brief Выключить питание устройства
     *  \details Сбрасывает флаг питания. Производные классы могут реализовать корректное
     *           завершение работы в переопределённых методах.
     */
    void TurnOff() {
        this->isPowered_ = false;
    }

protected:
    bool isConnected_{false}; /*!< Флаг состояния подключения устройства */
    bool isPowered_{false}; /*!< Флаг состояния питания устройства */
    PortType port_{PortType::None}; /*!< Тип порта устройства */
};

#endif
