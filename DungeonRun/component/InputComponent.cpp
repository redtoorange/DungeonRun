#include "InputComponent.h"
#include "PhysicsComponent.h"
#include "Entity.h"
#include "SFML/Graphics.hpp"

namespace Engine
{
	InputComponent::InputComponent(Entity* owner) : Component(owner)
	{
		transform = &owner->getTransform();
	}


	void InputComponent::normalize(float& x, float&y)
	{
		const float length = sqrtf((x * x) + (y * y));

		if (abs(length) > 0.0f)
		{
			x /= length;
			y /= length;
		}
	}

	void InputComponent::getInput(float delta, float& x, float& y)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			x += 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			x -= 1;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			y += 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			y -= 1;
		}
	}

	void InputComponent::update(float delta)
	{
		if (!rigidBody) rigidBody = getOwner()->getComponent<PhysicsComponent>()->getBody();

		if (rigidBody)
		{
			float x = 0;
			float y = 0;

			getInput(delta, x, y);
			calculateFacing(x, y);
			normalize(x, y);

			// You might take the ship's current velocity
			//		rigidBody->SetLinearVelocity(b2Vec2{ x * speed, 1 + y * speed });
			rigidBody->SetLinearVelocity(b2Vec2{ x * speed, y * speed });
			//		rigidBody->ApplyLinearImpulseToCenter( b2Vec2{x * speed, y * speed}, true);
		}
	}

	void InputComponent::draw(sf::RenderWindow& window)
	{
		//
	}


	void InputComponent::calculateFacing(float x, float y)
	{
		if (abs(x) > abs(y))
		{
			if (x > 0)
				currentFacing = EAST;
			else
				currentFacing = WEST;
		}
		else if (abs(x) < abs(y))
		{
			if (y > 0)
				currentFacing = SOUTH;
			else
				currentFacing = NORTH;
		}

	}


	Facing InputComponent::getFacing() const
	{
		return currentFacing;
	}

}	//	namespace Engine
