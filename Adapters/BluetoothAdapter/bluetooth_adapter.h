/*! \file bluetooth_adapter.h
 *  \brief Заголовочный файл с описанием класса BluetoothAdapter
 *  \details Содержит объявление класса BluetoothAdapter, моделирующего Bluetooth-адаптер.
 *           Класс наследует Adapter и реализует интерфейс для настройки строки подключения,
 *           скорости передачи, радиуса покрытия и управления состоянием Bluetooth-соединения.
 */
#ifndef BLUETOOTH_ADAPTER
#define BLUETOOTH_ADAPTER
#include "adapter.h"

/*! \class BluetoothAdapter
 *  \brief Модель Bluetooth адаптера
 *  \details BluetoothAdapter реализует контракт Adapter, предоставляя методы для установки
 *           и получения строки интерфейса подключения, скорости передачи данных и радиуса покрытия.
 *           Класс также содержит методы управления состоянием соединения Bluetooth и проверки
 *           текущего состояния подключения.
 */
class BluetoothAdapter : public Adapter {
public:
    /*! \brief Конструктор по умолчанию
     *  \details Инициализирует адаптер со значениями по умолчанию.
     */
    BluetoothAdapter();

    /*! \brief Конструктор с инициализацией параметров адаптера
     *  \param connectionInterface Строка интерфейса подключения
     *  \param speed Рабочая скорость адаптера Мбит/с
     *  \param coverageRadius Радиус покрытия в метрах
     *  \details Позволяет задать ключевые характеристики адаптера при создании объекта.
     */
    BluetoothAdapter(const std::string &connectionInterface, int speed, int coverageRadius);

    /*! \brief Установить интерфейс подключения
     *  \param connectionInterface Строковое описание интерфейса подключения
     *  \details Сохраняет описание интерфейса (например стандарта Bluetooth).
     */
    void SetConnectionInterface(const std::string &connectionInterface) override;

    /*! \brief Получить интерфейс подключения
     *  \return Строка с описанием интерфейса подключения
     *  \details Возвращает ранее установленную строку интерфейса.
     */
    std::string GetConnectionInterface() const override;

    /*! \brief Установить рабочую скорость адаптера
     *  \param speed Скорость передачи данных
     *  \details Сохраняет значение скорости для последующего использования.
     */
    void SetSpeed(int speed) override;

    /*! \brief Получить текущую рабочую скорость адаптера
     *  \return Значение скорости
     */
    int GetSpeed() const override;

    /*! \brief Установить радиус покрытия Bluetooth
     *  \param coverageRadius Радиус покрытия в метрах
     *  \details Используется для моделирования зоны действия беспроводного сигнала.
     */
    void SetCoverageRadius(int coverageRadius);

    /*! \brief Получить радиус покрытия Bluetooth
     *  \return Радиус покрытия в тех же единицах, что и в SetCoverageRadius
     */
    int GetCoverageRadius() const;

    /*! \brief Установить соединение Bluetooth
     *  \details Меняет внутренний флаг состояния на подключён и может инициировать
     *           процедуры аутентификации в реальных реализациях.
     */
    void ConnectBluetooth();

    /*! \brief Отключить соединение Bluetooth
     *  \details Меняет внутренний флаг состояния на отключён и выполняет необходимые шаги
     *           для корректного завершения сессии в реальных реализациях.
     */
    void DisconnectBluetooth();

    /*! \brief Проверить состояние подключения Bluetooth
     *  \return true если адаптер подключён, false в противном случае
     */
    bool IsConnectBluetooth() const;

private:
    std::string connectionInterface_{""}; /*!< Описание интерфейса подключения */
    int speed_{0}; /*!< Рабочая скорость адаптера */
    int coverageRadius_{0}; /*!< Радиус покрытия в метрах */
    bool isConnectBluetooth_{false}; /*!< Флаг состояния Bluetooth-соединения */
};

#endif
