/*! \file power_supply_cooler.h
 *  \brief Заголовочный файл с описанием класса PowerSupplyCooler
 *  \details Содержит объявление класса PowerSupplyCooler, представляющего вентилятор
 *           блока питания. Класс наследует Cooler и Hardware и предоставляет методы
 *           для управления минимальной и максимальной скоростью, а также получения типа.
 */
#ifndef POWERSUPPLYCOOLER
#define POWERSUPPLYCOOLER
#include "cooler.h"
#include "hardware.h"

/*! \class PowerSupplyCooler
 *  \brief Класс, моделирующий кулер блока питания
 *  \details Наследует Cooler и Hardware. Хранит минимальную и максимальную
 *           скорости и возвращает тип кулера как "psu".
 */
class PowerSupplyCooler : public Cooler, public Hardware {
public:
    /*! \brief Конструктор по умолчанию */
    PowerSupplyCooler();

    /*! \brief Конструктор с инициализацией минимальной и максимальной скорости
     *  \param minSpeed Минимальная скорость кулера
     *  \param maxSpeed Максимальная скорость кулера
     */
    PowerSupplyCooler(int minSpeed, int maxSpeed);

    /*! \brief Установить минимальную скорость кулера
     *  \param minSpeed Новая минимальная скорость
     */
    void SetMinSpeed(int minSpeed) override;

    /*! \brief Получить минимальную скорость кулера
     *  \return Минимальная скорость
     */
    int GetMinSpeed() const override;

    /*! \brief Установить максимальную скорость кулера
     *  \param maxSpeed Новая максимальная скорость
     */
    void SetMaxSpeed(int maxSpeed) override;

    /*! \brief Получить максимальную скорость кулера
     *  \return Максимальная скорость
     */
    int GetMaxSpeed() const override;

    /*! \brief Получить тип кулера в виде строки
     *  \return Строковое представление типа кулера
     */
    std::string GetType() const override;

    /*! \brief Установить текущую скорость работы вентилятора и вернуть текстовый статус
    *  \param speed Желаемая скорость в об/мин
    *  \return Строка с указанием установленной скорости или сообщение об ошибке
    */
    std::string SetCurrentSpeed(int speed) const override;

private:
    int minSpeed_{0}; /*!< Минимальная скорость кулера */
    int maxSpeed_{0}; /*!< Максимальная скорость кулера */
    std::string type_{"psu"}; /*!< Тип кулера */
};

#endif
