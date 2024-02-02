#include "Bullet.h"

Bullet::Bullet() {

}

Bullet::~Bullet() {}

void Bullet::Init() {

	pos_ = { 0.0f,0.0f };
	speed_ = 10.0f;
	radius_ = 16.0f;
	isShot_ = false;
}

void Bullet::Update() {

	if (isShot_) {

		pos_.y -= speed_;
		if (pos_.y <= 0.0f - radius_) {

			isShot_ = false;
		}
	}
}

void Bullet::Draw() {

	if (isShot_) {

		Novice::DrawEllipse(int(pos_.x), int(pos_.y),
			int(radius_), int(radius_), 0.0f, RED, kFillModeSolid);
	}
}

