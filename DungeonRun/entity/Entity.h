#pragma once
#include <vector>
#include <memory>
#include "Component.h"
#include "Transform.h"
#include <SFML/Graphics.hpp>

namespace Engine
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		Transform& getTransform();

		void addChild( Entity* child );
		const std::vector<std::unique_ptr<Entity>>* getChildren();

		void addComponent(Component* child);
		const std::vector<std::unique_ptr<Component>>* getComponents();

		virtual void update(float delta);
		virtual void draw(sf::RenderWindow& window);

		template <typename T>
		T* getComponent();

		template <typename T>
		T* getChild();

	private:
		Transform transform;

		std::vector<std::unique_ptr<Entity>> children;
		std::vector<std::unique_ptr<Component>> components;
	};

	//Something something
	template <typename T>
	T* Entity::getComponent()
	{
			for( auto& comp : components)
			{
				if ( T* p = dynamic_cast<T*>(comp.get()) )
					return p;
			}

		return nullptr;
	}

	template <typename T>
	T* Entity::getChild()
	{
		for (auto& child : children)
		{
			if (T* p = dynamic_cast<T*>(child.get()))
				return p;
		}

		return nullptr;
	}
}	//	namespace Engine
