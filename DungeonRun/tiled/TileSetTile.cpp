#include "TileSetTile.h"
namespace Engine
{
	TileSetTile::TileSetTile(TileSet* tileset, const sf::IntRect& rect ) :
		tileset(tileset), rect(rect)
	{

	}

	//----------------------------------------------------------------------------------
	sf::IntRect* TileSetTile::getRect()
	{
		return &rect;
	}

	//----------------------------------------------------------------------------------
	TileSet* TileSetTile::getTileSet()
	{
		return tileset;
	}

}	//	namespace Engine
