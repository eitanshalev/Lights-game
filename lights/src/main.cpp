#include "Board.h"
#include "Globals.h"
#include <SFML/Graphics.hpp>

int main()
{
	srand(time(NULL));

	Board game;
	int indexLevel = START_POINT; //FIRSTLY DECIDE THE LENGTH OF THE CENTER LINE
	game.run(indexLevel);

	return EXIT_SUCCESS;
}
