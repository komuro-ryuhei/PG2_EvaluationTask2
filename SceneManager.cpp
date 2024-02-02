#include "SceneManager.h"

SceneManager::SceneManager() {

	sceneArr_.push_back(new Scene_Title());
	sceneArr_.push_back(new Scene_Game());
	sceneArr_.push_back(new Scene_Gameover());

	currentScene_ = TITLE;
	sceneArr_[currentScene_]->Init();
}

void SceneManager::Run(char* keys, char* preKeys) {

	preScene_ = currentScene_;

	currentScene_ = sceneArr_[currentScene_]->GetSceneNum();

	if (currentScene_ != preScene_) {
		sceneArr_[currentScene_]->Init();
	}

	sceneArr_[currentScene_]->Update(keys, preKeys);
	sceneArr_[currentScene_]->Draw();
}
