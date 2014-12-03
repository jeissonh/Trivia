#include "TextualQuestion.h"

TextualQuestion::TextualQuestion()
{
}

bool TextualQuestion::ask()
{
	QTextStream cin(stdin), cout(stdout);
	cout << text << endl;
	cout << "Your answer: ";

	const QString& playerAnswer = cin.readLine().toLower();
	const QString& rightAnswer = this->answer.toLower();

	bool correct = playerAnswer == rightAnswer;
	if ( correct )
		cout << "Correct!\n";
	else
		cout << "The right answer is: " << answer << endl;
	return correct;
}

GraphicsQuestionItem* TextualQuestion::buildGraphicsQuestionItem()
{
	return new GraphicsTextualQuestionItem(this);
}
