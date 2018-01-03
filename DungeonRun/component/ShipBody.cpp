#include "ShipBody.h"
#include "PhysicsComponent.h"

namespace Engine
{
	ShipBody::ShipBody(Entity* owner, PhysicsController* physics) :
		Component(owner)
	{
		left = std::make_unique<Wall>(physics, -2.25, 1, 0.25, 12);
		right = std::make_unique<Wall>(physics, 2.25, 1, 0.25, 12);
		front = std::make_unique<Wall>(physics, 0, -5.25, 2, 0.25);
		back = std::make_unique<Wall>(physics, 0, 6.75, 3, 0.25);
	}


	void ShipBody::update(float delta)
	{
		left->update(delta);
		right->update(delta);
		front->update(delta);
		back->update(delta);
	}

	void ShipBody::draw(sf::RenderWindow& window)
	{
		left->draw(window);
		right->draw(window);
		front->draw(window);
		back->draw(window);
	}
}	//	namespace Engine