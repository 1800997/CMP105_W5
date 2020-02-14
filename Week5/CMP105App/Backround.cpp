#include "Backround.h"

Backround::Backround()
{
	wow.addFrame(sf::IntRect(0, 0, 25, 25));
	wow.addFrame(sf::IntRect(25, 0, 25, 25));
	wow.addFrame(sf::IntRect(50, 0, 25, 25));
	wow.addFrame(sf::IntRect(75, 0, 25, 25));
	wow.addFrame(sf::IntRect(100, 0, 25, 25));

	wow.setFrameSpeed(1.f / 1.f);

	currentAnimation = &wow;
	setTextureRect(currentAnimation->getCurrentFrame());
};

Backround::~Backround()
{

};

void Backround::update(float dt)
{
	wow.animate(dt);
	currentAnimation = &wow;
	setTextureRect(currentAnimation->getCurrentFrame());
};
