#pragma once
#define DEBUG 0

#include <SFML/Graphics/Texture.hpp>
#include "TileSetTile.h"
#include "tinyxml2.h"
using namespace tinyxml2;
namespace Engine
{
	//	A Texture is broken into multiple smaller Tiles, each used to paint a map.  
	//	A TileSet is the collection of all Tile associate with a single Texture.
	class TileSet
	{
	public:
		TileSet() = default;
		TileSet(const TileSet& other);
		TileSet& operator=(const TileSet& other);

		~TileSet() = default;

		//	Parse a section of an XML file and create a TileSet from it.fdgd dfg
		void parseTileSet(const std::string& path, XMLElement* tileSet);
	
		//	Get the TileSet's source texture
		sf::Texture* getTexture();

		//	Get a TileSetTile* associate with the gid
		TileSetTile* getTile( int gid);

		//	Log debug info about the TileSet
		void logInfo() const;
		

		//	Does this TileSet contain a Tile that matches the ID
		bool containsID(int gid) const;

	private:
		std::string name;

		//	Each TileSetTile has an ID associate with it
		int firstID = 0;

		int tileWidth = 0;
		int tileHeight = 0;
		int spacing = 0;
		int margin = 0;
		int count = 0;
		int columns = 0;

		//	Texture that the TileSet is derived from
		sf::Texture sourceImage;
		int texWidth = 0;
		int textHeight = 0;

		//	All Tile associate with this TileSet
		std::vector<TileSetTile> tiles;

		//	Parse the TileSet into TileSetTiles
		void createTileSetTiles();
	};

}	//	namespace Engine

