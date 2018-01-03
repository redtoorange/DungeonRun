#include "GameEngine.h"

namespace Engine
{
	void GameEngine::gameLoop()
	{
		if (currentScreen && currentWindow)
		{
			sf::Clock clock;
			running = true;

			while (running)
			{
				currentScreen->handleInput(currentWindow);
				currentScreen->update(clock.restart().asSeconds());
				currentScreen->draw(currentWindow);
			}
		}
	}



	void GameEngine::setScreen(Screen* screen)
	{
		this->currentScreen = screen;
	}

	Screen* GameEngine::getScreen()
	{
		return currentScreen;
	}

	void GameEngine::setWindow(sf::RenderWindow* window)
	{
		this->currentWindow = window;
	}

	sf::RenderWindow* GameEngine::getWindow()
	{
		return currentWindow;
	}

	bool GameEngine::isRunning() const
	{
		return running;
	}

	void GameEngine::setRunning(bool running)
	{
		this->running = running;
	}


}	//	namespace Engine
