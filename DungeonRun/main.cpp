#include <SFML/Graphics.hpp>
#include "GameEngine.h"
#include "GameScreen.h"

using namespace Engine;


int main()
{
	sf::RenderWindow window{ sf::VideoMode{ 1422, 800 }, "Dungeon Run" };
	window.setFramerateLimit(144);

	GameEngine engine;
	engine.setWindow(&window);
	
	GameScreen screen(&engine);
	engine.setScreen(&screen);

	engine.gameLoop();

	window.close();

	return 0;
}
