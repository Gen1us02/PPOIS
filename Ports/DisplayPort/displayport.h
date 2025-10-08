/*! \file displayport.h
 *  \brief Заголовочный файл с описанием класса DisplayPort
 *  \details Содержит объявление класса DisplayPort, представляющего разъем
 *           DisplayPort для подключения дисплеев. Класс предоставляет интерфейс
 *           для подключения/отключения дисплея, проверки совместимости и состояния порта.
 */
#ifndef DISPLAY_PORT
#define DISPLAY_PORT
#include "optional"
#include "port.h"
#include "../Display/display.h"
#include "port_type.h"

/*! \class DisplayPort
 *  \brief Класс, моделирующий порт DisplayPort
 *  \details Наследует Port и реализует поведение порта типа DisplayPort:
 *           подключение и отключение дисплеев, проверка совместимости устройства
 *           и состояния занятости порта, а также получение строкового представления типа.
 */
class DisplayPort : public Port {
public:
    /*! \brief Конструктор по умолчанию */
    DisplayPort();

    /*! \brief Подключить дисплей к порту DisplayPort
     *  \param display Ссылка на объект Display для подключения
     *  \return true, если подключение выполнено успешно, false в противном случае
     */
    bool ConnectDevice(const Display &display);

    /*! \brief Отключить устройство от порта
     *  \return true, если отключение выполнено успешно,
     *          false если порт уже был свободен
     */
    bool DisconnectDevice() override;

    /*! \brief Проверить, занят ли порт
     *  \return true, если порт занят дисплеем, false если свободен
     */
    bool IsOccupied() const override;

    /*! \brief Проверить, может ли порт принять данный дисплей
     *  \param display Ссылка на проверяемый Display
     *  \return true, если дисплей совместим и может быть подключен
     */
    bool CanAccept(const Display &display) const;

    /*! \brief Получить тип порта в виде строки
     *  \return Строковое представление типа порта
     */
    std::string GetType() const override;

private:
    PortType type_{PortType::DisplayPort}; /*!< Тип порта */
    std::optional<Display> display_; /*!< Подключённый дисплей, если есть */
};

#endif
