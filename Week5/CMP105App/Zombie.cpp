#include "Zombie.h"


Zombie::Zombie() 
{
	// Setup walk animation.
	walk.addFrame(sf::IntRect(0, 0, 55, 108));
	walk.addFrame(sf::IntRect(55, 0, 55, 108));
	walk.addFrame(sf::IntRect(115, 0, 55, 108));
	walk.addFrame(sf::IntRect(165, 0, 55, 108));
	walk.addFrame(sf::IntRect(220, 0, 55, 108));
	walk.addFrame(sf::IntRect(275, 0, 55, 108));
	walk.addFrame(sf::IntRect(335, 0, 55, 108));
	walk.addFrame(sf::IntRect(385, 0, 55, 108));
	walk.setFrameSpeed(1.f / 10.f);

	currentAnimation = &walk;
	setTextureRect(currentAnimation->getCurrentFrame());
}

void  Zombie::update(float dt)
{
	walk.animate(dt);
	

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

}


Zombie::~Zombie()
{

}

