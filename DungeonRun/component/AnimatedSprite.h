#pragma once
#include "SpriteComponent.h"
#include "InputComponent.h"

namespace Engine
{
	class Entity;

	class AnimatedSprite : public SpriteComponent
	{
	public:
		AnimatedSprite(Entity* owner);
		~AnimatedSprite() = default;

		// Update the facing and animation frame for the sprite
		void update(float delta) override;

	private:
		sf::Texture textures[4];

		InputComponent* playerInput = nullptr;
	};
}

