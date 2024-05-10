#include <string>
using namespace std;

class Admin {
private:
    string name;
    string surname;
    int age;
    string username;
    string password;

public:
    // DEFAULT CONSTRUCTOR
    Admin();

    // Constructor
    Admin(const string& adminName, const string& adminSurname, const int& adminAge, const string& adminUsername, const string& adminPassword);

    // Methods
    bool addStudent(const string& studentName, const string& studentSurname, const string& studentAge, const string& studentUsername, const string& studentPassword);
    bool deleteStudent(const string& studentUsername);
    bool changeStudentInfo(const string& studentUsername, const string& newName, const string& newSurname, const string& newPassword);
    bool changeStudentAge(const string& studentUsername, const int& newAge);

    // Helper methods
    bool isAlphabetic(const string& str) const;
    bool isNumeric(const string& str) const;
};
