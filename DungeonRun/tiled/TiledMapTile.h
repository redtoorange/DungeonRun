/**
 * This is a placeholder entity that is
 * used by the TiledMapRenderer to create
 * test renders.  This is VERY slow.
 */
#pragma once

#include "SFML/Graphics.hpp"

namespace Engine
{
	class TileSetTile;

	//	Represents a single Tile within a TileMapLayer.  This Tile can contain information
	//	loaded in from the TMX file including a TileSetTile ID.
	class TiledMapTile
	{
	public:
		TiledMapTile();
		TiledMapTile(const sf::Vector2f& pos, TileSetTile* ts, const sf::Vector2f& offset = { 0, 0 });
		TiledMapTile(const TiledMapTile& other);

		~TiledMapTile();
		
		//	Draw this Tile's Sprite
		void draw(sf::RenderWindow& window) ;
		
		//	Init the Tile's position and TileSetTile information
		void initialize(const sf::Vector2f& pos, TileSetTile* ts, const sf::Vector2f& offset = { 0, 0 });

	
		TileSetTile* const& getTileSetTile() const;
		const sf::Vector2f& getPosition() const;
		const sf::Sprite& getSprite() const;

		//	Adjust the position of the Sprite, not the Tile's position within the layer
		void setOffset(const sf::Vector2f& offset);

	private:
		//Tile set tile is the tile associated with this tiles
		// On the tileSet
		TileSetTile* tileSetTile = nullptr;
		sf::Vector2f position;
		sf::Vector2f offset;

		//Temp to allow drawing
		sf::Sprite sprite;
	};
}	//	namespace Engine
