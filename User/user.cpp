#include "user.h"

#include <format>

User::User() = default;

User::~User() = default;

User::User(const std::string& name, const std::string& surname, int age, const std::string& email,
           const std::string& username, const std::string& password)
{
    if (!EmailValidator(email))
    {
        throw ExceptionInvalidEmail("Email validation failed.");
    }
    if (!PasswordValidator(password))
    {
        throw ExceptionInvalidPassword("Password validation failed.");
    }

    this->name_ = name;
    this->surname_ = surname;
    this->age_ = age;
    this->username_ = username;
    this->email_ = email;
    this->password_ = password;
}

void User::SetName(const std::string& name)
{
    this->name_ = name;
}

std::string User::GetName() const
{
    return this->name_;
}

void User::SetSurname(const std::string& surname)
{
    this->surname_ = surname;
}

std::string User::GetSurname() const
{
    return this->surname_;
}

void User::SetAge(const int age)
{
    this->age_ = age;
}

int User::GetAge() const
{
    return this->age_;
}

void User::SetEmail(const std::string& email)
{
    if (!EmailValidator(email))
    {
        throw ExceptionInvalidEmail("Email validation failed.");
    }

    this->email_ = email;
}

std::string User::GetEmail() const
{
    return this->email_;
}

void User::SetPassword(const std::string& password)
{
    if (!PasswordValidator(password))
    {
        throw ExceptionInvalidPassword("Password validation failed.");
    }

    this->password_ = password;
}

std::string User::GetPassword() const
{
    return this->password_;
}

void User::SetUsername(const std::string& username)
{
    this->username_ = username;
}

std::string User::GetUsername() const
{
    return this->username_;
}

std::string User::GetUserInfo() const
{
    return std::format("Имя: {}\n"
                       "Фамилия: {}\n"
                       "Возраст: {}\n"
                       "Имя пользователя: {}\n"
                       "Email: {}\n"
                       "Пароль: {}\n", this->name_, this->surname_, this->age_, this->username_, this->email_,
                       this->password_);
}
