#pragma once
#include "Component.h"
#include "Wall.h"

namespace Engine
{
	class PhysicsController;

	class ShipBody : public Component
	{
	public:
		ShipBody(Entity* owner, PhysicsController* physics);
		~ShipBody() = default;

		void update(float delta) override;
		void draw(sf::RenderWindow& window) override;

	private:
		//TODO: Clean these up into a single body with 4 fictures
		std::unique_ptr<Wall> left;
		std::unique_ptr<Wall> right;
		std::unique_ptr<Wall> front;
		std::unique_ptr<Wall> back;
	};
}	//	namespace Engine
