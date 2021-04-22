#include "Skin.h"
CurrentSkin Skin::doodles; //<-- whaaat ???

CurrentSkin& Skin::getCurrentSkin()
{
	return doodles;
}

void Skin::setNewSkin(std::pair<sf::Texture, sf::Texture> newSkin)
{
	doodles.first = newSkin.first;
	doodles.second = newSkin.second;
}

void Skin::setDefaultSkin(TextureHolder* textureHolder)
{
	doodles.first = sf::Texture(textureHolder->get("PLAYER"));
	doodles.second = sf::Texture(textureHolder->get("PLAYER_JUMP"));
}


