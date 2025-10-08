/*! \file hdd.h
 *  \brief Заголовочный файл с описанием класса HDD
 *  \details Содержит объявление класса HDD, представляющего жесткий диск как
 *           реализацию интерфейсов MemoryDevice и Hardware. Класс управляет
 *           объёмом памяти, скоростью вращения шпинделя и технологией записи.
 */
#ifndef HDDDEVICE
#define HDDDEVICE
#include <string>
#include "memory_device.h"
#include "hardware.h"

/*! \class HDD
 *  \brief Класс, моделирующий жесткий диск
 *  \details Наследует MemoryDevice и Hardware. Хранит параметры накопителя:
 *           объём памяти, скорость вращения шпинделя и тип технологии записи.
 *           Предоставляет интерфейс для установки и получения этих параметров.
 */
class HDD : public MemoryDevice, public Hardware {
public:
    /*! \brief Конструктор по умолчанию */
    HDD();

    /*! \brief Конструктор с инициализацией параметров
     *  \param memorySize Объём памяти накопителя (в Гб)
     *  \param spindleSpeed Скорость вращения шпинделя
     *  \param recordTechnology Строка, описывающая технологию записи
     */
    HDD(int memorySize, int spindleSpeed, const std::string &recorecordTechnology);

    /*! \brief Установить объём памяти накопителя
     *  \param memorySize Новый объём памяти
     */
    void SetMemorySize(int memorySize) override;

    /*! \brief Получить объём памяти накопителя
     *  \return Текущий объём памяти
     */
    int GetMemorySize() const override;

    /*! \brief Установить скорость вращения шпинделя
     *  \param spindleSpeed Скорость шпинделя
     */
    void SetSpindleSpeed(int spindleSpeed);

    /*! \brief Получить скорость вращения шпинделя
     *  \return Скорость шпинделя
     */
    int GetSpindleSpeed() const;

    /*! \brief Установить технологию записи
     *  \param recordTechnology Строка с описанием технологии записи
     */
    void SetRecordTechnology(const std::string &recordTechnology);

    /*! \brief Получить технологию записи
     *  \return Строка с описанием технологии записи
     */
    std::string GetRecordTechnology() const;

private:
    int memorySize_{0}; /*!< Размер памяти накопителя */
    int spindleSpeed_{0}; /*!< Скорость вращения шпинделя */
    std::string recordTechnology_{""}; /*!< Технология записи*/
};


#endif
