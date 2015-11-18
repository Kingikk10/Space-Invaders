#pragma once
#include "GameObject.h"
#include <vector>


class Gamestate
{

	Player player;
	std::vector<Missile> missile;

public:
	
	void spawnMissile(float x , float y , float dx , float dy, float lifespan)
	{
		for (int i = 0; i < missile.size(); ++i)
		{
			if (!missile[i].isActive)
			{
				missile[i] = Missile(x, y, dx, dy, lifespan);
				return;
			}
		}
		missile.push_back(Missile(x, y, dx, dy, lifespan));
	}
	
	//void death();
	//void enemey();

	Gamestate()
	{
		GameObject::gs() = this;
	}
	void update()
	{

		if (player.isActive)
				player.update();


		int nMissileActive = 0;
		
			for (int i = 0; i < missile.size(); ++i)
			 if (missile[i].isActive)
			 {
			missile[i].update();
			if (player.isActive)
				 doCollision(player, missile[i]);
			}
		else nMissileActive++;
		
			if (nMissileActive == 0)
			 {
							// Spawn a new wave of enemies (obviously not using Bullets >__>)
			 }
		
					// Collision detection between two objects of the same type
			for (int i = 0; i + 1 < missile.size(); ++i)
			 for (int j = i + 1; j < missile.size(); ++j)
			 {
				 doCollision(missile[i], missile[j]);
			 }



	}

	void draw()
	{
		if (player.isActive) player.draw();

		for (int i = 0; i < missile.size(); ++i)
			if (missile[i].isActive)
				missile[i].draw();

	}


};







