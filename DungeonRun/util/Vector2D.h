#pragma once
#include "SFML/Graphics.hpp"
#include <Box2D/Common/b2Math.h>

namespace Engine
{
	class Vector2D
	{
	public:
		Vector2D() = default;
		~Vector2D() = default;

		Vector2D(float x, float y);
		Vector2D(const sf::Vector2f& other);
		Vector2D(const b2Vec2& other);

		float x;
		float y;


		float length() const;
		bool isZero() const;

		Vector2D& setZero();
		Vector2D& set(float x, float y);
		Vector2D& normalize();
		Vector2D& clamp( float min, float max);
		Vector2D& scale( float scalar);

	};

}	//	namespace Engine

