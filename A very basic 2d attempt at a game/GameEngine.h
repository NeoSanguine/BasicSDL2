#ifndef GAMEENGINE_H_
#define GAMEENGINE_H_

#pragma once
#include <SDL.h>
#include <iostream>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <vector>
#include "Console.h"

struct GameEngine
{
	
	GameEngine(){}
	//Standard engine setup
	bool Initialize();
	void HandleEvents();
	void Update();
	void Render();
	void Clean();

	//Helper function to check if gRunning is true of false
	bool Running(){ return gRunning; }
	//Returns the window surface
	SDL_Surface*getScreen(){ return screen; }
	//Gets the event handler
	SDL_Event getEvent(){ return gEvent; }
	//Calls for gRunning to be false. i.e : Ends the game loop
	bool Quit(){ return gRunning = false; }
	//Gets the current renderer
	SDL_Renderer*getRenderer(){ return gRenderer; }
	//returns my favorite console helper
	Console getConsole(){ return console; }

private:
	bool gRunning;
	SDL_Window*gWindow = NULL;
	SDL_Renderer*gRenderer = NULL;
	SDL_Surface*screen = NULL;
	SDL_Event gEvent;
	Console console;
};



#endif //GAMEENGINE_H_