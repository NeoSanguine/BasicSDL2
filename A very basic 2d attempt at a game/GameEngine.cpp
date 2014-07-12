#include "GameEngine.h"

using namespace std;

bool GameEngine::Initialize(bool fullscreen)
{

	
	//Just a place holder
	bool success = true;
	if (SDL_Init(SDL_INIT_EVERYTHING)!= 0)
	{
		getConsole()->Text("Failed To Initialize Engine");
		getConsole()->Text(SDL_GetError());
	}
	else
	{
		int flags = 0;
		if (fullscreen)
			flags = SDL_WINDOW_FULLSCREEN;

		getConsole()->Text("Statring Engine");
		gWindow = SDL_CreateWindow("Simply Platform", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, flags);
		if (gWindow == NULL)
			std::cout << "Failed to Create Window \n" << SDL_GetError();
		else
		{
			getConsole()->Text("Created Window");
			gRenderer = SDL_CreateRenderer(gWindow, -1, NULL);
			if (gRenderer == NULL)
				cout << "Failed to Create Renderer \n" << SDL_GetError();
			else
			{
				getConsole()->Text("Created Renderer");
				screen = SDL_GetWindowSurface(gWindow);
				getConsole()->Text("Setting Window Surface");
				//Add code here
			}
		}
	}
	getConsole()->Text("Engine Succesfully Initialized");
	return success;
}

void GameEngine::HandleEvents()
{

	while (SDL_PollEvent(&*getEvent()) != 0)
	{
		if (getEvent()->type == SDL_QUIT)
		{
			getConsole()->Text("Event Type Is SDL_QUIT");
			Quit();

		}
			
		if (getEvent()->key.keysym.sym == SDLK_F1)
			Quit();
	}
	
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
	getConsole()->Text("Cleaning Engine");
	SDL_DestroyWindow(gWindow);
	SDL_DestroyRenderer(gRenderer);

	gWindow = NULL;
	gRenderer = NULL;
	screen = NULL;
	getConsole()->Text("Bye");
	SDL_Quit();

}