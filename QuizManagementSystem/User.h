#pragma once
#include <string>

class User {
protected:
    std::string name;
    std::string surname;
    std::string age;
    std::string username;
    std::string password;

public:
    User(const std::string& name, const std::string& surname, const std::string& age, const std::string& username, const std::string& password);
    User(){}
    const std::string& getUsername() const;

    bool checkPassword(const std::string& inputPassword) const;

    void changePassword(const std::string& newPassword);
};
