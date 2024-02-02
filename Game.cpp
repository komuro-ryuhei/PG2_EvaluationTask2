#include "Game.h"

Game::Game() {

	//各クラスのインスタンスの作成
	player = new Player();

	for (int i = 0; i < 4; i++) {

		enemy[i] = new Enemy({ 200.0f + 200.0f * i,100.0f + 100.0f * i });
	}

	collision = new Collision();
}

Game::~Game() {

	delete player;

	for (int i = 0; i < 4; i++) {

		delete enemy[i];
	}
}

Player* Game::GetPlayerPtr() const {
	return player;
}

void Game::Init() {

	//プレイヤークラスの初期化
	player->Init();
	//エネミークラスの初期化
	for (int i = 0; i < 4; i++) {

		enemy[i]->Init({ 200.0f + 200.0f * i,100.0f + 100.0f * i });
	}
}

void Game::Update(char* keys, char* preKeys) {

	//プレイヤークラスの更新
	player->Update(keys, preKeys);
	//エネミークラスの更新
	for (int i = 0; i < 4; i++) {

		enemy[i]->Update();
	}

	//自機と敵の当たり判定
	for (int i = 0; i < 4; i++) {
		if (enemy[i]->GetisAlive()) {
			if (collision->isHit(player->GetPos(), player->GetRadius()
				, enemy[i]->GetPos(), enemy[i]->GetRadius()) ||
				collision->isHit(player->GetPos(), player->GetRadius(),
					enemy[i]->GetPos(), enemy[i]->GetRadius())) {

				player->SetisAlive(false);
			}
		}
	}

	//敵と弾の当たり判定
	for (int i = 0; i < 4; i++) {
		if (collision->isHit(player->BulletGetPos(), player->BulletGetRadius()
			, enemy[i]->GetPos(), enemy[i]->GetRadius()) ||
			collision->isHit(player->BulletGetPos(), player->BulletGetRadius(),
				enemy[i]->GetPos(), enemy[i]->GetRadius())) {

			enemy[i]->SetisAlive(false);
		}
	}

	for (int i = 0; i < 4; i++) {
		if (!enemy[i]->GetisAlive()) {

			enemy[i]->SetRespawnTime(enemy[i]->GetRespawnTime() - 1);
		}
		if (enemy[i]->GetRespawnTime() <= 0) {
			enemy[i]->SetisAlive(true);
			enemy[i]->SetRespawnTime(150);
		}
	}

	for (int i = 0; i < 4; i++) {
		if (keys[DIK_R] && !preKeys[DIK_R]) {

			Init();
		}
	}
}

void Game::Draw() {

	//プレイヤークラスの描画
	player->Draw();
	//エネミークラスの描画
	for (int i = 0; i < 4; i++) {

		enemy[i]->Draw();
	}
}
