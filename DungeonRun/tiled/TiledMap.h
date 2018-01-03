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
	class TiledMap
	{
	public:
		void parseTiledMap(const string& path, const string& name);
		TileSet* findTileSet( int gid);

		vector< unique_ptr<TiledMapLayer> >& getMapLayers();
		vector< unique_ptr<TileSet> >& getTileSets();

		void setMapOffset( const sf::Vector2f& offset);

	private:
		vector< unique_ptr<TiledMapLayer> > mapLayers;
		vector< unique_ptr<TileSet> > tileSets;
	};

}	//	namespace Engine
