/*! \file lineout.h
 *  \brief Заголовочный файл с описанием класса LineOut
 *  \details Содержит объявление класса LineOut, представляющего разъем
 *           для подключения колонок. Класс предоставляет
 *           интерфейс подключения/отключения Speakers, проверки совместимости
 *           и состояния порта.
 */
#ifndef LINEOUT_PORT
#define LINEOUT_PORT
#include "optional"
#include "port.h"
#include "../Speakers/speakers.h"
#include "port_type.h"

/*! \class LineOut
 *  \brief Класс, моделирующий выход Line Out
 *  \details Наследует Port и реализует поведение порта типа Line Out:
 *           подключение и отключение колонок, проверка совместимости,
 *           состояния занятости и обнаружение подключенных колонок.
 */
class LineOut : public Port{
public:
    /*! \brief Конструктор по умолчанию */
    LineOut();

    /*! \brief Подключить колонки к порту Line Out
     *  \param speakers Ссылка на объект Speakers для подключения
     *  \return true, если подключение выполнено успешно, false в противном случае
     */
    bool ConnectDevice(const Speakers& speakers);

    /*! \brief Отключить устройство от порта
     *  \return true, если отключение выполнено успешно,
     *          false если порт уже был свободен
     */
    bool DisconnectDevice() override;

    /*! \brief Проверить, может ли порт принять данные колонки
     *  \param speakers Ссылка на проверяемый объект Speakers
     *  \return true, если колонки совместимы и могут быть подключены
     */
    bool CanAccept(const Speakers& speakers) const;

    /*! \brief Проверить, занят ли порт
     *  \return true, если порт занят колонками, false если свободен
     */
    bool IsOccupied() const;

    /*! \brief Получить тип порта в виде строки
     *  \return Строковое представление типа порта
     */
    std::string GetType() const override;

    /*! \brief Проверить наличие подключённых колонок
     *  \return true, если колонки обнаружены в порту, false в противном случае
     */
    std::string DetectSpeakers() const;

private:
    PortType type_ {PortType::LineOut};   /*!< Тип порта*/
    std::optional<Speakers> speakers_;    /*!< Подключённые колонки, если есть */
};

#endif