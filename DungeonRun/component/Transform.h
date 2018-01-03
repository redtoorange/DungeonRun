#pragma once
#include "Component.h"
#include <ostream>

namespace Engine
{
	class Transform : Component
	{
	public:
		Transform( Entity* owner );
		~Transform() = default;

		float getX() const;
		float getY() const;

		void setX(float x);
		void setY(float y);

		void setPos(float x, float y);

		float getWidth() const;
		float getHeight() const;

		void setWidth(float w);
		void setHeight(float h);

		void setSize(float w, float h);

		float getRotation() const;
		void setRotation(float rot);


		void update(float delta) override;
		void draw(sf::RenderWindow& window) override;

	private:
		float x = 0;
		float y = 0;

		float w = 1;
		float h = 1;

		float rot = 0;
	};

	inline std::ostream& operator<<(std::ostream& os, const Transform& t)
	{
		os  << "Pos: (" << t.getX() << ", " << t.getY() << ")\n"
			<< "\tScale: (" << t.getWidth() << ", " << t.getHeight() << ")\n"
			<< "\tRot: " << t.getRotation();

		return os;
	}
}	// namespace Engine


