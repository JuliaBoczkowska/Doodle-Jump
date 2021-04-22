#include "MovingPlatform.h"
#include "Constants.h"

#include <random>



MovingPlatform::MovingPlatform(TextureHolder* textureHolder):
Platform(textureHolder),
DefaultPlatform(textureHolder)
{
	sprite.setTexture(textureHolder->get("BLUE"));
	
	static std::random_device dev;
	static std::mt19937 engine(dev());
	static std::bernoulli_distribution randDirection(0.50);
	
	direction = randDirection(engine) ? Direction::Right : Direction::Left;
	velocity = { 2.f, 0.f };
}


void MovingPlatform::update(const float& dt)
{
	if (sprite.getPosition().x <= 0)
		direction = Direction::Right;
	
	else if (sprite.getPosition().x + sprite.getLocalBounds().width >= SCREEN_WIDTH)
		direction = Direction::Left;
	
	if(direction == Direction::Right)
		sprite.move(sf::Vector2f(velocity.x, 0));
	
	else if (direction == Direction::Left)
		sprite.move(sf::Vector2f(-velocity.x, 0));
}
