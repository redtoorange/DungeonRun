#pragma once
#include "Screen.h"

#include "CameraController.h"
#include "MouseController.h"
#include "PhysicsController.h"

#include "Entity.h"
#include "TiledMap.h"
#include "TiledMapRenderer.h"

#define DEBUG 0

namespace Engine
{
	class Player;
	class Map;
	class GameEngine;

	class GameScreen : public Screen
	{
	public:
		GameScreen(GameEngine* engine );
		virtual ~GameScreen() = default;


		void draw(sf::RenderWindow* window) override;
		void update(float delta) override;
		void handleInput(sf::RenderWindow* window) override;
	

	private:
		TiledMap levelOne;
		TiledMap levelTwo;

		TiledMapRenderer tiledRenderer;

		Entity root;

		Player* p = nullptr;
	
		CameraController cController;
		PhysicsController pController;
		MouseController mController;

		float totalTime = 0;
		int frames = 0;
	};
}	//	namespace Engine


