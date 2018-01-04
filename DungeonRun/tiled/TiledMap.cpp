#include "TiledMap.h"

#include <iostream>

namespace Engine
{
	void TiledMap::parseTiledMap(const string& path, const string& name)
	{
		XMLDocument doc;

		string file;
		file.append(path);
		file.append(name);

		XMLError error = doc.LoadFile(file.c_str());
		if (error != XML_SUCCESS)
		{
			cout << "Error Loading TMX File <" << file.c_str() << ">" << endl;
			return;
		}

		XMLElement* map = doc.FirstChildElement("map");

		//Parse tilesets
		auto t = make_unique<TileSet>();
		t->parseTileSet(path, map->FirstChildElement("tileset"));
		tileSets.push_back( move(t) );

		//Parse layers
		auto l = make_unique<TiledMapLayer>();
		l->parseTiledMap(map->FirstChildElement("layer"), this);
		mapLayers.push_back( move(l) );
	}

	//----------------------------------------------------------------------------------
	TileSet* TiledMap::findTileSet(int gid)
	{
		for( auto& t : tileSets)
			if( t->containsID(gid) ) 
				return t.get();

		return nullptr;
	}

	//----------------------------------------------------------------------------------
	vector<unique_ptr<TiledMapLayer>>& TiledMap::getMapLayers()
	{
		return mapLayers;
	}

	//----------------------------------------------------------------------------------
	vector<unique_ptr<TileSet>>& TiledMap::getTileSets()
	{
		return tileSets;
	}

	//----------------------------------------------------------------------------------
	void TiledMap::setMapOffset(const sf::Vector2f& offset)
	{
		for( auto& l : mapLayers)
			l->setOffset(offset);
	}

}	//	namespace Engine

