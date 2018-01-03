#pragma once
#include "Entity.h"

namespace Engine
{
	class PhysicsController;

	class Wall : public Entity
	{
	public:
		Wall( PhysicsController* physics, float x, float y, float width, float height);
		~Wall();
	};
}	//	namespace Engine
