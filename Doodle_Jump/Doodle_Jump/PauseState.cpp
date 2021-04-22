#include "PauseState.h"

#include "Button.h"
#include "Constants.h"
#include "StatesStack.h"

PauseState::PauseState(std::shared_ptr<EssentialData> data) : 
State(data),
button(std::make_unique<Button>(data->textureHolder, "resume", false,  sf::Vector2f(370.f, 750.f)))
{
	data->textureHolder->load("PAUSE", "Textures/pause.png");
	sprite.setTexture(data->textureHolder->get("PAUSE"));

	//Set the default view
	data->window->setView(sf::View(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)));
}

bool PauseState::requestChange(sf::Event& event) const
{
	if (button->isButtonPressed(event))
		return true;

	if (event.type == event.KeyPressed)
	{
		if(event.key.code == sf::Keyboard::Escape)
			return true;
	}
	return false;
}

void PauseState::handleInputState(sf::Event& event)
{
	button->handleInput(event, data->window);
	if (requestChange(event))
		data->gameStack->pop();
}

void PauseState::updateState(const float& dt)
{
	button->update();	
}

void PauseState::renderState()
{
	data->window->draw(sprite);
	button->render(data->window);
}
