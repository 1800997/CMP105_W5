#include "Mario.h"

Mario::Mario()
{
	// Setup walk animation.
	walk.addFrame(sf::IntRect(0, 0, 14, 21));
	walk.addFrame(sf::IntRect(15, 0, 15, 21));
	walk.addFrame(sf::IntRect(30, 0, 15, 21));
	//walk.addFrame(sf::IntRect(32, 0, 14, 21));
	walk.setFrameSpeed(1.f / 10.f);

	// Setup swim animation.
	swim.addFrame(sf::IntRect(0, 21, 16, 20));
	swim.addFrame(sf::IntRect(17, 21, 15, 20));
	swim.addFrame(sf::IntRect(32, 21, 16, 20));
	swim.setFrameSpeed(1.f / 10.f);

	// Setup duck animation.
	duck.addFrame(sf::IntRect(0, 41, 16, 20));
	duck.addFrame(sf::IntRect(16, 41, 16, 20));
	duck.setFrameSpeed(1.f / 10.f);

	currentAnimation = &walk;
	setTextureRect(currentAnimation->getCurrentFrame());
};

Mario::~Mario()
{

};

void  Mario::update(float dt)
{
	walk.animate(dt);
	duck.animate(dt);
	swim.animate(dt);

	if (input->isKeyDown(sf::Keyboard::Right))
	{
		currentAnimation->setFlipped(false);
		currentAnimation = &walk;
		setTextureRect(currentAnimation->getCurrentFrame());
		move(velocity.x * dt, 0);
	}

	if (input->isKeyDown(sf::Keyboard::Left))
	{
		currentAnimation->setFlipped(true);
		currentAnimation = &walk;
		setTextureRect(currentAnimation->getCurrentFrame());
		move(-velocity.x * dt, 0);
	}

	if (input->isKeyDown(sf::Keyboard::Down))
	{
		currentAnimation = &duck;
		setTextureRect(currentAnimation->getCurrentFrame());
		move(0, velocity.y * dt);
	}

	if (input->isKeyDown(sf::Keyboard::Up))
	{
		currentAnimation = &swim;
		setTextureRect(currentAnimation->getCurrentFrame());
		move(velocity.x * dt, -velocity.y * dt);
	}

};
