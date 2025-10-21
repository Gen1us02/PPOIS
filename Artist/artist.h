/*! \file artist.h
 *  \brief Заголовочный файл с описанием класса Artist
 *  \details Содержит объявление класса Artist, представляющего музыкального исполнителя.
 *           Класс наследует Human и реализует интерфейс для управления информацией об исполнителе,
 *           его треками, альбомами и статистикой.
 */
#ifndef ARTIST
#define ARTIST
#include <string>
#include <vector>
#include <iostream>
#include <memory>

#include "../Track/track.h"
#include "../BaseClasses/human.h"
#include "../BaseClasses/album.h"
#include "../BaseClasses/album_type.h"

/*! \class Artist
 *  \brief Модель музыкального исполнителя
 *  \details Artist наследуется от Human, расширяя его функциональность для работы
 *           с музыкальной карьерой. Класс предоставляет методы для управления персональной
 *           информацией, треками, альбомами и статистикой популярности исполнителя.
 */
class Artist : public Human
{
public:
    /*! \brief Конструктор по умолчанию
     *  \details Инициализирует исполнителя с пустыми значениями имени и псевдонима,
     *           нулевыми значениями возраста и количества слушателей.
     */
    Artist();

    /*! \brief Конструктор с инициализацией основных параметров
     *  \param name Имя исполнителя
     *  \param age Возраст исполнителя
     *  \param listeners Количество слушателей
     *  \param pseudonym Псевдоним исполнителя
     *  \details Позволяет создать объект исполнителя с заданными основными характеристиками.
     */
    Artist(const std::string& name, int age, int listeners, const std::string& pseudonym);

    /*! \brief Деструктор
     *  \details Обеспечивает корректное уничтожение объекта исполнителя.
     */
    ~Artist();

    /*! \brief Установить имя исполнителя
     *  \param name Новое имя исполнителя
     *  \details Сохраняет имя исполнителя.
     */
    void SetName(const std::string& name) override;

    /*! \brief Получить имя исполнителя
     *  \return Строка с именем исполнителя
     *  \details Возвращает текущее установленное имя исполнителя.
     */
    std::string GetName() const override;

    /*! \brief Установить возраст исполнителя
     *  \param age Новый возраст исполнителя
     *  \details Сохраняет возраст исполнителя.
     */
    void SetAge(int age) override;

    /*! \brief Получить возраст исполнителя
     *  \return Возраст исполнителя
     *  \details Возвращает текущий установленный возраст исполнителя.
     */
    int GetAge() const override;

    /*! \brief Установить количество слушателей
     *  \param listeners Количество слушателей
     *  \details Сохраняет количество слушателей исполнителя.
     */
    void SetListeners(int listeners);

    /*! \brief Получить количество слушателей
     *  \return Количество слушателей
     *  \details Возвращает текущее количество слушателей исполнителя.
     */
    int GetListeners() const;

    /*! \brief Установить псевдоним исполнителя
     *  \param pseudonym Новый псевдоним исполнителя
     *  \details Сохраняет псевдоним исполнителя.
     */
    void SetPseudonym(const std::string& pseudonym);

    /*! \brief Получить псевдоним исполнителя
     *  \return Строка с псевдонимом исполнителя
     *  \details Возвращает текущий установленный псевдоним исполнителя.
     */
    std::string GetPseudonym() const;

    /*! \brief Получить информацию об исполнителе
     *  \return Строка с полной информацией об исполнителе
     *  \details Возвращает форматированную строку, содержащую всю основную информацию
     *           об исполнителе (имя, псевдоним, возраст, количество слушателей).
     */
    std::string GetArtistInfo() const;

    /*! \brief Получить список треков исполнителя
     *  \return Строка с отформатированным списком треков
     *  \details Возвращает строковое представление всех треков исполнителя
     *           с их названиями и характеристиками.
     */
    std::string GetTrackList() const;

    /*! \brief Получить список альбомов исполнителя
     *  \return Строка с отформатированным списком альбомов
     *  \details Возвращает строковое представление всех альбомов исполнителя
     *           с их названиями и типами.
     */
    std::string GetAlbumList() const;

    /*! \brief Выпустить новый трек
     *  \param name Название трека
     *  \param text Текст трека
     *  \param duration Длительность трека в секундах
     *  \param genre Жанр трека
     *  \return Строка с подтверждением выпуска трека
     *  \details Создает и добавляет новый трек в коллекцию исполнителя.
     */
    std::string RealeseTrack(const std::string& name, const std::string& text, int duration, GenreType genre);

    /*! \brief Добавить трек в альбом
     *  \param albumTitle Название альбома
     *  \param trackName Название трека
     *  \details Находит указанный трек и добавляет его в указанный альбом.
     */
    void AddTrackToAlbum(const std::string& albumTitle, const std::string& trackName);

    /*! \brief Выпустить новый альбом
     *  \param type Тип альбома
     *  \param albumTitle Название альбома
     *  \param albumTracks Вектор треков для добавления в альбом
     *  \return Строка с подтверждением выпуска альбома
     *  \details Создает и добавляет новый альбом указанного типа в коллекцию исполнителя.
     */
    std::string RealeseAlbum(AlbumType type, const std::string& albumTitle, const std::vector<Track>& albumTracks);

private:
    std::string name_; /*!< Имя исполнителя */
    int age_{0}; /*!< Возраст исполнителя */
    int listeners_{0}; /*!< Количество слушателей исполнителя */
    std::string pseudonym_; /*!< Псевдоним исполнителя */
    std::vector<Track> tracks_; /*!< Вектор треков исполнителя */
    std::vector<std::shared_ptr<Album>> albums_; /*!< Вектор альбомов исполнителя */
};

#endif
