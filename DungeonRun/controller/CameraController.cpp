#include "CameraController.h"
#include <iostream>

namespace Engine
{
	CameraController::CameraController(const sf::Vector2f& pos, const sf::Vector2f& size) :
		target(pos), current(pos), size(size)
	{
	}

	// Update the camera's position and size in preparation for drawing.
	void CameraController::update()
	{
		view.setSize(size);

		current.x = (smoothing * current.x) + ((1.0f - smoothing) * target.x);
		if (abs(current.x - target.x) <= threshold) current.x = target.x;

		current.y = (smoothing * current.y) + ((1.0f - smoothing) * target.y);
		if (abs(current.y - target.y) <= threshold) current.y = target.y;

		view.setCenter(current);
	}


	sf::View& CameraController::get_view()
	{
		return view;
	}

	void CameraController::setSize(float w, float h)
	{
		setSize({ w,h });
	}


	void CameraController::setSize(const sf::Vector2f& s)
	{
		size.x = s.x;
		size.y = s.y;
	}

	void CameraController::translate(float x, float y)
	{
		translate({ x, y });
	}

	void CameraController::translate(const sf::Vector2f& pos)
	{
		target.x = pos.x;
		target.y = pos.y;
	}


	void CameraController::setPos(float x, float y)
	{
		setPos({ x, y });
	}

	void CameraController::setPos(const sf::Vector2f& pos)
	{
		target = pos;
		current = pos;
		view.setCenter(pos);
	}

	float CameraController::getWidth() const
	{
		return size.x;
	}

	float CameraController::getHeight() const
	{
		return size.y;
	}

}	//	namespace Engine

