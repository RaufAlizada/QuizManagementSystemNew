//#include <iostream>
//#include <ctime>
//#include <string>
//#include <conio.h>
//#include "Admin.h"
//#include "User.h"
//#include "Question.h"
//#include "Quiz.h"
//#include "QuizManager.h"
//#include "OwnException.h"
//
////#include "LoadingScreen.h"
//
//using namespace std;
//
//void HomeMenu(int currentOption) {
//    cout << (currentOption == 1 ? "> " : "  ") << "ADMIN" << endl;
//    cout << (currentOption == 2 ? "> " : "  ") << "STUDENT" << endl;
//    cout << (currentOption == 3 ? "> " : "  ") << "EXIT" << endl;
//}
//
//void AdminMenu(int currentOption) {
//    cout << (currentOption == 1 ? "> " : "  ") << "ADD QUIZ" << endl;
//    cout << (currentOption == 2 ? "> " : "  ") << "DELETE QUIZ" << endl;
//    cout << (currentOption == 3 ? "> " : "  ") << "CHANGE QUIZ NAME" << endl;
//    cout << (currentOption == 4 ? "> " : "  ") << "CHANGE QUIZ QUESTIONS" << endl;
//    cout << (currentOption == 5 ? "> " : "  ") << "CHANGE QUIZ QUESTIONS ANSWERS" << endl;
//    cout << (currentOption == 6 ? "> " : "  ") << "CHANGE QUIZ QUESTIONS TRUE ANSWERS" << endl;
//    cout << (currentOption == 7 ? "> " : "  ") << "ADD STUDENT" << endl;
//    cout << (currentOption == 8 ? "> " : "  ") << "DELETE STUDENT" << endl;
//    cout << (currentOption == 9 ? "> " : "  ") << "CHANGE STUDENT" << endl;
//    cout << (currentOption == 10 ? "> " : "  ") << "CHANGE ADMIN PASSWORD" << endl;
//    cout << (currentOption == 11 ? "> " : "  ") << "EXIT" << endl;
//}
//
//void StudentMenu(int currentOption) {
//    cout << (currentOption == 1 ? "> " : "  ") << "START QUIZ" << endl;
//    cout << (currentOption == 2 ? "> " : "  ") << "CONTINUE QUIZ" << endl;
//    cout << (currentOption == 3 ? "> " : "  ") << "SHOW YOUR STATISTICS" << endl;
//    cout << (currentOption == 4 ? "> " : "  ") << "EXIT" << endl;
//}
//
//void ChangeQuizMenu(int currentOption) {
//    cout << (currentOption == 1 ? "> " : "  ") << "CHANGE QUIZ TEXT" << endl;
//    cout << (currentOption == 2 ? "> " : "  ") << "CHANGE QUESTION TEXT" << endl;
//    cout << (currentOption == 3 ? "> " : "  ") << "CHANGE ANSWER VARIANTS" << endl;
//    cout << (currentOption == 4 ? "> " : "  ") << "CHANGE TRUE ANSWER" << endl;
//}
//
//void ChangeStudentInfoMenu(int currentOption) {
//    cout << (currentOption == 1 ? "> " : "  ") << "CHANGE STUDENT NAME" << endl;
//    cout << (currentOption == 2 ? "> " : "  ") << "CHANGE STUDENT SURNAME" << endl;
//    cout << (currentOption == 3 ? "> " : "  ") << "CHANGE STUDENT PASSWORD" << endl;
//}
//
//void QuizMenu(int currentOption) {
//    cout << (currentOption == 1 ? "> " : "  ") << "Add New Question" << endl;
//    cout << (currentOption == 2 ? "> " : "  ") << "Submit Test" << endl;
//    cout << (currentOption == 3 ? "> " : "  ") << "Previous" << endl;
//    cout << (currentOption == 4 ? "> " : "  ") << "Exit" << endl;
//    cout << (currentOption == 5 ? "> " : "  ") << "Cancel" << endl;
//}
//
//Admin admin;
//QuizManager quizManager;
//quizManager.loadQuizzes();
//
//bool check = true;
//int currentOption = 1;
//int action;
//std::string quizName;
//std::string questionText;
//std::vector<std::string> options;
//char correctAnswer;
//bool running = true;
//
//while (check) {
//    system("cls");
//    HomeMenu(currentOption);
//    char key = _getch();
//
//    if (key == 72) { // Yuxari ox isaresi
//        currentOption = (currentOption - 1 < 1) ? 3 : currentOption - 1;
//    }
//    else if (key == 80) { // Asagi ox isaresi
//        currentOption = (currentOption + 1 > 3) ? 1 : currentOption + 1;
//    }
//    else if (key == 13) {
//        system("cls");
//
//        // ---------------------------- ADMIN ----------------------------
//
//        if (currentOption == 1) {
//            bool check1 = true;
//            int currentOption1 = 1;
//            while (check1) {
//                system("cls");
//                AdminMenu(currentOption1);
//                char key1 = _getch();
//                if (key1 == 72) { // Yuxari ox isaresi
//                    currentOption1 = (currentOption1 - 1 < 1) ? 11 : currentOption1 - 1;
//                }
//                else if (key1 == 80) { // Asagi ox isaresi
//                    currentOption1 = (currentOption1 + 1 > 11) ? 1 : currentOption1 + 1;
//                }
//                else if (key1 == 13) {
//                    system("cls");
//                    if (currentOption1 == 11)
//                        break;
//                    if (currentOption1 == 1) {
//                        std::cout << "Enter the name of the quiz: ";
//                        std::getline(std::cin, quizName);
//                        Quiz newQuiz;
//                        newQuiz.setName(quizName);
//
//                        bool addingQuestions = true;
//                        while (addingQuestions) {
//                            std::cout << "Enter the question text: ";
//                            std::getline(std::cin, questionText);
//                            options.clear();
//                            for (int i = 0; i < 4; ++i) {
//                                std::string option;
//                                std::cout << "Enter answer option " << char('A' + i) << ": ";
//                                std::getline(std::cin, option);
//                                options.push_back(option);
//                            }
//                            std::cout << "Enter the correct answer (A, B, C, or D): ";
//                            std::cin >> correctAnswer;
//                            std::cin.ignore();
//
//                            Question newQuestion;
//                            newQuestion.setQuestion(questionText, options, correctAnswer);
//                            newQuiz.addQuestion(newQuestion);
//
//                            std::cout << "1. Submit Quiz\n";
//                            std::cout << "2. Add New Question\n";
//                            std::cout << "3. Exit from Quiz Adding\n";
//                            std::cout << "Enter your choice: ";
//                            int choice;
//                            std::cin >> choice;
//                            std::cin.ignore();
//
//                            switch (choice) {
//                            case 1:
//                                if (quizManager.addQuiz(newQuiz)) {
//                                    std::cout << "Quiz added.\n";
//                                    quizManager.saveQuizzes();
//                                }
//                                else {
//                                    std::cout << "Cannot add quiz.\n";
//                                }
//                                addingQuestions = false;
//                                break;
//                            case 2:
//                                // Continue adding questions
//                                break;
//                            case 3:
//                                addingQuestions = false;
//                                break;
//                            default:
//                                std::cout << "Wrong choice! Please try again.\n";
//                                break;
//                            }
//                        }
//                        break;
//                    }
//                    else if (currentOption1 == 2) {
//                        string quizName;
//                        cout << "Enter the name of the quiz to delete: ";
//                        getline(cin, quizName);
//                        if (quizManager.removeQuiz(quizName)) {
//                            cout << "Quiz deleted successfully.\n";
//                        }
//                        else {
//                            cout << "Quiz not found.\n";
//                        }
//                        system("pause");
//                    }
//                    else if (currentOption1 == 3) {         // CHANGE QUIZ
//                        /*string oldQuizName, newQuizName;
//                        cout << "Enter the name of the quiz to change: ";
//                        getline(cin, oldQuizName);
//                        cout << "Enter the new name for the quiz: ";
//                        getline(cin, newQuizName);
//                        if (quizManager.changeQuizName(oldQuizName, newQuizName)) {
//                            cout << "Quiz name changed successfully.\n";
//                        }
//                        else {
//                            cout << "Quiz not found.\n";
//                        }
//                        system("pause");*/
//                    }
//                    else if (currentOption1 == 4) {
//                        string studentName, studentSurname, studentAge, studentUsername, studentPassword;
//                        cout << "Enter student's name: ";
//                        getline(cin, studentName);
//                        cout << "Enter student's surname: ";
//                        getline(cin, studentSurname);
//                        cout << "Enter student's age: ";
//                        getline(cin, studentAge);
//                        cout << "Enter student's username: ";
//                        getline(cin, studentUsername);
//                        cout << "Enter student's password: ";
//                        getline(cin, studentPassword);
//
//                        if (admin.addStudent(studentName, studentSurname, studentAge, studentUsername, studentPassword)) {
//                            cout << "Student added successfully.\n";
//                        }
//                        else {
//                            cout << "Error adding student.\n";
//                        }
//                        system("pause");
//                    }
//                    else if (currentOption1 == 5) {
//                        string studentUsername;
//                        cout << "Enter student's username to delete: ";
//                        getline(cin, studentUsername);
//                        if (admin.deleteStudent(studentUsername)) {
//                            cout << "Student deleted successfully.\n";
//                        }
//                        else {
//                            cout << "Error deleting student.\n";
//                        }
//                        system("pause");
//                    }
//                    else if (currentOption1 == 6) {
//                        string studentUsername, newName, newSurname, newPassword;
//                        cout << "Enter student's username to change: ";
//                        getline(cin, studentUsername);
//                        cout << "Enter new name for the student (leave empty to keep current name): ";
//                        getline(cin, newName);
//                        cout << "Enter new surname for the student (leave empty to keep current surname): ";
//                        getline(cin, newSurname);
//                        cout << "Enter new password for the student (leave empty to keep current password): ";
//                        getline(cin, newPassword);
//
//                        if (admin.changeStudentInfo(studentUsername, newName, newSurname, newPassword)) {
//                            cout << "Student information changed successfully.\n";
//                        }
//                        else {
//                            cout << "Error changing student information.\n";
//                        }
//                        system("pause");
//                    }
//                }
//            }
//        }
//
//        // ---------------------------- STUDENT ----------------------------
//
//        else if (currentOption == 2) {
//
//            bool check1 = true;
//            int currentOption1 = 1;
//            while (check1) {
//
//                system("cls");
//                StudentMenu(currentOption1);
//                char key1 = _getch();
//
//                if (key1 == 72) { // Yuxari ox isaresi
//                    currentOption1 = (currentOption1 - 1 < 1) ? 4 : currentOption1 - 1;
//                }
//                else if (key1 == 80) { // Asagi ox isaresi
//                    currentOption1 = (currentOption1 + 1 > 4) ? 1 : currentOption1 + 1;
//                }
//                else if (key1 == 13) {
//                    system("pause");
//                    break;
//                }
//            }
//        }
//
//        // ---------------------------- EXIT ----------------------------
//
//        else if (currentOption == 3) {
//            break;
//        }
//    }
//}


// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================


//void addQuestionsToQuiz(Quiz& quiz) {
//    char option;
//    do {
//        cout << "Choose an option:\n";
//        cout << "1. Add New Question\n";
//        cout << "2. Submit\n";
//        cout << "3. Exit\n";
//        cin >> option;
//        cin.ignore(); // To consume the newline character
//
//        switch (option) {
//        case '1': {
//            string questionText;
//            vector<string> options;
//            char correctAnswer;
//            cout << "Enter the question text: ";
//            getline(cin, questionText);
//
//            for (int i = 0; i < 4; ++i) {
//                string option;
//                cout << "Enter option " << char('a' + i) << ": ";
//                getline(cin, option);
//                options.push_back(option);
//            }
//
//            cout << "Enter the correct answer (a, b, c, or d): ";
//            cin >> correctAnswer;
//            cin.ignore(); // To consume the newline character
//
//            Question newQuestion;
//            newQuestion.setQuestion(questionText, options, correctAnswer);
//            quiz.addQuestion(newQuestion);
//            break;
//        }
//        case '2': {
//            // Quiz submission logic here
//            cout << "Quiz submitted successfully.\n";
//            return;
//        }
//        case '3': {
//            cout << "Exiting...\n";
//            return;
//        }
//        default: {
//            cout << "Invalid option. Please try again.\n";
//            break;
//        }
//        }
//    } while (true);
//}
//
//void addQuizAndQuestions(QuizManager& quizManager) {
//    string quizName;
//    cout << "Enter the name of the quiz to add: ";
//    getline(cin, quizName);
//    Quiz newQuiz;
//    newQuiz.setName(quizName);
//
//    addQuestionsToQuiz(newQuiz);
//
//    if (quizManager.addQuiz(newQuiz)) {
//        cout << "Quiz added successfully.\n";
//    }
//    else {
//        cout << "Quiz already exists.\n";
//    }
//}