#include "Scene_Title.h"

void Scene_Title::Init() {

}

void Scene_Title::Update(char* keys, char* preKeys){

	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {

		sceneNum_ = GAME;
	}
}

void Scene_Title::Draw() {

	Novice::ScreenPrintf(640, 360, "TITLE");
	Novice::ScreenPrintf(640, 400, "SPACE to PLAY");
}