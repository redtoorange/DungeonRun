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
