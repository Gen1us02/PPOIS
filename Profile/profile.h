/*! \file profile.h
 *  \brief Заголовочный файл с описанием класса Profile
 *  \details Содержит объявление класса Profile, представляющего профиль пользователя.
 *           Класс хранит дополнительную информацию о пользователе, такую как описание,
 *           пол и музыкальные предпочтения.
 */
#ifndef PROFILE
#define PROFILE
#include "../User/user.h"
#include "unordered_set"
#include "genre_type.h"
#include "../Exceptions/exceptions.h"

/*! \class Profile
 *  \brief Модель профиля пользователя
 *  \details Profile предоставляет методы для управления дополнительной информацией
 *           о пользователе, включая описание, пол и музыкальные предпочтения.
 *           Расширяет базовую информацию о пользователе для персонализации приложения.
 */
class Profile
{
public:
    /*! \brief Конструктор по умолчанию
     *  \details Инициализирует профиль с пустым описанием, полем и предпочтениями.
     */
    Profile();

    /*! \brief Деструктор
     *  \details Обеспечивает корректное уничтожение объекта профиля.
     */
    ~Profile();

    /*! \brief Конструктор с инициализацией параметров профиля
     *  \param user Пользователь, связанный с профилем
     *  \param description Описание профиля
     *  \param gender Пол пользователя
     *  \param preferences Музыкальные предпочтения пользователя
     *  \details Позволяет создать профиль с заданными параметрами пользователя.
     */
    Profile(const User& user, const std::string& description, const std::string& gender,
            const std::unordered_set<GenreType>& preferences);

    /*! \brief Установить описание профиля
     *  \param description Новое описание профиля
     *  \details Сохраняет текстовое описание профиля пользователя.
     */
    void SetDescription(const std::string& description);

    /*! \brief Получить описание профиля
     *  \return Строка с описанием профиля
     *  \details Возвращает текущее установленное описание профиля пользователя.
     */
    std::string GetDescription() const;

    /*! \brief Установить пол пользователя
     *  \param gender Пол пользователя
     *  \details Сохраняет информацию о поле пользователя.
     */
    void SetGender(const std::string& gender);

    /*! \brief Получить пол пользователя
     *  \return Строка с указанием пола пользователя
     *  \details Возвращает текущую установленную информацию о поле пользователя.
     */
    std::string GetGender() const;

    /*! \brief Установить музыкальные предпочтения
     *  \param preferences Набор музыкальных предпочтений
     *  \details Сохраняет набор музыкальных жанров, предпочитаемых пользователем.
     */
    void SetPreferences(const std::unordered_set<GenreType>& preferences);

    /*! \brief Получить музыкальные предпочтения
     *  \return Набор музыкальных предпочтений
     *  \details Возвращает текущие музыкальные предпочтения пользователя.
     */
    std::unordered_set<GenreType> GetPreferences() const;

    /*! \brief Получить информацию о профиле
     *  \return Строка с форматированной информацией о профиле
     *  \details Возвращает полную информацию о профиле пользователя в удобочитаемом формате.
     */
    std::string GetProfileInfo() const;

private:
    User user_; /*!< Пользователь, связанный с профилем */
    std::string description_; /*!< Описание профиля */
    std::string gender_; /*!< Пол пользователя */
    std::unordered_set<GenreType> preferences_; /*!< Музыкальные предпочтения пользователя */
};

#endif
