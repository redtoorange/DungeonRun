#include "Entity.h"

namespace Engine
{
	//*********************************************************************
	Entity::Entity() : transform(this)
	{
	}

	//*********************************************************************
	Transform& Entity::getTransform()
	{
		return transform;
	}

	//*********************************************************************
	void Entity::addChild(Entity* child)
	{
		children.push_back(std::unique_ptr<Entity>(child));
	}

	//*********************************************************************
	const std::vector<std::unique_ptr<Entity>>* Entity::getChildren()
	{
		return &children;
	}

	//*********************************************************************
	void Entity::update(float delta)
	{
		for (auto& c : components)
			c->update(delta);

		for (auto& c : children)
			c->update(delta);
	}

	//*********************************************************************
	void Entity::draw(sf::RenderWindow& window)
	{
		for (auto& c : components)
			c->draw(window);

		for (auto& c : children)
			c->draw(window);
	}

	//*********************************************************************
	void Entity::addComponent(Component* comp)
	{
		components.push_back(std::unique_ptr<Component>(comp));
	}

	//*********************************************************************
	const std::vector<std::unique_ptr<Component>>* Entity::getComponents()
	{
		return &components;
	}
}	//	namespace Engine
