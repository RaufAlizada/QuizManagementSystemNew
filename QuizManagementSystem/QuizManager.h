#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include "Quiz.h"

using namespace std;

class QuizManager
{
private:
	std::vector<Quiz> quizzes;
public:
	bool addQuiz(const Quiz& quiz);

	bool removeQuiz(const string& quizName);

	bool saveQuizzes() const;

	void loadQuizzes();

	bool changeQuizName(const string& oldName, const string& newName);

	//bool changeQuestions(int quizIndex, int questionIndex, const std::string& newQuestionText);

	//bool changeAnswers(int quizIndex, int questionIndex, const std::vector<std::string>& newOptions);

	//bool changeTrueAnswer(int quizIndex, int questionIndex, char newCorrectAnswer);

	vector<string> getQuizNames() const;
	vector<string> getQuestionTexts(int quizIndex) const;

	std::vector<Quiz> getQuizzes() const { return quizzes; }

	//void ChangeQuizQuestions(QuizManager& quizManager);
	//void ChangeQuizQuestionsAnswers(QuizManager& quizManager);
	//void ChangeQuizQuestionsTrueAnswers(QuizManager& quizManager);

	Quiz getQuiz(int index) const;
};