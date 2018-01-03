#include "GameScreen.h"

#include "BackGround.h"
#include "GameEngine.h"
#include "Player.h"



namespace Engine
{
	GameScreen::GameScreen( GameEngine* engine ) 
	: Screen(engine), mController(engine->getWindow())
	{	
//		root.addChild(new BackGround(&pController));

		p = new Player(&pController);
		root.addChild(p);

		levelOne.parseTiledMap("assets/maps/", "levelOne.tmx");
		levelTwo.parseTiledMap("assets/maps/", "levelTwo.tmx");

		tiledRenderer.setCurrentMap(&levelOne);
		tiledRenderer.setOffset({ -6, -6 });
	}


	void GameScreen::draw(sf::RenderWindow* window)
	{
		cController.update();
		window->setView(cController.get_view());

		window->clear(sf::Color(40, 40, 80));
	
		tiledRenderer.renderMap(*window);
		root.draw(*window);

		window->display();
	}

	void GameScreen::update(float delta)
	{

#if DEBUG>0
		totalTime += delta;
		frames++;

		if( totalTime >= 1)
		{
			std::cout << "FPS: " << frames << std::endl;
			frames = 0;
			totalTime = 0;
		}
#endif

		pController.step(delta);
		root.update(delta);

		mController.update();
		cController.translate(p->getTransform().getX(), p->getTransform().getY());

		if( sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1))
		{
			//swap to levelOne
			if( tiledRenderer.getCurrentMap() != &levelOne)
			{
				tiledRenderer.setCurrentMap(&levelOne);
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2))
		{
			//Swap to levelTwo
			if (tiledRenderer.getCurrentMap() != &levelTwo)
			{
				tiledRenderer.setCurrentMap(&levelTwo);
			}
		}
	}

	void GameScreen::handleInput(sf::RenderWindow* window)
	{
		sf::Event events{};
		while (window->pollEvent(events))
		{
			if (events.type == sf::Event::Closed || (events.type == sf::Event::KeyPressed && events.key.code == sf::Keyboard::Escape))
				engine->setRunning( false );

			mController.handleZooming(events, cController);
			mController.handleClicking(events);
		}

		//mController->handleDragging();
	}

}	//	namespace Engine

