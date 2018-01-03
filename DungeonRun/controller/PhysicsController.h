#pragma once

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

namespace Engine
{
	class PhysicsController
	{
	public:
		PhysicsController(const b2Vec2& gravity = { 0.0f, 0.0f });
		~PhysicsController() = default;

		void step(float delta);
		b2Body* createBody(const sf::Vector2f& pos, const sf::Vector2f& size, const float density = 1.0f, b2BodyType type = b2_staticBody);

	private:
		b2World world;
	};

}	//	namespace Engine
