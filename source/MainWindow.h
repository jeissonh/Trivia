#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

class TriviaGame;
namespace Ui { class MainWindow; }

/**
	@brief The Trivia main window class
 */
class MainWindow : public QMainWindow
{
	Q_OBJECT

  protected: // Data members
	/** Points to an instance of the MainWindow design created by QtDesigner **/
	Ui::MainWindow* ui;
	QGraphicsScene scene;
	TriviaGame* triviaGame;

  public: // Public methods
	/** Constructor **/
	explicit MainWindow(TriviaGame* triviaGame, QWidget* parent = 0);
	/** Destructor **/
	virtual ~MainWindow();

  protected: // Utility methods
	/** Set up connections that QtDesigner is unable to create **/
	void setupConnections();
	void displayNextQuestion();

  protected slots:
	/** Called when user asks for a new Trivia game **/
	void actionNewTriggered();
};

#endif // MAINWINDOW_H
