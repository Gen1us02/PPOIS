/*! \file compilation_album.h
 *  \brief Заголовочный файл с описанием класса CompilationAlbum
 *  \details Содержит объявление класса CompilationAlbum, представляющего сборник.
 *           Класс наследует Album и реализует интерфейс для работы со сборником.
 */
#ifndef COMPILATION_ALBUM
#define COMPILATION_ALBUM
#include <vector>

#include "album.h"
#include "album_type.h"

/*! \class CompilationAlbum
 *  \brief Модель сборника
 *  \details CompilationAlbum наследуется от Album, предоставляя методы для управления
 *           названием альбома, добавления и получения треков, вычисления общей длительности
 *           и получения информации о типе альбома. Специализирован для работы со сборниками
 *           треков.
 */
class CompilationAlbum : public Album
{
public:
    /*! \brief Конструктор по умолчанию
     *  \details Инициализирует сборник с пустым названием и списком треков.
     */
    CompilationAlbum();

    /*! \brief Конструктор с инициализацией названия и треков
     *  \param title Название компиляционного альбома
     *  \param tracks Вектор треков для добавления в альбом
     *  \details Позволяет создать альбом с заданным названием и предустановленным списком треков.
     */
    CompilationAlbum(const std::string& title, const std::vector<Track>& tracks);

    /*! \brief Деструктор
     *  \details Обеспечивает корректное уничтожение объекта сборника.
     */
    ~CompilationAlbum();

    /*! \brief Установить название альбома
     *  \param title Новое название альбома
     *  \details Сохраняет название сборника.
     */
    void SetTitle(const std::string& title) override;

    /*! \brief Получить название альбома
     *  \return Строка с названием альбома
     *  \details Возвращает текущее установленное название сборника.
     */
    std::string GetTitle() const override;

    /*! \brief Добавить трек в альбом
     *  \param track Трек для добавления
     *  \details Добавляет переданный трек в конец списка треков сборника.
     */
    void AddTrack(const Track& track) override;

    /*! \brief Получить количество треков в альбоме
     *  \return Количество треков в альбоме
     *  \details Возвращает общее количество треков, содержащихся в сборнике.
     */
    int GetTrackCount() const override;

    /*! \brief Получить общую длительность альбома
     *  \return Общая длительность всех треков в секундах
     *  \details Вычисляет и возвращает сумму длительностей всех треков в альбоме.
     */
    int GetTotalDuration() const override;

    /*! \brief Получить список треков альбома
     *  \return Строка с отформатированным списком треков
     *  \details Возвращает строковое представление списка треков с их названиями и длительностями.
     */
    std::string GetTrackList() const override;

    /*! \brief Получить тип альбома
     *  \return Строка с описанием типа альбома
     *  \details Возвращает тип альбома, соответствующий значению AlbumType::CompilationAlbum.
     */
    std::string GetAlbumType() const override;

private:
    std::string title_; /*!< Название сборника */
    std::vector<Track> tracks_; /*!< Вектор треков, содержащихся в альбоме */
    AlbumType albumType_{AlbumType::CompilationAlbum}; /*!< Тип альбома - сборник */
};

#endif
