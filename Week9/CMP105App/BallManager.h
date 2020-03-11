#pragma once
#include "Ball.h"
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;

class BallManager
{
public:
	BallManager();
	~BallManager();

	void spawn();
	void update(float dt);
	void deathCheck();
	void render(sf::RenderWindow* window);
	void setWindu(sf::RenderWindow* hwnd) { window = hwnd; };

private:
	std::vector<Ball> balls;
	sf::Vector2f spawnPoint;
	sf::Texture texture;
	sf::RenderWindow* window;
};

