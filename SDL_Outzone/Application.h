#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 17

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleParticles;
class ModuleSceneSpace;
class ModuleSceneSpaceUpper;
class ModuleSceneIntro;
class ModuleGameOver;
class ModuleWinScreen;
class ModulePlayer;
class ModuleFadeToBlack;
class ModuleAudio;
class ModuleCollision;
class ModuleEnemies;
class Module;
class ModuleEffects;
class ModuleUI;

class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleSceneSpace* scene_space;
	ModuleSceneSpaceUpper* scene_space_upper;
	ModuleSceneIntro* scene_intro;
	ModuleGameOver* scene_gameover;
	ModuleWinScreen* scene_gamewin;
	ModuleCollision* collision;
	ModulePlayer* player;
	ModuleFadeToBlack* fade;
	ModuleAudio* audio;
	ModuleParticles* particles;
	ModuleEnemies* enemies;
	ModuleEffects* effects;
	ModuleUI* ui;
	//EnemyT

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__