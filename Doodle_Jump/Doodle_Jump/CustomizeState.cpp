#include "CustomizeState.h"
#include "StatesStack.h"
#include "MenuState.h"

CustomizeState::CustomizeState(const std::shared_ptr<EssentialData> data):
State(data),
next(std::make_unique<Button>(data->textureHolder, "->", false, sf::Vector2f(SCREEN_WIDTH * 0.84f, SCREEN_HEIGHT / 2.f), -60.f)),
prev(std::make_unique<Button>(data->textureHolder, "<-", false, sf::Vector2f(SCREEN_WIDTH * 0.17f, SCREEN_HEIGHT / 2.f), -60.f)),
save(std::make_unique<Button>(data->textureHolder, "save&return", false, sf::Vector2f(SCREEN_WIDTH * 0.7, SCREEN_HEIGHT * 0.85f), 0.f, 40.f)),
vectorIndex(0)
{
	loadTextures(*data->textureHolder);
	initButtons();
	initDoodle();
}

void CustomizeState::handleInputState(sf::Event& event)
{
	for (const auto& button : buttons)
	{
		button->handleInput(event, data->window);
		
		if (button->isButtonPressed(event))
			switchState(button->getButtonName());
	}	
}

void CustomizeState::switchState(const std::string& buttonName)
{
	if (buttonName == "save&return")
	{
		Skin::setNewSkin(doodles[vectorIndex]);
		data->gameStack->setState<MenuState>(data);
	}
		
	if (buttonName == "->")
		changeSprite(Position::Next);
	
	if (buttonName == "<-")
		changeSprite(Position::Previous);
}


void CustomizeState::initButtons()
{
	save->changeScale(sf::Vector2f(1.f, 1.f));
	prev->changeScale(sf::Vector2f(0.7f, 1.f));
	next->changeScale(sf::Vector2f(0.7f, 1.f));
	
	buttons.emplace_back(std::move(next));
	buttons.emplace_back(std::move(prev));
	buttons.emplace_back(std::move(save));
}

void CustomizeState::initDoodle()
{
	currentDoodle.setTexture(doodles[vectorIndex].first);

	const auto boundaries = currentDoodle.getLocalBounds();
	currentDoodle.setOrigin((boundaries.top + boundaries.width) / 2.f, (boundaries.left + boundaries.height) / 2.f);
	currentDoodle.setScale(sf::Vector2f(1.5f, 1.5f));
	currentDoodle.setPosition(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT * 0.45);
}

void CustomizeState::updateState(const float& dt)
{	
	for (const auto& button : buttons)
		button->update();
}

void CustomizeState::renderState()
{
	//Draw background
	data->window->draw(background);

	//Draw Doodle
	currentDoodle.setTexture(doodles[vectorIndex].first);
	data->window->draw(currentDoodle);

	//Draw Buttons
	for (auto& button : buttons)	button->render(data->window);
}

void CustomizeState::changeSprite(const Position& position)
{
	switch (position)
	{
		case Position::Next:
		{
			if (vectorIndex == doodles.size() - 1)
				vectorIndex = 0;
			else
				++vectorIndex;
			break;
		}
		case Position::Previous:
		{
			if (vectorIndex == 0)
				vectorIndex = doodles.size() - 1;
			else
				--vectorIndex;
			break;
		}
	}
}


void CustomizeState::loadTextures(TextureHolder& textureHolder)
{
	textureHolder.load("Doodle_1", "Textures/CUSTOM/Doodle_1.png");
	textureHolder.load("Doodle_1_1", "Textures/CUSTOM/Doodle_1_1.png");
	doodles.emplace_back(std::make_pair(sf::Texture(textureHolder.get("Doodle_1")), sf::Texture(textureHolder.get("Doodle_1_1"))));

	textureHolder.load("Doodle_3", "Textures/CUSTOM/Doodle_3.png");
	textureHolder.load("Doodle_3_3", "Textures/CUSTOM/Doodle_3_3.png");
	doodles.emplace_back(std::make_pair(sf::Texture(textureHolder.get("Doodle_3")), sf::Texture(textureHolder.get("Doodle_3_3"))));

	textureHolder.load("Doodle_4", "Textures/CUSTOM/Doodle_4.png");
	textureHolder.load("Doodle_4_4", "Textures/CUSTOM/Doodle_4_4.png");
	doodles.emplace_back(std::make_pair(sf::Texture(textureHolder.get("Doodle_4")), sf::Texture(textureHolder.get("Doodle_4_4"))));

	textureHolder.load("Doodle_5", "Textures/CUSTOM/Doodle_5.png");
	textureHolder.load("Doodle_5_5", "Textures/CUSTOM/Doodle_5_5.png");
	doodles.emplace_back(std::make_pair(sf::Texture(textureHolder.get("Doodle_5")), sf::Texture(textureHolder.get("Doodle_5_5"))));

	textureHolder.load("Doodle_6", "Textures/CUSTOM/Doodle_6.png");
	textureHolder.load("Doodle_6_6", "Textures/CUSTOM/Doodle_6_6.png");
	doodles.emplace_back(std::make_pair(sf::Texture(textureHolder.get("Doodle_6")), sf::Texture(textureHolder.get("Doodle_6_6"))));

	data->textureHolder->load("CUSTOM", "Textures/CUSTOM/custom.png");
	background.setTexture(data->textureHolder->get("CUSTOM"));
}
