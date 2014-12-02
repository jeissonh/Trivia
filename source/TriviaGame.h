#ifndef TRIVIAGAME_H
#define TRIVIAGAME_H

#include "Question.h"
#include <vector>

class TriviaGame
{
  private:
	std::vector<Question*> questions;

  public:
	TriviaGame();
	~TriviaGame();
	int run(int argc, char* argv[]);

  private:
	bool loadQuestions();
	bool analyzeArguments(int argc, char* argv[]);
	int play();
	void printQuestions() const;
	Question*createQuestion(const std::string& type);
};

#endif // TRIVIAGAME_H
