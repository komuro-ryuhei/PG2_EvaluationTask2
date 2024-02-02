#pragma once
#include "Vector2.h"
#include "Novice.h"

class Enemy {

public:

	Enemy(Vector2 pos);

	void Init(Vector2 pos);
	void Update();
	void Draw();

	~Enemy();

	//ゲッター,セッター
	Vector2 GetPos() { return pos_; }
	float GetSpeed() { return speed_; }
	float GetRadius() { return radius_; }
	int SetRespawnTime(int time) { return respawnTime_ = time; }
	int GetRespawnTime() { return respawnTime_; }
	bool SetisAlive(bool isAlive) { 
	
		return isAlive_ = isAlive;
	}

	bool GetisAlive() { return isAlive_; }

private:

	Vector2 pos_;
	float speed_;
	float radius_;
	int respawnTime_;
	bool isAlive_;
};

