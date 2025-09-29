/*! \file microphone.h
 *  \brief Заголовочный файл с описанием класса Microphone
 *  \details Содержит объявление класса Microphone, представляющего устройство
 *           ввода звука. Класс предоставляет методы для управления
 *           типом микрофона, его характеристиками и для чтения аудиосигнала.
 */
#ifndef MICROPHONE
#define MICROPHONE
#include "input_device.h"
/*! \class Microphone
 *  \brief Класс, моделирующий микрофон
 *  \details Наследуется от InputDevice и реализует поведение типичного микрофона:
 *           хранит тип, максимальную частоту записи, отношение сигнал/шум,
 *           состояние заглушения и предоставляет методы управления и чтения звука.
 */
class Microphone: public InputDevice{
public:
    /*! \brief Конструктор по умолчанию */
    Microphone();

    /*! \brief Конструктор с инициализацией параметров
     *  \param type Тип микрофона
     *  \param maxFrequency Максимальная частота, поддерживаемая микрофоном (в Гц)
     *  \param signalNoiseRatio Отношение сигнал/шум (в дБ)
     */
    Microphone(const std::string& type, int maxFrequency, int signalNoiseRatio);

    /*! \brief Установить тип микрофона
     *  \param type Строка, описывающая тип микрофона
     */
    void SetType(const std::string& type);

    /*! \brief Получить тип микрофона
     *  \return Строка с типом микрофона
     */
    std::string GetType() const;

    /*! \brief Установить максимальную частоту записи
     *  \param signalNoiseRatio Частота в герцах
     */
    void SetMaxFrequency(int signalNoiseRatio);

    /*! \brief Получить максимальную частоту записи
     *  \return Максимальная частота в герцах
     */
    int GetMaxFrequency() const;

    /*! \brief Установить отношение сигнал/шум
     *  \param signalNoiseRatio Отношение сигнал/шум в дБ
     */
    void SetSignalNoiseRatio(int signalNoiseRatio);

    /*! \brief Получить отношение сигнал/шум
     *  \return Отношение сигнал/шум в дБ
     */
    int GetSignalNoiseRatio() const;

    /*! \brief Заглушить микрофон
     *  \return Текстовое сообщение о результате операции
     */
    std::string Mute();

    /*! \brief Включить звук микрофона
     *  \return Текстовое сообщение о результате операции
     */
    std::string Unmute();

    /*! \brief Проверить, заглушён ли микрофон
     *  \return true если микрофон заглушён, false в противном случае
     */
    bool IsMuted() const;

    /*! \brief Считать аудиосигнал с микрофона
     *  \return Строковое представление считанного звука
     */
    std::string ReadSound();

private:
    std::string type_ {""};         /*!< Тип микрофона */
    int maxFrequency_ {0};          /*!< Максимальная частота в герцах */
    int signalNoiseRatio_ {0};      /*!< Отношение сигнал/шум в дБ */
    bool isMute_ {false};           /*!< Флаг заглушения микрофона */
};

#endif