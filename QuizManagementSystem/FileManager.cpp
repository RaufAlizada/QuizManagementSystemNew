#include "FileManager.h"
#include <fstream>

bool FileManager::saveToFile(const std::vector<Quiz>& quizzes) {
    std::ofstream file("quizzes.txt");
    if (!file.is_open()) {
        return false;
    }

    for (const auto& quiz : quizzes) {
        file << quiz.getName() << "\n";
        for (const auto& question : quiz.getQuestions()) {
            file << question.getText() << "\n";
            for (const auto& option : question.getOptions()) {
                file << option << "\n";
            }
            file << question.getCorrectAnswer() << "\n";
        }
        file << ";\n"; // Quiz separator
    }
    file.close();
    return true;
}

std::vector<Quiz> FileManager::loadFromFile() {
    std::vector<Quiz> quizzes;
    std::ifstream file("quizzes.txt");
    if (!file.is_open()) {
        return quizzes;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line == ";") {
            continue; // Skip quiz separator
        }

        Quiz quiz;
        quiz.setName(line);

        while (std::getline(file, line) && line != ";") {
            Question question;
            std::string text = line;
            std::vector<std::string> options;
            for (int i = 0; i < 4; ++i) {
                std::getline(file, line);
                options.push_back(line);
            }
            char correctAnswer;
            file >> correctAnswer;
            file.ignore(); // Skip newline after reading char

            question.setQuestion(text, options, correctAnswer);
            quiz.addQuestion(question);
        }

        quizzes.push_back(quiz);
    }
    file.close();
    return quizzes;
}
