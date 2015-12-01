#pragma once
#include <string>
#include "sfwdraw.h"
#include "AssetLibrary.h"
#include <iostream>
#include "GameObject.h"



class Gamestate;

class GameObject
{
public:

	
	static Gamestate *&gs()
	{
		static Gamestate *game;
		return game;

	}

	float x, y, width, height, radius, angle;
	
	bool isActive;
	
	
	unsigned currentFrame;
	std::string textureName;

	GameObject() :x(400), y(300), width(60), height(60), radius(30), angle(0), currentFrame(0), isActive(true) {}
	 
	virtual void draw()
	{
		sfw::drawTexture(getTexture(textureName), x, y, width, height, angle, true, currentFrame);
			
	}
	virtual void update() {}


	virtual void onCollision(GameObject &go, float distance) {}

};

float doCollision(GameObject &go1, GameObject &go2);





class Missile : public GameObject
{
	float velx, vely;
	float lifetime; 
	unsigned missile; // for now, will be deleted soon hopefully
	unsigned speed; // for now, will be deleted soon hopefully
public:
	Missile(float a_x, float a_y, float dx, float dy, float lifespan)
	{
		x = a_x;
		y = a_y;
		velx = dx;
		vely = dy;
		lifetime = lifespan;
	}
	virtual void onCollision(GameObject &go, float distance)
	{
		isActive = false;

	}
	virtual void update()
	{
		GameObject::update();
		lifetime -= sfw::getDeltaTime();
		isActive = lifetime > 0; //the missile is no longer active when the lifetime reduces to 0


		x += velx *sfw::getDeltaTime();
		y += vely *sfw::getDeltaTime();

			
	}
	virtual void draw()
	{
		sfw::drawTexture(getTexture("missile"), x, y, 50, 50, 0, true, 48);

	}



};


class Player : public GameObject
{
public:
	float speed;
	float fireDelay;
	float fireRate;
	int lifes = 3;

	Player() : speed(300), fireDelay(1), fireRate(1)
	{
		x = 400;
		y = 50;
	}

	// called when a collision has occurred for this GameObject
	//	- 'go' is the gameobject that it collided with
	//	- distance is the penetration distance? (idk esme wrote the func not me)
	virtual void onCollision(GameObject &go, float distance)
	{
		lifes - 1;
		std::cout << "lives are" << lifes << std::endl;
	}

	virtual void update();

	virtual void draw()
	{
		sfw::drawTexture(getTexture("player"), x, y, 50, 50, 0, true, 0);
	
	}
};


class Enemy : public GameObject
{
public:
	float speed;

	Enemy(float a_x, float a_y, float dx, float dy)
	{
		x = a_x;
		y = a_y;

		speed = 75;
	}
	
		
	//	y -= speed *sfw::getDeltaTime();

	
		virtual void onCollision(GameObject &go, float distance)
		{
			isActive = false;
		}

		virtual void update();

		virtual void draw()
		{
			sfw::drawTexture(getTexture("enemey"), x, y, 50, 50, 0, true, 0);

		}

	






};
























