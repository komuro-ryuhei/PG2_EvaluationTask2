#pragma once
#include "Novice.h"
#include <vector>

enum SceneNum {
	TITLE,
	GAME,
	GAMEOVER
};

class Scene_Base {

protected:

	static SceneNum sceneNum_;

public:

	virtual void Init() = 0;
	virtual void Update(char* keys, char* preKeys) = 0;
	virtual void Draw() = 0;

	SceneNum GetSceneNum() { return sceneNum_; }
};