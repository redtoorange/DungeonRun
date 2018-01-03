#include "BackGround.h"
#include "SpriteComponent.h"
#include "ShipBody.h"

namespace Engine
{
	BackGround::BackGround(PhysicsController* physics)
	{
		getTransform().setSize(8, 17);

	//	addComponent(new SpriteComponent(this, "assets/ship.jpg"));
		addComponent(new ShipBody(this, physics));
	}

}	//	namespace Engine
