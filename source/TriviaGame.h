#ifndef TRIVIAGAME_H
#define TRIVIAGAME_H

#include <QApplication>
#include <QVector>

// Forward declarations
class MainWindow;
class Question;

class TriviaGame : public QApplication
{
  protected:
	MainWindow* mainWindow;
	QVector<Question*> questions;
	bool validArguments;

  public:
	TriviaGame(int& argc, char* argv[]);
	virtual ~TriviaGame();
	int run();

  private:
	bool loadQuestions();
	bool analyzeArguments(int argc, char* argv[]);
	int play();
	void printQuestions() const;
	static Question* createQuestion(const QString& type);
};

#endif // TRIVIAGAME_H
