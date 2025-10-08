/*! \file motherboard_battery.h
 *  \brief Заголовочный файл с описанием класса MotherBoardBattery
 *  \details Содержит объявление класса MotherBoardBattery, представляющего
 *           батарейку для материнской платы. Класс наследует
 *           интерфейс Battery и реализует методы управления напряжением,
 *           типом и ёмкостью, а также проверку работоспособности батареи.
 */
#ifndef MOTHERBOARDBATTERY
#define MOTHERBOARDBATTERY
#include "battery.h"

/*! \class MotherBoardBattery
 *  \brief Класс, моделирующий батарею материнской платы
 *  \details Наследует Battery. Предоставляет методы установки и получения
 *           напряжения и типа, управления ёмкостью и проверки, «живая» ли батарея.
 */
class MotherBoardBattery : public Battery {
public:
    /*! \brief Конструктор по умолчанию */
    MotherBoardBattery();

    /*! \brief Конструктор с инициализацией параметров
     *  \param voltage Значение напряжения батареи (в вольтах)
     *  \param type Строка, описывающая тип батареи
     *  \param capacity Ёмкость батареи (в мА·ч)
     */
    MotherBoardBattery(int voltage, const std::string &type, int capacity);

    /*! \brief Установить напряжение батареи
     *  \param voltage Новое значение напряжения
     *  \note Переопределяет виртуальный метод Battery
     */
    void SetVoltage(int voltage) override;

    /*! \brief Получить текущее напряжение батареи
     *  \return Текущее значение напряжения
     *  \note Переопределяет виртуальный метод Battery
     */
    int GetVoltage() const override;

    /*! \brief Установить тип батареи
     *  \param type Строка с описанием типа батареи
     *  \note Переопределяет виртуальный метод Battery
     */
    void SetType(const std::string &type) override;

    /*! \brief Получить тип батареи
     *  \return Строка с типом батареи
     *  \note Переопределяет виртуальный метод Battery
     */
    std::string GetType() const override;

    /*! \brief Установить ёмкость батареи
     *  \param capacity Новая ёмкость батареи
     */
    void SetCapacity(int capacity);

    /*! \brief Получить текущую ёмкость батареи
     *  \return Текущее значение ёмкости
     */
    int GetCapacity() const;

    /*! \brief Проверить, работоспособна ли батарея
     *  \return true если батарея считается живой,
     *          false если батарея разряжена или требует замены
     */
    bool IsAlive() const;

private:
    int voltage_{0}; /*!< Текущее напряжение батареи */
    std::string type_{""}; /*!< Тип батареи */
    int capacity_{0}; /*!< Ёмкость батареи */
};

#endif
