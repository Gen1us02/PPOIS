/*! \file display.h
 *  \brief Заголовочный файл с описанием класса Display
 *  \details Содержит объявление класса Display, моделирующего внешний дисплей.
 *           Класс предоставляет настройки разрешения, частоты обновления и диагонали,
 *           умеет принимать видеопоток от подключённых устройств ввода и взаимодействовать
 *           с веб-камерой. Также реализует проверку поддержки типа порта.
 */
#ifndef DISPLAY
#define DISPLAY
#include "output_device.h"
#include "../Mouse/mouse.h"
#include "../KeyBoard/keyboard.h"
#include "../Camera/webcamera.h"
#include "port_type.h"
#include <string>

/*! \class Display
 *  \brief Модель внешнего дисплея (монитора)
 *  \details Display наследует OutputDevice и представляет собой модель монитора
 *           в аппаратной системе. Класс хранит параметры экрана, встроенную веб-камеру
 *           и информацию о поддерживаемом порте. Предназначен для использования в
 *           симуляциях и тестах взаимодействия устройств вывода и ввода.
 */
class Display : public OutputDevice {
public:
    /*! \brief Конструктор по умолчанию
     */
    Display();

    /*! \brief Конструктор с инициализацией основных параметров дисплея
     *  \param maxCamResolution Максимальное разрешение камеры монитора
     *  \param megapixels Количество мегапикселей камеры
     *  \param max_fps Максимальнальное значение частоты кадров камеры
     *  \param resolution Разрешение экрана
     *  \param refreshRate Частота обновления экрана
     *  \param diagonal Диагональ экрана в дюймах
     *  \details Конструктор позволяет задать ключевые характеристики дисплея.
     *           Реализация должна проверять корректность значений
     */
    Display(const std::string &maxCamResolution, double megapixels, int max_fps, const std::string &resolution,
            int refreshRate, int diagonal);

    /*! \brief Установить строковое разрешение экрана
     *  \param resolution Строка вида "widthxheight"
     *  \details Метод обновляет internal resolution_. Реализация может валидировать формат строки.
     */
    void SetResolution(const std::string &resolution);

    /*! \brief Получить строковое представление разрешения экрана
     *  \return Строка разрешения
     */
    std::string GetResolution() const;

    /*! \brief Установить частоту обновления экрана
     *  \param rate Частота в герцах
     */
    void SetRefreshRate(int refreshRate);

    /*! \brief Получить текущую частоту обновления экрана
     *  \return Частота в герцах
     */
    int GetRefreshRate() const;

    /*! \brief Установить диагональ экрана
     *  \param diagonal Диагональ в дюймах
     *  \details Значение должно быть положительным целым числом.
     */
    void SetDiagonal(int diagonal);

    /*! \brief Получить диагональ экрана
     *  \return Диагональ в дюймах
     */
    int GetDiagonal() const;

    /*! \brief Проверить, поддерживает ли дисплей данный тип порта
     *  \param p Тип порта для проверки
     *  \return true если порт поддерживается, false в противном случае
     */
    bool SupportsPort(PortType p) const override;

    /*! \brief Обработать ввод от устройства ввода и вернуть текстовое представление события
     *  \param inputDevice Ссылка на устройство ввода
     *  \return Текстовое описание получённого ввода
    */
    std::string DisplayInput(const InputDevice &inputDevice) const override;

    /*! \brief Получить текстовое представление видеопотока от встроенной веб-камеры
     *  \param seconds Продолжительность захвата в секундах
     *  \return Строковое представление видеопотока или статусное сообщение
     */
    std::string WebCameraVideo(int seconds);

    /*! \brief Получить текстовое описание текущих настроек дисплея
     *  \return Строка с разрешением, частотой обновления, диагональю и поддерживаемым портом
     */
    std::string DisplaySettings() const;

    /*! \brief Подключить камеру */
    void ConnectCamera();

    /*! \brief Отключить камеру*/
    void DisconnectCamera();

    /*! \brief Подключить камеру
     * return true если камера подключена, false иначе
     */
    bool IsCameraConnected() const;

private:
    WebCamera webcamera_; /*!< Встроенная веб-камера */
    std::string resolution_{""}; /*!< Разрешение монитора */
    int refreshRate_{0}; /*!< Частота обновления экрана */
    int diagonal_{0}; /*!< Диагональ экрана */
    PortType portHDMI_{PortType::HDMI}; /*!< Дополнительный порт поддержки */
};

#endif
