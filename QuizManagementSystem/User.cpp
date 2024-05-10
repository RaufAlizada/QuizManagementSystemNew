#include "User.h"

User::User(const std::string& name, const std::string& surname, const std::string& age, const std::string& username, const std::string& password)
    : name(name), surname(surname), age(age), username(username), password(password) {}

const std::string& User::getUsername() const {
    return username;
}

bool User::checkPassword(const std::string& inputPassword) const {
    return password == inputPassword;
}

void User::changePassword(const std::string& newPassword) {
    password = newPassword;
}
