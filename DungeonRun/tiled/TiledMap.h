#pragma once
#define DEBUG 0

#include "TiledMapLayer.h"
#include "TileSet.h"
#include "tinyxml2.h"
#include <vector>
#include <memory>

using namespace tinyxml2;
using namespace std;

namespace Engine
{
	//	Represents a single Tiled TMX map file loaded from Disk.  All TileSets associated with the map are
	//	Parsed and loaded onto the GPU indepentently of all other TileMaps.
	class TiledMap
	{
	public:
		TiledMap() = default;
		~TiledMap() = default;

		//	Parse a Tiled TMX map file into the TileMap object
		void parseTiledMap(const string& path, const string& name);
		
		//	Locate a TileSet based on an ID
		TileSet* findTileSet( int gid);

		//	Get the collection of all Layers on the map
		vector< unique_ptr<TiledMapLayer> >& getMapLayers();
		
		//	Get the collection of all TileSets associated with this map
		vector< unique_ptr<TileSet> >& getTileSets();

		//	Change the offset of the map, this will change the offset of all tiles in the map
		void setMapOffset( const sf::Vector2f& offset);

	private:
		vector< unique_ptr<TiledMapLayer> > mapLayers;
		vector< unique_ptr<TileSet> > tileSets;
	};

}	//	namespace Engine
