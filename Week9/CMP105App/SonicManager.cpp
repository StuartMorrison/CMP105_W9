#include "SonicManager.h"

SonicManager::SonicManager()
{
	spawnPoint = sf::Vector2f(100, -100);
	texture.loadFromFile("gfx/sonic.png");

	for (int i = 0; i < 40; i++)
	{
		sonics.push_back(Ball());
		sonics[i].setAlive(false);
		sonics[i].setTexture(&texture);
		sonics[i].setSize(sf::Vector2f(100, 100));
	}
}

SonicManager::~SonicManager()
{

}

void SonicManager::update(float dt)
{
	for (int j = 0; j < sonics.size(); j++)
	{
		if (sonics[j].isAlive())
		{
			sonics[j].update(dt);
		}
	}
	deathCheck();
}

void SonicManager::spawn()
{
	spawnPoint = sf::Vector2f(rand() % 1000, -100);
	for (int k = 0; k < sonics.size(); k++)
	{
		if (!sonics[k].isAlive())
		{
			sonics[k].setAlive(true);
			sonics[k].setVelocity(0, rand() % 200 + 50);
			sonics[k].setPosition(spawnPoint);
			return;
		}
	}
}

void SonicManager::deathCheck()
{
	sf::Vector2u pos = window->getSize();
	for (int l = 0; l < sonics.size(); l++)
	{
		if (sonics[l].isAlive())
		{
			if (sonics[l].getPosition().y > pos.y + 100)
			{
				sonics[l].setAlive(false);
				counter--;
			}
		}
	}
}

void SonicManager::render(sf::RenderWindow* window)
{
	for (int m = 0; m < sonics.size(); m++)
	{
		if (sonics[m].isAlive())
		{
			window->draw(sonics[m]);
		}
	}
}


