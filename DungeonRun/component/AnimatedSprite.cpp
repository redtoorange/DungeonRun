#include "AnimatedSprite.h"
#include "InputComponent.h"
#include "Entity.h"

namespace Engine
{

	////////////////////////////////////////////////////////////
	AnimatedSprite::AnimatedSprite(Entity* owner) : SpriteComponent(owner)
	{
		textures[NORTH].loadFromFile("assets/Frog/Frog_N.png");
		textures[SOUTH].loadFromFile("assets/Frog/Frog_S.png");
		textures[EAST].loadFromFile("assets/Frog/Frog_E.png");
		textures[WEST].loadFromFile("assets/Frog/Frog_W.png");

		sprite.setTexture(textures[SOUTH]);

		tex_width = textures[NORTH].getSize().x;
		tex_height = textures[NORTH].getSize().y;
	}


	////////////////////////////////////////////////////////////
	void AnimatedSprite::update(float delta)
	{
		SpriteComponent::update(delta);

		if (!playerInput)
			playerInput = getOwner()->getComponent<InputComponent>();

		if (playerInput)
			sprite.setTexture(textures[playerInput->getFacing()]);
	}

}	// namespace Engine
