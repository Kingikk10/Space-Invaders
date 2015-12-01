#include "GameObject.h"
#include "Gamestate.h"

void Enemy::update()
{
	y -= speed *sfw::getDeltaTime();
}