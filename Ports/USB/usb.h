/*! \file usb.h
 *  \brief Заголовочный файл с описанием класса USB
 *  \details Содержит объявление класса USB, представляющего реализацию
 *           порта USB в системе портов. Класс предоставляет интерфейс подключения
 *           и отключения устройств, проверки занятости порта и получения типа порта.
 */
#ifndef USB_PORT
#define USB_PORT
#include "optional"
#include "port.h"
#include "port_type.h"

/*! \class USB
 *  \brief Класс, моделирующий USB порт
 *  \details Наследует Port и реализует поведение порта USB. Подключение и
 *           отключение устройств, проверка возможности подключения и состояние занятости.
 */
class USB : public Port{
public:
    /*! \brief Конструктор по умолчанию */
    USB();

    /*! \brief Подключить устройство к порту
     *  \param device Ссылка на устройство для подключения
     *  \return true, если подключение успешно, false в противном случае
     */
    bool ConnectDevice(const Device& device) override;

    /*! \brief Отключить устройство от порта
     *  \return true, если отключение успешно,
     *          false если порт уже был свободен
     */
    bool DisconnectDevice() override;

    /*! \brief Проверить, занят ли порт
     *  \return true, если порт занят устройством, false если свободен
     */
    bool IsOccupied() const;

    /*! \brief Проверить, может ли порт принять устройство
     *  \param device Ссылка на проверяемое устройство
     *  \return true, если устройство совместимо с портом и может быть подключено
     */
    bool CanAccept(const Device& device) const override;

    /*! \brief Получить тип порта в виде строки
     *  \return Строковое представление типа порта
     */
    std::string GetType() const override;

private:
    PortType type_ {PortType::USB};        /*!< Тип порта*/
    std::optional<Device> device_;         /*!< Подключённое устройство, если есть */
};

#endif
