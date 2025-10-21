/*! \file artist_info_button.h
 *  \brief Заголовочный файл с описанием класса ArtistInfoButton
 *  \details Содержит объявление класса ArtistInfoButton, представляющего кнопку
 *           для отображения информации об исполнителе. Класс наследует Button
 *           и реализует интерфейс для управления размерами кнопки и получения
 *           информации об исполнителе.
 */
#ifndef ARTIST_INFO_BUTTON
#define ARTIST_INFO_BUTTON
#include "button.h"
#include "../Artist/artist.h"
#include <string>

/*! \class ArtistInfoButton
 *  \brief Модель кнопки для отображения информации об исполнителе
 *  \details ArtistInfoButton наследуется от Button и предоставляет методы для управления
 *           размерами кнопки и получения форматированной информации об исполнителе.
 *           Используется в пользовательском интерфейсе для отображения данных об артистах.
 */
class ArtistInfoButton : public Button
{
public:
    /*! \brief Конструктор по умолчанию
     *  \details Инициализирует кнопку с нулевыми значениями ширины и высоты.
     */
    ArtistInfoButton();

    /*! \brief Деструктор
     *  \details Обеспечивает корректное уничтожение объекта кнопки.
     */
    ~ArtistInfoButton();

    /*! \brief Конструктор с инициализацией размеров
     *  \param width Ширина кнопки
     *  \param height Высота кнопки
     *  \details Позволяет создать кнопку с заданными размерами.
     */
    ArtistInfoButton(int width, int height);

    /*! \brief Установить ширину кнопки
     *  \param width Новая ширина кнопки
     *  \details Устанавливает ширину визуального представления кнопки.
     */
    void SetWidth(int width) override;

    /*! \brief Получить ширину кнопки
     *  \return Ширина кнопки
     *  \details Возвращает текущую установленную ширину кнопки.
     */
    int GetWidth() const override;

    /*! \brief Установить высоту кнопки
     *  \param height Новая высота кнопки
     *  \details Устанавливает высоту визуального представления кнопки.
     */
    void SetHeight(int height) override;

    /*! \brief Получить высоту кнопки
     *  \return Высота кнопки
     *  \details Возвращает текущую установленную высоту кнопки.
     */
    int GetHeight() const override;

    /*! \brief Получить информацию об исполнителе
     *  \param artist Ссылка на объект исполнителя
     *  \return Строка с форматированной информацией об исполнителе
     *  \details Возвращает подробную информацию об указанном исполнителе
     *           в удобочитаемом строковом формате.
     */
    std::string GetArtistInfo(const Artist& artist) const;

private:
    int width_{0}; /*!< Ширина кнопки */
    int height_{0}; /*!< Высота кнопки */
};

#endif
