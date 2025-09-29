/*! \file portm2.h
 *  \brief Заголовочный файл с описанием класса PortM2
 *  \details Содержит объявление класса PortM2, представляющего разъем M.2
 *           для подключения SSD накопителей. Класс предоставляет методы для
 *           подключения/отключения SSD, проверки занятости порта и получения
 *           характеристик подключенного накопителя.
 */
#ifndef PORTM2
#define PORTM2
#include "optional"
#include "port.h"
#include "port_type.h"
#include "ssd.h"

/*! \class PortM2
 *  \brief Класс, моделирующий разъем M.2 для SSD
 *  \details Наследует Port и реализует поведение порта типа M.2: подключение
 *           и отключение SSD, проверка возможности подключения и получение
 *           типа порта и размера подключенного накопителя.
 */
class PortM2 : public Port{
public:
    /*! \brief Конструктор по умолчанию */
    PortM2();

    /*! \brief Подключить SSD к порту M.2
     *  \param ssd Ссылка на SSD для подключения
     *  \return true, если подключение успешно, false в противном случае
     */
    bool ConnectDevice(const SSD& ssd);

    /*! \brief Отключить устройство от порта
     *  \return true, если отключение успешно,
     *          false если порт уже был свободен
     */
    bool DisconnectDevice() override;

    /*! \brief Проверить, занят ли порт
     *  \return true, если порт занят SSD, false если свободен
     */
    bool IsOccupied() const;

    /*! \brief Проверить, может ли порт принять данный SSD
     *  \param ssd Ссылка на проверяемый SSD
     *  \return true, если SSD совместим и может быть подключен
     *          false в противном случае
     */
    bool CanAccept(const SSD& ssd) const;

    /*! \brief Получить тип порта в виде строки
     *  \return Строковое представление типа порта
     */
    std::string GetType() const override;

    /*! \brief Получить размер подключенного SSD
     *  \return Размер подключенного SSD, или 0 если порт не занят
     */
    int GetSSDSize() const;

private:
    PortType type_ {PortType::M2};    /*!< Тип порта*/
    std::optional<SSD> ssd_;          /*!< Подключённый SSD, если есть */
};

#endif