#pragma once

#include <SFML/Graphics.hpp>
#include "CameraController.h"

namespace Engine
{
	class MouseController
	{
	public:
		MouseController(sf::RenderWindow* window);
		void update();

		//	void handleDragging() const;
		void handleZooming(sf::Event& events, CameraController& cController);
		void handleClicking(sf::Event& events);

	private:
		sf::RenderWindow* window = nullptr;
		//	Map* tileMap = nullptr;
		//	MapTile* hoveredTile = nullptr;

		bool left_held;
		bool middle_held;
		bool right_held;
	};

}	//	namespace Engine

