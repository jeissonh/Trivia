#include "SingleChoiceQuestion.h"

SingleChoiceQuestion::SingleChoiceQuestion()
{
}

std::istream& SingleChoiceQuestion::load(std::istream& in, bool)
{
	Question::load(in, false);
	std::string choice;
	while ( std::getline(in, choice) && choice.length() > 0 )
		choices.push_back(choice);

	return in;
}

bool SingleChoiceQuestion::ask()
{
	std::cout << text << std::endl;
	for (size_t i = 0; i < choices.size(); ++i)
		std::cout << i + 1 << ". " << choices[i] << std::endl;
	std::cout << "Your answer: ";

	size_t playerAnswer;
	std::cin >> playerAnswer;
	size_t rightAnswer = ::strtoull(this->answer.c_str(), nullptr, 10);
	// remove the enter character
	std::string dummy;
	std::getline( std::cin, dummy );

	bool correct = playerAnswer == rightAnswer;
	if ( correct )
		std::cout << "Correct!\n";
	else
		std::cout << "The right answer is: " << answer << std::endl;
	return correct;
}
