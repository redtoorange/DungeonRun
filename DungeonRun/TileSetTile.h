#pragma once
#include <SFML/Graphics/Rect.hpp>

namespace Engine
{
	class TileSet;

	class TileSetTile
	{
	public:
		TileSetTile(TileSet* tileset, const sf::IntRect& rect);
		~TileSetTile() = default;

		sf::IntRect* getRect();
		TileSet* getTileSet();

	private:
		TileSet* tileset = nullptr;
		sf::IntRect rect;
	};

}	//	namespace Engine
