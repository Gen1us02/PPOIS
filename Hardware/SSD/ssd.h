/*! \file ssd.h
 *  \brief Заголовочный файл с описанием класса SSD
 *  \details Содержит объявление класса SSD, представляющего твердотельный
 *           накопитель как реализацию интерфейса MemoryDevice и Hardware.
 *           Класс предоставляет методы управления объёмом памяти, скоростями
 *           чтения/записи, временем до отказа и расчётом времени операций ввода/вывода.
 */
#ifndef SSDDEVICE
#define SSDDEVICE
#include <string>
#include "memory_device.h"
#include "hardware.h"
#include "port_type.h"

/*! \class SSD
 *  \brief Класс, моделирующий SSD накопитель
 *  \details Наследует MemoryDevice и Hardware. Хранит параметры накопителя:
 *           размер памяти, скорости чтения и записи, ожидаемое время до поломки
 *           и тип порта. Предоставляет интерфейс для установки и получения этих
 *           параметров, проверки поддержки порта и оценки времени операций.
 */
class SSD : public MemoryDevice, public Hardware{
public:
    /*! \brief Конструктор по умолчанию */
    SSD();

    /*! \brief Конструктор с инициализацией параметров
     *  \param memorySize Размер памяти накопителя (в ГБ)
     *  \param readSpeed Скорость чтения (в МБ/с)
     *  \param writeSpeed Скорость записи (в МБ/с)
     *  \param timeBeforeBreak Время до отказа/среднее время наработки (в часах)
     */
    SSD(int memorySize, int readSpeed, int writeSpeed, int timeBeforeBreak);

    /*! \brief Установить объём памяти накопителя
     *  \param memorySize Новый объём памяти
     */
    void SetMemorySize(int memorySize) override;

    /*! \brief Получить объём памяти накопителя
     *  \return Текущий объём памяти
     */
    int GetMemorySize() const override;

    /*! \brief Установить скорость чтения
     *  \param readSpeed Скорость чтения в МБ/с
     */
    void SetReadSpeed(int readSpeed);

    /*! \brief Получить скорость чтения
     *  \return Скорость чтения в МБ/с
     */
    int GetReadSpeed() const;

    /*! \brief Установить скорость записи
     *  \param writeSpeed Скорость записи в МБ/с
     */
    void SetWriteSpeed(int writeSpeed);

    /*! \brief Получить скорость записи
     *  \return Скорость записи в МБ/с
     */
    int GetWriteSpeed() const;

    /*! \brief Проверить поддержку конкретного типа порта
     *  \param p Тип порта для проверки
     *  \return true если данный SSD поддерживает указанный тип порта, false в противном случае
     */
    bool SupportsPort(PortType p) const;

    /*! \brief Установить время до поломки
     *  \param timeBeforeBreak Время до поломки
     */
    void SetTimeBeforeBreak(int timeBeforeBreak);

    /*! \brief Получить время до поломки
     *  \return Текущее значение времени до поломки
     */
    int GetTimeBeforeBreak() const;

    /*! \brief Оценить время чтения заданного объёма данных
     *  \param dataSize Объём данных для чтения
     *  \return Оценочное время чтения в секундах или в другой выбранной единице
     */
    double ReadTime(int dataSize);

    /*! \brief Оценить время записи заданного объёма данных
     *  \param dataSize Объём данных для записи
     *  \return Оценочное время записи в секундах или в другой выбранной единице
     */
    double WriteTime(int dataSize);

private:
    int memorySize_ {0};        /*!< Размер памяти накопителя */
    int readSpeed_ {0};         /*!< Скорость чтения в МБ/с */
    int writeSpeed_ {0};        /*!< Скорость записи в МБ/с */
    int timeBeforeBreak_ {0};   /*!< Ожидаемое время до поломки в часах */
    PortType port_ {PortType::M2}; /*!< Тип порта, к которому ориентирован SSD */
};

#endif