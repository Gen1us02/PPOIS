/*! \file ram.h
 *  \brief Заголовочный файл с описанием класса RAM
 *  \details Содержит объявление класса RAM, представляющего модули оперативной памяти.
 *           Класс наследуется от Hardware и предоставляет методы для управления
 *           числом модулей, объёмом памяти, типом, частотой и состоянием включения,
 *           а также метод для получения текстового статуса памяти.
 */
#ifndef RAMDEVICE
#define RAMDEVICE
#include <string>
#include "hardware.h"

/*! \class RAM
 *  \brief Класс, моделирующий оперативную память
 *  \details Наследует Hardware. Хранит параметры модулей памяти: количество модулей,
 *           общий объём, тип, рабочую частоту и состояние включения. Предоставляет
 *           интерфейс для управления этими параметрами и получения статуса.
 */
class RAM : public Hardware{
public:
    /*! \brief Конструктор по умолчанию */
    RAM();

    /*! \brief Конструктор с инициализацией параметров
     *  \param moduleCount Число модулей памяти
     *  \param memory Общий объём памяти (в выбранных единицах)
     *  \param type Строка, описывающая тип памяти (например, "DDR4")
     *  \param frequency Рабочая частота памяти (в МГц)
     */
    RAM(int memory, const std::string& type, int frequency);

    /*! \brief Установить объём памяти
     *  \param memory Новый объём памяти
     */
    void SetMemory(int memory);

    /*! \brief Получить объём памяти
     *  \return Текущий объём памяти
     */
    int GetMemory() const;

    /*! \brief Установить тип памяти
     *  \param type Строка с описанием типа памяти
     */
    void SetType(const std::string& type);

    /*! \brief Получить тип памяти
     *  \return Строка с типом памяти
     */
    std::string GetType() const;

    /*! \brief Установить рабочую частоту памяти
     *  \param frequency Новая частота в МГц
     */
    void SetFrequency(int frequency);

    /*! \brief Получить рабочую частоту памяти
     *  \return Частота в МГц
     */
    int GetFrequency() const;

    /*! \brief Включить или выключить модули памяти
     *  \param enabled true для включения, false для выключения
     */
    void SetEnabled(bool enabled);

    /*! \brief Проверить, включена ли память
     *  \return true если память включена, false в противном случае
     */
    bool IsEnabled() const;

    /*! \brief Получить текстовый статус RAM
     *  \return Строка с описанием текущего состояния памяти
     */
    std::string RamStatus() const;
private:
    int memory_ {0};        /*!< Общий объём памяти */
    std::string type_ {0};  /*!< Тип памяти */
    int frequency_ {0};     /*!< Частота памяти в МГц */
    bool enabled_ {false};  /*!< Флаг состояния включения */
};


#endif
