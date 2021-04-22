#include "Score.h"

//Initializing static variable
int Score::highestScore = 0;

Score::Score(): currentScore(0)
{
	initText();
	initRectangle();
}

void Score::update(Player& player, const std::vector<std::unique_ptr<Platform>>& platforms)
{
	AddToScore(player, platforms);
}

void Score::render(sf::RenderWindow* window) 
{
	counter.setString(std::to_string(currentScore));
	window->draw(rectangle);
	window->draw(counter);
}

void Score::AddToScore(Player& player, const std::vector<std::unique_ptr<Platform>>& platforms)
{
	for(const auto &platform : platforms)
	{
		if (!platform->isPassed)
		{
			if (player.getHeight() < platform->getY())
			{
				platform->isAbovePlatform();	
				currentScore += 50;
			}
		}
	}
}

void Score::initText()
{
	font.loadFromFile("Textures/DoodleJump.ttf");
	counter.setFont(font);
	counter.setCharacterSize(static_cast<unsigned>(40.f));
	counter.setFillColor(sf::Color::Black);
	counter.setOutlineColor(sf::Color::Black);
	counter.setOutlineThickness(0.4f);

	highScore.setFont(font);
	highScore.setCharacterSize(static_cast<unsigned>(40.f));
	highScore.setFillColor(sf::Color::Black);
	highScore.setOutlineColor(sf::Color::Black);
	highScore.setOutlineThickness(0.4f);

	auto textRect = counter.getLocalBounds();
	counter.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f); //Make the origin in center
	
	textRect = highScore.getLocalBounds();
	highScore.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f); //Make the origin in center
}

void Score::initRectangle()
{
	rectangle.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT * 0.07f));
	rectangle.setFillColor(sf::Color(173, 194, 235, 130));
}

void Score::setPosition(const sf::Vector2f &pos)
{
	rectangle.setPosition(pos.x, pos.y);
	counter.setPosition({ pos.x + 7, pos.y + 7 });
}

void Score::setHighScore() const
{
	if (currentScore > highestScore)
		highestScore = currentScore;
}

const int& Score::getCurrentScore() const
{
	return currentScore;
}

void Score::displayHighestScore(sf::RenderWindow* window)
{
	counter.setString(std::to_string(currentScore));
	highScore.setString(std::to_string(highestScore));
	window->draw(counter);
	window->draw(highScore);
}

std::pair<int, int> Score::getScores() const
{
	return {currentScore, highestScore};
}

