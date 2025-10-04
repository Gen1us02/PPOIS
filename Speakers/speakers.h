/*! \file speakers.h
 *  \brief Заголовочный файл с описанием класса Speakers
 *  \details Содержит объявление класса Speakers, представляющего
 *           колонки как конкретную реализацию интерфейса OutputDevice. Класс
 *           предоставляет методы для управления характеристиками динамиков и
 *           отображения входного аудиосигнала от микрофона.
 */
#ifndef SPEAKERS
#define SPEAKERS
#include <iostream>
#include <string>
#include "output_device.h"
#include "../Microphone/microphone.h"
#include "port_type.h"

/*! \class Speakers
 *  \brief Класс, моделирующий колонки
 *  \details Наследует OutputDevice и реализует интерфейс вывода звука.
 *           Класс предоставляет возможности управления физическими
 *           характеристиками акустики, изменения громкости и отображения
 *           входного аудиосигнала от устройств ввода.
 */
class Speakers : public OutputDevice{
    public:
    /*! \brief Конструктор по умолчанию */
    Speakers();

    /*! \brief Конструктор с инициализацией параметров
     *  \param dynamicCount Количество динамиков в акустической системе
     *  \param power Мощность акустической системы (в ваттах)
     *  \param weight Вес акустической системы (в килограммах)
     *  \param maxRate Максимальная воспроизводимая частота (в герцах)
     */
    Speakers(int dynamicCount, int power, double weight, int maxRate);

    /*! \brief Установить количество динамиков
     *  \param dynamicCount Новое количество динамиков
     */
    void SetDynamicCount(int dynamicCount);

    /*! \brief Получить текущее количество динамиков
     *  \return Количество динамиков
     */
    int GetDynamicCount() const;

    /*! \brief Установить мощность колонок
     *  \param power Новая мощность в ваттах
     */
    void SetPower(int power);

    /*! \brief Получить мощность колонок
     *  \return Мощность в ваттах
     */
    int GetPower() const;

    /*! \brief Установить вес колонок
     *  \param weight Вес в килограммах
     */
    void SetWeight(double);

    /*! \brief Получить вес колонок
     *  \return Вес в килограммах
     */
    double GetWeight() const;

    /*! \brief Установить максимальную воспроизводимую частоту
     *  \param maxRate Частота в герцах
     */
    void SetMaxRate(int maxRate);

    /*! \brief Получить максимальную воспроизводимую частоту
     *  \return Частота в герцах
     */
    int GetMaxRate() const;

    /*! \brief Отобразить входной аудиосигнал от устройства ввода
     *  \details Принимает ссылку на InputDevice.
     *           Ожидается, что вызывающий код обеспечит корректность типа
     *           устройства или будет использовать полиморфный интерфейс.
     *  \param microphone Объект устройства ввода
     *  \return Строковое представление входного аудиосигнала
     */
    std::string DisplayInput(const InputDevice& microphone) const override;

    /*! \brief Изменить громкость
     *  \details Если значение volumeValue выходит за допустимый диапазон,
     *           реализация может выбросить соответствующее исключение.
     *  \param volumeValue Значение громкости
     *  \return Сообщение о результате операции либо текст ошибки
     */
    std::string ChangeVolume(int volumeValue) const;
private:
    int dynamicCount_ {0};
    int power_ {0};
    double weight_ {0.0};
    int maxRate_ {0};
};

#endif