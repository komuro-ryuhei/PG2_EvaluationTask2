#include "Enemy.h"

Enemy::Enemy(Vector2 pos) {

	Init(pos);
}

Enemy::~Enemy() {

}

void Enemy::Init(Vector2 pos) {

	pos_ = pos;
	speed_ = 10.0f;
	radius_ = 32.0f;
	respawnTime_ = 150;
	isAlive_ = true;
}

void Enemy::Update() {

	if (isAlive_) {
		pos_.x += speed_;

		if (pos_.x >= 1280.0f - radius_ || pos_.x <= 0.0f + radius_) {

			speed_ *= -1;
		}
	}
}

void Enemy::Draw() {

	if (isAlive_) {

		Novice::DrawEllipse(int(pos_.x), int(pos_.y), int(radius_), int(radius_),
			0.0f, WHITE, kFillModeSolid);
	}
}