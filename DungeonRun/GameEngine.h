#pragma once
#include "Screen.h"

//class sf::RenderWindow;

namespace Engine
{
	class GameEngine
	{
	public:
		GameEngine() = default;
		~GameEngine() = default;

		void setScreen(Screen* screen);
		Screen* getScreen();

		void setWindow(sf::RenderWindow* window);
		sf::RenderWindow* getWindow();

		bool isRunning() const;
		void setRunning(bool running);

		void gameLoop();

	private:
		bool running = false;
		sf::RenderWindow* currentWindow = nullptr;
		Screen* currentScreen = nullptr;

	};


}	//	namespace Engine
