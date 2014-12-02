#include "MainWindow.h"
#include "Question.h"
#include "TriviaGame.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>

TriviaGame::TriviaGame(int& argc, char* argv[])
	: QApplication(argc, argv)
	, mainWindow(nullptr)
	, validArguments(analyzeArguments(argc, argv))
{
}

TriviaGame::~TriviaGame()
{
	delete mainWindow;
	for ( int i = 0; i < questions.size(); ++i )
		delete questions[i];
}

int TriviaGame::run()
{
	if ( ! validArguments )
		return 1;

	if ( loadQuestions() )
		return play();

	return 1;
}

bool TriviaGame::loadQuestions()
{
	// Open trivia3.txt located in assets.qrc
	const QString sourceFilename(":/questions/trivia3.txt");
	QFile file(sourceFilename);
	if ( ! file.open(QIODevice::ReadOnly | QIODevice::Text) )
	{
		qDebug() << "trivia: could not open " << sourceFilename;
		return false;
	}

	// We can read lines from QFile directly, but QTextStream takes care of Unicode
	QTextStream source(&file);
	while ( ! source.atEnd() )
	{
		QString type = source.readLine();
		Question* question = createQuestion(type);
		if ( ! question ) return false;
		source >> *question;
		questions.push_back( question );
	}

	file.close();
	printQuestions();
	return true;
}

bool TriviaGame::analyzeArguments(int /*argc*/, char* /*argv*/[])
{
	return true;
}

int TriviaGame::play()
{
	Q_ASSERT(mainWindow == nullptr);
	mainWindow = new MainWindow();
	mainWindow->show();
#if 0
	std::srand( std::time(nullptr) );
	size_t questionNumber = 0;
	while ( std::cin )
	{
		std::cout << std::endl << ++questionNumber << ". ";
		size_t index = rand() % questions.size();
		questions[index]->ask();
	}
#endif
	return exec();
}

void TriviaGame::printQuestions() const
{
	QTextStream cout(stdout);
	for ( int i = 0; i < questions.size(); ++i )
		cout << *questions[i] << endl;
}


#include "NumericQuestion.h"
#include "TextualQuestion.h"
#include "SingleChoiceQuestion.h"
Question* TriviaGame::createQuestion(const QString& type)
{
	if ( type == "numeric") return new NumericQuestion();
	if ( type == "textual") return new TextualQuestion();
	if ( type == "single_choice") return new SingleChoiceQuestion();
	return nullptr;
}
