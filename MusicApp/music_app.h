/*! \file music_app.h
 *  \brief Заголовочный файл с описанием класса MusicApp
 *  \details Содержит объявление класса MusicApp, представляющего главное музыкальное приложение.
 *           Класс объединяет все компоненты медиаплеера: кнопки, полосы прогресса, очередь
 *           воспроизведения, профиль пользователя и медиатеку.
 */
#ifndef MUSIC_APP
#define MUSIC_APP
#include "../Buttons/ArtistInfoButton/artist_info_button.h"
#include "../Buttons/MarkFavouriteButton/mark_favourite_button.h"
#include "../Buttons/NextTrackButton/next_track_button.h"
#include "../Buttons/PreviousTrackButton/previous_track_button.h"
#include "../Buttons/NowPlayingButton/now_playing_button.h"
#include "../Buttons/PlayButton/play_button.h"
#include "../Buttons/TrackTextButton/track_text_button.h"
#include "../Buttons/VolumeButton/volume_button.h"
#include "../Bars/TrackDurationBar/track_duration_bar.h"
#include "../Bars/VolumeBar/volume_bar.h"
#include "../Queue/queue.h"
#include "../Profile/profile.h"
#include "../MediaLibrary/media_library.h"

/*! \class MusicApp
 *  \brief Главный класс музыкального приложения
 *  \details MusicApp объединяет все компоненты медиаплеера в единую систему.
 *           Предоставляет высокоуровневые методы для управления воспроизведением,
 *           громкостью, навигацией по трекам и работы с медиатекой пользователя.
 */
class MusicApp
{
public:
    /*! \brief Конструктор по умолчанию
     *  \details Инициализирует музыкальное приложение с компонентами по умолчанию.
     */
    MusicApp();

    /*! \brief Деструктор
     *  \details Обеспечивает корректное уничтожение объекта музыкального приложения.
     */
    ~MusicApp();

    /*! \brief Конструктор с инициализацией всех компонентов
     *  \param artistInfoButton Кнопка информации об исполнителе
     *  \param markFavouriteButton Кнопка добавления в избранное
     *  \param nextTrackButton Кнопка следующего трека
     *  \param previousTrackButton Кнопка предыдущего трека
     *  \param nowPlayingButton Кнопка текущего трека
     *  \param playButton Кнопка воспроизведения/паузы
     *  \param trackTextButton Кнопка текста трека
     *  \param volumeButton Кнопка громкости
     *  \param trackDurationBar Полоса длительности трека
     *  \param volumeBar Полоса громкости
     *  \param queue Очередь воспроизведения
     *  \param profile Профиль пользователя
     *  \param mediaLibrary Медиатека пользователя
     *  \details Позволяет создать музыкальное приложение с предустановленными компонентами.
     */
    MusicApp(const ArtistInfoButton& artistInfoButton, const MarkFavouriteButton& markFavouriteButton,
             const NextTrackButton& nextTrackButton, const PreviousTrackButton& previousTrackButton,
             const NowPlayingButton& nowPlayingButton, const PlayButton& playButton,
             const TrackTextButton& trackTextButton, const VolumeButton& volumeButton,
             const TrackDurationBar& trackDurationBar, const VolumeBar& volumeBar, const Queue& queue,
             const Profile& profile, const MediaLibrary& mediaLibrary);

    /*! \brief Воспроизвести текущий трек
     *  \details Запускает воспроизведение текущего выбранного трека.
     */
    void PlayTrack();

    /*! \brief Поставить трек на паузу
     *  \return Строка с подтверждением постановки на паузу
     *  \details Приостанавливает воспроизведение текущего трека.
     */
    std::string PauseTrack();

    /*! \brief Отключить громкость
     *  \return Строка с подтверждением отключения громкости
     *  \details Устанавливает громкость в 0 (режим без звука).
     */
    std::string TurnOffVolume();

    /*! \brief Включить громкость
     *  \return Строка с подтверждением включения громкости
     *  \details Восстанавливает предыдущий уровень громкости.
     */
    std::string TurnOnVolume();

    /*! \brief Установить уровень громкости
     *  \param volume Новый уровень громкости (0-100)
     *  \return Строка с подтверждением установки громкости
     *  \details Устанавливает указанный уровень громкости с проверкой допустимости значения.
     */
    std::string SetVolume(int volume);

    /*! \brief Показать информацию об исполнителе
     *  \param artist Исполнитель для отображения информации
     *  \return Строка с информацией об исполнителе
     *  \details Возвращает форматированную информацию об указанном исполнителе.
     */
    std::string ShowArtistInfo(const Artist& artist);

    /*! \brief Показать информацию о текущем треке
     *  \return Строка с информацией о текущем треке
     *  \details Возвращает информацию о треке, который воспроизводится в данный момент.
     */
    std::string ShowNowPlayingTrackInfo() const;

    /*! \brief Добавить трек в избранное
     *  \details Помечает текущий трек как избранный и добавляет его в плейлист избранного.
     */
    void MarkFavouriteTrack();

    /*! \brief Удалить трек из избранного
     *  \details Убирает пометку избранного с текущего трека и удаляет его из плейлиста избранного.
     */
    void UnmarkFavouriteTrack();

    /*! \brief Перейти к следующему треку
     *  \details Переключает воспроизведение на следующий трек в очереди или плейлисте.
     */
    void NextTrack();

    /*! \brief Перейти к предыдущему треку
     *  \details Переключает воспроизведение на предыдущий трек в очереди или плейлисте.
     */
    void PreviousTrack();

    /*! \brief Показать информацию о профиле
     *  \return Строка с информацией о профиле пользователя
     *  \details Возвращает информацию о текущем пользователе приложения.
     */
    std::string ShowProfileInfo();

    /*! \brief Добавить трек в очередь
     *  \param track Трек для добавления в очередь
     *  \details Добавляет указанный трек в конец очереди воспроизведения.
     */
    void AddTrackToQueue(const Track& track);

    /*! \brief Удалить трек из очереди
     *  \param track Трек для удаления из очереди
     *  \details Удаляет указанный трек из очереди воспроизведения.
     */
    void RemoveTrackFromQueue(const Track& track);

private:
    Track currentTrack_; /*!< Текущий воспроизводимый трек */
    int currentTrackIndex_{0}; /*!< Индекс текущего трека в плейлисте */
    int currentVolume_{0}; /*!< Текущий уровень громкости */
    int lastVolume_{0}; /*!< Предыдущий уровень громкости (для восстановления) */
    ArtistInfoButton artistInfoButton_; /*!< Кнопка информации об исполнителе */
    MarkFavouriteButton markFavouriteButton_; /*!< Кнопка добавления в избранное */
    NextTrackButton nextTrackButton_; /*!< Кнопка следующего трека */
    PreviousTrackButton previousTrackButton_; /*!< Кнопка предыдущего трека */
    NowPlayingButton nowPlayingButton_; /*!< Кнопка текущего трека */
    PlayButton playButton_; /*!< Кнопка воспроизведения/паузы */
    TrackTextButton trackTextButton_; /*!< Кнопка текста трека */
    VolumeButton volumeButton_; /*!< Кнопка громкости */
    TrackDurationBar trackDurationBar_; /*!< Полоса длительности трека */
    VolumeBar volumeBar_; /*!< Полоса громкости */
    Queue queue_; /*!< Очередь воспроизведения */
    Profile profile_; /*!< Профиль пользователя */
    MediaLibrary mediaLibrary_; /*!< Медиатека пользователя */
};

#endif
