#include "Transform.h"

namespace Engine
{
	Transform::Transform(Entity* owner) : Component(owner)
	{
	}


	float Transform::getX() const
	{
		return x;
	}

	float Transform::getY() const
	{
		return y;
	}

	void Transform::setX(float x)
	{
		this->x = x;
	}

	void Transform::setY(float y)
	{
		this->y = y;
	}

	void Transform::setPos(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	float Transform::getWidth() const
	{
		return w;
	}

	float Transform::getHeight() const
	{
		return h;
	}

	void Transform::setWidth(float w)
	{
		this->w = w;
	}

	void Transform::setHeight(float h)
	{
		this->h = h;
	}

	void Transform::setSize(float w, float h)
	{
		this->w = w;
		this->h = h;
	}

	float Transform::getRotation() const
	{
		return rot;
	}

	void Transform::setRotation(float rot)
	{
		this->rot = rot;
	}


	void Transform::update(float delta)
	{
	}

	void Transform::draw(sf::RenderWindow& window)
	{
	}
}	// namespace Engine


