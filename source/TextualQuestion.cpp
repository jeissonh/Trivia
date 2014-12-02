#include "TextualQuestion.h"

TextualQuestion::TextualQuestion()
{
}

bool TextualQuestion::ask()
{
	std::cout << text << std::endl;
	std::cout << "Your answer: ";
	std::string playerAnswer;
	std::getline(std::cin, playerAnswer);

	std::string rightAnswer = this->answer;
	std::transform(rightAnswer.begin(), rightAnswer.end(), rightAnswer.begin(), ::tolower);
	std::transform(playerAnswer.begin(), playerAnswer.end(), playerAnswer.begin(), ::tolower);

	bool correct = playerAnswer == rightAnswer;
	if ( correct )
		std::cout << "Correct!\n";
	else
		std::cout << "The right answer is: " << answer << std::endl;
	return correct;
}
