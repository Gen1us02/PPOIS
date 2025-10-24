/*! \file user.h
 *  \brief Заголовочный файл с описанием класса User
 *  \details Содержит объявление класса User, представляющего пользователя музыкального приложения.
 *           Класс предоставляет методы для управления персональными данными пользователя,
 *           включая имя, фамилию, возраст, email, имя пользователя и пароль.
 */
#ifndef USER
#define USER
#include <string>
#include "../Validator/validator.h"
#include "../Exceptions/exceptions.h"

/*! \class User
 *  \brief Модель пользователя музыкального приложения
 *  \details User предоставляет методы для управления учетной записью пользователя,
 *           включая хранение и валидацию персональных данных, аутентификационную
 *           информацию и методы для получения полной информации о пользователе.
 */
class User
{
public:
    /*! \brief Конструктор по умолчанию
     *  \details Инициализирует пользователя с пустыми значениями имени, фамилии, email,
     *           имени пользователя и пароля, нулевым значением возраста.
     */
    User();

    /*! \brief Деструктор
     *  \details Обеспечивает корректное уничтожение объекта пользователя.
     */
    ~User();

    /*! \brief Конструктор с инициализацией параметров пользователя
     *  \param name Имя пользователя
     *  \param surname Фамилия пользователя
     *  \param age Возраст пользователя
     *  \param email Email пользователя
     *  \param username Имя пользователя (логин)
     *  \param password Пароль пользователя
     *  \details Позволяет создать пользователя с заданными персональными данными.
     */
    User(const std::string& name, const std::string& surname, int age, const std::string& email,
         const std::string& username,
         const std::string& password);

    /*! \brief Установить имя пользователя
     *  \param name Новое имя пользователя
     *  \details Сохраняет имя пользователя.
     */
    void SetName(const std::string& name);

    /*! \brief Получить имя пользователя
     *  \return Строка с именем пользователя
     *  \details Возвращает текущее установленное имя пользователя.
     */
    std::string GetName() const;

    /*! \brief Установить фамилию пользователя
     *  \param surname Новая фамилия пользователя
     *  \details Сохраняет фамилию пользователя.
     */
    void SetSurname(const std::string& surname);

    /*! \brief Получить фамилию пользователя
     *  \return Строка с фамилией пользователя
     *  \details Возвращает текущую установленную фамилию пользователя.
     */
    std::string GetSurname() const;

    /*! \brief Установить возраст пользователя
     *  \param age Новый возраст пользователя
     *  \details Сохраняет возраст пользователя.
     */
    void SetAge(int age);

    /*! \brief Получить возраст пользователя
     *  \return Возраст пользователя
     *  \details Возвращает текущий установленный возраст пользователя.
     */
    int GetAge() const;

    /*! \brief Установить email пользователя
     *  \param email Новый email пользователя
     *  \details Сохраняет email пользователя с проверкой корректности формата.
     */
    void SetEmail(const std::string& email);

    /*! \brief Получить email пользователя
     *  \return Строка с email пользователя
     *  \details Возвращает текущий установленный email пользователя.
     */
    std::string GetEmail() const;

    /*! \brief Установить имя пользователя (логин)
     *  \param username Новое имя пользователя
     *  \details Сохраняет имя пользователя для входа в систему.
     */
    void SetUsername(const std::string& username);

    /*! \brief Получить имя пользователя (логин)
     *  \return Строка с именем пользователя
     *  \details Возвращает текущее установленное имя пользователя для входа в систему.
     */
    std::string GetUsername() const;

    /*! \brief Установить пароль пользователя
     *  \param password Новый пароль пользователя
     *  \details Сохраняет пароль пользователя с проверкой соответствия требованиям безопасности.
     */
    void SetPassword(const std::string& password);

    /*! \brief Получить пароль пользователя
     *  \return Строка с паролем пользователя
     *  \details Возвращает текущий установленный пароль пользователя.
     */
    std::string GetPassword() const;

    /*! \brief Получить информацию о пользователе
     *  \return Строка с форматированной информацией о пользователе
     *  \details Возвращает полную информацию о пользователе в удобочитаемом формате.
     */
    std::string GetUserInfo() const;

private:
    std::string name_; /*!< Имя пользователя */
    std::string surname_; /*!< Фамилия пользователя */
    int age_{0}; /*!< Возраст пользователя */
    std::string email_; /*!< Email пользователя */
    std::string username_; /*!< Имя пользователя для входа в систему */
    std::string password_; /*!< Пароль пользователя */
};

#endif
