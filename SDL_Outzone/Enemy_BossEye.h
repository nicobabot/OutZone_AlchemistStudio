#ifndef __BOSSEYE_H__
#define __BOSSEYE_H__

#include "Enemy.h"

class Enemy_Bosseye : public Enemy
{

private:

	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	int original_x = 0;
	bool firsttime = true;
	unsigned int lastTime = 0;
	unsigned int currentTime = 0;
	Animation BossEYElvl2idleopen;
	Animation BossEYElvl2idleclose;
	Animation BossEYElvl2open;
	Animation BossEYElvl2close;
	int count;
	int movement = 0;

public:
	Enemy_Bosseye(int x, int y);
	void Move();
	void Shoot();
};

#endif // __ENEMY_TURRET1_H__