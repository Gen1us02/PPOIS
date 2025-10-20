#ifndef USER
#define USER
#include <string>
#include "../Utils/utils.h"
#include "../Exceptions/exceptions.h"


class User
{
public:
    User();
    ~User();
    User(const std::string& name, const std::string& surname, int age, const std::string& email,
         const std::string& username,
         const std::string& password);
    void SetName(const std::string& name);
    std::string GetName() const;
    void SetSurname(const std::string& surname);
    std::string GetSurname() const;
    void SetAge(int age);
    int GetAge() const;
    void SetEmail(const std::string& email);
    std::string GetEmail() const;
    void SetUsername(const std::string& username);
    std::string GetUsername() const;
    void SetPassword(const std::string& password);
    std::string GetPassword() const;
    std::string GetUserInfo() const;

private:
    std::string name_;
    std::string surname_;
    int age_{0};
    std::string email_;
    std::string username_;
    std::string password_;
};


#endif
