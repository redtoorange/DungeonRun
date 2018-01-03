#include "PhysicsComponent.h"
#include "../controller/PhysicsController.h"
#include "Entity.h"

namespace Engine
{
	PhysicsComponent::PhysicsComponent(Entity* owner, PhysicsController* physics, float density, b2BodyType type) : Component(owner)
	{
		auto& trans = owner->getTransform();

		auto h = trans.getHeight();
		auto w = trans.getWidth();

		auto x = trans.getX();
		auto y = trans.getY();


		body = physics->createBody({ x, y }, { w / 2, h / 2 }, density, type);
		body->SetSleepingAllowed(false);

		debugShape.setSize(sf::Vector2f{ w, h });
		debugShape.setOrigin(sf::Vector2f{ w / 2, h / 2 });
		debugShape.setPosition(sf::Vector2f{ x, y });

		debugShape.setFillColor(sf::Color{ 255, 255, 255, 0 });
		debugShape.setOutlineColor(sf::Color{ 255, 0, 0, 255 });
		debugShape.setOutlineThickness(.02f);
	}


	PhysicsComponent::~PhysicsComponent()
	{
	}

	b2Body* PhysicsComponent::getBody()
	{
		return body;
	}


	void PhysicsComponent::update(float delta)
	{
		auto& pos = body->GetPosition();

		debugShape.setPosition(pos.x, pos.y);
		getOwner()->getTransform().setPos(pos.x, pos.y);
	}

	void PhysicsComponent::draw(sf::RenderWindow& window)
	{
		window.draw(debugShape);
	}

}	//	namespace Engine
