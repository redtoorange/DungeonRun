#include "Vector2D.h"

namespace Engine
{
	Vector2D::Vector2D(float x, float y): x(x),y(y)
	{
	}

	Vector2D::Vector2D(const sf::Vector2f& other): x(other.x), y(other.y)
	{
	}


	Vector2D::Vector2D(const b2Vec2& other) : x(other.x), y(other.y)
	{
	}


	float Vector2D::length() const
	{
		return sqrt(x * x + y * y);
	}

	bool Vector2D::isZero() const
	{
		return x == 0 && y == 0;
	}

	Vector2D& Vector2D::setZero()
	{
		this->x = 0;
		this->y = 0;
		return *this;
	}

	Vector2D& Vector2D::set(float x, float y)
	{
		this->x = x;
		this->y = y;
		return *this;
	}

	Vector2D& Vector2D::normalize()
	{
		const float len = length();
		if (len != 0) {
			x /= len;
			y /= len;
		}
		return *this;
	}

	Vector2D& Vector2D::clamp(float min, float max)
	{
		const float len = length();
		if (len == 0) return *this;
	
		float max2 = max * max;
		if (len > max2) return scale(sqrt(max2 / len));
	
		float min2 = min * min;
		if (len < min2) return scale(sqrt(min2 / len));
	
		return *this;
	}

	Vector2D& Vector2D::scale(float scalar)
	{
		x *= scalar;
		y *= scalar;
		return *this;
	}

}	//	namespace Engine
