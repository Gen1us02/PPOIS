/*! \file exceptions.h
 *  \brief Заголовочный файл с классами исключений
 *  \details Содержит классы исключений для обработки различного рода ошибок
 */

#ifndef EXCEPTIONS
#define EXCEPTIONS
#include "string"
#include <exception>

/*! \class Exception
 *  \brief Базовый класс для создания дочерних исключений
 *  \details Класс наследуется от std::exception и предоставляет базовое поведение для всех созданных исключений
 */
class Exception : public std::exception {
public:
    /*! \brief Конструктор с сообщением об ошибке
	*  \param message Текст сообщения об ошибке
	*/
    explicit Exception(const char *message);

    /*! \brief Получение сообщения об ошибку
	*  \return Текст сообщения об ошибке
	*/
    const char *what() const noexcept override;

private:
    std::string message_; /*!< Сообщение об ошибке */
};

/*! \class ExceptionIncorrectInstance
 *  \brief Исключение, связанное с неверной сущностью объекта
 *  \details Выбрасывается, когда в метод класса передана неверная сущность объекта
 */
class ExceptionIncorrectInstance : public Exception {
public:
    explicit ExceptionIncorrectInstance(const char *);
};

/*! \class ExceptionIncorrectSpeed
 *  \brief Исключение, связанное с неверной скорость вентиляторов
 *  \details Выбрасывается, при попытке установить неверную скорость для вентиляторов
 */
class ExceptionIncorrectSpeed : public Exception {
public:
    explicit ExceptionIncorrectSpeed(const char *);
};

/*! \class ExceptionConnection
 *  \brief Исключение, связанное с отсутствием подключения устройства
 *  \details Выбрасывается, если устройство не подключено к компьютеру
 */
class ExceptionConnection : public Exception {
public:
    explicit ExceptionConnection(const char *);
};

/*! \class ExceptionManyKeysPressed
 *  \brief Исключение, связанное нажатием множества клавиш на клавиатуре
 *  \details Выбрасывается, если пользователь нажал больше, чем 1 клавишу
 */
class ExceptionManyKeysPressed : public Exception {
public:
    explicit ExceptionManyKeysPressed(const char *);
};

/*! \class ExceptionRAMStatusError
 *  \brief Исключение, связанное с выключением компьютера и очисткой памяти
 *  \details Выбрасывается, когда компьютер выключается
 */
class ExceptionRAMStatusError : public Exception {
public:
    explicit ExceptionRAMStatusError(const char *);
};

/*! \class ExceptionIncorrectVoltage
 *  \brief Исключение, связанное с напряжением в сети
 *  \details Выбрасывается, когда блок питания подключается к сети с слишком высоким напряжением
 */
class ExceptionIncorrectVoltage : public Exception {
public:
    explicit ExceptionIncorrectVoltage(const char *);
};

/*! \class ExceptionIncorrectDLLSMode
 *  \brief Исключение, связанное с неправильным DLSS режимом
 *  \details Выбрасывается, при попытке установить неправильный DLSS режим
 */
class ExceptionIncorrectDLLSMode : public Exception {
public:
    explicit ExceptionIncorrectDLLSMode(const char *);
};

/*! \class ExceptionIncorrectCoolerCount
 *  \brief Исключение, связанное с неправильным количеством вентиляторов
 *  \details Выбрасывается, при попытке установить неправильное количество вентиляторов
 */
class ExceptionIncorrectCoolerCount : public Exception {
public:
    explicit ExceptionIncorrectCoolerCount(const char *);
};

/*! \class ExceptionIncorrectVolume
 *  \brief Исключение, связанное с неправильным значением звука
 *  \details Выбрасывается, при попытке установить неправильное значение звука
 */
class ExceptionIncorrectVolume : public Exception {
public:
    explicit ExceptionIncorrectVolume(const char *);
};

/*! \class ExceptionIsOccupiedError
 *  \brief Исключение, связанное с занятым портом
 *  \details Выбрасывается, при попытке установить устройство в занятый порт
 */
class ExceptionIsOccupiedError : public Exception {
public:
    explicit ExceptionIsOccupiedError(const char *);
};

/*! \class ExceptionNotIsOccupiedError
 *  \brief Исключение, связанное с извлечением из порта
 *  \details Выбрасывается, при попытке извлечь устройство из свободного порта
 */
class ExceptionNotIsOccupiedError : public Exception {
public:
    explicit ExceptionNotIsOccupiedError(const char *);
};

#endif
