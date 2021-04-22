#include "View.h"
#include "Constants.h"

View::View() : falling(false), posY(0) { }

sf::View View::view = sf::View(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));

void View::followPlayer(const sf::Sprite& sprite)
{
	if (sprite.getPosition().y < view.getCenter().y)
		view.setCenter(SCREEN_WIDTH / 2, sprite.getPosition().y);

	if (!falling)
	{
		if ((sprite.getPosition().y + sprite.getLocalBounds().height / 2) >= getBottomEdge().y)
		{
			view.setCenter(SCREEN_WIDTH / 2, sprite.getPosition().y);
			falling = true;
		}
	}
	else
	{
		//Disappearing of the character
		posY += 15.f;
		view.setCenter(SCREEN_WIDTH / 2, sprite.getPosition().y + view.getSize().y / 2 - posY );
	}	
}

sf::View& View::getView()
{
	return view;
}

sf::View View::resize(const sf::Vector2u& windowSize)
{
	viewport = sf::FloatRect(0.f, 0.f, 1.f, 1.f); //The last two variables is a ratio of a window
		
	const auto screenWidth = static_cast<float>(windowSize.x) / SCREEN_WIDTH;		//new width ratio
	const auto screenHeight = static_cast<float>(windowSize.y) / SCREEN_HEIGHT;	//new height ratio

	if(screenWidth > screenHeight)
	{
		viewport.width = screenHeight / screenWidth;
		viewport.left = (1.f - viewport.width) / 2.f;
	}
	else if(screenHeight > screenWidth)
	{
		viewport.height = screenWidth / screenHeight;
		viewport.top = (1.f - viewport.height) / 2.f;
	}

	//When window is resized we need to set a new view
	view = sf::View(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
	view.setViewport(viewport);
	return view;
}

sf::Vector2f View::getBottomEdge() { return  view.getCenter() + (view.getSize() / 2.0f); }

sf::Vector2f View::getTopEdge() { return  view.getCenter() - (view.getSize() / 2.0f); }
