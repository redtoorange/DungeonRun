#pragma once
#define DEBUG 0

#include <SFML/Graphics/Texture.hpp>
#include "TileSetTile.h"
#include "tinyxml2.h"
using namespace tinyxml2;
namespace Engine
{
	class TileSet
	{
	public:
		TileSet() = default;
		~TileSet() = default;


		TileSet(const TileSet& other);
		TileSet& operator=(const TileSet& other);

		void parseTileSet(const std::string& path, XMLElement* tileSet);
	

		sf::Texture* getTexture();
		TileSetTile* getTile( int gid);

		void logInfo() const;
		bool containsID(int gid) const;

	private:
		std::string name;
		int firstID = 0;

		int tileWidth = 0;
		int tileHeight = 0;
		int spacing = 0;
		int margin = 0;
		int count = 0;
		int columns = 0;

		sf::Texture sourceImage;
		int texWidth = 0;
		int textHeight = 0;

		std::vector<TileSetTile> tiles;
	};

}	//	namespace Engine

