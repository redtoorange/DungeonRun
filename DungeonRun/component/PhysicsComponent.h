#pragma once
#include "Component.h"
#include <Box2D/Box2D.h>

namespace Engine
{
	class PhysicsController;

	class PhysicsComponent : public Component
	{
	public:
		PhysicsComponent(Entity* owner, PhysicsController* physics, float density = 1.0f, b2BodyType type = b2_dynamicBody);
		~PhysicsComponent();

		b2Body* getBody();


		void update(float delta) override;
		void draw(sf::RenderWindow& window) override;

	private:
		b2Body * body = nullptr;
		sf::RectangleShape debugShape;
	};
}	//	namespace Engine

