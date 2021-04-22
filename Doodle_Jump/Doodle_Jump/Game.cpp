#include "Game.h"
#include "TitleState.h"
#include "Constants.h"
#include "DefaultPlatform.h"
#include "MovingPlatform.h"
#include "RedPlatform.h"
#include "SpringPlatform.h"
#include "MovingSpringPlatform.h"
#include "CloudPlatform.h"


Game::Game():
	window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Doodle Jump"),
	essentialData(std::make_shared<EssentialData> (window, stateStack, textureHolder))
{
	stateStack.setState(std::make_unique<TitleState>(essentialData)); 
	window.setFramerateLimit(60);
}

void Game::run()
{
	sf::Clock clock; //Measures elapsed time
	auto elapsedSinceUpdate = sf::Time::Zero;

	if (stateStack.isEmpty()) //test delete after
		window.close();

	window.setView(view.resize(window.getSize()));
	window.setKeyRepeatEnabled(false);

	while (window.isOpen())
	{
		elapsedSinceUpdate += clock.restart(); //Returns the elapsed time since its start also restarts the clock.

		while (elapsedSinceUpdate > deltaTime)
		{
			elapsedSinceUpdate -= deltaTime; //we subtract the desired length of this frame delt
			handleInput();

			update(deltaTime.asSeconds()); //convert sf::Time value to float type.

			//before update stack might be empty
			if (stateStack.isEmpty())
				window.close();
		}
		render();
	}
}

void Game::handleInput()
{
	sf::Event event;
	
	while (window.pollEvent(event))
	{
		stateStack.getCurrent()->handleInputState(event);
		
		if (event.type == sf::Event::Closed)
			window.close();
		if (event.type == sf::Event::Resized)
			window.setView(view.resize(window.getSize()));
	}
}

void Game::update(const float& deltaTime)
{
	stateStack.getCurrent()->updateState(deltaTime);
}

void Game::render()
{
	window.clear();
	stateStack.getCurrent()->renderState();
	window.display();
}

