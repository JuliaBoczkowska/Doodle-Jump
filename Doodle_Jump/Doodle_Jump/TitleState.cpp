#include "TitleState.h"
#include "MenuState.h"
#include "Constants.h"
#include "Skin.h"
#include "StatesStack.h"


TitleState::TitleState(std::shared_ptr<EssentialData> data):
	State(data),
	platformGenerator(data->textureHolder)
{
	loadTextures();
	initText();
	generateBackground();
}

bool TitleState::requestChange() const
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		return true;

	if (clock.getElapsedTime().asSeconds() > TITLE_STATE_TIME)
		return true;

	return false;
}

void TitleState::handleInputState(sf::Event& event) {}

void TitleState::updateState(const float& dt)
{
	for (auto& platform : platforms)
		platform->update(dt);

	if (requestChange())
		data->gameStack->setState<MenuState>(data);
}

void TitleState::renderState()
{
	data->window->draw(sprite);

	//render platforms
	for (auto& platform : platforms)
		platform->render(data->window);

	data->window->draw(text);
	data->window->draw(textSecond);
}

void TitleState::generateBackground() { platformGenerator.spawnPlatforms(platforms, 0, 4500); }

void TitleState::initText()
{
	font.loadFromFile("Textures/doodle.ttf");

	text.setFont(font);
	text.setString("Doodle jump!");
	text.setCharacterSize(static_cast<unsigned>(130.f));
	text.setFillColor(sf::Color::Black);
	text.setOutlineColor(sf::Color::White);
	text.setOutlineThickness(2.5f);

	textSecond.setFont(font);
	textSecond.setString("Assignment\n  Edition!");
	textSecond.setCharacterSize(static_cast<unsigned>(70.f));
	textSecond.setFillColor(sf::Color::Black);
	textSecond.setOutlineColor(sf::Color::White);
	textSecond.setOutlineThickness(2.5f);
	textSecond.setRotation(-26.f);

	const auto textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	text.setPosition({SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f}); //Position text in the center of the screen

	textSecond.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	textSecond.setPosition({SCREEN_WIDTH, SCREEN_HEIGHT - 200}); //Position text in the center of the screen
}

void TitleState::loadTextures()
{
	data->textureHolder->load("PLAYER", "Textures/Doodle_4.png");
	data->textureHolder->load("PLAYER_JUMP", "Textures/Doodle_4_4.png");
	data->textureHolder->load("BACKGROUND", "Textures/background.png");
	data->textureHolder->load("RED", "Textures/red.png");
	data->textureHolder->load("RED_BROKEN", "Textures/redBroken.png");
	data->textureHolder->load("DEFAULT", "Textures/default.png");
	data->textureHolder->load("BLUE", "Textures/blue.png");
	data->textureHolder->load("SPRING", "Textures/spring.png");
	data->textureHolder->load("SPRING_BROKEN", "Textures/spring_broken.png");
	data->textureHolder->load("CLOUD", "Textures/white.png");	
	sprite.setTexture(data->textureHolder->get("BACKGROUND"));
	Skin::setDefaultSkin(data->textureHolder);
}


