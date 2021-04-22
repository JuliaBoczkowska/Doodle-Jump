#include "Player.h"

#include <iostream>
#include <SFML/Window/Event.hpp>

#include "Skin.h"
#include "SFML/Window/Keyboard.hpp"


Player::Player(TextureHolder* textureHolder):
	jumpOnce(true), firstMove(true),
	jumpHeight(JUMP_HEIGHT),
	direction(Direction::Right)
{
	initSprite();

	//Down side of the dooodle, collision box
	rect = sf::FloatRect(35, getLocalHeight() - static_cast<float>(30), getLocalWidth() - 68, 29); 
}

void Player::update(const float& dt, const float& bottomEdgeWindow)
{
	jump(dt, bottomEdgeWindow);
	movePlayer(dt);
	flipSprite();
}

void Player::render(sf::RenderWindow* window) const { window->draw(sprite); }


void Player::movePlayer(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		direction = Direction::Left;

		if (velocity.x <= -MAX_VELOCITY);
		else
			velocity.x -= 20.f;

		//If player is out of screen bounds move to the right side of the screen
		if (sprite.getPosition().x + sprite.getLocalBounds().width <= 0)
			sprite.setPosition(SCREEN_WIDTH - sprite.getLocalBounds().width / 2, sprite.getPosition().y);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		direction = Direction::Right;

		if (velocity.x >= MAX_VELOCITY);
		else
			velocity.x += 20.f;

		//If player is out of screen bounds move to the left side of the screen
		if (sprite.getPosition().x >= SCREEN_WIDTH)
			sprite.setPosition(0 - sprite.getLocalBounds().width / 2, sprite.getPosition().y);
	}

	else if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
		velocity.x = 0.f;

	//Update movement
	sprite.move(velocity * dt);
}

void Player::endFirstMove() { firstMove = false; 	std::cout << "called once";}

void Player::notFalling(const float& posY)
{
	if (sprite.getPosition().y > posY)
	{
		sprite.setPosition(sprite.getPosition().x, posY);

		//Stop falling
		velocity.y = 0;
		
		//Bounce from invisible ground
		jumpOnce = true;
	}
}

void Player::initSprite()
{
	sprite.setTexture(Skin::getCurrentSkin().first);
	sprite.setOrigin(0, 0);
	setPosition(sf::Vector2f(SCREEN_WIDTH / 2, GROUND_HEIGHT));
	sprite.setScale(sf::Vector2f(0.9f, 0.9f));
}

void Player::allowJump() { jumpOnce = true; }

void Player::jump(const float& dt, const float& posY)
{
	//Jump once and then lose velocity
	if (jumpOnce)
	{
		//Change sprite to jumping
		sprite.setTexture(Skin::getCurrentSkin().second);

		//Calculating initial velocity using kinematic equation, final velocity is zero.
		velocity.y = -sqrtf(2.0f * GRAVITY * jumpHeight);
		jumpOnce = false;
		jumpHeight = JUMP_HEIGHT;
	}

	//Lose velocity
	velocity.y += GRAVITY * dt; //apply gravity to playerSprite

	//If first move, don't fall
	if (firstMove)
		notFalling(posY);

	//If player is falling set diff texture
	if (velocity.y > 0)
		sprite.setTexture(Skin::getCurrentSkin().first);

	sprite.move(velocity * dt);
}

void Player::flipSprite()
{
	switch (direction)
	{
	case Direction::Right:
		flipSpriteRight(sprite);
		break;
	case Direction::Left:
		flipSpriteLeft(sprite);
		break;
	}
}

inline void Player::flipSpriteLeft(sf::Sprite& player)
{
	player.setTextureRect(sf::IntRect(static_cast<int>(player.getLocalBounds().width), 0,
	                                  static_cast<int>(-player.getLocalBounds().width),
	                                  static_cast<int>(player.getLocalBounds().height)));
}

inline void Player::flipSpriteRight(sf::Sprite& player)
{
	player.setTextureRect(sf::IntRect(0, 0, static_cast<int>(player.getLocalBounds().width),
	                                  static_cast<int>(player.getLocalBounds().height)));
}

float Player::getVelocity() const { return velocity.y; }
