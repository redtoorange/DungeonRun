#include "MouseController.h"
#include "CameraController.h"
#include <iostream>

namespace Engine
{
	MouseController::MouseController(sf::RenderWindow* window) :
		window(window)
	{
	}

	void MouseController::update()
	{
		const auto worldPos = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
		//	MapTile* hovered = tileMap->getTileByPos(worldPos.x, worldPos.y);
		//	if (hovered != hoveredTile)
		//	{
		//		if (hoveredTile)
		//			hoveredTile->getRect()->setOutlineColor(sf::Color::Black);
		//
		//		hoveredTile = hovered;
		//
		//		if (hoveredTile)
		//			hoveredTile->getRect()->setOutlineColor(sf::Color::Magenta);
		//	}

		if (left_held)
		{
			std::cout << "Left Held" << std::endl;
		}
		if (right_held)
		{
			std::cout << "Right Held" << std::endl;
		}
		if (middle_held)
		{
			std::cout << "Middle Held" << std::endl;
		}
	}

	void MouseController::handleZooming(sf::Event& events, CameraController& cController)
	{
		float vWidth = cController.getWidth();
		float vHeight = cController.getHeight();

		if (events.type == sf::Event::MouseWheelScrolled)
		{
			if (events.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
			{
				if (events.mouseWheelScroll.delta > 0)
				{
					vWidth += 1.77777777778f;
					vHeight += 1;

					if (vWidth > 35.5555555556f) vWidth = 35.5555555556f;
					if (vHeight > 20) vHeight = 20;
				}
				else
				{
					vWidth -= 1.77777777778f;
					vHeight -= 1;

					if (vWidth < 1.77777777778f) vWidth = 1.77777777778f;
					if (vHeight < 1) vHeight = 1;
				}

			}
		}

		cController.setSize(vWidth, vHeight);
	}

	void MouseController::handleClicking(sf::Event& events)
	{
		if (events.type == sf::Event::MouseButtonPressed)
		{
			if (events.mouseButton.button == sf::Mouse::Left)
				left_held = true;
			else if (events.mouseButton.button == sf::Mouse::Right)
				right_held = true;
			else if (events.mouseButton.button == sf::Mouse::Middle)
				middle_held = true;


		}
		else if (events.type == sf::Event::MouseButtonReleased)
		{
			if (events.mouseButton.button == sf::Mouse::Left)
				left_held = false;
			else if (events.mouseButton.button == sf::Mouse::Right)
				right_held = false;
			else if (events.mouseButton.button == sf::Mouse::Middle)
				middle_held = false;
		}
	}

	//void MouseController::handleDragging() const
	//{
	//	if( hoveredTile)
	//	{
	//		if (left_held)
	//			hoveredTile->getRect()->setFillColor(sf::Color::Blue);
	//		else if (right_held)
	//			hoveredTile->getRect()->setFillColor(sf::Color::Red);
	//		else if (middle_held)
	//			hoveredTile->getRect()->setFillColor(sf::Color::Green);
	//	}
	//}

}	//	namespace Engine

