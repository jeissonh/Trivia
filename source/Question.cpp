#include "Question.h"

Question::Question()
{
}

std::istream& Question::load(std::istream& in, bool removeEmptyLine)
{
	std::getline(in, text);
	std::getline(in, answer);

	// Ignore the empty line
	if ( removeEmptyLine )
	{
		std::string dummy;
		return std::getline(in, dummy);
	}
	return in;
}
