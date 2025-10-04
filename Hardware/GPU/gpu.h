/*! \file gpu.h
 *  \brief Заголовочный файл с описанием класса GPU
 *  \details Содержит объявление класса GPU, моделирующего видеокарту.
 *           Класс управляет поддержкой RTX, объёмом видеопамяти, количеством
 *           и скоростью кулеров, а также предоставляет методы управления
 *           вертикальной синхронизацией и режимом DLSS.
 */

#ifndef GPUDEVICE
#define GPUDEVICE
#include <string>
#include <vector>
#include <algorithm>
#include "hardware.h"
#include "../Coolers/GPUCooler/gpu_cooler.h"

/*! \class GPU
 *  \brief Класс, моделирующий видеокарту
 *  \details Наследует Hardware. Хранит параметры видеокарты: поддержка RTX,
 *           объём видеопамяти, число кулеров и список объектов GPUCooler.
 *           Предоставляет методы для настройки этих параметров и управления
 *           режимами отображения и апскейлинга.
 */
class GPU: public Hardware{
public:
    /*! \brief Конструктор по умолчанию */
    GPU();

    /*! \brief Конструктор с инициализацией параметров
     *  \param minSpeed Минимальная скорость вентиляторов
     *  \param maxSpeed Максимальная скорость вентиляторов
     *  \param rtxSupport Флаг поддержки RTX
     *  \param videoMemory Количество видеопамяти
     *  \param coolersCount Количество вентиляторов
     */
    GPU(int minSpeed, int maxSpeed, bool rtxSupport, int videoMemory, int coolersCount);

    /*! \brief Включить или отключить поддержку RTX
     *  \param rtxSupport true для включения поддержки RTX, false для отключения
     */
    void SetRtxSupport(bool rtxSupport);

    /*! \brief Проверить, поддерживается ли RTX
     *  \return true если RTX поддерживается, false в противном случае
     */
    bool GetRtxSupport() const;

    /*! \brief Установить объём видеопамяти
     *  \param videoMemory Новый объём видеопамяти
     */
    void SetVideoMemory(int videoMemory);

    /*! \brief Получить объём видеопамяти
     *  \return Текущий объём видеопамяти
     */
    int GetVideoMemory() const;

    /*! \brief Получить текущее количество кулеров
     *  \return Количество кулеров
     */
    int GetCoolerCount() const;

    /*! \brief Установить текущую скорость всех кулеров
     *  \param speed Новая скорость кулеров
     */
    std::string SetCoolerCurrentSpeed(int speed);

    /*! \brief Включить или отключить Vsync
     *  \param mode true для включения Vsync, false для отключения
     *  \return Текстовое сообщение о результате операции
     */
    std::string SetVsync(bool mode) const;

    /*! \brief Установить режим DLSS
     *  \param dlssMode Строка с названием режима DLSS
     *  \return Текстовое сообщение о результате операции или описание ошибки
     */
    std::string SetDlssMode(const std::string& dlssMode) const;

private:
    bool rtxSupport_ {false};           /*!< Флаг поддержки RTX */
    int videoMemory_ {0};               /*!< Объём видеопамяти */
    int coolerCount_ {0};         /*!< Количество кулеров */
    std::vector<GPUCooler> coolers_;    /*!< Список объектов кулеров видеокарты */
};

#endif