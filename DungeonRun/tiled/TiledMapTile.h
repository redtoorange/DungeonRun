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

	class TiledMapTile
	{
	public:
		TiledMapTile();
		TiledMapTile(const sf::Vector2f& pos, TileSetTile* ts, const sf::Vector2f& offset = { 0, 0 });
		TiledMapTile(const TiledMapTile& other);

		~TiledMapTile();
		void draw(sf::RenderWindow& window) ;
		void initialize(const sf::Vector2f& pos, TileSetTile* ts, const sf::Vector2f& offset = { 0, 0 });


		TileSetTile* const& getTileSetTile() const;
		const sf::Vector2f& getPosition() const;
		const sf::Sprite& getSprite() const;

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
