#pragma once
#include "Ball.h"
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;

class SonicManager
{
public:
	SonicManager();
	~SonicManager();

	void spawn();
	void update(float dt);
	void deathCheck();
	void render(sf::RenderWindow* window);
	void setWindu(sf::RenderWindow* hwnd) { window = hwnd; };
	int getCounter() { return counter; };
	void setCounter(int newCounter) { counter += newCounter; };

private:
	std::vector<Ball> sonics;
	sf::Vector2f spawnPoint;
	sf::Texture texture;
	sf::RenderWindow* window;
	int counter = 0;
};



