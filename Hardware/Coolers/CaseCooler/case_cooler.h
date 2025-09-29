/*! \file case_cooler.h
 *  \brief Заголовочный файл с описанием класса CaseCooler
 *  \details Содержит объявление класса CaseCooler, представляющего корпусный кулер.
 *           Класс наследует Cooler и Hardware и предоставляет методы для управления
 *           минимальной и максимальной скоростью, направлением потока и получения типа кулера.
 */
#ifndef CASECOOLER
#define CASECOOLER
#include "cooler.h"
#include "hardware.h"

/*! \class CaseCooler
 *  \brief Класс, моделирующий кулер корпуса
 *  \details Наследует Cooler и Hardware. Хранит минимальную и максимальную
 *           скорости, направление воздуха и возвращает тип кулера как "case".
 */
class CaseCooler:public Cooler, public Hardware{
public:
    /*! \brief Конструктор по умолчанию */
    CaseCooler();

    /*! \brief Конструктор с инициализацией параметров
     *  \param minSpeed Минимальная скорость кулера
     *  \param maxSpeed Максимальная скорость кулера
     *  \param direction Направление потока воздуха
     */
    CaseCooler(int, int, const std::string&);

    /*! \brief Установить минимальную скорость кулера
     *  \param minSpeed Новая минимальная скорость
     */
    void SetMinSpeed(int minSpeed) override;

    /*! \brief Получить минимальную скорость кулера
     *  \return Минимальная скорость
     */
    int GetMinSpeed() const override;

    /*! \brief Установить максимальную скорость кулера
     *  \param maxSpeed Новая максимальная скорость
     */
    void SetMaxSpeed(int maxSpeed) override;

    /*! \brief Получить максимальную скорость кулера
     *  \return Максимальная скорость
     */
    int GetMaxSpeed() const override;

    /*! \brief Установить направление потока воздуха
     *  \param direction Строка с направлением
     */
    void SetDirection(const std::string& direction);

    /*! \brief Получить направление потока воздуха
     *  \return Текущий режим направления
     */
    std::string GetDirection() const;

    /*! \brief Получить тип кулера в виде строки
     *  \return Строковое представление типа кулера
     */
    std::string GetType() const override;

    /*! \brief Установить текущую скорость работы вентилятора и вернуть текстовый статус
    *  \param speed Желаемая скорость в об/мин
    *  \return Строка с указанием установленной скорости или сообщение об ошибке
    */
    std::string SetCurrentSpeed(int speed) const override;
private:
    int minSpeed_ {0};   /*!< Минимальная скорость кулера */
    int maxSpeed_ {0};   /*!< Максимальная скорость кулера */
    std::string type_ {"case"}; /*!< Тип кулера */
    std::string direction_ {""}; /*!< Направление потока воздуха */
};

#endif