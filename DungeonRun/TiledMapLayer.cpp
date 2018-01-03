#include "TiledMapLayer.h"

#include <iostream>
#include <sstream>
#include <vector>
#include "TileSet.h"
#include "TiledMap.h"



namespace Engine
{
	void TiledMapLayer::logInfo() const
	{
		std::cout << name.c_str() << "\nWidth: " << size.x << "\tHeight: " << size.y << std::endl;
		std::cout << data.c_str() << std::endl;
		std::cout << "Tile Count: " << tiles.size() << std::endl;
	}

	void TiledMapLayer::parseTiledMap(tinyxml2::XMLElement* layer, TiledMap* map, const sf::Vector2f& offset)
	{
		owningMap = map;
		name = layer->Attribute("name");

		size.x = layer->IntAttribute("width");
		size.y = layer->IntAttribute("height");

		tiles.resize(size.x*size.y);

		data = layer->FirstChildElement("data")->GetText();

		std::stringstream ss(data);

		int index = 0;
		int gid;
		int posX = 0;
		int posY = 0;

		while (ss >> gid)
		{
			if (auto ts = map->findTileSet(gid))
			{
				tiles.at(index++).initialize(
					{static_cast<float>(posX), 
						static_cast<float>(posY)},
					ts->getTile( gid ), offset);
				posX++;
				if (posX >= size.x)
				{
					posX = 0;
					posY++;
				}
			}
			else
			{
				std::cout << "Error locating tileSet associated with ID: " << gid << std::endl;
			}

			if (ss.peek() == ',' || ss.peek() == ' ')
				ss.ignore();
		}
	}


	TiledMapLayer::TiledMapLayer()
	{
#if DEBUG>0
		std::cout << "TiledMapLayer created" << std::endl;
#endif
	}

	TiledMapLayer::TiledMapLayer(const TiledMapLayer& other)
		: owningMap(other.owningMap),
		name(other.name),
		data(other.data),
		size(other.size)
	{
#if DEBUG>0
		std::cout << "TiledMapLayer copied" << std::endl;
#endif
		for( auto t : other.tiles)
		{
			tiles.push_back(t);
		}
	}

	TiledMapLayer& TiledMapLayer::operator=(const TiledMapLayer& other)
	{
#if DEBUG>0
		std::cout << "TiledMapLayer = operator" << std::endl;
#endif

		if (this == &other)
			return *this;
		owningMap = other.owningMap;
		for (auto t : other.tiles)
		{
			tiles.push_back(t);
		}
		name = other.name;
		data = other.data;
		size = other.size;

		return *this;
	}


	std::vector<TiledMapTile>& TiledMapLayer::getTiles()
	{
		return tiles;
	}

	void TiledMapLayer::setOffset(const sf::Vector2f& offset)
	{
		for( auto& t : tiles)
			t.setOffset(offset);
	}

}	//	namespace Engine

