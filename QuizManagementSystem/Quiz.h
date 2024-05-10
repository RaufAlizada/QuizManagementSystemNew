#pragma once
#include <string>
#include <vector>
#include "Question.h"

using namespace std;

class Quiz
{
private:
	string name;
	vector<Question> questions;
public:
	Quiz();

	void setName(const string& quizName);

	void addQuestion(const Question& question);

	string getName() const;

	vector<Question> getQuestions() const;

	void print() const;
	void printQuestions() const;
	void printAnswers() const;
	void printTrueAnswers() const;
};

