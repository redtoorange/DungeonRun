#include "Player.h"

#include "InputComponent.h"
#include "AnimatedSprite.h"
#include "PhysicsComponent.h"

namespace Engine
{
	Player::Player( PhysicsController* physics)
	{
		getTransform().setSize(1, 1);


		addComponent(new PhysicsComponent(this, physics ));
		addComponent(new AnimatedSprite(this));
		addComponent(new InputComponent(this));
	}
}	//	namespace Engine


