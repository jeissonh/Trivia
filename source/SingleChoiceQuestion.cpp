#include "SingleChoiceQuestion.h"

SingleChoiceQuestion::SingleChoiceQuestion()
{
}

QTextStream& SingleChoiceQuestion::load(QTextStream& in, bool)
{
	Question::load(in, false);
	while ( ! in.atEnd() )
	{
		QString choice = in.readLine();
		if ( choice.length() == 0 ) break;
		choices.push_back(choice);
	}

	return in;
}

bool SingleChoiceQuestion::ask()
{
	QTextStream cin(stdin), cout(stdout);
	cout << text << endl;
	for (int i = 0; i < choices.size(); ++i)
		cout << i + 1 << ". " << choices[i] << endl;
	cout << "Your answer: ";

	int playerAnswer = cin.readLine().toInt();
	int rightAnswer = answer.toInt();

	bool correct = playerAnswer == rightAnswer;
	if ( correct )
		cout << "Correct!\n";
	else
		cout << "The right answer is: " << answer << endl;
	return correct;
}
