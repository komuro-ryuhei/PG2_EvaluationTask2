#pragma once
#include "Scene_Base.h"
#include "Player.h"
#include "Game.h"

class Scene_Game :
	public Scene_Base {

private:

	Game* game_;

	Player* player_;

public:

	Scene_Game();

	~Scene_Game();

	void Init()override;
	void Update(char* keys, char* preKeys)override;
	void Draw()override;
};

