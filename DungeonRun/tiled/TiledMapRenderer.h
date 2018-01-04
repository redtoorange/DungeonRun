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

	//	Class to help render a TiledMap to the buffer.  It is not the most efficient method of rendering,
	//	but it is simple.
	class TiledMapRenderer
	{
	public:
		TiledMapRenderer() = default;
		~TiledMapRenderer() = default;

		//	Change the current map, apply the current offset to all Tile within that map
		void setCurrentMap(TiledMap* map);
		TiledMap* getCurrentMap();

		//	Draw the entire map to the buffer
		void renderMap(sf::RenderWindow& window);
		
		//	Draw a single layer to the window buffer
		void renderLayer(sf::RenderWindow& window, int index);

		//	Adjust the positional data of the Tile sprites for drawing
		void setOffset( const sf::Vector2f& offset);

	private:
		//	Offset to use when drawing the Tile Sprites
		sf::Vector2f offset;
		Vector2D offset2;

		TiledMap* currentMap = nullptr;
	};

}	//	namespace Engine

