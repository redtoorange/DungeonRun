#pragma once
#include <SFML/Graphics.hpp>

namespace Engine
{
	class CameraController
	{
	public:
		CameraController(const sf::Vector2f& = { 0, 0 }, const sf::Vector2f& = { 16, 9 });

		void update();
		sf::View& get_view();

		void setSize(float w, float h);
		void setSize(const sf::Vector2f& s);

		void translate(float x, float y);
		void translate(const sf::Vector2f& pos);

		void setPos(float x, float y);
		void setPos(const sf::Vector2f& pos);

		float getWidth() const;
		float getHeight() const;

	private:
		sf::View view;

		sf::Vector2f target;
		sf::Vector2f current;
		sf::Vector2f size;

		const float smoothing = 0.95f;
		const float threshold = 0.01f;
	};
}	//	namespace Engine
