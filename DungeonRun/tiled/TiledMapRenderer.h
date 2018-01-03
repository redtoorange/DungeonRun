/**
 * Simple Test Renderer Class.  This class should only be
 * used to print the "contents" of a TiledMap to the screen.
 * Actual Tile data is not stored or maintained, each tile is 
 * draw as an independent Sprite, this can cause dramatic 
 * slow down.
 *
 */
#pragma once

#include "Vector2D.h"
#include "SFML/Graphics.hpp"
namespace Engine
{
	class TiledMap;

	class TiledMapRenderer
	{
	public:
		TiledMapRenderer() = default;
		~TiledMapRenderer() = default;

		void setCurrentMap(TiledMap* map);
		TiledMap* getCurrentMap();

		void renderMap(sf::RenderWindow& window);
		void renderLayer(sf::RenderWindow& window, int index);

		void setOffset( const sf::Vector2f& offset);

	private:
		sf::Vector2f offset;
		Vector2D offset2;

		TiledMap* currentMap = nullptr;
	};

}	//	namespace Engine

