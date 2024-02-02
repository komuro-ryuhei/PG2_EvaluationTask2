#include "Scene_Game.h"

Scene_Game::Scene_Game() {
	game_ = new Game();

}

Scene_Game::~Scene_Game() {

	delete game_;
}

void Scene_Game::Init() {
	game_->Init();
	player_ = game_->GetPlayerPtr();
}

void Scene_Game::Update(char* keys, char* preKeys) {

	game_->Update(keys, preKeys);

	if (keys[DIK_T] && !preKeys[DIK_T]) {
		sceneNum_ = TITLE;
	}

	if (!player_->GetisAlive()) {
		sceneNum_ = GAMEOVER;
	}
}

void Scene_Game::Draw() {

	game_->Draw();
}