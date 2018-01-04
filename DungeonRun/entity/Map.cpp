#include "Map.h"
#include "MapTile.h"

namespace Engine
{
	//******************************************************************
	Map::Map(int width, int height, float xOffset, float yOffset) 
	: width(width), height(height), xOffset(xOffset), yOffset(yOffset)
	{
		for( int i = 0; i < width; i++)
		{
			tiles.emplace_back(std::vector<MapTile*>());

			for( int j = 0; j < height; j++)
			{
				tiles[i].push_back(new MapTile(i + xOffset, j + yOffset));
				addChild(tiles[i][j]);
			}
		}
	}

	//******************************************************************
	MapTile* Map::getTileByPos(float x, float y)
	{
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				auto bounds = tiles[i][j]->getRect()->getGlobalBounds();
				if( bounds.contains(x, y) )
				{
					return tiles[i][j];
				}
			}
		}

		return nullptr;
	}

}	//	namespace Engine

