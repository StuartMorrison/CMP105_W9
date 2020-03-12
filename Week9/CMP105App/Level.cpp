#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	ballManager.setWindu(window);
	Tails.setWindu(window);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Q))
	{
		input->setKeyUp(sf::Keyboard::Q);
		ballManager.spawn();
	}

	if (input->isKeyDown(sf::Keyboard::P))
	{
		input->setKeyUp(sf::Keyboard::P);
		Tails.spawn();
		if (Tails.getCounter() < 40)
		{
			Tails.setCounter(1);
			std::cout << Tails.getCounter() << "\n";
		}
	}
}

// Update game objects
void Level::update(float dt)
{
	ballManager.update(dt);
	Tails.update(dt);
	
}

// Render level
void Level::render()
{
	beginDraw();
	ballManager.render(window);
	Tails.render(window);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}