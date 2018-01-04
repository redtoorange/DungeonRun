/**
 * This class has been replaced by the TiledMap and TiledMapRenderer combo.  This allows for hot swapping maps
 * at runtime without worrying out pushing textures to the card.
 */
#pragma once
#include "Entity.h"
namespace Engine
{
	class MapTile : public Entity {
	public:
		MapTile(float x, float y, float cost = 1.0f, float border = 0.05f );
		~MapTile();

		void draw(sf::RenderWindow& window) override;
		sf::RectangleShape* getRect();

		float getMovementCost() const;

	private:
		sf::RectangleShape rect;

		float border_width;
		float movement_cost;

		void initRect();
	};
}	//	namespace Engine
