#ifndef PROFILE
#define PROFILE
#include "../User/user.h"
#include "unordered_set"
#include "genre_type.h"
#include "../Exceptions/exceptions.h"


class Profile
{
public:
    Profile();
    ~Profile();
    Profile(const User& user, const std::string& description, const std::string& gender,
            const std::unordered_set<GenreType>& preferences);
    void SetDescription(const std::string& description);
    std::string GetDescription() const;
    void SetGender(const std::string& gender);
    std::string GetGender() const;
    void SetPreferences(const std::unordered_set<GenreType>& preferences);
    std::unordered_set<GenreType> GetPreferences() const;
    std::string GetProfileInfo() const;

private:
    User user_;
    std::string description_;
    std::string gender_;
    std::unordered_set<GenreType> preferences_;
};


#endif
