#include "Level.h"


Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	zombie.setInput(input);
	mario.setInput(input);
	backround.setInput(input);

	// initialise game objects
	zombTexture.loadFromFile("gfx/animZombie.png"); 
	zombie.setTexture(&zombTexture);
	
	zombie.setSize(sf::Vector2f(110, 216)); 
	zombie.setPosition(100, 100); 
	zombie.setVelocity(100, 100);
	
	marioTexture.loadFromFile("gfx/MarioSheetT.png");
	mario.setTexture(&marioTexture);

	mario.setSize(sf::Vector2f(64, 84));
	mario.setPosition(300, 300);
	mario.setVelocity(100, 100);

	backroundTexture.loadFromFile("gfx/wallpaper.png");
	backround.setTexture(&backroundTexture);

	backround.setSize(sf::Vector2f(1536,1152));
	backround.setPosition(0, 0);


}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	zombie.update(dt);
	mario.update(dt);
	backround.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(backround);
	window->draw(zombie);
	window->draw(mario);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}