/*! \file validator.h
 *  \brief Заголовочный файл с описанием класса Validator
 *  \details Содержит объявление класса Validator, предоставляющего методы
 *           для валидации различных типов данных, таких как пароли и email-адреса.
 */
#ifndef VALIDATOR
#define VALIDATOR

#include <string>
#include <regex>

/*! \class Validator
 *  \brief Класс для валидации данных
 *  \details Validator предоставляет методы для проверки корректности
 *           паролей и электронных почт пользователя. Все методы класса являются статическими и не
 *           требуют создания экземпляра класса для использования.
 */
class Validator {
public:
    /*! \brief Валидатор пароля
     *  \param password Пароль для проверки
     *  \return true если пароль соответствует требованиям безопасности, false в противном случае
     *  \details Проверяет пароль на соответствие требованиям безопасности, таким как минимальная длина,
     *           наличие цифр, заглавных и строчных букв, специальных символов.
     */
    static bool PasswordValidator(const std::string &password);

    /*! \brief Валидатор email-адреса
     *  \param email Email-адрес для проверки
     *  \return true если email соответствует стандартному формату, false в противном случае
     *  \details Проверяет email-адрес на соответствие стандартному формату с использованием регулярных выражений.
     */
    static bool EmailValidator(const std::string &email);
};

#endif