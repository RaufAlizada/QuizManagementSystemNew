#include "Admin.h"
#include <fstream>
#include <iostream>
using namespace std;

Admin::Admin() {}

Admin::Admin(const string& adminName, const string& adminSurname, const int& adminAge, const string& adminUsername, const string& adminPassword) {}

bool Admin::addStudent(const string& studentName, const string& studentSurname, const string& studentAge, const string& studentUsername, const string& studentPassword) {
    ofstream file("students.txt", ios::app);
    if (!file.is_open()) {
        cout << "Error: Unable to open file." << endl;
        return false;
    }
    file << studentName << " " << studentSurname << " " << studentAge << " " << studentUsername << " " << studentPassword << endl;
    file.close();
    return true;
}

bool Admin::deleteStudent(const string& studentUsername) {
    ifstream inFile("students.txt");
    if (!inFile.is_open()) {
        cout << "Error: Unable to open file." << endl;
        return false;
    }

    ofstream outFile("temp.txt");
    if (!outFile.is_open()) {
        cout << "Error: Unable to open file." << endl;
        inFile.close();
        return false;
    }

    string name, surname, username, password, age;
    bool found = false;
    while (inFile >> name >> surname >> age >> username >> password) {
        if (username != studentUsername) {
            outFile << name << " " << surname << " " << age << " " << username << " " << password << endl;
        }
        else {
            found = true;
        }
    }
    inFile.close();
    outFile.close();
    if (found) {
        remove("students.txt");
        rename("temp.txt", "students.txt");
    }
    return found;
}

bool Admin::changeStudentInfo(const string& studentUsername, const string& newName, const string& newSurname, const string& newPassword) {
    ifstream inFile("students.txt");
    if (!inFile.is_open()) {
        cout << "Error: Unable to open file." << endl;
        return false;
    }

    ofstream outFile("temp.txt");
    if (!outFile.is_open()) {
        cout << "Error: Unable to open file." << endl;
        inFile.close();
        return false;
    }

    string name, surname, username, password, age;
    bool found = false;
    while (inFile >> name >> surname >> age >> username >> password) {
        if (username == studentUsername) {
            if (!newName.empty() && !isAlphabetic(newName)) {
                cout << "Name should contain only alphabetic characters." << endl;
                inFile.close();
                outFile.close();
                return false;
            }
            if (!newSurname.empty() && !isAlphabetic(newSurname)) {
                cout << "Surname should contain only alphabetic characters." << endl;
                inFile.close();
                outFile.close();
                return false;
            }
            if (!newName.empty()) name = newName;
            if (!newSurname.empty()) surname = newSurname;
            if (!newPassword.empty()) password = newPassword;
            found = true;
        }
        outFile << name << " " << surname << " " << age << " " << username << " " << password << endl;
    }
    inFile.close();
    outFile.close();
    if (found) {
        remove("students.txt");
        rename("temp.txt", "students.txt");
    }
    return found;
}

bool Admin::changeStudentAge(const string& studentUsername, const int& newAge) {
    ifstream inFile("students.txt");
    if (!inFile.is_open()) {
        cout << "Error: Unable to open file." << endl;
        return false;
    }

    ofstream outFile("temp.txt");
    if (!outFile.is_open()) {
        cout << "Error: Unable to open file." << endl;
        inFile.close();
        return false;
    }

    string name, surname, username, password, age;
    bool found = false;
    while (inFile >> name >> surname >> age >> username >> password) {
        if (username == studentUsername) {
            if (!isNumeric(to_string(newAge))) {
                cout << "Age should be a numeric value." << endl;
                inFile.close();
                outFile.close();
                return false;
            }
            age = to_string(newAge);
            found = true;
        }
        outFile << name << " " << surname << " " << age << " " << username << " " << password << endl;
    }
    inFile.close();
    outFile.close();
    if (found) {
        remove("students.txt");
        rename("temp.txt", "students.txt");
    }
    return found;
}

bool Admin::isAlphabetic(const string& str) const {
    for (char c : str) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

bool Admin::isNumeric(const string& str) const {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}
