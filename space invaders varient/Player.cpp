#include "GameObject.h"
#include "Gamestate.h"


void Player::update()
{
	
	fireDelay -= sfw::getDeltaTime();

	
	{
		if (sfw::getKey(263))
		{
			if (x >= 30)
			{
				x -= speed * sfw::getDeltaTime();
			}
		}

		if (sfw::getKey(262))
		{
			if (x <= 770)
			{
				x += speed * sfw::getDeltaTime();
			}
		}
		if (sfw::getKey(32) && fireDelay < 0)
		{
			fireDelay = fireRate;
			gs()->spawnMissile(x, y, 0, 300, 4.f);
		}


//		player.draw();
	//	sfw::drawTexture(player, x, y, 50, 50, 0, true, 20);
	}
}