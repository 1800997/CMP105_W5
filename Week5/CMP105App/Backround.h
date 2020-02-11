#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"

class Backround:public GameObject
{
public:
	Backround();
	~Backround();

	void update(float dt) override;

protected:
	Animation wow;
	Animation* currentAnimation;

};

