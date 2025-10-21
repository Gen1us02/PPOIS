/*! \file queue.h
 *  \brief Заголовочный файл с описанием класса Queue
 *  \details Содержит объявление класса Queue, представляющего очередь воспроизведения.
 *           Класс наследует MusicCollection и реализует интерфейс для управления
 *           очередью треков для последовательного воспроизведения.
 */
#ifndef QUEUE
#define QUEUE
#include "music_collection.h"
#include <vector>
#include "../Track/track.h"
#include "../Exceptions/exceptions.h"

/*! \class Queue
 *  \brief Модель очереди воспроизведения
 *  \details Queue наследуется от MusicCollection и предоставляет методы для управления
 *           очередью треков. Обеспечивает функциональность для добавления, удаления
 *           и получения списка треков в порядке их воспроизведения.
 */
class Queue : public MusicCollection
{
public:
    /*! \brief Конструктор по умолчанию
     *  \details Инициализирует очередь с пустым списком треков.
     */
    Queue();

    /*! \brief Деструктор
     *  \details Обеспечивает корректное уничтожение объекта очереди.
     */
    ~Queue();

    /*! \brief Явный конструктор с инициализацией треков
     *  \param tracks Вектор треков для добавления в очередь
     *  \details Позволяет создать очередь с предустановленным списком треков.
     */
    explicit Queue(const std::vector<Track>& tracks);

    /*! \brief Установить треки очереди
     *  \param tracks Вектор треков для установки в очередь
     *  \details Заменяет текущий список треков очереди на указанный вектор.
     */
    void SetTracks(const std::vector<Track>& tracks);

    /*! \brief Получить треки очереди
     *  \return Вектор треков в очереди
     *  \details Возвращает текущий список треков, содержащихся в очереди воспроизведения.
     */
    std::vector<Track> GetTracks() const;

    /*! \brief Добавить трек в очередь
     *  \param track Трек для добавления в очередь
     *  \details Добавляет указанный трек в конец очереди воспроизведения.
     */
    void AddTrack(const Track& track);

    /*! \brief Удалить трек из очереди
     *  \param track Трек для удаления из очереди
     *  \details Удаляет указанный трек из очереди воспроизведения.
     */
    void RemoveTrack(const Track& track);

    /*! \brief Получить список треков очереди
     *  \return Строка с отформатированным списком треков
     *  \details Возвращает строковое представление всех треков в очереди воспроизведения.
     */
    std::string GetTrackList() const override;

private:
    std::vector<Track> tracks_; /*!< Вектор треков в очереди воспроизведения */
};

#endif
