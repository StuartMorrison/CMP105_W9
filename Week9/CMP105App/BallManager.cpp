#include "BallManager.h"

BallManager::BallManager()
{
	spawnPoint = sf::Vector2f(350, 250);
	texture.loadFromFile("gfx/Beach_Ball.png");

	for (int i = 0; i < 20; i++)
	{
		balls.push_back(Ball());
		balls[i].setAlive(false);
		balls[i].setTexture(&texture);
		balls[i].setSize(sf::Vector2f(100, 100));
	}
}

BallManager::~BallManager()
{

}

void BallManager::update(float dt)
{
	for (int j = 0; j < balls.size(); j++)
	{
		if (balls[j].isAlive())
		{
			balls[j].update(dt);
		}
	}
	deathCheck();
}

void BallManager::spawn()
{
	int counter;
	for (int k = 0; k < balls.size(); k++)
	{
		counter = 0;
		if (!balls[k].isAlive())
		{
			balls[k].setAlive(true);
			balls[k].setVelocity(rand() % 200 - 100, rand() % 200 - 100);
			balls[k].setPosition(spawnPoint);
			counter++;
			return;
		}
	}
	
	if (counter == 0)
	{
		balls.push_back(Ball());
		balls[balls.size()].setAlive(false);
		balls[balls.size()].setTexture(&texture);
		balls[balls.size()].setSize(sf::Vector2f(100, 100));
	}
}

void BallManager::deathCheck()
{
	sf::Vector2u pos = window->getSize();
	for (int l = 0; l < balls.size(); l++)
	{
		if (balls[l].isAlive())
		{
			if (balls[l].getPosition().x < -100)
			{
				balls[l].setAlive(false);
			}
			if (balls[l].getPosition().y < -100)
			{
				balls[l].setAlive(false);
			}
			if (balls[l].getPosition().x > pos.x + 100)
			{
				balls[l].setAlive(false);
			}
			if (balls[l].getPosition().y > pos.y + 100)
			{
				balls[l].setAlive(false);
			}
		}
	}
}

void BallManager::render(sf::RenderWindow* window)
{
	for (int m = 0; m < balls.size(); m++)
	{
		if (balls[m].isAlive())
		{
			window->draw(balls[m]);
		}
	}
}

