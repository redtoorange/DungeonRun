#pragma once

#include <SFML/Graphics.hpp>

namespace Engine
{
	class Entity;

	class Component
	{
	public:
		Component(Entity* owner);
		virtual ~Component() = default;

		Entity* getOwner();
		void setOwner(Entity* owner);

		virtual void update(float delta) = 0;
		virtual void draw(sf::RenderWindow& window) = 0;

	private:
		Entity * owner;
	};
}	// namespace Engine


