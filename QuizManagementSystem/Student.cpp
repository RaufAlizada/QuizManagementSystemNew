#include "Student.h"
#include <string>
#include <vector>
#include "QuizManager.h"
using namespace std;

double Student::getCorrectAnswers() const { return (correctAnswers / 10); }

double Student::getIncorrectAnswers() const { return (incorrentAnswers / 10); }

double Student::getUnansweredQuestions() const { return unansweredQuestions; }

double Student::getPercentage() const { return percentage; }

