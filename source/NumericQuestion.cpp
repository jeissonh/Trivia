#include "NumericQuestion.h"

NumericQuestion::NumericQuestion()
{
}

bool NumericQuestion::ask()
{
	QTextStream cin(stdin), cout(stdout);
	cout << text << endl;
	cout << "Your answer: ";

	double playerAnswer = cin.readLine().toDouble();
	double rightAnswer = answer.toDouble();

	bool correct = playerAnswer == rightAnswer;
	if ( correct )
		cout << "Correct!\n";
	else
		cout << "The right answer is: " << answer << endl;
	return correct;
}

GraphicsQuestionItem* NumericQuestion::buildGraphicsQuestionItem()
{
	return new GraphicsNumericQuestionItem(this);
}
