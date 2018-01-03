#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"

namespace Engine
{
	class SpriteComponent : public Component
	{
	public:
		SpriteComponent(Entity* owner);
		SpriteComponent(Entity* owner, const std::string& path);
		~SpriteComponent() = default;

		void update(float delta) override;
		void draw(sf::RenderWindow& window) override;

	protected:
		sf::Sprite sprite;
		sf::Texture texture;

		int tex_width = 1;
		int tex_height = 1;
	};
}	//	namespace Engine


