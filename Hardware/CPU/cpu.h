/*! \file cpu.h
 *  \brief Заголовочный файл с описанием класса CPU
 *  \details Содержит объявление класса CPU, моделирующего центральный процессор.
 *           Класс предоставляет методы для установки и получения параметров сокета,
 *           числа ядер и потоков, базовой и максимальной частоты, а также управления
 *           режимом турбо-частоты.
 */
#ifndef CPUDEVICE
#define CPUDEVICE
#include <string>
#include "hardware.h"

/*! \class CPU
 *  \brief Класс, моделирующий центральный процессор
 *  \details Наследует Hardware. Хранит параметры процессора: тип сокета,
 *           количество ядер, максимальное количество потоков, базовую и максимальную
 *           частоты. Предоставляет методы для изменения и получения этих параметров
 *           и для переключения турбо-режима.
 */
class CPU : public Hardware {
public:
    /*! \brief Конструктор по умолчанию */
    CPU();

    /*! \brief Конструктор с инициализацией параметров
     *  \param socketType Строка с названием типа сокета
     *  \param coreCount Число физических ядер процессора
     *  \param maxThreadCount Максимальное число потоков
     *  \param baseFrequency Базовая рабочая частота в ГГц
     *  \param maxFrequency Максимальная частота в ГГц
     */
    CPU(const std::string &socketType, int coreCount, int maxThreadCount, double baseFrequency, double maxFrequency);

    /*! \brief Установить тип сокета процессора
     *  \param socketType Строка с названием сокета
     */
    void SetSocketType(const std::string &socketType);

    /*! \brief Получить тип сокета процессора
     *  \return Строка с названием сокета
     */
    std::string GetSocketType() const;

    /*! \brief Установить количество физических ядер
     *  \param coreCount Новое значение количества ядер
     */
    void SetCoreCount(int coreCount);

    /*! \brief Получить количество физических ядер
     *  \return Текущее количество ядер
     */
    int GetCoreCount() const;

    /*! \brief Установить максимальное число потоков
     *  \param maxThreadCount Новое значение максимального числа потоков
     */
    void SetMaxTreadCount(int maxThreadCount);

    /*! \brief Получить максимальное число потоков
     *  \return Текущее значение максимального числа потоков
     */
    int GetMaxTreadCount() const;

    /*! \brief Установить базовую рабочую частоту
     *  \param baseFrequency Частота в ГГц
     */
    void SetBaseFrequency(double baseFrequency);

    /*! \brief Получить базовую рабочую частоту
     *  \return Частота в ГГц
     */
    double GetBaseFrequency() const;

    /*! \brief Установить максимальную частоту
     *  \param maxFrequency Максимальная частота в ГГц
     */
    void SetMaxFrequency(double maxFrequency);

    /*! \brief Получить максимальную частоту
     *  \return Частота в ГГц
     */
    double GetMaxFrequency() const;

    /*! \brief Включить или отключить турбо-режим процессора
     *  \param mode true для включения турбо-режима, false для отключения
     *  \return Текстовое сообщение о результате операции
     */
    std::string SetTurboMode(bool mode) const;

private:
    std::string socketType_{""}; /*!< Тип сокета процессора */
    int coreCount_{0}; /*!< Число физических ядер */
    int maxThreadCount_{0}; /*!< Максимальное число потоков */
    double baseFrequency_{0.0}; /*!< Базовая частота в ГГц */
    double maxFrequency_{0.0}; /*!< Максимальная частота в ГГц */
};

#endif
