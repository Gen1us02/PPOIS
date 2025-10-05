/*! \file case.h
 *  \brief Заголовочный файл с описанием класса Case
 *  \details Содержит объявление класса Case, моделирующего корпус компьютера.
 *           Класс управляет внутренними вентиляторами, портами ввода-вывода,
 *           слотами для периферии и связанными компонентами: материнской платой,
 *           блоком питания, видеокартой и охладителями. Предназначен для использования
 *           в симуляциях сборки и тестирования совместимости компонентов.
 */
#ifndef CASE
#define CASE

#include <vector>
#include "../Hardware/Coolers/CaseCooler/case_cooler.h"
#include "../Ports/DisplayPort/displayport.h"
#include "../Ports/HDMI/hdmi.h"
#include "../Ports/LineOut/lineout.h"
#include "../Ports/MicIn/micin.h"
#include "../Ports/USB/usb.h"
#include "../Hardware/MotherBoard/motherboard.h"
#include "../Hardware/PowerSupply/power_supply.h"
#include "../Hardware/Coolers/CPUCooler/cpu_cooler.h"
#include "../Hardware/GPU/gpu.h"

/*! \class Case
 *  \brief Модель корпуса системного блока
 *  \details Case представляет корпус компьютера с набором внутренних и внешних
 *           интерфейсов. Класс хранит коллекции вентиляторов и USB-портов, а также
 *           объекты портов отображения, аудиоразъёмов, материнской платы, блока питания,
 *           процессорного охладителя и видеокарты. Предназначен для управления установкой
 *           и удалением устройств, регулировкой скоростей вентиляторов и проверки
 *           параметров питания.
 */
class Case{
public:
    /*! \brief Конструктор по умолчанию
     *  \details Инициализирует корпус со значениями по умолчанию для всех компонентов.
     */
    Case();

    /*! \brief Конструктор с инициализацией параметров корпуса
     *  \param coolersCount Количество установленных корпусных вентиляторов
     *  \param usbPortsCount Количество USB портов
     *  \param usbPort Объект USB порта для инициализации
     *  \param coolers Вектор объекторов CaseCooler для установки
     *  \param motherBoard Ссылка на объект материнской платы
     *  \param gpu Ссылка на объект видеокарты
     *  \param powerSupply Ссылка на объект блока питания
     *  \param cpuCooler Ссылка на объект процессорного охладителя
     *  \details Конструктор позволяет создать корпус с заранее заданным набором
     *           вентиляторов, портов и ключевых компонентов для моделирования
     *           реальной конфигурации системы.
     */
    Case(int usbPortsCount, const USB& usbPort, const std::vector<CaseCooler>& coolers,
        const MotherBoard& motherBoard, const GPU& gpu, const PowerSupply&powerSupply, const CPUCooler& cpuCooler);

    /*! \brief Получить количество корпусных вентиляторов
     *  \return Число вентиляторов в корпусе
     */
    int GetCoolerCount() const;

    /*! \brief Получить количество USB портов
     *  \return Число USB портов
     */
    int GetUSBPortsCount() const;

    /*! \brief Установить USB-устройство в один из портов корпуса
     *  \param device Ссылка на устанавливаемое устройство
     *  \return true если установка успешна, false если нет доступных портов
     *  \details Метод пытается подключить переданное устройство к свободному USB-порту.
     */
    bool InstallUSBDevice(const Device& device);

    bool UninstallUSBDeviceByIndex(int portIndex);

    /*! \brief Подключить внешний дисплей к указанному типу порта
     *  \param display Ссылка на объект дисплея
     *  \param port Тип порта
     *  \return true при успешном подключении, false иначе
     *  \details Метод проверяет совместимость порта и при возможности устанавливает дисплей.
     */
    bool InstallDisplay(const Display& display, PortType port);

    /*! \brief Отключить внешний дисплей
     *  \return true если дисплей был успешно удалён, false если дисплея нет
     *  \details Корректно освобождает занятый порт отображения и обновляет состояние корпуса.
     */
    bool UninstallDisplay();

    /*! \brief Установить колонки в разъём LineOut корпуса
     *  \param speakers Ссылка на объект колонок
     *  \return true при успешной установке, false иначе
     *  \details Метод подключает аудиоустройство к разъёму LineOut и проверяет работоспособность.
     */
    bool InstallSpeakers(const Speakers& speakers);

    /*! \brief Установить скорость всех кулеров видеокарты
     *  \param speed Новый уровень скорости (условная шкала)
     *  \details Метод распространяет заданную скорость на все вентиляторы, связанные с GPU.
     */

    /*! \brief Установить скорость всех кулеров видеокарты
    *  \param speed Новая скорость
    *  \return Строка с результатом операции
    *  \details Метод распространяет заданную скорость на все вентиляторы, связанные с GPU.
    *           Возвращаемая строка содержит информацию о проделанных изменениях
    *           и может содержать предупреждения при недопустимых значениях speed.
    */
    std::string SetGpuCoolersSpeed(int speed) const;

    /*! \brief Установить скорость всех кулеров корпуса
    *  \param speed Новая скорость
    *  \return Строка с результатом операции
    *  \details Метод распространяет заданную скорость на все вентиляторы, связанные с корпусом.
    *           Возвращаемая строка содержит информацию о проделанных изменениях
    *           и может содержать предупреждения при недопустимых значениях speed.
    */
    std::string SetCaseCoolersSpeed(int speed) const;

    /*! \brief Установить скорость кулера блока питания
    *  \param speed Новая скорость
    *  \return Строка с результатом операции
    *  \details Метод распространяет заданную скорость на вентилятор блока питания.
    *           Возвращаемая строка содержит информацию о проделанных изменениях
    *           и может содержать предупреждения при недопустимых значениях speed.
    */
    std::string SetPowerSupplyCoolerSpeed(int speed) const;

    /*! \brief Установить скорость кулера процессора
    *  \param speed Новая скорость
    *  \return Строка с результатом операции
    *  \details Метод распространяет заданную скорость на кулер процессора.
    *           Возвращаемая строка содержит информацию о проделанных изменениях
    *           и может содержать предупреждения при недопустимых значениях speed.
    */
    std::string SetCpuCoolerSpeed(int speed) const;

    /*! \brief Получить строковое представление выходного напряжения блока питания
     *  \param voltage Напряжение сети
     *  \return Строка с информацией о выходном напряжении
     *  \details Метод возвращает измеренное или конфигурированное напряжение блока питания
     *           для указанной линии в человекочитаемом виде.
     */
    std::string GetPowerSupplyVoltage(int voltage) const;

    /*! \brief Отключить колонки от корпуса
     *  \return true если колонки успешно удалены, false если их не было
     */
    bool UninstallSpeakers();

    /*! \brief Установить микрофон в разъём корпуса
     *  \param microphone Ссылка на объект микрофона
     *  \return true при успешной установке, false иначе
     *  \details Метод подключает микрофон к входу MicIn и проверяет наличие сигнала.
     */
    bool InstallMicrophone(const Microphone& microphohne);

    /*! \brief Отключить микрофон от корпуса
     *  \return true если микрофон успешно удалён, false если его не было
     */
    bool UninstallMicrophone();

private:
    std::vector<CaseCooler> coolers_; /*!< Вектор корпусных вентиляторов */
    int coolersCount_ {0}; /*!< Фиксированное число вентиляторов */
    CPUCooler cpuCooler_; /*!< Охладитель процессора */
    DisplayPort displayPort_; /*!< Встроенный DisplayPort разъём */
    HDMI hdmiPort_; /*!< Встроенный HDMI разъём */
    LineOut lineoutPort_; /*!< Аудио LineOut разъём */
    MicIn micinPort_; /*!< Вход MicIn для микрофона */
    std::vector<USB> usbPorts_; /*!< Коллекция USB портов корпуса */
    MotherBoard motherBoard_; /*!< Материнская плата, установленная в корпусе */
    GPU gpu_; /*!< Видеокарта, установленная в корпусе */
    PowerSupply powerSupply_; /*!< Блок питания корпуса */
    int usbPortsCount_ {0}; /*!< Фиксированное число USB портов */
};

#endif