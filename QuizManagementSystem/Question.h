#pragma once
#include <string>
#include <vector>
using namespace std;

class Question
{
private:
	string text;
	vector<string>options;
	char correctAnswer;
public:
	Question() {}

	void setQuestion(const string& questionText, const vector<string>& optns, char correct);

	string getText() const;
	
	vector<string>getOptions() const;

	char getCorrectAnswer() const;
};

