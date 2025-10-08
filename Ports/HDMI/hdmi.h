/*! \file hdmi.h
 *  \brief Заголовочный файл с описанием класса HDMI
 *  \details Содержит объявление класса HDMI, представляющего реализацию
 *           HDMI-порта в системе портов. Класс предоставляет интерфейс для
 *           подключения и отключения произвольных устройств, проверки
 *           совместимости и состояния занятости порта.
 */
#ifndef HDMI_PORT
#define HDMI_PORT

#include "optional"
#include "port.h"
#include "port_type.h"

/*! \class HDMI
 *  \brief Класс, моделирующий HDMI-порт
 *  \details Наследует Port и реализует поведение порта типа HDMI. Подключение
 *           и отключение устройств общего типа Device, проверка совместимости
 *           и состояния занятости.
 */
class HDMI : public Port {
public:
    /*! \brief Конструктор по умолчанию */
    HDMI();

    /*! \brief Подключить устройство к HDMI-порту
     *  \param device Ссылка на устройство для подключения
     *  \return true если подключение успешно, false в противном случае
     */
    bool ConnectDevice(const Device &device);

    /*! \brief Отключить устройство от порта
     *  \return true если отключение успешно,
     *          false если порт уже был свободен
     */
    bool DisconnectDevice() override;

    /*! \brief Проверить, занят ли порт
     *  \return true если порт занят устройством, false если свободен
     */
    bool IsOccupied() const override;

    /*! \brief Проверить, может ли порт принять устройство
     *  \param device Ссылка на проверяемое устройство
     *  \return true если устройство совместимо с HDMI-портом и может быть подключено
     */
    bool CanAccept(const Device &device) const;

    /*! \brief Получить тип порта в виде строки
     *  \return Строковое представление типа порта
     */
    std::string GetType() const override;

private:
    PortType type_{PortType::HDMI}; /*!< Тип порта */
    std::optional<Device> device_; /*!< Подключённое устройство, если есть */
};

#endif
