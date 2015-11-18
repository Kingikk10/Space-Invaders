#include "GameObject.h"
#include "Gamestate.h"






void Enemey::update()
{

	if (gs()->enemey[i] < 10)
	{
	gs()->spawnEnemey(x, y, 0, 300);




	y -= speed *sfw::getDeltaTime();








}













