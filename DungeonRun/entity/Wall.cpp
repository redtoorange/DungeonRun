#include "Wall.h"
#include "PhysicsComponent.h"
namespace Engine
{
	Wall::Wall(PhysicsController* physics, float x, float y, float width, float height)
	{
		getTransform().setSize(width, height);
		getTransform().setPos(x, y);

		addComponent(new PhysicsComponent(this, physics, 10.0f, b2_dynamicBody));
	}

	//----------------------------------------------------------------------------------
	Wall::~Wall()
	{
	}

}	//	namespace Engine

