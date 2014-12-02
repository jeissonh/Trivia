#include "Question.h"

Question::Question()
{
}

QTextStream& Question::load(QTextStream& in, bool removeEmptyLine)
{
	text = in.readLine();
	answer = in.readLine();

	// Ignore the empty line
	if ( removeEmptyLine )
		in.readLine();

	return in;
}
