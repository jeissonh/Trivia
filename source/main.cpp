#include "MainWindow.h"
#include "TriviaGame.h"

int main(int argc, char *argv[])
{
	TriviaGame game(argc, argv);
	return game.run();
}
