#include "GameEngine.h"

using namespace std;

bool GameEngine::Initialize()
{

	cout << "Starting Engine \n";
	//Just a place holder
	bool success = true;
	if (!SDL_Init(SDL_INIT_EVERYTHING))
	{
		std::cout << "Failed to Initialize SDL \n" << SDL_GetError();
	}
	else
	{
			
		gWindow = SDL_CreateWindow("Simply Platform", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN&&SDL_WINDOW_BORDERLESS);
		if (!gWindow)
			std::cout << "Failed to Create Window \n" << SDL_GetError();
		else
		{
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer = NULL)
				cout << "Failed to Create Renderer \n" << SDL_GetError();
			else
			{
				screen = SDL_GetWindowSurface(gWindow);
				//Add code here
			}
		}
	}
	return success;
}

void GameEngine::HandleEvents()
{
	if (getEvent().type == SDL_QUIT)
		Quit();
	if (getEvent().key.keysym.sym == SDLK_F1)
		Quit();
}

void GameEngine::Update()
{

}

void GameEngine::Render()
{
	SDL_RenderClear(getRenderer());
	//Add render code here
	SDL_RenderPresent(getRenderer());
	
}

void GameEngine::Clean()
{
	SDL_DestroyWindow(gWindow);
	SDL_DestroyRenderer(gRenderer);
	SDL_FreeSurface(screen);

	gWindow = NULL;
	gRenderer = NULL;
	screen = NULL;

	SDL_Quit();
}