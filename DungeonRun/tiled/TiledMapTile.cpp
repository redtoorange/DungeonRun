#include "TiledMapTile.h"

#include "TileSetTile.h"
#include "TileSet.h"

#include <iostream>

namespace Engine
{
	TiledMapTile::TiledMapTile(const sf::Vector2f& pos, TileSetTile* ts, const sf::Vector2f& offset)
	: tileSetTile(ts), position(pos), offset(offset)
	{
#if DEBUG>0
		std::cout << "Tile Created" << std::endl;
#endif

		sprite.setPosition(position);
		sprite.setScale(1.0f / 64.0f, 1.0f / 64.0f);


		sprite.setTexture(*ts->getTileSet()->getTexture(), true);
		sprite.setTextureRect(*ts->getRect());

		setOffset(offset);
	}

	//----------------------------------------------------------------------------------
	TiledMapTile::TiledMapTile(const TiledMapTile& other)
		: tileSetTile(other.tileSetTile), position(other.position), offset( other.offset), sprite(other.sprite)
	{
#if DEBUG>0
		std::cout << "Tile Copied" << std::endl;
#endif
	}

	//----------------------------------------------------------------------------------
	void TiledMapTile::draw(sf::RenderWindow& window)
	{
		window.draw(sprite);
	}

	//----------------------------------------------------------------------------------
	void TiledMapTile::initialize(const sf::Vector2f& pos, TileSetTile* ts, const sf::Vector2f& offset)
	{
#if DEBUG>0
		std::cout << "Tile initialized" << std::endl;
#endif
		tileSetTile = ts;
		position = pos;

		sprite.setPosition(position);
		sprite.setScale(1.0f / 64.0f, 1.0f / 64.0f);

		sprite.setTexture(*ts->getTileSet()->getTexture(), true);
		sprite.setTextureRect(*ts->getRect());

		setOffset(offset);
	}

	//----------------------------------------------------------------------------------
	TileSetTile* const& TiledMapTile::getTileSetTile() const
	{
		return tileSetTile;
	}

	//----------------------------------------------------------------------------------
	const sf::Vector2f& TiledMapTile::getPosition() const
	{
		return position;
	}

	//----------------------------------------------------------------------------------
	const sf::Sprite& TiledMapTile::getSprite() const
	{
		return sprite;
	}

	//----------------------------------------------------------------------------------
	TiledMapTile::TiledMapTile()
	{
#if DEBUG>0
		std::cout << "Tile default Created" << std::endl;
#endif
	}

	//----------------------------------------------------------------------------------
	TiledMapTile::~TiledMapTile()
	{
#if DEBUG>0
		std::cout << "Tile deallocated"  << std::endl;
#endif
	}

	//----------------------------------------------------------------------------------
	void TiledMapTile::setOffset(const sf::Vector2f& offset)
	{
		this->offset = offset;
		sprite.setPosition(position + offset);
	}

}	//	namespace Engine

