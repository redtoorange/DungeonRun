#include "Component.h"


namespace Engine
{
	Component::Component(Entity* owner) : owner(owner)
	{
	}


	// Get the Entity that this Component is attached to
	Entity* Component::getOwner()
	{
		return owner;
	}

	// Set the Entity that this Component is attached to
	void Component::setOwner(Entity* owner)
	{
		this->owner = owner;
	}
}	// namespace Engine

