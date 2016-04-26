#include "Application.h"
#include "Enemy_Turret1.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "SDL/include/SDL_timer.h"
#include <math.h>

#define RANGE 30
#define PI 3.14159265
#define ANGLE_CONVERT (180.0 / PI)
#define ANGLE_CONVERT_REVERSE (PI / 180.0)
#define ENEMY_SHOOT_SPEED 6

Enemy_Turret1::Enemy_Turret1(int x, int y) : Enemy(x, y)
{
	turret1__0.PushBack({ 342, 54, 27, 47 });
	turret1__22_5.PushBack({ 342, 110, 26, 46 });
	turret1__45.PushBack({ 297, 111, 27, 45 });
	turret1__67_5.PushBack({ 252, 113, 27, 43 });
	turret1__90.PushBack({ 206, 113, 28, 43 });
	turret1__112_5.PushBack({ 161, 113, 27, 44 });
	turret1__135.PushBack({ 115, 113, 28, 44 });
	turret1__157_5.PushBack({ 69, 113, 28, 45 });
	turret1__180.PushBack({ 22, 113, 29, 45 });
	turret1__202_5.PushBack({ 25, 57, 27, 45 });
	turret1__225.PushBack({ 71, 58, 26, 44 });
	turret1__247_5.PushBack({ 114, 57, 29, 44 });
	turret1__270.PushBack({ 157, 58, 30, 43 });
	turret1__292_5.PushBack({ 206, 58, 28, 43 });
	turret1__315.PushBack({ 254, 56, 24, 45 });
	turret1__337_5.PushBack({ 299, 55, 24, 46 });

	animation = &turret1__180;

	collider = App->collision->AddCollider({ 0, 0, 27, 47 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
	original_x = x;
}

void Enemy_Turret1::Move()
{
	bool left = false;
	float angle = 0;

	if ((original_y >= (App->render->camera.y / 2) - RANGE) && (original_y <= (App->render->camera.y / 2) + 340 - RANGE)){
		//left or right of the turret
		if (App->player->position.x >= original_x){
			left = false;
		}
		else{
			left = true;
		}

		//angle
		//angle = (float)acos(((App->player->position.x * 0) + (App->player->position.y * 1)) / ((sqrt((pow((double)App->player->position.x, 2)) + (pow((double)App->player->position.y, 2))))*(sqrt((pow(0.0, 2.0)) + (pow(1.0, 2.0)))))) * ANGLE_CONVERT;

		//angle = ((float)acos(((App->player->position.x * 0) + (App->player->position.y * 1)) / (sqrt((double)((App->player->position.x)*(App->player->position.x) + (App->player->position.y)*(App->player->position.y)))*sqrt((double)(0 * 0 + 1 * 1))))) * ANGLE_CONVERT;

		angle = ((float)acos((((App->player->position.x - original_x) * 0) + ((App->player->position.y - original_y) * 1)) / (sqrt((double)((App->player->position.x - original_x)*(App->player->position.x - original_x) + (App->player->position.y - original_y)*(App->player->position.y - original_y)))*sqrt((double)(0 * 0 + 1 * 1))))) * ANGLE_CONVERT;

		//LOG("Angle %.2f", angle);

		//Right
		if ((angle <= 11.25) && (angle >= 0) && (left == false)){
			animation = &turret1__180;
		}
		else if ((angle <= 33.75) && (angle >= 11.25) && (left == false)){
			animation = &turret1__157_5;
		}
		else if ((angle <= 56.25) && (angle >= 33.75) && (left == false)){
			animation = &turret1__135;
		}
		else if ((angle <= 78.75) && (angle >= 56.25) && (left == false)){
			animation = &turret1__112_5;
		}
		else if ((angle <= 101.25) && (angle >= 78.75) && (left == false)){
			animation = &turret1__90;
		}
		else if ((angle <= 123.75) && (angle >= 101.25) && (left == false)){
			animation = &turret1__67_5;
		}
		else if ((angle <= 146.25) && (angle >= 123.75) && (left == false)){
			animation = &turret1__45;
		}
		else if ((angle <= 168.75) && (angle >= 146.25) && (left == false)){
			animation = &turret1__22_5;
		}
		else if ((angle <= 180) && (angle >= 168.75) && (left == false)){
			animation = &turret1__0;
		}

		//Left
		else if ((angle <= 11.25) && (angle >= 0) && (left == true)){
			animation = &turret1__180;
		}
		else if ((angle <= 33.75) && (angle >= 11.25) && (left == true)){
			animation = &turret1__202_5;
		}
		else if ((angle <= 56.25) && (angle >= 33.75) && (left == true)){
			animation = &turret1__225;
		}
		else if ((angle <= 78.75) && (angle >= 56.25) && (left == true)){
			animation = &turret1__247_5;
		}
		else if ((angle <= 101.25) && (angle >= 78.75) && (left == true)){
			animation = &turret1__270;
		}
		else if ((angle <= 123.75) && (angle >= 101.25) && (left == true)){
			animation = &turret1__292_5;
		}
		else if ((angle <= 146.25) && (angle >= 123.75) && (left == true)){
			animation = &turret1__315;
		}
		else if ((angle <= 168.75) && (angle >= 146.25) && (left == true)){
			animation = &turret1__337_5;
		}
		else if ((angle <= 180) && (angle >= 168.75) && (left == true)){
			animation = &turret1__0;
		}
	}
	position.y = original_y;
	position.x = original_x;
}

void Enemy_Turret1::Shoot()
{
	unsigned int currentTime = 0;
	bool left = false;
	float angle = 0;
	int i = 0;

	currentTime = SDL_GetTicks();

	if ((original_y >= (App->render->camera.y / 2) - RANGE) && (original_y <= (App->render->camera.y / 2) + 340 - RANGE)){
		
		if (App->player->position.x >= original_x){
			left = false;
		}
		else{
			left = true;
		}

		angle = ((float)acos((((App->player->position.x + 14 - original_x) * 0) + ((App->player->position.y + 16 - original_y) * 1)) / (sqrt((double)((App->player->position.x + 14 - original_x)*(App->player->position.x + 14 - original_x) + (App->player->position.y + 16 - original_y)*(App->player->position.y + 16 - original_y)))*sqrt((double)(0 * 0 + 1 * 1))))) * ANGLE_CONVERT;
		//LOG("Angle %.2f", angle);
		
		if (currentTime > (lastTime + 1200)) {
			if (left == true){
				if ((angle < 90) && (angle >= 0)){
					App->particles->enemyshoot.speed.x = -ENEMY_SHOOT_SPEED * sin(angle * ANGLE_CONVERT_REVERSE);
					App->particles->enemyshoot.speed.y = ENEMY_SHOOT_SPEED * cos(angle * ANGLE_CONVERT_REVERSE);
				}
				else{
					App->particles->enemyshoot.speed.x = -ENEMY_SHOOT_SPEED * sin(angle * ANGLE_CONVERT_REVERSE);
					App->particles->enemyshoot.speed.y = ENEMY_SHOOT_SPEED * cos(angle * ANGLE_CONVERT_REVERSE);
				}
			}
			else{
				if ((angle < 90) && (angle >= 0)){
					App->particles->enemyshoot.speed.x = ENEMY_SHOOT_SPEED * sin(angle * ANGLE_CONVERT_REVERSE);
					App->particles->enemyshoot.speed.y = ENEMY_SHOOT_SPEED * cos(angle * ANGLE_CONVERT_REVERSE);
				}
				else{
					App->particles->enemyshoot.speed.x = ENEMY_SHOOT_SPEED * sin(angle * ANGLE_CONVERT_REVERSE);
					App->particles->enemyshoot.speed.y = ENEMY_SHOOT_SPEED * cos(angle * ANGLE_CONVERT_REVERSE);
				}
			}
			App->particles->AddParticle(App->particles->enemyshoot, original_x, original_y, COLLIDER_ENEMY_SHOT);
			lastTime = currentTime;
		}
	}
}