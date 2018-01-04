#pragma once
#include "Entity.h"

namespace Engine
{
	class PhysicsController;

	//	A simple Entity that can be used to create a static wall to block player movement.
	// TODO: Allow creation from TiledMaps
	class Wall : public Entity
	{
	public:
		Wall( PhysicsController* physics, float x, float y, float width, float height);
		~Wall();
	};
}	//	namespace Engine
