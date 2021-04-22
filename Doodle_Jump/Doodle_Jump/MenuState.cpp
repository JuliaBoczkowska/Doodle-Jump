#include "MenuState.h"

#include "Button.h"
#include "Constants.h"
#include "CustomizeState.h"
#include "GameState.h"
#include "StatesStack.h"

MenuState::MenuState(std::shared_ptr<EssentialData> data) :
	State(data),
	player(data->textureHolder),
	platform(data->textureHolder)
{
	//load texturesc
	data->textureHolder->load("BUTTON", "Textures/button.png");

	//initialize sprites
	background.setTexture(data->textureHolder->get("BACKGROUND"));

	//initialize buttons
	buttons.emplace_back(std::make_unique<Button>(data->textureHolder, "play", true, sf::Vector2f(0.f, 0.f), 0.f));
	buttons.emplace_back(std::make_unique<Button>(data->textureHolder, "customize", true, sf::Vector2f(0.f, 0.f), 120.f));
	buttons.emplace_back(std::make_unique<Button>(data->textureHolder, "exit", true, sf::Vector2f(0.f, 0.f), 240.f));

	//initialize player and platform
	initText();
	initObjects();
}

void MenuState::switchState(const std::string& buttonName) const
{
	if (buttonName == "play")
		data->gameStack->setState<GameState>(data);

	else if (buttonName == "exit")
		data->window->close();

	else if (buttonName == "customize")
		data->gameStack->setState<CustomizeState>(data);
}

void MenuState::initObjects()
{
	//Set position of a player
	platform.setOriginCenter();
	platform.setPosition(sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 100));

	//Set position of a platform
	player.setOriginCenter();
	player.setPosition(sf::Vector2f(SCREEN_WIDTH / 2 , SCREEN_HEIGHT - 105.f - platform.getLocalHeight()));
}

void MenuState::handleInputState(sf::Event& event)
{
	for (auto& button : buttons)
	{
		if (button->isButtonPressed(event))
		{
			switchState(button->getButtonName());
			break;
		}
		button->handleInput(event, data->window);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		data->window->close();
}

void MenuState::updateState(const float& dt)
{
	player.jump(dt, platform.getY() - 50);
	for (auto& button : buttons)
	{
		button->update();
	}
}

void MenuState::renderState()
{
	//render background
	data->window->draw(background);
	data->window->draw(text);

	//render buttons
	for (auto& button : buttons) button->render(data->window);

	//render player and platform
	platform.render(data->window);
	player.render(data->window);
}


void MenuState::initText()
{
	font.loadFromFile("Textures/DoodleJump.ttf");
	text.setFont(font);
	text.setString("Doodle Jump");
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(100);
	text.setOutlineThickness(BUTTON_TEXT_THICKNESS);
	text.setPosition({120.f, 100.f});
}
