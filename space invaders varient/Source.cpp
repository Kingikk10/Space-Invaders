
#include "window.h"
#include <iostream>
#include "sfwdraw.h"
#include "GameObject.h"
#include "Gamestate.h"
#include <vector>


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
	unsigned player = sfw::loadTextureMap("./textures/spaceship.jpg");
	unsigned missile = sfw::loadTextureMap("./textures/creatures.png", 8, 80);
	unsigned enemy = sfw::loadTextureMap("./textures/ships.png", 8, 80);
	
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

































