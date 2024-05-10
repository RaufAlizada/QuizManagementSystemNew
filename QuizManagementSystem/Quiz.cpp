#include "Quiz.h"
#include <iostream>

Quiz::Quiz() {}

void Quiz::setName(const string& quizName) {
	name = quizName;
}

void Quiz::addQuestion(const Question& question) {
	questions.push_back(question);
}

string Quiz::getName() const {
	return name;
}

vector<Question> Quiz::getQuestions() const {
	return questions;
}

void Quiz::print() const {
    std::cout << "Quiz Name: " << getName() << std::endl;
    int questionCount = 1;
    for (const auto& question : questions) {
        std::cout << "Question " << questionCount++ << ": " << std::endl;
        std::cout << "Question Text: " << question.getText() << std::endl;
        std::cout << "Options: " << std::endl;
        for (int i = 0; i < question.getOptions().size(); ++i) {
            std::cout << static_cast<char>('A' + i) << ". " << question.getOptions()[i] << std::endl;
        }
        std::cout << "Correct Answer: " << question.getCorrectAnswer() << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }
}

void Quiz::printQuestions() const {
    std::cout << "Quiz Name: " << getName() << std::endl;
    int questionCount = 1;
    for (const auto& question : questions) {
        std::cout << "Question " << questionCount++ << ": " << std::endl;
        std::cout << "Question Text: " << question.getText() << std::endl;
        std::cout << "Options: " << std::endl;
        for (int i = 0; i < question.getOptions().size(); ++i) {
            std::cout << static_cast<char>('A' + i) << ". " << question.getOptions()[i] << std::endl;
        }
        std::cout << "-----------------------------" << std::endl;
    }
}

void Quiz::printAnswers() const {
    std::cout << "Quiz Name: " << getName() << std::endl;
    int questionCount = 1;
    for (const auto& question : questions) {
        std::cout << "Question " << questionCount++ << ": " << std::endl;
        std::cout << "Correct Answer: " << question.getCorrectAnswer() << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }
}

void Quiz::printTrueAnswers() const {
    std::cout << "Quiz Name: " << getName() << std::endl;
    int questionCount = 1;
    for (const auto& question : questions) {
        std::cout << "Question " << questionCount++ << ": " << std::endl;
        std::cout << "Correct Answer: " << question.getCorrectAnswer() << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }
}
