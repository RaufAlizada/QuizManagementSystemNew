#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <vector>
#include <list>
#include <random>
#include <string>
#include <fstream>
#include <conio.h>
#include <memory>
#include <ctime>


using namespace std;

#include "OwnException.h"
#include "QuizManager.h"
#include "FileManager.h"
#include "Quiz.h"



bool QuizManager::addQuiz(const Quiz& quiz) {
	for (const auto& q : quizzes) {
		if (q.getName() == quiz.getName()) {
			return false; // [QUIZ ALREADY EXIST]
		}
	}
	quizzes.push_back(quiz);
	return true;
}

bool QuizManager::removeQuiz(const string& quizName) {
	auto it = find_if(quizzes.begin(), quizzes.end(),
		[&](const Quiz& quiz) {
			return quiz.getName() == quizName;
		});
	if (it != quizzes.end()) {
		quizzes.erase(it);
		return true;
	}
	return false;
}

bool QuizManager::saveQuizzes() const
{
	if (FileManager::saveToFile(quizzes)) {
        return true;
	}
	else {
        return false;
	}
}

void QuizManager::loadQuizzes() {
	quizzes = FileManager::loadFromFile();
}

bool QuizManager::changeQuizName(const string& oldName, const string& newName) {
    for (auto& quiz : quizzes) {
        if (quiz.getName() == oldName) {
            quiz.setName(newName);
            return true;
        }
    }
    return false; // [QUIZ NOT FOUND]
}

//bool QuizManager::changeQuestions(int quizIndex, int questionIndex, const std::string& newQuestionText) {
//	if (quizIndex >= 0 && quizIndex < quizzes.size() && questionIndex >= 0 && questionIndex < quizzes[quizIndex].getQuestions().size()) {
//		quizzes[quizIndex].getQuestions()[questionIndex].setQuestion(newQuestionText, quizzes[quizIndex].getQuestions()[questionIndex].getOptions(), quizzes[quizIndex].getQuestions()[questionIndex].getCorrectAnswer());
//		return true;
//	}
//	return false;
//}
//
//bool QuizManager::changeAnswers(int quizIndex, int questionIndex, const std::vector<std::string>& newOptions) {
//	if (quizIndex >= 0 && quizIndex < quizzes.size() && questionIndex >= 0 && questionIndex < quizzes[quizIndex].getQuestions().size()) {
//		quizzes[quizIndex].getQuestions()[questionIndex].setQuestion(quizzes[quizIndex].getQuestions()[questionIndex].getText(), newOptions, quizzes[quizIndex].getQuestions()[questionIndex].getCorrectAnswer());
//		return true;
//	}
//	return false;
//}
//
//bool QuizManager::changeTrueAnswer(int quizIndex, int questionIndex, char newCorrectAnswer) {
//	if (quizIndex >= 0 && quizIndex < quizzes.size() && questionIndex >= 0 && questionIndex < quizzes[quizIndex].getQuestions().size()) {
//		quizzes[quizIndex].getQuestions()[questionIndex].setQuestion(quizzes[quizIndex].getQuestions()[questionIndex].getText(), quizzes[quizIndex].getQuestions()[questionIndex].getOptions(), newCorrectAnswer);
//		return true;
//	}
//	return false;
//}

vector<string> QuizManager::getQuizNames() const {
	vector<string> names;
	for (const auto& quiz : quizzes) {
		names.push_back(quiz.getName());
	}
	return names;
}

vector<string> QuizManager::getQuestionTexts(int quizIndex) const {
	vector<string> texts;
	if (quizIndex >= 0 && quizIndex < quizzes.size()) {
		for (const auto& question : quizzes[quizIndex].getQuestions()) {
			texts.push_back(question.getText());
		}
	}
	return texts;
}

// NEW _________

bool QuizManager::changeQuestions(int quizIndex, int questionIndex, const std::string& newQuestionText) {
	if (quizIndex < 0 || quizIndex >= quizzes.size()) {
		return false;
	}
	if (questionIndex < 0 || questionIndex >= quizzes[quizIndex].getQuestions().size()) {
		return false;
	}
	quizzes[quizIndex].getQuestions()[questionIndex].setQuestion(newQuestionText, quizzes[quizIndex].getQuestions()[questionIndex].getOptions(), quizzes[quizIndex].getQuestions()[questionIndex].getCorrectAnswer());
	return true;
}

bool QuizManager::changeAnswers(int quizIndex, int questionIndex, const std::vector<std::string>& newOptions) {
	if (quizIndex < 0 || quizIndex >= quizzes.size()) {
		return false;
	}
	if (questionIndex < 0 || questionIndex >= quizzes[quizIndex].getQuestions().size()) {
		return false;
	}
	quizzes[quizIndex].getQuestions()[questionIndex].setQuestion(quizzes[quizIndex].getQuestions()[questionIndex].getText(), newOptions, quizzes[quizIndex].getQuestions()[questionIndex].getCorrectAnswer());
	return true;
}

bool QuizManager::changeTrueAnswer(int quizIndex, int questionIndex, char newCorrectAnswer) {
	if (quizIndex < 0 || quizIndex >= quizzes.size()) {
		return false;
	}
	if (questionIndex < 0 || questionIndex >= quizzes[quizIndex].getQuestions().size()) {
		return false;
	}
	quizzes[quizIndex].getQuestions()[questionIndex].setQuestion(quizzes[quizIndex].getQuestions()[questionIndex].getText(), quizzes[quizIndex].getQuestions()[questionIndex].getOptions(), newCorrectAnswer);
	return true;
}

void QuizManager::ChangeQuizQuestions(QuizManager& quizManager) {
    system("cls");
    cout << "Available quizzes:\n";
    vector<string> quizNames = quizManager.getQuizNames();
    for (int i = 0; i < quizNames.size(); ++i) {
        cout << i + 1 << ". " << quizNames[i] << endl;
    }
    cout << "Enter the number of the quiz to change its questions (or 0 to go back): ";
    int choice;
    cin >> choice;
    cin.ignore();
    if (choice >= 1 && choice <= quizNames.size()) {
        vector<string> questionTexts = quizManager.getQuestionTexts(choice - 1);
        system("cls");
        cout << "Available questions for quiz " << quizNames[choice - 1] << ":\n";
        for (int i = 0; i < questionTexts.size(); ++i) {
            cout << i + 1 << ". " << questionTexts[i] << endl;
        }
        cout << "Enter the number of the question to change its text (or 0 to go back): ";
        int questionChoice;
        cin >> questionChoice;
        cin.ignore();
        if (questionChoice >= 1 && questionChoice <= questionTexts.size()) {
            string newQuestionText;
            cout << "Enter the new text for the question: ";
            getline(cin, newQuestionText);
            if (changeQuestions(choice - 1, questionChoice - 1, newQuestionText)) {
                cout << "Question text changed successfully.\n";
                saveQuizzes();
            }
            else {
                cout << "Failed to change question text.\n";
            }
        }
        else if (questionChoice != 0) {
            cout << "Invalid choice.\n";
        }
    }
    else if (choice != 0) {
        cout << "Invalid choice.\n";
    }
}

void QuizManager::ChangeQuizQuestionsAnswers(QuizManager& quizManager) {
    system("cls");
    cout << "Available quizzes:\n";
    vector<string> quizNames = quizManager.getQuizNames();
    for (int i = 0; i < quizNames.size(); ++i) {
        cout << i + 1 << ". " << quizNames[i] << endl;
    }
    cout << "Enter the number of the quiz to change its questions' answers (or 0 to go back): ";
    int choice;
    cin >> choice;
    cin.ignore();
    if (choice >= 1 && choice <= quizNames.size()) {
        vector<string> questionTexts = quizManager.getQuestionTexts(choice - 1);
        system("cls");
        cout << "Available questions for quiz " << quizNames[choice - 1] << ":\n";
        for (int i = 0; i < questionTexts.size(); ++i) {
            cout << i + 1 << ". " << questionTexts[i] << endl;
        }
        cout << "Enter the number of the question to change its answers (or 0 to go back): ";
        int questionChoice;
        cin >> questionChoice;
        cin.ignore();
        if (questionChoice >= 1 && questionChoice <= questionTexts.size()) {
            vector<string> newOptions;
            cout << "Enter the new options for the question:\n";
            for (int i = 0; i < 4; ++i) {
                string option;
                cout << static_cast<char>('A' + i) << ". ";
                getline(cin, option);
                newOptions.push_back(option);
            }
            if (changeAnswers(choice - 1, questionChoice - 1, newOptions)) {
                cout << "Question answers changed successfully.\n";
                saveQuizzes();
            }
            else {
                cout << "Failed to change question answers.\n";
            }
        }
        else if (questionChoice != 0) {
            cout << "Invalid choice.\n";
        }
    }
    else if (choice != 0) {
        cout << "Invalid choice.\n";
    }
}

void QuizManager::ChangeQuizQuestionsTrueAnswers(QuizManager& quizManager) {
    system("cls");
    cout << "Available quizzes:\n";
    vector<string> quizNames = quizManager.getQuizNames();
    for (int i = 0; i < quizNames.size(); ++i) {
        cout << i + 1 << ". " << quizNames[i] << endl;
    }
    cout << "Enter the number of the quiz to change its questions' true answers (or 0 to go back): ";
    int choice;
    cin >> choice;
    cin.ignore();
    if (choice >= 1 && choice <= quizNames.size()) {
        vector<string> questionTexts = quizManager.getQuestionTexts(choice - 1);
        system("cls");
        cout << "Available questions for quiz " << quizNames[choice - 1] << ":\n";
        for (int i = 0; i < questionTexts.size(); ++i) {
            cout << i + 1 << ". " << questionTexts[i] << endl;
        }
        cout << "Enter the number of the question to change its true answer (or 0 to go back): ";
        int questionChoice;
        cin >> questionChoice;
        cin.ignore();
        if (questionChoice >= 1 && questionChoice <= questionTexts.size()) {
            char newCorrectAnswer;
            cout << "Enter the new correct answer for the question: ";
            cin >> newCorrectAnswer;
            cin.ignore();
            if (changeTrueAnswer(choice - 1, questionChoice - 1, newCorrectAnswer)) {
                cout << "Question true answer changed successfully.\n";
                saveQuizzes();
            }
            else {
                cout << "Failed to change question true answer.\n";
            }
        }
        else if (questionChoice != 0) {
            cout << "Invalid choice.\n";
        }
    }
    else if (choice != 0) {
        cout << "Invalid choice.\n";
    }
}
