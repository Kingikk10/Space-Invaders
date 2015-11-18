#pragma once
#include <string>
#include "sfwdraw.h"
#include "AssetLibrary.h"
#include <iostream>
#include "GameObject.h"
//#include "Gamestate.h"


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

		//reactions

	}
	virtual void update()
	{
		GameObject::update();
		lifetime -= sfw::getDeltaTime();
		isActive = lifetime > 0; //the missile is no longer active when the lifetime reduces to 0


		x += velx *sfw::getDeltaTime();
		y += velx *sfw::getDeltaTime();

			
	}
	virtual void draw()
	{

		sfw::drawTexture(missile, x, y, 50, 50, 0, true, 48);

	}



};


class Player : public GameObject
{
public:
	float x, y;
	float speed;
	float fireDelay;
	float fireRate;
	unsigned player;

	Player() : x(400), y(50), speed(300), fireDelay(1), fireRate(1) {}

	virtual void onCollision(GameObject &go, float distance) {}

	virtual void update();

	virtual void draw()
	{
		sfw::drawTexture(player, x, y, 50, 50, 0, true, 20);
	
	}
	//sfw::drawTexture(getTexture(textureName), x, y, width, height, angle, true, currentFrame);


};


class Enemey : public GameObject
{
public:
	float x, y;
	float speed;
	unsigned enemy;
	Enemey() :x(), y(), speed()  {enemy = sfw::loadTextureMap("./textures/ships.png", 8, 80); }
	void update()
	{
		if (x > 0)
		{
          sfw::drawTexture(enemy, 50, 550, 50, 50, 0, true, 20);
		  
		}
	}


	






};























