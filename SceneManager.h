#pragma once
#include "Scene_Base.h"
#include "Scene_Title.h"
#include "Scene_Game.h"
#include "Scene_Gameover.h"

class SceneManager {

private:

	std::vector<Scene_Base*> sceneArr_;
	int stageNum;

	SceneNum currentScene_;
	SceneNum preScene_;

public:

	SceneManager();

	~SceneManager();

	void Run(char* keys, char* preKeys);
};

