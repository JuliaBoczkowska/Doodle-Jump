#include "GameState.h"
#include "Constants.h"
#include "PauseState.h"
#include "StatesStack.h"
#include "GameOverState.h"

GameState::GameState(const std::shared_ptr<EssentialData> &data) : State(data), world(data) {}

void GameState::handleInputState(sf::Event& event) { checkPause(event); }

void GameState::updateState(const float& dt)
{
	world.update(dt);
	
	if (world.gameOver())
	{
		data->window->setView(sf::View(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)));
		data->gameStack->setState<GameOverState>(data, world.score.getScores());
	}
}

void GameState::renderState()
{
	world.render();
}

void GameState::checkPause(sf::Event& event)
{
	if (event.type == event.KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Escape)
				data->gameStack->push(std::make_unique<PauseState>(data));
	}	
}
