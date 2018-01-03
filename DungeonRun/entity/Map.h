#pragma once

#include "Entity.h"
#include "TiledMapRenderer.h"

namespace Engine
{
	class MapTile;

	class Map : public Entity{
	public:
		Map(int width, int height, float xOffset, float yOffset);
		Map(TiledMap* tiledMap);

		MapTile* getTileByPos(float x, float y);

	private:
		int width;
		int height;

		float xOffset;
		float yOffset;

		std::vector< std::vector<MapTile*> > tiles;
	};

}	//	namespace Engine
