#pragma once

#include "Transform.h"
#include <Box2D/Dynamics/b2Body.h>

namespace Engine
{
	class Entity;
	class PhysicsComponent;

	enum Facing
	{
		NORTH = 0, SOUTH, EAST, WEST
	};

	class InputComponent : public Component
	{
	public:
		InputComponent(Entity* owner);
		~InputComponent() = default;

		void update(float delta) override;
		void draw(sf::RenderWindow& window) override;

		Facing getFacing() const;

	private:
		Transform * transform = nullptr;
		b2Body* rigidBody = nullptr;

		float speed = 10;
		Facing currentFacing = SOUTH;

		void normalize(float& x, float&y);
		void getInput(float delta, float& x, float& y);
		void calculateFacing(float x, float y);
	};

}	//	namespace Engine

