#pragma once
#include "Novice.h"
#include "Bullet.h"
#include "Vector2.h"

class Player {

public:

	Player();

	void Init();
	void Update(char* keys, char* preKeys);
	void Draw();
	~Player();

	Bullet* bullet_;

	//プレイヤーのゲッター,セッター
	Vector2 GetPos() { return pos_; }
	float GetSpeed() { return speed_; }
	float GetRadius() { return radius_; }
	bool GetisAlive() { return isAlive_; }
	bool SetisAlive(bool isAlive) {

		return isAlive_ = isAlive;
	}

	//バレットのゲッター,セッター
	Vector2 BulletGetPos() { return bullet_->pos_; }
	float BulletGetSpeed() { return bullet_->speed_; }
	float BulletGetRadius() { return bullet_->radius_; }
	bool BulletSetisShot(bool isShot) {

		return bullet_->isShot_ = isShot;
	}

private:

	Vector2 pos_{};
	float speed_{};
	float radius_{};
	bool isAlive_;
};

