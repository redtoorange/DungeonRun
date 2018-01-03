#pragma once
#include "Entity.h"

namespace Engine
{
	class PhysicsController;

	class Player : public Entity
	{ 
	public:
		Player( PhysicsController* phys);
		~Player() = default;
	};

}	//	namespace Engine

