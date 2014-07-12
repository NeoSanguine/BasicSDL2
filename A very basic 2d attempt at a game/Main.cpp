#include "GameEngine.h"


int main(int argc, char*args[])
{
	GameEngine game;
	
	game.Initialize(false);

	while (game.Running())
	{
		game.HandleEvents();
		game.Update();
		game.Render();
	}
	game.Clean();

	return 0;
}