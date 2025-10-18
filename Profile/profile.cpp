#include "profile.h"
#include <format>

Profile::Profile() = default;

Profile::~Profile() = default;

Profile::Profile(const User& user, const std::string& description, const std::string& gender,
                 const std::unordered_set<GenreType>& preferences) : user_(user), description_(description), gender_(gender), preferences_(preferences)
{
}

void Profile::SetDescription(const std::string& description)
{
    this->description_ = description;
}

std::string Profile::GetDescription() const
{
    return this->description_;
}

void Profile::SetGender(const std::string& gender)
{
    this->gender_ = gender;
}

std::string Profile::GetGender() const
{
    return this->gender_;
}

void Profile::SetPreferences(const std::unordered_set<GenreType>& preferences)
{
    this->preferences_ = preferences;
}

std::unordered_set<GenreType> Profile::GetPreferences() const
{
    return this->preferences_;
}

std::string Profile::GetProfileInfo() const
{
    std::string preference_list;
    for (const auto& preference : this->preferences_)
    {
        preference_list += GenreTypeToString(preference) + " ";
    }
    return user_.GetUserInfo() + std::format("Описание профиля: {}\n"
                                             "Пол: {}\n"
                                             "Предпочтения: {}", this->description_, this->gender_, preference_list);
}
