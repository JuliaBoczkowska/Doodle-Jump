#include "Entity.h"

sf::Sprite& Entity::getSprite() { return sprite; }

float Entity::getX() const { return sprite.getPosition().x; }

float Entity::getY() const { return sprite.getPosition().y; }

float Entity::getWidth() const { return (sprite.getPosition().x + sprite.getLocalBounds().width); }

float Entity::getHeight() const { return (sprite.getPosition().y + sprite.getLocalBounds().height); }

float Entity::getLocalWidth() const { return sprite.getLocalBounds().width; }

float Entity::getLocalHeight() const { return sprite.getLocalBounds().height; }

void Entity::setPosition(const sf::Vector2f& pos) { sprite.setPosition(pos);  }

void Entity::setOriginCenter(sf::Vector2f)
{
	const auto boundaries = sprite.getLocalBounds();
	sprite.setOrigin((boundaries.top + boundaries.width) / 2.f, (boundaries.left + boundaries.height) / 2.f);
}



