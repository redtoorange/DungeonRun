#include "SpriteComponent.h"
#include "Entity.h"
#include <iostream>

namespace Engine
{
	SpriteComponent::SpriteComponent(Entity* owner) : Component(owner)
	{
	}


	SpriteComponent::SpriteComponent(Entity* owner, const std::string& path) : Component(owner)
	{
		if (texture.loadFromFile(path))
		{
			sprite.setTexture(texture);

			tex_width = texture.getSize().x;
			tex_height = texture.getSize().y;
		}
		else
		{
			std::cout << "Fail to load <" << path << ">" << std::endl;
		}

	}


	void SpriteComponent::update(float delta)
	{
		//update the sprite's position
		auto& t = getOwner()->getTransform();

		sprite.setScale(t.getWidth() / tex_width, t.getHeight() / tex_height);
		sprite.setPosition(t.getX() - (t.getWidth() / 2.0f), t.getY() - (t.getHeight() / 2.0f));
		sprite.setRotation(t.getRotation());
	}

	void SpriteComponent::draw(sf::RenderWindow& window)
	{
		//draw the sprite
		window.draw(sprite);
	}

}	//	namespace Engine

