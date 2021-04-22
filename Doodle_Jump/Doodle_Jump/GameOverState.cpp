#include "GameOverState.h"
#include "StatesStack.h"
#include "MenuState.h"
#include "GameState.h"

GameOverState::GameOverState(std::shared_ptr<EssentialData> data, std::pair<int, int> scores) : State(data), scores(std::move(scores))
{
	background.setTexture(data->textureHolder->get("BACKGROUND"));

	//initialize buttons
	buttons.emplace_back(std::make_unique<Button>(data->textureHolder, "replay", false, sf::Vector2f(SCREEN_WIDTH / 2.f, 550.f), 0.f));
	buttons.emplace_back(std::make_unique<Button>(data->textureHolder, "menu", false, sf::Vector2f(SCREEN_WIDTH / 2.f, 550.f), 150.f));
	initText();
}

void GameOverState::handleInputState(sf::Event& event)
{
	for (auto& button : buttons)
	{
		if (button->isButtonPressed(event))
		{
			switchState(button->getButtonName());
			break;
		}
		button->handleInput(event, data->window);
		button->update();
	}
}

void GameOverState::updateState(const float& dt)
{
	data->window->setView(view.resize(data->window->getSize()));
}

void GameOverState::renderState()
{
	data->window->draw(background);
	data->window->draw(score);
	data->window->draw(gameOver);

	//render buttons
	for (auto& button : buttons)	button->render(data->window);
}

void GameOverState::switchState(const std::string& buttonName)
{
	if (buttonName == "replay")
		data->gameStack->setState<GameState>(data);
	else if (buttonName == "menu")
		data->gameStack->setState<MenuState>(data);
}

void GameOverState::initText()
{
	font.loadFromFile("Textures/DoodleJump.ttf");
	
	score.setFont(font);
	score.setString("your score: " + std::to_string(scores.first) +"\nyour high score: " + std::to_string(scores.second));
	score.setCharacterSize(static_cast<unsigned>(45.f));
	score.setFillColor(sf::Color::Black);
	score.setOutlineColor(sf::Color::Black);
	score.setOutlineThickness(0.4f);
	score.setPosition(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT * 0.4);

	gameOver.setFont(font);
	gameOver.setString("Game Over!");
	gameOver.setCharacterSize(static_cast<unsigned>(120.f));
	gameOver.setFillColor(sf::Color::Red);
	gameOver.setOutlineColor(sf::Color::Black);
	gameOver.setOutlineThickness(2.f);
	gameOver.setRotation(-15.f);
	gameOver.setPosition(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT * 0.15);


	const auto textRect = score.getLocalBounds();
	score.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f); //Make the origin in center

	const auto gametextRect = gameOver.getLocalBounds();
	gameOver.setOrigin(gametextRect.left + gametextRect.width / 2.0f, gametextRect.top + gametextRect.height / 2.0f); //Make the origin in center
}
