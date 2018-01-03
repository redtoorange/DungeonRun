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
	class TiledMapLayer
	{
	public:
		TiledMapLayer();
		TiledMapLayer(const TiledMapLayer& other);
		TiledMapLayer& operator=(const TiledMapLayer& other);

		~TiledMapLayer() = default;

		void parseTiledMap(tinyxml2::XMLElement* layer, TiledMap* map, const sf::Vector2f& offset = {0, 0});
		void logInfo() const;

		vector<TiledMapTile>& getTiles();

		void setOffset( const sf::Vector2f& offset );

	private:
		TiledMap* owningMap = nullptr;

		vector<TiledMapTile> tiles;

		string name;
		string data;

		sf::Vector2i size;
	};
}	//	namespace Engine

