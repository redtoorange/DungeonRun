#pragma once
#define DEBUG 0

#include <vector>
#include "tinyxml2.h"
#include "TiledMapTile.h"

using namespace tinyxml2;
using namespace std;


namespace Engine
{
	class TiledMap;

	//	A Single Layer within a Tiled TMX map
	class TiledMapLayer
	{
	public:
		TiledMapLayer();
		TiledMapLayer(const TiledMapLayer& other);
		TiledMapLayer& operator=(const TiledMapLayer& other);

		~TiledMapLayer() = default;

		//	Parse the Layer data from the Tiled TMX map File into a TileMapLayer Object
		void parseTiledMap(tinyxml2::XMLElement* layer, TiledMap* map, const sf::Vector2f& offset = {0, 0});
		
		//	Log debug info the object and it's current state
		void logInfo() const;

		//	All of the TiledMapTiles that are on this Layer
		vector<TiledMapTile>& getTiles();

		//	Adjust the position of all TiledMapTiles within the layer
		void setOffset( const sf::Vector2f& offset );

	private:
		TiledMap* owningMap = nullptr;

		//	All of the Tiles on this layer
		vector<TiledMapTile> tiles;

		string name;
		string data;

		sf::Vector2i size;
	};
}	//	namespace Engine

