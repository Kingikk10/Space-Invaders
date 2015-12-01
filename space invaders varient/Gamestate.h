#pragma once
#include "GameObject.h"
#include <vector>
#include <stdlib.h>
#include "collisiontest.h"

class Gamestate
{

	
	std::vector<Missile> missile;
	std::vector<Enemy> enemy;

	int enemyCount = 3;
public:
	Player player;
	
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
	
	

	void spawnEnemy(float x, float y, float dx, float dy)
	{
		// search for an inactive enemy
		for (int i = 0; i < enemy.size(); ++i)
		{
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
				}
				else nMissileActive++;
		
		
					// Collision detection between two objects of the same type
			for (int i = 0; i + 1 < missile.size(); ++i)
			 for (int j = i + 1; j < missile.size(); ++j)
			 {
				 if (missile[i].isActive && missile[j].isActive)
					doCollision(missile[i], missile[j]);
			 }

			int nEnemy = 0;
			
			for (int i = 0; i < enemy.size(); ++i)
			{
				if (enemy[i].isActive)
				{
					nEnemy++;
					enemy[i].update();
					doCollision(player, enemy[i]);

				}
				if (enemy[i].y < 0)
				{
					enemy[i].isActive = false;
					enemyCount++;
				}	
			}

			if (nEnemy < enemyCount)
			{
				spawnEnemy(rand() % 800, 600, 50, 50);// Spawn a new wave of enemies 
			}

			// check for collision between ENEMY and MISSILE
			for (int i = 0; i < enemy.size(); ++i)
				for (int j = 0; j < missile.size(); ++j)
				{
					if (enemy[i].isActive && missile[j].isActive)
						doCollision(enemy[i], missile[j]);
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







