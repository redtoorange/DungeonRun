#include "MapTile.h"

namespace Engine
{
	MapTile::MapTile(float x, float y, float cost, float border) : movement_cost(cost), border_width(border)
	{
		getTransform().setPos(x, y);
		initRect();
	}


	MapTile::~MapTile()
	{
	}


	void MapTile::initRect()
	{
		rect.setFillColor(sf::Color::Red);
		rect.setOutlineColor(sf::Color::Black);
		rect.setOutlineThickness(border_width);
		rect.setSize(sf::Vector2f(1.0f - (border_width *2), 1.0f - (border_width * 2)));
		rect.setPosition(getTransform().getX(), getTransform().getY());
	}

	void MapTile::draw(sf::RenderWindow& window)
	{
		window.draw(rect);
	}

	sf::RectangleShape* MapTile::getRect()
	{
		return &rect;
	}

	float MapTile::getMovementCost() const
	{
		return movement_cost;
	}

}	//	namespace Engine

