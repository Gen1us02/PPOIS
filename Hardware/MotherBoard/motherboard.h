/*! \file motherboard.h
 *  \brief Заголовочный файл с описанием класса MotherBoard
 *  \details Содержит объявление класса MotherBoard, моделирующего материнскую плату.
 *           Плата управляет установкой процессора, подключением модулей RAM и SSD,
 *           хранит сведения о сокете, типе RAM, количестве слотов и наборе чипсета,
 *           а также предоставляет методы для проверки состояния батареи и совместимости комплектующих.
 */
#ifndef MOTHERBOARD
#define MOTHERBOARD
#include <string>
#include <optional>
#include "vector"
#include "hardware.h"
#include "../CPU/cpu.h"
#include "../SSD/ssd.h"
#include "../RAM/ram.h"
#include "../Ports/PortM2/portm2.h"
#include "motherboard_battery.h"

/*! \class MotherBoard
 *  \brief Класс, моделирующий материнскую плату
 *  \details Наследует Hardware. Предоставляет интерфейс для установки и удаления
 *           процессора, добавления и удаления модулей RAM, установки и удаления SSD,
 *           проверки совместимости CPU и RAM с текущими параметрами платы,
 *           получения характеристик платы и проверки состояния батареи.
 */
class MotherBoard : public Hardware {
public:
    /*! \brief Конструктор по умолчанию */
    MotherBoard();

    /*! \brief Конструктор с инициализацией параметров платы
     *  \param socket Строковое имя сокета процессора
     *  \param battery Объект батареи материнской платы
     *  \param ramCount Максимальное число слотов для RAM модулей
     *  \param ramType Тип поддерживаемой оперативной памяти
     *  \param chipset Название чипсета платы
     */
    MotherBoard(const std::string &socket, const MotherBoardBattery &battery,
                int ramCount, const std::string &ramType, const std::string &chipset);

    /*! \brief Получить название сокета платы
     *  \return Строка с именем сокета
     */
    std::string GetSocket() const;

    /*! \brief Установить процессор в плату
     *  \param processor Объект CPU для установки
     *  \return true если установка прошла успешно, false если несовместимо или уже установлен CPU
     */
    bool InstallCPU(const CPU &processor);

    /*! \brief Удалить установленный процессор
     *  \return true если процессор был установлен и успешно удалён, false если процессора не было
     */
    bool UninstallCPU();

    /*! \brief Добавить модуль RAM в свободный слот
     *  \param slotIndex Индекс слота или желаемая позиция вставки
     *  \param module Объект RAM для добавления
     *  \return true если модуль успешно добавлен, false если нет свободных слотов или несовместим
     */
    bool AddRAM(int slotIndex, const RAM &module);

    /*! \brief Удалить модуль RAM по индексу слота
     *  \param slotIndex Индекс слота для удаления
     *  \return true если модуль удалён, false если слот пуст или индекс некорректен
     */
    bool RemoveRAMByIndex(int slotIndex);

    /*! \brief Установить SSD в соответствующий порт
     *  \param ssd Объект SSD для установки
     *  \return true если SSD успешно установлен, false если порт занят или SSD несовместим
     */
    bool InstallSSD(const SSD &ssd);

    /*! \brief Удалить установленный SSD
     *  \return true если SSD был установлен и успешно удалён, false если SSD отсутствует
     */
    bool UninstallSSD();

    /*! \brief Проверить состояние батареи материнской платы
     *  \return true если батарея в здоровом состоянии, false если требуется замена
     */
    bool IsBatteryHealthy() const;

    /*! \brief Получить текущее количество установленных RAM модулей
     *  \return Количество установленных модулей RAM
     */
    int GetRamCount() const;

    /*! \brief Получить тип поддерживаемой RAM
     *  \return Строка с типом RAM
     */
    std::string GetRamType() const;

    /*! \brief Получить название чипсета платы
     *  \return Строка с именем чипсета
     */
    std::string GetChipset() const;

private:
    /*! \brief Проверить совместимость процессора с платой
     *  \param processor Проверяемый процессор
     *  \return true если CPU совместим с платой, false иначе
     */
    bool IsCPUCompatibility(const CPU &processor) const;

    /*! \brief Проверить совместимость RAM модуля с платой
     *  \param module Проверяемый модуль RAM
     *  \return true если RAM совместима с платой, false иначе
     */
    bool IsRAMCompatibility(const RAM &module) const;

    std::string socket_{""}; /*!< Название сокета процессора */
    std::optional<CPU> processor_; /*!< Установленный процессор, если есть */
    std::vector<std::optional<RAM> > ramModules_; /*!< Слоты RAM */
    std::optional<SSD> ssd_; /*!< Установленный SSD, если есть */
    MotherBoardBattery battery_; /*!< Батарея платы */
    PortM2 ssdPort_; /*!< Порт M.2 для SSD */
    int ramCount_{0}; /*!< Максимальное количество слотов RAM */
    std::string ramType_{""}; /*!< Поддерживаемый тип RAM */
    std::string chipset_{""}; /*!< Название чипсета платы */
};

#endif
