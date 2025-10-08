/*! \file micin.h
 *  \brief Заголовочный файл с описанием класса MicIn
 *  \details Содержит объявление класса MicIn, реализующего входной микрофонный
 *           порт системы. Порт предоставляет интерфейс для подключения и
 *           отключения микрофона, проверки совместимости и состояния занятости.
 */
#ifndef MICIN_PORT
#define MICIN_PORT
#include "optional"
#include "port.h"
#include "../Microphone/microphone.h"
#include "port_type.h"

/*! \class MicIn
 *  \brief Класс, моделирующий микрофонный вход
 *  \details Наследует Port и реализует поведение порта типа MicIn:
 *           подключение/отключение микрофона, проверка совместимости и
 *           состояния занятости, а также обнаружение подключенного микрофона.
 */
class MicIn : public Port {
public:
    /*! \brief Конструктор по умолчанию */
    MicIn();

    /*! \brief Подключить микрофон к порту
     *  \param microphone Ссылка на объект Microphone для подключения
     *  \return true, если подключение выполнено успешно, false в противном случае
     */
    bool ConnectDevice(const Microphone &microphone);

    /*! \brief Отключить устройство от порта
     *  \return true, если отключение выполнено успешно,
     *          false если порт уже был свободен
     */
    bool DisconnectDevice() override;

    /*! \brief Проверить, занят ли порт
     *  \return true если порт занят микрофоном, false если свободен
     */
    bool IsOccupied() const override;

    /*! \brief Проверить, может ли порт принять данный микрофон
     *  \param microphone Ссылка на проверяемый Microphone
     *  \return true, если микрофон совместим и может быть подключен
     *          fasle в противном случае
     */
    bool CanAccept(const Microphone &microphone) const;

    /*! \brief Получить тип порта в виде строки
     *  \return Строковое представление типа порта
     */
    std::string GetType() const override;

    /*! \brief Проверить наличие подключенного микрофона
     *  \return true, если микрофон обнаружен в порту, false в противном случае
     */
    std::string DetectMicriphone() const;

private:
    PortType type_{PortType::MicIn}; /*!< Тип порта*/
    std::optional<Microphone> microphone_; /*!< Подключённый микрофон, если есть */
};

#endif
