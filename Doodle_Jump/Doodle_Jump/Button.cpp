#include "Button.h"
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Event.hpp>


Button::Button(TextureHolder* textureHolder, std::string buttonName, const bool centerButton, const sf::Vector2f pos, 
	const float& offset, const float& fontSize) :
	buttonName(std::move(buttonName)),
	isMouseOver(false),
	scale(1.f, 1.f)
{
	sprite.setTexture(textureHolder->get("BUTTON"));

	//Set origin to the center of the button
	const auto textRect = sprite.getLocalBounds();
	sprite.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);

	//Set position of the button
	if (centerButton)
		sprite.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT * 0.33f + offset);
	else
		sprite.setPosition(pos.x, pos.y + offset);
	
	buttonArea = sf::IntRect(sprite.getGlobalBounds());
	initText(fontSize);
}

void Button::render(sf::RenderWindow* window) const
{
	window->draw(sprite);
	window->draw(text);
}

//bool Button::isButtonPressed(sf::RenderWindow* window) const
//{
//	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
//		if (isMouseOver) //Check if a point is inside the rectangle's area
//			return true;
//	
//	return false;
//}

bool Button::isButtonPressed(sf::Event& event) const
{
	if(isMouseOver)
	{
		if (event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
			return true;
	}
	return false;
}

std::string Button::getButtonName() const { return buttonName; }

void Button::unActive()
{
	sprite.setColor(sf::Color(255, 255, 255, 255)); //Alpha
	sprite.setScale(scale);
	text.setScale(scale);
}

void Button::active()
{
	sprite.setColor(sf::Color(255, 77, 77, 180)); //Red
	sprite.setScale(scale * 1.1f);
	text.setScale(scale * 1.1f);
}

void Button::changeScale(const sf::Vector2f& newScale)
{
	sprite.setScale(scale);
	scale = newScale;
}


void Button::handleInput(sf::Event &event, sf::RenderWindow* window)
{
	const auto mousePosition = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
	if (sprite.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
		isMouseOver = true;
	else
		isMouseOver = false;
}

void Button::update()
{
	if (isMouseOver)
		active();
	else
		unActive();
}

void Button::initText(const float& fontSize)
{
	font.loadFromFile("Textures/doodle.ttf");

	//Text init
	text.setFont(font);
	text.setString(buttonName);
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(static_cast<unsigned>(fontSize));
	text.setOutlineThickness(BUTTON_TEXT_THICKNESS);

	//Set origin in the center
	const auto textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);

	//Position text in the center of the box
	text.setPosition({getX(), getY()});
}
