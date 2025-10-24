#include "validator.h"

bool Validator::PasswordValidator(const std::string &password) {
    const std::regex passwordRegex("(^[a-zA-Z0-9.-@]{8,25}$)");
    return std::regex_match(password, passwordRegex);
}

bool Validator::EmailValidator(const std::string &email) {
    const std::regex emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4})");
    return std::regex_match(email, emailRegex);
}
