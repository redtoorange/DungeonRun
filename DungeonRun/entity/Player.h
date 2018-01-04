#pragma once
#include "Entity.h"

namespace Engine
{
	class PhysicsController;

	//	A basic Player Character that can be controlled by the keyboard and mouse.
	//	It should be added to the Root node last so that it draw on top of everything
	class Player : public Entity
	{ 
	public:
		Player( PhysicsController* phys);
		~Player() = default;
	};
}	//	namespace Engine