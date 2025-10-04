/*! \file computer.h
 *  \brief Заголовочный файл с описанием класса Computer
 *  \details Содержит объявление класса Computer, моделирующего персональный компьютер.
 *           Класс объединяет корпус, монитор, устройства ввода и аудио, а также сетевые адаптеры.
 *           Предназначен для использования в симуляциях сборки системы и тестирования поведения
 *           при включении и выключении.
 */
#ifndef COMPUTER
#define COMPUTER

#include "../Case/case.h"
#include "../Display/display.h"
#include "../Microphone/microphone.h"
#include "../Speakers/speakers.h"
#include "../Adapters/WiFiAdapter/wifi_adapter.h"
#include "../Adapters/BluetoothAdapter/bluetooth_adapter.h"
#include "../KeyBoard/keyboard.h"
#include "../Mouse/mouse.h"

/*! \class Computer
 *  \brief Модель персонального компьютера
 *  \details Computer агрегирует аппаратные компоненты: корпус, внешний дисплей,
 *           микрофон, колонки, сетевые адаптеры и устройства ввода. Класс предоставляет
 *           интерфейс для сборки системы, включения и выключения, позволяя проводить
 *           интеграционные тесты взаимодействия компонентов в составе одного устройства.
 */
class Computer{
public:
    /*! \brief Конструктор по умолчанию
     */
    Computer();

    /*! \brief Конструктор с передачей всех компонентов
     *  \param computerCase_ Ссылка на объект корпуса
     *  \param display_ Ссылка на объект дисплея
     *  \param microphone_ Ссылка на объект микрофона
     *  \param speakers_ Ссылка на объект колонок
     *  \param wifiAdapter_ Ссылка на объект WiFi адаптера
     *  \param bluetoothAdapter_ Ссылка на объект Bluetooth адаптера
     *  \param keyboard_ Ссылка на объект клавиатуры
     *  \param mouse_ Ссылка на объект мыши
     *  \details Конструктор позволяет собрать экземпляр Computer из готовых компонентов,
     *           что удобно для моделирования разных конфигураций и подмены зависимостей в тестах.
     */
    Computer(const Case& computerCase, const Display& display, const Microphone& microphone, const Speakers& speakers,
            const WiFiAdapter& wifiAdapter, const BluetoothAdapter& bluetoothAdapter, const KeyBoard& keyboard, const Mouse& mouse);

    /*! \brief Попытаться собрать компьютер из компонентов
     *  \return true если сборка прошла успешно, false при ошибках конфигурации
     *  \details Метод проверяет совместимость и наличие основных компонентов и возвращает
     *           результат попытки собрать работоспособную систему.
     */
    bool BuildComputer();

    /*! \brief Включить компьютер
     *  \param powerLevel Уровень питания или режим включения
     *  \param bootOption Опция загрузки или приоритет загрузочного устройства
     *  \return Текстовое сообщение с результатом операции включения
     *  \details Метод инициирует последовательность действий по включению системы,
     *           проверяет готовность подсистем и формирует диагностическое сообщение.
     */
    std::string TurnOn(int, int);

    /*! \brief Выключить компьютер
     *  \return Текстовое сообщение с результатом операции выключения
     *  \details Метод корректно завершает работу компонентов, освобождает ресурсы и
     *           возвращает статус операции выключения.
     */
    std::string TurnOff();

private:
    Case case_; /*!< Корпус компьютера */
    Display display_; /*!< Монитор */
    Microphone microphone_; /*!< Подключённый микрофон */
    Speakers speakers_; /*!< Колонки */
    WiFiAdapter wifiAdapter_; /*!< WiFi адаптер для беспроводной сети */
    BluetoothAdapter bluetoothAdapter_; /*!< Bluetooth адаптер */
    KeyBoard keyboard_; /*!< Клавиатура */
    Mouse mouse_; /*!< Мышь */
};

#endif