#include "game.h"

Game* game = nullptr;

int main(int argc, char* argv[])
{
	game = new Game();

	game->init("BruhEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		800, 600, true);

	while (game->running())
	{
		game->handleEvents();
		game->update();
		game->render();

	}

	game->clean();

	return 0;
}