#pragma once
#include "GameObject.h"
#include <vector>
#include <stdlib.h>
#include "collisiontest.h"

class Gamestate
{

	Player player;
	std::vector<Missile> missile;
	std::vector<Enemy> enemy;
public:
	
	void spawnMissile(float x , float y , float dx , float dy, float lifespan)
	{
		// search
		for (int i = 0; i < missile.size(); ++i)
		{
			if (!missile[i].isActive)
			{
				missile[i] = Missile(x, y, dx, dy, lifespan);
				return;
			}
		}

		// otherwise, add another
		missile.push_back(Missile(x, y, dx, dy, lifespan));
	}
	
	//void death();

	void spawnEnemy(float x, float y, float dx, float dy)
	{
		// search for an inactive enemy
		for (int i = 0; i < enemy.size(); ++i)
		{
			std::cout << i << std::endl;
			if (!enemy[i].isActive) // Find an empty spot in our vector
			{
				enemy[i] = Enemy(x, y, dx, dy);
				return;
			}
		}

		// if none, add another enemy to the vector
		enemy.push_back(Enemy(x, y, dx, dy));
	}

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
		
		
					// Collision detection between two objects of the same type
			for (int i = 0; i + 1 < missile.size(); ++i)
			 for (int j = i + 1; j < missile.size(); ++j)
			 {
				 doCollision(missile[i], missile[j]);
			 }

			int nEnemy = 0;
			int s = 3;
			for (int i = 0; i < enemy.size(); ++i)
			{
				if (enemy[i].isActive)
				{
					nEnemy++;
					enemy[i].update();
					doCollision(enemy[i], player);

				}
				if (enemy[i].y < 0)
				{
					enemy[i].isActive = false;
				}
				
			}

			// check for collision between ENEMY and MISSILE
			for (int i = 0; i < enemy.size(); ++i)
				for (int j = 0; j < missile.size(); ++j)
				{
					if (enemy[i].isActive && missile[j].isActive)
						doCollision(enemy[i], missile[j]);
				}

			
			if (nEnemy < s)
			{
				spawnEnemy(rand() % 800, 600, 50, 50);// Spawn a new wave of enemies 
			}
	
			if (player.lifes = 0)
			{
				system("pause");

			}

	}

	void draw()
	{
		if (player.isActive) player.draw();

		for (int i = 0; i < enemy.size(); ++i)
			if (enemy[i].isActive)
				enemy[i].draw();


		for (int i = 0; i < missile.size(); ++i)
			if (missile[i].isActive)
				missile[i].draw();

	}


};







