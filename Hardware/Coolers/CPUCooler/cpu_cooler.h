/*! \file cpu_cooler.h
 *  \brief Заголовочный файл с описанием класса CPUCooler
 *  \details Содержит объявление класса CPUCooler, представляющего кулер для процессора.
 *           Класс наследует Cooler и Hardware и предоставляет методы для управления
 *           минимальной и максимальной скоростью, сокетом и получения типа кулера.
 */
#ifndef CPUCOOLER
#define CPUCOOLER
#include "cooler.h"
#include "hardware.h"


/*! \class CPUCooler
 *  \brief Класс, моделирующий кулер процессора
 *  \details Наследует Cooler и Hardware. Хранит минимальную и максимальную
 *           скорости, совместимый сокет и возвращает тип кулера как "cpu".
 */
class CPUCooler : public Cooler, public Hardware {
public:
    /*! \brief Конструктор по умолчанию */
    CPUCooler();

    /*! \brief Конструктор с инициализацией параметров
     *  \param minSpeed Минимальная скорость кулера
     *  \param maxSpeed Максимальная скорость кулера
     *  \param socket Совместимый тип сокета
     */
    CPUCooler(int minSpeed, int maxSpeed, const std::string &socket);

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
     *  \note Переопределяет метод интерфейса Cooler
     */
    void SetMaxSpeed(int maxSpeed) override;

    /*! \brief Получить максимальную скорость кулера
     *  \return Максимальная скорость
     */
    int GetMaxSpeed() const override;

    /*! \brief Установить совместимый сокет кулера
     *  \param socket Строка с названием сокета
     */
    void SetSocket(const std::string &socket);

    /*! \brief Получить совместимый сокет кулера
     *  \return Строка с именем сокета
     */
    std::string GetSocket() const;

    /*! \brief Получить тип кулера в виде строки
     *  \return Строковое представление типа кулера ("cpu")
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
    std::string socket_{""}; /*!< Совместимый тип сокета */
    std::string type_{"cpu"}; /*!< Тип кулера */
};

#endif
