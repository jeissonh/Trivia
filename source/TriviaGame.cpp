#include "TriviaGame.h"
#include <fstream>

TriviaGame::TriviaGame()
{
}

TriviaGame::~TriviaGame()
{
	for ( size_t i = 0; i < questions.size(); ++i )
		delete questions[i];
}

int TriviaGame::run(int argc, char* argv[])
{
	if ( ! analyzeArguments(argc, argv) )
		return 1;

	if ( loadQuestions() )
		return play();

	return 1;
}

bool TriviaGame::loadQuestions()
{
	const char* const sourceFilename = "trivia3.txt";
	std::ifstream source(sourceFilename);
	if ( ! source )
	{
		std::cerr << "trivia: could not open " << sourceFilename;
		return 1;
	}

	std::string type;
	while ( std::getline(source, type) )
	{
		Question* question = createQuestion(type);
		if ( ! question ) return false;
		source >> *question;
		questions.push_back( question );
	}

	source.close();
	return true;
}

bool TriviaGame::analyzeArguments(int argc, char* argv[])
{
	return true;
}

int TriviaGame::play()
{
	std::srand( std::time(nullptr) );
	size_t questionNumber = 0;
	while ( std::cin )
	{
		std::cout << std::endl << ++questionNumber << ". ";
		size_t index = rand() % questions.size();
		questions[index]->ask();
	}
	return 0;
}

void TriviaGame::printQuestions() const
{
	for ( size_t i = 0; i < questions.size(); ++i )
		std::cout << questions[i] << std::endl;
}


#include "NumericQuestion.h"
#include "TextualQuestion.h"
#include "SingleChoiceQuestion.h"
Question* TriviaGame::createQuestion(const std::string& type)
{
	if ( type == "numeric") return new NumericQuestion();
	if ( type == "textual") return new TextualQuestion();
	if ( type == "single_choice") return new SingleChoiceQuestion();
	return nullptr;
}
