#include "Question.h"


void Question::setQuestion(const string& questionText, const vector<string>& optns, char correct) {
	text = questionText;
	options = optns;
	correctAnswer = correct;
}

string Question::getText() const {
	return text;
}

vector<string> Question::getOptions() const {
	return options;
}

char Question::getCorrectAnswer() const {
	return correctAnswer;
}