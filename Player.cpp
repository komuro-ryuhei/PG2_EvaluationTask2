#include "Player.h"

Player::Player() {

	bullet_ = new Bullet();
	bullet_->Init();

	Init();
}

Player::~Player() { delete bullet_; }

void Player::Init() {

	pos_ = { 640.0f,640.0f };
	speed_ = 8.0f;
	radius_ = 32.0f;
	isAlive_ = true;

	bullet_->Init();
}

void Player::Update(char* keys, char* preKeys) {

	if (isAlive_) {
		if (keys[DIK_A]) {

			pos_.x -= speed_;
		}

		if (keys[DIK_D]) {

			pos_.x += speed_;
		}

		if (keys[DIK_W]) {

			pos_.y -= speed_;
		}

		if (keys[DIK_S]) {

			pos_.y += speed_;
		}

		if (!bullet_->isShot_) {
			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {

				bullet_->pos_.x = pos_.x;
				bullet_->pos_.y = pos_.y;
				bullet_->isShot_ = true;
			}
		}
	}

	bullet_->Update();
}

void Player::Draw() {

	if (isAlive_) {
		Novice::DrawEllipse(int(pos_.x), int(pos_.y), int(radius_), int(radius_),
			0.0f, 0x0000ffff, kFillModeSolid);
	}

	bullet_->Draw();

	Novice::ScreenPrintf(10, 10, "%d", bullet_->isShot_);
}
