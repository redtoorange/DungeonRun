#include "PhysicsController.h"

namespace Engine
{
	PhysicsController::PhysicsController(const b2Vec2& gravity) : world(gravity)
	{

	}


	void PhysicsController::step(float delta)
	{
		world.Step(delta, 8, 2);
	}

	b2Body* PhysicsController::createBody(const sf::Vector2f& pos, const sf::Vector2f& size, const float density, b2BodyType type)
	{
		b2PolygonShape shape;
		shape.SetAsBox(size.x, size.y);

		b2FixtureDef fDef;
		fDef.density = density;
		fDef.shape = &shape;

		b2BodyDef bDef;
		bDef.type = type;
		bDef.allowSleep = false;
		bDef.fixedRotation = true;
		bDef.position = b2Vec2{ pos.x, pos.y };
		bDef.linearDamping = 5.0f;

		b2Body* body = world.CreateBody(&bDef);
		body->CreateFixture(&fDef);

		return body;
	}

}	//	namespace Engine

