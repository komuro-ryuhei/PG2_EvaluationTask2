#include "Scene_Gameover.h"

void Scene_Gameover::Init() {

}

void Scene_Gameover::Update(char* keys, char* preKeys) {

	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {

		sceneNum_ = TITLE;
	}
}

void Scene_Gameover::Draw() {

	Novice::ScreenPrintf(640, 360, "GAMEOVER");
	Novice::ScreenPrintf(640, 400, "SPACE to TITLE");
}