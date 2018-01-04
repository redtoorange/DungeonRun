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
		virtual ~Entity() = default;

		//	Get the Entity's Transform Component: Contains position and rotation data
		Transform& getTransform();

		//	Add an Entity to this Entity's tree.  This Entity will call update and draw on it
		void addChild( Entity* child );
		
		//	Get the collection of Children owned by this Entity
		const std::vector<std::unique_ptr<Entity>>* getChildren();

		//	Add a Component to this Entity's component bag.  This Entity will call update and draw on it
		void addComponent(Component* comp);
		
		//	Get the collection of Components owned by this Entity
		const std::vector<std::unique_ptr<Component>>* getComponents();

		//	Call update on all Components, then on all Children
		virtual void update(float delta);
		
		//	Call draw on all Componenets, then on all Children
		virtual void draw(sf::RenderWindow& window);

		//	Get the first Component of the specified type
		template <typename T>
		T* getComponent();

		//	Get the first Child of the specified type
		template <typename T>
		T* getChild();

	private:
		Transform transform;

		std::vector<std::unique_ptr<Entity>> children;
		std::vector<std::unique_ptr<Component>> components;
	};


	template <typename T>
	T* Entity::getComponent()
	{
		// Locate the first Component that can be cast to T, return it
		for( auto& comp : components)
			if ( T* p = dynamic_cast<T*>(comp.get()) )
				return p;

		return nullptr;
	}

	template <typename T>
	T* Entity::getChild()
	{
		// Locate the first Child that can be cast to T, return it
		for (auto& child : children)
			if (T* p = dynamic_cast<T*>(child.get()))
				return p;

		return nullptr;
	}
}	//	namespace Engine
