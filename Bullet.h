#pragma once
#include "Vector2.h"
#include "Novice.h"

class Bullet {

public:

	Bullet();

	void Init();
	void Update();
	void Draw();

	~Bullet();

public:

	Vector2 pos_{};
	float speed_{};
	float radius_{};
	bool isShot_{};
};