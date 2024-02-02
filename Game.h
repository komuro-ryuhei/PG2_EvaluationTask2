#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Collision.h"
#include "Scene_Base.h"

class Game {

public:

	Game();

	void Init();
	void Update(char* keys, char* preKeys);
	void Draw();

	~Game();

private:

	Player* player;
	Enemy* enemy[4];
	Collision* collision;
public:
	Player* GetPlayerPtr()const;
};