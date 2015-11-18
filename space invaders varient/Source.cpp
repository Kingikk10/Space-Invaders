
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

void level1()
{	
	sfw::drawTexture(r, 0, y, 800, 600, 0, false, 0);
}
};




void main()
{
	sfw::initContext(800, 600, "Space Invaders");
	loadTexture("player", "./textures/spaceship.jpg", 1, 1);
	loadTexture("missile","./textures/creatures.png", 8, 80);
	loadTexture("enemey", "./textures/ships.png", 8, 80);

	
	Gamestate game;
	Player p;
	Background b;
	Enemey e;
	while (sfw::stepContext())
	{
		b.level1();
		/*p.update();
		e.update();*/
		game.update();
		game.draw();
	}
	sfw::termContext();
}

































