#include "TiledMapRenderer.h"
#include "TiledMap.h"

namespace Engine
{
	void TiledMapRenderer::setCurrentMap(TiledMap* map)
	{
		// Reverse the current offset
		if( currentMap )
			currentMap->setMapOffset({ -offset.x, -offset.y });

		currentMap = map;

		// Apply the current offset
		if( currentMap )
			currentMap->setMapOffset(offset);
	}


	TiledMap* TiledMapRenderer::getCurrentMap()
	{
		return currentMap;
	}


	void TiledMapRenderer::renderMap(sf::RenderWindow& window)
	{
		if (!currentMap) return;

		for( auto& layer : currentMap->getMapLayers())
		{
			for( auto& tile : layer->getTiles())
			{
				tile.draw(window);
			}
		}
	}

	void TiledMapRenderer::renderLayer(sf::RenderWindow& window, int index)
	{
		if( currentMap && index < currentMap->getMapLayers().size())
		{
			auto& l = currentMap->getMapLayers().at(index);

			for (auto& t : l->getTiles())
				t.draw(window);
		}
	}


	void TiledMapRenderer::setOffset(const sf::Vector2f& offset)
	{
		if( currentMap )
		{
			this->offset = offset;
			currentMap->setMapOffset(offset);
		}
	}

}	//	namespace Engine

