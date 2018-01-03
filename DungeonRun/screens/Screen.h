#pragma once
#include <SFML/Graphics.hpp>
namespace Engine
{
	class GameEngine;

	class Screen
	{
	public:
		Screen(GameEngine* engine);
		virtual ~Screen() = default;

		virtual void draw( sf::RenderWindow* window) = 0;
		virtual void update( float delta) = 0;
		virtual void handleInput(sf::RenderWindow* window) = 0;

	protected:
		GameEngine* engine;
	};

}	//	namespace Engine

