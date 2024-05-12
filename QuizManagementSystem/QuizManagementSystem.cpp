#include <iostream>
#include <ctime>
#include <string>
#include <conio.h>
#include <windows.h>

#include "Admin.h"
#include "User.h"
#include "Question.h"
#include "Quiz.h"
#include "QuizManager.h"
//#include "OwnException.h"
#include "Student.h"

//#include "LoadingScreen.h"

using namespace std;

void printQuiz(const Quiz& quiz);
void HomeMenu(int currentOption);
void AdminMenu(int currentOption);
void StudentMenu(int currentOption);
void ChangeQuizMenu(int currentOption);
void QuizMenu(int currentOption);

void AnimationText();

void ChangeQuizName(QuizManager& quizManager);
void ChangeQuizQuestions(QuizManager& quizManager);
void ChangeQuizQuestionsAnswers(QuizManager& quizManager);
void ChangeQuizQuestionsTrueAnswers(QuizManager& quizManager);
void ChangeTrueAnswer(QuizManager& quizManager);

int main() {
    Admin admin;
    QuizManager quizManager;
    quizManager.loadQuizzes();

    bool check = true;
    int currentOption = 1;
    int action;
    std::string quizName;
    std::string questionText;
    std::vector<std::string> options;
    char correctAnswer;
    bool running = true;

    while (check) {
        system("cls");
        HomeMenu(currentOption);
        char key = _getch();

        if (key == 72) {
            currentOption = (currentOption - 1 < 1) ? 5 : currentOption - 1;
        }
        else if (key == 80) {
            currentOption = (currentOption + 1 > 5) ? 1 : currentOption + 1;
        }
        else if (key == 13) {
            system("cls");

            // ---------------------------- ADMIN ----------------------------

            if (currentOption == 1) {
                bool check1 = true;
                int currentOption1 = 1;
                while (check1) {
                    system("cls");
                    AdminMenu(currentOption1);
                    char key1 = _getch();
                    if (key1 == 72) {
                        currentOption1 = (currentOption1 - 1 < 1) ? 11 : currentOption1 - 1;
                    }
                    else if (key1 == 80) {
                        currentOption1 = (currentOption1 + 1 > 11) ? 1 : currentOption1 + 1;
                    }
                    else if (key1 == 13) {
                        system("cls");
                        if (currentOption1 == 1) {
                            std::cout << "Enter the name of the quiz: ";
                            std::getline(std::cin, quizName);
                            Quiz newQuiz;
                            newQuiz.setName(quizName);

                            bool addingQuestions = true;
                            while (addingQuestions) {
                                std::cout << "Enter the question text: ";
                                std::getline(std::cin, questionText);
                                options.clear();
                                for (int i = 0; i < 4; ++i) {
                                    std::string option;
                                    std::cout << "Enter answer option " << char('A' + i) << ": ";
                                    std::getline(std::cin, option);
                                    options.push_back(option);
                                }
                                std::cout << "Enter the correct answer (A, B, C, or D): ";
                                std::cin >> correctAnswer;
                                std::cin.ignore();

                                Question newQuestion;
                                newQuestion.setQuestion(questionText, options, correctAnswer);
                                newQuiz.addQuestion(newQuestion);

                                std::cout << "1. Submit Quiz\n";
                                std::cout << "2. Add New Question\n";
                                std::cout << "3. Exit from Quiz Adding\n";
                                std::cout << "Enter your choice: ";
                                int choice;
                                std::cin >> choice;
                                std::cin.ignore();

                                switch (choice) {
                                case 1:
                                    if (quizManager.addQuiz(newQuiz)) {
                                        std::cout << "Quiz added.\n";
                                        quizManager.saveQuizzes();
                                    }
                                    else {
                                        std::cout << "Cannot add quiz.\n";
                                    }
                                    addingQuestions = false;
                                    break;
                                case 2:
                                    // Continue adding questions
                                    break;
                                case 3:
                                    addingQuestions = false;
                                    break;
                                default:
                                    std::cout << "Wrong choice! Please try again.\n";
                                    break;
                                }
                            }
                            break;
                        }
                        else if (currentOption1 == 2) {
                            string quizName;
                            cout << "Enter the name of the quiz to delete: ";
                            getline(cin, quizName);
                            if (quizManager.removeQuiz(quizName)) {
                                cout << "Quiz deleted successfully.\n";
                                quizManager.saveQuizzes();
                            }
                            else {
                                cout << "Quiz not found.\n";
                            }
                            system("pause");
                        }
                        else if (currentOption1 == 3) {
                            ChangeQuizName(quizManager);
                        }
                        else if (currentOption1 == 4) {
                            // LEAVE BLANK
                        }
                        else if (currentOption1 == 5) {
                            // LEAVE BLANK
                        }
                        else if (currentOption1 == 6) {
                            //ChangeTrueAnswer(quizManager);
                        }
                        else if (currentOption1 == 7) {
                            string studentName, studentSurname, studentAge, studentUsername, studentPassword;
                            cout << "Enter student's name: ";
                            getline(cin, studentName);
                            cout << "Enter student's surname: ";
                            getline(cin, studentSurname);
                            cout << "Enter student's age: ";
                            getline(cin, studentAge);
                            cout << "Enter student's username: ";
                            getline(cin, studentUsername);
                            cout << "Enter student's password: ";
                            getline(cin, studentPassword);

                            if (admin.addStudent(studentName, studentSurname, studentAge, studentUsername, studentPassword)) {
                                cout << "Student added successfully.\n";
                            }
                            else {
                                cout << "Error adding student.\n";
                            }
                            system("pause");
                        }
                        else if (currentOption1 == 8) {
                            string studentUsername;
                            cout << "Enter student's username to delete: ";
                            getline(cin, studentUsername);
                            if (admin.deleteStudent(studentUsername)) {
                                cout << "Student deleted successfully.\n";
                            }
                            else {
                                cout << "Error deleting student.\n";
                            }
                            system("pause");
                        }
                        else if (currentOption1 == 9) {
                            int choice;
                            string studentUsername, newName, newSurname, newPassword, newAgeStr;
                            int newAge;

                            cout << "1. Change student's name\n";
                            cout << "2. Change student's surname\n";
                            cout << "3. Change student's password\n";
                            cout << "4. Change student's age\n";
                            cout << "Enter your choice: ";
                            cin >> choice;
                            cin.ignore(); // Clear the newline character from the input buffer

                            switch (choice) {
                            case 1:
                                cout << "Enter student's username: ";
                                getline(cin, studentUsername);
                                cout << "Enter new name for the student: ";
                                getline(cin, newName);
                                if (admin.changeStudentInfo(studentUsername, newName, "", ""))
                                    cout << "Student name changed successfully.\n";
                                else
                                    cout << "Error changing student name.\n";
                                break;
                            case 2:
                                cout << "Enter student's username: ";
                                getline(cin, studentUsername);
                                cout << "Enter new surname for the student: ";
                                getline(cin, newSurname);
                                if (admin.changeStudentInfo(studentUsername, "", newSurname, ""))
                                    cout << "Student surname changed successfully.\n";
                                else
                                    cout << "Error changing student surname.\n";
                                break;
                            case 3:
                                cout << "Enter student's username: ";
                                getline(cin, studentUsername);
                                cout << "Enter new password for the student: ";
                                getline(cin, newPassword);
                                if (admin.changeStudentInfo(studentUsername, "", "", newPassword))
                                    cout << "Student password changed successfully.\n";
                                else
                                    cout << "Error changing student password.\n";
                                break;
                            case 4:
                                cout << "Enter student's username: ";
                                getline(cin, studentUsername);
                                cout << "Enter new age for the student: ";
                                getline(cin, newAgeStr);
                                newAge = stoi(newAgeStr); // Convert string to integer
                                if (admin.changeStudentAge(studentUsername, newAge))
                                    cout << "Student age changed successfully.\n";
                                else
                                    cout << "Error changing student age.\n";
                                break;
                            default:
                                cout << "Invalid choice.\n";
                            }
                            system("pause");
                        }
                        else if (currentOption1 == 10) {
                            // LEAVE BLANK
                        }
                        else if (currentOption1 == 11)
                            break;
                    }
                }
            }

            // ---------------------------- STUDENT ----------------------------

            else if (currentOption == 2) {

                bool check1 = true;
                int currentOption1 = 1;
                while (check1) {

                    system("cls");
                    StudentMenu(currentOption1);
                    char key1 = _getch();

                    if (key1 == 72) {
                        currentOption1 = (currentOption1 - 1 < 1) ? 4 : currentOption1 - 1;
                    }
                    else if (key1 == 80) {
                        currentOption1 = (currentOption1 + 1 > 4) ? 1 : currentOption1 + 1;
                    }
                    else if (key1 == 13) {
                        if (currentOption1 == 1) {
                            //startQuiz(quizManager);
                        }
                        else if (currentOption1 == 4) {
                            break;
                        }
                    }
                }
            }

            // ---------------------------- ABOUT US ----------------------------

            else if (currentOption == 3) {
                AnimationText();
            }

            // ---------------------------- MORE PROJECTS ----------------------------

            else if (currentOption == 4) {
                system("start https://github.com/RaufAlizada");
            }

            // ---------------------------- EXIT ----------------------------

            else if (currentOption == 5) {
                break;
            }
        }
    }
}

// --------------------------------------> FUNCTIONS <--------------------------------------

void printQuiz(const Quiz& quiz) {
    cout << "Quiz Name: " << quiz.getName() << endl;
    int questionCount = 1;
    for (const auto& question : quiz.getQuestions()) {
        cout << "Question " << questionCount++ << ": " << endl;
        cout << "Question Text: " << question.getText() << endl;
        cout << "Options: " << endl;
        for (int i = 0; i < question.getOptions().size(); ++i) {
            cout << static_cast<char>('A' + i) << ". " << question.getOptions()[i] << endl;
        }
        cout << "Correct Answer: " << question.getCorrectAnswer() << endl;
        cout << "-----------------------------" << endl;
    }
}

void HomeMenu(int currentOption) {
    cout << (currentOption == 1 ? "> " : "  ") << "ADMIN" << endl;
    cout << (currentOption == 2 ? "> " : "  ") << "STUDENT" << endl;
    cout << (currentOption == 3 ? "> " : "  ") << "ABOUT US" << endl;
    cout << (currentOption == 4 ? "> " : "  ") << "MORE PROJECTS" << endl;
    cout << (currentOption == 5 ? "> " : "  ") << "EXIT" << endl;
}

void AdminMenu(int currentOption) {
    cout << (currentOption == 1 ? "> " : "  ") << "ADD QUIZ" << endl;
    cout << (currentOption == 2 ? "> " : "  ") << "DELETE QUIZ" << endl;
    cout << (currentOption == 3 ? "> " : "  ") << "CHANGE QUIZ NAME" << endl;
    cout << (currentOption == 4 ? "> " : "  ") << "CHANGE QUIZ QUESTIONS" << endl;
    cout << (currentOption == 5 ? "> " : "  ") << "CHANGE QUIZ QUESTIONS ANSWERS" << endl;
    cout << (currentOption == 6 ? "> " : "  ") << "CHANGE QUIZ QUESTIONS TRUE ANSWERS" << endl;
    cout << (currentOption == 7 ? "> " : "  ") << "ADD STUDENT" << endl;
    cout << (currentOption == 8 ? "> " : "  ") << "DELETE STUDENT" << endl;
    cout << (currentOption == 9 ? "> " : "  ") << "CHANGE STUDENT" << endl;
    cout << (currentOption == 10 ? "> " : "  ") << "CHANGE ADMIN PASSWORD" << endl;
    cout << (currentOption == 11 ? "> " : "  ") << "EXIT" << endl;
}

void StudentMenu(int currentOption) {
    cout << (currentOption == 1 ? "> " : "  ") << "START QUIZ" << endl;
    cout << (currentOption == 2 ? "> " : "  ") << "CONTINUE QUIZ" << endl;
    cout << (currentOption == 3 ? "> " : "  ") << "SHOW YOUR STATISTICS" << endl;
    cout << (currentOption == 4 ? "> " : "  ") << "EXIT" << endl;
}

void ChangeQuizMenu(int currentOption) {
    cout << (currentOption == 1 ? "> " : "  ") << "CHANGE QUIZ TEXT" << endl;
    cout << (currentOption == 2 ? "> " : "  ") << "CHANGE QUESTION TEXT" << endl;
    cout << (currentOption == 3 ? "> " : "  ") << "CHANGE ANSWER VARIANTS" << endl;
    cout << (currentOption == 4 ? "> " : "  ") << "CHANGE TRUE ANSWER" << endl;
}

void ChangeStudentInfoMenu(int currentOption) {
    cout << (currentOption == 1 ? "> " : "  ") << "CHANGE STUDENT NAME" << endl;
    cout << (currentOption == 2 ? "> " : "  ") << "CHANGE STUDENT SURNAME" << endl;
    cout << (currentOption == 3 ? "> " : "  ") << "CHANGE STUDENT PASSWORD" << endl;
}

void QuizMenu(int currentOption) {
    cout << (currentOption == 1 ? "> " : "  ") << "Add New Question" << endl;
    cout << (currentOption == 2 ? "> " : "  ") << "Submit Test" << endl;
    cout << (currentOption == 3 ? "> " : "  ") << "Previous" << endl;
    cout << (currentOption == 4 ? "> " : "  ") << "Exit" << endl;
    cout << (currentOption == 5 ? "> " : "  ") << "Cancel" << endl;
}

void AnimationText()
{
    string text = "\033[1;33mWARNING: PLEASE DON'T WANT TO BREAK MY CODE\n\032Welcome! This Console App created by _ralizada\nQuiz Management System Exam Project is a useful programme for teachers and students\nThe programme created with C++ Object Oriented Programming\nFor seeing my other projects, visit RaufAlizada account in github\nThanks for using my programme!!!\033[0m";
    int x = 0;
    while (text[x] != '\0')
    {
        cout << text[x];
        Sleep(50);
        x++;
    };
    cout << endl;
    cout << endl;
    system("pause");
}

// --------------------------------------> QUIZ FUNCTIONS <--------------------------------------

void ChangeQuizName(QuizManager& quizManager) {
    system("cls");
    cout << "Available quizzes:\n";
    vector<string> quizNames = quizManager.getQuizNames();
    for (int i = 0; i < quizNames.size(); ++i) {
        cout << i + 1 << ". " << quizNames[i] << endl;
    }
    cout << "Enter the number of the quiz to change its name (or 0 to go back): ";
    int choice;
    cin >> choice;
    cin.ignore();
    if (choice >= 1 && choice <= quizNames.size()) {
        string newName;
        cout << "Enter the new name for the quiz: ";
        getline(cin, newName);
        if (quizManager.changeQuizName(quizNames[choice - 1], newName)) {
            cout << "Quiz name changed successfully.\n";
            quizManager.saveQuizzes();
        }
        else {
            cout << "Failed to change quiz name.\n";
        }
    }
    else if (choice != 0) {
        cout << "Invalid choice.\n";
    }
}

//void ChangeTrueAnswer(QuizManager& quizManager) {
//    system("cls");
//    cout << "Available quizzes:\n";
//    vector<string> quizNames = quizManager.getQuizNames();
//
//    // Quiz seçimi
//    int quizChoice;
//    do {
//        cout << "Enter the number of the quiz to change its true answer (or 0 to go back): ";
//        cin >> quizChoice;
//        cin.ignore();
//        if (quizChoice < 0 || quizChoice > quizNames.size()) {
//            cout << "Invalid choice. Please enter a number between 0 and " << quizNames.size() << ".\n";
//        }
//    } while (quizChoice < 0 || quizChoice > quizNames.size());
//
//    if (quizChoice == 0) return; // Geri dön
//
//    // Soru seçimi
//    vector<string> questionTexts = quizManager.getQuestionTexts(quizChoice - 1);
//    system("cls");
//    cout << "Available questions for quiz " << quizNames[quizChoice - 1] << ":\n";
//    for (int i = 0; i < questionTexts.size(); ++i) {
//        cout << i + 1 << ". " << questionTexts[i] << endl;
//    }
//
//    int questionChoice;
//    do {
//        cout << "Enter the number of the question to change its true answer (or 0 to go back): ";
//        cin >> questionChoice;
//        cin.ignore();
//        if (questionChoice < 0 || questionChoice > questionTexts.size()) {
//            cout << "Invalid choice. Please enter a number between 0 and " << questionTexts.size() << ".\n";
//        }
//    } while (questionChoice < 0 || questionChoice > questionTexts.size());
//
//    if (questionChoice == 0) return; // Geri dön
//
//    char newCorrectAnswer;
//    cout << "Enter the new correct answer for the question (A, B, C, or D): ";
//    cin >> newCorrectAnswer;
//    cin.ignore();
//
//    if (quizManager.changeTrueAnswer(quizChoice - 1, questionChoice - 1, newCorrectAnswer)) {
//        cout << "Question true answer changed successfully.\n";
//        quizManager.saveQuizzes();
//    }
//    else {
//        cout << "Failed to change question true answer.\n";
//    }
//}


// ======================================================================================================================================================================

//void ChangeQuizQuestions(QuizManager& quizManager) {
//    system("cls");
//    cout << "Available quizzes:\n";
//    vector<string> quizNames = quizManager.getQuizNames();
//    for (int i = 0; i < quizNames.size(); ++i) {
//        cout << i + 1 << ". " << quizNames[i] << endl;
//    }
//    cout << "Enter the number of the quiz to change its questions (or 0 to go back): ";
//    int choice;
//    cin >> choice;
//    cin.ignore();
//    if (choice >= 1 && choice <= quizNames.size()) {
//        vector<string> questionTexts = quizManager.getQuestionTexts(choice - 1);
//        system("cls");
//        cout << "Available questions for quiz " << quizNames[choice - 1] << ":\n";
//        for (int i = 0; i < questionTexts.size(); ++i) {
//            cout << i + 1 << ". " << questionTexts[i] << endl;
//        }
//        cout << "Enter the number of the question to change its text (or 0 to go back): ";
//        int questionChoice;
//        cin >> questionChoice;
//        cin.ignore();
//        if (questionChoice >= 1 && questionChoice <= questionTexts.size()) {
//            string newQuestionText;
//            cout << "Enter the new text for the question: ";
//            getline(cin, newQuestionText);
//            if (quizManager.changeQuestions(choice - 1, questionChoice - 1, newQuestionText)) {
//                cout << "Question text changed successfully.\n";
//                quizManager.saveQuizzes();
//            }
//            else {
//                cout << "Failed to change question text.\n";
//            }
//        }
//        else if (questionChoice != 0) {
//            cout << "Invalid choice.\n";
//        }
//    }
//    else if (choice != 0) {
//        cout << "Invalid choice.\n";
//    }
//}
//
//void ChangeQuizQuestionsAnswers(QuizManager& quizManager) {
//    system("cls");
//    cout << "Available quizzes:\n";
//    vector<string> quizNames = quizManager.getQuizNames();
//    for (int i = 0; i < quizNames.size(); ++i) {
//        cout << i + 1 << ". " << quizNames[i] << endl;
//    }
//    cout << "Enter the number of the quiz to change its questions' answers (or 0 to go back): ";
//    int choice;
//    cin >> choice;
//    cin.ignore();
//    if (choice >= 1 && choice <= quizNames.size()) {
//        vector<string> questionTexts = quizManager.getQuestionTexts(choice - 1);
//        system("cls");
//        cout << "Available questions for quiz " << quizNames[choice - 1] << ":\n";
//        for (int i = 0; i < questionTexts.size(); ++i) {
//            cout << i + 1 << ". " << questionTexts[i] << endl;
//        }
//        cout << "Enter the number of the question to change its answers (or 0 to go back): ";
//        int questionChoice;
//        cin >> questionChoice;
//        cin.ignore();
//        if (questionChoice >= 1 && questionChoice <= questionTexts.size()) {
//            vector<string> newOptions;
//            cout << "Enter the new options for the question:\n";
//            for (int i = 0; i < 4; ++i) {
//                string option;
//                cout << static_cast<char>('A' + i) << ". ";
//                getline(cin, option);
//                newOptions.push_back(option);
//            }
//            if (quizManager.changeAnswers(choice - 1, questionChoice - 1, newOptions)) {
//                cout << "Question answers changed successfully.\n";
//                quizManager.saveQuizzes();
//            }
//            else {
//                cout << "Failed to change question answers.\n";
//            }
//        }
//        else if (questionChoice != 0) {
//            cout << "Invalid choice.\n";
//        }
//    }
//    else if (choice != 0) {
//        cout << "Invalid choice.\n";
//    }
//}
//
//void ChangeQuizQuestionsTrueAnswers(QuizManager& quizManager) {
//    system("cls");
//    cout << "Available quizzes:\n";
//    vector<string> quizNames = quizManager.getQuizNames();
//    for (int i = 0; i < quizNames.size(); ++i) {
//        cout << i + 1 << ". " << quizNames[i] << endl;
//    }
//    cout << "Enter the number of the quiz to change its questions' true answers (or 0 to go back): ";
//    int choice;
//    cin >> choice;
//    cin.ignore();
//    if (choice >= 1 && choice <= quizNames.size()) {
//        vector<string> questionTexts = quizManager.getQuestionTexts(choice - 1);
//        system("cls");
//        cout << "Available questions for quiz " << quizNames[choice - 1] << ":\n";
//        for (int i = 0; i < questionTexts.size(); ++i) {
//            cout << i + 1 << ". " << questionTexts[i] << endl;
//        }
//        cout << "Enter the number of the question to change its true answer (or 0 to go back): ";
//        int questionChoice;
//        cin >> questionChoice;
//        cin.ignore();
//        if (questionChoice >= 1 && questionChoice <= questionTexts.size()) {
//            char newCorrectAnswer;
//            cout << "Enter the new correct answer for the question: ";
//            cin >> newCorrectAnswer;
//            cin.ignore();
//            if (quizManager.changeTrueAnswer(choice - 1, questionChoice - 1, newCorrectAnswer)) {
//                cout << "Question true answer changed successfully.\n";
//                quizManager.saveQuizzes();
//            }
//            else {
//                cout << "Failed to change question true answer.\n";
//            }
//        }
//        else if (questionChoice != 0) {
//            cout << "Invalid choice.\n";
//        }
//    }
//    else if (choice != 0) {
//        cout << "Invalid choice.\n";
//    }
//}