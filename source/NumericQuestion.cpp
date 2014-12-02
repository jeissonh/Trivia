#include "NumericQuestion.h"

NumericQuestion::NumericQuestion()
{
}

bool NumericQuestion::ask()
{
	std::cout << text << std::endl;
	std::cout << "Your answer: ";

	double playerAnswer;
	std::cin >> playerAnswer;
	double rightAnswer = ::atof(this->answer.c_str());
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
