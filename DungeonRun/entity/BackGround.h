#pragma once
#include "Entity.h"

namespace Engine
{
	class PhysicsController;

	class BackGround : public Entity
	{
	public:
		BackGround(PhysicsController* physics);
		~BackGround() = default;
	};

}	//	namespace Engine

