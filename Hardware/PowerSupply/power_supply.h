/*! \file power_supply.h
 *  \brief Заголовочный файл с описанием класса PowerSupply
 *  \details Содержит объявление класса PowerSupply, моделирующего блок питания.
 *           Класс предоставляет интерфейс для управления мощностью, КПД,
 *           параметрами напряжения и вентилятором блока питания, а также
 *           диагностику состояния подачи напряжения.
 */
#ifndef POWERSUPPLY
#define POWERSUPPLY
#include <string>
#include "hardware.h"
#include "../Hardware/Coolers/PowerSupplyCooler/power_supply_cooler.h"

/*! \class PowerSupply
 *  \brief Класс, моделирующий блок питания
 *  \details Наследуется от Hardware и хранит параметры блока питания:
 *           выходную мощность, эффективность, минимальное и максимальное
 *           допустимое напряжение, а также встроенный кулер. Предоставляет
 *           методы для изменения этих параметров и проверки корректности
 *           диапазона питающего напряжения.
 */
class PowerSupply : public Hardware {
public:
    /*! \brief Конструктор по умолчанию */
    PowerSupply();

    /*! \brief Конструктор с инициализацией параметров
     *  \param minSpeed Минимальная скорость кулера блока питания
     *  \param maxSpeed Максимальная скорость кулера блока питания
     *  \param power Выходная мощность блока питания (в ваттах)
     *  \param efficiency КПД блока питания (в процентах)
     *  \param minVoltage
     *  \param maxVoltage Максимальное допустимое входное напряжение (в вольтах)
     */
    PowerSupply(int minSpeed, int maxSpeed, int power, int efficiency, int minVoltage, int maxVoltage);

    /*! \brief Установить выходную мощность блока питания
     *  \param power Новая мощность в ваттах
     */
    void SetPower(int power);

    /*! \brief Получить текущую выходную мощность блока питания
     *  \return Мощность в ваттах
     */
    int GetPower() const;

    /*! \brief Установить КПД блока питания
     *  \param efficiency Новое значение КПД в процентах
     */
    void SetEfficiency(int efficiency);

    /*! \brief Получить текущее значение КПД блока питания
     *  \return КПД в процентах
     */
    int GetEfficiency() const;

    /*! \brief Установить текущую скорость кулера блока питания
     *  \param speed Новая скорость кулера
     *  \return Сообщение об установке скорости или об ошибке
     */
    std::string SetCoolerCurrentSpeed(int speed) const;

    /*! \brief Установить минимальное допустимое входное напряжение
     *  \param minVoltage Минимальное напряжение в вольтах
     */
    void SetMinVoltage(int minVoltage);

    /*! \brief Получить минимальное допустимое входное напряжение
     *  \return Минимальное напряжение в вольтах
     */
    int GetMinVoltage() const;

    /*! \brief Установить максимальное допустимое входное напряжение
     *  \param voltage Максимальное напряжение в вольтах
     */
    void SetMaxVoltage(int voltage);

    /*! \brief Получить максимальное допустимое входное напряжение
     *  \return Максимальное напряжение в вольтах
     */
    int GetMaxVoltage() const;

    /*! \brief Получить сообщение о состоянии подачи напряжения
     *  \details Возвращает строку с информацией о корректности поданного
     *           напряжения: если напряжение в допустимом диапазоне — сообщение
     *           об успешной подаче, иначе — сообщение об ошибке/остановке.
     *  \param voltage Текущее поданное напряжение для проверки
     *  \return Текстовое сообщение с результатом проверки
     */
    std::string VoltageSupplyMessage(int voltage) const;

private:
    /*! \brief Проверить, находится ли поданное напряжение в допустимом диапазоне
     *  \param voltage Текущее поданное напряжение в вольтах
     *  \return true если напряжение в диапазоне от minVoltage_ до maxVoltage_, false иначе
     */
    bool VoltageSupply(int voltage) const;

    int power_{0}; /*!< Выходная мощность в ваттах */
    int efficiency_{0}; /*!< КПД в процентах */
    int minVoltage_{0}; /*!< Минимальное допустимое входное напряжение в вольтах */
    int maxVoltage_{0}; /*!< Максимальное допустимое входное напряжение в вольтах */
    PowerSupplyCooler cooler_; /*!< Встроенный кулер блока питания */
};

#endif
