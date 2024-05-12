#pragma once
#include "Student.h"
#include <string>
#include <vector>
#include "QuizManager.h"

using namespace std;

class Student {
private:
    string name;
    string surname;
    string age;
    string username;
    string password;
    QuizManager quizManager;

    vector<string> quizNames;

    int currentQuestionIndex = 0;
    int correctAnswers = 0;
    int incorrentAnswers = 0;
    int unansweredQuestions = 0;
    double percentage;

    int choice;

public:
    Student() {}
    Student(const std::string& name, const std::string& surname, const std::string& age, const std::string& username, const std::string& password, const QuizManager& quizManager)
        : name(name), surname(surname), age(age), username(username), password(password), quizManager(quizManager) {}

    bool startQuiz(const int& choice, const string& userChoice, const string& userAnswer);

    double getCorrectAnswers() const;
    double getIncorrectAnswers() const;
    double getUnansweredQuestions() const;
    double getPercentage() const;
};