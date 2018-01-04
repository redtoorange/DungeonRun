#pragma once
#include <SFML/Graphics/Rect.hpp>

namespace Engine
{
	class TileSet;

	//	Represents a single Tile within a TileSet
	class TileSetTile
	{
	public:
		TileSetTile(TileSet* tileset, const sf::IntRect& rect);
		~TileSetTile() = default;

		//	Get the bounds of this Tile within the parent TileSet.
		sf::IntRect* getRect();

		//	Get the TileSet this Tile belongs to
		TileSet* getTileSet();

	private:
		//	Owning TileSet
		TileSet* tileset = nullptr;

		//	An IntRect that represents the bouds of this Tile within the TileSet's Texture
		sf::IntRect rect;
	};

}	//	namespace Engine
