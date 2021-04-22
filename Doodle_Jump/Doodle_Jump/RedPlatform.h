#ifndef REDPLATFORM_H
#define REDPLATFORM_H
#include "DefaultPlatform.h"

/** @class RedPlatform
 *  Class that is the child of Default platform.
 *  It defines a new type of platform which breaks automatically when touched by player.
 */
class RedPlatform: public DefaultPlatform
{
public:
	
	/**
	 * \brief Constructor of the RedPlatform.
	 * \param textureHolder Used to load textures into a sprite.
	 */
	explicit RedPlatform(TextureHolder* textureHolder);
	
	/**
	 * \brief Destructor of the RedPlatform
	 */
	~RedPlatform() = default;

	/**
	 * \brief Checks if the platform has been touched by a player.
	 *		  If yes, the sprite is changed.
	 * \param dt Makes the game frame rate independent
	 */
	void update(const float& dt) override;

	/**
	 * \brief Defines what will happen after detecting collision with a player.
	 *		  In this case platform breaks.
	 * \param player Thanks to this parameter the platform controls the time in which player will bounce from the platform.
	 */
	void onCollision(Player & player) override;

	
	/**
	 * \brief Sets texture to a broken platform.
	 */
	void breakPlatform();

private:
	TextureHolder& textureHolder;	///< Reference to a texture textureHolder created in class GameData.
	bool isBroken;					///< A variable that determine if the player has touched a platform.
};

#endif

