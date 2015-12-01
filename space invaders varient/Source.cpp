
#include "window.h"
#include <iostream>
#include "sfwdraw.h"
#include "GameObject.h"
#include "Gamestate.h"
#include <vector>
#include "AssetLibrary.h"


struct Background
{
	float y = 600;
	unsigned r = sfw::loadTextureMap("./textures/stars.jpg");
	unsigned f = sfw::loadTextureMap("./textures/starsdied.jpg");
void level1()
{	
	sfw::drawTexture(r, 0, y, 800, 600, 0, false, 0);
}
void death()
{
	sfw::drawTexture(f, 0, y, 800, 600, 0, false, 0);
}
};

bool play()
{
	if (sfw::getKey(257))
		return true;
}


void main()
{
	sfw::initContext(800, 600, "Space Invaders");
	loadTexture("player", "./textures/spaceship.jpg", 1, 1);
	loadTexture("missile","./textures/creatures.png", 8, 80);
	loadTexture("enemey", "./textures/ships.png", 8, 80);
	
	bool play = false;
	
	Gamestate game;
	Background b;

	while (sfw::stepContext())
	{
		b.level1();
		if (sfw::getKey(257))
		{
			play = true;
		}
		if (game.player.lifes == 0)
		{

			b.death();
			play = false;
		}
		if (play == true)
		{
			game.update();
			game.draw();
		}
	}
	sfw::termContext();
}

































